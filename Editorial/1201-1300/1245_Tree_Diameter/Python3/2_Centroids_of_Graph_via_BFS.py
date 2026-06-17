class Solution:
    def treeDiameter(self, edges: List[List[int]]) -> int:

        # build the adjacency list representation of the graph.
        graph = [set() for i in range(len(edges)+1)]
        for edge in edges:
            u, v = edge
            graph[u].add(v)
            graph[v].add(u)

        # find the outer most nodes, _i.e._ leaf nodes
        leaves = []
        for vertex, links in enumerate(graph):
            if len(links) == 1:
                leaves.append(vertex)

        # "peel" the graph layer by layer,
        #   until we have the centroids left.
        layers = 0
        vertex_left = len(edges) + 1
        while vertex_left > 2:
            vertex_left -= len(leaves)
            next_leaves = []
            for leaf in leaves:
                # the only neighbor left on the leaf node.
                neighbor = graph[leaf].pop()
                graph[neighbor].remove(leaf)
                if len(graph[neighbor]) == 1:
                    next_leaves.append(neighbor)
            layers += 1
            leaves = next_leaves

        return layers * 2 + (0 if vertex_left == 1 else 1)
