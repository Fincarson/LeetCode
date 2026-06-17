const int INF = 1e9;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int validSubarraySplit(int* nums, int numsSize) {
    int dp[numsSize + 1];
    for (int i = 1; i <= numsSize; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;
    for (int i = 1; i <= numsSize; i++) {
        for (int j = 1; j <= i; j++) {
            if (gcd(nums[i - 1], nums[j - 1]) > 1) {
                dp[i] = (dp[i] < dp[j - 1] + 1) ? dp[i] : dp[j - 1] + 1;
            }
        }
    }
    return (dp[numsSize] == INF) ? -1 : dp[numsSize];
}
