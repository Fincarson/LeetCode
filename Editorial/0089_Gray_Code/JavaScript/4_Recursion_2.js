let nextNum = 0;
var grayCode = function (n) {
    let result = [];
    grayCodeHelper(result, n);
    nextNum = 0; // reset global variable
    return result;
};
let grayCodeHelper = function (result, n) {
    if (n == 0) {
        result.push(nextNum);
        return;
    }
    grayCodeHelper(result, n - 1);
    // Flip the bit at (n - 1)th position from right
    nextNum = nextNum ^ (1 << (n - 1));
    grayCodeHelper(result, n - 1);
};
