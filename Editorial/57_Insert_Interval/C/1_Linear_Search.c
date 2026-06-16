int** insert(int** intervals, int intervalsSize, int* intervalsColSize,
             int* newInterval, int newIntervalSize, int* returnSize,
             int** returnColumnSizes) {
    *returnSize = 0;
    int i = 0, j = 0;
    int** res = malloc((intervalsSize + 1) * sizeof(int*));
    *returnColumnSizes = malloc((intervalsSize + 1) * sizeof(int));

    // Case 1: No overlapping before merging intervals
    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        res[j] = intervals[i++];
        (*returnColumnSizes)[j++] = 2;
    }

    // Case 2: Overlapping and merging intervals
    while (i < intervalsSize && newInterval[1] >= intervals[i][0]) {
        newInterval[0] = fmin(newInterval[0], intervals[i][0]);
        newInterval[1] = fmax(newInterval[1], intervals[i][1]);
        i++;
    }
    res[j] = newInterval;
    (*returnColumnSizes)[j++] = 2;

    // Case 3: No overlapping after merging newInterval
    while (i < intervalsSize) {
        res[j] = intervals[i++];
        (*returnColumnSizes)[j++] = 2;
    }
    *returnSize = j;

    return res;
}
