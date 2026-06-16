int* getRow(int n, int* returnSize) {
    *returnSize = n + 1;
    int* ans = malloc((n + 1) * sizeof(int));
    ans[0] = 1;
    for (int k = 1; k <= n; k++)
        ans[k] = (int)((ans[k - 1] * (long long)(n - k + 1)) / k);
    return ans;
}
