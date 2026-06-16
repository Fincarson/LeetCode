function maxPathSum(root) {
    let maxPath = -Infinity;

    // post order traversal of subtree rooted at `node`
    function gainFromSubtree(node) {
        if (!node) {
            return 0;
        }
        // add the path sum from left subtree and the current root
        let gainFromLeft = Math.max(gainFromSubtree(node.left), 0);

        // add the path sum from right subtree and the current root
        let gainFromRight = Math.max(gainFromSubtree(node.right), 0);

        // if left or right path sum are negative, they are counted
        // as 0, so this statement takes care of all four scenarios
        maxPath = Math.max(maxPath, gainFromLeft + gainFromRight + node.val);

        // return the max sum for a path starting at the root of subtree
        return Math.max(gainFromLeft + node.val, gainFromRight + node.val);
    }
    gainFromSubtree(root);
    return maxPath;
}
