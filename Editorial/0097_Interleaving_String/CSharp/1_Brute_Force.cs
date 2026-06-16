public class Solution {
    private bool IsInterleave(string s1, string s2, string s3, int i = 0,
                              int j = 0, string res = "") {
        // If result matches with third string and we have reached the end of
        // the all strings, return true.
        if (res == s3 && i == s1.Length && j == s2.Length)
            return true;
        bool ans = false;
        // Recurse for s1 & s2 if "ans" is false
        if (i < s1.Length)
            ans |= IsInterleave(s1, s2, s3, i + 1, j, res + s1[i]);
        if (j < s2.Length)
            ans |= IsInterleave(s1, s2, s3, i, j + 1, res + s2[j]);
        return ans;
    }

    public bool IsInterleave(string s1, string s2, string s3) {
        // Check if sum of sizes of two strings is equal to the size of third
        // string.
        if (s1.Length + s2.Length != s3.Length)
            return false;
        return IsInterleave(s1, s2, s3, 0, 0, "");
    }
}
