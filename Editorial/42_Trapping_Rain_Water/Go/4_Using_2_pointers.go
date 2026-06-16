func trap(height []int) int {
    left := 0
    right := len(height) - 1
    ans := 0
    left_max := 0
    right_max := 0
    for left < right {
        if height[left] < height[right] {
            if height[left] >= left_max {
                left_max = height[left]
            } else {
                ans += left_max - height[left]
            }
            left++
        } else {
            if height[right] >= right_max {
                right_max = height[right]
            } else {
                ans += right_max - height[right]
            }
            right--
        }
    }
    return ans
}
