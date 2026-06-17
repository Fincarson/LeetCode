func countAndSay(n int) string {
    s := "1"
    for i := 2; i <= n; i++ {
        t := ""
        count := 1
        for j := 1; j < len(s); j++ {
            if s[j] == s[j-1] {
                count++
            } else {
                t += strconv.Itoa(count) + string(s[j-1])
                count = 1
            }
        }
        t += strconv.Itoa(count) + string(s[len(s)-1])
        s = t
    }
    return s
}
