public class Solution {
    public string LongestPalindrome(string s) {
        int[] ans = new int[] { 0, 0 };

        for (int i = 0; i < s.Length; i++) {
            int oddLength = Expand(s, i, i);
            if (oddLength > ans[1] - ans[0] + 1) {
                int dist = oddLength / 2;
                ans[0] = i - dist;
                ans[1] = i + dist;
            }

            int evenLength = Expand(s, i, i + 1);
            if (evenLength > ans[1] - ans[0] + 1) {
                int dist = (evenLength / 2) - 1;
                ans[0] = i - dist;
                ans[1] = i + dist + 1;
            }
        }

        return s.Substring(ans[0], ans[1] - ans[0] + 1);
    }

    private int Expand(string s, int i, int j) {
        int left = i;
        int right = j;

        while (left >= 0 && right < s.Length && s[left] == s[right]) {
            left--;
            right++;
        }

        return right - left - 1;
    }
}
