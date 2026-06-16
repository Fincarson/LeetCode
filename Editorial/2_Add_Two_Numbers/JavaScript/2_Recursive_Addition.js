var addTwoNumbers = function(l1, l2) {
    const add = (node1, node2, carry) => {
        if (!node1 && !node2 && carry === 0) {
            return null;
        }

        let total = carry;
        let next1 = null;
        let next2 = null;

        if (node1) {
            total += node1.val;
            next1 = node1.next;
        }

        if (node2) {
            total += node2.val;
            next2 = node2.next;
        }

        const node = new ListNode(total % 10);
        node.next = add(next1, next2, Math.floor(total / 10));
        return node;
    };

    return add(l1, l2, 0);
};
