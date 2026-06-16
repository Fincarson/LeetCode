class Solution {
    int MOD = 1_000_000_007;
    Long[][] SQ_MATRIX = {  // Initialize the square matrix
            {1L, 1L, 2L},
            {1L, 0L, 0L},
            {0L, 1L, 1L},
    };
    int SIZE = 3;  // Width/Length of square matrix
    Map<Integer, Long[][]> cache = new HashMap<>();

    /** Return product of 2 square matrices */
    public Long[][] matrixProduct(Long[][] m1, Long[][] m2) {  
        // Result matrix `ans` will also be a square matrix with same dimension
        Long[][] ans = new Long[SIZE][SIZE];  
        for (int row = 0; row < SIZE; ++row) {
            for (int col = 0; col < SIZE; ++col) {
                Long sum = 0L;
                for (int k = 0; k < SIZE; ++k) {
                    sum = (sum + m1[row][k] * m2[k][col]) % MOD;
                }
                ans[row][col] = sum;
            }
        }
        return ans;
    }

    /** Return pow(SQ_MATRIX, n) */
    public Long[][] matrixExpo(int n) {  
        // Use cache is `n` is already calculated
        if (cache.containsKey(n)) {  
            return cache.get(n);
        }
        Long[][] cur;
        if (n == 1) {  // base case
            cur = SQ_MATRIX;
        } else if (n % 2 == 1) {  // When `n` is odd
            cur = matrixProduct(matrixExpo(n - 1), SQ_MATRIX);
        } else {  // When `n` is even
            cur = matrixProduct(matrixExpo(n / 2), matrixExpo(n / 2));
        }
        cache.put(n, cur);
        return cur;
    }

    public int numTilings(int n) {
        if (n <= 2) {  // Handle base cases
            return n;
        }
        // The answer will be cur[0][0] * f(2) + cur[0][1] * f(1) + cur[0][2] * p(2) 
        Long[] ans = matrixExpo(n - 2)[0];
        return (int) ((ans[0] * 2 + ans[1] * 1 + ans[2] * 1) % MOD);
    }
}
