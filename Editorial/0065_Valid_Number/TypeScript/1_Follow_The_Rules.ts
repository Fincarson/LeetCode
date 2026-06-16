function isNumber(s: string): boolean {
    let seenDigit: boolean = false;
    let seenExponent: boolean = false;
    let seenDot: boolean = false;
    for (let i = 0; i < s.length; i++) {
        let curr: string = s[i];
        if (!isNaN(parseInt(curr))) {
            seenDigit = true;
        } else if (curr == "+" || curr == "-") {
            if (i > 0 && s[i - 1] != "e" && s[i - 1] != "E") {
                return false;
            }
        } else if (curr == "e" || curr == "E") {
            if (seenExponent || !seenDigit) {
                return false;
            }
            seenExponent = true;
            seenDigit = false;
        } else if (curr == ".") {
            if (seenDot || seenExponent) {
                return false;
            }
            seenDot = true;
        } else {
            return false;
        }
    }
    return seenDigit;
}
