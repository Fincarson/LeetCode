function deleteDuplicates(head: ListNode | null): ListNode | null {
    // sentinel
    let sentinel: ListNode = new ListNode(0, head);
    // predecessor = the last node
    // before the sublist of duplicates
    let pred: ListNode = sentinel;
    while (head !== null) {
        // If it's a beginning of duplicates sublist
        // skip all duplicates
        if (head.next !== null && head.val === head.next.val) {
            // move till the end of duplicates sublist
            while (head.next !== null && head.val === head.next.val) {
                head = head.next;
            }
            // Skip all duplicates
            pred.next = head.next;
            // otherwise, move predecessor
        } else {
            pred = pred.next;
        }
        // move forward
        head = head.next;
    }
    return sentinel.next;
}
