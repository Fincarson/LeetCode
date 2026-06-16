var addTwoNumbers = function(l1, l2) {
    const head = l1 || l2;
    let current = head;
    let previous = null;
    let carry = 0;

    while (l1 || l2 || carry) {
        if (!current) {
            current = new ListNode(0);
            previous.next = current;
        }

        let total = carry;
        if (l1) {
            total += l1.val;
            l1 = l1.next;
        }

        if (l2) {
            total += l2.val;
            l2 = l2.next;
        }

        current.val = total % 10;
        carry = Math.floor(total / 10);
        previous = current;

        if (current.next) {
            current = current.next;
        } else if (l1) {
            current.next = l1;
            current = current.next;
        } else if (l2) {
            current.next = l2;
            current = current.next;
        } else {
            current = null;
        }
    }

    return head;
};
