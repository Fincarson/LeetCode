public class Solution {
    public IList<IList<int>> FourSum(int[] nums, int target) {
        Array.Sort(nums);
        return kSum(nums, target, 0, 4);
    }

    private IList<IList<int>> kSum(int[] nums, long target, int start, int k) {
        List<IList<int>> res = new List<IList<int>>();
        if (start == nums.Length) {
            return res;
        }

        long averageValue = target / k;
        if (nums[start] > averageValue ||
            averageValue > nums[nums.Length - 1]) {
            return res;
        }

        if (k == 2) {
            return twoSum(nums, target, start);
        }

        for (int i = start; i < nums.Length; ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                foreach (List<int> subset in kSum(nums, target - nums[i], i + 1,
                                                  k - 1)) {
                    List<int> temp = new List<int> { nums[i] };
                    temp.AddRange(subset);
                    res.Add(temp);
                }
            }
        }

        return res;
    }

    public IList<IList<int>> twoSum(int[] nums, long target, int start) {
        List<IList<int>> res = new List<IList<int>>();
        HashSet<long> s = new HashSet<long>();
        for (int i = start; i < nums.Length; ++i) {
            if (res.Count == 0 || res[res.Count - 1][1] != nums[i]) {
                if (s.Contains(target - nums[i])) {
                    res.Add(new List<int> { (int)target - nums[i], nums[i] });
                }
            }

            s.Add(nums[i]);
        }

        return res;
    }
}
