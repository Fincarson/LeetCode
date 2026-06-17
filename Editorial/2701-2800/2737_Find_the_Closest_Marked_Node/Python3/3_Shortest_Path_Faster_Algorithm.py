class Solution:
    def minimumDistance(
        self, n: int, edges: list[list[int]], s: int, marked: list[int]
    ) -> int:
        # Adjacency list representation
        graph = defaultdict(list)

        # Build the graph
        for from_node, to_node, weight in edges:
            graph[from_node].append((to_node, weight))

        # Distance array
        dist = [float("inf")] * n
        dist[s] = 0

        queue = deque([s])

        # Track nodes in queue
        in_queue = [False] * n
        in_queue[s] = True

        while queue:
            current = queue.popleft()
            in_queue[current] = False

            # Explore neighbors
            for next_node, weight in graph[current]:
                # Relaxation step
                if dist[next_node] > dist[current] + weight:
                    dist[next_node] = dist[current] + weight

                    # Add to queue if not already in queue
                    if not in_queue[next_node]:
                        queue.append(next_node)
                        in_queue[next_node] = True

        # Find minimum distance to any marked node
        min_dist = min((dist[node] for node in marked), default=float("inf"))

        return -1 if min_dist == float("inf") else min_dist
