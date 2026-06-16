/*
 * Definition for a node.
 * function Node(val, next, random) {
 *  	  this.val = val;
 *     this.next = next;
 *     this.random = random;
 * };
 */
var copyRandomList = function (head) {
    // HashMap which holds old nodes as keys and new nodes as its values.
    let visitedHash = new Map();
    let cloneNode = function (node) {
        if (node === null) {
            return null;
        }
        // If the node was already visited before.
        // Return the clone from the visited dictionary.
        if (visitedHash.has(node)) {
            return visitedHash.get(node);
        }
        // Create a new node
        // with the value same as old node.
        let newNode = new Node(node.val, null, null);
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
};
