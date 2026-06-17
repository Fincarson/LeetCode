var cache = map[int]int{0: 0, 1: 1}

func fib(N int) int {
    if _, ok := cache[N]; ok {
        return cache[N]
    }
    cache[N] = fib(N - 1) + fib(N - 2)
    return cache[N]
}
