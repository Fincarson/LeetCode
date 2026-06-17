long long maximumTripletValue(int* nums, int numsSize) {
    long long res = 0;
    for (int k = 2; k < numsSize; k++) {
        int maxPrefix = nums[0];
        for (int j = 1; j < k; j++) {
            long long value = (long long)(maxPrefix - nums[j]) * nums[k];
            if (value > res) {
                res = value;
            }
            if (nums[j] > maxPrefix) {
                maxPrefix = nums[j];
            }
        }
    }
    return res;
}
