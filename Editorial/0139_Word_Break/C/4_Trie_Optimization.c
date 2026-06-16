struct TrieNode {
    bool isWord;
    struct TrieNode* children[26];
};
struct TrieNode* createNode() {
    struct TrieNode* node = malloc(sizeof(struct TrieNode));
    node->isWord = false;
    for (int i = 0; i < 26; ++i) {
        node->children[i] = NULL;
    }
    return node;
}
bool wordBreak(char* s, char* wordDict[], int wordDictSize) {
    struct TrieNode* root = createNode();
    for (int i = 0; i < wordDictSize; ++i) {
        char* word = wordDict[i];
        struct TrieNode* curr = root;
        for (int j = 0; word[j] != '\0'; j++) {
            char c = word[j];
            if (curr->children[c - 'a'] == NULL) {
                curr->children[c - 'a'] = createNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isWord = true;
    }
    int strLength = strlen(s);
    bool dp[strLength];
    memset(dp, false, strLength);
    for (int i = 0; i < strLength; i++) {
        if (i == 0 || dp[i - 1]) {
            struct TrieNode* curr = root;
            for (int j = i; j < strLength; j++) {
                char c = s[j];
                if (curr->children[c - 'a'] == NULL) {
                    // No words exist
                    break;
                }
                curr = curr->children[c - 'a'];
                if (curr->isWord) {
                    dp[j] = true;
                }
            }
        }
    }
    return dp[strLength - 1];
}
