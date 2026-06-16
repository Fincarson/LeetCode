# 1208. Get Equal Substrings Within Budget

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/get-equal-substrings-within-budget/)  
`String` `Binary Search` `Sliding Window` `Prefix Sum`

**Problem Link:** [LeetCode 1208 - Get Equal Substrings Within Budget](https://leetcode.com/problems/get-equal-substrings-within-budget/)

## Problem

You are given two strings s and t of the same length and an integer maxCost.

You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).

Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.

### Example 1

```text
Input: s = "abcd", t = "bcdf", maxCost = 3
Output: 3
Explanation: "abc" of s can change to "bcd".
That costs 3, so the maximum length is 3.
```

### Example 2

```text
Input: s = "abcd", t = "cdef", maxCost = 3
Output: 1
Explanation: Each character in s costs 2 to change to character in t,  so the maximum length is 1.
```

### Example 3

```text
Input: s = "abcd", t = "acde", maxCost = 0
Output: 1
Explanation: You cannot make any change, so the maximum length is 1.
```

## Constraints

- 1 <= s.length <= 105
- t.length == s.length
- 0 <= maxCost <= 106
- s and t consist of only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Nice Subarray](https://leetcode.com/problems/longest-nice-subarray/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1208. Get Equal Substrings Within Budget

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sliding Window | C++, Java, Python3 |

## Approach: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int N = s.size();

        int maxLen = 0;
        // Starting index of the current substring
        int start = 0;
        // Cost of converting the current substring in s to t
        int currCost = 0;

        for (int i = 0; i < N; i++) {
            // Add the current index to the substring
            currCost += abs(s[i] - t[i]);

            // Remove the indices from the left end till the cost becomes less
            // than or equal to maxCost
            while (currCost > maxCost) {
                currCost -= abs(s[start] - t[start]);
                start++;
            }

            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int equalSubstring(String s, String t, int maxCost) {
        int N = s.length();

        int maxLen = 0;
        // Starting index of the current substring
        int start = 0;
        // Cost of converting the current substring in s to t
        int currCost = 0;

        for (int i = 0; i < N; i++) {
            // Add the current index to the substring
            currCost += Math.abs(s.charAt(i) - t.charAt(i));

            // Remove the indices from the left end till the cost becomes less than or equal to maxCost
            while (currCost > maxCost) {
                currCost -= Math.abs(s.charAt(start) - t.charAt(start));
                start++;
            }

            maxLen = Math.max(maxLen, i - start + 1);
        }

        return maxLen;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        N = len(s)

        max_len = 0
        # Starting index of the current substring
        start = 0
        # Cost of converting the current substring in s to t
        curr_cost = 0

        for i in range(N):
            # Add the current index to the substring
            curr_cost += abs(ord(s[i]) - ord(t[i]))

            # Remove the indices from the left end till the cost becomes less than or equal to maxCost
            while curr_cost > maxCost:
                curr_cost -= abs(ord(s[start]) - ord(t[start]))
                start += 1

            max_len = max(max_len, i - start + 1)

        return max_len
```

</details>
