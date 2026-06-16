func reverseLinkedList(head *ListNode, k int) *ListNode {
    var newHead *ListNode = nil
    ptr := head
    for k > 0 {
        nextNode := ptr.Next
        ptr.Next = newHead
        newHead = ptr
        ptr = nextNode
        k--
    }
    return newHead
}

func reverseKGroup(head *ListNode, k int) *ListNode {
    count := 0
    ptr := head
    for count < k && ptr != nil {
        ptr = ptr.Next
        count++
    }
    if count == k {
        reversedHead := reverseLinkedList(head, k)
        head.Next = reverseKGroup(ptr, k)
        return reversedHead
    }
    return head
}
