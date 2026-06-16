func sortList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    mid := getMid(head)
    left := sortList(head)
    right := sortList(mid)
    return merge(left, right)
}

func merge(list1, list2 *ListNode) *ListNode {
    dummyHead := &ListNode{}
    tail := dummyHead
    for list1 != nil && list2 != nil {
        if list1.Val < list2.Val {
            tail.Next = list1
            list1 = list1.Next
        } else {
            tail.Next = list2
            list2 = list2.Next
        }
        tail = tail.Next
    }
    if list1 != nil {
        tail.Next = list1
    } else {
        tail.Next = list2
    }
    return dummyHead.Next
}

func getMid(head *ListNode) *ListNode {
    midPrev := (*ListNode)(nil)
    for head != nil && head.Next != nil {
        if midPrev == nil {
            midPrev = head
        } else {
            midPrev = midPrev.Next
        }
        head = head.Next.Next
    }
    mid := midPrev.Next
    midPrev.Next = nil
    return mid
}
