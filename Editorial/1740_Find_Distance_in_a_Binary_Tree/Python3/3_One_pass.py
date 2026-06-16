class Solution:
    def findDistance(self, root, p, q):
        return self.__distance(root, p, q, 0)

    # Private helper function
    def __distance(self, root, p, q, depth):
        if root is None or p == q:
            return 0

        # If either p or q is found, calculate the ret_distance as the maximum
        # of depth and ret_distance value for left and right subtrees.
        if root.val == p or root.val == q:
            left = self.__distance(root.left, p, q, 1)
            right = self.__distance(root.right, p, q, 1)

            return max(left, right) if left > 0 or right > 0 else depth

        # Otherwise, calculate the ret_distance as sum of ret_distance of left
        # and right subtree.
        left = self.__distance(root.left, p, q, depth + 1)
        right = self.__distance(root.right, p, q, depth + 1)
        ret_distance = left + right

        # If current node is the LCA, subtract twice of depth.
        if left != 0 and right != 0:
            ret_distance -= 2 * depth

        return ret_distance
