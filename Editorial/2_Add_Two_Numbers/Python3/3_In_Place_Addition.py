class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        head = l1 or l2
        current = head
        previous = None
        carry = 0

        while l1 or l2 or carry:
            if current is None:
                current = ListNode(0)
                previous.next = current

            total = carry
            if l1:
                total += l1.val
                l1 = l1.next

            if l2:
                total += l2.val
                l2 = l2.next

            current.val = total % 10
            carry = total // 10
            previous = current

            if current.next:
                current = current.next
            elif l1:
                current.next = l1
                current = current.next
            elif l2:
                current.next = l2
                current = current.next
            else:
                current = None

        return head
