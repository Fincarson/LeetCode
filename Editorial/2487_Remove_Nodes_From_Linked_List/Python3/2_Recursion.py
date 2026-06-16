class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Base case, reached end of the list
        if head is None or head.next is None:
            return head

        # Recursive call
        next_node = self.removeNodes(head.next)
        
        # If the next node has greater value than head, delete the head
        # Return next node, which removes the current head and 
        # makes next the new head
        if head.val < next_node.val:
            return next_node
     
        # Keep the head
        head.next = next_node
        return head
