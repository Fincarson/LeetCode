class Solution:
    def findNearestRightNode(self, root: TreeNode, u: TreeNode) -> TreeNode:
        def dfs(current_node, depth):
            nonlocal u_depth, next_node
            # the depth to look for next node is identified
            if current_node == u:
                u_depth = depth
                return
            # we're on the level to look for the next node
            if depth == u_depth:
                # if this next node is not identified yet
                if next_node is None:
                    next_node = current_node
                return
            # continue to traverse the tree
            if current_node.left:
                dfs(current_node.left, depth + 1)
            if current_node.right:
                dfs(current_node.right, depth + 1)

        u_depth, next_node = -1, None
        dfs(root, 0)
        return next_node
