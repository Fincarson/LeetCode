# 354. Russian Doll Envelopes

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/russian-doll-envelopes/)  
`Array` `Binary Search` `Dynamic Programming` `Sorting`

**Problem Link:** [LeetCode 354 - Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes/)

## Problem

You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

### Example 1

```text
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
```

### Example 2

```text
Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
```

## Constraints

- 1 <= envelopes.length <= 105
- envelopes[i].length == 2
- 1 <= wi, hi <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [The Number of Weak Characters in the Game](https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Non-decreasing Subarray From Two Arrays](https://leetcode.com/problems/longest-non-decreasing-subarray-from-two-arrays/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 354. Russian Doll Envelopes

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort + Longest Increasing Subsequence | Java, Python |

## Approach 1: Sort + Longest Increasing Subsequence

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int lengthOfLIS(int[] nums) {
        int[] dp = new int[nums.length];
        int len = 0;
        for (int num : nums) {
            int i = Arrays.binarySearch(dp, 0, len, num);
            if (i < 0) {
                i = -(i + 1);
            }
            dp[i] = num;
            if (i == len) {
                len++;
            }
        }
        return len;
    }

    public int maxEnvelopes(int[][] envelopes) {
        // sort on increasing in first dimension and decreasing in second
        Arrays.sort(envelopes, new Comparator<int[]>() {
            public int compare(int[] arr1, int[] arr2) {
                if (arr1[0] == arr2[0]) {
                    return arr2[1] - arr1[1];
                } else {
                    return arr1[0] - arr2[0];
                }
           }
        });
        // extract the second dimension and run LIS
        int[] secondDim = new int[envelopes.length];
        for (int i = 0; i < envelopes.length; ++i) secondDim[i] = envelopes[i][1];
        return lengthOfLIS(secondDim);
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
from bisect import bisect_left

class Solution:
    def maxEnvelopes(self, arr: List[List[int]]) -> int:
        # sort increasing in first dimension and decreasing on second
        arr.sort(key=lambda x: (x[0], -x[1]))

        def lis(nums):
            dp = []
            for i in range(len(nums)):
                idx = bisect_left(dp, nums[i])
                if idx == len(dp):
                    dp.append(nums[i])
                else:
                    dp[idx] = nums[i]
            return len(dp)
        # extract the second dimension and run the LIS
        return lis([i[1] for i in arr])
```

</details>
