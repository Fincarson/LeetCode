# 1758. Minimum Changes To Make Alternating Binary String

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/)  
`String`

**Problem Link:** [LeetCode 1758 - Minimum Changes To Make Alternating Binary String](https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/)

## Problem

You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.

The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.

Return the minimum number of operations needed to make s alternating.

### Example 1

```text
Input: s = "0100"
Output: 1
Explanation: If you change the last character to '1', s will be "0101", which is alternating.
```

### Example 2

```text
Input: s = "10"
Output: 0
Explanation: s is already alternating.
```

### Example 3

```text
Input: s = "1111"
Output: 2
Explanation: You need two operations to reach "0101" or "1010".
```

## Constraints

- 1 <= s.length <= 104
- s[i] is either '0' or '1'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove Adjacent Almost-Equal Characters](https://leetcode.com/problems/remove-adjacent-almost-equal-characters/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1758. Minimum Changes To Make Alternating Binary String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Start with Zero or Start with One | C++, Java, Python3 |
| Only Check One | C++, Java, Python3 |

## Approach 1: Start with Zero or Start with One

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minOperations(string s) {
        int start0 = 0;
        int start1 = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                if (s[i] == '0') {
                    start1++;
                } else {
                    start0++;
                }
            } else {
                if (s[i] == '1') {
                    start1++;
                } else {
                    start0++;
                }
            }
        }
        
        return min(start0, start1);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minOperations(String s) {
        int start0 = 0;
        int start1 = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) {
                if (s.charAt(i) == '0') {
                    start1++;
                } else {
                    start0++;
                }
            } else {
                if (s.charAt(i) == '1') {
                    start1++;
                } else {
                    start0++;
                }
            }
        }
        
        return Math.min(start0, start1);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minOperations(self, s: str) -> int:
        start0 = 0
        start1 = 0
        
        for i in range(len(s)):
            if i % 2 == 0:
                if s[i] == "0":
                    start1 += 1
                else:
                    start0 += 1
            else:
                if s[i] == "1":
                    start1 += 1
                else:
                    start0 += 1
        
        return min(start0, start1)
```

</details>

<br>

## Approach 2: Only Check One

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minOperations(string s) {
        int start0 = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                if (s[i] == '1') {
                    start0++;
                }
            } else {
                if (s[i] == '0') {
                    start0++;
                }
            }
        }
        
        return min(start0, (int) s.size() - start0);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minOperations(String s) {
        int start0 = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) {
                if (s.charAt(i) == '1') {
                    start0++;
                }
            } else {
                if (s.charAt(i) == '0') {
                    start0++;
                }
            }
        }
        
        return Math.min(start0, s.length() - start0);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minOperations(self, s: str) -> int:
        start0 = 0
        
        for i in range(len(s)):
            if i % 2 == 0:
                if s[i] == "1":
                    start0 += 1
            else:
                if s[i] == "0":
                    start0 += 1
        
        return min(start0, len(s) - start0)
```

</details>
