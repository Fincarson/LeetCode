int getRect(int** P, int x1, int y1, int x2, int y2) {
    return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
}

int maxSideLength(int** mat, int matSize, int* matColSize, int threshold) {
    int m = matSize, n = matColSize[0];
    int** P = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        P[i] = (int*)calloc(n + 1, sizeof(int));
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            P[i][j] =
                P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
        }
    }

    int r = (m < n ? m : n);
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int c = ans + 1; c <= r; c++) {
                if (i + c - 1 <= m && j + c - 1 <= n &&
                    getRect(P, i, j, i + c - 1, j + c - 1) <= threshold) {
                    ans = c;
                } else {
                    break;
                }
            }
        }
    }

    for (int i = 0; i <= m; i++) {
        free(P[i]);
    }
    free(P);
    return ans;
}
