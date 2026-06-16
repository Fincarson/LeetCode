func maximalRectangle(matrix [][]byte) int {
    maxArea := 0
    width := len(matrix[0])
    heights := make([]int, width)
    for i := 0; i < len(matrix); i++ {
        for j := 0; j < len(matrix[i]); j++ {
            if matrix[i][j] == '1' {
                heights[j]++
            } else {
                heights[j] = 0
            }
        }
        maxArea = int(math.Max(float64(maxArea), float64(leetcode84(heights))))
    }
    return maxArea
}

func leetcode84(height []int) float64 {
    maxArea := 0.0
    stack := make([]int, 0)
    stack = append(stack, -1)
    for i := 0; i < len(height); i++ {
        for stack[len(stack)-1] != -1 && height[i] <= height[stack[len(stack)-1]] {
            pop := stack[len(stack)-1]
            stack = stack[:len(stack)-1]
            maxArea = math.Max(
                maxArea,
                float64(height[pop]*(i-stack[len(stack)-1]-1)),
            )
        }
        stack = append(stack, i)
    }
    for stack[len(stack)-1] != -1 {
        pop := stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        maxArea = math.Max(
            maxArea,
            float64(height[pop]*(len(height)-stack[len(stack)-1]-1)),
        )
    }
    return maxArea
}
