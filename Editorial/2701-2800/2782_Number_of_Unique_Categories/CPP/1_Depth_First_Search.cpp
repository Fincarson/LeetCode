class Solution {
public:
    void dfs(vector<int> adjList[], vector<bool>& vis, int src) {
        vis[src] = true;
        
        for (int i = 0; i < adjList[src].size(); i++) {
            if (!vis[adjList[src][i]]) {
                dfs(adjList, vis, adjList[src][i]);
            }
        }
    }
    
    int numberOfCategories(int n, CategoryHandler* categoryHandler) {
        vector<int> adjList[n];
        
        // Iterate over every pair and add an undirected edge if both belong to the same category.
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (categoryHandler->haveSameCategory(i, j)) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        vector<bool> vis(n, false);
        int components = 0;
        // Each DFS means that a new category is being accessed.
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                components++;
                dfs(adjList, vis, i);
            }
        }
        
        return components;
    }
};
