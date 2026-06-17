var reverseBetween = function (head, m, n) {
    if (head === null) {
        return null;
    }
    let cur = head,
        prev = null;
    while (m > 1) {
        prev = cur;
        cur = cur.next;
        m--;
        n--;
    }
    let con = prev,
        tail = cur;
    let third = null;
    while (n > 0) {
        third = cur.next;
        cur.next = prev;
        prev = cur;
        cur = third;
        n--;
    }
    if (con !== null) {
        con.next = prev;
    } else {
        head = prev;
    }
    tail.next = cur;
    return head;
};
