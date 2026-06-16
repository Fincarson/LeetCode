function levelOrderBottom(root: TreeNode | null): number[][] {
    let levels: number[][] = [];
    if (root == null) return levels;
    let nextLevel: (TreeNode | null)[] = [root];
    while (nextLevel.length > 0) {
        let currLevel: (TreeNode | null)[] = [...nextLevel];
        nextLevel = [];
        levels.push([]);
        for (let node of currLevel) {
            if (node != null) {
                // append the current node value
                levels[levels.length - 1].push(node.val);
                // process child nodes for the next level
                if (node.left != null) nextLevel.push(node.left);
                if (node.right != null) nextLevel.push(node.right);
            }
        }
    }
    levels.reverse();
    return levels;
}
