# 2104. Sum of Subarray Ranges

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/sum-of-subarray-ranges/)  
`Array` `Stack` `Monotonic Stack`

**Problem Link:** [LeetCode 2104 - Sum of Subarray Ranges](https://leetcode.com/problems/sum-of-subarray-ranges/)

## Problem

You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

### Example 1

```text
Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
```

### Example 2

```text
Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
```

### Example 3

```text
Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.
```

## Constraints

- 1 <= nums.length <= 1000
- -109 <= nums[i] <= 109

Follow-up: Could you find a solution with O(n) time complexity?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Sum of Subarray Minimums](https://leetcode.com/problems/sum-of-subarray-minimums/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Number of Visible People in a Queue](https://leetcode.com/problems/number-of-visible-people-in-a-queue/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Count Number of Homogenous Substrings](https://leetcode.com/problems/count-number-of-homogenous-substrings/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Sum of Total Strength of Wizards](https://leetcode.com/problems/sum-of-total-strength-of-wizards/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2104. Sum of Subarray Ranges

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Loops | C++, Java, Python3 |
| Monotonic Stack | C++, Java, Python3 |

## Approach 1: Two Loops

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = int(nums.size());
        long long answer = 0;

        for (int left = 0; left < n; ++left) {
            int minVal = nums[left], maxVal = nums[left];
            for (int right = left; right < n; ++right) {
                maxVal = max(maxVal, nums[right]);
                minVal = min(minVal, nums[right]);
                answer += maxVal - minVal;
            }
        }

        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long subArrayRanges(int[] nums) {
        int n = nums.length;
        long answer = 0;

        for (int left = 0; left < n; ++left) {
            int minVal = nums[left], maxVal = nums[left];
            for (int right = left; right < n; ++right) {
                minVal = Math.min(minVal, nums[right]);
                maxVal = Math.max(maxVal, nums[right]);
                answer += maxVal - minVal;
            }
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        n = len(nums)
        answer = 0
        
        for left in range(n):
            min_val, max_val = math.inf, -math.inf
            for right in range(left, n):
                max_val = max(max_val, nums[right])
                min_val = min(min_val, nums[right])
                answer += max_val - min_val
                
        return answer
```

</details>

<br>

## Approach 2: Monotonic Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long answer = 0;
        stack<int> stk;

        // Find the sum of all the minimum.
        for (int right = 0; right <= n; ++right) {
            while (!stk.empty() &&
                   (right == n || nums[stk.top()] >= nums[right])) {
                int mid = stk.top();
                stk.pop();
                int left = stk.empty() ? -1 : stk.top();
                answer -= (long long)nums[mid] * (right - mid) * (mid - left);
            }
            stk.push(right);
        }

        // Find the sum of all the maximum.
        stk.pop();
        for (int right = 0; right <= n; ++right) {
            while (!stk.empty() &&
                   (right == n || nums[stk.top()] <= nums[right])) {
                int mid = stk.top();
                stk.pop();
                int left = stk.empty() ? -1 : stk.top();
                answer += (long long)nums[mid] * (right - mid) * (mid - left);
            }
            stk.push(right);
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long subArrayRanges(int[] nums) {
        int n = nums.length;
        long answer = 0;
        Stack<Integer> stack = new Stack<>();

        // Find the sum of all the minimum.
        for (int right = 0; right <= n; ++right) {
            while (
                !stack.isEmpty() &&
                (right == n || nums[stack.peek()] >= nums[right])
            ) {
                int mid = stack.peek();
                stack.pop();
                int left = stack.isEmpty() ? -1 : stack.peek();
                answer -= (long) nums[mid] * (right - mid) * (mid - left);
            }
            stack.add(right);
        }

        // Find the sum of all the maximum.
        stack.clear();
        for (int right = 0; right <= n; ++right) {
            while (
                !stack.isEmpty() &&
                (right == n || nums[stack.peek()] <= nums[right])
            ) {
                int mid = stack.peek();
                stack.pop();
                int left = stack.isEmpty() ? -1 : stack.peek();
                answer += (long) nums[mid] * (right - mid) * (mid - left);
            }
            stack.add(right);
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        n, answer = len(nums), 0 
        stack = []
        
        # Find the sum of all the minimum.
        for right in range(n + 1):
            while stack and (right == n or nums[stack[-1]] >= nums[right]):
                mid = stack.pop()
                left = -1 if not stack else stack[-1]
                answer -= nums[mid] * (mid - left) * (right - mid)
            stack.append(right)

        # Find the sum of all the maximum.
        stack.clear()
        for right in range(n + 1):
            while stack and (right == n or nums[stack[-1]] <= nums[right]):
                mid = stack.pop()
                left = -1 if not stack else stack[-1]
                answer += nums[mid] * (mid - left) * (right - mid)
            stack.append(right)
        
        return answer
```

</details>
