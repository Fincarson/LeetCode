function isValidBST(root: TreeNode | null): boolean {
    let stack: (TreeNode | null)[] = [];
    let prev: number | null = null;
    while (stack.length !== 0 || root !== null) {
        while (root !== null) {
            stack.push(root);
            root = root.left;
        }
        root = stack.pop();
        // If next element in inorder traversal
        // is smaller than the previous one
        // that's not BST.
        if (prev !== null && root.val <= prev) {
            return false;
        }
        prev = root.val;
        root = root.right;
    }
    return true;
}
