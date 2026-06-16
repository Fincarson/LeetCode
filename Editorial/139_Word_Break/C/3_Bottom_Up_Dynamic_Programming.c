bool wordBreak(char *s, char **wordDict, int wordDictSize) {
    int len = strlen(s);
    int *dp = (int *)malloc(sizeof(int) * len);
    memset(dp, 0, sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < wordDictSize; j++) {
            int word_len = strlen(wordDict[j]);
            // Handle out of bounds case
            if (i < word_len - 1) {
                continue;
            }
            if (i == word_len - 1 || dp[i - word_len]) {
                if (strncmp(s + i - word_len + 1, wordDict[j], word_len) == 0) {
                    dp[i] = 1;
                    break;
                }
            }
        }
    }
    bool result = dp[len - 1];
    free(dp);
    return result;
}
