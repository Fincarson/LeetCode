class Solution {

    public int minimumCost(int n, int[][] highways, int discounts) {
        // Construct the graph from the given highways array
        List<List<int[]>> graph = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            graph.add(new ArrayList<>());
        }
        for (int[] highway : highways) {
            int u = highway[0], v = highway[1], toll = highway[2];
            graph.get(u).add(new int[] { v, toll });
            graph.get(v).add(new int[] { u, toll });
        }

        // Min-heap priority queue to store tuples of (cost, city, discounts used)
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            Comparator.comparingInt(a -> a[0])
        );
        pq.offer(new int[] { 0, 0, 0 }); // Start from city 0 with cost 0 and 0 discounts used

        // 2D array to track minimum distance to each city with a given number of discounts used
        int[][] dist = new int[n][discounts + 1];
        for (int[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        dist[0][0] = 0;

        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int currentCost = current[0], city = current[1], discountsUsed =
                current[2];

            // If this cost is already higher than the known minimum, skip it
            if (currentCost > dist[city][discountsUsed]) {
                continue;
            }

            // Explore all neighbors of the current city
            for (int[] neighbor : graph.get(city)) {
                int nextCity = neighbor[0], toll = neighbor[1];

                // Case 1: Move to the neighbor without using a discount
                if (currentCost + toll < dist[nextCity][discountsUsed]) {
                    dist[nextCity][discountsUsed] = currentCost + toll;
                    pq.offer(
                        new int[] {
                            dist[nextCity][discountsUsed],
                            nextCity,
                            discountsUsed,
                        }
                    );
                }

                // Case 2: Move to the neighbor using a discount if available
                if (discountsUsed < discounts) {
                    int newCostWithDiscount = currentCost + toll / 2;
                    if (
                        newCostWithDiscount < dist[nextCity][discountsUsed + 1]
                    ) {
                        dist[nextCity][discountsUsed + 1] = newCostWithDiscount;
                        pq.offer(
                            new int[] {
                                newCostWithDiscount,
                                nextCity,
                                discountsUsed + 1,
                            }
                        );
                    }
                }
            }
        }

        // Find the minimum cost to reach city n-1 with any number of discounts used
        int minCost = Integer.MAX_VALUE;
        for (int d = 0; d <= discounts; ++d) {
            minCost = Math.min(minCost, dist[n - 1][d]);
        }
        return minCost == Integer.MAX_VALUE ? -1 : minCost;
    }
}
