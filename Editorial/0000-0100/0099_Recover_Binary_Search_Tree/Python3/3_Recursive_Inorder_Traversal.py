class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        def find_two_swapped(root: TreeNode):
            nonlocal x, y, pred
            if root is None:
                return

            find_two_swapped(root.left)
            if pred and root.val < pred.val:
                y = root
                # The first swap occurence
                if x is None:
                    x = pred
                # The second swap occurence
                else:
                    return
            pred = root
            find_two_swapped(root.right)

        x = y = pred = None
        find_two_swapped(root)
        x.val, y.val = y.val, x.val
