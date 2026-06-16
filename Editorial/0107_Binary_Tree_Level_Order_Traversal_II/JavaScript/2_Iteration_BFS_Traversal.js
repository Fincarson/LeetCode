var levelOrderBottom = function (root) {
    let levels = [];
    if (root == null) return levels;
    let nextLevel = [root];
    while (nextLevel.length > 0) {
        let currLevel = [...nextLevel];
        nextLevel = [];
        levels.push([]);
        for (let node of currLevel) {
            // append the current node value
            levels[levels.length - 1].push(node.val);
            // process child nodes for the next level
            if (node.left != null) nextLevel.push(node.left);
            if (node.right != null) nextLevel.push(node.right);
        }
    }
    levels.reverse();
    return levels;
};
