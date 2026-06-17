# 899. Orderly Queue

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/orderly-queue/)  
`Math` `String` `Sorting`

**Problem Link:** [LeetCode 899 - Orderly Queue](https://leetcode.com/problems/orderly-queue/)

## Problem

You are given a string s and an integer k. You can choose one of the first k letters of s and append it at the end of the string.

Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.

### Example 1

```text
Input: s = "cba", k = 1
Output: "acb"
Explanation:
In the first move, we move the 1st character 'c' to the end, obtaining the string "bac".
In the second move, we move the 1st character 'b' to the end, obtaining the final result "acb".
```

### Example 2

```text
Input: s = "baaca", k = 3
Output: "aaabc"
Explanation:
In the first move, we move the 1st character 'b' to the end, obtaining the string "aacab".
In the second move, we move the 3rd character 'c' to the end, obtaining the final result "aaabc".
```

## Constraints

- 1 <= k <= s.length <= 1000
- s consist of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 899. Orderly Queue

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Mathematical | Java, Python3 |

## Approach 1: Mathematical

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String orderlyQueue(String s, int k) {
        if (k == 1) {
            String ans = s;
            for (int i = 0; i < s.length(); ++i) {
                String temp = s.substring(i) + s.substring(0, i);
                if (temp.compareTo(ans) < 0) {
                    ans = temp;
                }
            }
            return ans;
        } else {
            char[] chars = s.toCharArray();
            Arrays.sort(chars);
            return new String(chars);
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def orderlyQueue(self, s: str, k: int) -> str:
        if k == 1:
            return min(s[i:] + s[:i] for i in range(len(s)))
        else:
            return ''.join(sorted(s))
```

</details>
