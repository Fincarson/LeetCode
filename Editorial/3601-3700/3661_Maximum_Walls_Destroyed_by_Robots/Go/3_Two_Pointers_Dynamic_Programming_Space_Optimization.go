func maxWalls(robots []int, distance []int, walls []int) int {
    n := len(robots)
    type RobotDist struct {
        pos   int
        dist  int
    }
    robotDist := make([]RobotDist, n)
    for i := 0; i < n; i++ {
        robotDist[i] = RobotDist{robots[i], distance[i]}
    }

    sort.Slice(robotDist, func(i, j int) bool {
        return robotDist[i].pos < robotDist[j].pos
    })
    sort.Ints(walls)

    m := len(walls)
    rightPtr, leftPtr, curPtr, robotPtr := 0, 0, 0, 0

    var prevLeft, prevRight, prevNum int
    var subLeft, subRight int

    for i := 0; i < n; i++ {
        robotPos := robotDist[i].pos
        robotDistVal := robotDist[i].dist

        for rightPtr < m && walls[rightPtr] <= robotPos {
            rightPtr++
        }
        pos1 := rightPtr

        for curPtr < m && walls[curPtr] < robotPos {
            curPtr++
        }
        pos2 := curPtr

        leftBound := robotPos - robotDistVal
        if i >= 1 {
            leftBound = max(robotPos-robotDistVal, robotDist[i-1].pos+1)
        }
        for leftPtr < m && walls[leftPtr] < leftBound {
            leftPtr++
        }
        leftPos := leftPtr
        currentLeft := pos1 - leftPos

        rightBound := robotPos + robotDistVal
        if i < n-1 {
            rightBound = min(robotPos+robotDistVal, robotDist[i+1].pos-1)
        }
        for rightPtr < m && walls[rightPtr] <= rightBound {
            rightPtr++
        }
        rightPos := rightPtr
        currentRight := rightPos - pos2

        currentNum := 0
        if i > 0 {
            for robotPtr < m && walls[robotPtr] < robotDist[i-1].pos {
                robotPtr++
            }
            pos3 := robotPtr
            currentNum = pos1 - pos3
        }

        if i == 0 {
            subLeft = currentLeft
            subRight = currentRight
        } else {
            newsubLeft := max(subLeft+currentLeft, subRight-prevRight+min(currentLeft+prevRight, currentNum))
            newsubRight := max(subLeft+currentRight, subRight+currentRight)
            subLeft = newsubLeft
            subRight = newsubRight
        }

        prevLeft = currentLeft
        prevRight = currentRight
        prevNum = currentNum
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
