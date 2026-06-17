int dfs(int i, int* nums, int n, int target, int* memo) {
    if (i == n - 1) {
        return 0;
    }
    if (memo[i] != INT_MIN) {
        return memo[i];
    }

    int res = INT_MIN;
    for (int j = i + 1; j < n; j++) {
        if (abs(nums[i] - nums[j]) <= target) {
            res = fmax(res, dfs(j, nums, n, target, memo) + 1);
        }
    }
    memo[i] = res;
    return res;
}

int maximumJumps(int* nums, int numsSize, int target) {
    int* memo = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        memo[i] = INT_MIN;
    }

    int ans = dfs(0, nums, numsSize, target, memo);
    free(memo);
    return ans < 0 ? -1 : ans;
}
