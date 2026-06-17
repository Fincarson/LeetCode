class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size(), cols = dungeon[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));

        auto get_min_health = [&](int currCell, int nextRow,
                                  int nextCol) -> int {
            if (nextRow >= rows || nextCol >= cols) {
                return INT_MAX;
            }
            int nextCell = dp[nextRow][nextCol];
            // hero needs at least 1 point to survive
            return max(1, nextCell - currCell);
        };

        for (int row = rows - 1; row >= 0; --row) {
            for (int col = cols - 1; col >= 0; --col) {
                int currCell = dungeon[row][col];

                int right_health = get_min_health(currCell, row, col + 1);
                int down_health = get_min_health(currCell, row + 1, col);
                int next_health = min(right_health, down_health);

                int min_health;
                if (next_health != INT_MAX) {
                    min_health = next_health;
                } else {
                    min_health = currCell >= 0 ? 1 : 1 - currCell;
                }

                dp[row][col] = min_health;
            }
        }

        return dp[0][0];
    }
};
