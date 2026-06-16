class Solution {
public:
    int k;

    struct TrieNode {
        TrieNode* children[26];
        bool isWord;
        TrieNode() {
            isWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    void addWord(TrieNode& root, const string& word) {
        TrieNode* cur = &root;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (cur->children[idx] == nullptr) {
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
        }
        cur->isWord = true;
    }

    void getWords(TrieNode& root, const string& prefix, vector<string>& res) {
        if (k == 0) {
            return;
        }    
        if (root.isWord) {
            k--;
            res.push_back(prefix);
        }
        for (int i = 0; i < 26; i++) {
            if (root.children[i] != nullptr) {
                getWords(*root.children[i], prefix + (char)('a' + i), res);
            }
        }
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = int(words.size());
        this->k = k;

        map<string, int> cnt;
        for (string& word : words) {
            cnt[word]++;
        }
        vector<string> res;
        vector<TrieNode> bucket(n + 1, TrieNode());
        for (auto& p : cnt) {
            addWord(bucket[p.second], p.first);
        }
        for (int i = n; i > 0; i--) {
            getWords(bucket[i], "", res);
        }
        return res;
    }
};
