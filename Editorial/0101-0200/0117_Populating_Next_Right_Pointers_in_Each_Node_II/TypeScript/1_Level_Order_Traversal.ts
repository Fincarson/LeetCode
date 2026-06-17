function connect(root: Node | null): Node | null {
    if (!root) return root;
    // Initialize a Queue with the root
    const Q: Node[] = [];
    Q.push(root);
    // Loop while the Queue is not empty
    while (Q.length > 0) {
        const size = Q.length;
        // Iterate over all the nodes currently in the Queue
        for (let i = 0; i < size; i++) {
            // Remove the first node from the Queue
            const node: Node | undefined = Q.shift();
            // If this is not the last node in the level, point next to the next node
            if (i < size - 1) {
                if (node) node.next = Q[0];
            }
            // Add the left and right children (if they exist) to the Queue
            if (node?.left) Q.push(node?.left);
            if (node?.right) Q.push(node?.right);
        }
    }
    // Return the root
    return root;
}
