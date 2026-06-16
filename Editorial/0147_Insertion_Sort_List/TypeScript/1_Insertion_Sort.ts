function insertionSortList(head: ListNode | null): ListNode | null {
    let dummy = new ListNode();
    let curr = head;
    while (curr !== null) {
        // At each iteration, we insert an element into the resulting list.
        let prev = dummy;
        // find the position to insert the current node
        while (prev.next !== null && prev.next.val <= curr.val) {
            prev = prev.next;
        }
        let next = curr.next;
        // insert the current node to the new list
        curr.next = prev.next;
        prev.next = curr;
        // moving on to the next iteration
        curr = next;
    }
    return dummy.next;
}
