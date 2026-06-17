typedef struct {
    int* data;
    int top;
    int max;
} pairStack;
pairStack* createStack(int max) {
    pairStack* stack = calloc(1, sizeof(pairStack));
    stack->data = calloc(max, sizeof(int));
    stack->max = max;
    return stack;
}
void pushStack(pairStack* s, int a) {
    if (s->top >= s->max) return;
    s->data[s->top++] = a;
}
int popStack(pairStack* s) {
    if (s->top <= 0) return -1;
    return s->data[--s->top];
}
void dfs(char** board, int ROWS, int COLS, int row, int col) {
    if (board[row][col] != 'O') return;
    pairStack* stack = createStack(ROWS * COLS * 2);
    pushStack(stack, row);
    pushStack(stack, col);
    while (stack->top != 0) {
        col = popStack(stack);
        row = popStack(stack);
        if (board[row][col] == 'O') {
            board[row][col] = 'E';
            if (col + 1 < COLS) {
                pushStack(stack, row);
                pushStack(stack, col + 1);
            }
            if (row + 1 < ROWS) {
                pushStack(stack, row + 1);
                pushStack(stack, col);
            }
            if (col > 0) {
                pushStack(stack, row);
                pushStack(stack, col - 1);
            }
            if (row > 0) {
                pushStack(stack, row - 1);
                pushStack(stack, col);
            }
        }
    }
}
void solve(char** board, int boardSize, int* boardColSize) {
    if (boardSize == 0 || *boardColSize == 0) return;
    int ROWS = boardSize, COLS = *boardColSize;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || j == 0 || i == ROWS - 1 || j == COLS - 1)
                dfs(board, ROWS, COLS, i, j);
        }
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == 'E')
                board[i][j] = 'O';
}
