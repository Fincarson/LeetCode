# 217. Contains Duplicate

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/contains-duplicate/)  
`Array` `Hash Table` `Sorting`

**Problem Link:** [LeetCode 217 - Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)

## Problem

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= nums.length <= 105
- -109 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Contains Duplicate III](https://leetcode.com/problems/contains-duplicate-iii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Make Array Zero by Subtracting Equal Amounts](https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find Valid Pair of Adjacent Digits in String](https://leetcode.com/problems/find-valid-pair-of-adjacent-digits-in-string/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 217. Contains Duplicate

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 (Naive Linear Search) [Time Limit Exceeded] | Java |
| Approach #2 (Sorting) [Accepted] | Java |
| Approach #3 (Hash Table) [Accepted] | Java |

## Approach #1 (Naive Linear Search) [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public boolean containsDuplicate(int[] nums) {
    for (int i = 0; i < nums.length; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] == nums[i]) return true;  
        }
    }
    return false;
}
// Time Limit Exceeded
```

</details>

<br>

## Approach #2 (Sorting) [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public boolean containsDuplicate(int[] nums) {
    Arrays.sort(nums);
    for (int i = 0; i < nums.length - 1; ++i) {
        if (nums[i] == nums[i + 1]) return true;
    }
    return false;
}
```

</details>

<br>

## Approach #3 (Hash Table) [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public boolean containsDuplicate(int[] nums) {
    Set<Integer> set = new HashSet<>(nums.length);
    for (int x: nums) {
        if (set.contains(x)) return true;
        set.add(x);
    }
    return false;
}
```

</details>
