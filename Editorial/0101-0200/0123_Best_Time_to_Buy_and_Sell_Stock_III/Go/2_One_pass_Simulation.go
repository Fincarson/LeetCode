func maxProfit(prices []int) int {
    t1Cost := math.MaxInt32
    t2Cost := math.MaxInt32
    t1Profit := 0
    t2Profit := 0
    for _, price := range prices {
        // the maximum profit if only one transaction is allowed
        t1Cost = int(math.Min(float64(t1Cost), float64(price)))
        t1Profit = int(math.Max(float64(t1Profit), float64(price-t1Cost)))
        // reinvest the gained profit in the second transaction
        t2Cost = int(math.Min(float64(t2Cost), float64(price-t1Profit)))
        t2Profit = int(math.Max(float64(t2Profit), float64(price-t2Cost)))
    }
    return t2Profit
}
