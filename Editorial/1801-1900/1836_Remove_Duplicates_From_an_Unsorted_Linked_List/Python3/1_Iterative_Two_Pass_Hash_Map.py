class Solution:
    def deleteDuplicatesUnsorted(self, head: ListNode) -> ListNode:
        dummy = ListNode(-1, head)
        frequency = {}
        temp = head
        current = dummy.next
        prev = dummy

        # Count occurrences of each value in the linked list.
        while temp:
            if temp.val in frequency:
                frequency[temp.val] += 1
            else:
                frequency[temp.val] = 1
            temp = temp.next

        # Traverse the list and remove nodes with values that appear more than
        # once.
        while current:
            if frequency[current.val] > 1:
                # Delete current node from the list
                prev.next = current.next
            else:
                prev = current
            current = current.next
        return dummy.next
