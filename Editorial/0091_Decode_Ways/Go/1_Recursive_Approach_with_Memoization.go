func recursiveWithMemo(index int, str string, memo map[int]int) int {
    if val, ok := memo[index]; ok {
        return val
    }
    if index == len(str) {
        return 1
    }
    if str[index] == '0' {
        return 0
    }
    if index == len(str)-1 {
        return 1
    }
    ans := recursiveWithMemo(index+1, str, memo)
    substrNum, _ := strconv.Atoi(str[index : index+2])
    if substrNum <= 26 {
        ans += recursiveWithMemo(index+2, str, memo)
    }
    memo[index] = ans
    return ans
}

func numDecodings(s string) int {
    memo := make(map[int]int)
    return recursiveWithMemo(0, s, memo)
}
