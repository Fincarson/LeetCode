class Solution {
private:
    std::vector<std::pair<int, int>> bfsQueue;

    void dfs(std::vector<std::vector<int>>& grid, int x, int y, int n) {
        grid[x][y] = 2;
        bfsQueue.push_back(std::make_pair(x, y));
        for (auto& pair : std::vector<std::pair<int, int>>{
                 {x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}}) {
            int curX = pair.first, curY = pair.second;
            if (0 <= curX && curX < n && 0 <= curY && curY < n &&
                grid[curX][curY] == 1) {
                dfs(grid, curX, curY, n);
            }
        }
    }

public:
    int shortestBridge(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int firstX = -1, firstY = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    firstX = i;
                    firstY = j;
                    break;
                }
            }
            if (firstX != -1) {
                break;
            }
        }

        dfs(grid, firstX, firstY, n);

        int distance = 0;
        while (!bfsQueue.empty()) {
            std::vector<std::pair<int, int>> newBfs;
            for (auto& pair : bfsQueue) {
                int x = pair.first, y = pair.second;
                for (auto& nextPair : std::vector<std::pair<int, int>>{
                         {x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}}) {
                    int curX = nextPair.first, curY = nextPair.second;
                    if (0 <= curX && curX < n && 0 <= curY && curY < n) {
                        if (grid[curX][curY] == 1) {
                            return distance;
                        } else if (grid[curX][curY] == 0) {
                            newBfs.push_back(std::make_pair(curX, curY));
                            grid[curX][curY] = -1;
                        }
                    }
                }
            }

            bfsQueue.swap(newBfs);
            distance++;
        }

        return distance;
    }
};
