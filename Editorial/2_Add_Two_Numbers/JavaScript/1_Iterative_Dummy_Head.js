var addTwoNumbers = function(l1, l2) {
    const dummy = new ListNode(0);
    let current = dummy;
    let carry = 0;

    while (l1 || l2 || carry) {
        let total = carry;

        if (l1) {
            total += l1.val;
            l1 = l1.next;
        }

        if (l2) {
            total += l2.val;
            l2 = l2.next;
        }

        carry = Math.floor(total / 10);
        current.next = new ListNode(total % 10);
        current = current.next;
    }

    return dummy.next;
};
