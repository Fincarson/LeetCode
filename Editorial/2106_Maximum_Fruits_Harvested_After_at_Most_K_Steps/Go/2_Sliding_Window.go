func maxTotalFruits(fruits [][]int, startPos int, k int) int {
    left := 0
    right := 0
    n := len(fruits)
    sum := 0
    ans := 0

    step := func(left int, right int) int {
        if fruits[right][0] <= startPos {
            return startPos - fruits[left][0]
        } else if fruits[left][0] >= startPos {
            return fruits[right][0] - startPos
        } else {
            return min(abs(startPos-fruits[right][0]), abs(startPos-fruits[left][0])) + fruits[right][0] - fruits[left][0]
        }
    }
    // each time fix the right boundary of the window
    for right < n {
        sum += fruits[right][1]
        // move left boundary
        for left <= right && step(left, right) > k {
            sum -= fruits[left][1]
            left++
        }
        ans = max(ans, sum)
        right++
    }
    return ans
}

func min(a, b int) int {
    if a > b {
        return b
    }
    return a
}

func max(a, b int) int {
    if b > a {
        return b
    }
    return a
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}
