class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        def helper(in_left = 0, in_right = len(preorder)):
            nonlocal pre_idx
            # If there is no elements to construct subtrees
            if in_left == in_right:
                return None
            
            # pick up pre_idx element as a root
            root_val = preorder[pre_idx]
            root = TreeNode(root_val)

            # root splits inorder list
            # into left and right subtrees
            index = idx_map[root_val]

            # recursion 
            pre_idx += 1
            # build the left subtree
            root.left = helper(in_left, index)
            # build the right subtree
            root.right = helper(index + 1, in_right)
            return root
        
        inorder = sorted(preorder)
        # start from the first preorder element
        pre_idx = 0
        # build a hashmap value -> its index
        idx_map = {val:idx for idx, val in enumerate(inorder)} 
        return helper()
