// In C,the logic of hashmap is implemented using uthash library which is
// included by default for hash set or hash map usage.
bool is_Interleave(char* s1, int i, char* s2, int j, char* s3, int k,
                   int** memo) {
    if (i == strlen(s1)) {
        return strcmp(s2 + j, s3 + k) == 0;
    }
    if (j == strlen(s2)) {
        return strcmp(s1 + i, s3 + k) == 0;
    }
    if (memo[i][j] >= 0) {
        return memo[i][j] == 1 ? true : false;
    }
    bool ans = false;
    if ((s3[k] == s1[i] && is_Interleave(s1, i + 1, s2, j, s3, k + 1, memo)) ||
        (s3[k] == s2[j] && is_Interleave(s1, i, s2, j + 1, s3, k + 1, memo))) {
        ans = true;
    }
    memo[i][j] = ans ? 1 : 0;
    return ans;
}
bool isInterleave(char* s1, char* s2, char* s3) {
    if (strlen(s1) + strlen(s2) != strlen(s3)) {
        return false;
    }
    int** memo = malloc(strlen(s1) * sizeof(int*));
    for (int i = 0; i < strlen(s1); i++) {
        memo[i] = malloc(strlen(s2) * sizeof(int));
        for (int j = 0; j < strlen(s2); j++) {
            memo[i][j] = -1;
        }
    }
    return is_Interleave(s1, 0, s2, 0, s3, 0, memo);
}
