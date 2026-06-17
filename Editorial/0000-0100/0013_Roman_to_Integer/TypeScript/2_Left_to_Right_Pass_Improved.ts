let values: { [key: string]: number } = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000,
    IV: 4,
    IX: 9,
    XL: 40,
    XC: 90,
    CD: 400,
    CM: 900,
};

function romanToInt(s: string): number {
    let total = 0;
    let i = 0;
    while (i < s.length) {
        if (i < s.length - 1 && s.substring(i, i + 2) in values) {
            total += values[s.substring(i, i + 2)];
            i += 2;
        } else {
            total += values[s.charAt(i)];
            i++;
        }
    }
    return total;
}
