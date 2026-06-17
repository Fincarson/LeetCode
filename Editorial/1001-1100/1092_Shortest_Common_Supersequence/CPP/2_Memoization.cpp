class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        unordered_map<string, string> memo;
        return helper(str1, str2, memo);
    }

private:
    string helper(string str1, string str2,
                  unordered_map<string, string>& memo) {
        string memoKey = str1 + " " + str2;

        // Check if result is already computed
        if (memo.find(memoKey) != memo.end()) {
            return memo[memoKey];
        }

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
            return memo[memoKey] =
                       str1[0] + helper(str1.substr(1), str2.substr(1), memo);
        }

        // Try both options: picking from str1 or str2, and choose the shorter
        // one
        string pickStr1 = str1[0] + helper(str1.substr(1), str2, memo);
        string pickStr2 = str2[0] + helper(str1, str2.substr(1), memo);

        return memo[memoKey] = (pickStr1.length() < pickStr2.length())
                                   ? pickStr1
                                   : pickStr2;
    }
};
