function sortList(head: ListNode | null): ListNode | null {
    if (!head || !head.next) return head;

    function getCount(head: ListNode): number {
        let cnt = 0,
            ptr: ListNode | null = head;
        while (ptr) {
            ptr = ptr.next;
            cnt++;
        }
        return cnt;
    }

    function split(start: ListNode, size: number): ListNode {
        let midPrev = start;
        let end = start.next!;
        // use fast and slow approach to find middle and end of second linked list
        for (
            let index = 1;
            index < size && (midPrev.next || end.next);
            index++
        ) {
            if (end.next) {
                end = end.next.next ? end.next.next : end.next;
            }
            if (midPrev.next) {
                midPrev = midPrev.next;
            }
        }
        const mid = midPrev.next!;
        midPrev.next = null;
        nextSubList = end.next;
        end.next = null;
        // return the start of second linked list
        return mid;
    }

    function merge(list1: ListNode | null, list2: ListNode | null): void {
        let dummyHead = new ListNode();
        let newTail = dummyHead;
        while (list1 && list2) {
            if (list1.val < list2.val) {
                newTail.next = list1;
                list1 = list1.next;
            } else {
                newTail.next = list2;
                list2 = list2.next;
            }
            newTail = newTail.next;
        }
        newTail.next = list1 || list2;
        // traverse till the end of merged list to get the newTail
        while (newTail.next) {
            newTail = newTail.next;
        }
        // link the old tail with the head of merged list
        tail.next = dummyHead.next;
        // update the old tail to the new tail of merged list
        tail = newTail;
    }

    let n = getCount(head);
    let start = head;
    let dummyHead = new ListNode();
    let tail: ListNode, nextSubList: ListNode | null;

    for (let size = 1; size < n; size *= 2) {
        tail = dummyHead;
        while (start) {
            if (!start.next) {
                tail.next = start;
                break;
            }
            let mid = split(start, size);
            merge(start, mid);
            start = nextSubList;
        }
        start = dummyHead.next;
    }
    return dummyHead.next;
}
