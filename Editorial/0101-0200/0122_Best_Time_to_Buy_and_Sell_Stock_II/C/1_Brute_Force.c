int calculate(int* prices, int pricesSize, int s);
int maxProfit(int* prices, int pricesSize) {
    return calculate(prices, pricesSize, 0);
}
int calculate(int* prices, int pricesSize, int s) {
    if (s >= pricesSize) return 0;
    int max = 0;
    for (int start = s; start < pricesSize; start++) {
        int maxprofit = 0;
        for (int i = start + 1; i < pricesSize; i++) {
            if (prices[start] < prices[i]) {
                int profit = calculate(prices, pricesSize, i + 1) + prices[i] -
                             prices[start];
                if (profit > maxprofit) maxprofit = profit;
            }
        }
        if (maxprofit > max) max = maxprofit;
    }
    return max;
}
