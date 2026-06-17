class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        self.minDistance = 1e9
        # Initially, it will be null.
        self.prevNode = None

        def inorder(node):
            if node is None:
                return
            inorder(node.left)
            # Find the difference with the previous value if it is there.
            if self.prevNode is not None:
                self.minDistance = min(self.minDistance, node.val - self.prevNode)
            self.prevNode = node.val
            inorder(node.right)

        inorder(root)
        return self.minDistance
