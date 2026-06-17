class Solution {
public:
    int maxTurbulenceSize(std::vector<int>& A) {
        int N = A.size();
        if (N < 2) return N;

        int ans = 1;
        int anchor = 0;

        auto compare = [&](int x, int y) {
            if (x < y) return -1;
            if (x > y) return 1;
            return 0;
        };

        for (int i = 1; i < N; ++i) {
            int c = compare(A[i - 1], A[i]);
            if (c == 0) {
                anchor = i;
            } else {
                if (i == N - 1 || c * compare(A[i], A[i + 1]) != -1) {
                    ans = std::max(ans, i - anchor + 1);
                    anchor = i;
                }
            }
        }

        return ans;
    }
};
