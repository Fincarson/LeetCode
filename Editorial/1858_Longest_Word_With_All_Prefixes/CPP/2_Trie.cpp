class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        string longestValidWord = "";

        // Insert all words into the trie
        for (string& word : words) {
            trie.insert(word);
        }

        // Check each word and update the longest valid word
        for (string& word : words) {
            if (trie.hasAllPrefixes(word)) {
                if (word.length() > longestValidWord.length() ||
                    (word.length() == longestValidWord.length() &&
                     word < longestValidWord)) {
                    longestValidWord = word;
                }
            }
        }

        return longestValidWord;
    }

private:
    class Trie {
    private:
        struct TrieNode {
            TrieNode* children[26] = {nullptr};
            bool isEndOfWord = false;
        };

        TrieNode* root;

    public:
        Trie() : root(new TrieNode()) {}

        // Insert a word into the trie
        void insert(string& word) {
            TrieNode* node = root;
            for (char c : word) {
                int index = c - 'a';
                if (node->children[index] == nullptr) {
                    node->children[index] = new TrieNode();
                }
                node = node->children[index];
            }
            node->isEndOfWord = true;
        }

        // Check if all prefixes of the word exist in the trie
        bool hasAllPrefixes(string& word) {
            TrieNode* node = root;
            for (char c : word) {
                node = node->children[c - 'a'];
                if (node == nullptr || !node->isEndOfWord) {
                    return false;
                }
            }
            return true;
        }

        // Destructor to free allocated memory
        ~Trie() { deleteTrie(root); }

    private:
        void deleteTrie(TrieNode* node) {
            if (node == nullptr) return;
            for (int i = 0; i < 26; i++) {
                deleteTrie(node->children[i]);
            }
            delete node;
        }
    };
};
