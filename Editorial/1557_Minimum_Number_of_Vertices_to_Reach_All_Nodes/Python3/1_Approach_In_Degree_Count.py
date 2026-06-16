class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        in_degree = [False] * n
        for _, node2 in edges:
            in_degree[node2] = True

        return [node for node in range(n) if not in_degree[node]]
