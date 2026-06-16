class Solution:
    def findTheCity(
        self, n: int, edges: List[List[int]], distanceThreshold: int
    ) -> int:
        # Large value to represent infinity
        INF = int(1e9 + 7)
        # Distance matrix to store shortest paths between all pairs of cities
        distance_matrix = [[INF] * n for _ in range(n)]

        # Initialize distance matrix
        for i in range(n):
            distance_matrix[i][i] = 0  # Distance to itself is zero

        # Populate the distance matrix with initial edge weights
        for start, end, weight in edges:
            distance_matrix[start][end] = weight
            distance_matrix[end][start] = weight  # For undirected graph

        # Compute shortest paths using Floyd-Warshall algorithm
        self.floyd(n, distance_matrix)

        # Find the city with the fewest number of reachable cities within the distance threshold
        return self.get_city_with_fewest_reachable(
            n, distance_matrix, distanceThreshold
        )

    # Floyd-Warshall algorithm to compute shortest paths between all pairs of cities
    def floyd(self, n: int, distance_matrix: List[List[int]]):
        # Update distances for each intermediate city

        for k in range(n):
            for i in range(n):
                for j in range(n):
                    # Update shortest path from i to j through k
                    distance_matrix[i][j] = min(
                        distance_matrix[i][j],
                        distance_matrix[i][k] + distance_matrix[k][j],
                    )

    # Determine the city with the fewest number of reachable cities within the distance threshold
    def get_city_with_fewest_reachable(
        self, n: int, distance_matrix: List[List[int]], distance_threshold: int
    ) -> int:
        city_with_fewest_reachable = -1
        fewest_reachable_count = n

        # Count number of cities reachable within the distance threshold for each city
        for i in range(n):
            reachable_count = sum(
                1
                for j in range(n)
                if i != j and distance_matrix[i][j] <= distance_threshold
            )
            # Update the city with the fewest reachable cities
            if reachable_count <= fewest_reachable_count:
                fewest_reachable_count = reachable_count
                city_with_fewest_reachable = i
        return city_with_fewest_reachable
