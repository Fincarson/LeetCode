# 1437. Check If All 1's Are at Least Length K Places Away

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/)  
`Array`

**Problem Link:** [LeetCode 1437 - Check If All 1's Are at Least Length K Places Away](https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/)

## Problem

Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.

### Example 1

```text
Input: nums = [1,0,0,0,1,0,0,1], k = 2
Output: true
Explanation: Each of the 1s are at least 2 places away from each other.
```

### Example 2

```text
Input: nums = [1,0,0,1,0,1], k = 2
Output: false
Explanation: The second 1 and third 1 are only one apart from each other.
```

## Constraints

- 1 <= nums.length <= 105
- 0 <= k <= nums.length
- nums[i] is 0 or 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Task Scheduler II](https://leetcode.com/problems/task-scheduler-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1437. Check If All 1's Are at Least Length K Places Away

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| One Pass + Count | Java, Python3 |
| Bit Manipulation | Java, Python3 |

## Approach 1: One Pass + Count

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        // initialize the counter of zeros to k
        // to pass the first 1 in nums
        int count = k;
        
        for (int num : nums) {
            // if the current integer is 1
            if (num == 1) {
                // check that number of zeros in-between 1s
                // is greater than or equal to k
                if (count < k) {
                    return false;    
                }
                // reinitialize counter
                count = 0;
                
            // if the current integer is 0
            } else {
                // increase the counter
                ++count;    
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
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        # initialize the counter of zeros to k
        # to pass the first 1 in nums
        count = k
        
        for num in nums:
            # if the current integer is 1
            if num == 1:
                # check that number of zeros in-between 1s
                # is greater than or equal to k
                if count < k:
                    return False
                # reinitialize counter
                count = 0
            # if the current integer is 0
            else:
                # increase the counter
                count += 1
                
        return True
```

</details>

<br>

## Approach 2: Bit Manipulation

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
// remove trailing zeros
while ((x & 1) == 0) {
    x = x >> 1;    
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# remove trailing zeros
while x & 1 == 0:
    x = x >> 1
```

</details>
