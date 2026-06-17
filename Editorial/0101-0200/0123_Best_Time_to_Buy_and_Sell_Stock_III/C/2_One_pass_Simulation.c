int maxProfit(int* prices, int pricesSize) {
    int t1Cost = INT_MAX, t2Cost = INT_MAX;
    int t1Profit = 0, t2Profit = 0;
    for (int i = 0; i < pricesSize; i++) {
        // the maximum profit if only one transaction is allowed
        t1Cost = fmin(t1Cost, prices[i]);
        t1Profit = fmax(t1Profit, prices[i] - t1Cost);
        // reinvest the gained profit in the second transaction
        t2Cost = fmin(t2Cost, prices[i] - t1Profit);
        t2Profit = fmax(t2Profit, prices[i] - t2Cost);
    }
    return t2Profit;
}
