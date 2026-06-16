# 278. First Bad Version

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/first-bad-version/)  
`Binary Search` `Interactive`

**Problem Link:** [LeetCode 278 - First Bad Version](https://leetcode.com/problems/first-bad-version/)

## Problem

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

### Example 1

```text
Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
```

### Example 2

```text
Input: n = 1, bad = 1
Output: 1
```

## Constraints

- 1 <= bad <= n <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Search Insert Position](https://leetcode.com/problems/search-insert-position/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 278. First Bad Version

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 (Linear Scan) [Time Limit Exceeded] | Java |
| Approach #2 (Binary Search) [Accepted] | Java |

## Approach #1 (Linear Scan) [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public int firstBadVersion(int n) {
    for (int i = 1; i < n; i++) {
        if (isBadVersion(i)) {
            return i;
        }
    }
    return n;
}
```

</details>

<br>

## Approach #2 (Binary Search) [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public int firstBadVersion(int n) {
    int left = 1;
    int right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```

</details>
