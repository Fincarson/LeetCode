class Solution {
public:
    vector<vector<int>> costs;
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0) {
            return 0;
        }
        this->costs = costs;
        return min(paintCost(0, 0), min(paintCost(0, 1), paintCost(0, 2)));
    }

    int paintCost(int n, int color) {
        int totalCost = costs[n][color];
        if (n == costs.size() - 1) {
        } else if (color == 0) {  // Red
            totalCost += min(paintCost(n + 1, 1), paintCost(n + 1, 2));
        } else if (color == 1) {  // Green
            totalCost += min(paintCost(n + 1, 0), paintCost(n + 1, 2));
        } else {  // Blue
            totalCost += min(paintCost(n + 1, 0), paintCost(n + 1, 1));
        }
        return totalCost;
    }
};
