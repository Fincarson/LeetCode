char** twoEditWords(char** queries, int queriesSize, char** dictionary,
                    int dictionarySize, int* returnSize) {
    char** ans = (char**)malloc(sizeof(char*) * queriesSize);
    int cnt = 0;

    for (int i = 0; i < queriesSize; i++) {
        char* query = queries[i];
        for (int j = 0; j < dictionarySize; j++) {
            char* s = dictionary[j];
            int dis = 0;
            for (int k = 0; query[k] != '\0'; k++) {
                if (query[k] != s[k]) {
                    dis++;
                }
            }
            if (dis <= 2) {
                ans[cnt++] = query;
                break;
            }
        }
    }

    *returnSize = cnt;
    return ans;
}
