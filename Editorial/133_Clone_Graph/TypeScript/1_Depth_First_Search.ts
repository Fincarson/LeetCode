/*
// Definition for a Node.
class Node {
    val: number;
    neighbors: Node[];
    constructor(val?: number, neighbors?: Node[]) {
        this.val = (val===undefined ? 0 : val);
        this.neighbors = (neighbors===undefined ? [] : neighbors);
    }
}
*/
function cloneGraph(node: Node | null): Node | null {
    let visited = new Map();
    let dfs = (node: Node | null): Node | null => {
        if (node === null) {
            return null;
        }
        // If the node was already visited before.
        // Return the clone from the visited dictionary.
        if (visited.has(node)) {
            return visited.get(node);
        }
        // Create a clone for the given node.
        // Note that we don't have cloned neighbors as of now, hence [].
        let cloneNode = new Node(node.val, []);
        // The key is original node and value being the clone node.
        visited.set(node, cloneNode);
        if (node.neighbors !== undefined) {
            node.neighbors.forEach((neighbor) =>
                cloneNode.neighbors.push(dfs(neighbor)),
            );
        }
        return cloneNode;
    };
    return dfs(node);
}
