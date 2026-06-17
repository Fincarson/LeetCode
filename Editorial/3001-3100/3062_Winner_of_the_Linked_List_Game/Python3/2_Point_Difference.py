class Solution:
    def gameResult(self, head: Optional[ListNode]) -> str:
        current_node, point_difference = head, 0

        while current_node:
            # Update the point difference based on the comparison of current and next nodes
            point_difference += (current_node.val > current_node.next.val) - (current_node.val < current_node.next.val)
            
            # Move two steps ahead in the linked list to the next even node
            current_node = current_node.next.next

        # Determine the winner based on the final score difference
        if point_difference < 0:
            return "Odd"
        elif point_difference > 0:
            return "Even"
        else:
            return "Tie"
