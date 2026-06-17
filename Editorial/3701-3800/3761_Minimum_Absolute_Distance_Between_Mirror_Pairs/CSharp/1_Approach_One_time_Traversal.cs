public class Solution {
    public int MinMirrorPairDistance(int[] nums) {
        Dictionary<int, int> prev = new Dictionary<int, int>();
        int n = nums.Length;
        int ans = n + 1;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (prev.ContainsKey(x)) {
                ans = Math.Min(ans, i - prev[x]);
            }
            prev[ReverseNum(x)] = i;
        }

        return ans == n + 1 ? -1 : ans;
    }

    private int ReverseNum(int x) {
        int y = 0;
        while (x > 0) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y;
    }
}
