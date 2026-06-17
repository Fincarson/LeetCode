const INF = 1e9;

function gcd(a, b) {
    if (b === 0) return a;
    return gcd(b, a % b);
}

var validSubarraySplit = function (nums) {
    const n = nums.length;
    const dp = new Array(n + 1).fill(INF);
    dp[0] = 0;
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= i; j++) {
            if (gcd(nums[i - 1], nums[j - 1]) > 1) {
                dp[i] = Math.min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    return dp[n] === INF ? -1 : dp[n];
};
