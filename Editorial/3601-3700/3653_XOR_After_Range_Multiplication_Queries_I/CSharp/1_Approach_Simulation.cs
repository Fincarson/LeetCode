public class Solution {
    private const int MOD = 1_000_000_007;

    public int XorAfterQueries(int[] nums, int[][] queries) {
        int n = nums.Length;
        foreach (var q in queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for (int i = l; i <= r; i += k) {
                nums[i] = (int)((long)nums[i] * v % MOD);
            }
        }
        int res = 0;
        foreach (int x in nums) {
            res ^= x;
        }
        return res;
    }
}
