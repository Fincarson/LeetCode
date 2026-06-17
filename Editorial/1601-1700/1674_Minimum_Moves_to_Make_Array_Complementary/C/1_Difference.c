int minMoves(int* nums, int numsSize, int limit) {
    int n = numsSize;
    int* diff = (int*)calloc(2 * limit + 2, sizeof(int));

    for (int i = 0; i < n / 2; i++) {
        int a = fmin(nums[i], nums[n - 1 - i]);
        int b = fmax(nums[i], nums[n - 1 - i]);

        diff[2] += 2;
        diff[a + 1] -= 1;
        diff[a + b] -= 1;
        diff[a + b + 1] += 1;
        diff[b + limit + 1] += 1;
    }

    int minOps = n;
    int currentOps = 0;

    for (int c = 2; c <= 2 * limit; c++) {
        currentOps += diff[c];
        if (currentOps < minOps) {
            minOps = currentOps;
        }
    }

    free(diff);
    return minOps;
}
