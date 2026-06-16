public class Solution {
    public int MinCut(string s) {
        int[] cutsDp = new int[s.Length];
        bool[,] palindromeDp = new bool[s.Length, s.Length];
        // build the palindrome cutsDp for all susbtrings
        buildPalindromeDp(s, s.Length, ref palindromeDp);
        for (int end = 0; end < s.Length; end++) {
            int minimumCut = end;
            for (int start = 0; start <= end; start++) {
                if (palindromeDp[start, end]) {
                    minimumCut = start == 0 ? 0
                                            : Math.Min(minimumCut,
                                                       cutsDp[start - 1] + 1);
                }
            }

            cutsDp[end] = minimumCut;
        }

        return cutsDp[s.Length - 1];
    }

    void buildPalindromeDp(string s, int n, ref bool[,] palindromeDp) {
        for (int end = 0; end < s.Length; end++) {
            for (int start = 0; start <= end; start++) {
                if (s[start] == s[end] &&
                    (end - start <= 2 || palindromeDp[start + 1, end - 1])) {
                    palindromeDp[start, end] = true;
                }
            }
        }
    }
}
