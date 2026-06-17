int maxSubArray(int* nums, int numsSize) {
    // Initialize our variables using the first element.
    int currentSubarray = nums[0];
    int maxSubarray = nums[0];
    // Start with the 2nd element since we already used the first one.
    for (int i = 1; i < numsSize; i++) {
        // If current_subarray is negative, throw it away. Otherwise, keep
        // adding to it.
        currentSubarray =
            currentSubarray < 0 ? nums[i] : currentSubarray + nums[i];
        maxSubarray =
            currentSubarray > maxSubarray ? currentSubarray : maxSubarray;
    }
    return maxSubarray;
}
