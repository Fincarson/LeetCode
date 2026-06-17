public class Solution {
    public int MaximumJumps(int[] nums, int target) {
        int n = nums.Length;
        int[] memo = new int[n];
        Array.Fill(memo, int.MinValue);

        Func<int, int> dfs = null;
        dfs = (i) => {
            if (i == n - 1) {
                return 0;
            }
            if (memo[i] != int.MinValue) {
                return memo[i];
            }
            int res = int.MinValue;
            for (int j = i + 1; j < n; j++) {
                if (Math.Abs(nums[i] - nums[j]) <= target) {
                    res = Math.Max(res, dfs(j) + 1);
                }
            }
            return memo[i] = res;
        };

        int ans = dfs(0);
        return ans < 0 ? -1 : ans;
    }
}
