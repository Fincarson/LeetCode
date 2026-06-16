var mySqrt = function (x) {
    if (x < 2) return x;
    var left = mySqrt(x >> 2) << 1;
    var right = left + 1;
    return right * right > x ? left : right;
};
