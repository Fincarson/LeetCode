func candy(ratings []int) int {
    sum := 0
    n := len(ratings)
    left2right := make([]int, n)
    right2left := make([]int, n)
    for i := range left2right {
        left2right[i] = 1
    }
    for i := range right2left {
        right2left[i] = 1
    }
    for i := 1; i < n; i++ {
        if ratings[i] > ratings[i-1] {
            left2right[i] = left2right[i-1] + 1
        }
    }
    for i := n - 2; i >= 0; i-- {
        if ratings[i] > ratings[i+1] {
            right2left[i] = right2left[i+1] + 1
        }
    }
    for i := 0; i < n; i++ {
        sum += max(left2right[i], right2left[i])
    }
    return sum
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
