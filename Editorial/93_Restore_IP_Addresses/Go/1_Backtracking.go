func restoreIpAddresses(s string) []string {
    var ans []string
    var valid func(s string, start int, length int) bool
    valid = func(s string, start int, length int) bool {
        return length == 1 ||
            (s[start] != '0' && (length < 3 || s[start:start+length] <= "255"))
    }
    var helper func(s string, startIndex int, dots []int)
    helper = func(s string, startIndex int, dots []int) {
        remainingLength := len(s) - startIndex
        remainingNumberOfIntegers := 4 - len(dots)
        if remainingLength > remainingNumberOfIntegers*3 ||
            remainingLength < remainingNumberOfIntegers {
            return
        }
        if len(dots) == 3 {
            if valid(s, startIndex, remainingLength) {
                temp := ""
                last := 0
                for i := 0; i < len(dots); i++ {
                    temp += s[last : last+dots[i]]
                    if last != startIndex {
                        temp += "."
                    }
                    last += dots[i]
                }
                temp += s[startIndex:]
                ans = append(ans, temp)
            }
            return
        }
        for curPos := 1; curPos <= 3 && curPos <= remainingLength; curPos++ {
            dots = append(dots, curPos)
            if valid(s, startIndex, curPos) {
                helper(s, startIndex+curPos, dots)
            }
            dots = dots[:len(dots)-1]
        }
    }
    helper(s, 0, []int{})
    return ans
}
