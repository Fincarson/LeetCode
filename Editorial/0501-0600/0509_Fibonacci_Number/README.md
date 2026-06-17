# 509. Fibonacci Number

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/fibonacci-number/)  
`Math` `Dynamic Programming` `Recursion` `Memoization`

**Problem Link:** [LeetCode 509 - Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)

## Problem

The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

```text
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
```

Given n, calculate F(n).

### Example 1

```text
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
```

### Example 2

```text
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
```

### Example 3

```text
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
```

## Constraints

- 0 <= n <= 30

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Split Array into Fibonacci Sequence](https://leetcode.com/problems/split-array-into-fibonacci-sequence/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Length of Longest Fibonacci Subsequence](https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 509. Fibonacci Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | Go, Java, Python |
| Bottom-Up Approach using Tabulation | Go, Java, Python |
| Top-Down Approach using Memoization | Go, Java, Python |
| Iterative Bottom-Up Approach | Go, Java, Python |
| Matrix Exponentiation | Go, Java, Python |
| Math | Go, Java, Python |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>Go</strong></summary>

```go
func fib(N int) int {
    if N <= 1 {
        return N
    }
    return fib(N - 1) + fib(N - 2)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int fib(int N) {
        if (N <= 1) {
            return N;
        }
        return fib(N - 1) + fib(N - 2);
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def fib(self, N: int) -> int:
        if N <= 1:
            return N
        return self.fib(N - 1) + self.fib(N - 2)
```

</details>

<br>

## Approach 2: Bottom-Up Approach using Tabulation

### Implementation

<details>
<summary><strong>Go</strong></summary>

```go
func fib(N int) int {
    if N <= 1 {
        return N
    }
    
    cache := make([]int, N + 1)
    cache[1] = 1
    for i := 2; i <= N; i++ {
        cache[i] = cache[i - 1] + cache[i - 2]
    }
                      
    return cache[N]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int fib(int N) {
        if (N <= 1) {
            return N;
        }
                  
        int[] cache = new int[N + 1];
        cache[1] = 1;
        for (int i = 2; i <= N; i++) {
            cache[i] = cache[i - 1] + cache[i - 2];
        }
    
        return cache[N];
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def fib(self, N: int) -> int:
        if N <= 1:
            return N
        
        cache = [0] * (N + 1)
        cache[1] = 1
        for i in range(2, N + 1):
            cache[i] = cache[i - 1] + cache[i - 2]

        return cache[N]
```

</details>

<br>

## Approach 3: Top-Down Approach using Memoization

### Implementation

<details>
<summary><strong>Go</strong></summary>

```go
var cache = map[int]int{0: 0, 1: 1}

func fib(N int) int {
    if _, ok := cache[N]; ok {
        return cache[N]
    }
    cache[N] = fib(N - 1) + fib(N - 2)
    return cache[N]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Creating a hash map with 0 -> 0 and 1 -> 1 pairs
    private Map<Integer, Integer> cache = new HashMap<>(Map.of(0, 0, 1, 1));

    public int fib(int N) {
        if (cache.containsKey(N)) {
            return cache.get(N);
        }
        cache.put(N, fib(N - 1) + fib(N - 2));
        return cache.get(N);
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    cache = {0: 0, 1: 1}

    def fib(self, N: int) -> int:
        if N in self.cache:
            return self.cache[N]
        self.cache[N] = self.fib(N - 1) + self.fib(N - 2)
        return self.cache[N]
```

</details>

<br>

## Approach 4: Iterative Bottom-Up Approach

### Implementation

<details>
<summary><strong>Go</strong></summary>

```go
func fib(N int) int {
    if N <= 1 {
        return N
    }
    
    current := 0
    prev1 := 1
    prev2 := 0

    for i := 2; i <= N; i++ {
        current = prev1 + prev2
        prev2 = prev1
        prev1 = current
    }
    return current
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int fib(int N) {
        if (N <= 1) {
            return N;
        }

        int current = 0;
        int prev1 = 1;
        int prev2 = 0;

        for (int i = 2; i <= N; i++) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def fib(self, N: int) -> int:
        if (N <= 1):
            return N

        current = 0
        prev1 = 1
        prev2 = 0

        # Since range is exclusive and we want to include N, we need to put N+1.
        for i in range(2, N + 1):
            current = prev1 + prev2
            prev2 = prev1
            prev1 = current
        return current
```

</details>

<br>

## Approach 5: Matrix Exponentiation

### Implementation

<details>
<summary><strong>Go</strong></summary>

```go
func fib(N int) int {
    if N <= 1 {
        return N
    }
    var A = [2][2]int{
        {1, 1},
        {1, 0},
    }
    A = matrixPower(A, N - 1)
    return A[0][0]
}

func matrixPower(A [2][2]int, N int) [2][2]int {
    if N <= 1 {
        return A
    }
    A = matrixPower(A, N / 2)
    A = multiply(A, A)

    var B = [2][2]int{
        {1, 1},
        {1, 0},
    }
    if N % 2 != 0 {
        A = multiply(A, B)
    }

    return A
}

func multiply(A [2][2]int, B [2][2]int) [2][2]int {
    x := A[0][0] * B[0][0] + A[0][1] * B[1][0];
    y := A[0][0] * B[0][1] + A[0][1] * B[1][1];
    z := A[1][0] * B[0][0] + A[1][1] * B[1][0];
    w := A[1][0] * B[0][1] + A[1][1] * B[1][1];

    A[0][0] = x;
    A[0][1] = y;
    A[1][0] = z;
    A[1][1] = w;

    return A
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int fib(int N) {
        if (N <= 1) {
          return N;
        }
        int[][] A = new int[][]{{1, 1}, {1, 0}};
        matrixPower(A, N - 1);

        return A[0][0];
    }

    void matrixPower(int[][] A, int N) {
        if (N <= 1) {
          return;
        }
        matrixPower(A, N / 2);
        multiply(A, A);

        int[][] B = new int[][]{{1, 1}, {1, 0}};
        if (N % 2 != 0) {
            multiply(A, B);
        }
    }

    void multiply(int[][] A, int[][] B) {
        int x = A[0][0] * B[0][0] + A[0][1] * B[1][0];
        int y = A[0][0] * B[0][1] + A[0][1] * B[1][1];
        int z = A[1][0] * B[0][0] + A[1][1] * B[1][0];
        int w = A[1][0] * B[0][1] + A[1][1] * B[1][1];

        A[0][0] = x;
        A[0][1] = y;
        A[1][0] = z;
        A[1][1] = w;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def fib(self, N: int) -> int:
        if (N <= 1):
            return N

        A = [[1, 1], [1, 0]]
        self.matrix_power(A, N - 1)

        return A[0][0]

    def matrix_power(self, A: List[List[int]], N: int):
        if (N <= 1):
            return A

        self.matrix_power(A, N // 2)
        self.multiply(A, A)
        B = [[1, 1], [1, 0]]

        if (N % 2 != 0):
            self.multiply(A, B)

    def multiply(self, A: List[List[int]], B: List[List[int]]) -> None:
        x = A[0][0] * B[0][0] + A[0][1] * B[1][0]
        y = A[0][0] * B[0][1] + A[0][1] * B[1][1]
        z = A[1][0] * B[0][0] + A[1][1] * B[1][0]
        w = A[1][0] * B[0][1] + A[1][1] * B[1][1]

        A[0][0] = x
        A[0][1] = y
        A[1][0] = z
        A[1][1] = w
```

</details>

<br>

## Approach 6: Math

### Implementation

<details>
<summary><strong>Go</strong></summary>

```go
func fib(N int) int {
    var goldenRatio float64 = float64((1 + math.Sqrt(5)) / 2);
    return int(math.Round(math.Pow(goldenRatio, float64(N)) / math.Sqrt(5)));
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int fib(int N) {
        double goldenRatio = (1 + Math.sqrt(5)) / 2;
        return (int) Math.round(Math.pow(goldenRatio, N) / Math.sqrt(5));
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
# Contributed by LeetCode user mereck.
class Solution:
    def fib(self, N: int) -> int:
        golden_ratio = (1 + (5 ** 0.5)) / 2
        return int(round((golden_ratio ** N) / (5 ** 0.5)))
```

</details>
