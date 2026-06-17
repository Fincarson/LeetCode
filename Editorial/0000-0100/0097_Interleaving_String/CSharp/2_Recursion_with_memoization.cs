// A recursive function is used to go through all possible interleavings.
// Memoization is used to avoid recomputing the same information and to return
// the cached results.

public class Solution {
    public bool IsInterleave(string s1, string s2, string s3) {
        if (s1.Length + s2.Length != s3.Length) {
            return false;
        }

        int[,] memo = new int[s1.Length, s2.Length];
        for (int i = 0; i < s1.Length; i++) {
            for (int j = 0; j < s2.Length; j++) {
                memo[i, j] = -1;
            }
        }

        return IsInterleave(s1, 0, s2, 0, s3, 0, memo);
    }

    public bool IsInterleave(string s1, int i, string s2, int j, string s3,
                             int k, int[,] memo) {
        if (i == s1.Length) {
            return s2.Substring(j).Equals(s3.Substring(k));
        }

        if (j == s2.Length) {
            return s1.Substring(i).Equals(s3.Substring(k));
        }

        if (memo[i, j] >= 0) {
            return memo[i, j] == 1 ? true : false;
        }

        bool ans = false;
        if (s3[k] == s1[i] && IsInterleave(s1, i + 1, s2, j, s3, k + 1, memo) ||
            s3[k] == s2[j] && IsInterleave(s1, i, s2, j + 1, s3, k + 1, memo)) {
            ans = true;
        }

        memo[i, j] = ans ? 1 : 0;
        return ans;
    }
}
