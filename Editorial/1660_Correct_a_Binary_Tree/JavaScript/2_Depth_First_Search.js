var correctBinaryTree = function(root) {
    // Hash Set to store node value of rightmost branch
    const visited = new Set();

    // Do Reverse Postorder Traversal. 
    const buildCorrectTree = (node) => {
        // If Empty Node, return
        if (node === null) {
            return null;
        }

        // If node.right is already visited, then the node is defective
        // No need to build tree rooted at "node". Replace it with null
        if (node.right !== null && visited.has(node.right.val)) {
            return null;
        }

        // Add this node's value to the visited
        visited.add(node.val);

        // Recursively build tree rooted at "node"
        // Build the right subtree first, so that we can explore the right to left
        node.right = buildCorrectTree(node.right);
        node.left = buildCorrectTree(node.left);

        // Return root of built tree
        return node;       
    }

    // Build entire tree
    return buildCorrectTree(root);
};
