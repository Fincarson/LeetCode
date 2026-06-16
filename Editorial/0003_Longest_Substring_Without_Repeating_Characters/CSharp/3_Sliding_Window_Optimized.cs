public class Solution {
    public int LengthOfLongestSubstring(string s) {
        Dictionary<char, int> charToNextIndex = new Dictionary<char, int>();
        int maxLen = 0;
        int left = 0;
        for (int right = 0; right < s.Length; right++) {
            if (charToNextIndex.ContainsKey(s[right])) {
                left = Math.Max(charToNextIndex[s[right]], left);
            }

            maxLen = Math.Max(maxLen, right - left + 1);
            charToNextIndex[s[right]] = right + 1;
        }

        return maxLen;
    }
}
