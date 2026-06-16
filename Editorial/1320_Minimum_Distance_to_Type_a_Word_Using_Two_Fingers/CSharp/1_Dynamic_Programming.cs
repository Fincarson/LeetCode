public class Solution {
    private int GetDistance(int p, int q) {
        int x1 = p / 6, y1 = p % 6;
        int x2 = q / 6, y2 = q % 6;
        return Math.Abs(x1 - x2) + Math.Abs(y1 - y2);
    }

    public int MinimumDistance(string word) {
        int n = word.Length;
        int[,,] dp = new int[n, 26, 26];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                for (int k = 0; k < 26; ++k) {
                    dp[i, j, k] = int.MaxValue / 2;
                }
            }
        }

        for (int i = 0; i < 26; ++i) {
            dp[0, i, word[0] - 'A'] = 0;
            dp[0, word[0] - 'A', i] = 0;
        }
        for (int i = 1; i < n; ++i) {
            int cur = word[i] - 'A';
            int prev = word[i - 1] - 'A';
            int d = GetDistance(prev, cur);

            for (int j = 0; j < 26; ++j) {
                dp[i, cur, j] = Math.Min(dp[i, cur, j], dp[i - 1, prev, j] + d);
                dp[i, j, cur] = Math.Min(dp[i, j, cur], dp[i - 1, j, prev] + d);

                if (prev == j) {
                    for (int k = 0; k < 26; ++k) {
                        int d0 = GetDistance(k, cur);
                        dp[i, cur, j] =
                            Math.Min(dp[i, cur, j], dp[i - 1, k, j] + d0);
                        dp[i, j, cur] =
                            Math.Min(dp[i, j, cur], dp[i - 1, j, k] + d0);
                    }
                }
            }
        }

        int ans = int.MaxValue / 2;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                ans = Math.Min(ans, dp[n - 1, i, j]);
            }
        }
        return ans;
    }
}
