var next_items = [];
var max_depth = 0;
function next_maxDepth() {
    if (!next_items.length) return max_depth;
    var next_level = next_items[0][1] + 1;
    max_depth = Math.max(max_depth, next_level);
    var next_node = next_items.shift()[0];
    if (next_node.left) {
        next_items.push([next_node.left, next_level]);
    }
    if (next_node.right) {
        next_items.push([next_node.right, next_level]);
    }
    return next_maxDepth();
}
function maxDepth(root) {
    if (!root) return 0;
    next_items = [];
    max_depth = 0;
    next_items.push([root, 0]);
    return next_maxDepth();
}
