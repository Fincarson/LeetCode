class TrieNode {
    Map<Character, TrieNode> children = new HashMap();
    boolean word = false;

    public TrieNode() {}
}

class WordDictionary {
    TrieNode trie;

    /** Initialize your data structure here. */
    public WordDictionary() {
        trie = new TrieNode();
    }

    /** Adds a word into the data structure. */
    public void addWord(String word) {
        TrieNode node = trie;

        for (char ch : word.toCharArray()) {
            if (!node.children.containsKey(ch)) {
                node.children.put(ch, new TrieNode());
            }
            node = node.children.get(ch);
        }
        node.word = true;
    }
}
