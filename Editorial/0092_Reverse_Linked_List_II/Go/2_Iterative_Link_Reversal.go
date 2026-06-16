func reverseBetween(head *ListNode, m int, n int) *ListNode {
    if head == nil {
        return nil
    }
    var cur, prev *ListNode = head, nil
    for ; m > 1; m, n = m-1, n-1 {
        prev = cur
        cur = cur.Next
    }
    var con, tail *ListNode = prev, cur
    var third *ListNode = nil
    for ; n > 0; n-- {
        third = cur.Next
        cur.Next = prev
        prev = cur
        cur = third
    }
    if con != nil {
        con.Next = prev
    } else {
        head = prev
    }
    tail.Next = cur
    return head
}
