/* TypeScript */
function climbStairs(n: number): number {
    let q: number[][] = [
        [1, 1],
        [1, 0],
    ];
    let res: number[][] = pow(q, n);
    return res[0][0];
}
function pow(a: number[][], n: number): number[][] {
    let ret: number[][] = [
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
}
function multiply(a: number[][], b: number[][]): number[][] {
    let c: number[][] = [
        [0, 0],
        [0, 0],
    ];
    for (let i = 0; i < 2; i++) {
        for (let j = 0; j < 2; j++) {
            c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
        }
    }
    return c;
}
