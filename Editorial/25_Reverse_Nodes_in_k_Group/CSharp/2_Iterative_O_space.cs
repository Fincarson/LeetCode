public class Solution {
    public ListNode ReverseLinkedList(ListNode head, int k) {
        ListNode newHead = null;
        ListNode ptr = head;
        while (k > 0) {
            ListNode nextNode = ptr.next;
            ptr.next = newHead;
            newHead = ptr;
            ptr = nextNode;
            k--;
        }

        return newHead;
    }

    public ListNode ReverseKGroup(ListNode head, int k) {
        ListNode ptr = head;
        ListNode ktail = null;
        ListNode newHead = null;
        while (ptr != null) {
            int count = 0;
            ptr = head;
            while (count < k && ptr != null) {
                ptr = ptr.next;
                count += 1;
            }

            if (count == k) {
                ListNode revHead = this.ReverseLinkedList(head, k);
                if (newHead == null) {
                    newHead = revHead;
                }

                if (ktail != null) {
                    ktail.next = revHead;
                }

                ktail = head;
                head = ptr;
            }
        }

        if (ktail != null) {
            ktail.next = head;
        }

        return newHead == null ? head : newHead;
    }
}
