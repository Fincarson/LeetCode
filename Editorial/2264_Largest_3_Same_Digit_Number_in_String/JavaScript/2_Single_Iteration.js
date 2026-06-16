var largestGoodInteger = function(num) {
    // Assign 'maxDigit' to the NUL character (smallest ASCII value character)
    let maxDigit = '\0';

    // Iterate on characters of the num string.
    for (let index = 0; index <= num.length - 3; ++index) {
        // If 3 consecutive characters are the same,
        // store the character in 'maxDigit' if it's bigger than what it already stores.
        if (num[index] === num[index + 1] && num[index] === num[index + 2]) {
            maxDigit = String.fromCharCode(Math.max(maxDigit.charCodeAt(0), num.charCodeAt(index)));
        }
    }

    // If 'maxDigit' is NUL, return an empty string; otherwise, return a string of size 3 with 'maxDigit' characters.
    return maxDigit === '\0' ? '' : maxDigit.repeat(3);
};
