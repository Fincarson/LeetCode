function sortedListToBST(head) {
    // Convert the given linked list to an array
    let values = [];
    while (head) {
        values.push(head.val);
        head = head.next;
    }
    function convertListToBST(l, r) {
        // Invalid case
        if (l > r) {
            return null;
        }
        // Middle element forms the root.
        let mid = Math.floor((l + r) / 2);
        // Base case for when there is only one element left in the array
        let node = new TreeNode(values[mid]);
        if (l == r) {
            return node;
        }
        // Recursively form BST on the two halves
        node.left = convertListToBST(l, mid - 1);
        node.right = convertListToBST(mid + 1, r);
        return node;
    }
    // Form a BST out of the given array and then return the root of the newly formed BST
    return convertListToBST(0, values.length - 1);
}
