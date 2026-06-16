int maxProfit(int* prices, int pricesSize) {
    int maxprofit = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > prices[i - 1]) maxprofit += prices[i] - prices[i - 1];
    }
    return maxprofit;
}
