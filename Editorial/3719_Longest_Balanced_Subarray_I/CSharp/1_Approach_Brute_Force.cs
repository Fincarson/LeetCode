public class Solution {
    public int LongestBalanced(int[] nums) {
        int len = 0;

        for (int i = 0; i < nums.Length; i++) {
            var odd = new Dictionary<int, int>();
            var even = new Dictionary<int, int>();

            for (int j = i; j < nums.Length; j++) {
                var dict = (nums[j] & 1) == 1 ? odd : even;
                dict[nums[j]] = dict.GetValueOrDefault(nums[j]) + 1;

                if (odd.Count == even.Count) {
                    len = Math.Max(len, j - i + 1);
                }
            }
        }

        return len;
    }
}
