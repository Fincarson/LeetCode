# 300. Longest Increasing Subsequence

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/longest-increasing-subsequence/)  
`Array` `Binary Search` `Dynamic Programming`

**Problem Link:** [LeetCode 300 - Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)

## Problem

Given an integer array nums, return the length of the longest strictly increasing subsequence.

### Example 1

```text
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
```

### Example 2

```text
Input: nums = [0,1,0,3,2,3]
Output: 4
```

### Example 3

```text
Input: nums = [7,7,7,7,7,7,7]
Output: 1
```

## Constraints

- 1 <= nums.length <= 2500
- -104 <= nums[i] <= 104

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Increasing Triplet Subsequence](https://leetcode.com/problems/increasing-triplet-subsequence/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Number of Longest Increasing Subsequence](https://leetcode.com/problems/number-of-longest-increasing-subsequence/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Number of Removals to Make Mountain Array](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Find the Longest Valid Obstacle Course at Each Position](https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Operations to Make the Array K-Increasing](https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Longest Ideal Subsequence](https://leetcode.com/problems/longest-ideal-subsequence/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Number of Books You Can Take](https://leetcode.com/problems/maximum-number-of-books-you-can-take/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Longest Increasing Subsequence II](https://leetcode.com/problems/longest-increasing-subsequence-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Find the Maximum Length of a Good Subsequence II](https://leetcode.com/problems/find-the-maximum-length-of-a-good-subsequence-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Find the Maximum Length of a Good Subsequence I](https://leetcode.com/problems/find-the-maximum-length-of-a-good-subsequence-i/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find the Maximum Length of Valid Subsequence I](https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find the Maximum Length of Valid Subsequence II](https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Subsequence With Decreasing Adjacent Difference](https://leetcode.com/problems/longest-subsequence-with-decreasing-adjacent-difference/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 300. Longest Increasing Subsequence

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | Java, Python3 |
| Intelligently Build a Subsequence | Java, Python3 |
| Improve With Binary Search | Java, Python3 |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] dp = new int[nums.length];
        Arrays.fill(dp, 1);
        
        for (int i = 1; i < nums.length; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }
        
        int longest = 0;
        for (int c: dp) {
            longest = Math.max(longest, c);
        }
        
        return longest;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [1] * len(nums)
        for i in range(1, len(nums)):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)

        return max(dp)
```

</details>

<br>

## Approach 2: Intelligently Build a Subsequence

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        ArrayList<Integer> sub = new ArrayList<>();
        sub.add(nums[0]);
        
        for (int i = 1; i < nums.length; i++) {
            int num = nums[i];
            if (num > sub.get(sub.size() - 1)) {
                sub.add(num);
            } else {
                // Find the first element in sub that is greater than or equal to num
                int j = 0;
                while (num > sub.get(j)) {
                    j += 1;
                }
                
                sub.set(j, num);
            }
        }
        
        return sub.size();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        sub = [nums[0]]
        
        for num in nums[1:]:
            if num > sub[-1]:
                sub.append(num)
            else:
                # Find the first element in sub that is greater than or equal to num
                i = 0
                while num > sub[i]:
                    i += 1
                sub[i] = num

        return len(sub)
```

</details>

<br>

## Approach 3: Improve With Binary Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        ArrayList<Integer> sub = new ArrayList<>();
        sub.add(nums[0]);
        
        for (int i = 1; i < nums.length; i++) {
            int num = nums[i];
            if (num > sub.get(sub.size() - 1)) {
                sub.add(num);
            } else {
                int j = binarySearch(sub, num);
                sub.set(j, num);
            }
        }
        
        return sub.size();
    }
    
    private int binarySearch(ArrayList<Integer> sub, int num) {
        int left = 0;
        int right = sub.size() - 1;
        int mid = (left + right) / 2;
        
        while (left < right) {
            mid = (left + right) / 2;
            if (sub.get(mid) == num) {
                return mid;
            }
            
            if (sub.get(mid) < num) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        sub = []
        for num in nums:
            i = bisect_left(sub, num)

            # If num is greater than any element in sub
            if i == len(sub):
                sub.append(num)
            
            # Otherwise, replace the first element in sub greater than or equal to num
            else:
                sub[i] = num
        
        return len(sub)
```

</details>
