def maxProduct(self, root: TreeNode) -> int:

    def tree_sum(subroot):
        if subroot is None: return 0
        left_sum = tree_sum(subroot.left)
        right_sum = tree_sum(subroot.right)
        return left_sum + right_sum + subroot.val

    def maximum_product(subroot, total):
        best = 0
        def recursive_helper(subroot):
            nonlocal best
            if subroot is None: return 0
            left_sum = recursive_helper(subroot.left)
            right_sum = recursive_helper(subroot.right)
            total_sum = left_sum + right_sum + subroot.val
            product = total_sum * (tree_total_sum - total_sum)
            best = max(best, product)
            return total_sum
        recursive_helper(subroot)
        return best

    tree_total_sum = tree_sum(root)
    return maximum_product(root, tree_total_sum) % (10 ** 9 + 7)
