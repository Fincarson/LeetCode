public class Solution {
    public int MaxProfit(int[] prices) {
        int t1Cost = Int32.MaxValue, t2Cost = Int32.MaxValue;
        int t1Profit = 0, t2Profit = 0;
        foreach (int price in prices) {
            // the maximum profit if only one transaction is allowed
            t1Cost = Math.Min(t1Cost, price);
            t1Profit = Math.Max(t1Profit, price - t1Cost);
            // reinvest the gained profit in the second transaction
            t2Cost = Math.Min(t2Cost, price - t1Profit);
            t2Profit = Math.Max(t2Profit, price - t2Cost);
        }

        return t2Profit;
    }
}
