func isPalindrome(s string) bool {
    i := 0
    j := len(s) - 1
    for i < j {
        for i < j && !isalnum(s[i]) {
            i++
        }
        for i < j && !isalnum(s[j]) {
            j--
        }
        if tolower(s[i]) != tolower(s[j]) {
            return false
        }
        i++
        j--
    }
    return true
}

func isalnum(c byte) bool {
    return ('0' <= c && c <= '9') || ('a' <= c && c <= 'z') ||
        ('A' <= c && c <= 'Z')
}

func tolower(c byte) byte {
    if 'A' <= c && c <= 'Z' {
        return c - 'A' + 'a'
    }
    return c
}
