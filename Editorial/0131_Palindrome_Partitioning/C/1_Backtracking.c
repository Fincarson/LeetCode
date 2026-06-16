typedef struct {
    char* str;
    int len;
} Token;

bool is_palindrome(char* start, int len) {
    for (int i = 0; i < len / 2; i++)
        if (start[i] != start[len - i - 1]) return false;
    return true;
}

void dfs(char* s, Token* path, int pathLen, char**** result, int* returnSize,
         int** columnSizes, int* capacity) {
    int len = strlen(s);
    if (len == 0) {
        if (*returnSize == *capacity) {
            *capacity *= 2;
            *result = realloc(*result, sizeof(char**) * (*capacity));
            *columnSizes = realloc(*columnSizes, sizeof(int) * (*capacity));
        }
        (*columnSizes)[*returnSize] = pathLen;
        (*result)[*returnSize] = malloc(sizeof(char*) * pathLen);
        for (int i = 0; i < pathLen; i++) {
            (*result)[*returnSize][i] =
                malloc(sizeof(char) * (path[i].len + 1));
            strncpy((*result)[*returnSize][i], path[i].str, path[i].len);
            (*result)[*returnSize][i][path[i].len] = '\0';
        }
        (*returnSize)++;
    } else {
        for (int i = 1; i <= len; i++) {
            if (is_palindrome(s, i)) {
                Token* newPath = malloc(sizeof(Token) * (pathLen + 1));
                if (pathLen > 0) memcpy(newPath, path, sizeof(Token) * pathLen);
                newPath[pathLen].str = s;
                newPath[pathLen].len = i;
                dfs(s + i, newPath, pathLen + 1, result, returnSize,
                    columnSizes, capacity);
                free(newPath);
            }
        }
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int capacity = 100;  // Initial capacity; increase if necessary
    char*** result = malloc(sizeof(char**) * capacity);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * capacity);
    dfs(s, NULL, 0, &result, returnSize, returnColumnSizes, &capacity);
    return result;
}
