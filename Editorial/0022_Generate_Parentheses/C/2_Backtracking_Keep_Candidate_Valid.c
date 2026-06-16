void backtracking(char* cur_string, int left_count, int right_count, int n,
                  char** answer, int* returnSize) {
    if (strlen(cur_string) == 2 * n) {
        answer[*returnSize] = (char*)malloc(strlen(cur_string) + 1);
        strcpy(answer[*returnSize], cur_string);
        (*returnSize)++;
        return;
    }
    if (left_count < n) {
        strcat(cur_string, "(");
        backtracking(cur_string, left_count + 1, right_count, n, answer,
                     returnSize);
        cur_string[strlen(cur_string) - 1] = '\0';
    }
    if (right_count < left_count) {
        strcat(cur_string, ")");
        backtracking(cur_string, left_count, right_count + 1, n, answer,
                     returnSize);
        cur_string[strlen(cur_string) - 1] = '\0';
    }
}
char** generateParenthesis(int n, int* returnSize) {
    char** answer = (char**)malloc(16384 * sizeof(char*));
    char* cur_string = (char*)malloc((2 * n + 1) * sizeof(char));
    cur_string[0] = '\0';
    *returnSize = 0;
    backtracking(cur_string, 0, 0, n, answer, returnSize);
    free(cur_string);
    return answer;
}
