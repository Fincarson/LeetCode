function mergeKLists(lists: Array<ListNode | null>): ListNode | null {
    let nodes: number[] = [];
    let dummy: ListNode = new ListNode(0);
    let point: ListNode = dummy;
    lists.forEach((l) => {
        while (l) {
            nodes.push(l.val);
            l = l.next;
        }
    });
    nodes
        .sort((a, b) => a - b)
        .forEach((n) => {
            point.next = new ListNode(n);
            point = point.next;
        });
    return dummy.next;
}
