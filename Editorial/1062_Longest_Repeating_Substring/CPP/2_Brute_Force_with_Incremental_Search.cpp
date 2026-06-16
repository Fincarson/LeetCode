class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int length = s.length(), maxLength = 0;
        unordered_set<string> seenSubstrings;

        for (int start = 0; start < length; start++) {
            int end = start;
            // Stop if it's not possible to find a longer repeating substring
            if (end + maxLength >= length) {
                return maxLength;
            }
            // Generate substrings of length maxLength + 1
            string currentSubstring = s.substr(end, maxLength + 1);
            // If a repeating substring is found, increase maxLength and
            // restart
            if (!seenSubstrings.insert(currentSubstring).second) {
                start = -1;  // Restart search for new length
                seenSubstrings.clear();
                maxLength++;
            }
        }
        return maxLength;
    }
};
