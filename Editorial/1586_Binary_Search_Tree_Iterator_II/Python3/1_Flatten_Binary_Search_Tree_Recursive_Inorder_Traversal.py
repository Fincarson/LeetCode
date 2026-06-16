class BSTIterator:

    def __init__(self, root: TreeNode):
        def inorder(r):
            return inorder(r.left) + [r.val] + inorder(r.right) if r else []
        self.arr = inorder(root)
        self.n = len(self.arr)
        self.pointer = -1

    def hasNext(self) -> bool:
        return self.pointer < self.n - 1

    def next(self) -> int:
        self.pointer += 1
        return self.arr[self.pointer]

    def hasPrev(self) -> bool:
        return self.pointer > 0

    def prev(self) -> int:
        self.pointer -= 1
        return self.arr[self.pointer]
