class Solution {

    public int countCompleteComponents(int n, int[][] edges) {
        // Adjacency lists for each vertex
        List<Integer>[] graph = new ArrayList[n];

        // Initialize empty adjacency lists
        for (int vertex = 0; vertex < n; vertex++) {
            graph[vertex] = new ArrayList<>();
        }

        // Build adjacency lists from edges
        for (int[] edge : edges) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }

        int completeCount = 0;
        Set<Integer> visited = new HashSet<>();

        // Process each unvisited vertex
        for (int vertex = 0; vertex < n; vertex++) {
            if (visited.contains(vertex)) continue;

            // arr[0] = vertices count, arr[1] = total edges count
            int[] componentInfo = new int[2];
            dfs(vertex, graph, visited, componentInfo);

            // Check if component is complete - edges should be vertices * (vertices-1)
            if (componentInfo[0] * (componentInfo[0] - 1) == componentInfo[1]) {
                completeCount++;
            }
        }
        return completeCount;
    }

    private void dfs(
        int curr,
        List<Integer>[] graph,
        Set<Integer> visited,
        int[] componentInfo
    ) {
        visited.add(curr);
        componentInfo[0]++; // Increment vertex count
        componentInfo[1] += graph[curr].size(); // Add edges from current vertex

        // Explore unvisited neighbors
        for (int next : graph[curr]) {
            if (!visited.contains(next)) {
                dfs(next, graph, visited, componentInfo);
            }
        }
    }
}
