# 338. Counting Bits

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/counting-bits/)  
`Dynamic Programming` `Bit Manipulation`

**Problem Link:** [LeetCode 338 - Counting Bits](https://leetcode.com/problems/counting-bits/)

## Problem

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

### Example 1

```text
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
```

### Example 2

```text
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
```

## Constraints

- 0 <= n <= 105

Follow up:

- It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
- Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Sum of Values at Indices With K Set Bits](https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Find the K-or of an Array](https://leetcode.com/problems/find-the-k-or-of-an-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 338. Counting Bits

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Pop Count | Java, Python3 |
| DP + Most Significant Bit | Java, Python3 |
| DP + Least Significant Bit | Java, Python3 |
| DP + Last Set Bit | Java, Python3 |

## Approach 1: Pop Count

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    private int popCount(int x) {
        int count;
        for (count = 0; x != 0; ++count) {
            x &= x - 1; // zeroing out the least significant nonzero bit
        }
        return count;
    }

    public int[] countBits(int n) {
        int[] ans = new int[n + 1];
        for (int x = 0; x <= n; ++x) {
            ans[x] = popCount(x);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countBits(self, n: int) -> List[int]:
        
        def pop_count(x: int) -> int:
            count = 0
            while x != 0:
                x &= x - 1 # zeroing out the least significant nonzero bit
                count += 1
            return count
            
        ans = [0] * (n + 1)
        for x in range(n + 1):
            ans[x] = pop_count(x)
    
        return ans
```

</details>

<br>

## Approach 2: DP + Most Significant Bit

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int[] countBits(int n) {
        int[] ans = new int[n + 1];
        int x = 0;
        int b = 1;
    
        // [0, b) is calculated
        while (b <= n) {
            // generate [b, 2b) or [b, n) from [0, b)
            while (x < b && x + b <= n) {
                ans[x + b] = ans[x] + 1;
                ++x;
            }                         
            x = 0; // reset x
            b <<= 1; // b = 2b
        }
                  
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countBits(self, n: int) -> List[int]:
        ans = [0] * (n + 1)
        x = 0
        b = 1
        
        # [0, b) is calculated
        while b <= n:
            # generate [b, 2b) or [b, n) from [0, b)
            while x < b and x + b <= n:
                ans[x + b] = ans[x] + 1
                x += 1
            x = 0 # reset x
            b <<= 1 # b = 2b
            
        return ans
```

</details>

<br>

## Approach 3: DP + Least Significant Bit

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int[] countBits(int n) {
        int[] ans = new int[n + 1];
        for (int x = 1; x <= n; ++x) {
            // x / 2 is x >> 1 and x % 2 is x & 1
            ans[x] = ans[x >> 1] + (x & 1); 
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countBits(self, n: int) -> List[int]:
        ans = [0] * (n + 1)
        for x in range(1, n + 1):
            # x // 2 is x >> 1 and x % 2 is x & 1
            ans[x] = ans[x >> 1] + (x & 1) 
        return ans
```

</details>

<br>

## Approach 4: DP + Last Set Bit

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int[] countBits(int num) {
        int[] ans = new int[num + 1];
        for (int x = 1; x <= num; ++x) {
            ans[x] = ans[x & (x - 1)] + 1;
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countBits(self, n: int) -> List[int]:
        ans = [0] * (n + 1)
        for x in range(1, n + 1):
            ans[x] = ans[x & (x - 1)] + 1
        return ans
```

</details>
