function reverseBetween(
    head: ListNode | null,
    m: number,
    n: number,
): ListNode | null {
    if (head == null) return null;
    let left: ListNode = head,
        stop: boolean = false;
    const recurseAndReverse = (
        right: ListNode | null,
        m: number,
        n: number,
    ) => {
        if (right == null || n == 1) return;
        right = right.next;
        if (m > 1) left = left.next;
        recurseAndReverse(right, m - 1, n - 1);
        if (left === right || (right && right.next === left)) stop = true;
        if (!stop) {
            let tmp = left.val;
            left.val = right.val;
            right.val = tmp;
            left = left.next;
        }
    };
    recurseAndReverse(head, m, n);
    return head;
}
