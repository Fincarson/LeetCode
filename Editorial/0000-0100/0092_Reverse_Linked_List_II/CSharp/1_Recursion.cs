public class Solution {
    private ListNode left = null;
    private bool stop = false;

    public void recurseAndReverse(ListNode right, int m, int n) {
        if (n == 1)
            return;
        right = right.next;
        if (m > 1)
            this.left = this.left.next;
        this.recurseAndReverse(right, m - 1, n - 1);
        if (this.left == right || right.next == this.left)
            this.stop = true;
        if (!this.stop) {
            int tmp = this.left.val;
            this.left.val = right.val;
            right.val = tmp;
            this.left = this.left.next;
        }
    }

    public ListNode ReverseBetween(ListNode head, int m, int n) {
        stop = false;
        left = head;
        recurseAndReverse(head, m, n);
        return head;
    }
}
