def inorder(r: TreeNode) -> List[int]:
    return inorder(r.left) + [r.val] + inorder(r.right) if r else []
