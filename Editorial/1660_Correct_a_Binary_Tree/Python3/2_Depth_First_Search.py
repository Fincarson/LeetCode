class Solution:
    def correctBinaryTree(self, root: TreeNode) -> TreeNode:
        # Hash Set to store node value of the rightmost branch
        visited = set()

        # Do Reverse Postorder Traversal
        def build_correct_tree(node):
            # If Empty Node, return
            if node is None:
                return None

            # If node.right is already visited, then the node is defective
            # No need to build tree rooted at "node". Replace it with None
            if node.right and node.right.val in visited:
                return None
            
            # Add this node's value to the visited
            visited.add(node.val)

            # Recursively build tree rooted at "node"
            # Build the right subtree first, so that we can explore the right to left
            node.right = build_correct_tree(node.right)
            node.left = build_correct_tree(node.left)

            # Return the root of the built tree
            return node
        
        # Build entire tree
        return build_correct_tree(root)
