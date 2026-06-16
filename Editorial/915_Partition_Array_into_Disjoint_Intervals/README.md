# 915. Partition Array into Disjoint Intervals

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/partition-array-into-disjoint-intervals/)  
`Array`

**Problem Link:** [LeetCode 915 - Partition Array into Disjoint Intervals](https://leetcode.com/problems/partition-array-into-disjoint-intervals/)

## Problem

Given an integer array nums, partition it into two (contiguous) subarrays left and right so that:

- Every element in left is less than or equal to every element in right.
- left and right are non-empty.
- left has the smallest possible size.

Return the length of left after such a partitioning.

Test cases are generated such that partitioning exists.

### Example 1

```text
Input: nums = [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
```

### Example 2

```text
Input: nums = [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]
```

## Constraints

- 2 <= nums.length <= 105
- 0 <= nums[i] <= 106
- There is at least one valid answer for the given input.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sum of Beauty in the Array](https://leetcode.com/problems/sum-of-beauty-in-the-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Optimal Partition of String](https://leetcode.com/problems/optimal-partition-of-string/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Index of a Valid Split](https://leetcode.com/problems/minimum-index-of-a-valid-split/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Strength of K Disjoint Subarrays](https://leetcode.com/problems/maximum-strength-of-k-disjoint-subarrays/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 915. Partition Array into Disjoint Intervals

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Arrays | C++, Java, Python3 |
| One Array | C++, Java, Python3 |
| No Arrays | C++, Java, Python3 |

## Approach 1: Two Arrays

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int N = nums.size();
        int maxLeft[N];
        int minRight[N];
        
        maxLeft[0] = nums[0];
        minRight[N - 1] = nums[N - 1];
        
        for (int i = 1; i < N; ++i) {
            maxLeft[i] = max(maxLeft[i - 1], nums[i]);
        }
        
        for (int i = N - 2; i >= 0; --i) {
            minRight[i] = min(minRight[i + 1], nums[i]);
        }
        
        for (int i = 1; i < N; ++i) {
            if (maxLeft[i - 1] <= minRight[i]) {
                return i;
            } 
        }
        // In case there is no solution, we'll return -1
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int partitionDisjoint(int[] nums) {
        int N = nums.length;
        int[] maxLeft = new int[N];
        int[] minRight = new int[N];
        
        maxLeft[0] = nums[0];
        minRight[N - 1] = nums[N - 1];

        for (int i = 1; i < N; ++i) {
            maxLeft[i] = Math.max(maxLeft[i - 1], nums[i]);
        }

        for (int i = N - 2; i >= 0; --i) {
            minRight[i] = Math.min(minRight[i + 1], nums[i]);
        }

        for (int i = 1; i < N; ++i) {
            if (maxLeft[i - 1] <= minRight[i]) {
                return i;
            }
        }
        // In case there is no solution, we'll return -1
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        N = len(nums)
        max_left = [None] * N
        min_right = [None] * N
        
        max_left[0] = nums[0]
        min_right[-1] = nums[-1]

        for i in range(1, N):
            max_left[i] = max(max_left[i - 1], nums[i])

        for i in range(N - 2, -1, -1):
            min_right[i] = min(min_right[i + 1], nums[i])

        for i in range(1, N):
            if max_left[i - 1] <= min_right[i]:
                return i
```

</details>

<br>

## Approach 2: One Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int N = nums.size();
        int minRight[N];
        minRight[N - 1] = nums[N - 1];
        
        for (int i = N - 2; i >= 0; --i) {
            minRight[i] = min(minRight[i + 1], nums[i]);
        }
        
        int currMax = nums[0];
        for (int i = 1; i < N; ++i) {
            currMax = max(currMax, nums[i - 1]);
            if (currMax <= minRight[i]) {
                return i;
            } 
        }
        // In case there is no solution, we'll return -1
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int partitionDisjoint(int[] nums) {
        int N = nums.length;
        int[] minRight = new int[N];
        minRight[N - 1] = nums[N - 1];

        for (int i = N - 2; i >= 0; --i) {
            minRight[i] = Math.min(minRight[i + 1], nums[i]);
        }

        int currMax = nums[0];
        for (int i = 1; i < N; ++i) {
            currMax = Math.max(currMax, nums[i - 1]);
            if (currMax <= minRight[i]) {
                return i;
            }
        }
        // In case there is no solution, we'll return -1
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        N = len(nums)
        min_right = [None] * N
        min_right[-1] = nums[-1]

        for i in range(N - 2, -1, -1):
            min_right[i] = min(min_right[i + 1], nums[i])

        curr_max = nums[0]
        for i in range(1, N):
            curr_max = max(curr_max, nums[i - 1])
            if curr_max <= min_right[i]:
                return i
```

</details>

<br>

## Approach 3: No Arrays

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int currMax = nums[0];
        int possibleMax = nums[0];
        int length = 1;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < currMax) {
                length = i + 1;
                currMax = possibleMax;
            } else {
                possibleMax = max(possibleMax, nums[i]);
            }
        }
        
        return length;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int partitionDisjoint(int[] nums) {
        int currMax = nums[0];
        int possibleMax = nums[0];
        int length = 1;
        
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] < currMax) {
                length = i + 1;
                currMax = possibleMax;
            } else {
                possibleMax = Math.max(possibleMax, nums[i]);
            }
        }
        
        return length;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        curr_max = nums[0]
        possible_max = nums[0]
        length = 1
        
        for i in range(1, len(nums)):
            if nums[i] < curr_max:
                length = i + 1
                curr_max = possible_max
            else:
                possible_max = max(possible_max, nums[i])
                
        return length
```

</details>
