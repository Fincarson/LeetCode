class Solution {

    public int equalDigitFrequency(String s) {
        TrieNode root = new TrieNode(); // Initialize the Trie root
        int totalValidSubstrings = 0;

        // Iterate through all starting indices of substrings
        for (int start = 0; start < s.length(); start++) {
            TrieNode currentNode = root;
            int[] digitFrequency = new int[10];
            int uniqueDigitsCount = 0;
            int maxDigitFrequency = 0;

            // Extend the substring from 'start' to different end positions
            for (int end = start; end < s.length(); end++) {
                int currentDigit = s.charAt(end) - '0';

                // Update digit frequency and unique digits count
                if (digitFrequency[currentDigit]++ == 0) {
                    uniqueDigitsCount++;
                }
                maxDigitFrequency = Math.max(
                    maxDigitFrequency,
                    digitFrequency[currentDigit]
                );

                // Traverse or create a new node in the Trie
                if (currentNode.children[currentDigit] == null) {
                    currentNode.children[currentDigit] = new TrieNode(); // Add new node for the digit
                }
                currentNode = currentNode.children[currentDigit]; // Move to the child node

                // Check if the substring is valid
                if (
                    uniqueDigitsCount * maxDigitFrequency == end - start + 1 &&
                    !currentNode.isVisited
                ) {
                    totalValidSubstrings++; // Increment count of valid substrings
                    currentNode.isVisited = true; // Mark this substring as seen
                }
            }
        }
        return totalValidSubstrings;
    }

    class TrieNode {

        TrieNode[] children = new TrieNode[10]; // For digits 0-9
        boolean isVisited; // Checks if this substring has been counted
    }
}
