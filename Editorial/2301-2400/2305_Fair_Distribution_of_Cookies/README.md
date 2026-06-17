# 2305. Fair Distribution of Cookies

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/fair-distribution-of-cookies/)  
`Array` `Dynamic Programming` `Backtracking` `Bit Manipulation` `Bitmask`

**Problem Link:** [LeetCode 2305 - Fair Distribution of Cookies](https://leetcode.com/problems/fair-distribution-of-cookies/)

## Problem

You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag. You are also given an integer k that denotes the number of children to distribute all the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.

The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.

Return the minimum unfairness of all distributions.

### Example 1

```text
Input: cookies = [8,15,10,20,8], k = 2
Output: 31
Explanation: One optimal distribution is [8,15,8] and [10,20]
- The 1st child receives [8,15,8] which has a total of 8 + 15 + 8 = 31 cookies.
- The 2nd child receives [10,20] which has a total of 10 + 20 = 30 cookies.
The unfairness of the distribution is max(31,30) = 31.
It can be shown that there is no distribution with an unfairness less than 31.
```

### Example 2

```text
Input: cookies = [6,1,3,2,2,4,1,2], k = 3
Output: 7
Explanation: One optimal distribution is [6,1], [3,2,2], and [4,1,2]
- The 1st child receives [6,1] which has a total of 6 + 1 = 7 cookies.
- The 2nd child receives [3,2,2] which has a total of 3 + 2 + 2 = 7 cookies.
- The 3rd child receives [4,1,2] which has a total of 4 + 1 + 2 = 7 cookies.
The unfairness of the distribution is max(7,7,7) = 7.
It can be shown that there is no distribution with an unfairness less than 7.
```

## Constraints

- 2 <= cookies.length <= 8
- 1 <= cookies[i] <= 105
- 2 <= k <= cookies.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Split Array with Equal Sum](https://leetcode.com/problems/split-array-with-equal-sum/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Partition to K Equal Sum Subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum XOR Sum of Two Arrays](https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [The Number of Good Subsets](https://leetcode.com/problems/the-number-of-good-subsets/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Minimum Number of Work Sessions to Finish the Tasks](https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Partition Array Into Two Arrays to Minimize Sum Difference](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Maximum Rows Covered by Columns](https://leetcode.com/problems/maximum-rows-covered-by-columns/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Distribute Money to Maximum Children](https://leetcode.com/problems/distribute-money-to-maximum-children/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2305. Fair Distribution of Cookies

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Backtracking | C++, Java, Python3 |

## Approach: Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int dfs(int i, vector<int>& distribute, vector<int>& cookies, int k, int zeroCount) {
        // If there are not enough cookies remaining, return INT_MAX 
        // as it leads to an invalid distribution.
        if (cookies.size() - i < zeroCount) {
            return INT_MAX;
        }

        // After distributing all cookies, return the unfairness of this
        // distribution.
        if (i == cookies.size()) {
            return *max_element(distribute.begin(), distribute.end());
        }

        // Try to distribute the i-th cookie to each child, and update answer
        // as the minimum unfairness in these distributions.
        int answer = INT_MAX;
        for (int j = 0; j < k; ++j) {
            zeroCount -= distribute[j] == 0 ? 1 : 0;
            distribute[j] += cookies[i];
            
            // Recursively distribute the next cookie.
            answer = min(answer, dfs(i + 1, distribute, cookies, k, zeroCount)); 
            
            distribute[j] -= cookies[i];
            zeroCount += distribute[j] == 0 ? 1 : 0;
        }
        
        return answer;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> distribute(k, 0);

        return dfs(0, distribute, cookies, k, k);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int dfs(int i, int[] distribute, int[] cookies, int k, int zeroCount) {
        // If there are not enough cookies remaining, return Integer.MAX_VALUE
        // as it leads to an invalid distribution.
        if (cookies.length - i < zeroCount) {
            return Integer.MAX_VALUE;   
        }

        // After distributing all cookies, return the unfairness of this
        // distribution.
        if (i == cookies.length) {
            int unfairness = Integer.MIN_VALUE;
            for (int value : distribute) {
                unfairness = Math.max(unfairness, value);
            }
            return unfairness;
        }
        
        // Try to distribute the i-th cookie to each child, and update answer
        // as the minimum unfairness in these distributions.
        int answer = Integer.MAX_VALUE;
        for (int j = 0; j < k; ++j) {
            zeroCount -= distribute[j] == 0 ? 1 : 0;
            distribute[j] += cookies[i];
            
            // Recursively distribute the next cookie.
            answer = Math.min(answer, dfs(i + 1, distribute, cookies, k, zeroCount));
            
            distribute[j] -= cookies[i];
            zeroCount += distribute[j] == 0 ? 1 : 0;
        }
        
        return answer;
    }
    
    public int distributeCookies(int[] cookies, int k) {
        int[] distribute = new int[k];
        
        return dfs(0, distribute, cookies, k, k);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        cur = [0] * k
        n = len(cookies)

        def dfs(i, zero_count):
            # If there are not enough cookies remaining, return `float('inf')` 
            # as it leads to an invalid distribution.
            if n - i < zero_count:
                return float('inf')
            
            # After distributing all cookies, return the unfairness of this
            # distribution.
            if i == n:
                return max(cur)
            
            # Try to distribute the i-th cookie to each child, and update answer
            # as the minimum unfairness in these distributions.
            answer = float('inf')
            for j in range(k):
                zero_count -= int(cur[j] == 0)
                cur[j] += cookies[i]
                
                # Recursively distribute the next cookie.
                answer = min(answer, dfs(i + 1, zero_count))
                
                cur[j] -= cookies[i]
                zero_count += int(cur[j] == 0)
            
            return answer
        
        return dfs(0, k)
```

</details>
