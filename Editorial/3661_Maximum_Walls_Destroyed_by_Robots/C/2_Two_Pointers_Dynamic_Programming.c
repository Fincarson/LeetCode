int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int maxInt(int a, int b) { return a > b ? a : b; }

int minInt(int a, int b) { return a < b ? a : b; }

int maxWalls(int* robots, int robotsSize, int* distance, int distanceSize,
             int* walls, int wallsSize) {
    int n = robotsSize;
    int* left = (int*)calloc(n, sizeof(int));
    int* right = (int*)calloc(n, sizeof(int));
    int* num = (int*)calloc(n, sizeof(int));

    int* robotsCopy = (int*)malloc(n * sizeof(int));
    memcpy(robotsCopy, robots, n * sizeof(int));

    int* robotsToDistance = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        int robotPos = robotsCopy[i];
        for (int j = 0; j < n; j++) {
            if (robots[j] == robotPos) {
                robotsToDistance[i] = distance[j];
                break;
            }
        }
    }

    qsort(robotsCopy, n, sizeof(int), compare);
    qsort(walls, wallsSize, sizeof(int), compare);

    int m = wallsSize;
    int rightPtr = 0, leftPtr = 0, curPtr = 0, robotPtr = 0;

    for (int i = 0; i < n; i++) {
        while (rightPtr < m && walls[rightPtr] <= robotsCopy[i]) {
            rightPtr++;
        }
        int pos1 = rightPtr;

        while (curPtr < m && walls[curPtr] < robotsCopy[i]) {
            curPtr++;
        }
        int pos2 = curPtr;

        int leftBound = robotsCopy[i] - robotsToDistance[i];
        if (i >= 1) {
            leftBound = maxInt(robotsCopy[i] - robotsToDistance[i],
                               robotsCopy[i - 1] + 1);
        }
        while (leftPtr < m && walls[leftPtr] < leftBound) {
            leftPtr++;
        }
        int leftPos = leftPtr;
        left[i] = pos1 - leftPos;

        int rightBound = robotsCopy[i] + robotsToDistance[i];
        if (i < n - 1) {
            rightBound = minInt(robotsCopy[i] + robotsToDistance[i],
                                robotsCopy[i + 1] - 1);
        }
        while (rightPtr < m && walls[rightPtr] <= rightBound) {
            rightPtr++;
        }
        int rightPos = rightPtr;
        right[i] = rightPos - pos2;

        if (i == 0) {
            continue;
        }
        while (robotPtr < m && walls[robotPtr] < robotsCopy[i - 1]) {
            robotPtr++;
        }
        int pos3 = robotPtr;
        num[i] = pos1 - pos3;
    }

    int subLeft = left[0], subRight = right[0];
    for (int i = 1; i < n; i++) {
        int currentLeft = maxInt(
            subLeft + left[i],
            subRight - right[i - 1] + minInt(left[i] + right[i - 1], num[i]));
        int currentRight = maxInt(subLeft + right[i], subRight + right[i]);
        subLeft = currentLeft;
        subRight = currentRight;
    }

    int result = maxInt(subLeft, subRight);

    free(left);
    free(right);
    free(num);
    free(robotsCopy);
    free(robotsToDistance);

    return result;
}
