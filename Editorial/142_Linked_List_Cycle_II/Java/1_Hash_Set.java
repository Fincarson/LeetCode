public class Solution {
    public ListNode detectCycle(ListNode head) {
        // Initialize an empty hash set
        HashSet<ListNode> nodesSeen = new HashSet<>();

        // Start from the head of the linked list
        ListNode node = head;
        while (node != null) {
            // If the current node is in nodesSeen, we have a cycle
            if (nodesSeen.contains(node)) {
                return node;
            } else {
                // Add this node to nodesSeen and move to the next node
                nodesSeen.add(node);
                node = node.next;
            }
        }

        // If we reach a null node, there is no cycle
        return null;
    }
}
