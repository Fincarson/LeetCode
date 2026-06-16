/**
 * Definition for Node.
 * class Node {
 *     val: number
 *     next: Node | null
 *     random: Node | null
 *     constructor(val?: number, next?: Node, random?: Node) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *         this.random = (random===undefined ? null : random)
 *     }
 * }
 */

function copyRandomList(head: Node | null): Node | null {
    // HashMap which holds old nodes as keys and new nodes as its values.
    let visitedHash: Map<Node, Node> = new Map();

    // Helper function to clone a node
    const cloneNode = function (node: Node | null): Node | null {
        if (node === null) {
            return null;
        }
        // If the node was already visited before.
        // Return the clone from the visited dictionary.
        if (visitedHash.has(node)) {
            return visitedHash.get(node)!;
        }
        // Create a new node
        // with the value same as old node.
        let newNode: Node = new Node(node.val, null, null);
        // Save this value in the hash map. This is needed since there might be
        // loops during traversal due to randomness of random pointers and this would help us avoid them.
        visitedHash.set(node, newNode);

        // Recursively copy the remaining linked list starting once from the next pointer and then from the random pointer.
        // Thus we have two independent recursive calls.
        // Finally we update the next and random pointers for the new node created.
        newNode.next = cloneNode(node.next);
        newNode.random = cloneNode(node.random);
        return newNode;
    };

    return cloneNode(head);
}
