func reverseLinkedList(head *ListNode, k int) *ListNode {
    var newHead, ptr *ListNode = nil, head
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
    ptr, ktail := head, &ListNode{}
    var newHead *ListNode = nil
    for ptr != nil {
        count := 0
        ptr = head
        for count < k && ptr != nil {
            ptr = ptr.Next
            count++
        }
        if count == k {
            revHead := reverseLinkedList(head, k)
            if newHead == nil {
                newHead = revHead
            }
            if ktail != nil {
                ktail.Next = revHead
            }
            ktail = head
            head = ptr
        }
    }
    if ktail != nil {
        ktail.Next = head
    }
    if newHead == nil {
        return head
    } else {
        return newHead
    }
}
