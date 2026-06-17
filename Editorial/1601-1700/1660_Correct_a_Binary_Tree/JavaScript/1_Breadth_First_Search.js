var correctBinaryTree = function(root) {
    // Queue for BFS. Every element stores [node, parent]
    const queue = [[root, null]];

    // Traverse Level by Level
    while (queue.length) {
        // Nodes in the current level
        const n = queue.length;

        // Hash Set to store nodes of the current level
        const visited = new Set();

        // Traverse all nodes in the current level
        for (let i = 0; i < n; i++) {
            // Pop the node and its parent from the queue
            const [node, parent] = queue.shift();

            // If node.right is already visited, then node is defective
            if (visited.has(node.right)) {
                // Replace the child of node's parent with null and return root
                if (parent.left === node) {
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
            if (node.right) {
                queue.push([node.right, node]);
            }
            if (node.left) {
                queue.push([node.left, node]);
            }
        }
    }

    // For the sake of compilation
    return root;
};
