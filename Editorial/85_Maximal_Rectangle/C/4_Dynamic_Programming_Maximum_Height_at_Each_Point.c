#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0) return 0;
    int m = matrixSize;
    int n = matrixColSize[0];
    int left[n];
    int right[n];
    int height[n];
    memset(height, 0, sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        left[i] = 0;
        right[i] = n;
    }
    int maxarea = 0;
    for (int i = 0; i < m; i++) {
        int cur_left = 0, cur_right = n;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1')
                height[j]++;
            else
                height[j] = 0;
        }
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1')
                left[j] = max(left[j], cur_left);
            else {
                left[j] = 0;
                cur_left = j + 1;
            }
        }
        for (int j = n - 1; j >= 0; j--) {
            if (matrix[i][j] == '1')
                right[j] = min(right[j], cur_right);
            else {
                right[j] = n;
                cur_right = j;
            }
        }
        for (int j = 0; j < n; j++)
            maxarea = max(maxarea, (right[j] - left[j]) * height[j]);
    }
    return maxarea;
}
