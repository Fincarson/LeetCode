class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0) return 0;

        vector<int> previousRow = costs[costs.size() - 1];

        for (int n = costs.size() - 2; n >= 0; n--) {
            vector<int> currentRow = costs[n];
            // Total cost of painting the nth house red.
            currentRow[0] += min(previousRow[1], previousRow[2]);
            // Total cost of painting the nth house green.
            currentRow[1] += min(previousRow[0], previousRow[2]);
            // Total cost of painting the nth house blue.
            currentRow[2] += min(previousRow[0], previousRow[1]);
            previousRow = currentRow;
        }

        return min({previousRow[0], previousRow[1], previousRow[2]});
    }
};
