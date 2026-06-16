var wordBreak = function (s, wordDict) {
    let dp = new Array(s.length).fill(false);
    for (let i = 0; i < s.length; i++) {
        for (let word of wordDict) {
            // Handle out of bounds case
            if (i < word.length - 1) {
                continue;
            }
            if (i == word.length - 1 || dp[i - word.length]) {
                if (s.substring(i - word.length + 1, i + 1) == word) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[s.length - 1];
};
