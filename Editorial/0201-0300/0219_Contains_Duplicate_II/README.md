# 219. Contains Duplicate II

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/contains-duplicate-ii/)  
`Array` `Hash Table` `Sliding Window`

**Problem Link:** [LeetCode 219 - Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/)

## Problem

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

### Example 1

```text
Input: nums = [1,2,3,1], k = 3
Output: true
```

### Example 2

```text
Input: nums = [1,0,1,1], k = 1
Output: true
```

### Example 3

```text
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
```

## Constraints

- 1 <= nums.length <= 105
- -109 <= nums[i] <= 109
- 0 <= k <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Contains Duplicate III](https://leetcode.com/problems/contains-duplicate-iii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 219. Contains Duplicate II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Naive Linear Search | Java |
| Approach #2: Binary Search Tree | Java |
| Approach #3: Hash Table | Java |

## Approach #1: Naive Linear Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public boolean containsNearbyDuplicate(int[] nums, int k) {
    for (int i = 0; i < nums.length; ++i) {
        for (int j = Math.max(i - k, 0); j < i; ++j) {
            if (nums[i] == nums[j]) return true;
        }
    }
    return false;
}
// Time Limit Exceeded.
```

</details>

<br>

## Approach #2: Binary Search Tree

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public boolean containsNearbyDuplicate(int[] nums, int k) {
    Set<Integer> set = new TreeSet<>();
    for (int i = 0; i < nums.length; ++i) {
        if (set.contains(nums[i])) return true;
        set.add(nums[i]);
        if (set.size() > k) {
            set.remove(nums[i - k]);
        }
    }
    return false;
}
// Time Limit Exceeded.
```

</details>

<br>

## Approach #3: Hash Table

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public boolean containsNearbyDuplicate(int[] nums, int k) {
    Set<Integer> set = new HashSet<>();
    for (int i = 0; i < nums.length; ++i) {
        if (set.contains(nums[i])) return true;
        set.add(nums[i]);
        if (set.size() > k) {
            set.remove(nums[i - k]);
        }
    }
    return false;
}
```

</details>
