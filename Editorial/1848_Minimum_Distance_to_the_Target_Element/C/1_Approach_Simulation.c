int getMinDistance(int* nums, int numsSize, int target, int start) {
    int res = numsSize;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            res = fmin(res, abs(i - start));
        }
    }
    return res;
}
