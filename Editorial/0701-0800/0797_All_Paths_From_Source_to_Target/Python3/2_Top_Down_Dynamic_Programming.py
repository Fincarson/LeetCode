class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:

        target = len(graph) - 1

        # apply the memoization
        @lru_cache(maxsize=None)
        def all_paths_to_target(curr_node):
            if curr_node == target:
                return [[target]]

            results = []
            for next_node in graph[curr_node]:
                for path in all_paths_to_target(next_node):
                    results.append([curr_node] + path)

            return results

        return all_paths_to_target(0)
