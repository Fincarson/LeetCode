int largestRectangleArea(int* heights, int heightsSize) {
    int max_area = 0;
    for (int i = 0; i < heightsSize; i++) {
        int min_height = INT_MAX;
        for (int j = i; j < heightsSize; j++) {
            min_height = min_height < heights[j] ? min_height : heights[j];
            max_area = max_area > min_height * (j - i + 1)
                           ? max_area
                           : min_height * (j - i + 1);
        }
    }
    return max_area;
}
