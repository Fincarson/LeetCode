class TrieNode {

    boolean isEnd;
    TrieNode[] children;

    TrieNode() {
        isEnd = false;
        children = new TrieNode[26];
    }
}

class Trie {

    TrieNode root;

    Trie() {
        root = new TrieNode();
    }

    void insert(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            int index = c - 'a';
            if (node.children[index] == null) {
                node.children[index] = new TrieNode();
            }
            node = node.children[index];
        }
        node.isEnd = true;
    }
}

class Solution {

    public List<String> wordBreak(String s, List<String> wordDict) {
        // Build the Trie from the word dictionary
        Trie trie = new Trie();
        for (String word : wordDict) {
            trie.insert(word);
        }

        // Map to store results of subproblems
        Map<Integer, List<String>> dp = new HashMap<>();

        // Iterate from the end of the string to the beginning
        for (int startIdx = s.length(); startIdx >= 0; startIdx--) {
            // List to store valid sentences starting from startIdx
            List<String> validSentences = new ArrayList<>();

            // Initialize current node to the root of the trie
            TrieNode currentNode = trie.root;

            // Iterate from startIdx to the end of the string
            for (int endIdx = startIdx; endIdx < s.length(); endIdx++) {
                char c = s.charAt(endIdx);
                int index = c - 'a';

                // Check if the current character exists in the trie
                if (currentNode.children[index] == null) {
                    break;
                }

                // Move to the next node in the trie
                currentNode = currentNode.children[index];

                // Check if we have found a valid word
                if (currentNode.isEnd) {
                    String currentWord = s.substring(startIdx, endIdx + 1);

                    // If it's the last word, add it as a valid sentence
                    if (endIdx == s.length() - 1) {
                        validSentences.add(currentWord);
                    } else {
                        // If it's not the last word, append it to each sentence formed by the remaining substring
                        List<String> sentencesFromNextIndex = dp.get(
                            endIdx + 1
                        );
                        for (String sentence : sentencesFromNextIndex) {
                            validSentences.add(currentWord + " " + sentence);
                        }
                    }
                }
            }

            // Store the valid sentences in dp
            dp.put(startIdx, validSentences);
        }

        // Return the sentences formed from the entire string
        return dp.getOrDefault(0, new ArrayList<>());
    }
}
