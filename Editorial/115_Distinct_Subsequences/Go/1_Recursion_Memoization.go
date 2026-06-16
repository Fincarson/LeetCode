func numDistinct(s string, t string) int {
    memo := make(map[string]int)
    var helper func(i int, j int) int
    helper = func(i int, j int) int {
        if i == len(s) || j == len(t) || len(s)-i < len(t)-j {
            if j == len(t) {
                return 1
            }
            return 0
        }
        key := strconv.Itoa(i) + "," + strconv.Itoa(j)
        if val, ok := memo[key]; ok {
            return val
        }
        ans := helper(i+1, j)
        if s[i] == t[j] {
            ans += helper(i+1, j+1)
        }
        memo[key] = ans
        return ans
    }
    return helper(0, 0)
}
