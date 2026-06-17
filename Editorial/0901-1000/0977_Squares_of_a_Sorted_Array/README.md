# 977. Squares of a Sorted Array

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/squares-of-a-sorted-array/)  
`Array` `Two Pointers` `Sorting`

**Problem Link:** [LeetCode 977 - Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/)

## Problem

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

### Example 1

```text
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
```

### Example 2

```text
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
```

## Constraints

- 1 <= nums.length <= 104
- -104 <= nums[i] <= 104
- nums is sorted in non-decreasing order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Sort Transformed Array](https://leetcode.com/problems/sort-transformed-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 977. Squares of a Sorted Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort | C++, Java, Python3 |
| Two Pointer | C++, Java, Python3 |

## Approach 1: Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> ans(n);
        for (size_t i = 0; i < n; i++) {
            ans[i] = nums[i] * nums[i];
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] sortedSquares(int[] A) {
        int N = A.length;
        int[] ans = new int[N];
        for (int i = 0; i < N; ++i)
            ans[i] = A[i] * A[i];

        Arrays.sort(ans);
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def sortedSquares(self, A):
        return sorted(x*x for x in A)
```

</details>

<br>

## Approach 2: Two Pointer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n);

        int left = 0;
        int right = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            int square;
            if (abs(nums[left]) < abs(nums[right])) {
                square = nums[right];
                right--;
            } else {
                square = nums[left];
                left++;
            }
            result[i] = square * square;
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        int left = 0;
        int right = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            int square;
            if (Math.abs(nums[left]) < Math.abs(nums[right])) {
                square = nums[right];
                right--;
            } else {
                square = nums[left];
                left++;
            }
            result[i] = square * square;
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [0] * n
        left = 0
        right = n - 1
        for i in range(n - 1, -1, -1):
            if abs(nums[left]) < abs(nums[right]):
                square = nums[right]
                right -= 1
            else:
                square = nums[left]
                left += 1
            result[i] = square * square
        return result
```

</details>
