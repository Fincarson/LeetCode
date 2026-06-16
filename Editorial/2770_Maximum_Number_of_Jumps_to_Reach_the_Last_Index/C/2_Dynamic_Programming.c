int maximumJumps(int* nums, int numsSize, int target) {
    int* dp = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        dp[i] = INT_MIN;
    }
    dp[0] = 0;

    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (abs(nums[j] - nums[i]) <= target) {
                if (dp[j] != INT_MIN) {
                    dp[i] = fmax(dp[i], dp[j] + 1);
                }
            }
        }
    }

    int result = dp[numsSize - 1] < 0 ? -1 : dp[numsSize - 1];
    free(dp);
    return result;
}
