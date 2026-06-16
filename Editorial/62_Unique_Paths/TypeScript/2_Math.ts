function uniquePaths(m: number, n: number): number {
    return factorial(m + n - 2) / factorial(n - 1) / factorial(m - 1);
}
function factorial(n: number): number {
    let res = 1;
    for (let i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}
