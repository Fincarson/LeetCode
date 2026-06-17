/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
var detectCycle = function (head) {
    // Initialize an empty hash set
    let nodesSeen = new Set();
    // Start from the head of the linked list
    let node = head;
    while (node !== null) {
        // If the current node is in nodesSeen, we have a cycle
        if (nodesSeen.has(node)) {
            return node;
        } else {
            // Add this node to nodesSeen and move to the next node
            nodesSeen.add(node);
            node = node.next;
        }
    }
    // If we reach a null node, there is no cycle
    return null;
};
