int* grayCode(int n, int* returnSize) {
    int resultSize = 1;
    for (int i = 0; i < n; i++) {
        resultSize *= 2;
    }
    *returnSize = resultSize;
    int* result = (int*)malloc(sizeof(int) * resultSize);
    result[0] = 0;
    int length = 1;
    for (int i = 1; i <= n; i++) {
        int mask = 1 << (i - 1);
        for (int j = length - 1; j >= 0; j--) {
            result[length++] = mask + result[j];
        }
    }
    return result;
}
