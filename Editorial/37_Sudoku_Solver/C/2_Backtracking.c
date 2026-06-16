#define N 9
#define n 3

int **rows;
int **columns;
int **boxes;
char **board;
bool sudoku_solved;

bool could_place(int d, int row, int col) {
    int idx = (row / n) * n + col / n;
    return rows[row][d] + columns[col][d] + boxes[idx][d] == 0;
}

void place_number(int d, int row, int col) {
    int idx = (row / n) * n + col / n;
    rows[row][d]++;
    columns[col][d]++;
    boxes[idx][d]++;
    board[row][col] = (char)(d + '0');
}

void remove_number(int d, int row, int col) {
    int idx = (row / n) * n + col / n;
    rows[row][d]--;
    columns[col][d]--;
    boxes[idx][d]--;
    board[row][col] = '.';
}

void backtrack(int row, int col);

void place_next_numbers(int row, int col) {
    if ((col == N - 1) && (row == N - 1)) {
        sudoku_solved = true;
    } else {
        if (col == N - 1)
            backtrack(row + 1, 0);
        else
            backtrack(row, col + 1);
    }
}

void backtrack(int row, int col) {
    if (board[row][col] == '.') {
        for (int d = 1; d <= 9; d++) {
            if (could_place(d, row, col)) {
                place_number(d, row, col);
                place_next_numbers(row, col);
                if (!sudoku_solved) remove_number(d, row, col);
            }
        }
    } else {
        place_next_numbers(row, col);
    }
}

void solveSudoku(char **boardInput, int boardSize, int *boardColSize) {
    board = boardInput;
    rows = malloc(N * sizeof(int *));
    columns = malloc(N * sizeof(int *));
    boxes = malloc(N * sizeof(int *));
    sudoku_solved = false;

    for (int i = 0; i < N; i++) {
        rows[i] = calloc(10, sizeof(int));
        columns[i] = calloc(10, sizeof(int));
        boxes[i] = calloc(10, sizeof(int));
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char num = board[i][j];
            if (num != '.') {
                int d = num - '0';
                place_number(d, i, j);
            }
        }
    }
    backtrack(0, 0);

    for (int i = 0; i < N; i++) {
        free(rows[i]);
        free(columns[i]);
        free(boxes[i]);
    }
    free(rows);
    free(columns);
    free(boxes);
}
