#define MAX_LENGTH 1000
#define MAX_SIZE_DICT 1000
struct hash {
    char key[MAX_LENGTH + 1];
    UT_hash_handle hh;
};
bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    struct hash* wordsHash = NULL;
    for (int i = 0; i < wordDictSize; i++) {
        struct hash* wordHash = malloc(sizeof(struct hash));
        strcpy(wordHash->key, wordDict[i]);
        HASH_ADD_STR(wordsHash, key, wordHash);
    }
    bool dp[MAX_LENGTH + 1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    int slen = strlen(s);
    for (int i = 1; i <= slen; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j]) {
                struct hash* wordHash;
                char subWord[MAX_LENGTH + 1];
                strncpy(subWord, &s[j], i - j);
                subWord[i - j] = '\0';  // null terminate
                HASH_FIND_STR(wordsHash, subWord, wordHash);
                if (wordHash) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[slen];
}
