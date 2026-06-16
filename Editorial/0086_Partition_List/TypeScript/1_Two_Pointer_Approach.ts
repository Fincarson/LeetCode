function partition(head: ListNode | null, x: number): ListNode | null {
    let before_head: ListNode = new ListNode(0);
    let before: ListNode = before_head;
    let after_head: ListNode = new ListNode(0);
    let after: ListNode = after_head;
    while (head !== null) {
        if (head.val < x) {
            before.next = head;
            before = before.next;
        } else {
            after.next = head;
            after = after.next;
        }
        head = head.next;
    }
    after.next = null;
    before.next = after_head.next;
    return before_head.next;
}
