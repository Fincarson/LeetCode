public class Solution {
    public int ThreeSumClosest(int[] nums, int target) {
        int diff = Int32.MaxValue;
        int sz = nums.Length;
        Array.Sort(nums);
        for (int i = 0; i < sz && diff != 0; ++i) {
            int lo = i + 1;
            int hi = sz - 1;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (Math.Abs(target - sum) < Math.Abs(diff)) {
                    diff = target - sum;
                }

                if (sum < target) {
                    ++lo;
                } else {
                    --hi;
                }
            }
        }

        return target - diff;
    }
}
