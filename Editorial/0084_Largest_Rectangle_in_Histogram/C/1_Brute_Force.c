int largestRectangleArea(int* heights, int heightsSize) {
    int max_area = 0, min_height, i, j, k;
    for (i = 0; i < heightsSize; i++) {
        for (j = i; j < heightsSize; j++) {
            min_height = INT_MAX;
            for (k = i; k <= j; k++) {
                min_height = min_height < heights[k] ? min_height : heights[k];
            }
            max_area = max_area > min_height * (j - i + 1)
                           ? max_area
                           : min_height * (j - i + 1);
        }
    }
    return max_area;
}
