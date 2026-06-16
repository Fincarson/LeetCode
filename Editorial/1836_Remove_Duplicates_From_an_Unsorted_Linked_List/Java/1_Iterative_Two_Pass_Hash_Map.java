public class Solution {

    public ListNode deleteDuplicatesUnsorted(ListNode head) {
        ListNode dummy = new ListNode(-1, head);
        Map<Integer, Integer> frequency = new HashMap<Integer, Integer>();
        ListNode temp = head, current = dummy.next, prev = dummy;

        // Count occurrences of each value in the linked list.
        while (temp != null) {
            frequency.put(temp.val, frequency.getOrDefault(temp.val, 0) + 1);
            temp = temp.next;
        }

        // Traverse the list and remove nodes with values that appear more than
        // once.
        while (current != null) {
            if (frequency.get(current.val) > 1) {
                // Delete current node from the list
                prev.next = current.next;
            } else {
                prev = current;
            }
            current = current.next;
        }
        return dummy.next;
    }
}
