# 35. Search Insert Position

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/search-insert-position/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 35 - Search Insert Position](https://leetcode.com/problems/search-insert-position/)

## Problem

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

### Example 1

```text
Input: nums = [1,3,5,6], target = 5
Output: 2
```

### Example 2

```text
Input: nums = [1,3,5,6], target = 2
Output: 1
```

### Example 3

```text
Input: nums = [1,3,5,6], target = 7
Output: 4
```

## Constraints

- 1 <= nums.length <= 104
- -104 <= nums[i] <= 104
- nums contains distinct values sorted in ascending order.
- -104 <= target <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [First Bad Version](https://leetcode.com/problems/first-bad-version/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Minimum Operations to Exceed Threshold Value I](https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 35. Search Insert Position

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C++, Java, Python3 |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
pivot = left + (right - left) / 2;
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
pivot = left + (right - left) / 2;
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
pivot = (left + right) // 2
```

</details>
