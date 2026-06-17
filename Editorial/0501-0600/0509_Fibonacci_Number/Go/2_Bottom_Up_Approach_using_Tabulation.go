func fib(N int) int {
    if N <= 1 {
        return N
    }
    
    cache := make([]int, N + 1)
    cache[1] = 1
    for i := 2; i <= N; i++ {
        cache[i] = cache[i - 1] + cache[i - 2]
    }
                      
    return cache[N]
}
