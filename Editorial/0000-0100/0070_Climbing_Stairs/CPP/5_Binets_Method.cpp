class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        vector<vector<long long>> A = {{1, 1}, {1, 0}};
        vector<vector<long long>> res = binaryPow(A, n - 1);
        return res[0][0] + res[0][1];
    }

private:
    vector<vector<long long>> binaryPow(vector<vector<long long>> &A, int n) {
        vector<vector<long long>> ret = {{1, 0}, {0, 1}};
        while (n > 0) {
            if (n & 1) ret = multiply(ret, A);
            A = multiply(A, A);
            n >>= 1;
        }
        return ret;
    }
    vector<vector<long long>> multiply(vector<vector<long long>> &A,
                                       vector<vector<long long>> &B) {
        vector<vector<long long>> C(2, vector<long long>(2, 0));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }
};
