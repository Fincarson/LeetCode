// TypeScript
function isSymmetric(root: TreeNode | null): boolean {
    let q: Array<TreeNode | null> = [root, root];
    while (q.length !== 0) {
        let t1: TreeNode | null = q.shift();
        let t2: TreeNode | null = q.shift();
        if (t1 === null && t2 === null) {
            continue;
        }
        if (t1 === null || t2 === null) {
            return false;
        }
        if (t1.val !== t2.val) {
            return false;
        }
        q.push(t1.left, t2.right, t1.right, t2.left);
    }
    return true;
}
