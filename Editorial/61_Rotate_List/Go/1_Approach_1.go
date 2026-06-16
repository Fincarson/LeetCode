func rotateRight(head *ListNode, k int) *ListNode {
    // base cases
    if head == nil {
        return nil
    }
    if head.Next == nil {
        return head
    }
    // close the linked list into the ring
    old_tail := head
    n := 1
    for old_tail.Next != nil {
        n++
        old_tail = old_tail.Next
    }
    old_tail.Next = head
    // find new tail : (n - k % n - 1)th node
    // and new head : (n - k % n)th node
    new_tail := head
    for i := 1; i < n-k%n; i++ {
        new_tail = new_tail.Next
    }
    new_head := new_tail.Next
    // break the ring
    new_tail.Next = nil
    return new_head
}
