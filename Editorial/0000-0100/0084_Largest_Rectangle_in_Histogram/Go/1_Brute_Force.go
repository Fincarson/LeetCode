func largestRectangleArea(heights []int) int {
    max_area := 0
    inf := int(^uint(0) >> 1)
    for i := 0; i < len(heights); i++ {
        for j := i; j < len(heights); j++ {
            min_height := inf
            for k := i; k <= j; k++ {
                if heights[k] < min_height {
                    min_height = heights[k]
                }
            }
            if min_height*(j-i+1) > max_area {
                max_area = min_height * (j - i + 1)
            }
        }
    }
    return max_area
}
