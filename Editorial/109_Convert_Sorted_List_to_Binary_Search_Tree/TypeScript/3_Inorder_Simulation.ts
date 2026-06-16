/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 *
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */
function sortedListToBST(head: ListNode | null): TreeNode | null {
    let currentNode = head;
    let findSize = function (head: ListNode | null): number {
        let ptr = head,
            c = 0;
        while (ptr) {
            ptr = ptr.next;
            c++;
        }
        return c;
    };
    let convert = function (l: number, r: number): TreeNode | null {
        if (l > r) return null;
        let mid = Math.floor((l + r) / 2);
        let left = convert(l, mid - 1);
        let node = new TreeNode(currentNode.val);
        node.left = left;
        currentNode = currentNode.next;
        node.right = convert(mid + 1, r);
        return node;
    };
    let size = findSize(head);
    return convert(0, size - 1);
}
