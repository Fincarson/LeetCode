class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    vector<int> currentWordPosition;

    TrieNode() {}
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void addToTrie(const string& word, int currentWordPosition) {
        TrieNode* node = root;
        for (char c : word) {
            // If the current character is not in the children, create a new
            // node
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            // Store the position of the current word in the node
            node->currentWordPosition.push_back(currentWordPosition);
        }
    }

    vector<int> checkPrefix(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            // If the character is not found, the prefix does not exist
            if (node->children.find(c) == node->children.end()) {
                return {};
            }
            node = node->children[c];
        }
        // Return the list of word positions where the prefix matches
        return node->currentWordPosition;
    }
};

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        Trie trie;
        istringstream iss(sentence);
        string word;
        int currentWordPosition = 1;

        // Split the sentence into words and add each word to the Trie
        while (iss >> word) {
            trie.addToTrie(word, currentWordPosition);
            currentWordPosition++;
        }

        // Check if the searchWord is a prefix of any word in the Trie
        vector<int> currentWordPositions = trie.checkPrefix(searchWord);

        // Return the smallest word position where the prefix matches, or -1 if
        // not found
        return currentWordPositions.empty()
                   ? -1
                   : *min_element(currentWordPositions.begin(),
                                  currentWordPositions.end());
    }
};
