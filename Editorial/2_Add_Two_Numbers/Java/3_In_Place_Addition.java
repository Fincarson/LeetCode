class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = l1 != null ? l1 : l2;
        ListNode current = head;
        ListNode previous = null;
        int carry = 0;

        while (l1 != null || l2 != null || carry != 0) {
            if (current == null) {
                current = new ListNode(0);
                previous.next = current;
            }

            int total = carry;
            if (l1 != null) {
                total += l1.val;
                l1 = l1.next;
            }

            if (l2 != null) {
                total += l2.val;
                l2 = l2.next;
            }

            current.val = total % 10;
            carry = total / 10;
            previous = current;

            if (current.next != null) {
                current = current.next;
            } else if (l1 != null) {
                current.next = l1;
                current = current.next;
            } else if (l2 != null) {
                current.next = l2;
                current = current.next;
            } else {
                current = null;
            }
        }

        return head;
    }
}
