# 1663. Smallest String With A Given Numeric Value

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/)  
`String` `Greedy`

**Problem Link:** [LeetCode 1663 - Smallest String With A Given Numeric Value](https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/)

## Problem

The numeric value of a lowercase character is defined as its position (1-indexed) in the alphabet, so the numeric value of a is 1, the numeric value of b is 2, the numeric value of c is 3, and so on.

The numeric value of a string consisting of lowercase characters is defined as the sum of its characters' numeric values. For example, the numeric value of the string "abe" is equal to 1 + 2 + 5 = 8.

You are given two integers n and k. Return the lexicographically smallest string with length equal to n and numeric value equal to k.

Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, that is, either x is a prefix of y, or if i is the first position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.

### Example 1

```text
Input: n = 3, k = 27
Output: "aay"
Explanation: The numeric value of the string is 1 + 1 + 25 = 27, and it is the smallest string with such a value and length equal to 3.
```

### Example 2

```text
Input: n = 5, k = 73
Output: "aaszz"
```

## Constraints

- 1 <= n <= 105
- n <= k <= 26 * n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1663. Smallest String With A Given Numeric Value

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Build number from left to right | C++, Java |

## Approach 1: Build number from left to right

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string getSmallestString(int n, int k) {
        string result(n, 0);
        for (int position = 0; position < n; position++) {
            int positionsLeft = n - position - 1;
            if (k > positionsLeft * 26) {
                int add = k - (positionsLeft * 26);
                result[position] = ('a' + add - 1);
                k -= add;
            } else {
                result[position] = 'a';
                k--;
            }
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String getSmallestString(int n, int k) {
        char[] result = new char[n];
        for (int position = 0; position < n; position++) {
            int positionsLeft = (n - position - 1);
            if (k > positionsLeft * 26) {
                int add = k - (positionsLeft * 26);
                result[position] = (char) ('a' + add - 1);
                k -= add;
            } else {
                result[position] = 'a';
                k--;
            }
        }
        return new String(result);
    }
}
```

</details>
