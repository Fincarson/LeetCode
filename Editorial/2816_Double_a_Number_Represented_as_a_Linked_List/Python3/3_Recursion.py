class Solution:
    # To compute twice the value of each node's value and propagate carry
    def twice_of_val(self, head: Optional[ListNode]) -> int:
        # Base case: if head is None, return 0
        if not head:
            return 0
        
        # Double the value of current node and add the result of next nodes
        doubled_value = head.val * 2 + self.twice_of_val(head.next)
        
        # Update current node's value with the units digit of the result
        head.val = doubled_value % 10
        
        # Return the carry (tens digit of the result)
        return doubled_value // 10
    
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        carry = self.twice_of_val(head)
        
        # If there's a carry, insert a new node at the beginning with the carry value
        if carry:
            head = ListNode(carry, head)
        
        # Return the head of the updated linked list
        return head
