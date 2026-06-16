func insertionSortList(head *ListNode) *ListNode {
    dummy := &ListNode{}
    curr := head
    for curr != nil {
        // At each iteration, we insert an element into the resulting list.
        prev := dummy
        // find the position to insert the current node
        for prev.Next != nil && prev.Next.Val <= curr.Val {
            prev = prev.Next
        }
        next := curr.Next
        // insert the current node to the new list
        curr.Next = prev.Next
        prev.Next = curr
        // moving on to the next iteration
        curr = next
    }
    return dummy.Next
}
