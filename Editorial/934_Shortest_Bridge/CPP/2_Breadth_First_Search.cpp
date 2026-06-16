class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int firstX = -1, firstY = -1;

        // Find any land cell, and we treat it as a cell of island A.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    firstX = i;
                    firstY = j;
                    break;
                }
            }
        }

        // bfsQue for BFS on land cells of island A; secondBfsQue for BFS on
        // water cells.
        vector<pair<int, int>> bfsQue, secondBfsQue;
        bfsQue.push_back(make_pair(firstX, firstY));
        secondBfsQue.push_back(make_pair(firstX, firstY));
        grid[firstX][firstY] = 2;

        // BFS for all land cells of island A and add them to secondBfsQue.
        while (!bfsQue.empty()) {
            vector<pair<int, int>> newBfs;
            for (pair<int, int> cell : bfsQue) {
                int x = cell.first;
                int y = cell.second;
                for (auto next : vector<pair<int, int>>{
                         {x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}}) {
                    int curX = next.first;
                    int curY = next.second;
                    if (curX >= 0 && curX < n && curY >= 0 && curY < n &&
                        grid[curX][curY] == 1) {
                        newBfs.push_back(make_pair(curX, curY));
                        secondBfsQue.push_back(make_pair(curX, curY));
                        grid[curX][curY] = 2;
                    }
                }
            }
            bfsQue = newBfs;
        }

        int distance = 0;
        while (!secondBfsQue.empty()) {
            vector<pair<int, int>> newBfs;
            for (pair<int, int> cell : secondBfsQue) {
                int x = cell.first;
                int y = cell.second;
                for (auto next : vector<pair<int, int>>{
                         {x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}}) {
                    int curX = next.first;
                    int curY = next.second;
                    if (curX >= 0 && curX < n && curY >= 0 && curY < n) {
                        if (grid[curX][curY] == 1) {
                            return distance;
                        } else if (grid[curX][curY] == 0) {
                            newBfs.push_back(make_pair(curX, curY));
                            grid[curX][curY] = -1;
                        }
                    }
                }
            }

            // Once we finish one round without finding land cells of island B,
            // we will start the next round on all water cells that are 1 cell
            // further away from island A and increment the distance by 1.
            secondBfsQue = newBfs;
            distance++;
        }
        return distance;
    }
};
