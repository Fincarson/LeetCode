func isValid(s string, wordDict []string, memo []int, i int) bool {
    if i < 0 {
        return true
    }
    if memo[i] != -1 {
        return memo[i] == 1
    }
    for _, word := range wordDict {
        wordLen := len(word)
        if i-wordLen+1 < 0 {
            continue
        }
        if s[i-wordLen+1:i+1] == word && isValid(s, wordDict, memo, i-wordLen) {
            memo[i] = 1
            return true
        }
    }
    memo[i] = 0
    return false
}

func wordBreak(s string, wordDict []string) bool {
    memo := make([]int, len(s))
    for i := range memo {
        memo[i] = -1
    }
    return isValid(s, wordDict, memo, len(s)-1)
}
