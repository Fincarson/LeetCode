// Compute the tree's height via recursion
var height = function (root) {
    // An empty tree has height -1
    if (root == null) {
        return -1;
    }
    return 1 + Math.max(height(root.left), height(root.right));
};
var isBalanced = function (root) {
    // An empty tree satisfies the definition of a balanced tree
    if (root == null) {
        return true;
    }
    // Check if subtrees have height within 1. If they do, check if the
    // subtrees are balanced
    return (
        Math.abs(height(root.left) - height(root.right)) < 2 &&
        isBalanced(root.left) &&
        isBalanced(root.right)
    );
};
