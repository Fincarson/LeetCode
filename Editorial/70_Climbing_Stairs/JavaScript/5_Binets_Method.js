// JavaScript
var climbStairs = function (n) {
    let q = [
        [1, 1],
        [1, 0],
    ];
    let res = pow(q, n);
    return res[0][0];
};
var pow = function (a, n) {
    let ret = [
        [1, 0],
        [0, 1],
    ];
    while (n > 0) {
        if ((n & 1) == 1) {
            ret = multiply(ret, a);
        }
        n >>= 1;
        a = multiply(a, a);
    }
    return ret;
};
var multiply = function (a, b) {
    let c = [
        [0, 0],
        [0, 0],
    ];
    for (let i = 0; i < 2; i++) {
        for (let j = 0; j < 2; j++) {
            c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
        }
    }
    return c;
};
