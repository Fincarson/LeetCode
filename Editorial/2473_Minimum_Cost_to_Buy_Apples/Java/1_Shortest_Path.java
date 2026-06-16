class Solution {
    public long[] minCost(int n, int[][] roads, int[] appleCost, int k) {
        // Store the graph as a list of lists
        // The rows represent the cities (vertices)
        // The columns store an adjacency list of road, cost pairs (edge, weight)
        List<List<Pair<Integer, Integer>>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        // Add each road to the graph using adjacency lists
        // Store each city at graph[city - 1]
        for (int[] road : roads) {
            int cityA = road[0] - 1, cityB = road[1] - 1, cost = road[2];
            graph.get(cityA).add(new Pair<Integer, Integer>(cityB, cost));
            graph.get(cityB).add(new Pair<Integer, Integer>(cityA, cost));
        }

        // Find the minimum cost to buy an apple starting in each city
        long[] result = new long[n];
        for (int startCity = 0; startCity < n; startCity++) {
            result[startCity] = shortestPath(startCity, graph, appleCost, k, n);
        }

        return result;
    }

    // Finds the minimum cost to buy an apple from the start city
    private long shortestPath(int startCity, List<List<Pair<Integer, Integer>>> graph,
                              int[] appleCost, int k, int n) {
        // Stores the travel cost reach each city from the start city
        int[] travelCosts = new int[n];
        Arrays.fill(travelCosts, Integer.MAX_VALUE);
        travelCosts[startCity] = 0;

        // Initialize the heap (priority queue) with the starting city
        Queue<int[]> heap = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        heap.offer(new int[] { 0, startCity });
        long minCost = Integer.MAX_VALUE;

        while (!heap.isEmpty()) {
            // Remove the city with the minimum cost from the top of the heap
            int[] current = heap.poll();
            int travelCost = current[0];
            int currCity = current[1];

            // Update the min cost if the curr city has a smaller total cost
            minCost = Math.min(minCost, 
                               (long) appleCost[currCity] + (k + 1) * travelCost);

            // Add each neighboring city to the heap if an apple is cheaper
            for (Pair<Integer, Integer> next : graph.get(currCity)) {
                int neighbor = next.getKey();
                int nextCost = travelCost + next.getValue();
                if (nextCost < travelCosts[neighbor]) {
                    travelCosts[neighbor] = nextCost;
                    heap.offer(new int[] { nextCost, neighbor });
                }
            }
        }
        return minCost;
    }
}
