int trap(int* height, int heightSize) {
    // Case of empty height array
    if (heightSize == 0) return 0;
    int ans = 0;
    // Create left and right max arrays
    int* left_max = (int*)calloc(heightSize, sizeof(int));
    int* right_max = (int*)calloc(heightSize, sizeof(int));
    // Initialize first height into left max
    left_max[0] = height[0];
    for (int i = 1; i < heightSize; i++) {
        // update left max with current max
        left_max[i] = height[i] > left_max[i - 1] ? height[i] : left_max[i - 1];
    }
    // Initialize last height into right max
    right_max[heightSize - 1] = height[heightSize - 1];
    for (int i = heightSize - 2; i >= 0; i--) {
        // update right max with current max
        right_max[i] =
            height[i] > right_max[i + 1] ? height[i] : right_max[i + 1];
    }
    // Calculate the trapped water
    for (int i = 1; i < heightSize - 1; i++) {
        int min_height =
            left_max[i] < right_max[i] ? left_max[i] : right_max[i];
        ans += min_height - height[i];
    }
    // free the arrays
    free(left_max);
    free(right_max);
    // Return amount of trapped water
    return ans;
}
