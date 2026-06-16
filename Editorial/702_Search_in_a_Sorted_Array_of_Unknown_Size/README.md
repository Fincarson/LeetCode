# 702. Search in a Sorted Array of Unknown Size

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/)  
`Array` `Binary Search` `Interactive`

**Problem Link:** [LeetCode 702 - Search in a Sorted Array of Unknown Size](https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/)

## Problem

This is an interactive problem.

You have a sorted array of unique elements and an unknown size. You do not have an access to the array but you can use the ArrayReader interface to access it. You can call ArrayReader.get(i) that:

- returns the value at the ith index (0-indexed) of the secret array (i.e., secret[i]), or
- returns 231 - 1 if the i is out of the boundary of the array.

You are also given an integer target.

Return the index k of the hidden array where secret[k] == target or return -1 otherwise.

You must write an algorithm with O(log n) runtime complexity.

### Example 1

```text
Input: secret = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in secret and its index is 4.
```

### Example 2

```text
Input: secret = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in secret so return -1.
```

## Constraints

- 1 <= secret.length <= 104
- -104 <= secret[i], target <= 104
- secret is sorted in a strictly increasing order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Search](https://leetcode.com/problems/binary-search/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find the Index of the Large Integer](https://leetcode.com/problems/find-the-index-of-the-large-integer/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 702. Search in a Sorted Array of Unknown Size

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C++, Java, Python |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class ArrayReader;

class Solution {
  public:
  int search(const ArrayReader& reader, int target) {
    if (reader.get(0) == target) return 0;

    // search boundaries
    int left = 0, right = 1;
    while (reader.get(right) < target) {
      left = right;
      right <<= 1;
    }

    // binary search
    int pivot, num;
    while (left <= right) {
      pivot = left + ((right - left) >> 1);
      num = reader.get(pivot);

      if (num == target) return pivot;
      if (num > target) right = pivot - 1;
      else left = pivot + 1;
    }

    // there is no target element
    return -1;
  }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int search(ArrayReader reader, int target) {
    if (reader.get(0) == target) return 0;

    // search boundaries
    int left = 0, right = 1;
    while (reader.get(right) < target) {
      left = right;
      right <<= 1;
    }

    // binary search
    int pivot, num;
    while (left <= right) {
      pivot = left + ((right - left) >> 1);
      num = reader.get(pivot);

      if (num == target) return pivot;
      if (num > target) right = pivot - 1;
      else left = pivot + 1;
    }

    // there is no target element
    return -1;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def search(self, reader, target):
        if reader.get(0) == target:
            return 0
        
        # search boundaries
        left, right = 0, 1
        while reader.get(right) < target:
            left = right
            right <<= 1
        
        # binary search
        while left <= right:
            pivot = left + ((right - left) >> 1)
            num = reader.get(pivot)
            
            if num == target:
                return pivot
            if num > target:
                right = pivot - 1
            else:
                left = pivot + 1
        
        # there is no target element
        return -1
```

</details>
