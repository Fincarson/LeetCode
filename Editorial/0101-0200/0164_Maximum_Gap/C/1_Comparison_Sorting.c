int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int maximumGap(int* nums, int numsSize) {
    if (nums == NULL || numsSize < 2)  // check if array is empty or small sized
        return 0;

    qsort(nums, numsSize, sizeof(int), cmp);  // sort the array

    int maxGap = 0;

    for (int i = 0; i < numsSize - 1; i++)
        maxGap =
            (nums[i + 1] - nums[i] > maxGap) ? nums[i + 1] - nums[i] : maxGap;

    return maxGap;
}
