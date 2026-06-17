/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
var sortedListToBST = function (head) {
    var findSize = function (head) {
        let ptr = head,
            c = 0;
        while (ptr !== null) {
            ptr = ptr.next;
            c += 1;
        }
        return c;
    };
    var convertListToBST = function (l, r) {
        if (l > r) return null;
        let mid = Math.floor((l + r) / 2);
        let left = convertListToBST(l, mid - 1);
        let node = new TreeNode(head.val);
        node.left = left;
        head = head.next;
        node.right = convertListToBST(mid + 1, r);
        return node;
    };
    let size = findSize(head);
    return convertListToBST(0, size - 1);
};
