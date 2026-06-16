public class Solution {
    public int LengthOfLongestSubstring(string s) {
        Dictionary<char, int> chars = new Dictionary<char, int>();

        int left = 0;
        int right = 0;

        int res = 0;
        while (right < s.Length) {
            char r = s[right];
            if (!chars.ContainsKey(r)) {
                chars[r] = 0;
            }

            chars[r]++;

            while (chars[r] > 1) {
                char l = s[left];
                chars[l]--;
                left++;
            }

            res = Math.Max(res, right - left + 1);

            right++;
        }

        return res;
    }
}
