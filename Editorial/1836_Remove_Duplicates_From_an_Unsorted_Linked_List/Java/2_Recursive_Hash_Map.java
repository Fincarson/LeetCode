class Solution {

    public ListNode deleteDuplicatesUnsorted(ListNode head) {
        HashMap<Integer, Integer> frequency = new HashMap<>();
        countFrequencies(head, frequency);
        return deleteDuplicatesUnsortedHelper(head, frequency);
    }

    // Count the frequency of each value in the list
    private void countFrequencies(
        ListNode head,
        HashMap<Integer, Integer> frequency
    ) {
        ListNode current = head;
        while (current != null) {
            frequency.put(
                current.val,
                frequency.getOrDefault(current.val, 0) + 1
            );
            current = current.next;
        }
    }

    // Recursively delete duplicates based on the frequency map
    private ListNode deleteDuplicatesUnsortedHelper(
        ListNode head,
        HashMap<Integer, Integer> frequency
    ) {
        if (head == null) {
            return null;
        }

        // Recursive call for the next node
        ListNode updatedNextNode = deleteDuplicatesUnsortedHelper(
            head.next,
            frequency
        );
        head.next = updatedNextNode;

        // If the current node is a duplicate, return the updated next node
        if (frequency.get(head.val) > 1) {
            return updatedNextNode;
        }

        // Otherwise, return the current node
        return head;
    }
}
