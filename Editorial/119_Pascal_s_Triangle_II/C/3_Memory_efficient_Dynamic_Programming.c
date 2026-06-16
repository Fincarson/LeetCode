int* getRow(int rowIndex, int* returnSize) {
    // set return size
    *returnSize = rowIndex + 1;
    // initialize row with all elements as 1
    int* row = (int*)calloc(*returnSize, sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        row[i] = 1;
    }
    // populate each row element
    for (int i = 1; i < rowIndex; i++) {
        for (int j = i; j > 0; j--) {
            // current element is sum of current and previous element in above
            // row
            row[j] += row[j - 1];
        }
    }
    return row;
}
