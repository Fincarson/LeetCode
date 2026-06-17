func sortedListToBST(head *ListNode) *TreeNode {
    // Convert the given linked list to an array
    values := []int{}
    for head != nil {
        values = append(values, head.Val)
        head = head.Next
    }
    var convertListToBST func(int, int) *TreeNode
    convertListToBST = func(l int, r int) *TreeNode {
        // Invalid case
        if l > r {
            return nil
        }
        // Middle element forms the root.
        mid := (l + r) / 2
        node := &TreeNode{Val: values[mid]}
        // Base case for when there is only one element left in the array
        if l == r {
            return node
        }
        // Recursively form BST on the two halves
        node.Left = convertListToBST(l, mid-1)
        node.Right = convertListToBST(mid+1, r)
        return node
    }
    return convertListToBST(0, len(values)-1)
}
