func maxArea(height []int) int {
    maxArea := 0
    left := 0
    right := len(height) - 1

    for left < right {
        width := right - left
        maxArea = max(maxArea, min(height[left], height[right])*width)
        if height[left] <= height[right] {
            left++
        } else {
            right--
        }
    }
    return maxArea
}
