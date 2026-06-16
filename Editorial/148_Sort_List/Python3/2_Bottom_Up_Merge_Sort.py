class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        n = self.getCount(head)
        start = head
        dummyHead = ListNode()
        size = 1
        while size < n:
            self.tail = dummyHead
            while start is not None:
                if start.next is None:
                    self.tail.next = start
                    break
                mid = self.split(start, size)
                self.merge(start, mid)
                start = self.nextSubList
            start = dummyHead.next
            size *= 2
        return dummyHead.next

    def split(self, start, size):
        midPrev = start
        end = start.next
        # Use fast and slow approach to find middle and end of second linked list
        for index in range(1, size):
            if end and end.next:
                end = end.next.next
            else:
                if end:
                    end = end.next
            if midPrev.next:
                midPrev = midPrev.next
        mid = midPrev.next
        midPrev.next = None
        self.nextSubList = end.next if end else None
        if end:
            end.next = None
        # Return the start of second linked list
        return mid

    def merge(self, list1, list2):
        dummyHead = ListNode()
        newTail = dummyHead
        while list1 and list2:
            if list1.val < list2.val:
                newTail.next = list1
                list1 = list1.next
            else:
                newTail.next = list2
                list2 = list2.next
            newTail = newTail.next
        newTail.next = list1 if list1 else list2
        # Traverse till the end of merged list to get the newTail
        while newTail.next:
            newTail = newTail.next
        # Link the old tail with the head of merged list
        self.tail.next = dummyHead.next
        # Update the old tail to the new tail of merged list
        self.tail = newTail

    def getCount(self, head):
        cnt = 0
        ptr = head
        while ptr:
            ptr = ptr.next
            cnt += 1
        return cnt
