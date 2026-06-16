func max(x int, y int) int {
    if x > y {
        return x
    }
    return y
}

func min(x int, y int) int {
    if x > y {
        return y
    }
    return x
}

func maxProfit(prices []int) int {
    length := len(prices)
    if length <= 1 {
        return 0
    }
    leftMin := prices[0]
    rightMax := prices[length-1]
    leftProfits := make([]int, length)
    rightProfits := make([]int, length+1)
    for l := 1; l < length; l++ {
        leftProfits[l] = max(leftProfits[l-1], prices[l]-leftMin)
        leftMin = min(leftMin, prices[l])
        r := length - 1 - l
        rightProfits[r] = max(rightProfits[r+1], rightMax-prices[r])
        rightMax = max(rightMax, prices[r])
    }
    maxProfit := 0
    for i := 0; i < length; i++ {
        maxProfit = max(maxProfit, leftProfits[i]+rightProfits[i+1])
    }
    return maxProfit
}
