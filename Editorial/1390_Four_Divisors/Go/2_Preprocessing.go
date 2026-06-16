func sumFourDivisors(nums []int) int {
    // C is the upper bound of the array nums, and C3 is the cube root of C.
    C, C3 := 100000, 46
    
    isprime := make([]int, C+1)
    for i := 2; i <= C; i++ {
        isprime[i] = 1
    }
    primes := []int{}

    // Sieve of Eratosthenes
    for i := 2; i <= C; i++ {
        if isprime[i] == 1 {
            primes = append(primes, i)
        }
        for j := i + i; j <= C; j += i {
            isprime[j] = 0
        }
    }

    // Sieve of Euler
    /*
    for i := 2; i <= C; i++ {
        if isprime[i] == 1 {
            primes = append(primes, i)
        }
        for _, prime := range primes {
            if i * prime > C {
                break
            }
            isprime[i * prime] = 0
            if i % prime == 0 {
                break
            }
        }
    }
    */
    
    // Construct all four factors using the prime table
    factor4 := make(map[int]int)
    for _, prime := range primes {
        if prime <= C3 {
            factor4[prime * prime * prime] = 1 + prime + prime * prime + prime * prime * prime
        }
    }
    for i := 0; i < len(primes); i++ {
        for j := i + 1; j < len(primes); j++ {
            if primes[i] <= C / primes[j] {
                factor4[primes[i] * primes[j]] = 1 + primes[i] + primes[j] + primes[i] * primes[j]
            } else {
                break
            }
        }
    }

    ans := 0
    for _, num := range nums {
        if val, exists := factor4[num]; exists {
            ans += val
        }
    }
    return ans
}
