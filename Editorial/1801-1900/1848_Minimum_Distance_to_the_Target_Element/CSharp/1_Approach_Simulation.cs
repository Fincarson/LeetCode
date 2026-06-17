public class Solution {
    public int GetMinDistance(int[] nums, int target, int start) {
        int res = nums.Length;
        for (int i = 0; i < nums.Length; i++) {
            if (nums[i] == target) {
                res = Math.Min(res, Math.Abs(i - start));
            }
        }
        return res;
    }
}
