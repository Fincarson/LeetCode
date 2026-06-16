class Solution:
    def dfs(self, node, colors, adj, count, visit, inStack):
        # If the node is already in the stack, we have a cycle.
        if inStack[node]:
            return float("inf")
        if visit[node]:
            return count[node][ord(colors[node]) - ord("a")]
        # Mark the current node as visited and part of current recursion stack.
        visit[node] = True
        inStack[node] = True

        if node in adj:
            for neighbor in adj[node]:
                if self.dfs(
                    neighbor, colors, adj, count, visit, inStack
                ) == float("inf"):
                    return float("inf")
                for i in range(26):
                    count[node][i] = max(count[node][i], count[neighbor][i])

        # After all the incoming edges to the node are processed,
        # we count the color on the node itself.
        count[node][ord(colors[node]) - ord("a")] += 1
        # Remove the node from the stack.
        inStack[node] = False
        return count[node][ord(colors[node]) - ord("a")]

    def largestPathValue(self, colors, edges):
        n = len(colors)
        adj = {}
        for edge in edges:
            if edge[0] not in adj:
                adj[edge[0]] = []
            adj[edge[0]].append(edge[1])

        count = [[0] * 26 for _ in range(n)]
        visit = [False] * n
        inStack = [False] * n
        answer = 0
        for i in range(n):
            answer = max(
                answer, self.dfs(i, colors, adj, count, visit, inStack)
            )

        return -1 if answer == float("inf") else answer
