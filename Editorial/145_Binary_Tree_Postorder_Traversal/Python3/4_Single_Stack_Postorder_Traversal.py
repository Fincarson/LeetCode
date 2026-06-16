# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []

        # If the root is null, return an empty list
        if root is None:
            return result

        # To keep track of the previously processed node
        previous_node = None
        # Stack to manage the traversal
        traversal_stack = []

        # Process nodes until both the root is null and the stack is empty
        while root is not None or len(traversal_stack) > 0:
            # Traverse to the leftmost node
            if root is not None:
                traversal_stack.append(root)
                root = root.left
            else:
                # Peek at the top node of the stack
                root = traversal_stack[-1]

                # If there is no right child or the right child was already processed
                if root.right is None or root.right == previous_node:
                    result.append(root.val)
                    traversal_stack.pop()
                    previous_node = root
                    root = None  # Ensure we don’t traverse again from this node
                else:
                    # Move to the right child
                    root = root.right

        return result
