public class Solution {
    public int MinimumDistance(int[] nums) {
        int n = nums.Length;
        int[] next = new int[n];
        Array.Fill(next, -1);
        Dictionary<int, int> occur = new();
        int ans = n + 1;

        for (int i = n - 1; i >= 0; i--) {
            if (occur.TryGetValue(nums[i], out int val)) {
                next[i] = val;
            }
            occur[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            int secondPos = next[i];
            if (secondPos != -1) {
                int thirdPos = next[secondPos];
                if (thirdPos != -1) {
                    ans = Math.Min(ans, thirdPos - i);
                }
            }
        }

        return ans == n + 1 ? -1 : ans * 2;
    }
}
