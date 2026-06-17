# 976. Largest Perimeter Triangle

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/largest-perimeter-triangle/)  
`Array` `Math` `Greedy` `Sorting`

**Problem Link:** [LeetCode 976 - Largest Perimeter Triangle](https://leetcode.com/problems/largest-perimeter-triangle/)

## Problem

Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

### Example 1

```text
Input: nums = [2,1,2]
Output: 5
Explanation: You can form a triangle with three side lengths: 1, 2, and 2.
```

### Example 2

```text
Input: nums = [1,2,1,10]
Output: 0
Explanation:
You cannot use the side lengths 1, 1, and 2 to form a triangle.
You cannot use the side lengths 1, 1, and 10 to form a triangle.
You cannot use the side lengths 1, 2, and 10 to form a triangle.
As we cannot use any three side lengths to form a triangle of non-zero area, we return 0.
```

## Constraints

- 3 <= nums.length <= 104
- 1 <= nums[i] <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Largest Triangle Area](https://leetcode.com/problems/largest-triangle-area/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 976. Largest Perimeter Triangle

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sort | C++, Java, Python3 |

## Approach: Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        for (int i = A.size() - 3; i >= 0; --i) {
            if (A[i] + A[i + 1] > A[i + 2]) {
                return A[i] + A[i + 1] + A[i + 2];
            }
        }
        return 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int largestPerimeter(int[] A) {
        Arrays.sort(A);
        for (int i = A.length - 3; i >= 0; --i)
            if (A[i] + A[i+1] > A[i+2])
                return A[i] + A[i+1] + A[i+2];
        return 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestPerimeter(self, A):
        A.sort()
        for i in range(len(A) - 3, -1, -1):
            if A[i] + A[i + 1] > A[i + 2]:
                return A[i] + A[i + 1] + A[i + 2]
        return 0
```

</details>
