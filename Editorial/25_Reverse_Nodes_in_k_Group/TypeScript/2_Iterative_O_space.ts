function reverseLinkedList(head: ListNode | null, k: number): ListNode | null {
    let new_head = null;
    let ptr = head;
    while (k > 0 && ptr != null) {
        let next_node = ptr.next;
        ptr.next = new_head;
        new_head = ptr;
        ptr = next_node;
        k--;
    }
    return new_head;
}
function reverseKGroup(head: ListNode | null, k: number): ListNode | null {
    let ptr = head;
    let ktail = null;
    let new_head = null;
    while (ptr != null) {
        let count = 0;
        let temp_ptr = ptr;
        while (count < k && temp_ptr != null) {
            temp_ptr = temp_ptr.next;
            count += 1;
        }
        if (count == k) {
            let revHead = reverseLinkedList(ptr, k);
            if (new_head == null) new_head = revHead;
            if (ktail != null) ktail.next = revHead;
            ktail = ptr;
            ptr = temp_ptr;
        } else {
            if (ktail != null) {
                ktail.next = ptr;
            }
            break;
        }
    }
    return new_head == null ? head : new_head;
}
