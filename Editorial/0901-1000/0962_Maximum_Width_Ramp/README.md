# 962. Maximum Width Ramp

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-width-ramp/)  
`Array` `Two Pointers` `Stack` `Monotonic Stack`

**Problem Link:** [LeetCode 962 - Maximum Width Ramp](https://leetcode.com/problems/maximum-width-ramp/)

## Problem

A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.

Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.

### Example 1

```text
Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.
```

### Example 2

```text
Input: nums = [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.
```

## Constraints

- 2 <= nums.length <= 5 * 104
- 0 <= nums[i] <= 5 * 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 962. Maximum Width Ramp

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force (Time Limit Exceeded) | C++, Java, Python3 |
| Sorting | C++, Java, Python3 |
| Two Pointers | C++, Java, Python3 |
| Monotonic Stack | C++, Java, Python3 |

## Approach 1: Brute Force (Time Limit Exceeded)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int maxWidth = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] <= nums[j]) {
                    maxWidth = max(maxWidth, j - i);
                }
            }
        }
        return maxWidth;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxWidthRamp(int[] nums) {
        int n = nums.length;
        int maxWidth = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] <= nums[j]) {
                    maxWidth = Math.max(maxWidth, j - i);
                }
            }
        }
        return maxWidth;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        n = len(nums)
        max_width = 0
        for i in range(n):
            for j in range(i + 1, n):
                if nums[i] <= nums[j]:
                    max_width = max(max_width, j - i)
        return max_width
```

</details>

<br>

## Approach 2: Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> indices(n);

        // Initialize the array with indices
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        // Sort indices based on corresponding values in nums and ensure
        // stability
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return nums[i] != nums[j] ? nums[i] < nums[j] : i < j;
        });

        int minIndex = n;  // Minimum index encountered so far
        int maxWidth = 0;

        // Calculate maximum width ramp
        for (int i = 0; i < n; i++) {
            maxWidth = max(maxWidth, indices[i] - minIndex);
            minIndex = min(minIndex, indices[i]);
        }

        return maxWidth;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxWidthRamp(int[] nums) {
        int n = nums.length;
        Integer[] indices = new Integer[n];

        // Initialize the array with indices
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        // Sort indices based on corresponding values in nums and ensure stability
        Arrays.sort(indices, (i, j) ->
            nums[i] != nums[j] ? nums[i] - nums[j] : i - j
        );

        int minIndex = n; // Minimum index encountered so far
        int maxWidth = 0;

        // Calculate maximum width ramp
        for (int i : indices) {
            maxWidth = Math.max(maxWidth, i - minIndex);
            minIndex = Math.min(minIndex, i);
        }

        return maxWidth;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        n = len(nums)
        indices = [i for i in range(n)]

        # Sort indices based on corresponding values in nums and ensure stability
        indices.sort(key=lambda i: (nums[i], i))

        min_index = n  # Minimum index encountered so far
        max_width = 0

        # Calculate maximum width ramp
        for i in indices:
            max_width = max(max_width, i - min_index)
            min_index = min(min_index, i)

        return max_width
```

</details>

<br>

## Approach 3: Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMax(n);

        // Fill rightMax array with the maximum values from the right
        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }

        int left = 0, right = 0;
        int maxWidth = 0;

        // Traverse the array using left and right pointers
        while (right < n) {
            // Move left pointer forward if current left exceeds rightMax
            while (left < right && nums[left] > rightMax[right]) {
                left++;
            }
            maxWidth = max(maxWidth, right - left);
            right++;
        }

        return maxWidth;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxWidthRamp(int[] nums) {
        int n = nums.length;
        int[] rightMax = new int[n];

        // Fill rightMax array with the maximum values from the right
        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = Math.max(rightMax[i + 1], nums[i]);
        }

        int left = 0, right = 0;
        int maxWidth = 0;

        // Traverse the array using left and right pointers
        while (right < n) {
            // Move left pointer forward if current left exceeds rightMax
            while (left < right && nums[left] > rightMax[right]) {
                left++;
            }
            maxWidth = Math.max(maxWidth, right - left);
            right++;
        }

        return maxWidth;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        n = len(nums)
        right_max = [None] * n

        # Fill right_max array with the maximum values from the right
        right_max[n - 1] = nums[n - 1]
        for i in range(n - 2, -1, -1):
            right_max[i] = max(right_max[i + 1], nums[i])

        left = 0
        right = 0
        max_width = 0

        # Traverse the array using left and right pointers
        while right < n:
            # Move left pointer forward if current left exceeds right_max
            while left < right and nums[left] > right_max[right]:
                left += 1
            max_width = max(max_width, right - left)
            right += 1

        return max_width
```

</details>

<br>

## Approach 4: Monotonic Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> indicesStack;

        // Fill the stack with indices in increasing order of their values
        for (int i = 0; i < n; i++) {
            if (indicesStack.empty() || nums[indicesStack.top()] > nums[i]) {
                indicesStack.push(i);
            }
        }

        int maxWidth = 0;

        // Traverse the array from the end to the start
        for (int j = n - 1; j >= 0; j--) {
            while (!indicesStack.empty() &&
                   nums[indicesStack.top()] <= nums[j]) {
                maxWidth = max(maxWidth, j - indicesStack.top());
                // Pop the index since it's already processed
                indicesStack.pop();
            }
        }

        return maxWidth;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxWidthRamp(int[] nums) {
        int n = nums.length;
        Stack<Integer> indicesStack = new Stack<>();

        // Fill the stack with indices in increasing order of their values
        for (int i = 0; i < n; i++) {
            if (indicesStack.isEmpty() || nums[indicesStack.peek()] > nums[i]) {
                indicesStack.push(i);
            }
        }

        int maxWidth = 0;

        // Traverse the array from the end to the start
        for (int j = n - 1; j >= 0; j--) {
            while (
                !indicesStack.isEmpty() && nums[indicesStack.peek()] <= nums[j]
            ) {
                maxWidth = Math.max(maxWidth, j - indicesStack.peek());
                // Pop the index since it's already processed
                indicesStack.pop();
            }
        }

        return maxWidth;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxWidthRamp(self, nums):
        n = len(nums)
        indices_stack = []

        # Fill the stack with indices in increasing order of their values
        for i in range(n):
            if not indices_stack or nums[indices_stack[-1]] > nums[i]:
                indices_stack.append(i)

        max_width = 0

        # Traverse the array from the end to the start
        for j in range(n - 1, -1, -1):
            while indices_stack and nums[indices_stack[-1]] <= nums[j]:
                max_width = max(max_width, j - indices_stack[-1])
                # Pop the index since it's already processed
                indices_stack.pop()

        return max_width
```

</details>
