public class Solution {
    public TreeNode CorrectBinaryTree(TreeNode root) {
        // Hash Set to store node value of the rightmost branch
        HashSet<int> visited = new HashSet<int>();

        // Do Reverse Postorder Traversal. Assume input "root" as recursive parameter "node"
        TreeNode correctBinaryTree(TreeNode node) {
            // If Empty Node, return
            if (node == null) {
                return null;
            }

            // If node.right is already visited, then the node is defective
            // No need to build tree rooted at "node". Replace it with null
            if (node.right != null && visited.Contains(node.right.val)) {
                return null;
            }

            // Add this node's value to the visited
            visited.Add(node.val);

            // Recursively build tree rooted at "node"
            // Build the right subtree first, so that we can explore right to left
            node.right = correctBinaryTree(node.right);
            node.left = correctBinaryTree(node.left);

            // Return root of built tree
            return node;       
        }

        // Build entire tree
        return correctBinaryTree(root);
    }
}
