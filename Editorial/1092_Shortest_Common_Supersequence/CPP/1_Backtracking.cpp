class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // Base case: both strings are empty
        if (str1.empty() && str2.empty()) {
            return "";
        }

        // Base case: one string is empty, append the other string
        if (str1.empty()) {
            return str2;
        }

        if (str2.empty()) {
            return str1;
        }

        // If the first characters match, include it in the supersequence
        if (str1[0] == str2[0]) {
            return str1[0] +
                   shortestCommonSupersequence(str1.substr(1), str2.substr(1));
        } else {
            // Try both options: picking from str1 or str2, and choose the
            // shorter one
            string pickStr1 =
                str1[0] + shortestCommonSupersequence(str1.substr(1), str2);
            string pickStr2 =
                str2[0] + shortestCommonSupersequence(str1, str2.substr(1));

            return (pickStr1.length() < pickStr2.length()) ? pickStr1
                                                           : pickStr2;
        }
    }
};
