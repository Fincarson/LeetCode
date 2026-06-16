# 565. Array Nesting

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/array-nesting/)  
`Array` `Depth-First Search`

**Problem Link:** [LeetCode 565 - Array Nesting](https://leetcode.com/problems/array-nesting/)

## Problem

You are given an integer array nums of length n where nums is a permutation of the numbers in the range [0, n - 1].

You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... } subjected to the following rule:

- The first element in s[k] starts with the selection of the element nums[k] of index = k.
- The next element in s[k] should be nums[nums[k]], and then nums[nums[nums[k]]], and so on.
- We stop adding right before a duplicate element occurs in s[k].

Return the longest length of a set s[k].

### Example 1

```text
Input: nums = [5,4,0,3,1,6,2]
Output: 4
Explanation:
nums[0] = 5, nums[1] = 4, nums[2] = 0, nums[3] = 3, nums[4] = 1, nums[5] = 6, nums[6] = 2.
One of the longest sets s[k]:
s[0] = {nums[0], nums[5], nums[6], nums[2]} = {5, 6, 2, 0}
```

### Example 2

```text
Input: nums = [0,1,2]
Output: 1
```

## Constraints

- 1 <= nums.length <= 105
- 0 <= nums[i] < nums.length
- All the values of nums are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Nested List Weight Sum](https://leetcode.com/problems/nested-list-weight-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Flatten Nested List Iterator](https://leetcode.com/problems/flatten-nested-list-iterator/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Nested List Weight Sum II](https://leetcode.com/problems/nested-list-weight-sum-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 565. Array Nesting

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Brute Force [Time Limit Exceeded] | Java |
| Approach #2 Using Visited Array [Accepted] | Java |
| Approach #3 Without Using Extra Space [Accepted] | Java |

## Approach #1 Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int arrayNesting(int[] nums) {
        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            int start = nums[i], count = 0;
            do {
                start = nums[start];
                count++;
            }
            while (start != nums[i]);
            res = Math.max(res, count);

        }
        return res;
    }
}
```

</details>

<br>

## Approach #2 Using Visited Array [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int arrayNesting(int[] nums) {
        boolean[] visited = new boolean[nums.length];
        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            if (!visited[i]) {
                int start = nums[i], count = 0;
                do {
                    start = nums[start];
                    count++;
                    visited[start] = true;
                }
                while (start != nums[i]);
                res = Math.max(res, count);
            }
        }
        return res;
    }
}
```

</details>

<br>

## Approach #3 Without Using Extra Space [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

public class Solution {
    public int arrayNesting(int[] nums) {
        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != Integer.MAX_VALUE) {
                int start = nums[i], count = 0;
                while (nums[start] != Integer.MAX_VALUE) {
                    int temp = start;
                    start = nums[start];
                    count++;
                    nums[temp] = Integer.MAX_VALUE;
                }
                res = Math.max(res, count);
            }
        }
        return res;
    }
}
```

</details>
