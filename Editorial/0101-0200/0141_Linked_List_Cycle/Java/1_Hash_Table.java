public class Solution {
    public boolean hasCycle(ListNode head) {
        Set<ListNode> nodesSeen = new HashSet<>();
        ListNode current = head;
        while (current != null) {
            if (nodesSeen.contains(current)) {
                return true;
            }
            nodesSeen.add(current);
            current = current.next;
        }
        return false;
    }
}
