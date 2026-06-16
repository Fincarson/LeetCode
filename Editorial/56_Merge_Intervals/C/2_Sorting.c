int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
int compareC(const void* a, const void* b) {
    int* ia = *(int**)a;
    int* ib = *(int**)b;
    return ia[0] == ib[0] ? ib[1] - ia[1] : ia[0] - ib[0];
}
int** merge(int** intervals, int intervalsSize, const int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {
    int n = intervalsSize;
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    qsort(intervals, n, sizeof(int*), compareC);
    int** merged = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; ++i) merged[i] = malloc(sizeof(int) * 2);
    memcpy(merged[0], intervals[0], 2 * sizeof(int));
    int t = 0;  // pointers to merged
    for (int i = 1; i < n; ++i) {
        int l = intervals[i][0], r = intervals[i][1];
        if (l <= merged[t][1]) {
            merged[t][1] = max(merged[t][1], r);
        } else {
            memcpy(merged[++t], intervals[i], 2 * sizeof(int));
        }
    }
    ++t;
    *returnSize = t;
    *returnColumnSizes = malloc(sizeof(int) * t);
    for (int i = 0; i < t; ++i) {
        (*returnColumnSizes)[i] = 2;
    }
    return merged;
}
