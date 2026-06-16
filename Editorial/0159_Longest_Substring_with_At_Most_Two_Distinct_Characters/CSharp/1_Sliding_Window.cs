public class Solution {
    public int LengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.Length;
        if (n < 3) return n;

        // sliding window left and right pointers
        int left = 0;
        int right = 0;
        // hashmap character -> its rightmost position
        // in the sliding window
        Dictionary<char, int> hashmap = new Dictionary<char, int>();

        int max_len = 2;

        while (right < n) {
            // when the slidewindow contains less than 3 characters
            hashmap[s[right]] = right++;

            // slidewindow contains 3 characters
            if (hashmap.Count == 3) {
                // delete the leftmost character
                int del_idx = hashmap.Values.Min();
                hashmap.Remove(s[del_idx]);
                // move left pointer of the slidewindow
                left = del_idx + 1;
            }

            max_len = Math.Max(max_len, right - left);
        }

        return max_len;
    }
}
