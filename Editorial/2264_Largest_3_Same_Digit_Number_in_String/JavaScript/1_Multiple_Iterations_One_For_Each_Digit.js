const sameDigitNumbers = ["999", "888", "777", "666", "555", "444", "333", "222", "111", "000"];

// Check whether the 'num' string contains the 'sameDigitNumber' string or not.
let contains = (sameDigitNumber, num) => {
    for (let index = 0; index <= num.length - 3; ++index) {
        if (num[index] === sameDigitNumber[0] &&
            num[index + 1] === sameDigitNumber[1] &&
            num[index + 2] === sameDigitNumber[2]) {
            return true;
        }
    }
    return false;
};

let largestGoodInteger = num => {
    // Iterate on all 'sameDigitNumbers' and check if the string 'num' contains it.
    for (const sameDigitNumber of sameDigitNumbers) {
        if (contains(sameDigitNumber, num)) {
            // Return the current 'sameDigitNumber'.
            return sameDigitNumber;
        }
    }
    // No 3 consecutive same digits are present in the string 'num'.
    return "";
};
