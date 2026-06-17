class Solution {
public:
    vector<int> diStringMatch(string s) {
        int N = s.length();
        int lo = 0, hi = N;
        vector<int> ans(N + 1);

        for (int i = 0; i < N; ++i) {
            if (s[i] == 'I') {
                ans[i] = lo++;
            } else {
                ans[i] = hi--;
            }
        }

        ans[N] = lo;
        return ans;
    }
};
