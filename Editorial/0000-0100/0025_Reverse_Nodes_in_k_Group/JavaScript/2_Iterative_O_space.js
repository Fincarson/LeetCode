var reverseLinkedList = function (head, k) {
    let new_head = null;
    let ptr = head;
    while (k > 0) {
        let next_node = ptr.next;
        ptr.next = new_head;
        new_head = ptr;
        ptr = next_node;
        k--;
    }
    return new_head;
};
var reverseKGroup = function (head, k) {
    let ptr = head;
    let ktail = null;
    let new_head = null;
    while (ptr !== null) {
        let count = 0;
        ptr = head;
        while (count < k && ptr !== null) {
            ptr = ptr.next;
            count++;
        }
        if (count === k) {
            let revHead = reverseLinkedList(head, k);
            if (new_head === null) new_head = revHead;
            if (ktail !== null) ktail.next = revHead;
            ktail = head;
            head = ptr;
        }
    }
    if (ktail !== null) ktail.next = head;
    return new_head === null ? head : new_head;
};
