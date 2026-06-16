const INF: number = 1e9;

function gcd(a: number, b: number): number {
    if (b === 0) return a;
    return gcd(b, a % b);
}

function validSubarraySplit(nums: number[]): number {
    const n: number = nums.length;
    const dp: number[] = new Array(n + 1).fill(INF);
    dp[0] = 0;
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= i; j++) {
            if (gcd(nums[i - 1], nums[j - 1]) > 1) {
                dp[i] = Math.min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    return dp[n] === INF ? -1 : dp[n];
}
