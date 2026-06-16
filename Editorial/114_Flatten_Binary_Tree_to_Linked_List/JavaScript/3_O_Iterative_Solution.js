var flatten = function (root) {
    // Handle the null scenario
    if (!root) {
        return;
    }
    let node = root;
    while (node != null) {
        // If the node has a left child
        if (node.left != null) {
            // Find the rightmost node
            let rightmost = node.left;
            while (rightmost.right != null) {
                rightmost = rightmost.right;
            }
            // rewire the connections
            rightmost.right = node.right;
            node.right = node.left;
            node.left = null;
        }
        // move on to the right side of the tree
        node = node.right;
    }
};
