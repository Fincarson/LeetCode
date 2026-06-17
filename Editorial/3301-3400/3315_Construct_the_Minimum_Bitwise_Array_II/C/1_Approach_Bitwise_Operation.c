int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        int res = -1;
        int d = 1;
        while ((x & d) != 0) {
            res = x - d;
            d <<= 1;
        }
        nums[i] = res;
    }
    return nums;
}
