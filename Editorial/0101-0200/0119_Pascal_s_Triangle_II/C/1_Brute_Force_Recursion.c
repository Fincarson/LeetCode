int getNum(int row, int col) {
    if (row == 0 || col == 0 || row == col) {
        return 1;
    }
    return getNum(row - 1, col - 1) + getNum(row - 1, col);
}
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* ans = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i <= rowIndex; i++) {
        ans[i] = getNum(rowIndex, i);
    }
    return ans;
}
