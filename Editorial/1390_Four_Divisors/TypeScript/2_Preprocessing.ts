function sumFourDivisors(nums: number[]): number {
    // C is the upper bound of the array nums, and C3 is the cube root of C.
    const C: number = 100000,
        C3: number = 46;

    let isprime: number[] = new Array(C + 1).fill(0);
    let primes: number[] = [];

    // Sieve of Eratosthenes
    for (let i = 2; i <= C; i++) {
        isprime[i] = 1;
    }
    for (let i = 2; i <= C; i++) {
        if (isprime[i]) {
            primes.push(i);
        }
        for (let j = i + i; j <= C; j += i) {
            isprime[j] = 0;
        }
    }

    // Sieve of Euler
    /*
    for (let i = 2; i <= C; i++) {
        if (isprime[i]) {
            primes.push(i);
        }
        for (let prime of primes) {
            if (i * prime > C) {
                break;
            }
            isprime[i * prime] = 0;
            if (i % prime === 0) {
                break;
            }
        }
    }
    */

    // Construct all four factors using the prime table
    let factor4: Map<number, number> = new Map();
    for (let prime of primes) {
        if (prime <= C3) {
            factor4.set(
                prime * prime * prime,
                1 + prime + prime * prime + prime * prime * prime,
            );
        }
    }
    for (let i = 0; i < primes.length; i++) {
        for (let j = i + 1; j < primes.length; j++) {
            if (primes[i] <= C / primes[j]) {
                factor4.set(
                    primes[i] * primes[j],
                    1 + primes[i] + primes[j] + primes[i] * primes[j],
                );
            } else {
                break;
            }
        }
    }

    let ans: number = 0;
    for (let num of nums) {
        if (factor4.has(num)) {
            ans += factor4.get(num)!;
        }
    }
    return ans;
}
