func grayCode(n int) []int {
    seen := map[int]bool{0: true}
    res := []int{0}
    var helper func(n int, seen map[int]bool) bool
    helper = func(n int, seen map[int]bool) bool {
        if len(res) == 1<<n {
            return true
        }
        curr := res[len(res)-1]
        for i := 0; i < n; i++ {
            next := curr ^ (1 << i)
            if seen[next] == false {
                seen[next] = true
                res = append(res, next)
                if helper(n, seen) {
                    return true
                }
                seen[next] = false
                res = res[:len(res)-1]
            }
        }
        return false
    }
    helper(n, seen)
    return res
}
