int minimumPairRemoval(int* nums, int n) {
    int* next = (int*)malloc(n * sizeof(int));
    if (next == NULL) {
        return -1;
    }
    for (int i = 0; i < n; i++) {
        next[i] = i + 1;
    }
    next[n - 1] = -1;

    int count = 0;
    while (n - count > 1) {
        int curr = 0;
        int target = 0;
        int targetAdjSum = nums[target] + nums[next[target]];
        int isAscending = 1;

        while (curr != -1 && next[curr] != -1) {
            if (nums[curr] > nums[next[curr]]) {
                isAscending = 0;
            }

            int currAdjSum = nums[curr] + nums[next[curr]];
            if (currAdjSum < targetAdjSum) {
                target = curr;
                targetAdjSum = currAdjSum;
            }
            curr = next[curr];
        }
        if (isAscending) {
            break;
        }
        count++;
        next[target] = next[next[target]];
        nums[target] = targetAdjSum;
    }

    free(next);
    return count;
}
