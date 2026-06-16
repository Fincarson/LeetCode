class Solution {
    public String gameResult(ListNode head) {
        ListNode currentNode = head;
        int pointDifference = 0;

        while (currentNode != null) {
            // Update the point difference based on the comparison of current and next nodes
            if (currentNode.next != null) {
                pointDifference += (currentNode.val > currentNode.next.val) ? 1 : -1;
            }
            
            // Move two steps ahead in the linked list to the next even node
            currentNode = currentNode.next.next;
        }

        // Determine the winner based on the final score difference
        if (pointDifference < 0)
            return "Odd";
        else if (pointDifference > 0)
            return "Even";
        else
            return "Tie";
    }
}
