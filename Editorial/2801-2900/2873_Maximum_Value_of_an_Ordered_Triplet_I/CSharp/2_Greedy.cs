public class Solution {
    public long MaximumTripletValue(int[] nums) {
        int n = nums.Length;
        long res = 0;
        for (int k = 2; k < n; k++) {
            int maxPrefix = nums[0];
            for (int j = 1; j < k; j++) {
                res = Math.Max(res, (long)(maxPrefix - nums[j]) * nums[k]);
                maxPrefix = Math.Max(maxPrefix, nums[j]);
            }
        }
        return res;
    }
}
