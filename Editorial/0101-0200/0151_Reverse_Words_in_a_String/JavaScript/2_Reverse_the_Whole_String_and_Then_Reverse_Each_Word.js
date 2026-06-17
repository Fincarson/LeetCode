// Translated JavaScript solution
var reverseWords = function (s) {
    // convert string to char array
    // and trim spaces at the same time
    let arr = trimSpaces(s);

    // reverse the whole string
    reverse(arr, 0, arr.length - 1);

    // reverse each word
    reverseEachWord(arr);

    return arr.join("");
};

var trimSpaces = function (s) {
    let left = 0,
        right = s.length - 1;
    // remove leading spaces
    while (left <= right && s[left] === " ") ++left;
    // remove trailing spaces
    while (left <= right && s[right] === " ") --right;
    // reduce multiple spaces to single one
    let output = [];
    while (left <= right) {
        if (s[left] !== " ") output.push(s[left]);
        else if (output[output.length - 1] !== " ") output.push(s[left]);
        ++left;
    }
    return output;
};

var reverseEachWord = function (arr) {
    let n = arr.length;
    let start = 0,
        end = 0;
    while (start < n) {
        // go to the end of the word
        while (end < n && arr[end] !== " ") ++end;
        // reverse the word
        reverse(arr, start, end - 1);
        // move to the next word
        start = end + 1;
        ++end;
    }
};

var reverse = function (arr, start, end) {
    while (start < end) {
        const tmp = arr[start];
        arr[start++] = arr[end];
        arr[end--] = tmp;
    }
};
