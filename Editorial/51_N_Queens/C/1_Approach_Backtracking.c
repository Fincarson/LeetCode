int* diagonal;
int* antiDiagonal;
int* cols;
char*** result;
char** board;
int size;
void backtrack(int n, int row) {
    if (row == n) {
        char** current = (char**)malloc(n * sizeof(char*));
        for (int i = 0; i < n; ++i) {
            char* currRow = (char*)calloc(n + 1, sizeof(char));
            memcpy(currRow, board[i], n);
            currRow[n] = '\0';
            current[i] = currRow;
        }
        result[size++] = current;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (cols[i] || diagonal[i - row + n - 1] || antiDiagonal[i + row])
            continue;
        cols[i] = diagonal[i - row + n - 1] = antiDiagonal[i + row] = 1;
        board[row][i] = 'Q';
        backtrack(n, row + 1);
        board[row][i] = '.';
        cols[i] = diagonal[i - row + n - 1] = antiDiagonal[i + row] = 0;
    }
}
char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    size = 0;
    if (n < 1) {
        *returnSize = 0;
        return 0;
    }
    result = (char***)malloc(n * n * n * sizeof(char**));
    diagonal = (int*)calloc(2 * n - 1, sizeof(int));
    antiDiagonal = (int*)calloc(2 * n - 1, sizeof(int));
    cols = (int*)calloc(n, sizeof(int));
    board = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; ++i) {
        board[i] = (char*)calloc(n + 1, sizeof(char));
        memset(board[i], '.', n);
    }
    backtrack(n, 0);
    *returnSize = size;
    *returnColumnSizes = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        (*returnColumnSizes)[i] = n;
    }
    return result;
}
