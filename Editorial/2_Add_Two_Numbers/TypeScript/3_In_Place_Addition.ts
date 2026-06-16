function addTwoNumbers(
    l1: ListNode | null,
    l2: ListNode | null
): ListNode | null {
    const head = l1 ?? l2;
    let current = head;
    let previous: ListNode | null = null;
    let carry = 0;

    while (l1 !== null || l2 !== null || carry !== 0) {
        if (current === null) {
            current = new ListNode(0);
            previous!.next = current;
        }

        let total = carry;
        if (l1 !== null) {
            total += l1.val;
            l1 = l1.next;
        }

        if (l2 !== null) {
            total += l2.val;
            l2 = l2.next;
        }

        current.val = total % 10;
        carry = Math.floor(total / 10);
        previous = current;

        if (current.next !== null) {
            current = current.next;
        } else if (l1 !== null) {
            current.next = l1;
            current = current.next;
        } else if (l2 !== null) {
            current.next = l2;
            current = current.next;
        } else {
            current = null;
        }
    }

    return head;
}
