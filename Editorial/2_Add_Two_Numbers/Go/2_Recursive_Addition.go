func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    return add(l1, l2, 0)
}

func add(l1 *ListNode, l2 *ListNode, carry int) *ListNode {
    if l1 == nil && l2 == nil && carry == 0 {
        return nil
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

    return &ListNode{
        Val:  total % 10,
        Next: add(l1, l2, total/10),
    }
}
