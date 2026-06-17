public class Solution {
    public int MaxDistance(int[] colors) {
        int n = colors.Length;
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (colors[i] != colors[n - 1]) {
                ans = Math.Max(ans, Math.Max(i, n - 1 - i));
            }
        }
        return ans;
    }
}
