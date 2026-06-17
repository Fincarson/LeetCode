var climbStairs = function (n) {
    let memo = new Array(n + 1).fill(0);
    return climb_Stairs(0, n, memo);
};
var climb_Stairs = function (i, n, memo) {
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
};
