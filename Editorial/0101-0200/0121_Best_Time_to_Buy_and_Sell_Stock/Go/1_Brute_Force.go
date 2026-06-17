func maxProfit(prices []int) int {
    maxprofit := 0
    for i := 0; i < len(prices)-1; i++ {
        for j := i + 1; j < len(prices); j++ {
            profit := prices[j] - prices[i]
            if profit > maxprofit {
                maxprofit = profit
            }
        }
    }
    return maxprofit
}
