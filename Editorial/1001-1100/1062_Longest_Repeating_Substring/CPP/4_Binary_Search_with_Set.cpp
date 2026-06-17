class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int start = 1, end = s.length() - 1;

        while (start <= end) {
            int mid = (start + end) / 2;
            // Check if there's a repeating substring of length mid
            if (hasRepeatingSubstring(s, mid)) {
                start = mid + 1;  // Try longer substrings
            } else {
                end = mid - 1;  // Try shorter substrings
            }
        }
        return start - 1;
    }

private:
    bool hasRepeatingSubstring(string& s, int length) {
        unordered_set<string> seenSubstrings;
        for (int i = 0; i <= s.length() - length; i++) {
            // Extract a substring of the given length
            string substring = s.substr(i, length);
            // Check if the substring has been seen before
            if (!seenSubstrings.insert(substring).second) {
                return true;
            }
        }
        return false;
    }
};
