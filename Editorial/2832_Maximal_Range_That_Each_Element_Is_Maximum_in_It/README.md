# 2832. Maximal Range That Each Element Is Maximum in It

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximal-range-that-each-element-is-maximum-in-it/)  
`Array` `Stack` `Monotonic Stack`

**Problem Link:** [LeetCode 2832 - Maximal Range That Each Element Is Maximum in It](https://leetcode.com/problems/maximal-range-that-each-element-is-maximum-in-it/)

## Problem

You are given a 0-indexed array nums of distinct integers.

Let us define a 0-indexed array ans of the same length as nums in the following way:

- ans[i] is the maximum length of a subarray nums[l..r], such that the maximum element in that subarray is equal to nums[i].

Return the array ans.

Note that a subarray is a contiguous part of the array.

### Example 1

```text
Input: nums = [1,5,4,3,6]
Output: [1,4,2,1,5]
Explanation: For nums[0] the longest subarray in which 1 is the maximum is nums[0..0] so ans[0] = 1.
For nums[1] the longest subarray in which 5 is the maximum is nums[0..3] so ans[1] = 4.
For nums[2] the longest subarray in which 4 is the maximum is nums[2..3] so ans[2] = 2.
For nums[3] the longest subarray in which 3 is the maximum is nums[3..3] so ans[3] = 1.
For nums[4] the longest subarray in which 6 is the maximum is nums[0..4] so ans[4] = 5.
```

### Example 2

```text
Input: nums = [1,2,3,4,5]
Output: [1,2,3,4,5]
Explanation: For nums[i] the longest subarray in which it's the maximum is nums[0..i] so ans[i] = i + 1.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 105
- All elements in nums are distinct.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2832. Maximal Range That Each Element Is Maximum in It

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Monotonic Stack | C++, Java, Python3 |

## Approach: Monotonic Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> maximumLengthOfRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> idxStack;

        // Calculate left boundaries
        for (int currIdx = 0; currIdx < n; ++currIdx) {
            while (!idxStack.empty() && nums[idxStack.top()] < nums[currIdx]) {
                idxStack.pop();
            }
            left[currIdx] = idxStack.empty() ? -1 : idxStack.top();
            idxStack.push(currIdx);
        }

        // Clear the stack for reuse
        while (!idxStack.empty()) idxStack.pop();

        // Calculate right boundaries
        for (int currIdx = n - 1; currIdx >= 0; --currIdx) {
            while (!idxStack.empty() && nums[idxStack.top()] < nums[currIdx]) {
                idxStack.pop();
            }
            right[currIdx] = idxStack.empty() ? n : idxStack.top();
            idxStack.push(currIdx);
        }

        // Calculate the maximal range for each element
        vector<int> maxRanges(n);
        for (int currIdx = 0; currIdx < n; ++currIdx) {
            maxRanges[currIdx] = right[currIdx] - left[currIdx] - 1;
        }

        return maxRanges;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] maximumLengthOfRanges(int[] nums) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Stack<Integer> idxStack = new Stack<>();

        // Calculate left boundaries
        for (int currIdx = 0; currIdx < n; currIdx++) {
            while (!idxStack.empty() && nums[idxStack.peek()] < nums[currIdx]) {
                idxStack.pop();
            }
            left[currIdx] = idxStack.empty() ? -1 : idxStack.peek();
            idxStack.push(currIdx);
        }

        // Clear the stack for reuse
        idxStack.clear();

        // Calculate right boundaries
        for (int currIdx = n - 1; currIdx >= 0; currIdx--) {
            while (!idxStack.empty() && nums[idxStack.peek()] < nums[currIdx]) {
                idxStack.pop();
            }
            right[currIdx] = idxStack.empty() ? n : idxStack.peek();
            idxStack.push(currIdx);
        }

        // Calculate the maximal range for each element
        int[] ans = new int[n];
        for (int currIdx = 0; currIdx < n; currIdx++) {
            ans[currIdx] = right[currIdx] - left[currIdx] - 1;
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
    def maximumLengthOfRanges(self, nums):
        n = len(nums)
        left = [0] * n
        right = [0] * n
        idx_stack = []

        # Calculate left boundaries
        for curr_idx in range(n):
            while idx_stack and nums[idx_stack[-1]] < nums[curr_idx]:
                idx_stack.pop()
            left[curr_idx] = -1 if not idx_stack else idx_stack[-1]
            idx_stack.append(curr_idx)

        # Clear the stack for reuse
        idx_stack = []

        # Calculate right boundaries
        for curr_idx in range(n - 1, -1, -1):
            while idx_stack and nums[idx_stack[-1]] < nums[curr_idx]:
                idx_stack.pop()
            right[curr_idx] = n if not idx_stack else idx_stack[-1]
            idx_stack.append(curr_idx)

        # Calculate the maximal range for each element
        ans = [0] * n
        for curr_idx in range(n):
            ans[curr_idx] = right[curr_idx] - left[curr_idx] - 1

        return ans
```

</details>
