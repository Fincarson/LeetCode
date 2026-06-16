class Solution {

    public int minimumDistance(
        int n,
        List<List<Integer>> edges,
        int s,
        int[] marked
    ) {
        // Initialize distances array with maximum values
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[s] = 0;

        // Bellman-Ford algorithm: relax edges n-1 times
        for (int iter = 0; iter < n - 1; iter++) {
            for (List<Integer> edge : edges) {
                int from = edge.get(0);
                int to = edge.get(1);
                int weight = edge.get(2);

                // Relaxation step: if we can improve the path to 'to' via 'from'
                if (
                    dist[from] != Integer.MAX_VALUE &&
                    dist[from] + weight < dist[to]
                ) {
                    dist[to] = dist[from] + weight;
                }
            }
        }

        // Find minimum distance to any marked node
        int minDist = Integer.MAX_VALUE;
        for (int node : marked) {
            if (dist[node] < minDist) {
                minDist = dist[node];
            }
        }

        // Return -1 if no path exists, otherwise return the minimum distance
        return minDist == Integer.MAX_VALUE ? -1 : minDist;
    }
}
