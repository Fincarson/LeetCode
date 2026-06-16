class Solution:
    def findDistance(self, root, p, q):
        lca = self._find_LCA(root, p, q)
        bfs = deque([lca])
        distance = 0
        depth = 0
        foundp = False
        foundq = False
        while bfs and (not foundp or not foundq):
            size = len(bfs)
            for i in range(size):
                node = bfs.popleft()  # Dequeue the node
                if node.val == p:
                    distance += depth
                    foundp = True
                if node.val == q:
                    distance += depth
                    foundq = True
                if node.left:
                    bfs.append(node.left)  # Enqueue left child
                if node.right:
                    bfs.append(node.right)  # Enqueue right child
            depth += 1
        return distance

    def _find_LCA(self, root, p, q):
        if root is None or root.val == p or root.val == q:
            return root
        left = self._find_LCA(root.left, p, q)
        right = self._find_LCA(root.right, p, q)
        if left and right:
            return root
        return left if left else right
