# 1063. Number of Valid Subarrays

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/number-of-valid-subarrays/)  
`Array` `Stack` `Monotonic Stack`

**Problem Link:** [LeetCode 1063 - Number of Valid Subarrays](https://leetcode.com/problems/number-of-valid-subarrays/)

## Problem

Given an integer array nums, return the number of non-empty subarrays with the leftmost element of the subarray not larger than other elements in the subarray.

A subarray is a contiguous part of an array.

### Example 1

```text
Input: nums = [1,4,2,5,3]
Output: 11
Explanation: There are 11 valid subarrays: [1],[4],[2],[5],[3],[1,4],[2,5],[1,4,2],[2,5,3],[1,4,2,5],[1,4,2,5,3].
```

### Example 2

```text
Input: nums = [3,2,1]
Output: 3
Explanation: The 3 valid subarrays are: [3],[2],[1].
```

### Example 3

```text
Input: nums = [2,2,2]
Output: 6
Explanation: There are 6 valid subarrays: [2],[2],[2],[2,2],[2,2],[2,2,2].
```

## Constraints

- 1 <= nums.length <= 5 * 104
- 0 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Smooth Descent Periods of a Stock](https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1063. Number of Valid Subarrays

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Monotonic Stack | C++, Java |

## Approach: Monotonic Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int ans = 0;
        
        stack<int> st;
        for (int i = 0; i < nums.size(); i++) {
            // Keep popping elements from the stack
            // until the current element becomes greater than the top element.
            while (!st.empty() && nums[i] < nums[st.top()]) {
                // The diff between the current index and the stack top would be the subarray size.
                // Which is equal to the number of subarrays.
                ans += (i - st.top());
                st.pop();
            }
            st.push(i);
        }
        
        // For all remaining elements, the last element will be considered as the right endpoint.
        while (!st.empty()) {
            ans += (nums.size() - st.top());
            st.pop();
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
    public int validSubarrays(int[] nums) {
        int ans = 0;
        
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < nums.length; i++) {
            // Keep popping elements from the stack
            // until the current element becomes greater than the top element.
            while(!st.isEmpty() && nums[i] < nums[st.peek()]) {
                // The diff between the current index and the stack top would be the subarray size.
                // Which is equal to the number of subarrays.
                ans += (i - st.peek());
                st.pop();
            }
            st.push(i);
        }
        
        // For all remaining elements, the last element will be considered as the right endpoint.
        while (!st.isEmpty()) {
            ans += (nums.length - st.peek());
            st.pop();
        }
        
        return ans;
    }
}
```

</details>
