func maxArea(height []int) int {
    maxarea := 0

    for left := 0; left < len(height); left++ {
        for right := left + 1; right < len(height); right++ {
            width := right - left
            maxarea = max(maxarea, min(height[left], height[right])*width)
        }
    }

    return maxarea
}
