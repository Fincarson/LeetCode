var levelOrderBottom = function (root) {
    let levels = [];
    function helper(node, level) {
        if (!node) return;
        // start the current level
        if (!levels[level]) levels[level] = [];
        // append the current node value
        levels[level].push(node.val);
        // process child nodes for the next level
        if (node.left) helper(node.left, level + 1);
        if (node.right) helper(node.right, level + 1);
    }
    helper(root, 0);
    return levels.reverse();
};
