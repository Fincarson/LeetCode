class Solution:

    # Checks whether the given pair of nodes should be examined -
    # be pushed into the stack
    def check_node_values(self, node_1: TreeNode, node_2: TreeNode) -> bool:
        if not node_1 and not node_2:
            return True
        if node_1 and node_2 and node_1.val == node_2.val:
            return True
        return False

    def flipEquiv(self, root1: TreeNode, root2: TreeNode) -> bool:
        # Initialize stack to store pairs of nodes
        node_pair_stack = []
        node_pair_stack.append((root1, root2))

        # While the stack is not empty:
        while node_pair_stack:
            node_1, node_2 = node_pair_stack.pop()

            if not node_1 and not node_2:
                continue
            if not node_1 or not node_2:
                return False
            if node_1.val != node_2.val:
                return False

            # Check both configurations: no swap and swap
            if self.check_node_values(
                node_1.left, node_2.left
            ) and self.check_node_values(node_1.right, node_2.right):
                node_pair_stack.append((node_1.left, node_2.left))
                node_pair_stack.append((node_1.right, node_2.right))
            elif self.check_node_values(
                node_1.left, node_2.right
            ) and self.check_node_values(node_1.right, node_2.left):
                node_pair_stack.append((node_1.left, node_2.right))
                node_pair_stack.append((node_1.right, node_2.left))
            else:
                return False
        return True
