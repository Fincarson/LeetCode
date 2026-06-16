int maximumGap(int* nums, int numsSize) {
    if (nums == NULL || numsSize < 2) {
        return 0;
    }

    int maxVal = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        maxVal = (maxVal > nums[i]) ? maxVal : nums[i];
    }

    long exp = 1;
    int radix = 10;
    int* aux = (int*)malloc(numsSize * sizeof(int));

    while (maxVal / exp > 0) {
        int count[radix];
        memset(count, 0, sizeof(count));

        for (int i = 0; i < numsSize; i++) {
            count[(nums[i] / exp) % 10]++;
        }

        for (int i = 1; i < radix; i++) {
            count[i] += count[i - 1];
        }

        for (int i = numsSize - 1; i >= 0; i--) {
            aux[--count[(nums[i] / exp) % 10]] = nums[i];
        }

        memmove(nums, aux, numsSize * sizeof(int));

        exp *= 10;
    }
    int maxGap = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        int diff = nums[i + 1] - nums[i];
        maxGap = (maxGap > diff) ? maxGap : diff;
    }
    return maxGap;
}
