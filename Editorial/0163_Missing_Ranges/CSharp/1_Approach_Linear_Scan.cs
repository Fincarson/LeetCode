public class Solution {
    public IList<IList<int>>
        FindMissingRanges(int[] nums, int lower, int upper) {
        int n = nums.Length;
        IList<IList<int>> missingRanges = new List<IList<int>>();

        if (n == 0) {
            missingRanges.Add(new List<int>() { lower, upper });
            return missingRanges;
        }

        // Check for any missing numbers between the lower bound and nums[0].
        if (lower < nums[0]) {
            missingRanges.Add(new List<int>() { lower, nums[0] - 1 });
        }

        // Check for any missing numbers between successive elements of nums.
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] <= 1) {
                continue;
            }

            missingRanges.Add(new List<int>() { nums[i] + 1, nums[i + 1] - 1 });
        }

        // Check for any missing numbers between the last element of nums and the upper bound.
        if (upper > nums[n - 1]) {
            missingRanges.Add(new List<int>() { nums[n - 1] + 1, upper });
        }

        return missingRanges;
    }
}
