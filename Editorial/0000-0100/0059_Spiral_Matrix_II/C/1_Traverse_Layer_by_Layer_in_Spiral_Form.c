int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(n * sizeof(int*));
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    int cnt = 1;
    for (int layer = 0; layer < (n + 1) / 2; layer++) {
        // direction 1 - traverse from left to right
        for (int ptr = layer; ptr < n - layer; ptr++) {
            result[layer][ptr] = cnt++;
        }
        // direction 2 - traverse from top to bottom
        for (int ptr = layer + 1; ptr < n - layer; ptr++) {
            result[ptr][n - layer - 1] = cnt++;
        }
        // direction 3 - traverse from right to left
        for (int ptr = n - layer - 2; ptr >= layer; ptr--) {
            result[n - layer - 1][ptr] = cnt++;
        }
        // direction 4 - traverse from bottom to top
        for (int ptr = n - layer - 2; ptr > layer; ptr--) {
            result[ptr][layer] = cnt++;
        }
    }
    return result;
}
