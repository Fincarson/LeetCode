public class Solution {
    public bool HasCycle(ListNode head) {
        HashSet<ListNode> nodesSeen = new HashSet<ListNode>();
        ListNode current = head;
        while (current != null) {
            if (nodesSeen.Contains(current)) {
                return true;
            }

            nodesSeen.Add(current);
            current = current.next;
        }

        return false;
    }
}
