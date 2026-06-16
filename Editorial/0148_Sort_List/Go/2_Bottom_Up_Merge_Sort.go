var (
    tail        *ListNode
    nextSubList *ListNode
)

func sortList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    n := getCount(head)
    start := head
    dummyHead := &ListNode{}
    for size := 1; size < n; size = size * 2 {
        tail = dummyHead
        for start != nil {
            if start.Next == nil {
                tail.Next = start
                break
            }
            mid := split(start, size)
            merge(start, mid)
            start = nextSubList
        }
        start = dummyHead.Next
    }
    return dummyHead.Next
}

func split(start *ListNode, size int) *ListNode {
    midPrev := start
    end := start.Next
    for index := 1; index < size && (midPrev.Next != nil || end.Next != nil); index++ {
        if end.Next != nil {
            if end.Next.Next != nil {
                end = end.Next.Next
            } else {
                end = end.Next
            }
        }
        if midPrev.Next != nil {
            midPrev = midPrev.Next
        }
    }
    mid := midPrev.Next
    nextSubList = end.Next
    midPrev.Next = nil
    if end != nil {
        end.Next = nil
    }
    return mid
}

func merge(list1 *ListNode, list2 *ListNode) {
    dummyHead := &ListNode{}
    newTail := dummyHead
    for list1 != nil && list2 != nil {
        if list1.Val < list2.Val {
            newTail.Next = list1
            list1 = list1.Next
        } else {
            newTail.Next = list2
            list2 = list2.Next
        }
        newTail = newTail.Next
    }
    if list1 != nil {
        newTail.Next = list1
    } else {
        newTail.Next = list2
    }
    for newTail.Next != nil {
        newTail = newTail.Next
    }
    tail.Next = dummyHead.Next
    tail = newTail
}

func getCount(head *ListNode) int {
    cnt := 0
    ptr := head
    for ptr != nil {
        ptr = ptr.Next
        cnt++
    }
    return cnt
}
