# 485. Max Consecutive Ones

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/max-consecutive-ones/)  
`Array`

**Problem Link:** [LeetCode 485 - Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/)

## Problem

Given a binary array nums, return the maximum number of consecutive 1's in the array.

### Example 1

```text
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
```

### Example 2

```text
Input: nums = [1,0,1,1,0,1]
Output: 2
```

## Constraints

- 1 <= nums.length <= 105
- nums[i] is either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Max Consecutive Ones II](https://leetcode.com/problems/max-consecutive-ones-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Consecutive Characters](https://leetcode.com/problems/consecutive-characters/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Longer Contiguous Segments of Ones than Zeros](https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Length of the Longest Alphabetical Continuous Substring](https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Enemy Forts That Can Be Captured](https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 485. Max Consecutive Ones

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: One pass | Java, Python |

## Approach: One pass

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int findMaxConsecutiveOnes(int[] nums) {
    int count = 0;
    int maxCount = 0;
    for(int i = 0; i < nums.length; i++) {
      if(nums[i] == 1) {
        // Increment the count of 1's by one.
        count += 1;
      } else {
        // Find the maximum till now.
        maxCount = Math.max(maxCount, count);
        // Reset count of 1.
        count = 0;
      }
    }
    return Math.max(maxCount, count);
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        count = max_count = 0
        for num in nums:
            if num == 1:
                # Increment the count of 1's by one.
                count += 1
            else:
                # Find the maximum till now.
                max_count = max(max_count, count)
                # Reset count of 1.
                count = 0
        return max(max_count, count)
```

</details>
