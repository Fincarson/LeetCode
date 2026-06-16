typedef struct {
    int x, y;
} Direction;
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize,
                 int* returnSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }
    const int VISITED = 101;
    int rows = matrixSize, columns = matrixColSize[0];
    Direction directions[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int currentDirection = 0;
    int row = 0, col = 0;
    *returnSize = rows * columns;
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    result[0] = matrix[0][0];
    matrix[0][0] = VISITED;
    for (int i = 1; i < *returnSize;) {
        while (row + directions[currentDirection].x >= 0 &&
               row + directions[currentDirection].x < rows &&
               col + directions[currentDirection].y >= 0 &&
               col + directions[currentDirection].y < columns &&
               matrix[row + directions[currentDirection].x]
                     [col + directions[currentDirection].y] != VISITED) {
            row = row + directions[currentDirection].x;
            col = col + directions[currentDirection].y;
            result[i++] = matrix[row][col];
            matrix[row][col] = VISITED;
        }
        currentDirection = (currentDirection + 1) % 4;
    }
    return result;
}
