# 1004. Max Consecutive Ones III

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/max-consecutive-ones-iii/)  
`Array` `Binary Search` `Sliding Window` `Prefix Sum`

**Problem Link:** [LeetCode 1004 - Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/)

## Problem

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

### Example 1

```text
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
```

### Example 2

```text
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
```

## Constraints

- 1 <= nums.length <= 105
- nums[i] is either 0 or 1.
- 0 <= k <= nums.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Max Consecutive Ones II](https://leetcode.com/problems/max-consecutive-ones-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Subarray of 1's After Deleting One Element](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximize the Confusion of an Exam](https://leetcode.com/problems/maximize-the-confusion-of-an-exam/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Recolors to Get K Consecutive Black Blocks](https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Longest Nice Subarray](https://leetcode.com/problems/longest-nice-subarray/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Sum of Distinct Subarrays With Length K](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Enemy Forts That Can Be Captured](https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1004. Max Consecutive Ones III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sliding Window | C++, Java, Python3 |

## Approach: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int curr = 0;
        int ans = 0;
        int n = nums.size();
        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) {
                curr++;
            }

            while (curr > k) {
                if (nums[left] == 0) {
                    curr--;
                }

                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int longestOnes(int[] nums, int k) {
        int left = 0;
        int curr = 0;
        int ans = 0;
        for (int right = 0; right < nums.length; right++) {
            if (nums[right] == 0) {
                curr++;
            }

            while (curr > k) {
                if (nums[left] == 0) {
                    curr--;
                }

                left++;
            }

            ans = Math.max(ans, right - left + 1);
        }     

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        left = 0
        curr = 0
        ans = 0
        for right in range(len(nums)):
            if nums[right] == 0:
                curr += 1

            while curr > k:
                if nums[left] == 0:
                    curr -= 1
                left += 1
            
            ans = max(ans, right - left + 1)

        return ans
```

</details>
