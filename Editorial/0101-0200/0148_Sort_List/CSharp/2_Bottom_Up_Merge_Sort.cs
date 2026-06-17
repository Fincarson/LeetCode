public class Solution {
    private ListNode tail;
    private ListNode nextSubList;

    // Sorts the linked list using merge sort
    public ListNode SortList(ListNode head) {
        if (head == null || head.next == null)
            return head;

        int n = GetCount(head);
        ListNode start = head;
        ListNode dummyHead = new ListNode();
        for (int size = 1; size < n; size *= 2) {
            tail = dummyHead;
            while (start != null) {
                if (start.next == null) {
                    tail.next = start;
                    break;
                }

                ListNode mid = Split(start, size);
                Merge(start, mid);
                start = nextSubList;
            }

            start = dummyHead.next;
        }

        return dummyHead.next;
    }

    // Splits the list into two and returns the middle node
    private ListNode Split(ListNode start, int size) {
        ListNode midPrev = start;
        ListNode end = start.next;
        // Use fast and slow approach to find middle and end of second linked
        // list
        for (int index = 1; index < size && (midPrev.next != null ||
                                             (end != null && end.next != null));
             index++) {
            if (end != null && end.next != null) {
                end = (end.next.next != null) ? end.next.next : end.next;
            }

            if (midPrev.next != null) {
                midPrev = midPrev.next;
            }
        }

        ListNode mid = midPrev.next;
        midPrev.next = null;
        nextSubList = end != null ? end.next : null;
        if (end != null)
            end.next = null;
        // Return the start of second linked list
        return mid;
    }

    // Merges two sorted lists
    private void Merge(ListNode list1, ListNode list2) {
        ListNode dummyHead = new ListNode();
        ListNode newTail = dummyHead;
        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                newTail.next = list1;
                list1 = list1.next;
                newTail = newTail.next;
            } else {
                newTail.next = list2;
                list2 = list2.next;
                newTail = newTail.next;
            }
        }

        newTail.next = (list1 != null) ? list1 : list2;
        // Traverse till the end of merged list to get the newTail
        while (newTail.next != null) {
            newTail = newTail.next;
        }

        // Link the old tail with the head of merged list
        tail.next = dummyHead.next;
        // Update the old tail to the new tail of merged list
        tail = newTail;
    }

    // Counts the number of nodes in the list
    private int GetCount(ListNode head) {
        int cnt = 0;
        ListNode ptr = head;
        while (ptr != null) {
            ptr = ptr.next;
            cnt++;
        }

        return cnt;
    }
}
