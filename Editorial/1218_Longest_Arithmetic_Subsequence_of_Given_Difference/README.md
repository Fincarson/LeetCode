# 1218. Longest Arithmetic Subsequence of Given Difference

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/)  
`Array` `Hash Table` `Dynamic Programming`

**Problem Link:** [LeetCode 1218 - Longest Arithmetic Subsequence of Given Difference](https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/)

## Problem

Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.

### Example 1

```text
Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].
```

### Example 2

```text
Input: arr = [1,3,5,7], difference = 1
Output: 1
Explanation: The longest arithmetic subsequence is any single element.
```

### Example 3

```text
Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].
```

## Constraints

- 1 <= arr.length <= 105
- -104 <= arr[i], difference <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Destroy Sequential Targets](https://leetcode.com/problems/destroy-sequential-targets/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1218. Longest Arithmetic Subsequence of Given Difference

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Dynamic Programming | C++, Java, Python3 |

## Approach: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int answer = 1;
        
        for (int a : arr) {
            int beforeA = dp.count(a - difference) ? dp[a - difference] : 0;
            dp[a] = beforeA + 1;
            answer = max(answer, dp[a]);
        }
        
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int longestSubsequence(int[] arr, int difference) {
        Map<Integer, Integer> dp = new HashMap<>();
        int answer = 1;
        
        for (int a : arr) {
            int beforeA = dp.getOrDefault(a - difference, 0);
            dp.put(a, beforeA + 1);
            answer = Math.max(answer, dp.get(a));
        }
        
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        dp = {}
        answer = 1
        for a in arr:
            before_a = dp.get(a - difference, 0)
            dp[a] = before_a + 1
            answer = max(answer, dp[a])
            
        return answer
```

</details>
