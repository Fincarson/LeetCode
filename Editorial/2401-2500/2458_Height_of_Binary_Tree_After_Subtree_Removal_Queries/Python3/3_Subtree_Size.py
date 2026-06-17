class Solution:
    def treeQueries(
        self, root: Optional[TreeNode], queries: List[int]
    ) -> List[int]:
        # Dictionary to store the index of each node value
        node_index_map = {}

        # Dictionary to store the number of nodes in the subtree for each node
        subtree_size = {}

        # Lists to store node depths and maximum depths from left and right
        node_depths = []
        max_depth_from_left = []
        max_depth_from_right = []

        # Perform DFS to populate node_index_map and node_depths
        self._dfs(root, 0, node_index_map, node_depths)

        total_nodes = len(node_depths)

        # Calculate subtree sizes
        self._calculate_subtree_size(root, subtree_size)

        # Calculate maximum depths from left and right
        max_depth_from_left.append(node_depths[0])
        max_depth_from_right.append(node_depths[-1])

        for i in range(1, total_nodes):
            max_depth_from_left.append(
                max(max_depth_from_left[i - 1], node_depths[i])
            )
            max_depth_from_right.append(
                max(
                    max_depth_from_right[i - 1],
                    node_depths[total_nodes - i - 1],
                )
            )

        max_depth_from_right.reverse()

        # Process queries
        results = []
        for query_node in queries:
            start_index = node_index_map[query_node] - 1
            end_index = start_index + 1 + subtree_size[query_node]

            max_depth = max_depth_from_left[start_index]
            if end_index < total_nodes:
                max_depth = max(max_depth, max_depth_from_right[end_index])

            results.append(max_depth)

        return results

    # Depth-first search to populate node_index_map and node_depths
    def _dfs(self, root, depth, node_index_map, node_depths):
        if not root:
            return

        node_index_map[root.val] = len(node_depths)
        node_depths.append(depth)

        self._dfs(root.left, depth + 1, node_index_map, node_depths)
        self._dfs(root.right, depth + 1, node_index_map, node_depths)

    # Calculate the size of the subtree for each node
    def _calculate_subtree_size(self, root, subtree_size):
        if not root:
            return 0

        left_size = self._calculate_subtree_size(root.left, subtree_size)
        right_size = self._calculate_subtree_size(root.right, subtree_size)

        total_size = left_size + right_size + 1
        subtree_size[root.val] = total_size

        return total_size
