func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    head := l1
    if head == nil {
        head = l2
    }

    current := head
    var previous *ListNode
    carry := 0

    for l1 != nil || l2 != nil || carry != 0 {
        if current == nil {
            current = &ListNode{}
            previous.Next = current
        }

        total := carry
        if l1 != nil {
            total += l1.Val
            l1 = l1.Next
        }

        if l2 != nil {
            total += l2.Val
            l2 = l2.Next
        }

        current.Val = total % 10
        carry = total / 10
        previous = current

        if current.Next != nil {
            current = current.Next
        } else if l1 != nil {
            current.Next = l1
            current = current.Next
        } else if l2 != nil {
            current.Next = l2
            current = current.Next
        } else {
            current = nil
        }
    }

    return head
}
