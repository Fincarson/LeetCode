int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int comparePair(const void* a, const void* b) {
    int* pairA = (int*)a;
    int* pairB = (int*)b;
    return pairA[0] - pairB[0];
}

int maxInt(int a, int b) { return a > b ? a : b; }

int minInt(int a, int b) { return a < b ? a : b; }

int maxWalls(int* robots, int robotsSize, int* distance, int distanceSize,
             int* walls, int wallsSize) {
    int n = robotsSize;

    int (*robotDist)[2] = malloc(n * sizeof(int[2]));
    for (int i = 0; i < n; i++) {
        robotDist[i][0] = robots[i];
        robotDist[i][1] = distance[i];
    }
    qsort(robotDist, n, sizeof(int[2]), comparePair);
    qsort(walls, wallsSize, sizeof(int), compare);

    int m = wallsSize;
    int rightPtr = 0;
    int leftPtr = 0;
    int curPtr = 0;
    int robotPtr = 0;

    int prevLeft = 0;
    int prevRight = 0;
    int prevNum = 0;
    int subLeft = 0;
    int subRight = 0;

    for (int i = 0; i < n; i++) {
        int robotPos = robotDist[i][0];
        int robotDistVal = robotDist[i][1];

        while (rightPtr < m && walls[rightPtr] <= robotPos) {
            rightPtr++;
        }
        int pos1 = rightPtr;

        while (curPtr < m && walls[curPtr] < robotPos) {
            curPtr++;
        }
        int pos2 = curPtr;

        int leftBound = robotPos - robotDistVal;
        if (i >= 1) {
            leftBound =
                maxInt(robotPos - robotDistVal, robotDist[i - 1][0] + 1);
        }
        while (leftPtr < m && walls[leftPtr] < leftBound) {
            leftPtr++;
        }
        int leftPos = leftPtr;
        int currentLeft = pos1 - leftPos;

        int rightBound = robotPos + robotDistVal;
        if (i < n - 1) {
            rightBound =
                minInt(robotPos + robotDistVal, robotDist[i + 1][0] - 1);
        }
        while (rightPtr < m && walls[rightPtr] <= rightBound) {
            rightPtr++;
        }
        int rightPos = rightPtr;
        int currentRight = rightPos - pos2;

        int currentNum = 0;
        if (i > 0) {
            while (robotPtr < m && walls[robotPtr] < robotDist[i - 1][0]) {
                robotPtr++;
            }
            int pos3 = robotPtr;
            currentNum = pos1 - pos3;
        }

        if (i == 0) {
            subLeft = currentLeft;
            subRight = currentRight;
        } else {
            int newsubLeft =
                maxInt(subLeft + currentLeft,
                       subRight - prevRight +
                           minInt(currentLeft + prevRight, currentNum));
            int newsubRight =
                maxInt(subLeft + currentRight, subRight + currentRight);
            subLeft = newsubLeft;
            subRight = newsubRight;
        }

        prevLeft = currentLeft;
        prevRight = currentRight;
        prevNum = currentNum;
    }

    int result = maxInt(subLeft, subRight);
    free(robotDist);
    return result;
}
