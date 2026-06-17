function buildTree(inorder: number[], postorder: number[]): TreeNode | null {
    let idx_map = new Map<number, number>();
    let post_idx = postorder.length - 1;
    let helper = (in_left: number, in_right: number): TreeNode | null => {
        if (in_left > in_right) return null;
        let root_val = postorder[post_idx];
        let root = new TreeNode(root_val);
        let index = idx_map.get(root_val);
        post_idx--;
        root.right = helper(index + 1, in_right);
        root.left = helper(in_left, index - 1);
        return root;
    };
    for (let i = 0; i < inorder.length; i++) idx_map.set(inorder[i], i);
    return helper(0, inorder.length - 1);
}
