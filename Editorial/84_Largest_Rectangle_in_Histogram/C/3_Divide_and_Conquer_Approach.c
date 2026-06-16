int max(int a, int b) { return (a > b) ? a : b; }
int calculateArea(int* heights, int start, int end) {
    if (start > end) return 0;
    int min_index = start;
    for (int i = start; i <= end; i++)
        if (heights[min_index] > heights[i]) min_index = i;
    return max(heights[min_index] * (end - start + 1),
               max(calculateArea(heights, start, min_index - 1),
                   calculateArea(heights, min_index + 1, end)));
}
int largestRectangleArea(int* heights, int heightsSize) {
    return calculateArea(heights, 0, heightsSize - 1);
}
