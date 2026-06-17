class Solution:
    
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        
        # An empty root is one of the test cases!
        if root is None:
            return 0

        def process_subtree(subtree, is_left):
            
            # Base case: This is a leaf node.
            if subtree.left is None and subtree.right is None:
                return subtree.val if is_left else 0
            
            # Recursive case: We need to add and return the results of the 
            # left and right subtrees.
            total = 0
            if subtree.left:
                total += process_subtree(subtree.left, True)
            if subtree.right:
                total += process_subtree(subtree.right, False)
            return total
        
        # Call the recursive function on the root node to start the process.
        # We need to be careful of the case that the root is empty.
        return process_subtree(root, False)
