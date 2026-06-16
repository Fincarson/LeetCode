class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int length = s.length();
        vector<string> suffixes(length);

        // Create suffix array by storing all suffixes of the string
        for (int i = 0; i < length; i++) {
            suffixes[i] = s.substr(i);
        }
        // Sort the suffix array
        sort(suffixes.begin(), suffixes.end());

        int maxLength = 0;
        // Compare adjacent suffixes to find the longest common prefix
        for (int i = 1; i < length; i++) {
            int j = 0;
            // Compare characters one by one until they differ or end of one
            // suffix is reached
            while (j < min(suffixes[i].length(), suffixes[i - 1].length()) &&
                   suffixes[i][j] == suffixes[i - 1][j]) {
                j++;
            }
            // Update maxLength with the length of the common prefix
            maxLength = max(maxLength, j);
        }
        return maxLength;
    }
};
