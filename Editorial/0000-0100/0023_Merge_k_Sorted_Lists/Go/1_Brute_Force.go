func mergeKLists(lists []*ListNode) *ListNode {
    nodes := make([]int, 0, 10000)
    dummyNode := &ListNode{}
    currNode := dummyNode
    for _, l := range lists {
        for l != nil {
            nodes = append(nodes, l.Val)
            l = l.Next
        }
    }
    sort.Ints(nodes)
    for _, v := range nodes {
        currNode.Next = &ListNode{Val: v}
        currNode = currNode.Next
    }
    return dummyNode.Next
}
