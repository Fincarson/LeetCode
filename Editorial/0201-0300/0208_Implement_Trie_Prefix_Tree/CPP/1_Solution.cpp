class TrieNode {
private:
    // R links to node children
    TrieNode* links[26];
    bool isEnd;

public:
    TrieNode() {
        // Initialize all links to null
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
        isEnd = false;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        isEnd = true;
    }

    bool isEndOfWord() {
        return isEnd;
    }
};
