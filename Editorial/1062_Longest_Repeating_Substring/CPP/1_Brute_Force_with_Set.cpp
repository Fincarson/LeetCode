class Solution {
public:
    int longestRepeatingSubstring(string s) {
        unordered_set<string> seenSubstrings;
        int maxLength = s.length() - 1;

        for (int start = 0; start <= s.length(); start++) {
            int end = start;
            // Check if the remaining characters can form a substring of
            // maxLength
            if (end + maxLength > s.length()) {
                // Reduce maxLength if not possible and reset
                if (--maxLength == 0) break;
                start = -1;
                seenSubstrings.clear();
                continue;
            }
            // Extract the substring from the current start to start +
            // maxLength
            string currentSubstring = s.substr(end, maxLength);
            // If the substring has been seen before, it's a repeating
            // substring
            if (!seenSubstrings.insert(currentSubstring).second) {
                return maxLength;
            }
        }
        return maxLength;
    }
};
