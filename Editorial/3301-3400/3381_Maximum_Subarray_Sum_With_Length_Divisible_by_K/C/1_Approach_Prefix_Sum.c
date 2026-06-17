long long maxSubarraySum(int* nums, int numsSize, int k) {
    long long prefixSum = 0;
    long long maxSum = LONG_MIN;
    long long* kSum = (long long*)malloc(sizeof(long long) * k);
    for (int i = 0; i < k; i++) {
        kSum[i] = LLONG_MAX / 2;
    }
    kSum[k - 1] = 0;
    for (int i = 0; i < numsSize; i++) {
        prefixSum += nums[i];
        if (prefixSum - kSum[i % k] > maxSum) {
            maxSum = prefixSum - kSum[i % k];
        }
        if (prefixSum < kSum[i % k]) {
            kSum[i % k] = prefixSum;
        }
    }
    free(kSum);
    return maxSum;
}
