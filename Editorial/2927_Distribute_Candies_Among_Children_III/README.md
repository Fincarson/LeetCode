# 2927. Distribute Candies Among Children III

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/distribute-candies-among-children-iii/)  
`Math` `Combinatorics`

**Problem Link:** [LeetCode 2927 - Distribute Candies Among Children III](https://leetcode.com/problems/distribute-candies-among-children-iii/)

## Problem

You are given two positive integers n and limit.

Return the total number of ways to distribute n candies among 3 children such that no child gets more than limit candies.

### Example 1

```text
Input: n = 5, limit = 2
Output: 3
Explanation: There are 3 ways to distribute 5 candies such that no child gets more than 2 candies: (1, 2, 2), (2, 1, 2) and (2, 2, 1).
```

### Example 2

```text
Input: n = 3, limit = 3
Output: 10
Explanation: There are 10 ways to distribute 3 candies such that no child gets more than 3 candies: (0, 0, 3), (0, 1, 2), (0, 2, 1), (0, 3, 0), (1, 0, 2), (1, 1, 1), (1, 2, 0), (2, 0, 1), (2, 1, 0) and (3, 0, 0).
```

## Constraints

- 1 <= n <= 108
- 1 <= limit <= 108

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2927. Distribute Candies Among Children III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Inclusion-Exclusion Principle | C, C++, C#, Go, Java, Python3 |

## Approach: Inclusion-Exclusion Principle

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
long long cal(int x) {
    if (x < 0) {
        return 0;
    }
    return (long long)x * (x - 1) / 2;
}

long long distributeCandies(int n, int limit) {
    return cal(n + 2) - 3 * cal(n - limit + 1) +
           3 * cal(n - (limit + 1) * 2 + 2) - cal(n - 3 * (limit + 1) + 2);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long cal(int x) {
        if (x < 0) {
            return 0;
        }
        return (long)x * (x - 1) / 2;
    }

    long long distributeCandies(int n, int limit) {
        return cal(n + 2) - 3 * cal(n - limit + 1) +
               3 * cal(n - (limit + 1) * 2 + 2) - cal(n - 3 * (limit + 1) + 2);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public long DistributeCandies(int n, int limit) {
        return Cal(n + 2) - 3 * Cal(n - limit + 1) +
               3 * Cal(n - (limit + 1) * 2 + 2) - Cal(n - 3 * (limit + 1) + 2);
    }

    public long Cal(int x) {
        if (x < 0) {
            return 0;
        }
        return (long)x * (x - 1) / 2;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func cal(x int) int64 {
    if x < 0 {
        return 0
    }
    return int64(x) * int64(x - 1) / 2
}

func distributeCandies(n int, limit int) int64 {
    return cal(n + 2) - 3 * cal(n - limit + 1) + 3 * cal(n - (limit + 1) * 2 + 2) - cal(n - 3 * (limit + 1) + 2)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long distributeCandies(int n, int limit) {
        return (
            cal(n + 2) -
            3 * cal(n - limit + 1) +
            3 * cal(n - (limit + 1) * 2 + 2) -
            cal(n - 3 * (limit + 1) + 2)
        );
    }

    public long cal(int x) {
        if (x < 0) {
            return 0;
        }
        return ((long) x * (x - 1)) / 2;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
def cal(x):
    if x < 0:
        return 0
    return x * (x - 1) // 2


class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        return (
            cal(n + 2)
            - 3 * cal(n - limit + 1)
            + 3 * cal(n - (limit + 1) * 2 + 2)
            - cal(n - 3 * (limit + 1) + 2)
        )
```

</details>
