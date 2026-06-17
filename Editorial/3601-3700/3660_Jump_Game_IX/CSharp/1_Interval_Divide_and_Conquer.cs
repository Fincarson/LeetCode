public class Solution {
    public int[] MaxValue(int[] nums) {
        int n = nums.Length;
        int[] ans = new int[n];
        // [value, index]
        (int Value, int Index)[] prevMax = new(int, int)[n];

        (int Value, int Index) prev = (int.MinValue, -1);
        for (int i = 0; i < n; i++) {
            if (nums[i] > prev.Value) {
                prev = (nums[i], i);
            }
            prevMax[i] = prev;
        }

        void Process(int r, int rightMin, int rightMax) {
            var (pMax, pivotIndex) = prevMax[r];
            int currMax = pMax <= rightMin ? pMax : rightMax;

            int nextRightMin = Math.Min(pMax, rightMin);
            for (int i = pivotIndex; i <= r; i++) {
                ans[i] = currMax;
                nextRightMin = Math.Min(nextRightMin, nums[i]);
            }

            if (pivotIndex == 0) {
                return;
            }

            Process(pivotIndex - 1, nextRightMin, currMax);
        }

        Process(n - 1, int.MaxValue, 0);
        return ans;
    }
}
