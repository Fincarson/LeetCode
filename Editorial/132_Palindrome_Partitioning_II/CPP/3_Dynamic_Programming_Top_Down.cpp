class Solution {
public:
    vector<int> memoCuts;
    vector<vector<optional<bool>>> memoPalindrome;

    int minCut(string s) {
        memoCuts.resize(s.length(), -1);
        memoPalindrome.resize(s.length(),
                              vector<optional<bool>>(s.length(), nullopt));
        return findMinimumCut(s, 0, s.length() - 1, s.length() - 1);
    }

    int findMinimumCut(string &s, int start, int end, int minimumCut) {
        // base case
        if (start == end || isPalindrome(s, start, end)) {
            return 0;
        }

        // check for results in memoCuts
        if (memoCuts[start] != -1) {
            return memoCuts[start];
        }

        for (int currentEndIndex = start; currentEndIndex <= end;
             currentEndIndex++) {
            if (isPalindrome(s, start, currentEndIndex)) {
                minimumCut =
                    min(minimumCut, 1 + findMinimumCut(s, currentEndIndex + 1,
                                                       end, minimumCut));
            }
        }
        return memoCuts[start] = minimumCut;
    }

    bool isPalindrome(string &s, int start, int end) {
        if (start >= end) return true;
        // check for results in memoPalindrome
        if (memoPalindrome[start][end] != nullopt)
            return (memoPalindrome[start][end] == true);
        memoPalindrome[start][end] =
            (s[start] == s[end]) && isPalindrome(s, start + 1, end - 1);
        return (memoPalindrome[start][end] == true);
    }
};
