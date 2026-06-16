# 790. Domino and Tromino Tiling

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/domino-and-tromino-tiling/)  
`Dynamic Programming`

**Problem Link:** [LeetCode 790 - Domino and Tromino Tiling](https://leetcode.com/problems/domino-and-tromino-tiling/)

## Problem

You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.

Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

### Example 1

```text
Input: n = 3
Output: 5
Explanation: The five different ways are shown above.
```

### Example 2

```text
Input: n = 1
Output: 1
```

## Constraints

- 1 <= n <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 790. Domino and Tromino Tiling

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming (Top-down) | C++, Java, Python3 |
| Dynamic Programming (Bottom-up) | C++, Java, Python3 |
| Dynamic Programming (Bottom-up, space optimization) | C++, Java, Python3 |
| Matrix Exponentiation | C++, Java, Python3 |
| Matrix Exponentiation (time optimization, space/time trade off) | C++, Java, Python3 |
| Math optimization (Fibonacci sequence like) | C++, Java, Python3 |

## Approach 1: Dynamic Programming (Top-down)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int MOD = 1'000'000'007;
    unordered_map<int, long> f_cache;  
    unordered_map<int, long> p_cache;  
    
    long p(int n) {  
        if (p_cache.find(n) != p_cache.end()) {
            return p_cache[n];
        }
        long val;
        if (n == 2) {
            val = 1L;
        } else {
            val = (p(n - 1) + f(n - 2)) % MOD;
        }
        p_cache[n] = val;
        return val;
    };
    
    long f(int n) {  
        if (f_cache.find(n) != f_cache.end()) {
            return f_cache[n];
        }
        long val;
        if (n == 1) {
            val = 1L;
        } else if (n == 2) {
            val = 2L;
        } else {
            val = (f(n - 1) + f(n - 2) + 2 * p(n - 1)) % MOD;
        }
        f_cache[n] = val;
        return val;
    };
    
    int numTilings(int n) {
        return static_cast<int>(f(n));
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int MOD = 1_000_000_007;
    Map<Integer, Long> f_cache = new HashMap<>();  
    Map<Integer, Long> p_cache = new HashMap<>();  

    public long p(int n) { 
        if (p_cache.containsKey(n)) {
            return p_cache.get(n);
        }
        long val;
        if (n == 2) {
            val = 1L;
        } else {
            val = (p(n - 1) + f(n - 2)) % MOD;
        }
        p_cache.put(n, val);
        return val;

    }

    public long f(int n) {  
        if (f_cache.containsKey(n)) {
            return f_cache.get(n);
        }
        long val;
        if (n == 1) {
            val = 1L;
        } else if (n == 2) {
            val = 2L;
        } else {
            val = (f(n - 1) + f(n - 2) + 2 * p(n - 1)) % MOD;
        }
        f_cache.put(n, val);
        return val;
    }

    public int numTilings(int n) {
        return (int) (f(n));  
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numTilings(self, n: int) -> int:
        MOD = 1_000_000_007

        @cache  
        def p(n):  
            if n == 2:
                return 1
            return (p(n - 1) + f(n - 2)) % MOD

        @cache  
        def f(n):  
            if n <= 2:
                return n
            return (f(n - 1) + f(n - 2) + 2 * p(n - 1)) % MOD

        return f(n)
```

</details>

<br>

## Approach 2: Dynamic Programming (Bottom-up)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numTilings(int n) {
        int MOD = 1'000'000'007;
        // handle base case scenarios
        if (n <= 2) {  
            return n;
        }
        // f[k]: number of ways to "fully cover a board" of width k
        long f[n + 1];
        // p[k]: number of ways to "partially cover a board" of width k
        long p[n + 1];
        // initialize f and p with results for the base case scenarios
        f[1] = 1L;
        f[2] = 2L;
        p[2] = 1L;
        for (int k = 3; k < n + 1; ++k) {
            f[k] = (f[k - 1] + f[k - 2] + 2 * p[k - 1]) % MOD;
            p[k] = (p[k - 1] + f[k - 2]) % MOD; 
        }
        return static_cast<int>(f[n]);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numTilings(int n) {
        int MOD = 1_000_000_007;
        // handle base case scenarios
        if (n <= 2) {  
            return n;
        }
        // f[k]: number of ways to "fully cover a board" of width k
        long[] f = new long[n + 1];  
        // p[k]: number of ways to "partially cover a board" of width k
        long[] p = new long[n + 1];  
        // initialize f and p with results for the base case scenarios
        f[1] = 1L;
        f[2] = 2L;
        p[2] = 1L;
        for (int k = 3; k < n + 1; ++k) {
            f[k] = (f[k - 1] + f[k - 2] + 2 * p[k - 1]) % MOD;
            p[k] = (p[k - 1] + f[k - 2]) % MOD;
        }
        return (int) (f[n]);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numTilings(self, n: int) -> int:
        MOD = 1_000_000_007
        
        # handle base case scenarios
        if n <= 2:
            return n

        # f[k]: number of ways to "fully cover a board" of width k
        f = [0] * (n + 1)  
        
        # p[k]: number of ways to "partially cover a board" of width k
        p = [0] * (n + 1)  
        
        # initialize f and p with results for the base case scenarios
        f[1] = 1
        f[2] = 2
        p[2] = 1
        
        for k in range(3, n + 1):
            f[k] = (f[k - 1] + f[k - 2] + 2 * p[k - 1]) % MOD
            p[k] = (p[k - 1] + f[k - 2]) % MOD
        return f[n]
```

</details>

<br>

## Approach 3: Dynamic Programming (Bottom-up, space optimization)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numTilings(int n) {
        int MOD = 1'000'000'007; 
        if (n <= 2) {
            return n;
        }
        long fPrevious = 1L; 
        long fCurrent = 2L; 
        long pCurrent = 1L;
        for (int k = 3; k < n + 1; ++k) {
            long tmp = fCurrent;
            fCurrent = (fCurrent + fPrevious + 2 * pCurrent) % MOD;
            pCurrent = (pCurrent + fPrevious) % MOD;
            fPrevious = tmp;
        }
        return static_cast<int>(fCurrent);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numTilings(int n) {
        int MOD = 1_000_000_007;
        if (n <= 2) {
            return n;
        }
        long fPrevious = 1L;
        long fCurrent = 2L;
        long pCurrent = 1L;
        for (int k = 3; k < n + 1; ++k) {
            long tmp = fCurrent;
            fCurrent = (fCurrent + fPrevious + 2 * pCurrent) % MOD;
            pCurrent = (pCurrent + fPrevious) % MOD;
            fPrevious = tmp;
        }
        return (int) (fCurrent);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numTilings(self, n: int) -> int:
        MOD = 1_000_000_007
        if n <= 2:
            return n
        fPrevious = 1
        fCurrent = 2
        pCurrent = 1
        for k in range(3, n + 1):
            tmp = fCurrent
            fCurrent = (fCurrent + fPrevious + 2 * pCurrent) % MOD
            pCurrent = (pCurrent + fPrevious) % MOD
            fPrevious = tmp
        return fCurrent
```

</details>

<br>

## Approach 4: Matrix Exponentiation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
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
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
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
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numTilings(self, n: int) -> int:
        MOD = 1_000_000_007
        SQ_MATRIX = [[1, 1, 2], [1, 0, 0], [0, 1, 1]] # Initialize square matrix
        SIZE = 3 # Width/Length of square matrix

        def matrix_product(m1, m2):  
            """Return product of 2 square matrices."""
            nonlocal MOD, SIZE
            # Result matrix `ans` will also be a square matrix with same dimensions.
            ans = [[0] * SIZE for _ in range(SIZE)]  
            for row in range(SIZE):
                for col in range(SIZE):
                    cur_sum = 0
                    for k in range(SIZE):
                        cur_sum += (m1[row][k] * m2[k][col]) % MOD
                    ans[row][col] = cur_sum
            return ans

        def matrix_expo(n):  
            """Perform matrix multiplication n times."""
            cur = SQ_MATRIX
            for _ in range(1, n):
                cur = matrix_product(cur, SQ_MATRIX)
            # The answer will be cur[0][0] * f(2) + cur[0][1] * f(1) + cur[0][2] * p(2)
            return (cur[0][0] * 2 + cur[0][1] * 1 + cur[0][2] * 1) % MOD

        # Handle base cases
        if n <= 2:
            return n  
        
        return matrix_expo(n - 2)
```

</details>

<br>

## Approach 5: Matrix Exponentiation (time optimization, space/time trade off)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
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
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
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
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numTilings(self, n: int) -> int:
        MOD = 1_000_000_007
        SQ_MATRIX = [[1, 1, 2], [1, 0, 0], [0, 1, 1]]  # Initialize square matrix
        SIZE = 3  # Width/Length of square matrix

        def matrix_product(m1, m2):  
            """Return product of 2 square matrices."""
            nonlocal MOD, SIZE
            # Result matrix `ans` will also be a square matrix with same dimension
            ans = [[0] * SIZE for _ in range(SIZE)]  
            for row in range(SIZE):
                for col in range(SIZE):
                    cur_sum = 0
                    for k in range(SIZE):
                        cur_sum = (cur_sum + m1[row][k] * m2[k][col]) % MOD
                    ans[row][col] = cur_sum
            return ans

        @cache  
        def matrix_expo(n):
            nonlocal SQ_MATRIX
            if n == 1:  # base case
                return SQ_MATRIX
            elif n % 2:  # If `n` is odd
                return matrix_product(matrix_expo(n - 1), SQ_MATRIX)
            else:  # If `n` is even
                return matrix_product(matrix_expo(n // 2), matrix_expo(n // 2))

        if n <= 2:
            return n

        # The answer will be cur[0][0] * f(2) + cur[0][1] * f(1) + cur[0][2] * p(2)
        ans = matrix_expo(n - 2)[0]
        return (ans[0] * 2 + ans[1] * 1 + ans[2] * 1) % MOD
```

</details>

<br>

## Approach 6: Math optimization (Fibonacci sequence like)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numTilings(int n) {
        int MOD = 1'000'000'007;
        if (n <= 2) {
            return n;
        }
        long fCurrent = 5L;
        long fPrevious = 2L; 
        long fBeforePrevious = 1L; 
        for (int k = 4; k < n + 1; ++k) {
            long tmp = fPrevious;
            fPrevious = fCurrent; 
            fCurrent = (2 * fCurrent + fBeforePrevious) % MOD;
            fBeforePrevious = tmp;
        }
        return static_cast<int>(fCurrent);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numTilings(int n) {
        int MOD = 1_000_000_007;
        if (n <= 2) {
            return n;
        }
        long fCurrent = 5L;
        long fPrevious = 2;
        long fBeforePrevious = 1;
        for (int k = 4; k < n + 1; ++k) {
            long tmp = fPrevious;
            fPrevious = fCurrent;
            fCurrent = (2 * fCurrent + fBeforePrevious) % MOD;
            fBeforePrevious = tmp;
        }
        return (int) (fCurrent % MOD);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numTilings(self, n: int) -> int:
        MOD = 1_000_000_007
        if n <= 2:
            return n
        fCurrent = 5
        fPrevious = 2
        fBeforePrevious = 1
        for k in range(4, n + 1):
            tmp = fPrevious 
            fPrevious = fCurrent
            fCurrent = (2 * fCurrent + fBeforePrevious) % MOD
            fBeforePrevious = tmp
        return fCurrent
```

</details>
