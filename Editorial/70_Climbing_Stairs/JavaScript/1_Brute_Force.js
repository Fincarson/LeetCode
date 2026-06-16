// JavaScript
var climbStairs = function (n) {
    return climb_Stairs(0, n);
};
var climb_Stairs = function (i, n) {
    if (i > n) {
        return 0;
    }
    if (i == n) {
        return 1;
    }
    return climb_Stairs(i + 1, n) + climb_Stairs(i + 2, n);
};
