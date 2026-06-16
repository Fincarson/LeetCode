func lengthOfLastWord(s string) int {
    // trim the trailing spaces
    p := len(s) - 1
    for p >= 0 && s[p] == ' ' {
        p--
    }
    // compute the length of last word
    length := 0
    for p >= 0 && s[p] != ' ' {
        p--
        length++
    }
    return length
}
