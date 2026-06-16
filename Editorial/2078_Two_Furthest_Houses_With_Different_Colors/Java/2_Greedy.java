class Solution {
    public int maxDistance(int[] colors) {
        int n = colors.length;
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (colors[i] != colors[n - 1]) {
                ans = Math.max(ans, Math.max(i, n - 1 - i));
            }
        }
        return ans;
    }
}
