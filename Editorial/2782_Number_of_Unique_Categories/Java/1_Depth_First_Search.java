class Solution {
    private void dfs(List<Integer>[] adjList, boolean[] vis, int src) {
        vis[src] = true;
         
        for (int i = 0; i < adjList[src].size(); i++) {
            if (!vis[adjList[src].get(i)]) {
                dfs(adjList, vis, adjList[src].get(i));
            }
        }
    }
    
    public int numberOfCategories(int n, CategoryHandler categoryHandler) {
        List<Integer>[] adjList = new ArrayList[n]; 
        for (int i = 0; i < n; i++) {
            adjList[i] = new ArrayList<Integer>();
        } 
        
        // Iterate over every pair and add an undirected edge if both belong to the same category.
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (categoryHandler.haveSameCategory(i, j)) {
                    adjList[i].add(j);
                    adjList[j].add(i);
                }
            }
        }
        
        int components = 0;
        boolean[] vis = new boolean[n];
        // Each DFS means that a new category is being accessed.
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                components++;
                dfs(adjList, vis, i);
            }
        }
        
        return components;
    }
}
