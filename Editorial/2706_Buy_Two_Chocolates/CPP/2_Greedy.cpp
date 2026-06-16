class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        // Sort the Array in Increasing Order
        sort(prices.begin(), prices.end());

        // Minimum Cost
        int minCost = prices[0] + prices[1];

        // We can buy chocolates only if we have enough money
        if (minCost <= money) {
            // Return the Amount of Money Left
            return money - minCost;
        } else {
            // We cannot buy chocolates. Return the initial amount of money
            return money;
        }
    }
};
