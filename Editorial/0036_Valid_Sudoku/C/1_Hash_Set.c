#define N 9
bool inHashTable(int* hashTable, int val) {
    if (hashTable[val - 1] == 1) {
        return true;
    }
    return false;
}
void insertHashTable(int* hashTable, int val) { hashTable[val - 1]++; }
bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int *rows[N], *cols[N], *boxes[N];
    // Initialize hash tables
    for (int i = 0; i < N; i++) {
        rows[i] = (int*)calloc(9, sizeof(int));
        cols[i] = (int*)calloc(9, sizeof(int));
        boxes[i] = (int*)calloc(9, sizeof(int));
    }
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (board[r][c] == '.') {
                continue;
            }
            int val = board[r][c] - '0';
            // Check the row
            if (inHashTable(rows[r], val)) {
                return false;
            }
            insertHashTable(rows[r], val);
            // Check the column
            if (inHashTable(cols[c], val)) {
                return false;
            }
            insertHashTable(cols[c], val);
            // Check the box
            int idx = (r / 3) * 3 + c / 3;
            if (inHashTable(boxes[idx], val)) {
                return false;
            }
            insertHashTable(boxes[idx], val);
        }
    }
    return true;
}
