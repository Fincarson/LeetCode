func largestRectangleArea(heights []int) int {
    stack := []int{-1}
    maxArea := 0
    for i := range heights {
        for len(stack) > 1 && heights[stack[len(stack)-1]] >= heights[i] {
            currentHeight := heights[stack[len(stack)-1]]
            stack = stack[:len(stack)-1]
            currentWidth := i - stack[len(stack)-1] - 1
            if currentArea := currentHeight * currentWidth; currentArea > maxArea {
                maxArea = currentArea
            }
        }
        stack = append(stack, i)
    }
    for len(stack) > 1 {
        currentHeight := heights[stack[len(stack)-1]]
        stack = stack[:len(stack)-1]
        currentWidth := len(heights) - stack[len(stack)-1] - 1
        if currentArea := currentHeight * currentWidth; currentArea > maxArea {
            maxArea = currentArea
        }
    }
    return maxArea
}
