public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        Array.Sort(nums);
        List<IList<int>> res = new List<IList<int>>();
        for (int i = 0; i < nums.Length && nums[i] <= 0; ++i)
            if (i == 0 || nums[i - 1] != nums[i]) {
                TwoSumII(nums, i, res);
            }

        return res;
    }

    void TwoSumII(int[] nums, int i, List<IList<int>> res) {
        int lo = i + 1, hi = nums.Length - 1;
        while (lo < hi) {
            int sum = nums[i] + nums[lo] + nums[hi];
            if (sum < 0) {
                ++lo;
            } else if (sum > 0) {
                --hi;
            } else {
                res.Add(new List<int> { nums[i], nums[lo++], nums[hi--] });
                while (lo < hi && nums[lo] == nums[lo - 1]) ++lo;
            }
        }
    }
}
