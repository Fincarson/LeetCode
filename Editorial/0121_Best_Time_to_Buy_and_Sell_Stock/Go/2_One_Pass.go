func maxProfit(prices []int) int {
    minprice := int(^uint(0) >> 1)
    maxprofit := 0
    for i := 0; i < len(prices); i++ {
        if prices[i] < minprice {
            minprice = prices[i]
        } else if prices[i]-minprice > maxprofit {
            maxprofit = prices[i] - minprice
        }
    }
    return maxprofit
}
