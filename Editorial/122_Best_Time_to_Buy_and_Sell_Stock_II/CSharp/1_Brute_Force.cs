public class Solution {
    public int MaxProfit(int[] prices) {
        return Calculate(prices, 0);
    }

    private int Calculate(int[] prices, int s) {
        if (s >= prices.Length)
            return 0;
        int max = 0;
        for (int start = s; start < prices.Length; start++) {
            int maxprofit = 0;
            for (int i = start + 1; i < prices.Length; i++) {
                if (prices[start] < prices[i]) {
                    int profit =
                        Calculate(prices, i + 1) + prices[i] - prices[start];
                    if (profit > maxprofit)
                        maxprofit = profit;
                }
            }

            if (maxprofit > max)
                max = maxprofit;
        }

        return max;
    }
}
