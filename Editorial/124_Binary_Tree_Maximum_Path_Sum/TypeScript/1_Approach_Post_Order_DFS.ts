function gainFromSubtree(node, maxPath) {
    if (!node) {
        return 0;
    }
    let gainFromLeft = Math.max(gainFromSubtree(node.left, maxPath), 0);
    let gainFromRight = Math.max(gainFromSubtree(node.right, maxPath), 0);
    maxPath[0] = Math.max(maxPath[0], gainFromLeft + gainFromRight + node.val);
    return Math.max(gainFromLeft + node.val, gainFromRight + node.val);
}
function maxPathSum(root) {
    let maxPath = [-Infinity];
    gainFromSubtree(root, maxPath);
    return maxPath[0];
}
