public class Solution {
    public int MinCut(string s) {
        int[] cutsDp = new int[s.Length];
        for (int i = 1; i < s.Length; i++) {
            cutsDp[i] = i;
        }

        for (int mid = 0; mid < s.Length; mid++) {
            // check for odd length palindrome around mid index
            FindMinimumCuts(mid, mid, cutsDp, s);
            // check for even length palindrome around mid index
            FindMinimumCuts(mid - 1, mid, cutsDp, s);
        }

        return cutsDp[s.Length - 1];
    }

    public void FindMinimumCuts(int startIndex, int endIndex, int[] cutsDp,
                                string s) {
        for (int start = startIndex, end = endIndex;
             start >= 0 && end < s.Length && s[start] == s[end];
             start--, end++) {
            int newCut = start == 0 ? 0 : cutsDp[start - 1] + 1;
            cutsDp[end] = Math.Min(cutsDp[end], newCut);
        }
    }
}
