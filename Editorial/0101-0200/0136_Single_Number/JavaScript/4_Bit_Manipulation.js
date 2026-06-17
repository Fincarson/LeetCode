// JavaScript
var singleNumber = function (nums) {
    let a = 0;
    for (let i of nums) {
        a ^= i;
    }
    return a;
};
