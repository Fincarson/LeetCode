public class Solution {
    public IList<IList<int>> FourSum(int[] nums, int target) {
        Array.Sort(nums);
        return KSum(nums, target, 0, 4);
    }

    public IList<IList<int>> KSum(int[] nums, long target, int start, int k) {
        List<IList<int>> res = new List<IList<int>>();
        if (start == nums.Length) {
            return res;
        }

        long average_value = target / k;
        if (nums[start] > average_value ||
            average_value > nums[nums.Length - 1]) {
            return res;
        }

        if (k == 2) {
            return TwoSum(nums, target, start);
        }

        for (int i = start; i < nums.Length; i++) {
            if (i == start || nums[i - 1] != nums[i]) {
                foreach (var subset in KSum(nums, target - nums[i], i + 1,
                                            k - 1)) {
                    var list = new List<int> { nums[i] };
                    list.AddRange(subset);
                    res.Add(list);
                }
            }
        }

        return res;
    }

    public IList<IList<int>> TwoSum(int[] nums, long target, int start) {
        List<IList<int>> res = new List<IList<int>>();
        int lo = start, hi = nums.Length - 1;
        while (lo < hi) {
            int curr_sum = nums[lo] + nums[hi];
            if (curr_sum < target || (lo > start && nums[lo] == nums[lo - 1])) {
                ++lo;
            } else if (curr_sum > target ||
                       (hi < nums.Length - 1 && nums[hi] == nums[hi + 1])) {
                --hi;
            } else {
                res.Add(new List<int> { nums[lo++], nums[hi--] });
            }
        }

        return res;
    }
}
