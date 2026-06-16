int maxSubArray(int* nums, int numsSize) {
    int max_subarray = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        int current_subarray = 0;
        for (int j = i; j < numsSize; j++) {
            current_subarray += nums[j];
            max_subarray = current_subarray > max_subarray ? current_subarray
                                                           : max_subarray;
        }
    }
    return max_subarray;
}
