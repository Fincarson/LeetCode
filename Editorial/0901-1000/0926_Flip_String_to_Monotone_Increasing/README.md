# 926. Flip String to Monotone Increasing

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/flip-string-to-monotone-increasing/)  
`String` `Dynamic Programming`

**Problem Link:** [LeetCode 926 - Flip String to Monotone Increasing](https://leetcode.com/problems/flip-string-to-monotone-increasing/)

## Problem

A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).

You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.

Return the minimum number of flips to make s monotone increasing.

### Example 1

```text
Input: s = "00110"
Output: 1
Explanation: We flip the last digit to get 00111.
```

### Example 2

```text
Input: s = "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.
```

### Example 3

```text
Input: s = "00011000"
Output: 2
Explanation: We flip to get 00000000.
```

## Constraints

- 1 <= s.length <= 105
- s[i] is either '0' or '1'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Cost to Make All Characters Equal](https://leetcode.com/problems/minimum-cost-to-make-all-characters-equal/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 926. Flip String to Monotone Increasing

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Windows | C++, Java, Python3 |
| Dynamic Programming | C++, Java, Python3 |

## Approach 1: Dynamic Windows

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int m = 0;
        for (char c : s) {
            if (c == '0') {
                ++m;
            }
        }
        int ans = m;
        for (char c : s) {
            if (c == '0') {
                ans = min(ans, --m);
            } else {
                ++m;
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minFlipsMonoIncr(String s) {
        int m = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '0') {
                ++m;
            }
        }
        int ans = m;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '0') {
                ans = Math.min(ans, --m);
            } else {
                ++m;
            }
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
    def minFlipsMonoIncr(self, s: str) -> int:
        m = 0
        for c in s:
            if c == '0':
                m += 1
        ans = m
        for c in s:
            if c == '0':
                m -= 1
                ans = min(ans, m)
            else:
                m += 1
        return ans
```

</details>

<br>

## Approach 2: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans = 0, num = 0;
        for (char c : s) {
            if (c == '0') {
                ans = min(num, ans + 1);
            } else {
                ++num;
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minFlipsMonoIncr(String s) {
        int ans = 0, num = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '0') {
                ans = Math.min(num, ans + 1);
            } else {
                ++num;
            }
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
    def minFlipsMonoIncr(self, s: str) -> int:
        ans = 0
        num = 0
        for c in s:
            if c == '0':
                ans = min(num, ans + 1)
            else:
                num += 1
        return ans
```

</details>
