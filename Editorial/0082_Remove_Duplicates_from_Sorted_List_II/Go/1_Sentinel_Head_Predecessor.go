func deleteDuplicates(head *ListNode) *ListNode {
    // sentinel
    sentinel := &ListNode{0, head}
    // predecessor = the last node
    // before the sublist of duplicates
    pred := sentinel
    for head != nil {
        // If it's a beginning of duplicates sublist
        // skip all duplicates
        if head.Next != nil && head.Val == head.Next.Val {
            // move till the end of duplicates sublist
            for head.Next != nil && head.Val == head.Next.Val {
                head = head.Next
            }
            // Skip all duplicates
            pred.Next = head.Next
            // otherwise, move predecessor
        } else {
            pred = pred.Next
        }
        // move forward
        head = head.Next
    }
    return sentinel.Next
}
