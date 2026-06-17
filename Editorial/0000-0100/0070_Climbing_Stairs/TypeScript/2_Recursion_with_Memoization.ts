function climbStairs(n: number): number {
    let memo: number[] = new Array(n + 1).fill(0);
    return climb_Stairs(0, n, memo);
}
function climb_Stairs(i: number, n: number, memo: number[]): number {
    if (i > n) {
        return 0;
    }
    if (i == n) {
        return 1;
    }
    if (memo[i] > 0) {
        return memo[i];
    }
    memo[i] = climb_Stairs(i + 1, n, memo) + climb_Stairs(i + 2, n, memo);
    return memo[i];
}
