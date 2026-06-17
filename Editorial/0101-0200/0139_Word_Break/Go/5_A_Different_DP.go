func wordBreak(s string, wordDict []string) bool {
    words := make(map[string]struct{}, len(wordDict))
    for _, word := range wordDict {
        words[word] = struct{}{}
    }
    dp := make([]bool, len(s)+1)
    dp[0] = true
    for i := 1; i <= len(s); i++ {
        for j := 0; j < i; j++ {
            if dp[j] {
                if _, ok := words[s[j:i]]; ok {
                    dp[i] = true
                    break
                }
            }
        }
    }
    return dp[len(s)]
}
