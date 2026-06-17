class Solution:
    # DFS to detect cycle nodes and mark them in `is_in_cycle`
    def detect_cycle_nodes(
        self, current_node, adjacency_list, is_in_cycle, visited, parent
    ):
        visited[current_node] = True  # Mark current node as visited
        for neighbor in adjacency_list[current_node]:
            if not visited[neighbor]:
                parent[neighbor] = current_node  # Set parent for backtracking
                if self.detect_cycle_nodes(
                    neighbor, adjacency_list, is_in_cycle, visited, parent
                ):
                    return True  # Return True if cycle detected
            elif parent[current_node] != neighbor:  # Cycle detected
                is_in_cycle[neighbor] = True  # Mark the start of the cycle
                temp_node = current_node
                # Backtrack to mark all nodes in the cycle
                while temp_node != neighbor:
                    is_in_cycle[temp_node] = True
                    temp_node = parent[temp_node]
                return True
        return False  # No cycle found in this path

    # DFS to calculate distances from cycle nodes
    def calculate_distances(
        self,
        current_node,
        current_distance,
        adjacency_list,
        distances,
        visited,
        is_in_cycle,
    ):
        distances[current_node] = (
            current_distance  # Set distance for current node
        )
        visited[current_node] = True  # Mark node as visited
        for neighbor in adjacency_list[current_node]:
            if visited[neighbor]:
                continue  # Skip if already visited
            new_distance = (
                0 if is_in_cycle[neighbor] else current_distance + 1
            )  # Reset if on cycle
            self.calculate_distances(
                neighbor,
                new_distance,
                adjacency_list,
                distances,
                visited,
                is_in_cycle,
            )

    def distanceToCycle(self, n, edges):
        is_in_cycle = [False] * n
        visited = [False] * n
        parent = [0] * n
        distances = [0] * n
        adjacency_list = [[] for _ in range(n)]

        # Build adjacency list for the graph
        for edge in edges:
            adjacency_list[edge[0]].append(edge[1])
            adjacency_list[edge[1]].append(edge[0])

        # Detect and mark cycle nodes
        self.detect_cycle_nodes(0, adjacency_list, is_in_cycle, visited, parent)

        # Reset visited array before distance calculation
        visited = [False] * n

        # Calculate distances starting from any cycle node
        for i in range(n):
            if is_in_cycle[i]:
                self.calculate_distances(
                    i, 0, adjacency_list, distances, visited, is_in_cycle
                )
                break  # Only need to start from one cycle node
        return distances
