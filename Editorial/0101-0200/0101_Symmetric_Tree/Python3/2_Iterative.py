from collections import deque

class Solution:
    def isSymmetric(self, root):
        q = deque([root, root])
        while q:
            t1 = q.popleft()
            t2 = q.popleft()
            if t1 is None and t2 is None:
                continue
            if t1 is None or t2 is None:
                return False
            if t1.val != t2.val:
                return False
            q.append(t1.left)
            q.append(t2.right)
            q.append(t1.right)
            q.append(t2.left)
        return True
