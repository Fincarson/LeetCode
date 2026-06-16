public class ListNode {

    int val;
    ListNode next;

    ListNode() {}

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class MRUQueue {

    private ListNode head;
    private ListNode tail;

    public MRUQueue(int n) {
        this.head = new ListNode(0, null);
        ListNode current = head;

        // Initialize the linked list with values from 1 to n
        for (int number = 1; number <= n; ++number) {
            current.next = new ListNode(number, null);
            current = current.next;
        }

        tail = current;
    }

    public int fetch(int k) {
        ListNode current = head;

        // Traverse to the node before the k-th node
        for (int index = 1; index < k; ++index) {
            current = current.next;
        }

        // Get the value of the k-th node
        int value = current.next.val;

        // Move the k-th node to the end of the list
        tail.next = current.next;
        tail = tail.next;
        current.next = tail.next;
        tail.next = null;

        return value;
    }
}
