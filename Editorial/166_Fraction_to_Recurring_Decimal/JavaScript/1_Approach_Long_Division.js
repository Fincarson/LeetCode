var fractionToDecimal = function (numerator, denominator) {
    if (numerator === 0) {
        return "0";
    }
    var fraction = [];
    // If either one is negative (not both)
    if ((numerator < 0) ^ (denominator < 0)) {
        fraction.push("-");
    }
    // Convert to Long or else abs(-2147483648) overflows
    var dividend = Math.abs(numerator);
    var divisor = Math.abs(denominator);
    fraction.push(Math.floor(dividend / divisor).toString());
    var remainder = dividend % divisor;
    if (remainder === 0) {
        return fraction.join("");
    }
    fraction.push(".");
    var map = {};
    while (remainder !== 0) {
        if (remainder in map) {
            fraction.splice(map[remainder], 0, "(");
            fraction.push(")");
            break;
        }
        map[remainder] = fraction.length;
        remainder *= 10;
        fraction.push(Math.floor(remainder / divisor).toString());
        remainder %= divisor;
    }
    return fraction.join("");
};
