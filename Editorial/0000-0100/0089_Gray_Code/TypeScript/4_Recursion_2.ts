let nextNum = 0;
function grayCode(n: number): number[] {
    let result: number[] = [];
    grayCodeHelper(result, n);
    nextNum = 0; //reset global variable after all recursions
    return result;
}
let grayCodeHelper = function (result: number[], n: number): void {
    if (n == 0) {
        result.push(nextNum);
        return;
    }
    grayCodeHelper(result, n - 1);
    // Flip the bit at (n - 1)th position from right
    nextNum = nextNum ^ (1 << (n - 1));
    grayCodeHelper(result, n - 1);
};
