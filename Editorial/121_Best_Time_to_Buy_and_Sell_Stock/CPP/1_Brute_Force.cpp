class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                int profit = prices[j] - prices[i];
                if (profit > maxprofit) maxprofit = profit;
            }
        }
        return maxprofit;
    }
};
