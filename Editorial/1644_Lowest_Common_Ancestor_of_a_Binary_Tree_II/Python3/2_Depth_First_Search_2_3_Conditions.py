class Solution:
    def lowestCommonAncestor(
        self, root: "TreeNode", p: "TreeNode", q: "TreeNode"
    ) -> "TreeNode":
        self.nodes_found = False

        def dfs(node):
            # Base case: If the node is null, return None
            if not node:
                return node
            # Recursively search the left and right subtrees
            left, right = dfs(node.left), dfs(node.right)

            # Check conditions for current node being part of the solution
            conditions = 0
            if node in (p, q):
                conditions += 1
            if left:
                conditions += 1
            if right:
                conditions += 1
            if conditions == 2:
                self.nodes_found = True  # Mark that both nodes are found
            # Determine if current node is the lowest common ancestor
            if (left and right) or node in (p, q):
                return node
            # Return the non-null child, if any
            return left or right

        # Start DFS traversal to find the lowest common ancestor
        ans = dfs(root)
        # Return the result only if both nodes are found
        return ans if self.nodes_found else None
