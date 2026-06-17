int minSwaps(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int* pos = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        pos[i] = -1;
        for (int j = n - 1; j >= 0; --j) {
            if (grid[i][j] == 1) {
                pos[i] = j;
                break;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int k = -1;
        for (int j = i; j < n; ++j) {
            if (pos[j] <= i) {
                ans += j - i;
                k = j;
                break;
            }
        }

        if (k != -1) {
            for (int j = k; j > i; --j) {
                int temp = pos[j];
                pos[j] = pos[j - 1];
                pos[j - 1] = temp;
            }
        } else {
            free(pos);
            return -1;
        }
    }

    free(pos);
    return ans;
}
