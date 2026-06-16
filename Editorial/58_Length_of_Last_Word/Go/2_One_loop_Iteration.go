func lengthOfLastWord(s string) int {
    p, length := len(s), 0
    for p > 0 {
        p--
        // we're in the middle of the last word
        if s[p:p+1] != " " {
            length++
        } else if length > 0 { // here is the end of last word
            return length
        }
    }
    return length
}
