int maxProfit(int* prices, int pricesSize) {
    int maxprofit = 0;
    for (int i = 0; i < pricesSize - 1; i++) {
        for (int j = i + 1; j < pricesSize; j++) {
            int profit = prices[j] - prices[i];
            if (profit > maxprofit) maxprofit = profit;
        }
    }
    return maxprofit;
}
