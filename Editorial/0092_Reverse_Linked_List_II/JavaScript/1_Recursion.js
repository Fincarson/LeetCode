var reverseBetween = function (head, m, n) {
    let left = head,
        stop = false;
    const recurseAndReverse = (right, m, n) => {
        if (n == 1) return;
        right = right.next;
        if (m > 1) left = left.next;
        recurseAndReverse(right, m - 1, n - 1);
        if (left == right || right.next == left) stop = true;
        if (!stop) {
            [left.val, right.val] = [right.val, left.val];
            left = left.next;
        }
    };
    recurseAndReverse(head, m, n);
    return head;
};
