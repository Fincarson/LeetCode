/*
// Definition for a Node.
function Node(val: number, next: any, random: any) {
   this.val = val;
   this.next = next;
   this.random = random;
};
*/
function copyRandomList(head: any) {
    // Creating a visited dictionary to hold old node reference as key and new node reference as the value
    let visited = new Map();
    function getClonedNode(node: any) {
        // If node exists then
        if (node) {
            // Check if its in the visited map
            if (visited.has(node)) {
                // If its in the visited map then return the new node reference from the map
                return visited.get(node);
            } else {
                // Otherwise create a new node, save the reference in the visited map and return it.
                let newNode = new Node(node.val, null, null);
                visited.set(node, newNode);
                return newNode;
            }
        }
        return null;
    }
    if (head == null) {
        return null;
    }
    let oldNode = head;
    // Creating the new head node.
    let newNode = new Node(oldNode.val);
    visited.set(oldNode, newNode);
    // Iterate on the linked list until all nodes are cloned.
    while (oldNode != null) {
        // Get the clones of the nodes referenced by random and next pointers.
        newNode.random = getClonedNode(oldNode.random);
        newNode.next = getClonedNode(oldNode.next);
        // Move one step ahead in the linked list.
        oldNode = oldNode.next;
        newNode = newNode.next;
    }
    return visited.get(head);
}
