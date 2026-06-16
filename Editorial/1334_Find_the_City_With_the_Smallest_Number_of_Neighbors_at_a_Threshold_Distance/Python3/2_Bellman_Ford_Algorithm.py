class Solution:
    def findTheCity(
        self, n: int, edges: List[List[int]], distanceThreshold: int
    ) -> int:
        # Large value to represent infinity
        INF = int(1e9) + 7
        # Matrix to store shortest path distances from each city
        shortestPathMatrix = [[INF] * n for _ in range(n)]

        # Compute shortest paths from each city using Bellman-Ford algorithm
        for i in range(n):
            self.bellmanFord(n, edges, shortestPathMatrix[i], i)

        # Find the city with the fewest number of reachable cities within the distance threshold
        return self.getCityWithFewestReachable(
            n, shortestPathMatrix, distanceThreshold
        )

    # Bellman-Ford algorithm to find shortest paths from a source city
    def bellmanFord(
        self,
        n: int,
        edges: List[List[int]],
        shortestPathDistances: List[int],
        source: int,
    ) -> None:
        # Initialize distances from the source
        shortestPathDistances[:] = [float("inf")] * n
        shortestPathDistances[source] = 0  # Distance to source itself is zero

        # Relax edges up to n-1 times with early stopping
        for _ in range(n - 1):
            updated = False
            for start, end, weight in edges:
                if (
                    shortestPathDistances[start] != float("inf")
                    and shortestPathDistances[start] + weight
                    < shortestPathDistances[end]
                ):
                    shortestPathDistances[end] = (
                        shortestPathDistances[start] + weight
                    )
                    updated = True
                if (
                    shortestPathDistances[end] != float("inf")
                    and shortestPathDistances[end] + weight
                    < shortestPathDistances[start]
                ):
                    shortestPathDistances[start] = (
                        shortestPathDistances[end] + weight
                    )
                    updated = True
            if not updated:
                break  # Stop early if no updates

    # Determine the city with the fewest number of reachable cities within the distance threshold
    def getCityWithFewestReachable(
        self,
        n: int,
        shortestPathMatrix: List[List[int]],
        distanceThreshold: int,
    ) -> int:
        cityWithFewestReachable = -1
        fewestReachableCount = n

        # Count number of cities reachable within the distance threshold for each city
        for i in range(n):
            reachableCount = 0
            for j in range(n):
                if i == j:
                    continue  # Skip self
                if shortestPathMatrix[i][j] <= distanceThreshold:
                    reachableCount += 1

            # Update the city with the fewest reachable cities
            if reachableCount <= fewestReachableCount:
                fewestReachableCount = reachableCount
                cityWithFewestReachable = i
        return cityWithFewestReachable
