class Solution {
public:
    int minCut(string s) {
        return findMinimumCut(s, 0, s.length() - 1, s.length() - 1);
    }

    int findMinimumCut(string &s, int start, int end, int minimumCut) {
        // base condition, no cut needed for an empty substring or palindrome
        // substring.
        if (start == end || isPalindrome(s, start, end)) {
            return 0;
        }
        for (int currentEndIndex = start; currentEndIndex <= end;
             currentEndIndex++) {
            // find result for substring (start, currentEnd) if it is palindrome
            if (isPalindrome(s, start, currentEndIndex)) {
                minimumCut =
                    min(minimumCut, 1 + findMinimumCut(s, currentEndIndex + 1,
                                                       end, minimumCut));
            }
        }
        return minimumCut;
    }

    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};
