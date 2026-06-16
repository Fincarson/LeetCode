function numDecodings(s: string): number {
    if (s.charAt(0) === "0") {
        return 0;
    }
    let n = s.length;
    let twoBack = 1;
    let oneBack = 1;
    for (let i = 1; i < n; i++) {
        let current = 0;
        if (s.charAt(i) !== "0") {
            current = oneBack;
        }
        let twoDigit = parseInt(s.slice(i - 1, i + 1));
        if (twoDigit >= 10 && twoDigit <= 26) {
            current += twoBack;
        }
        twoBack = oneBack;
        oneBack = current;
    }
    return oneBack;
}
