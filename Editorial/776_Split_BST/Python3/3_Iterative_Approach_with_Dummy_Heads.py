class Solution:
    def splitBST(self, root: TreeNode, target: int) -> list[TreeNode]:
        # Create dummy nodes to hold the split tree parts
        dummy_sm = TreeNode(0)
        cur_sm = dummy_sm
        dummy_lg = TreeNode(0)
        cur_lg = dummy_lg

        # Start traversal from the root
        current = root
        next_node = None

        while current is not None:
            if current.val <= target:
                # Attach the current node to the tree
                # with values less than or equal to the target
                cur_sm.right = current
                cur_sm = current

                # Move to the right subtree
                next_node = current.right

                # Clear the right pointer of current node
                cur_sm.right = None

                current = next_node
            else:
                # Attach the current node to the tree
                # with values greather to the target
                cur_lg.left = current
                cur_lg = current

                # Move to the left subtree
                next_node = current.left

                # Clear the left pointer of current node
                cur_lg.left = None

                current = next_node

        # Return the split parts as a list
        return [dummy_sm.right, dummy_lg.left]
