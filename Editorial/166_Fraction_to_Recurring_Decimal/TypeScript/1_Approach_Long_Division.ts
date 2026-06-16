function fractionToDecimal(numerator: number, denominator: number): string {
    if (numerator === 0) {
        return "0";
    }
    var fraction = [];
    if (
        (numerator < 0 && denominator >= 0) ||
        (numerator >= 0 && denominator < 0)
    ) {
        fraction.push("-");
    }
    var dividend = Math.abs(numerator);
    var divisor = Math.abs(denominator);
    fraction.push(Math.floor(dividend / divisor).toString());
    var remainder = dividend % divisor;
    if (remainder === 0) {
        return fraction.join("");
    }
    fraction.push(".");
    var map = new Map<number, number>();
    while (remainder !== 0) {
        if (map.has(remainder)) {
            fraction.splice(map.get(remainder) as number, 0, "(");
            fraction.push(")");
            break;
        }
        map.set(remainder, fraction.length);
        remainder *= 10;
        fraction.push(Math.floor(remainder / divisor).toString());
        remainder %= divisor;
    }
    return fraction.join("");
}
