# 96. Unique Binary Search Trees

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/unique-binary-search-trees/)  
`Math` `Dynamic Programming` `Tree` `Binary Search Tree` `Binary Tree`

**Problem Link:** [LeetCode 96 - Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/)

## Problem

Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

### Example 1

```text
Input: n = 3
Output: 5
```

### Example 2

```text
Input: n = 1
Output: 1
```

## Constraints

- 1 <= n <= 19

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Unique Binary Search Trees II](https://leetcode.com/problems/unique-binary-search-trees-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 96. Unique Binary Search Trees

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Mathematical Deduction | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// C Solution
int numTrees(int n) {
    int* G = (int*)calloc(n + 1, sizeof(int));
    G[0] = 1;
    G[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            G[i] += G[j - 1] * G[i - j];
        }
    }
    int result = G[n];
    free(G);
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
// C++ Solution
class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
// C# Solution

public class Solution {
    public int NumTrees(int n) {
        int[] G = new int[n + 1];
        G[0] = 1;
        G[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                G[i] += G[j - 1] * G[i - j];
            }
        }

        return G[n];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// GoSolution
func numTrees(n int) int {
    G := make([]int, n+1)
    G[0] = 1
    G[1] = 1
    for i := 2; i <= n; i++ {
        for j := 1; j <= i; j++ {
            G[i] += G[j-1] * G[i-j]
        }
    }
    return G[n]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int numTrees(int n) {
        int[] G = new int[n + 1];
        G[0] = 1;
        G[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// JavaScript Solution
var numTrees = function (n) {
    let G = new Array(n + 1).fill(0);
    G[0] = 1;
    G[1] = 1;
    for (let i = 2; i <= n; i++) {
        for (let j = 1; j <= i; j++) {
            G[i] += G[j - 1] * G[i - j];
        }
    }
    return G[n];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numTrees(self, n: int) -> int:
        G = [0] * (n + 1)
        G[0], G[1] = 1, 1

        for i in range(2, n + 1):
            for j in range(1, i + 1):
                G[i] += G[j - 1] * G[i - j]

        return G[n]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
// TypeScript Solution
function numTrees(n: number): number {
    let G: number[] = Array(n + 1).fill(0);
    G[0] = 1;
    G[1] = 1;
    for (let i = 2; i <= n; i++) {
        for (let j = 1; j <= i; j++) {
            G[i] += G[j - 1] * G[i - j];
        }
    }
    return G[n];
}
```

</details>

<br>

## Approach 2: Mathematical Deduction

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Note: we should use long long here instead of int, otherwise overflow
int numTrees(int n) {
    long long C = 1;
    for (int i = 0; i < n; ++i) {
        C = C * 2 * (2 * i + 1) / (i + 2);
    }
    return (int)C;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numTrees(int n) {
        // Note: we should use long long here instead of int, otherwise overflow
        long long C = 1;
        for (int i = 0; i < n; ++i) {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)C;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int NumTrees(int n) {
        // Note: we should use long here instead of int, otherwise overflow
        long C = 1;
        for (int i = 0; i < n; ++i) {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }

        return (int)C;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func numTrees(n int) int {
    // Note: we should use int64 here instead of int, otherwise overflow
    var C int64 = 1
    for i := 0; i < n; i++ {
        C = C * 2 * int64(2*i+1) / int64(i+2)
    }
    return int(C)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numTrees(int n) {
        // Note: we should use long here instead of int, otherwise overflow
        long C = 1;
        for (int i = 0; i < n; ++i) {
            C = (C * 2 * (2 * i + 1)) / (i + 2);
        }
        return (int) C;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numTrees = function (n) {
    // Note: we should use BigInt here instead of number, otherwise overflow
    let C = BigInt(1);
    for (let i = 0; i < n; ++i) {
        C = (C * BigInt(2) * BigInt(2 * i + 1)) / BigInt(i + 2);
    }
    return Number(C);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def numTrees(self, n: int) -> int:
        C = 1
        for i in range(0, n):
            C = C * 2 * (2 * i + 1) / (i + 2)
        return int(C)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function numTrees(n: number): number {
    // Note: we should use BigInt here instead of number, otherwise overflow
    let C = BigInt(1);
    for (let i = 0; i < n; ++i) {
        C = (C * BigInt(2) * BigInt(2 * i + 1)) / BigInt(i + 2);
    }
    return Number(C);
}
```

</details>
