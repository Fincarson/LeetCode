class Solution {
public:
    bool is_Interleave(string s1, int i, string s2, int j, string res,
                       string s3) {
        // If result matches with third string and we have reached the end of
        // the all strings, return true.
        if (res == s3 && i == s1.length() && j == s2.length()) return true;
        bool ans = false;
        // Recurse for s1 & s2 if "ans" is false
        if (i < s1.length())
            ans |= is_Interleave(s1, i + 1, s2, j, res + s1[i], s3);
        if (j < s2.length())
            ans |= is_Interleave(s1, i, s2, j + 1, res + s2[j], s3);
        return ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        // Check if sum of sizes of two strings is equal to the size of third
        // string.
        if (s1.length() + s2.length() != s3.length()) return false;
        return is_Interleave(s1, 0, s2, 0, "", s3);
    }
};
