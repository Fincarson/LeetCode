function addTwoNumbers(
    l1: ListNode | null,
    l2: ListNode | null
): ListNode | null {
    function add(
        node1: ListNode | null,
        node2: ListNode | null,
        carry: number
    ): ListNode | null {
        if (node1 === null && node2 === null && carry === 0) {
            return null;
        }

        let total = carry;
        let next1: ListNode | null = null;
        let next2: ListNode | null = null;

        if (node1 !== null) {
            total += node1.val;
            next1 = node1.next;
        }

        if (node2 !== null) {
            total += node2.val;
            next2 = node2.next;
        }

        const node = new ListNode(total % 10);
        node.next = add(next1, next2, Math.floor(total / 10));
        return node;
    }

    return add(l1, l2, 0);
}
