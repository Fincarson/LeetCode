class Solution {
public:
    int minCut(string s) {
        vector<int> cutsDp;
        cutsDp.resize(s.length());
        for (int i = 1; i < s.length(); i++) {
            cutsDp[i] = i;
        }
        for (int mid = 0; mid < s.length(); mid++) {
            // check for odd length palindrome around mid index
            findMinimumCuts(mid, mid, cutsDp, s);
            // check for even length palindrome around mid index
            findMinimumCuts(mid - 1, mid, cutsDp, s);
        }
        return cutsDp[s.length() - 1];
    }

    void findMinimumCuts(int startIndex, int endIndex, vector<int> &cutsDp,
                         string s) {
        for (int start = startIndex, end = endIndex;
             start >= 0 && end < s.length() && s[start] == s[end];
             start--, end++) {
            int newCut = start == 0 ? 0 : cutsDp[start - 1] + 1;
            cutsDp[end] = min(cutsDp[end], newCut);
        }
    }
};
