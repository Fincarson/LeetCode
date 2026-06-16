/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode DetectCycle(ListNode head) {
        // Initialize an empty hash set
        HashSet<ListNode> nodesSeen = new HashSet<ListNode>();
        // Start from the head of the linked list
        ListNode node = head;
        while (node != null) {
            // If the current node is in nodesSeen, we have a cycle
            if (nodesSeen.Contains(node)) {
                return node;
            } else {
                // Add this node to nodesSeen and move to the next node
                nodesSeen.Add(node);
                node = node.next;
            }
        }

        // If we reach a null node, there is no cycle
        return null;
    }
}
