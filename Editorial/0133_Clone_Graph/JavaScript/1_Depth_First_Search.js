/*
// Definition for a Node.
function Node(val = 0, neighbors = []) {
   this.val = val;
   this.neighbors = neighbors;
};
*/
var cloneGraph = function (node) {
    var visited = new Map();
    function dfs(node) {
        if (node == null) {
            return node;
        }
        // If the node was already visited before.
        // Return the clone from the visited dictionary.
        if (visited.has(node)) {
            return visited.get(node);
        }
        // Create a clone for the given node.
        // Note that we don't have cloned neighbors as of now, hence [].
        var cloneNode = new Node(node.val, []);
        // The key is original node and value being the clone node.
        visited.set(node, cloneNode);
        // Iterate through the neighbors to generate their clones
        // and prepare a list of cloned neighbors to be added to the cloned node.
        node.neighbors.forEach(function (neighbor) {
            cloneNode.neighbors.push(dfs(neighbor));
        });
        return cloneNode;
    }
    return dfs(node);
};
