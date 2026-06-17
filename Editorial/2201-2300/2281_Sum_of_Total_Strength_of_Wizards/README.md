# 2281. Sum of Total Strength of Wizards

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/sum-of-total-strength-of-wizards/)  
`Array` `Stack` `Monotonic Stack` `Prefix Sum`

**Problem Link:** [LeetCode 2281 - Sum of Total Strength of Wizards](https://leetcode.com/problems/sum-of-total-strength-of-wizards/)

## Problem

As the ruler of a kingdom, you have an army of wizards at your command.

You are given a 0-indexed integer array strength, where strength[i] denotes the strength of the ith wizard. For a contiguous group of wizards (i.e. the wizards' strengths form a subarray of strength), the total strength is defined as the product of the following two values:

- The strength of the weakest wizard in the group.
- The total of all the individual strengths of the wizards in the group.

Return the sum of the total strengths of all contiguous groups of wizards. Since the answer may be very large, return it modulo 109 + 7.

A subarray is a contiguous non-empty sequence of elements within an array.

### Example 1

```text
Input: strength = [1,3,1,2]
Output: 44
Explanation: The following are all the contiguous groups of wizards:
- [1] from [1,3,1,2] has a total strength of min([1]) * sum([1]) = 1 * 1 = 1
- [3] from [1,3,1,2] has a total strength of min([3]) * sum([3]) = 3 * 3 = 9
- [1] from [1,3,1,2] has a total strength of min([1]) * sum([1]) = 1 * 1 = 1
- [2] from [1,3,1,2] has a total strength of min([2]) * sum([2]) = 2 * 2 = 4
- [1,3] from [1,3,1,2] has a total strength of min([1,3]) * sum([1,3]) = 1 * 4 = 4
- [3,1] from [1,3,1,2] has a total strength of min([3,1]) * sum([3,1]) = 1 * 4 = 4
- [1,2] from [1,3,1,2] has a total strength of min([1,2]) * sum([1,2]) = 1 * 3 = 3
- [1,3,1] from [1,3,1,2] has a total strength of min([1,3,1]) * sum([1,3,1]) = 1 * 5 = 5
- [3,1,2] from [1,3,1,2] has a total strength of min([3,1,2]) * sum([3,1,2]) = 1 * 6 = 6
- [1,3,1,2] from [1,3,1,2] has a total strength of min([1,3,1,2]) * sum([1,3,1,2]) = 1 * 7 = 7
The sum of all the total strengths is 1 + 9 + 1 + 4 + 4 + 4 + 3 + 5 + 6 + 7 = 44.
```

### Example 2

```text
Input: strength = [5,4,6]
Output: 213
Explanation: The following are all the contiguous groups of wizards:
- [5] from [5,4,6] has a total strength of min([5]) * sum([5]) = 5 * 5 = 25
- [4] from [5,4,6] has a total strength of min([4]) * sum([4]) = 4 * 4 = 16
- [6] from [5,4,6] has a total strength of min([6]) * sum([6]) = 6 * 6 = 36
- [5,4] from [5,4,6] has a total strength of min([5,4]) * sum([5,4]) = 4 * 9 = 36
- [4,6] from [5,4,6] has a total strength of min([4,6]) * sum([4,6]) = 4 * 10 = 40
- [5,4,6] from [5,4,6] has a total strength of min([5,4,6]) * sum([5,4,6]) = 4 * 15 = 60
The sum of all the total strengths is 25 + 16 + 36 + 36 + 40 + 60 = 213.
```

## Constraints

- 1 <= strength.length <= 105
- 1 <= strength[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Sum of Subarray Minimums](https://leetcode.com/problems/sum-of-subarray-minimums/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Number of Visible People in a Queue](https://leetcode.com/problems/number-of-visible-people-in-a-queue/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Sum of Subarray Ranges](https://leetcode.com/problems/sum-of-subarray-ranges/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2281. Sum of Total Strength of Wizards

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Prefix Sum + Monotonic Stack | Java, Python3 |

## Approach: Prefix Sum + Monotonic Stack

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int totalStrength(int[] strength) {
        int mod = (int)1e9 + 7, n = strength.length;
        
        // Get the first index of the non-larger value to strength[i]'s right.
        Stack<Integer> stack = new Stack<>();
        int rightIndex[] = new int[n];
        Arrays.fill(rightIndex, n);
        for (int i = 0; i < n; ++i) {
            while (!stack.isEmpty() && strength[stack.peek()] >= strength[i]) {
                rightIndex[stack.pop()] = i;
            }
            stack.add(i);
        }
        
        // Get the first index of the smaller value to strength[i]'s left.
        int leftIndex[] = new int[n];
        Arrays.fill(leftIndex, -1);
        stack.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!stack.isEmpty() && strength[stack.peek()] > strength[i])
                leftIndex[stack.pop()] = i;
            stack.add(i);
        }

        // Get the prefix sum of the prefix sum array of strength.
        long answer = 0;
        long[] presumOfPresum = new long[n + 2];
        for (int i = 0; i < n; ++i)
            presumOfPresum[i + 2] = (presumOfPresum[i + 1] + strength[i]) % mod;
        for (int i = 1; i <= n; ++i)
            presumOfPresum[i + 1] = (presumOfPresum[i + 1] + presumOfPresum[i]) % mod;
        
        // For each element in strength, we get the value of R_term - L_term.
        for (int i = 0; i < n; ++i) {
            // Get the left index and the right index.
            int leftBound = leftIndex[i], rightBound = rightIndex[i];

            // Get the leftCount and rightCount (marked as L and R in the previous slides)
            int leftCount = i - leftBound, rightCount = rightBound - i;
            
            // Get posPresum and negPresum.
            long negPresum = (presumOfPresum[i + 1] - presumOfPresum[i - leftCount + 1]) % mod;
            long posPresum = (presumOfPresum[i + rightCount + 1] - presumOfPresum[i + 1]) % mod;

            // The total strength of all subarrays that have strength[i] as the minimum.
            answer = (answer + (posPresum * leftCount - negPresum * rightCount) % mod * strength[i] % mod) % mod;
        }

        return (int)(answer + mod) % mod;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python

class Solution:
    def totalStrength(self, strength: List[int]) -> int:
        mod, n = 10 ** 9 + 7, len(strength)
        
        # Get the first index of the non-larger value to strength[i]'s right.
        right_index = [n] * n
        stack = []
        for i in range(n):
            while stack and strength[stack[-1]] >= strength[i]:
                right_index[stack.pop()] = i
            stack.append(i)

        # Get the first index of the smaller value to strength[i]'s left.
        left_index = [-1] * n
        stack = []
        for i in range(n - 1, -1, -1):
            while stack and strength[stack[-1]] > strength[i]:
                left_index[stack.pop()] = i
            stack.append(i)
            
        # prefix sum of the prefix sum array of strength.
        presum_of_presum =  list(accumulate(accumulate(strength, initial = 0), initial = 0))
        answer = 0
        # For each element in strength, we get the value of R_term - L_term.
        for i in range(n):
            # Get the left index and the right index.
            left_bound = left_index[i]
            right_bound = right_index[i]
            
            # Get the left_count and right_count (marked as L and R in the previous slides)
            left_count = i - left_bound
            right_count = right_bound - i
            
            # Get positive presum and the negative presum.
            neg_presum = (presum_of_presum[i + 1] - presum_of_presum[i - left_count + 1]) % mod
            pos_presum = (presum_of_presum[i + right_count + 1] - presum_of_presum[i + 1]) % mod
            
            # The total strength of all subarrays that have strength[i] as the minimum.
            answer += strength[i] * (pos_presum * left_count - neg_presum * right_count)
            answer %= mod
            
        return answer
```

</details>
