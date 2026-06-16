function minDepth(root: TreeNode | null): number {
    if (!root) {
        return 0;
    }
    let q: (TreeNode | null)[] = [root];
    let depth: number = 1;
    while (q.length) {
        let qSize: number = q.length;
        for (let i = 0; i < qSize; i++) {
            let node: TreeNode | null = q.shift()!;
            // Since we added nodes without checking null, we need to skip them here.
            if (!node) {
                continue;
            }
            // The first leaf would be at minimum depth, hence return it.
            if (node.left === null && node.right === null) {
                return depth;
            }
            q.push(node.left);
            q.push(node.right);
        }
        depth++;
    }
    return -1;
}
