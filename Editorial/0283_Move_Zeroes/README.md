# 283. Move Zeroes

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/move-zeroes/)  
`Array` `Two Pointers`

**Problem Link:** [LeetCode 283 - Move Zeroes](https://leetcode.com/problems/move-zeroes/)

## Problem

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

### Example 1

```text
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
```

### Example 2

```text
Input: nums = [0]
Output: [0]
```

## Constraints

- 1 <= nums.length <= 104
- -231 <= nums[i] <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove Element](https://leetcode.com/problems/remove-element/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Apply Operations to an Array](https://leetcode.com/problems/apply-operations-to-an-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 283. Move Zeroes

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 (Space Sub-Optimal) [Accepted] | C++ |
| Approach #2 (Space Optimal, Operation Sub-Optimal) [Accepted] | C++ |
| Approach #3 (Optimal) [Accepted] | C++ |

## Approach #1 (Space Sub-Optimal) [Accepted]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
  void moveZeroes(vector<int>& nums) {
      int n = nums.size();

      // Count the zeroes
      int numZeroes = 0;
      for (int i = 0; i < n; i++) {
          numZeroes += (nums[i] == 0);
      }

      // Make all the non-zero elements retain their original order.
      vector<int> ans;
      for (int i = 0; i < n; i++) {
          if (nums[i] != 0) {
              ans.push_back(nums[i]);
          }
      }

      // Move all zeroes to the end
      while (numZeroes--) {
          ans.push_back(0);
      }

      // Combine the result
      for (int i = 0; i < n; i++) {
          nums[i] = ans[i];
      }
  }
};
```

</details>

<br>

## Approach #2 (Space Optimal, Operation Sub-Optimal) [Accepted]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
  void moveZeroes(vector<int>& nums) {
      int lastNonZeroFoundAt = 0;
      // If the current element is not 0, then we need to
      // append it just in front of last non 0 element we found.
      for (int i = 0; i < nums.size(); i++) {
          if (nums[i] != 0) {
              nums[lastNonZeroFoundAt++] = nums[i];
          }
      }
    // After we have finished processing new elements,
    // all the non-zero elements are already at beginning of array.
    // We just need to fill remaining elements in the array with 0's.
      for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
          nums[i] = 0;
      }
  }
};
```

</details>

<br>

## Approach #3 (Optimal) [Accepted]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
  void moveZeroes(vector<int>& nums) {
      for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
          if (nums[cur] != 0) {
              swap(nums[lastNonZeroFoundAt++], nums[cur]);
          }
      }
  }
};
```

</details>
