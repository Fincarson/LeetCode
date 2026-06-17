class Solution {
    public TreeNode correctBinaryTree(TreeNode root) {
        // Queue for BFS. Every element stores [node, parent]
        Queue<TreeNode[]> queue = new LinkedList<>();
        queue.add(new TreeNode[]{root, null});

        // Traverse Level by Level
        while (!queue.isEmpty()) {
            // Nodes in the current level
            int n = queue.size();

            // Hash Set to store nodes of the current level
            Set<TreeNode> visited = new HashSet<>();

            // Traverse all nodes in the current level
            for (int i = 0; i < n; i++) {
                // Pop the node and its parent from the queue
                TreeNode[] temp = queue.poll();
                TreeNode node = temp[0], parent = temp[1];

                // If node.right is already visited, then node is defective
                if (visited.contains(node.right)) {
                    // Replace the child of node's parent with null and return root
                    if (parent.left == node) {
                        parent.left = null;
                    } else {
                        parent.right = null;
                    }
                    return root;
                }

                // Add node to visited
                visited.add(node);

                // Add child in queue for traversal in next level
                // They won't get popped in this level because of "n"
                // Add right child first, so that we can explore right to left
                if (node.right != null) {
                    queue.add(new TreeNode[]{node.right, node});
                }
                if (node.left != null) {
                    queue.add(new TreeNode[]{node.left, node});
                }
            }
        }

        // For the sake of compilation
        return root;
    }
}
