int min(int a, int b) { return a < b ? a : b; }
int minDistance(char* word1, char* word2) {
    int word1_len = strlen(word1);
    int word2_len = strlen(word2);
    int** memo = (int**)malloc((word1_len + 1) * sizeof(int*));
    for (int i = 0; i <= word1_len; i++) {
        memo[i] = (int*)malloc((word2_len + 1) * sizeof(int));
        for (int j = 0; j <= word2_len; j++) {
            memo[i][j] = -1;
        }
    }
    int minDistanceRecur(char* word1, char* word2, int word1Index,
                         int word2Index) {
        if (word1Index == 0) {
            return word2Index;
        }
        if (word2Index == 0) {
            return word1Index;
        }
        if (memo[word1Index][word2Index] != -1) {
            return memo[word1Index][word2Index];
        }
        int minEditDistance = 0;
        if (word1[word1Index - 1] == word2[word2Index - 1]) {
            minEditDistance =
                minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
        } else {
            int insertOperation =
                minDistanceRecur(word1, word2, word1Index, word2Index - 1);
            int deleteOperation =
                minDistanceRecur(word1, word2, word1Index - 1, word2Index);
            int replaceOperation =
                minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
            minEditDistance =
                min(insertOperation, min(deleteOperation, replaceOperation)) +
                1;
        }
        memo[word1Index][word2Index] = minEditDistance;
        return minEditDistance;
    }
    return minDistanceRecur(word1, word2, word1_len, word2_len);
}
