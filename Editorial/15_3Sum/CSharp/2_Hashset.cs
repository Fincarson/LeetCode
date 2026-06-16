public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        Array.Sort(nums);
        List<IList<int>> res = new List<IList<int>>();
        for (int i = 0; i < nums.Length && nums[i] <= 0; ++i)
            if (i == 0 || nums[i - 1] != nums[i]) {
                TwoSum(nums, i, res);
            }

        return res;
    }

    void TwoSum(int[] nums, int i, List<IList<int>> res) {
        HashSet<int> seen = new HashSet<int>();
        for (int j = i + 1; j < nums.Length; ++j) {
            int complement = -nums[i] - nums[j];
            if (seen.Contains(complement)) {
                res.Add(new List<int> { nums[i], nums[j], complement });
                while (j + 1 < nums.Length && nums[j] == nums[j + 1]) ++j;
            }

            seen.Add(nums[j]);
        }
    }
}
