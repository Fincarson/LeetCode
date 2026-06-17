class Solution {
    public int numberOfCategories(int n, CategoryHandler categoryHandler) {
        UnionFind uF = new UnionFind(n);
        
        // Iterate over every pair and perform union if both belong to the same category.
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (categoryHandler.haveSameCategory(i, j)) {
                    uF.performUnion(i, j);
                }
            }
        }
        
        return uF.getComponentsCount();
    }
    
    private class UnionFind {
        int[] root;
        int[] componentSize;
        // Number of distinct components in the graph.
        int componentsCount;

        // Initialize the list root and componentSize
        // Each node is root of itself with size 1.
        public UnionFind(int n) {
            componentsCount = n;
            root = new int[n + 1];
            componentSize = new int[n + 1];

            for (int i = 0; i <= n; i++) {
                root[i] = i;
                componentSize[i] = 1;
            }
        }

        // Get the root of a node.
        int findRoot(int x) {
            if (root[x] == x) {
                return x;
            }

            // Path compression.
            return root[x] = findRoot(root[x]);
        }
        
        // Perform the union of two components that belongs to node x and node y.
        void performUnion(int x, int y) {       
            x = findRoot(x); y = findRoot(y);

            if (x == y) {
                return;
            }

            if (componentSize[x] > componentSize[y]) {
                componentSize[x] += componentSize[y];
                root[y] = x;
            } else {
                componentSize[y] += componentSize[x];
                root[x] = y;
            }

            componentsCount--;
        }

        // Returns the number of components.
        int getComponentsCount() {
            return componentsCount;
        }
    }
}
