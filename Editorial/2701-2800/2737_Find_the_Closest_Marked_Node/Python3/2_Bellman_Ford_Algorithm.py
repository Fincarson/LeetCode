class Solution:
    def minimumDistance(
        self, n: int, edges: list[list[int]], s: int, marked: list[int]
    ) -> int:
        # Initialize distances array with maximum values
        dist = [float("inf")] * n
        dist[s] = 0

        # Bellman-Ford algorithm: relax edges n-1 times
        for _ in range(n - 1):
            for from_node, to_node, weight in edges:
                # Relaxation step: if we can improve the path to 'to_node' via 'from_node'
                if (
                    dist[from_node] != float("inf")
                    and dist[from_node] + weight < dist[to_node]
                ):
                    dist[to_node] = dist[from_node] + weight

        # Find minimum distance to any marked node
        min_dist = min((dist[node] for node in marked), default=float("inf"))

        # Return -1 if no path exists, otherwise return the minimum distance
        return -1 if min_dist == float("inf") else min_dist
