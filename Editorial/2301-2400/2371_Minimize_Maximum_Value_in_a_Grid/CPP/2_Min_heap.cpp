class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        // Get size of the grid
        int rowSize = grid.size(), colSize = grid[0].size();

        // Initialize priority_queue to store elements with their values and
        // coordinates
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            min_heap;

        // Initialize arrays to keep track of maximum values assigned
        vector<int> rows(rowSize, 1);
        vector<int> cols(colSize, 1);

        // Populate the heap with all elements of the grid
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                min_heap.push(make_pair(grid[i][j], make_pair(i, j)));
            }
        }

        // Process elements in ascending order of their values
        while (!min_heap.empty()) {
            auto element = min_heap.top();

            // Extract additional data from element
            int value = element.first;
            int row = element.second.first;
            int col = element.second.second;

            min_heap.pop();

            // Determine the smallest assignable value based on rows and cols
            // constraints
            int val = max(rows[row], cols[col]);
            grid[row][col] = val;

            // Update rows and cols arrays with the next possible value for each
            // row and column
            rows[row] = val + 1;
            cols[col] = val + 1;
        }

        return grid;
    }
};
