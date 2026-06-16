class Solution {
    public ListNode removeZeroSumSublists(ListNode head) {
        ListNode front = new ListNode(0, head);
        ListNode current = front;
        int prefixSum = 0;
        Map<Integer, ListNode> prefixSumToNode = new HashMap<>();
        prefixSumToNode.put(0, front);

        // Calculate the prefix sum for each node and add to the hashmap
        // Duplicate prefix sum values will be replaced
        while (current != null) {
            prefixSum += current.val;
            prefixSumToNode.put(prefixSum, current);
            current = current.next;
        }

        // Reset prefix sum and current
        prefixSum = 0;
        current = front;

        // Delete zero sum consecutive sequences 
        // by setting node before sequence to node after
        while (current != null) {
            prefixSum += current.val;
            current.next = prefixSumToNode.get(prefixSum).next;
            current = current.next;
        }
        return front.next; 
    }
}
