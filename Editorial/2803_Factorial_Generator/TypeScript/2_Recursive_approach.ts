function* factorial(n: number): Generator<number> {
    function factorialRecursive(n: number): number {
        if (n <= 1) {
            return 1;
        }
        return n * factorialRecursive(n - 1);
    }

    if (n === 0) {
        yield 1;
    } else {
        for (let i = 1; i <= n; i++) {
            yield factorialRecursive(i);
        }
    }
}
