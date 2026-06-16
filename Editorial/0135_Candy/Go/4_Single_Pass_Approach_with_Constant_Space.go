func count(n int) int {
    // Function to calculate sum of first n natural numbers
    return (n * (n + 1)) / 2
}

func max(a int, b int) int {
    if a > b {
        return a
    }
    return b
}

func candy(ratings []int) int {
    if len(ratings) <= 1 {
        return len(ratings)
    }
    candies := 0
    up := 0
    down := 0
    oldSlope := 0
    for i := 1; i < len(ratings); i++ {
        newSlope := 0
        if ratings[i] > ratings[i-1] {
            newSlope = 1
        } else if ratings[i] < ratings[i-1] {
            newSlope = -1
        }
        if (oldSlope > 0 && newSlope == 0) || (oldSlope < 0 && newSlope >= 0) {
            candies += count(up) + count(down) + max(up, down)
            up = 0
            down = 0
        }
        if newSlope > 0 {
            up++
        }
        if newSlope < 0 {
            down++
        }
        if newSlope == 0 {
            candies++
        }
        oldSlope = newSlope
    }
    candies += count(up) + count(down) + max(up, down) + 1
    return candies
}
