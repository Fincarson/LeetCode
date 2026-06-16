class Solution {
private:
    vector<vector<int>> costs;
    unordered_map<string, int> memo;

public:
    int minCost(vector<vector<int>>& _costs) {
        if (_costs.size() == 0) {
            return 0;
        }
        this->costs = _costs;
        return min(paintCost(0, 0), min(paintCost(0, 1), paintCost(0, 2)));
    }

private:
    int paintCost(int n, int color) {
        string key = getKey(n, color);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        int totalCost = costs[n][color];
        if (n == costs.size() - 1) {
        } else if (color == 0) {  // Red
            totalCost += min(paintCost(n + 1, 1), paintCost(n + 1, 2));
        } else if (color == 1) {  // Green
            totalCost += min(paintCost(n + 1, 0), paintCost(n + 1, 2));
        } else {  // Blue
            totalCost += min(paintCost(n + 1, 0), paintCost(n + 1, 1));
        }
        memo[key] = totalCost;

        return totalCost;
    }

    string getKey(int n, int color) {
        return to_string(n) + " " + to_string(color);
    }
};
