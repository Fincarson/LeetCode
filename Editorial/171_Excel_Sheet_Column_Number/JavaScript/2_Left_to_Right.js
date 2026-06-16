var titleToNumber = function (s) {
    let result = 0;
    let n = s.length;
    for (let i = 0; i < n; i++) {
        result = result * 26;
        // In JavaScript, subtracting characters is subtracting ASCII values of characters
        result += s.charCodeAt(i) - "A".charCodeAt(0) + 1;
    }
    return result;
};
