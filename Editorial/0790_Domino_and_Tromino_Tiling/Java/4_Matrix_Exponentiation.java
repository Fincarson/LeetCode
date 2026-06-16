class Solution {
    int MOD = 1_000_000_007;
    long[][] SQ_MATRIX = { // Initialize the square matrix.
            {1, 1, 2},
            {1, 0, 0},
            {0, 1, 1},
    };
    int SIZE = 3; // Width/Length of the square matrix.
    
    /** Return product of 2 square matrices. */
    public long[][] matrixProduct(long[][] m1, long[][] m2) {  
        // Result matrix `ans` will also be a 3x3 square matrix.
        long[][] ans = new long[SIZE][SIZE];  
        for (int row = 0; row < SIZE; ++row) {
            for (int col = 0; col < SIZE; ++col) {
                long curSum = 0;
                for (int k = 0; k < SIZE; ++k) {
                    curSum = (curSum + m1[row][k] * m2[k][col]) % MOD;
                }
                ans[row][col] = curSum;
            }
        }
        return ans;
    }
    
    /** Return answer after `n` times matrix multiplication. */
    public int matrixExpo(int n) {  
        long[][] cur = SQ_MATRIX;
        for (int i = 1; i < n; ++i) {
            cur = matrixProduct(cur, SQ_MATRIX);
        }
        // The answer will be cur[0][0] * f(2) + cur[0][1] * f(1) + cur[0][2] * p(2) 
        return (int) ((cur[0][0] * 2 + cur[0][1] * 1 + cur[0][2] * 1) % MOD);
    }
    
    public int numTilings(int n) {
        // Handle base cases.
        if (n <= 2) { 
            return n;
        } 
        return matrixExpo(n - 2);
    }
}
