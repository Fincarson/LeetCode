func numDecodings(s string) int {
    if string(s[0]) == "0" {
        return 0
    }
    n := len(s)
    twoBack := 1
    oneBack := 1
    for i := 1; i < n; i++ {
        current := 0
        if string(s[i]) != "0" {
            current = oneBack
        }
        twoDigit, _ := strconv.Atoi(s[i-1 : i+1])
        if twoDigit >= 10 && twoDigit <= 26 {
            current += twoBack
        }
        twoBack = oneBack
        oneBack = current
    }
    return oneBack
}
