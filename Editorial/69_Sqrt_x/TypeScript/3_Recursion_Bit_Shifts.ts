function mySqrt(x: number): number {
    if (x < 2) return x;
    let left = mySqrt(x >> 2) << 1;
    let right = left + 1;
    return right * right > x ? left : right;
}
