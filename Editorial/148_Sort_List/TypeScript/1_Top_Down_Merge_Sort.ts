function sortList(head: ListNode | null): ListNode | null {
    if (!head || !head.next) return head;

    let mid = getMid(head);
    let left = sortList(head);
    let right = sortList(mid);
    return merge(left, right);

    function merge(
        list1: ListNode | null,
        list2: ListNode | null,
    ): ListNode | null {
        let dummyHead = new ListNode(0, null);
        let tail = dummyHead;
        while (list1 && list2) {
            if (list1.val < list2.val) {
                tail.next = list1;
                list1 = list1.next;
            } else {
                tail.next = list2;
                list2 = list2.next;
            }
            tail = tail.next;
        }
        tail.next = list1 ? list1 : list2;
        return dummyHead.next;
    }

    function getMid(head: ListNode | null): ListNode | null {
        let midPrev = null;
        while (head && head.next) {
            midPrev = midPrev === null ? head : midPrev.next;
            head = head.next.next;
        }
        let mid = midPrev.next;
        midPrev.next = null;
        return mid;
    }
}
