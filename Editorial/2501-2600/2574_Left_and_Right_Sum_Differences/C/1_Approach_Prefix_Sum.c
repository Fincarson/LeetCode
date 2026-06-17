int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* ans = (int*)malloc(numsSize * sizeof(int));

    int leftSum = 0;
    for (int i = 0; i < numsSize; ++i) {
        ans[i] = leftSum;
        leftSum += nums[i];
    }

    int rightSum = 0;
    for (int i = numsSize - 1; i >= 0; --i) {
        ans[i] = abs(ans[i] - rightSum);
        rightSum += nums[i];
    }

    return ans;
}
