class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        n = len(colors)
        adj = [[] for _ in range(n)]
        indegree = [0] * n

        for edge in edges:
            adj[edge[0]].append(edge[1])
            indegree[edge[1]] += 1

        count = [[0] * 26 for _ in range(n)]
        q = []

        # Push all the nodes with indegree zero in the queue.
        for i in range(n):
            if indegree[i] == 0:
                q.append(i)

        answer = 0
        nodesSeen = 0
        while q:
            node = q.pop(0)
            answer = max(answer, count[node][ord(colors[node]) - ord("a")] + 1)
            count[node][ord(colors[node]) - ord("a")] += 1
            nodesSeen += 1

            for neighbor in adj[node]:
                for i in range(26):
                    # Try to update the frequency of colors for the neighbor to include paths
                    # that use node->neighbor edge.
                    count[neighbor][i] = max(count[neighbor][i], count[node][i])

                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    q.append(neighbor)

        return answer if nodesSeen == n else -1
