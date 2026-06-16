# 852. Peak Index in a Mountain Array

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/peak-index-in-a-mountain-array/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 852 - Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/)

## Problem

You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.

### Example 1

### Example 2

### Example 3

## Constraints

- 3 <= arr.length <= 105
- 0 <= arr[i] <= 106
- arr is guaranteed to be a mountain array.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find Peak Element](https://leetcode.com/problems/find-peak-element/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find in Mountain Array](https://leetcode.com/problems/find-in-mountain-array/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Number of Removals to Make Mountain Array](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 852. Peak Index in a Mountain Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Linear Scan | C++, Java, Python3 |
| Binary Search | C++, Java, Python3 |

## Approach 1: Linear Scan

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0;
        while (arr[i] < arr[i + 1]) {
            i++;
        }
        return i;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int i = 0;
        while (arr[i] < arr[i + 1]) {
            i++;
        }
        return i;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        i = 0
        while arr[i] < arr[i + 1]:
            i += 1
        return i
```

</details>

<br>

## Approach 2: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1, mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (arr[mid] < arr[mid + 1])
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int l = 0, r = arr.length - 1, mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (arr[mid] < arr[mid + 1])
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        l = 0
        r = len(arr) - 1
        while l < r:
            mid = (l + r) // 2
            if arr[mid] < arr[mid + 1]:
                l = mid + 1
            else:
                r = mid
        return l
```

</details>
