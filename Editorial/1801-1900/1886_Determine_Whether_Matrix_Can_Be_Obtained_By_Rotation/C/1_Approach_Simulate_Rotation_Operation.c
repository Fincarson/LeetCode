bool isEqual(int** mat, int** target, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != target[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool findRotation(int** mat, int matSize, int* matColSize, int** target,
                  int targetSize, int* targetColSize) {
    int n = matSize;

    // at most 4 rotations
    for (int k = 0; k < 4; k++) {
        // rotation operation
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < (n + 1) / 2; j++) {
                int temp = mat[i][j];
                mat[i][j] = mat[n - 1 - j][i];
                mat[n - 1 - j][i] = mat[n - 1 - i][n - 1 - j];
                mat[n - 1 - i][n - 1 - j] = mat[j][n - 1 - i];
                mat[j][n - 1 - i] = temp;
            }
        }

        if (isEqual(mat, target, n)) {
            return true;
        }
    }
    return false;
}
