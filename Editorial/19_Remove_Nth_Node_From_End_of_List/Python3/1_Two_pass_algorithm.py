class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        length = 0
        first = head
        while first is not None:
            length += 1
            first = first.next
        length -= n
        first = dummy
        while length > 0:
            length -= 1
            first = first.next
        first.next = first.next.next
        return dummy.next
