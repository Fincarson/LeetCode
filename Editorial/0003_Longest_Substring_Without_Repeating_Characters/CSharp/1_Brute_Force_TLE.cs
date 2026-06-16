public class Solution {
    public int LengthOfLongestSubstring(string s) {
        int n = s.Length;

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (CheckRepetition(s, i, j)) {
                    res = Math.Max(res, j - i + 1);
                }
            }
        }

        return res;
    }

    private bool CheckRepetition(string s, int start, int end) {
        HashSet<char> chars = new HashSet<char>();

        for (int i = start; i <= end; i++) {
            char c = s[i];
            if (chars.Contains(c)) {
                return false;
            }

            chars.Add(c);
        }

        return true;
    }
}
