type Solution struct {
    stop bool
    left *ListNode
}

func (s *Solution) recurseAndReverse(right *ListNode, m int, n int) {
    if n == 1 {
        return
    }
    right = right.Next
    if m > 1 {
        s.left = s.left.Next
    }
    s.recurseAndReverse(right, m-1, n-1)
    if s.left == right || right.Next == s.left {
        s.stop = true
    }
    if !s.stop {
        t := s.left.Val
        s.left.Val = right.Val
        right.Val = t
        s.left = s.left.Next
    }
}

func reverseBetween(head *ListNode, m int, n int) *ListNode {
    sol := &Solution{left: head, stop: false}
    sol.recurseAndReverse(head, m, n)
    return head
}
