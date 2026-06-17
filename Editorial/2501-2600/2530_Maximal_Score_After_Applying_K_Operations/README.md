# 2530. Maximal Score After Applying K Operations

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximal-score-after-applying-k-operations/)  
`Array` `Greedy` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 2530 - Maximal Score After Applying K Operations](https://leetcode.com/problems/maximal-score-after-applying-k-operations/)

## Problem

You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.

In one operation:

Return the maximum possible score you can attain after applying exactly k operations.

The ceiling function ceil(val) is the least integer greater than or equal to val.

### Example 1

```text
Input: nums = [10,10,10,10,10], k = 5
Output: 50
Explanation: Apply the operation to each array element exactly once. The final score is 10 + 10 + 10 + 10 + 10 = 50.
```

### Example 2

```text
Input: nums = [1,10,3,3,3], k = 3
Output: 17
Explanation: You can do the following operations:
Operation 1: Select i = 1, so nums becomes [1,4,3,3,3]. Your score increases by 10.
Operation 2: Select i = 1, so nums becomes [1,2,3,3,3]. Your score increases by 4.
Operation 3: Select i = 2, so nums becomes [1,2,1,3,3]. Your score increases by 3.
The final score is 10 + 4 + 3 = 17.
```

## Constraints

- 1 <= nums.length, k <= 105
- 1 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Remove Stones to Minimize the Total](https://leetcode.com/problems/remove-stones-to-minimize-the-total/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2530. Maximal Score After Applying K Operations

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach : Priority Queue | Python3 |

## Approach : Priority Queue

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        max_heap = [-x for x in sorted(nums, reverse=True)[:k]]
        ans = 0

        for _ in range(k):
            max_element = heapq.heappop(max_heap)
            ans -= max_element
            heapq.heappush(max_heap, max_element // 3)
        
        return ans
```

</details>
