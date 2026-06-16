function swapPairs(head: ListNode | null): ListNode | null {
    // If the list has no node or has only one node left.
    if (head == null || head.next == null) {
        return head;
    }
    // Nodes to be swapped
    let firstNode: ListNode | null = head;
    let secondNode: ListNode | null = head.next;
    // Swapping
    firstNode.next = swapPairs(secondNode.next);
    secondNode.next = firstNode;
    // Now the head is the second node
    return secondNode;
}
