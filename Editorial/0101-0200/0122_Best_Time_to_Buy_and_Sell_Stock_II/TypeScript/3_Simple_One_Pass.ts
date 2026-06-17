function maxProfit(prices: number[]): number {
    let maxprofit: number = 0;
    for (let i = 1; i < prices.length; i++) {
        if (prices[i] > prices[i - 1]) {
            maxprofit += prices[i] - prices[i - 1];
        }
    }
    return maxprofit;
}
