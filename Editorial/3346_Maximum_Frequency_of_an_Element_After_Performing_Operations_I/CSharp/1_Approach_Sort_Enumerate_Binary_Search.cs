public class Solution {
    public int MaxFrequency(int[] nums, int k, int numOperations) {
        Array.Sort(nums);

        int ans = 0;
        Dictionary<int, int> numCount = new Dictionary<int, int>();

        int lastNumIndex = 0;
        for (int i = 0; i < nums.Length; ++i) {
            if (nums[i] != nums[lastNumIndex]) {
                numCount[nums[lastNumIndex]] = i - lastNumIndex;
                ans = Math.Max(ans, i - lastNumIndex);
                lastNumIndex = i;
            }
        }

        numCount[nums[lastNumIndex]] = nums.Length - lastNumIndex;
        ans = Math.Max(ans, nums.Length - lastNumIndex);

        for (int i = nums[0]; i <= nums[nums.Length - 1]; i++) {
            int l = LeftBound(nums, i - k);
            int r = RightBound(nums, i + k);

            int tempAns;
            if (numCount.ContainsKey(i)) {
                tempAns = Math.Min(r - l + 1, numCount[i] + numOperations);
            } else {
                tempAns = Math.Min(r - l + 1, numOperations);
            }
            ans = Math.Max(ans, tempAns);
        }

        return ans;
    }

    private int LeftBound(int[] nums, int value) {
        int left = 0, right = nums.Length - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < value) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    private int RightBound(int[] nums, int value) {
        int left = 0, right = nums.Length - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (nums[mid] > value) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return left;
    }
}
