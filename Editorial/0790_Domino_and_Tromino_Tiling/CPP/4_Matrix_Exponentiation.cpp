class Solution {
public:
    // To avoid confusing point syntax, we use 2d-vector instead
    vector<vector<long>> SQ_MATRIX { // Initialize square matrix
        {1, 1, 2}, 
        {1, 0, 0}, 
        {0, 1, 1},
    };
    int MOD = 1'000'000'007;
    int SIZE = 3; // Width/Lenght of the square matrix
    
    // Return product of 2 square matrices.
    vector<vector<long>> matrixProduct(vector<vector<long>> m1, 
                                       vector<vector<long>> m2) {
        
        // Result matrix `ans` will also be a square matrix with same dimension
        vector<vector<long>> ans = SQ_MATRIX;  
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
    
    // Return answer after n times matrix multiplication.
    int matrixExpo(int n) {  
        vector<vector<long>> cur = SQ_MATRIX;
        for (int i = 1; i < n; ++i) {
            cur = matrixProduct(cur, SQ_MATRIX);
        }
        // The answer will be cur[0][0] * f(2) + cur[0][1] * f(1) + cur[0][2] * p(2) 
        return static_cast<int>((cur[0][0] * 2 + cur[0][1] * 1 + cur[0][2] * 1) % MOD);  
    }
    
    int numTilings(int n) {
        // Handle base cases
        if (n <= 2) {  
            return n;
        } 
        return matrixExpo(n-2);
    }
};
