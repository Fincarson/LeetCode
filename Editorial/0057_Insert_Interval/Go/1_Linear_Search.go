func insert(intervals [][]int, newInterval []int) [][]int {
    n := len(intervals)
    i := 0
    res := make([][]int, 0)

    // Case 1: No overlapping before merging intervals
    for i < n && intervals[i][1] < newInterval[0] {
        res = append(res, intervals[i])
        i++
    }

    // Case 2: Overlapping and merging intervals
    for i < n && newInterval[1] >= intervals[i][0] {
        newInterval[0] = min(newInterval[0], intervals[i][0])
        newInterval[1] = max(newInterval[1], intervals[i][1])
        i++
    }
    res = append(res, newInterval)

    // Case 3: No overlapping after merging newInterval
    for i < n {
        res = append(res, intervals[i])
        i++
    }

    return res
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
