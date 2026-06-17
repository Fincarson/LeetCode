class Solution:
    def deleteDuplicatesUnsorted(self, head: ListNode) -> ListNode:
        frequency = {}
        self.count_frequencies(head, frequency)
        return self.delete_duplicates_unsorted_helper(head, frequency)

    # Count the frequency of each value in the list
    def count_frequencies(self, head: ListNode, frequency: dict):
        current = head
        while current is not None:
            frequency[current.val] = frequency.get(current.val, 0) + 1
            current = current.next

    # Recursively delete duplicates based on the frequency map
    def delete_duplicates_unsorted_helper(
        self, head: ListNode, frequency: dict
    ) -> ListNode:
        if head is None:
            return None

        # Recursive call for the next node
        updated_next_node = self.delete_duplicates_unsorted_helper(
            head.next, frequency
        )
        head.next = updated_next_node

        # If the current node is a duplicate, return the updated next node
        if frequency[head.val] > 1:
            return updated_next_node

        # Otherwise, return the current node
        return head
