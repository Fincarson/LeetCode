class Solution {
public:
    int MOD = 1'000'000'007;
    vector<vector<long>> SQ_MATRIX {  // Initialize square matrix
        {1, 1, 2}, 
        {1, 0, 0}, 
        {0, 1, 1},
    };
    int SIZE = 3;  // Width/Length of square matrix
    unordered_map<int, vector<vector<long>>> cache;
    
    // Return product of 2 square matrices
    vector<vector<long>> matrixProduct(  
        vector<vector<long>> m1, vector<vector<long>> m2) {  
        
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
    
    // Return pow(SQ_MATRIX, n)
    vector<vector<long>> matrixExpo(int n) {  
        if (cache.find(n) != cache.end()) {
            return cache[n];
        }
        vector<vector<long>> cur = SQ_MATRIX;
        if (n == 1) {  // base case
            cur = SQ_MATRIX;
        } else if (n % 2) {  // If `n` is odd
            cur = matrixProduct(matrixExpo(n - 1), SQ_MATRIX);
        } else {  // If `n` is even
            cur = matrixProduct(matrixExpo(n / 2), matrixExpo(n / 2));
        }
        cache[n] = cur;
        return cur;
    }
    
    int numTilings(int n) {
        if (n <= 2) {  // Handle base cases
            return n;
        }
        // The answer will be cur[0][0] * f(2) + cur[0][1] * f(1) + cur[0][2] * p(2) 
        vector<long> ans = matrixExpo(n - 2)[0];          
        return (ans[0] * 2 + ans[1] * 1 + ans[2] * 1) % MOD;
    }
};
