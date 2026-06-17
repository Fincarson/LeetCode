func largestRectangleArea(heights []int) int {
    maxArea := 0
    length := len(heights)
    for i := 0; i < length; i++ {
        minHeight := int(^uint(0) >> 1) // set to maximum int value
        for j := i; j < length; j++ {
            if minHeight > heights[j] {
                minHeight = heights[j]
            }
            area := minHeight * (j - i + 1)
            if maxArea < area {
                maxArea = area
            }
        }
    }
    return maxArea
}
