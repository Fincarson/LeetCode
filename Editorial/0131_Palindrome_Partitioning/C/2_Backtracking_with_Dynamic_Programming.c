#define MAX 1000
char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int len = strlen(s);
    bool dp[MAX][MAX] = {false};
    char*** result = (char***)calloc(MAX * MAX, sizeof(char**));
    char** currentList = (char**)calloc(MAX, sizeof(char*));
    *returnSize = 0;
    *returnColumnSizes = (int*)calloc(MAX * MAX, sizeof(int));
    dfs(s, 0, &result, returnSize, returnColumnSizes, &currentList, 0, dp);
    free(currentList);
    return result;
}
void dfs(char* s, int start, char**** result, int* returnSize,
         int** returnColumnSizes, char*** currentList, int currentListSize,
         bool dp[][MAX]) {
    int len = strlen(s);
    if (start >= len) {
        (*result)[*returnSize] =
            (char**)malloc(currentListSize * sizeof(char*));
        memcpy((*result)[*returnSize], *currentList,
               currentListSize * sizeof(char*));
        (*returnColumnSizes)[*returnSize] = currentListSize;
        (*returnSize)++;
    }
    for (int end = start; end < len; end++) {
        if (s[start] == s[end] &&
            (end - start <= 2 || dp[start + 1][end - 1])) {
            dp[start][end] = true;
            char* substr = (char*)calloc((end - start + 2), sizeof(char));
            strncpy(substr, &s[start], end - start + 1);
            (*currentList)[currentListSize] = substr;
            dfs(s, end + 1, result, returnSize, returnColumnSizes, currentList,
                currentListSize + 1, dp);
            (*currentList)[currentListSize] = NULL;
        }
    }
}
