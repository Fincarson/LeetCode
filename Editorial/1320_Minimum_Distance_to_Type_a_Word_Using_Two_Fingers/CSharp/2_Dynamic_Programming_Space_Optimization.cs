public class Solution {
    private int GetDistance(int p, int q) {
        int x1 = p / 6, y1 = p % 6;
        int x2 = q / 6, y2 = q % 6;
        return Math.Abs(x1 - x2) + Math.Abs(y1 - y2);
    }

    public int MinimumDistance(string word) {
        int n = word.Length;
        int[,] dp = new int[n, 26];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                dp[i, j] = int.MaxValue / 2;
            }
        }

        for (int j = 0; j < 26; j++) {
            dp[0, j] = 0;
        }
        for (int i = 1; i < n; i++) {
            int cur = word[i] - 'A';
            int prev = word[i - 1] - 'A';
            int d = GetDistance(prev, cur);

            for (int j = 0; j < 26; j++) {
                dp[i, j] = Math.Min(dp[i, j], dp[i - 1, j] + d);
                if (prev == j) {
                    for (int k = 0; k < 26; k++) {
                        int d0 = GetDistance(k, cur);
                        dp[i, j] = Math.Min(dp[i, j], dp[i - 1, k] + d0);
                    }
                }
            }
        }

        int ans = int.MaxValue / 2;
        for (int j = 0; j < 26; j++) {
            ans = Math.Min(ans, dp[n - 1, j]);
        }
        return ans;
    }
}
