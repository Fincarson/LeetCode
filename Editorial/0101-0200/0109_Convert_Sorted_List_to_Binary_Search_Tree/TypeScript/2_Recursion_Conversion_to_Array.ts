function sortedListToBST(head: ListNode): TreeNode | null {
    // Convert the given linked list to an array
    let values: number[] = [];
    while (head) {
        values.push(head.val);
        head = head.next;
    }
    function convertListToBST(l: number, r: number): TreeNode | null {
        // Invalid case
        if (l > r) {
            return null;
        }
        // Middle element forms the root.
        let mid = Math.floor((l + r) / 2);
        let node = new TreeNode(values[mid]);
        // Base case for when there is only one element left in the array
        if (l == r) {
            return node;
        }
        // Recursively form BST on the two halves
        node.left = convertListToBST(l, mid - 1);
        node.right = convertListToBST(mid + 1, r);
        return node;
    }
    return convertListToBST(0, values.length - 1);
}
