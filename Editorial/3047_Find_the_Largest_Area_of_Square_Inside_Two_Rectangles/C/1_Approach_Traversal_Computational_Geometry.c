long long largestSquareArea(int** bottomLeft, int bottomLeftSize,
                            int* bottomLeftColSize, int** topRight,
                            int topRightSize, int* topRightColSize) {
    int n = bottomLeftSize;
    long long maxSide = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int w = fmin(topRight[i][0], topRight[j][0]) -
                    fmax(bottomLeft[i][0], bottomLeft[j][0]);
            int h = fmin(topRight[i][1], topRight[j][1]) -
                    fmax(bottomLeft[i][1], bottomLeft[j][1]);
            if (w > 0 && h > 0) {
                int side = fmin(w, h);
                if ((long long)side > maxSide) {
                    maxSide = (long long)side;
                }
            }
        }
    }

    return maxSide * maxSide;
}
