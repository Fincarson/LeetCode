class BSTIterator:

    def __init__(self, root: TreeNode):
        self.last = root
        self.stack, self.arr = [], []
        self.pointer = -1

    def hasNext(self) -> bool:
        return self.stack or self.last or self.pointer < len(self.arr) - 1

    def next(self) -> int:
        self.pointer += 1
        
        # if the pointer is out of precomputed range
        if self.pointer == len(self.arr):
            # process all predecessors of the last node:
            # go left till you can and then one step right
            while self.last:
                self.stack.append(self.last)
                self.last = self.last.left
            curr = self.stack.pop()
            self.last = curr.right
        
            self.arr.append(curr.val)
            
        return self.arr[self.pointer]

    def hasPrev(self) -> bool:
        return self.pointer > 0

    def prev(self) -> int:
        self.pointer -= 1
        return self.arr[self.pointer]
