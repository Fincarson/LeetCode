public class Solution {
    public TreeNode CorrectBinaryTree(TreeNode root) {
        // Queue for BFS. Every element stores [node, parent]
        Queue<(TreeNode, TreeNode)> q = new Queue<(TreeNode, TreeNode)>();
        q.Enqueue((root, null));

        // Traverse Level by Level
        while (q.Count > 0) {
            // Nodes in the current level
            int n = q.Count;

            // Hash Set to store nodes of the current level
            HashSet<TreeNode> visited = new HashSet<TreeNode>();

            // Traverse all nodes in the current level
            for (int i = 0; i < n; i++) {
                // Pop the node and its parent from the queue
                (TreeNode node, TreeNode parent) = q.Dequeue();
                
                // If node.right is already visited, then node is defective
                if (visited.Contains(node.right)) {
                    // Replace the child of node's parent with null and return the root
                    if (parent.left == node) {
                        parent.left = null;
                    } else {
                        parent.right = null;
                    }
                    return root;
                }

                // Add node to visited
                visited.Add(node);

                // Add child in queue for traversal in next level
                // They won't get popped in this level because of "n"
                // Add the right child first, so that we can explore right to left
                if (node.right != null) {
                    q.Enqueue((node.right, node));
                }
                if (node.left != null) {
                    q.Enqueue((node.left, node));
                }
            }
        }

        // For the sake of compilation
        return root;
    }
}
