# 665. Non-decreasing Array

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/non-decreasing-array/)  
`Array`

**Problem Link:** [LeetCode 665 - Non-decreasing Array](https://leetcode.com/problems/non-decreasing-array/)

## Problem

Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

### Example 1

```text
Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
```

### Example 2

```text
Input: nums = [4,2,1]
Output: false
Explanation: You cannot get a non-decreasing array by modifying at most one element.
```

## Constraints

- n == nums.length
- 1 <= n <= 104
- -105 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Make Array Non-decreasing or Non-increasing](https://leetcode.com/problems/make-array-non-decreasing-or-non-increasing/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Find Good Days to Rob the Bank](https://leetcode.com/problems/find-good-days-to-rob-the-bank/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count Non-Decreasing Subarrays After K Operations](https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 665. Non-decreasing Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy | Java, Python3 |

## Approach: Greedy

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean checkPossibility(int[] nums) {
        
        int numViolations = 0;
        for (int i = 1; i < nums.length; i++) {
            
            if (nums[i - 1] > nums[i]) {
                
                if (numViolations == 1) {
                    return false;
                }
                
                numViolations++;
                
                if (i < 2 || nums[i - 2] <= nums[i]) {
                    nums[i - 1] = nums[i];
                } else {
                    nums[i] = nums[i - 1];
                }
            }
        }
        
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        
        num_violations = 0
        for i in range(1, len(nums)):
            
            if nums[i - 1] > nums[i]:
                
                if num_violations == 1:
                    return False
                
                num_violations += 1
                
                if i < 2 or nums[i - 2] <= nums[i]:
                    nums[i - 1] = nums[i]
                else:
                    nums[i] = nums[i - 1]
                    
        return True
```

</details>
