bool wordBreak(char *s, char **wordDict, int wordDictSize) {
    int s_length = strlen(s);
    int *q = (int *)malloc(sizeof(int) * (s_length + 1));
    int q_front = 0;
    int q_back = 0;
    bool *at = (bool *)calloc(s_length + 1, sizeof(bool));
    q[q_back++] = 0;
    while (q_front != q_back) {
        int start = q[q_front++];
        if (start == s_length) {
            free(q);
            free(at);
            return true;
        }
        for (int end = start + 1; end <= s_length; end++) {
            if (at[end]) {
                continue;
            }
            int len = end - start;
            char *substr = (char *)malloc(sizeof(char) * (len + 1));
            strncpy(substr, s + start, len);
            substr[len] = '\0';
            for (int i = 0; i < wordDictSize; i++) {
                if (strcmp(substr, wordDict[i]) == 0) {
                    q[q_back++] = end;
                    at[end] = true;
                    break;
                }
            }
            free(substr);
        }
    }
    free(q);
    free(at);
    return false;
}
