# 1759. Count Number of Homogenous Substrings

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-number-of-homogenous-substrings/)  
`Math` `String`

**Problem Link:** [LeetCode 1759 - Count Number of Homogenous Substrings](https://leetcode.com/problems/count-number-of-homogenous-substrings/)

## Problem

Given a string s, return the number of homogenous substrings of s. Since the answer may be too large, return it modulo 109 + 7.

A string is homogenous if all the characters of the string are the same.

A substring is a contiguous sequence of characters within a string.

### Example 1

```text
Input: s = "abbcccaa"
Output: 13
Explanation: The homogenous substrings are listed as below:
"a"   appears 3 times.
"aa"  appears 1 time.
"b"   appears 2 times.
"bb"  appears 1 time.
"c"   appears 3 times.
"cc"  appears 2 times.
"ccc" appears 1 time.
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.
```

### Example 2

```text
Input: s = "xy"
Output: 2
Explanation: The homogenous substrings are "x" and "y".
```

### Example 3

```text
Input: s = "zzzzz"
Output: 15
```

## Constraints

- 1 <= s.length <= 105
- s consists of lowercase letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Consecutive Characters](https://leetcode.com/problems/consecutive-characters/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Number of Substrings With Only 1s](https://leetcode.com/problems/number-of-substrings-with-only-1s/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Sum of Subarray Ranges](https://leetcode.com/problems/sum-of-subarray-ranges/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count the Number of Good Subarrays](https://leetcode.com/problems/count-the-number-of-good-subarrays/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1759. Count Number of Homogenous Substrings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Counting Streaks | C++, Java, Python3 |

## Approach: Counting Streaks

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countHomogenous(string s) {
        int ans = 0;
        int currStreak = 0;
        int MOD = 1e9 + 7;
        
        for (int i = 0; i < s.size(); i++) {
            if (i == 0 || s[i] == s[i - 1]) {
                currStreak++;
            } else {
                currStreak = 1;
            }
            
            ans = (ans + currStreak) % MOD;
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
    public int countHomogenous(String s) {
        int ans = 0;
        int currStreak = 0;
        int MOD = (int) 1e9 + 7;
        
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 || s.charAt(i) == s.charAt(i - 1)) {
                currStreak++;
            } else {
                currStreak = 1;
            }
            
            ans = (ans + currStreak) % MOD;
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
    def countHomogenous(self, s: str) -> int:
        ans = 0
        curr_streak = 0
        MOD = 10 ** 9 + 7

        for i in range(len(s)):
            if i == 0 or s[i] == s[i - 1]:
                curr_streak += 1
            else:
                curr_streak = 1
            
            ans = (ans + curr_streak) % MOD
        
        return ans
```

</details>
