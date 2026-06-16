public class Solution {
    public int MinCut(string s) {
        int[] cuts = new int[s.Length];
        bool[][] palindrome = new bool [s.Length][];
        for (int i = 0; i < s.Length; i++) palindrome[i] = new bool[s.Length];
        for (int end = 0; end < s.Length; end++) {
            int minimumCut = end;
            for (int start = 0; start <= end; start++) {
                // check if substring (start, end) is palindrome
                if (s[start] == s[end] &&
                    (end - start <= 2 || palindrome[start + 1][end - 1])) {
                    palindrome[start][end] = true;
                    minimumCut =
                        start == 0 ? 0
                                   : Math.Min(minimumCut, cuts[start - 1] + 1);
                }
            }

            cuts[end] = minimumCut;
        }

        return cuts[s.Length - 1];
    }
}
