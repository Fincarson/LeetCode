int max(int x, int y) { return (x > y) ? x : y; }
int min(int x, int y) { return (x > y) ? y : x; }
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) return 0;
    int leftMin = prices[0];
    int rightMax = prices[pricesSize - 1];
    int leftProfits[pricesSize];
    int rightProfits[pricesSize + 1];
    memset(rightProfits, 0, sizeof(rightProfits));
    int base = 0;
    memset(leftProfits, base, sizeof(leftProfits));
    for (int l = 1; l < pricesSize; ++l) {
        leftProfits[l] = max(leftProfits[l - 1], prices[l] - leftMin);
        leftMin = min(leftMin, prices[l]);
        int r = pricesSize - 1 - l;
        rightProfits[r] = max(rightProfits[r + 1], rightMax - prices[r]);
        rightMax = max(rightMax, prices[r]);
    }
    int maxProfit = 0;
    for (int i = 0; i < pricesSize; ++i)
        maxProfit = max(maxProfit, leftProfits[i] + rightProfits[i + 1]);
    return maxProfit;
}
