class Solution:
    def mostProfitablePath(self, edges, bob, amount):
        n = len(amount)
        tree = [[] for _ in range(n)]
        bob_path = {}
        visited = [False] * n
        max_income = float("-inf")

        # Form tree with edges
        for edge in edges:
            tree[edge[0]].append(edge[1])
            tree[edge[1]].append(edge[0])

        # Depth First Search to find Bob's path
        def find_bob_path(node, time):
            bob_path[node] = time
            visited[node] = True

            if node == 0:
                return True
            for neighbor in tree[node]:
                if not visited[neighbor] and find_bob_path(neighbor, time + 1):
                    return True
            bob_path.pop(node, None)
            return False

        # Find Bob's path
        find_bob_path(bob, 0)

        # Reset visited array for Alice's path
        visited = [False] * n

        # Depth First Search to find Alice's optimal path
        def find_alice_path(node, time, income):
            nonlocal max_income
            visited[node] = True

            # Alice reaches the node first
            if node not in bob_path or time < bob_path[node]:
                income += amount[node]
            elif time == bob_path[node]:  # Alice and Bob arrive together
                income += amount[node] // 2

            # Update max value if current node is a leaf
            if len(tree[node]) == 1 and node != 0:
                max_income = max(max_income, income)
            for neighbor in tree[node]:
                if not visited[neighbor]:
                    find_alice_path(neighbor, time + 1, income)

        # Find Alice's path
        find_alice_path(0, 0, 0)

        return max_income
