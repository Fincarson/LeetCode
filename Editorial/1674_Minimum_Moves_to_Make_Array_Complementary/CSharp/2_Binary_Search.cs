public class Solution {
    public int MinMoves(int[] nums, int limit) {
        int n = nums.Length;
        var sumCount = new Dictionary<int, int>();
        var minArr = new int[n / 2];
        var maxArr = new int[n / 2];

        for (int i = 0; i < n / 2; i++) {
            int a = Math.Min(nums[i], nums[n - 1 - i]);
            int b = Math.Max(nums[i], nums[n - 1 - i]);

            int sum = a + b;
            sumCount[sum] = sumCount.GetValueOrDefault(sum) + 1;

            minArr[i] = a;
            maxArr[i] = b;
        }

        Array.Sort(minArr);
        Array.Sort(maxArr);

        int LowerBound(int[] arr, int target) {
            int left = 0, right = arr.Length;
            while (left < right) {
                int mid = left + ((right - left) >>> 1);
                if (arr[mid] >= target) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }

        int minOps = n;

        for (int c = 2; c <= 2 * limit; c++) {
            int addLeft = n / 2 - LowerBound(minArr, c);
            int addRight = LowerBound(maxArr, c - limit);

            int currentOps =
                n / 2 + addLeft + addRight - sumCount.GetValueOrDefault(c);
            minOps = Math.Min(minOps, currentOps);
        }

        return minOps;
    }
}
