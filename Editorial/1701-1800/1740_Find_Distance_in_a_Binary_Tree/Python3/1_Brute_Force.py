class Solution:
    def findDistance(self, root, p, q):
        # Find the lowest common ancestor of p and q.
        lca = self.__find_LCA(root, p, q)
        return self.__depth(lca, p) + self.__depth(lca, q)

    # Function to find the LCA of the given nodes.
    def __find_LCA(self, root, p, q):
        if root is None or root.val == p or root.val == q:
            return root
        left = self.__find_LCA(root.left, p, q)
        right = self.__find_LCA(root.right, p, q)
        if left is not None and right is not None:
            return root
        return left if left is not None else right

    # Function to find the depth of the node with respect to LCA.
    def __depth(self, root, target, current_depth=0):
        # Node not found
        if root is None:
            return -1
        if root.val == target:
            return current_depth

        # Check left subtree
        left_depth = self.__depth(root.left, target, current_depth + 1)
        if left_depth != -1:
            return left_depth

        # If not in left subtree, it is guaranteed to be in right subtree
        return self.__depth(root.right, target, current_depth + 1)
