int min(int a, int b) { return a < b ? a : b; }
int minDistanceRecur(char *word1, char *word2, int word1Index, int word2Index) {
    if (word1Index == 0) {
        return word2Index;
    }
    if (word2Index == 0) {
        return word1Index;
    }
    if (word1[word1Index - 1] == word2[word2Index - 1]) {
        return minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
    } else {
        int insertOperation =
            minDistanceRecur(word1, word2, word1Index, word2Index - 1);
        int deleteOperation =
            minDistanceRecur(word1, word2, word1Index - 1, word2Index);
        int replaceOperation =
            minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
        return min(insertOperation, min(deleteOperation, replaceOperation)) + 1;
    }
}
int minDistance(char *word1, char *word2) {
    return minDistanceRecur(word1, word2, strlen(word1), strlen(word2));
}
