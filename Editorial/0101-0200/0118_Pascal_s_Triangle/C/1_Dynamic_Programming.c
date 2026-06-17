// The C language requires a convoluted way to
// allocate a multi-dimensional array on the heap.
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);
    int** triangle = (int**)malloc(sizeof(int*) * numRows);
    if (numRows == 0) {
        return NULL;
    }
    // Base case; first row is always [1].
    (*returnColumnSizes)[0] = 1;
    triangle[0] = (int*)malloc(sizeof(int) * 1);
    triangle[0][0] = 1;
    for (int rowNum = 1; rowNum < numRows; rowNum++) {
        int* row = (int*)malloc(sizeof(int) * (rowNum + 1));
        int* prevRow = triangle[rowNum - 1];
        row[0] = 1;
        // Each triangle element (other than the first and last of each row)
        // is equal to the sum of the elements above-and-to-the-left and
        // above-and-to-the-right.
        for (int j = 1; j < rowNum; j++) {
            row[j] = prevRow[j - 1] + prevRow[j];
        }
        row[rowNum] = 1;
        triangle[rowNum] = row;
        (*returnColumnSizes)[rowNum] = rowNum + 1;
    }
    return triangle;
}
