const levelOrder = function (root: TreeNode | null): number[][] {
    let levels: number[][] = [];
    if (!root) return levels;
    let queue: TreeNode[] = [root];
    let level: number = 0;
    while (queue.length) {
        // Start the current level
        levels.push([]);
        // Number of elements in the current level
        let level_length: number = queue.length;
        for (let i = 0; i < level_length; ++i) {
            let node: TreeNode | undefined = queue.shift();
            // Fulfill the current level
            if (node) levels[level].push(node.val);
            // Add child nodes of the current level
            // In the queue for the next level
            if (node?.left) queue.push(node.left);
            if (node?.right) queue.push(node.right);
        }
        // Go to next level
        level++;
    }
    return levels;
};
