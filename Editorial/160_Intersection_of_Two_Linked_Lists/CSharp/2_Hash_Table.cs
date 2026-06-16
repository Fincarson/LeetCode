public class Solution {
    public ListNode GetIntersectionNode(ListNode headA, ListNode headB) {
        HashSet<ListNode> nodesInB = new HashSet<ListNode>();

        while (headB != null) {
            nodesInB.Add(headB);
            headB = headB.next;
        }

        while (headA != null) {
            // if we find the node pointed to by headA,
            // in our set containing nodes of B, then return the node
            if (nodesInB.Contains(headA)) {
                return headA;
            }

            headA = headA.next;
        }

        return null;
    }
}
