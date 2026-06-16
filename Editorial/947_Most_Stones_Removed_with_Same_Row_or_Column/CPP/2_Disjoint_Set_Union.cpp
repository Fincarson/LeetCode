class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind uf(n);

        // Populate uf by connecting stones that share the same row or column
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    uf.unionNodes(i, j);
                }
            }
        }

        return n - uf.count;
    }

private:
    // Union-Find data structure for tracking connected components
    class UnionFind {
    public:
        vector<int> parent;  // Array to track the parent of each node
        int count;           // Number of connected components

        UnionFind(int n) {
            parent.resize(n, -1);  // Initialize all nodes as their own parent
            count = n;  // Initially, each stone is its own connected component
        }

        // Find the root of a node with path compression
        int find(int node) {
            if (parent[node] == -1) {
                return node;
            }
            return parent[node] = find(parent[node]);
        }

        // Union two nodes, reducing the number of connected components
        void unionNodes(int n1, int n2) {
            int root1 = find(n1);
            int root2 = find(n2);

            if (root1 == root2) {
                return;  // If they are already in the same component, do
                         // nothing
            }

            // Merge the components and reduce the count of connected components
            count--;
            parent[root1] = root2;
        }
    };
};
