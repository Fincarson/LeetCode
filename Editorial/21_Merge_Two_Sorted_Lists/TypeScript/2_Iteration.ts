function mergeTwoLists(
    l1: ListNode | null,
    l2: ListNode | null,
): ListNode | null {
    let prehead: ListNode = new ListNode(-1);
    let prev: ListNode = prehead;
    while (l1 !== null && l2 !== null) {
        if (l1.val <= l2.val) {
            prev.next = l1;
            l1 = l1.next;
        } else {
            prev.next = l2;
            l2 = l2.next;
        }
        prev = prev.next;
    }
    if (l1 !== null) {
        prev.next = l1;
    } else {
        prev.next = l2;
    }
    return prehead.next;
}
