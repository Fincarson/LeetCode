func generateMatrix(n int) [][]int {
    result := make([][]int, n)
    for i := range result {
        result[i] = make([]int, n)
    }
    cnt := 1
    for layer := 0; layer < (n+1)/2; layer++ {
        // direction 1 - traverse from left to right
        for ptr := layer; ptr < n-layer; ptr++ {
            result[layer][ptr] = cnt
            cnt++
        }
        // direction 2 - traverse from top to bottom
        for ptr := layer + 1; ptr < n-layer; ptr++ {
            result[ptr][n-layer-1] = cnt
            cnt++
        }
        // direction 3 - traverse from right to left
        for ptr := n - layer - 2; ptr >= layer; ptr-- {
            result[n-layer-1][ptr] = cnt
            cnt++
        }
        // direction 4 - traverse from bottom to top
        for ptr := n - layer - 2; ptr > layer; ptr-- {
            result[ptr][layer] = cnt
            cnt++
        }
    }
    return result
}
