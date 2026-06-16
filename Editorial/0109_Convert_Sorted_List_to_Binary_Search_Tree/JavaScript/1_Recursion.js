/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 *
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
var sortedListToBST = function (head) {
    if (!head) return null;
    var mid = findMiddleElement(head);
    var node = new TreeNode(mid.val);
    if (head === mid) return node;
    node.left = sortedListToBST(head);
    node.right = sortedListToBST(mid.next);
    return node;
};
var findMiddleElement = function (head) {
    var prevPtr = null;
    var slowPtr = head;
    var fastPtr = head;
    while (fastPtr && fastPtr.next) {
        prevPtr = slowPtr;
        slowPtr = slowPtr.next;
        fastPtr = fastPtr.next.next;
    }
    if (prevPtr != null) prevPtr.next = null;
    return slowPtr;
};
