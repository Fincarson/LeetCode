# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def postorderTraversal(self, root):
        # List to store the result of postorder traversal
        result = []
        # Stack to facilitate the traversal of nodes
        traversal_stack = []
        current_node = root

        # Traverse the tree while there are nodes to process
        while current_node or traversal_stack:
            if current_node:
                # Add current node's value to result list before going to its children
                result.append(current_node.val)
                # Push current node onto the stack
                traversal_stack.append(current_node)
                # Move to the right child
                current_node = current_node.right
            else:
                # Pop the node from the stack and move to its left child
                current_node = traversal_stack.pop()
                current_node = current_node.left
        # Reverse the result list to get the correct postorder sequence
        result.reverse()
        return result
