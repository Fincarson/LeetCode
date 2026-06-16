function isValidBST(root: TreeNode | null): boolean {
    let prev: number | null = null;
    function inorder(node: TreeNode | null): boolean {
        if (!node) {
            return true;
        }
        if (!inorder(node.left)) {
            return false;
        }
        if (prev !== null && node.val <= prev) {
            return false;
        }
        prev = node.val;
        return inorder(node.right);
    }
    return inorder(root);
}
