class Solution {
    public ListNode frequenciesOfElements(ListNode head) {
        Map<Integer, ListNode> frequencies = new HashMap<>();
        ListNode current = head;
        ListNode freqHead = null;

        // Process the linked list, storing
        // frequency ListNodes in the hashtable 
        while (current != null) {
            // Increment frequency of existing element
            if (frequencies.containsKey(current.val)) {
                ListNode frequencyNode = frequencies.get(current.val);
                frequencyNode.val += 1;
            // New element, create hashtable entry with frequency node
            } else {
                ListNode newFrequencyNode = new ListNode(1, freqHead);
                frequencies.put(current.val, newFrequencyNode);
                freqHead = newFrequencyNode;
            }
            current = current.next;
        }
        return freqHead;
    }
}
