class Solution:
    def addTwoNumbers(
        self,
        l1: Optional[ListNode],
        l2: Optional[ListNode],
        carry: int = 0,
    ) -> Optional[ListNode]:
        if not l1 and not l2 and carry == 0:
            return None

        total = carry
        next_l1 = None
        next_l2 = None

        if l1:
            total += l1.val
            next_l1 = l1.next

        if l2:
            total += l2.val
            next_l2 = l2.next

        node = ListNode(total % 10)
        node.next = self.addTwoNumbers(next_l1, next_l2, total // 10)
        return node
