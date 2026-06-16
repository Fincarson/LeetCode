class Solution {
public:
    vector<int> cutsDp;
    vector<vector<bool>> palindromeDp;

    int minCut(string s) {
        cutsDp.resize(s.length());
        palindromeDp.resize(s.length(), vector<bool>(s.length(), false));
        // build the palindrome cutsDp for all susbtrings
        buildPalindromeDp(s, s.length());
        for (int end = 0; end < s.length(); end++) {
            int minimumCut = end;
            for (int start = 0; start <= end; start++) {
                if (palindromeDp[start][end]) {
                    minimumCut =
                        start == 0 ? 0 : min(minimumCut, cutsDp[start - 1] + 1);
                }
            }
            cutsDp[end] = minimumCut;
        }
        return cutsDp[s.length() - 1];
    }

    void buildPalindromeDp(string &s, int n) {
        for (int end = 0; end < s.length(); end++) {
            for (int start = 0; start <= end; start++) {
                if (s[start] == s[end] &&
                    (end - start <= 2 || palindromeDp[start + 1][end - 1])) {
                    palindromeDp[start][end] = true;
                }
            }
        }
    }
};
