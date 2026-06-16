class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        result = []

        def inorder(node: Optional[TreeNode]) -> None:
            if node is None:
                return
            inorder(node.left)
            result.append(node.val)
            inorder(node.right)

        inorder(root)
        return result[k - 1]
