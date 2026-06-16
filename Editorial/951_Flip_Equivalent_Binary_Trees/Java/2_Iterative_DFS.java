class Solution {

    // Checks whether the given pair of nodes should be examined -
    // be pushed into the stack
    public boolean checkNodeValues(TreeNode node1, TreeNode node2) {
        if (node1 == null && node2 == null) return true;
        if (
            node1 != null && node2 != null && node1.val == node2.val
        ) return true;
        return false;
    }

    public boolean flipEquiv(TreeNode root1, TreeNode root2) {
        // Initialize stack to store pairs of nodes
        Stack<TreeNode[]> nodePairStack = new Stack<>();
        nodePairStack.push(new TreeNode[] { root1, root2 });

        // While the stack is not empty:
        while (!nodePairStack.isEmpty()) {
            TreeNode[] current = nodePairStack.pop();
            TreeNode node1 = current[0];
            TreeNode node2 = current[1];

            if (node1 == null && node2 == null) continue;
            if (node1 == null || node2 == null) return false;
            if (node1.val != node2.val) return false;

            // Check both configurations: no swap and swap
            if (
                checkNodeValues(node1.left, node2.left) &&
                checkNodeValues(node1.right, node2.right)
            ) {
                nodePairStack.push(new TreeNode[] { node1.left, node2.left });
                nodePairStack.push(new TreeNode[] { node1.right, node2.right });
            } else if (
                checkNodeValues(node1.left, node2.right) &&
                checkNodeValues(node1.right, node2.left)
            ) {
                nodePairStack.push(new TreeNode[] { node1.left, node2.right });
                nodePairStack.push(new TreeNode[] { node1.right, node2.left });
            } else {
                return false;
            }
        }
        return true;
    }
}
