public class Solution {
    public int ThreeSumClosest(int[] nums, int target) {
        int diff = int.MaxValue, sz = nums.Length;
        Array.Sort(nums);
        for (int i = 0; i < sz && diff != 0; ++i) {
            for (int j = i + 1; j < sz - 1; ++j) {
                int complement = target - nums[i] - nums[j];
                int lo = j + 1, hi = sz;
                while (lo < hi) {
                    int mid = lo + (hi - lo) / 2;
                    if (nums[mid] <= complement)
                        lo = mid + 1;
                    else
                        hi = mid;
                }

                int hi_idx = lo, lo_idx = lo - 1;
                if (hi_idx < sz &&
                    Math.Abs(complement - nums[hi_idx]) < Math.Abs(diff))
                    diff = complement - nums[hi_idx];
                if (lo_idx > j &&
                    Math.Abs(complement - nums[lo_idx]) < Math.Abs(diff))
                    diff = complement - nums[lo_idx];
            }
        }

        return target - diff;
    }
}
