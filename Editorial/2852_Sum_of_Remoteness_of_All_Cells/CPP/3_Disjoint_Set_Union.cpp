class Solution {
private:
    // Direction arrays for moving up, down, left, right
    const vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    long long sumRemoteness(vector<vector<int>>& grid) {
        int n = grid.size();
        // Initialize Union-Find data structure with size n*n
        UnionFind uf(n);

        // First pass: Connect all adjacent non-blocked cells into components
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                // Skip blocked cells
                if (grid[row][col] == -1) continue;

                // For each valid cell, check all 4 adjacent cells
                for (auto& d : dir) {
                    int newRow = d[0] + row;
                    int newCol = d[1] + col;
                    // If adjacent cell is valid, connect it to current cell
                    if (isValid(grid, newRow, newCol)) {
                        // Convert 2D coordinates to 1D index and union them
                        uf.unite(getIndex(n, row, col),
                                 getIndex(n, newRow, newCol));
                    }
                }
            }
        }

        // Second pass: Calculate sum of values in each connected component
        long long totalSum = 0;
        // Maps component root to its sum
        unordered_map<int, long long> compSum;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == -1) continue;

                // Find the root of current cell's component
                int parent = uf.find(getIndex(n, row, col));
                // Add current cell's value to its component sum
                compSum[parent] += grid[row][col];
                // Add to total sum of all values
                totalSum += grid[row][col];
            }
        }

        // Third pass: Calculate remoteness sum
        // For each cell, remoteness = (totalSum - sum of its component)
        long long result = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == -1) continue;

                // Get sum of current cell's component
                long long currCompSum = compSum[uf.find(getIndex(n, row, col))];

                result += totalSum - currCompSum;
            }
        }
        return result;
    }

    // UnionFind class to track connected components
    class UnionFind {
    private:
        vector<int> parent;  // parent[i] = -1 means i is a root
        vector<int> rank;

    public:
        UnionFind(int n) {
            parent.resize(n * n, -1);
            rank.resize(n * n, 1);
        }

        // Find with path compression for better amortized performance
        int find(int index) {
            if (parent[index] == -1) return index;
            return parent[index] = find(parent[index]);
        }

        // Union by linking roots directly
        void unite(int idx1, int idx2) {
            int root1 = find(idx1);
            int root2 = find(idx2);

            if (root1 == root2) return;  // Already in same component

            // Make the root with the higher rank the parent of the other root
            if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            } else if (rank[root1] > rank[root2]) {
                parent[root2] = root1;
            } else {
                parent[root2] = root1;
                rank[root1]++;
            }
        }
    };

    // Converts 2D coordinates to 1D index
    int getIndex(int n, int row, int col) { return row * n + col; }

    // Checks if cell (row, col) is within grid bounds and not blocked
    bool isValid(vector<vector<int>>& grid, int row, int col) {
        int n = grid.size();
        return row >= 0 && col >= 0 && row < n && col < n &&
               grid[row][col] != -1;
    }
};
