class Solution {
    public int longestIdealString(String s, int k) {
        int N = s.length();
        int[] dp = new int[26];

        int res = 0;
        // Updating dp with the i-th character
        for (int i = 0; i < N; i++) {
            int curr = s.charAt(i) - 'a';
            int best = 0;
            for (int prev = Math.max(0, curr - k); prev < Math.min(26, curr + k + 1); prev++) {
                best = Math.max(best, dp[prev]);
            }

            // Append s[i] to the previous longest ideal subsequence
            dp[curr] = best + 1;
            res = Math.max(res, dp[curr]);
        }

        return res;
    }
}
