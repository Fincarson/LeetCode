struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool word = false;
};

class WordDictionary {
    TrieNode* trie;

public:
    /** Initialize your data structure here. */
    WordDictionary() { trie = new TrieNode(); }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = trie;

        for (char ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->word = true;
    }
};
