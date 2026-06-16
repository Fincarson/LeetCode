func wordBreak(s string, wordDict []string) bool {
    words := make(map[string]bool)
    queue := make([]int, 0)
    seen := make([]bool, len(s)+1)
    for _, word := range wordDict {
        words[word] = true
    }
    queue = append(queue, 0)
    for len(queue) > 0 {
        start := queue[0]
        queue = queue[1:]
        if start == len(s) {
            return true
        }
        for end := start + 1; end <= len(s); end++ {
            if seen[end] {
                continue
            }
            if _, ok := words[s[start:end]]; ok {
                queue = append(queue, end)
                seen[end] = true
            }
        }
    }
    return false
}
