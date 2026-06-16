class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = int(s.length()), res = 0;
        unordered_map<char, int> charToNextIndex;

        for (int j = 0, i = 0; j < n; j++) {
            if (charToNextIndex[s[j]] > 0) {
                i = max(charToNextIndex[s[j]], i);
            }
            res = max(res, j - i + 1);
            charToNextIndex[s[j]] = j + 1;
        }
        return res;
    }
};
