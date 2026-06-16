# 1903. Largest Odd Number in String

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/largest-odd-number-in-string/)  
`Math` `String` `Greedy`

**Problem Link:** [LeetCode 1903 - Largest Odd Number in String](https://leetcode.com/problems/largest-odd-number-in-string/)

## Problem

You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.

### Example 1

```text
Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
```

### Example 2

```text
Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".
```

### Example 3

```text
Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.
```

## Constraints

- 1 <= num.length <= 105
- num only consists of digits and does not contain any leading zeros.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Largest 3-Same-Digit Number in String](https://leetcode.com/problems/largest-3-same-digit-number-in-string/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1903. Largest Odd Number in String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Find the Rightmost Odd Digit | C++, Java, Python3 |

## Approach: Find the Rightmost Odd Digit

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) {
                return num.substr(0, i + 1);
            }
        }
        
        return "";
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String largestOddNumber(String num) {
        for (int i = num.length() - 1; i >= 0; i--) {
            if (Character.getNumericValue(num.charAt(i)) % 2 != 0) {
                return num.substring(0, i + 1);
            }
        }
        
        return "";
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestOddNumber(self, num: str) -> str:
        for i in range(len(num) - 1, -1, -1):
            if int(num[i]) % 2 != 0:
                return num[:i + 1]
            
        return ""
```

</details>
