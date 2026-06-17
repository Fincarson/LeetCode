// Utility class to store information from recursive calls
class TreeInfo {
    constructor(
        public height: number,
        public balanced: boolean,
    ) {}
}
function isBalanced(root: TreeNode | null): boolean {
    // Returns whether the tree at root is balanced, along with the tree's height.
    function isBalancedTreeHelper(root: TreeNode | null): TreeInfo {
        // An empty tree is both balanced and has a height -1.
        if (root == null) {
            return new TreeInfo(-1, true);
        }
        // Checks whether the subtrees are balanced or not.
        const left = isBalancedTreeHelper(root.left);
        if (!left.balanced) {
            return new TreeInfo(-1, false);
        }
        const right = isBalancedTreeHelper(root.right);
        if (!right.balanced) {
            return new TreeInfo(-1, false);
        }
        // The obtained height from recursive calls can also determine
        // that the current node is balanced.
        if (Math.abs(left.height - right.height) < 2) {
            return new TreeInfo(Math.max(left.height, right.height) + 1, true);
        }
        return new TreeInfo(-1, false);
    }
    return isBalancedTreeHelper(root).balanced;
}
