func largestSquareArea(bottomLeft [][]int, topRight [][]int) int64 {
    n := len(bottomLeft)
    var maxSide int64 = 0

    for i := 0; i < n; i++ {
        for j := i + 1; j < n; j++ {
            w := min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0])
            h := min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1])
            
            if w > 0 && h > 0 {
                side := min(w, h)
                if int64(side) > maxSide {
                    maxSide = int64(side)
                }
            }
        }
    }

    return maxSide * maxSide
}
