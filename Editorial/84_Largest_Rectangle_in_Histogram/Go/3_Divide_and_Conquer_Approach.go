func calculateArea(heights []int, start int, end int) int {
    if start > end {
        return 0
    }
    min_index := start
    for i := start; i <= end; i++ {
        if heights[min_index] > heights[i] {
            min_index = i
        }
    }
    return max(heights[min_index]*(end-start+1),
        max(calculateArea(heights, start, min_index-1),
            calculateArea(heights, min_index+1, end)))
}

func largestRectangleArea(heights []int) int {
    return calculateArea(heights, 0, len(heights)-1)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
