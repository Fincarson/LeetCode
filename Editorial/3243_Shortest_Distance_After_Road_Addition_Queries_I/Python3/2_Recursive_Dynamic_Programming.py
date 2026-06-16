class Solution:
    # Recursive function to find the minimum distance from the current node to
    # the destination node (n-1)
    def find_min_distance(self, adj_list, n, current_node, dp):
        # We've reached the destination node
        if current_node == n - 1:
            return 0

        # If this node has already been computed, return the stored value
        if dp[current_node] != -1:
            return dp[current_node]

        min_distance = n

        for neighbor in adj_list[current_node]:
            # Recursively find the minimum distance from the neighbor to the destination
            min_distance = min(
                min_distance,
                self.find_min_distance(adj_list, n, neighbor, dp) + 1,
            )

        # Store the computed minimum distance in the dp array and return it
        dp[current_node] = min_distance
        return min_distance

    def shortestDistanceAfterQueries(self, n, queries):
        dp = [-1] * n  # DP array to store minimum distances from each node
        adj_list = [[] for _ in range(n)]

        # Initialize the graph with edges between consecutive nodes
        for i in range(n - 1):
            adj_list[i].append(i + 1)

        answer = []

        # Process each query to add new edges
        for road in queries:
            u = road[0]
            v = road[1]

            # Add the directed edge from u to v
            adj_list[u].append(v)

            # Find the minimum distance from the starting node (0) to the destination (n-1)
            answer.append(self.find_min_distance(adj_list, n, 0, dp))

            # Clear and reset the dp array
            dp = [-1] * n

        return answer  # Return the results for each query
