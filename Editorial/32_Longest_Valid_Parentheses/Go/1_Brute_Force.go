func isValid(s string) bool {
    stack := []rune{}
    for _, char := range s {
        if char == '(' {
            stack = append(stack, char)
        } else if len(stack) > 0 && stack[len(stack)-1] == '(' {
            stack = stack[:len(stack)-1]
        } else {
            return false
        }
    }
    return len(stack) == 0
}

func longestValidParentheses(s string) int {
    maxlen := 0
    for i := 0; i < len(s); i++ {
        for j := i + 2; j <= len(s); j += 2 {
            if isValid(s[i:j]) {
                if maxlen < j-i {
                    maxlen = j - i
                }
            }
        }
    }
    return maxlen
}
