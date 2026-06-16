func maxPoints(points [][]int) int {
    n := len(points)
    if n == 1 {
        return 1
    }
    result := 2
    for i := 0; i < n; i++ {
        cnt := make(map[float64]int)
        for j := 0; j < n; j++ {
            if j != i {
                key := math.Atan2(
                    float64(points[j][1]-points[i][1]),
                    float64(points[j][0]-points[i][0]),
                )
                cnt[key]++
            }
        }
        maxCnt := 0
        for _, v := range cnt {
            if v > maxCnt {
                maxCnt = v
            }
        }
        result = max(result, maxCnt+1)
    }
    return result
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
