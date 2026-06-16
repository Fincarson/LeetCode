var levelOrder = function (root) {
    let levels = [];
    function helper(node, level) {
        if (levels.length === level) levels.push([]);
        levels[level].push(node.val);
        if (node.left !== null) helper(node.left, level + 1);
        if (node.right !== null) helper(node.right, level + 1);
    }
    if (root !== null) helper(root, 0);
    return levels;
};
