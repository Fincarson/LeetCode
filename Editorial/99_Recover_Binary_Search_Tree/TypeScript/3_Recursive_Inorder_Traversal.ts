function recoverTree(root: TreeNode | null): void {
    // first node
    let x: TreeNode | null = null;
    // second node
    let y: TreeNode | null = null;
    // predecessor node
    let pred: TreeNode | null = null;
    function findTwoSwapped(root: TreeNode | null): void {
        if (root === null) return;
        findTwoSwapped(root.left);
        if (pred !== null && root.val < pred.val) {
            y = root;
            if (x === null) x = pred;
            else return;
        }
        pred = root;
        findTwoSwapped(root.right);
    }
    findTwoSwapped(root);
    // Swap x and y values
    [x.val, y.val] = [y.val, x.val];
}
