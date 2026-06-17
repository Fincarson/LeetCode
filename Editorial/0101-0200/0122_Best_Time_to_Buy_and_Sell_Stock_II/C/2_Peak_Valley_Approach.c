int maxProfit(int* prices, int pricesSize) {
    int i = 0;
    int valley = prices[0];
    int peak = prices[0];
    int maxprofit = 0;
    while (i < pricesSize - 1) {
        while (i < pricesSize - 1 && prices[i] >= prices[i + 1]) i++;
        valley = prices[i];
        while (i < pricesSize - 1 && prices[i] <= prices[i + 1]) i++;
        peak = prices[i];
        maxprofit += peak - valley;
    }
    return maxprofit;
}
