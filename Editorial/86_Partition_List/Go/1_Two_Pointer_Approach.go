func partition(head *ListNode, x int) *ListNode {
    before_head := &ListNode{0, nil}
    before := before_head
    after_head := &ListNode{0, nil}
    after := after_head
    for head != nil {
        if head.Val < x {
            before.Next = head
            before = before.Next
        } else {
            after.Next = head
            after = after.Next
        }
        head = head.Next
    }
    after.Next = nil
    before.Next = after_head.Next
    return before_head.Next
}
