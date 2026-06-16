type TrieNode struct {
    isWord   bool
    children map[rune]*TrieNode
}

func wordBreak(s string, wordDict []string) bool {
    root := &TrieNode{children: make(map[rune]*TrieNode)}
    for _, word := range wordDict {
        curr := root
        for _, c := range word {
            if _, ok := curr.children[c]; !ok {
                curr.children[c] = &TrieNode{children: make(map[rune]*TrieNode)}
            }
            curr = curr.children[c]
        }
        curr.isWord = true
    }
    dp := make([]bool, len(s))
    for i := range s {
        if i == 0 || dp[i-1] {
            curr := root
            for j, c := range s[i:] {
                if _, ok := curr.children[c]; !ok {
                    // No words exist
                    break
                }
                curr = curr.children[c]
                if curr.isWord {
                    dp[i+j] = true
                }
            }
        }
    }
    return dp[len(s)-1]
}
