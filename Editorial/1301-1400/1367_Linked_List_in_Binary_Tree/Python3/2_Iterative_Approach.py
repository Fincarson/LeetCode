class Solution:
    def isSubPath(
        self, head: Optional[ListNode], root: Optional[TreeNode]
    ) -> bool:
        if not root:
            return False
        stack = [root]

        while stack:
            node = stack.pop()

            if self._is_match(node, head):
                return True
            # Push left and right children onto the stack
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
        return False

    def _is_match(
        self, node: Optional[TreeNode], lst: Optional[ListNode]
    ) -> bool:
        # Stack to keep track of (current_tree_node, current_list_node)
        stack = [(node, lst)]

        while stack:
            current_node, current_list = stack.pop()

            while current_node and current_list:
                if current_node.val != current_list.val:
                    break
                current_list = current_list.next

                # Continue to the next node in the tree, left or right
                if current_list:
                    if current_node.left:
                        stack.append((current_node.left, current_list))
                    if current_node.right:
                        stack.append((current_node.right, current_list))
                    break
            if not current_list:
                return True
        return False
