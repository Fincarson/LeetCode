public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        return Add(l1, l2, 0);
    }

    private ListNode Add(ListNode l1, ListNode l2, int carry) {
        if (l1 == null && l2 == null && carry == 0) {
            return null;
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

        ListNode node = new ListNode(total % 10);
        node.next = Add(l1, l2, total / 10);
        return node;
    }
}
