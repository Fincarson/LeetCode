# 1685. Sum of Absolute Differences in a Sorted Array

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/)  
`Array` `Math` `Prefix Sum`

**Problem Link:** [LeetCode 1685 - Sum of Absolute Differences in a Sorted Array](https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/)

## Problem

You are given an integer array nums sorted in non-decreasing order.

Build and return an integer array result with the same length as nums such that result[i] is equal to the summation of absolute differences between nums[i] and all the other elements in the array.

In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).

### Example 1

```text
Input: nums = [2,3,5]
Output: [4,3,5]
Explanation: Assuming the arrays are 0-indexed, then
result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4,
result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3,
result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5.
```

### Example 2

```text
Input: nums = [1,4,6,8,10]
Output: [24,15,13,15,21]
```

## Constraints

- 2 <= nums.length <= 105
- 1 <= nums[i] <= nums[i + 1] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1685. Sum of Absolute Differences in a Sorted Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Prefix Sum | C++, Java, Python3 |
| Calculating Prefix Sum on the Fly | C++, Java, Python3 |

## Approach 1: Prefix Sum

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix = {nums[0]};
        for (int i = 1; i < n; i++) {
            prefix.push_back(prefix[i - 1] + nums[i]);
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int leftSum = prefix[i] - nums[i];
            int rightSum = prefix[n - 1] - prefix[i];
            
            int leftCount = i;
            int rightCount = n - 1 - i;
            
            int leftTotal = leftCount * nums[i] - leftSum;
            int rightTotal = rightSum - rightCount * nums[i];
            
            ans.push_back(leftTotal + rightTotal);
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
    public int[] getSumAbsoluteDifferences(int[] nums) {
        int n = nums.length;
        int[] prefix = new int[n];
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            int leftSum = prefix[i] - nums[i];
            int rightSum = prefix[n - 1] - prefix[i];
            
            int leftCount = i;
            int rightCount = n - 1 - i;
            
            int leftTotal = leftCount * nums[i] - leftSum;
            int rightTotal = rightSum - rightCount * nums[i];
            
            ans[i] = leftTotal + rightTotal;
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
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix = [nums[0]]
        for i in range(1, n):
            prefix.append(prefix[-1] + nums[i])
        
        ans = []
        for i in range(len(nums)):
            left_sum = prefix[i] - nums[i]
            right_sum = prefix[-1] - prefix[i]
            
            left_count = i
            right_count = n - 1 - i
            
            left_total = left_count * nums[i] - left_sum
            right_total = right_sum - right_count * nums[i]

            ans.append(left_total + right_total)
        
        return ans
```

</details>

<br>

## Approach 2: Calculating Prefix Sum on the Fly

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        int leftSum = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int rightSum = totalSum - leftSum - nums[i];
            
            int leftCount = i;
            int rightCount = n - 1 - i;
            
            int leftTotal = leftCount * nums[i] - leftSum;
            int rightTotal = rightSum - rightCount * nums[i];
            
            ans.push_back(leftTotal + rightTotal);
            leftSum += nums[i];
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
    public int[] getSumAbsoluteDifferences(int[] nums) {
        int n = nums.length;
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int leftSum = 0;
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            int rightSum = totalSum - leftSum - nums[i];
            
            int leftCount = i;
            int rightCount = n - 1 - i;
            
            int leftTotal = leftCount * nums[i] - leftSum;
            int rightTotal = rightSum - rightCount * nums[i];
            
            ans[i] = leftTotal + rightTotal;
            leftSum += nums[i];
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
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        n = len(nums)
        total_sum = sum(nums)
        left_sum = 0
        ans = []

        for i in range(len(nums)):
            right_sum = total_sum - left_sum - nums[i]
            
            left_count = i
            right_count = n - 1 - i
            
            left_total = left_count * nums[i] - left_sum
            right_total = right_sum - right_count * nums[i]

            ans.append(left_total + right_total)
            left_sum += nums[i]
        
        return ans
```

</details>
