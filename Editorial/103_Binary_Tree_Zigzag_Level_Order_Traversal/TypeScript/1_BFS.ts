function zigzagLevelOrder(root: TreeNode | null): number[][] {
    let res: number[][] = [];
    if (root === null) return res;
    let queue: (TreeNode | null)[] = [root, null];
    let levelVals: number[] = [],
        dir = 1;
    while (queue.length > 0) {
        let node: TreeNode | null | undefined = queue.shift();
        if (node !== null) {
            if (dir === 1) levelVals.push(node.val);
            else levelVals.unshift(node.val);
            if (node.left !== null) queue.push(node.left);
            if (node.right !== null) queue.push(node.right);
        } else {
            res.push(levelVals);
            levelVals = [];
            if (queue.length) queue.push(null);
            dir *= -1;
        }
    }
    return res;
}
