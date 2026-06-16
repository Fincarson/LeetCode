class Solution {
public:
    // Direction vectors for up, down, left, right movement
    const vector<vector<int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    int getFood(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> start = {-1, -1};
        vector<vector<int>> foods;

        // Find starting position and all food locations
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == '*') {
                    start = {r, c};
                } else if (grid[r][c] == '#') {
                    foods.push_back({r, c});
                }
            }
        }

        if (foods.empty()) {
            return -1;
        }

        // Track visited cells to avoid cycles
        vector<vector<bool>> seen(rows, vector<bool>(cols, false));

        // Priority queue stores: [estimated total cost, steps taken, row, col]
        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(
            comp);

        // Calculate initial Manhattan distance estimate to nearest food
        int initCost = calcDist(start[0], start[1], foods);
        pq.push({initCost, 0, start[0], start[1]});

        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            int estCost = curr[0];
            int steps = curr[1];
            int r = curr[2];
            int c = curr[3];

            // Try all four directions
            for (auto& d : dirs) {
                int newR = r + d[0];
                int newC = c + d[1];

                if (!isValid(grid, newR, newC) || seen[newR][newC]) {
                    continue;
                }

                // If food found, return total steps taken
                if (grid[newR][newC] == '#') {
                    return steps + 1;
                } else {
                    seen[newR][newC] = true;
                    // Calculate new Manhattan distance estimate
                    int newEst = calcDist(newR, newC, foods);
                    pq.push({newEst + steps + 1, steps + 1, newR, newC});
                }
            }
        }

        return -1;
    }

private:
    // Calculate Manhattan distance to nearest food
    int calcDist(int r, int c, vector<vector<int>>& foods) {
        int minDist = INT_MAX;
        for (const vector<int>& food : foods) {
            int dist = abs(food[0] - r) + abs(food[1] - c);
            minDist = min(minDist, dist);
        }
        return minDist;
    }

    // Check if position is within grid bounds and not an obstacle
    bool isValid(vector<vector<char>>& grid, int r, int c) {
        return r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() &&
               grid[r][c] != 'X';
    }
};
