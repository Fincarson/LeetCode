# 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/)  
`String` `Greedy`

**Problem Link:** [LeetCode 1689 - Partitioning Into Minimum Number Of Deci-Binary Numbers](https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/)

## Problem

A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.

### Example 1

```text
Input: n = "32"
Output: 3
Explanation: 10 + 11 + 11 = 32
```

### Example 2

```text
Input: n = "82734"
Output: 8
```

### Example 3

```text
Input: n = "27346209830709182346"
Output: 9
```

## Constraints

- 1 <= n.length <= 105
- n consists of only digits.
- n does not contain any leading zeros and represents a positive integer.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Math | C++, Java, Python3 |

## Approach 1: Math

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minPartitions(string n) {
        return *max_element(n.begin(), n.end()) - '0';
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minPartitions(String n) {
        int maximum = 0;
        for (int i = 0; i < n.length(); i++) {
            maximum = Math.max(maximum, n.charAt(i) - '0');
        }
        return maximum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minPartitions(self, n: str) -> int:
        return int(max(n))
```

</details>
