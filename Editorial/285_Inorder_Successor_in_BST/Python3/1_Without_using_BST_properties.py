class Solution:
    
    previous = None
    inorder_successor_node = None
    
    def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
        
        self.previous, self.inorder_successor_node = None, None
        
        # Case 1: We simply need to find the leftmost node in the subtree rooted at p.right.
        if p.right:
            leftmost = p.right
            while leftmost.left:
                leftmost = leftmost.left
                
            self.inorder_successor_node = leftmost
        
        # Case 2: We need to perform the standard in order traversal and keep track of the previous node.
        else:
            self.inorderCase2(root, p)
        
        return self.inorder_successor_node
        
        
    def inorderCase2(self, node: 'TreeNode', p: 'TreeNode'):
        
        if not node:
            return
        
        # Recurse on the left side
        self.inorderCase2(node.left, p)
        
        # Check if the previous is the inorder predecessor of node
        if self.previous == p and not self.inorder_successor_node:
            self.inorder_successor_node = node
            return
        
        # Keeping previous up-to-date for further recursions
        self.previous = node
        
        # Recurse on the right side
        self.inorderCase2(node.right, p)
