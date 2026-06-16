/**
 * Definition for singly-linked list.
 * class ListNode { constructor(public val: number, public next: ListNode | null = null) { } }
 *
 * Definition for a binary tree node.
 * class TreeNode { constructor(public val: number, public left: TreeNode | null = null, public right: TreeNode | null = null) { } }
 */
function sortedListToBST(head: ListNode | null): TreeNode | null {
    if (!head) {
        return null;
    }
    const mid = findMiddleElement(head);
    const node: TreeNode = new TreeNode(mid.val);
    if (head === mid) {
        return node;
    }
    node.left = sortedListToBST(head);
    node.right = sortedListToBST(mid.next);
    return node;
}
function findMiddleElement(head: ListNode | null): ListNode | null {
    let prevPtr: ListNode | null = null;
    let slowPtr: ListNode | null = head;
    let fastPtr: ListNode | null = head;
    while (fastPtr !== null && fastPtr.next !== null) {
        prevPtr = slowPtr;
        slowPtr = slowPtr !== null ? slowPtr.next : null;
        fastPtr =
            fastPtr !== null && fastPtr.next !== null
                ? fastPtr.next.next
                : null;
    }
    if (prevPtr !== null) {
        prevPtr.next = null;
    }
    return slowPtr;
}
