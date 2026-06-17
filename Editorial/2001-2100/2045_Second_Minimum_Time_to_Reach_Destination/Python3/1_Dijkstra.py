import heapq


class Solution:
    def secondMinimum(
        self, n: int, edges: List[List[int]], time: int, change: int
    ) -> int:
        # prepare the graph adjacency list
        adj = [[] for _ in range(n + 1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        dist1 = [float("inf")] * (n + 1)
        dist2 = [float("inf")] * (n + 1)
        freq = [0] * (n + 1)
        queue = [(0, 1)]
        dist1[1] = 0

        while queue:
            timeTaken, node = heapq.heappop(queue)
            freq[node] += 1

            # If the node is being visited for the second time and is 'n', return the
            # answer.
            if freq[node] == 2 and node == n:
                return timeTaken
            # If the current light is red, wait till the path turns green.
            if (timeTaken // change) % 2:
                timeTaken = change * (timeTaken // change + 1) + time
            else:
                timeTaken = timeTaken + time

            for neighbor in adj[node]:
                # Ignore nodes that have already popped out twice, we are not interested in
                # visiting them again.
                if freq[neighbor] == 2:
                    continue

                # Update dist1 if it's more than the current timeTaken and store its value in
                # dist2 since that becomes the second minimum value now.
                if dist1[neighbor] > timeTaken:
                    dist2[neighbor] = dist1[neighbor]
                    dist1[neighbor] = timeTaken
                    heapq.heappush(queue, (timeTaken, neighbor))
                elif (
                    dist2[neighbor] > timeTaken and dist1[neighbor] != timeTaken
                ):
                    dist2[neighbor] = timeTaken
                    heapq.heappush(queue, (timeTaken, neighbor))
        return 0
