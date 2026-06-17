class TrieNode {

    Map<Character, TrieNode> children;
    List<Integer> currentWordPosition;

    public TrieNode() {
        children = new HashMap<>();
        currentWordPosition = new ArrayList<>();
    }
}

class Trie {

    TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    public void addToTrie(String word, int currentWordPosition) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            // If the current character is not in the children, create a new node
            if (!node.children.containsKey(c)) {
                node.children.put(c, new TrieNode());
            }
            node = node.children.get(c);
            // Store the position of the current word in the node
            node.currentWordPosition.add(currentWordPosition);
        }
    }

    public List<Integer> checkPrefix(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            // If the character is not found, the prefix does not exist
            if (!node.children.containsKey(c)) {
                return new ArrayList<>();
            }
            node = node.children.get(c);
        }
        // Return the list of word positions where the prefix matches
        return node.currentWordPosition;
    }
}

class Solution {

    public int isPrefixOfWord(String sentence, String searchWord) {
        Trie trie = new Trie();
        String[] words = sentence.split(" ");
        // Split the sentence into words and add each word to the Trie
        for (
            int currentWordPosition = 1;
            currentWordPosition <= words.length;
            currentWordPosition++
        ) {
            trie.addToTrie(words[currentWordPosition - 1], currentWordPosition);
        }

        // Check if the searchWord is a prefix of any word in the Trie
        List<Integer> currentWordPositions = trie.checkPrefix(searchWord);
        // Return the smallest word position where the prefix matches, or -1 if not found
        return currentWordPositions.isEmpty()
            ? -1
            : Collections.min(currentWordPositions);
    }
}
