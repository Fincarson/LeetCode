/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 *
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public TreeNode SortedListToBST(ListNode head) {
        if (head == null)
            return null;
        ListNode mid = FindMiddleElement(head);
        TreeNode node = new TreeNode(mid.val);
        if (head == mid)
            return node;
        node.left = this.SortedListToBST(head);
        node.right = this.SortedListToBST(mid.next);
        return node;
    }

    private ListNode FindMiddleElement(ListNode head) {
        ListNode prevPtr = null;
        ListNode slowPtr = head;
        ListNode fastPtr = head;
        while (fastPtr != null && fastPtr.next != null) {
            prevPtr = slowPtr;
            slowPtr = slowPtr.next;
            fastPtr = fastPtr.next.next;
        }

        if (prevPtr != null)
            prevPtr.next = null;
        return slowPtr;
    }
}
