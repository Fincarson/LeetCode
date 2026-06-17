typedef struct TrieNode {
    struct TrieNode* child[26];
    bool isEnd;
} TrieNode;

TrieNode* newNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    memset(node->child, 0, sizeof(node->child));
    node->isEnd = false;
    return node;
}

void insert(TrieNode* root, char* word) {
    TrieNode* node = root;
    for (int i = 0; word[i]; i++) {
        int idx = word[i] - 'a';
        if (!node->child[idx]) node->child[idx] = newNode();
        node = node->child[idx];
    }
    node->isEnd = true;
}

bool dfs(char* word, int i, TrieNode* node, int cnt) {
    if (cnt > 2 || !node) return false;

    if (word[i] == '\0') return node->isEnd;

    int idx = word[i] - 'a';

    // no changes made
    if (node->child[idx] && dfs(word, i + 1, node->child[idx], cnt))
        return true;

    // made changes
    if (cnt < 2) {
        for (int c = 0; c < 26; c++) {
            if (c == idx) continue;
            if (node->child[c] && dfs(word, i + 1, node->child[c], cnt + 1))
                return true;
        }
    }

    return false;
}

char** twoEditWords(char** queries, int queriesSize, char** dictionary,
                    int dictionarySize, int* returnSize) {
    TrieNode* root = newNode();
    for (int i = 0; i < dictionarySize; i++) insert(root, dictionary[i]);

    char** res = (char**)malloc(sizeof(char*) * queriesSize);
    int cnt = 0;

    for (int i = 0; i < queriesSize; i++) {
        if (dfs(queries[i], 0, root, 0)) {
            res[cnt++] = queries[i];
        }
    }

    *returnSize = cnt;
    return res;
}
