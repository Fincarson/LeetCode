func maxWalls(robots []int, distance []int, walls []int) int {
    n := len(robots)
    left := make([]int, n)
    right := make([]int, n)
    num := make([]int, n)
    robotsToDistance := make(map[int]int)

    for i := 0; i < n; i++ {
        robotsToDistance[robots[i]] = distance[i]
    }

    sort.Ints(robots)
    sort.Ints(walls)

    m := len(walls)
    rightPtr, leftPtr, curPtr, robotPtr := 0, 0, 0, 0

    for i := 0; i < n; i++ {
        for rightPtr < m && walls[rightPtr] <= robots[i] {
            rightPtr++
        }
        pos1 := rightPtr

        for curPtr < m && walls[curPtr] < robots[i] {
            curPtr++
        }
        pos2 := curPtr

        leftBound := robots[i] - robotsToDistance[robots[i]]
        if i >= 1 {
            leftBound = max(robots[i]-robotsToDistance[robots[i]], robots[i-1]+1)
        }
        for leftPtr < m && walls[leftPtr] < leftBound {
            leftPtr++
        }
        leftPos := leftPtr
        left[i] = pos1 - leftPos

        rightBound := robots[i] + robotsToDistance[robots[i]]
        if i < n-1 {
            rightBound = min(robots[i]+robotsToDistance[robots[i]], robots[i+1]-1)
        }
        for rightPtr < m && walls[rightPtr] <= rightBound {
            rightPtr++
        }
        rightPos := rightPtr
        right[i] = rightPos - pos2

        if i == 0 {
            continue
        }

        for robotPtr < m && walls[robotPtr] < robots[i-1] {
            robotPtr++
        }
        pos3 := robotPtr
        num[i] = pos1 - pos3
    }

    subLeft, subRight := left[0], right[0]
    for i := 1; i < n; i++ {
        currentLeft := max(subLeft+left[i], subRight-right[i-1]+min(left[i]+right[i-1], num[i]))
        currentRight := max(subLeft+right[i], subRight+right[i])
        subLeft, subRight = currentLeft, currentRight
    }

    return max(subLeft, subRight)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
