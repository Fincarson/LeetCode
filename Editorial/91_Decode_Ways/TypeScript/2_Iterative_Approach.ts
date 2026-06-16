function numDecodings(s: string): number {
    // DP array to store the subproblem results
    let dp: number[] = new Array(s.length + 1).fill(0);
    dp[0] = 1;
    // Ways to decode a string of size 1 is 1. Unless the string is '0'.
    // '0' doesn't have a single digit decode.
    dp[1] = s[0] === "0" ? 0 : 1;
    for (let i = 2; i < dp.length; i++) {
        // Check if successful single digit decode is possible.
        if (s[i - 1] !== "0") {
            dp[i] = dp[i - 1];
        }
        // Check if successful two digit decode is possible.
        let twoDigit: number = parseInt(s.substring(i - 2, i));
        if (twoDigit >= 10 && twoDigit <= 26) {
            dp[i] += dp[i - 2];
        }
    }
    return dp[s.length];
}
