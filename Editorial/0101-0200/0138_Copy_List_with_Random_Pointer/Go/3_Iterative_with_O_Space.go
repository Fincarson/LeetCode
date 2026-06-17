func copyRandomList(head *Node) *Node {
    if head == nil {
        return nil
    }
    // Creating a new weaved list of original and copied nodes.
    ptr := head
    for ptr != nil {
        // Cloned node
        newNode := &Node{ptr.Val, nil, nil}
        // Inserting the cloned node just next to the original node.
        // If A->B->C is the original linked list,
        // Linked list after weaving cloned nodes would be A->A'->B->B'->C->C'
        newNode.Next = ptr.Next
        ptr.Next = newNode
        ptr = newNode.Next
    }
    ptr = head
    // Now link the random pointers of the new nodes created.
    // Iterate the newly created list and use the original nodes' random pointers,
    // to assign references to random pointers for cloned nodes.
    for ptr != nil {
        if ptr.Random != nil {
            ptr.Next.Random = ptr.Random.Next
        } else {
            ptr.Next.Random = nil
        }
        ptr = ptr.Next.Next
    }
    // Unweave the linked list to get back the original linked list and the cloned list.
    // i.e. A->A'->B->B'->C->C' would be broken to A->B->C and A'->B'->C'
    ptrOldList := head      // A->B->C
    ptrNewList := head.Next // A'->B'->C'
    headOld := head.Next
    for ptrOldList != nil {
        ptrOldList.Next = ptrOldList.Next.Next
        if ptrNewList.Next != nil {
            ptrNewList.Next = ptrNewList.Next.Next
        } else {
            ptrNewList.Next = nil
        }
        ptrOldList = ptrOldList.Next
        ptrNewList = ptrNewList.Next
    }
    return headOld
}
