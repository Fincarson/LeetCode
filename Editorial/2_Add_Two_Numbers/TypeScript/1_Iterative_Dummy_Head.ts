function addTwoNumbers(
    l1: ListNode | null,
    l2: ListNode | null
): ListNode | null {
    const dummy = new ListNode(0);
    let current = dummy;
    let carry = 0;

    while (l1 !== null || l2 !== null || carry !== 0) {
        let total = carry;

        if (l1 !== null) {
            total += l1.val;
            l1 = l1.next;
        }

        if (l2 !== null) {
            total += l2.val;
            l2 = l2.next;
        }

        carry = Math.floor(total / 10);
        current.next = new ListNode(total % 10);
        current = current.next;
    }

    return dummy.next;
}
