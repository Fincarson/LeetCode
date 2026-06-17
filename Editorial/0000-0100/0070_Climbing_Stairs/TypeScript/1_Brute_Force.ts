// TypeScript
function climbStairs(n: number): number {
    return climb_Stairs(0, n);
}
function climb_Stairs(i: number, n: number): number {
    if (i > n) {
        return 0;
    }
    if (i == n) {
        return 1;
    }
    return climb_Stairs(i + 1, n) + climb_Stairs(i + 2, n);
}
