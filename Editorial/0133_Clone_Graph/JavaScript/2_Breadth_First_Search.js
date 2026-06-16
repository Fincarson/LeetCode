var cloneGraph = function (node) {
    if (node === null) return node;
    // Hash map to save the visited node and it's respective clone
    // as key and value respectively. This helps to avoid cycles.
    const visited = new Map();
    // Put the first node in the queue
    const queue = [node];
    // Clone the node and put it in the visited dictionary.
    visited.set(node, { val: node.val, neighbors: [] });
    // Start BFS traversal
    while (queue.length > 0) {
        const n = queue.shift();
        n.neighbors.forEach((neighbor) => {
            if (!visited.has(neighbor)) {
                // Clone the neighbor and put in the visited, if not present already
                visited.set(neighbor, { val: neighbor.val, neighbors: [] });
                // Add the newly encountered node to the queue.
                queue.push(neighbor);
            }
            // Add the clone of the neighbor to the neighbors of the clone node "n".
            visited.get(n).neighbors.push(visited.get(neighbor));
        });
    }
    // Return the clone of the node from visited.
    return visited.get(node);
};
