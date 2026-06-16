# 487. Max Consecutive Ones II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/max-consecutive-ones-ii/)  
`Array` `Dynamic Programming` `Sliding Window`

**Problem Link:** [LeetCode 487 - Max Consecutive Ones II](https://leetcode.com/problems/max-consecutive-ones-ii/)

## Problem

Given a binary array nums, return the maximum number of consecutive 1's in the array if you can flip at most one 0.

### Example 1

```text
Input: nums = [1,0,1,1,0]
Output: 4
Explanation:
- If we flip the first zero, nums becomes [1,1,1,1,0] and we have 4 consecutive ones.
- If we flip the second zero, nums becomes [1,0,1,1,1] and we have 3 consecutive ones.
The max number of consecutive ones is 4.
```

### Example 2

```text
Input: nums = [1,0,1,1,0,1]
Output: 4
Explanation:
- If we flip the first zero, nums becomes [1,1,1,1,0,1] and we have 4 consecutive ones.
- If we flip the second zero, nums becomes [1,0,1,1,1,1] and we have 4 consecutive ones.
The max number of consecutive ones is 4.
```

## Constraints

- 1 <= nums.length <= 105
- nums[i] is either 0 or 1.

Follow up: What if the input numbers come in one by one as an infinite stream? In other words, you can't store all numbers coming from the stream as it's too large to hold in memory. Could you solve it efficiently?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [All Divisions With the Highest Score of a Binary Array](https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 487. Max Consecutive Ones II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java, Python3 |
| Sliding Window | Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int longestSequence = 0;
        for (int left = 0; left < nums.length; left++) {
            int numZeroes = 0;

            //Check every consecutive sequence
            for (int right = left; right < nums.length; right++) {
                // Count how many 0's
                if (nums[right] == 0) {
                    numZeroes += 1;
                }
                // Update answer if it's valid
                if (numZeroes <= 1) {
                    longestSequence = Math.max(longestSequence, right - left + 1);
                }
            }
        }
        return longestSequence;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        longest_sequence = 0
        for left in range(len(nums)):
            num_zeroes = 0
            for right in range(left, len(nums)):   # Check every consecutive sequence
                if num_zeroes == 2:
                    break
                if nums[right] == 0:               # Count how many 0's
                    num_zeroes += 1
                if num_zeroes <= 1:                 # Update answer if it's valid
                    longest_sequence = max(longest_sequence, right - left + 1)
        return longest_sequence
```

</details>

<br>

## Approach 2: Sliding Window

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int longestSequence = 0;
        int left = 0;
        int right = 0;
        int numZeroes = 0;

        // While our window is in bounds
        while (right < nums.length) {

            // Increase numZeroes if the rightmost element is 0
            if (nums[right] == 0) {
                numZeroes++;
            }

            //If our window is invalid, contract our window
            while (numZeroes == 2) {
                if (nums[left] == 0) {
                    numZeroes--;
                }
                left++;
            }

            // Update our longest sequence answer
            longestSequence = Math.max(longestSequence, right - left + 1);

            // Expand our window
            right++;
        }
        return longestSequence;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        longest_sequence = 0
        left, right = 0, 0
        num_zeroes = 0

        while right < len(nums):   # While our window is in bounds
            if nums[right] == 0:    # Increase num_zeroes if the rightmost element is 0
                num_zeroes += 1

            while num_zeroes == 2:   # If our window is invalid, contract our window
                if nums[left] == 0:    
                    num_zeroes -= 1
                left += 1

            longest_sequence = max(longest_sequence, right - left + 1)   # Update our longest sequence answer
            right += 1   # Expand our window

        return longest_sequence
```

</details>
