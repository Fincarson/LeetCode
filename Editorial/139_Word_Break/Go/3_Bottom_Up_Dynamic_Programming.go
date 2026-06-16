func wordBreak(s string, wordDict []string) bool {
    dp := make([]bool, len(s))
    for i := range s {
        for _, word := range wordDict {
            // Handle out of bounds case
            if i < len(word)-1 {
                continue
            }
            if i == len(word)-1 || dp[i-len(word)] {
                if s[i-len(word)+1:i+1] == word {
                    dp[i] = true
                    break
                }
            }
        }
    }
    return dp[len(s)-1]
}
