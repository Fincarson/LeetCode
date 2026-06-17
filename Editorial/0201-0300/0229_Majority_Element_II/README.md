# 229. Majority Element II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/majority-element-ii/)  
`Array` `Hash Table` `Sorting` `Counting`

**Problem Link:** [LeetCode 229 - Majority Element II](https://leetcode.com/problems/majority-element-ii/)

## Problem

Given an integer array of size n, find all elements that appear more than Ã¢Å’Å  n/3 Ã¢Å’â€¹ times.

### Example 1

```text
Input: nums = [3,2,3]
Output: [3]
```

### Example 2

```text
Input: nums = [1]
Output: [1]
```

### Example 3

```text
Input: nums = [1,2]
Output: [1,2]
```

## Constraints

- 1 <= nums.length <= 5 * 104
- -109 <= nums[i] <= 109

Follow up: Could you solve the problem in linear time and in O(1) space?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Majority Element](https://leetcode.com/problems/majority-element/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Check If a Number Is Majority Element in a Sorted Array](https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Most Frequent Even Element](https://leetcode.com/problems/most-frequent-even-element/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 229. Majority Element II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Boyer-Moore Voting Algorithm | Java, Python3 |

## Approach 1: Boyer-Moore Voting Algorithm

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List < Integer > majorityElement(int[] nums) {

        // 1st pass
        int count1 = 0;
        int count2 = 0;

        Integer candidate1 = null;
        Integer candidate2 = null;

        for (int n: nums) {
            if (candidate1 != null && candidate1 == n) {
                count1++;
            } else if (candidate2 != null && candidate2 == n) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = n;
                count1++;
            } else if (count2 == 0) {
                candidate2 = n;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        // 2nd pass
        List result = new ArrayList <> ();

        count1 = 0;
        count2 = 0;

        for (int n: nums) {
            if (candidate1 != null && n == candidate1) count1++;
            if (candidate2 != null && n == candidate2) count2++;
        }

        int n = nums.length;
        if (count1 > n/3) result.add(candidate1);
        if (count2 > n/3) result.add(candidate2);

        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    def majorityElement(self, nums):
        if not nums:
            return []
        
        # 1st pass
        count1, count2, candidate1, candidate2 = 0, 0, None, None
        for n in nums:
            if candidate1 == n:
                count1 += 1
            elif candidate2 == n:
                count2 += 1
            elif count1 == 0:
                candidate1 = n
                count1 += 1
            elif count2 == 0:
                candidate2 = n
                count2 += 1
            else:
                count1 -= 1
                count2 -= 1
        
        # 2nd pass
        result = []
        for c in [candidate1, candidate2]:
            if nums.count(c) > len(nums)//3:
                result.append(c)

        return result
```

</details>
