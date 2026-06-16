class Solution:
    def minimumSemesters(self, N: int, relations: List[List[int]]) -> int:
        graph = {i: [] for i in range(1, N + 1)}
        for start_node, end_node in relations:
            graph[start_node].append(end_node)

        # check if the graph contains a cycle
        visited = {}

        def dfs_check_cycle(node: int) -> bool:
            # return True if graph has a cycle
            if node in visited:
                return visited[node]
            else:
                # mark as visiting
                visited[node] = -1
            for end_node in graph[node]:
                if dfs_check_cycle(end_node):
                    # we meet a cycle!
                    return True
            # mark as visited
            visited[node] = False
            return False

        # if has cycle, return -1
        for node in graph.keys():
            if dfs_check_cycle(node):
                return -1

        # if no cycle, return the longest path
        visited_length = {}

        def dfs_max_path(node: int) -> int:
            # return the longest path (inclusive)
            if node in visited_length:
                return visited_length[node]
            max_length = 1
            for end_node in graph[node]:
                length = dfs_max_path(end_node)
                max_length = max(length+1, max_length)
            # store it
            visited_length[node] = max_length
            return max_length

        return max(dfs_max_path(node)for node in graph.keys())
