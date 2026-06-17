func trap(height []int) int {
    ans := 0
    current := 0
    var st []int = make([]int, 0)
    for current < len(height) {
        for len(st) != 0 && height[current] > height[st[len(st)-1]] {
            top := st[len(st)-1]
            st = st[:len(st)-1]
            if len(st) == 0 {
                break
            }
            distance := current - st[len(st)-1] - 1
            bounded_height := min(
                height[current],
                height[st[len(st)-1]],
            ) - height[top]
            ans += distance * bounded_height
        }
        st = append(st, current)
        current++
    }
    return ans
}

func min(a int, b int) int {
    if a < b {
        return a
    } else {
        return b
    }
}
