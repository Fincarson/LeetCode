# 594. Longest Harmonious Subsequence

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/longest-harmonious-subsequence/)  
`Array` `Hash Table` `Sliding Window` `Sorting` `Counting`

**Problem Link:** [LeetCode 594 - Longest Harmonious Subsequence](https://leetcode.com/problems/longest-harmonious-subsequence/)

## Problem

We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= nums.length <= 2 * 104
- -109 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 594. Longest Harmonious Subsequence

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java |
| Better Brute Force | Java |
| Using Sorting | Java |
| Using HashMap | Java |
| In Single Loop | Java |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int findLHS(int[] nums) {
        int res = 0;
        for (int i = 0; i < (1 << nums.length); i++) {
            int count = 0, min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
            for (int j = 0; j < nums.length; j++) {
                if ((i & (1 << j)) != 0) {
                    min = Math.min(min, nums[j]);
                    max = Math.max(max, nums[j]);
                    count++;
                }
            }
            if (max - min == 1)
                res = Math.max(res, count);
        }
        return res;
    }
}
```

</details>

<br>

## Approach 2: Better Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int findLHS(int[] nums) {
        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            int count = 0;
            boolean flag = false;
            for (int j = 0; j < nums.length; j++) {
                if (nums[j] == nums[i])
                    count++;
                else if (nums[j] + 1 == nums[i]) {
                    count++;
                    flag = true;
                }
            }
            if (flag)
                res = Math.max(count, res);
        }
        return res;
    }
}
```

</details>

<br>

## Approach 3: Using Sorting

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int findLHS(int[] nums) {
        Arrays.sort(nums);
        int prev_count = 1, res = 0;
        for (int i = 0; i < nums.length; i++) {
            int count = 1;
            if (i > 0 && nums[i] - nums[i - 1] == 1) {
                while (i < nums.length - 1 && nums[i] == nums[i + 1]) {
                    count++;
                    i++;
                }
                res = Math.max(res, count + prev_count);
                prev_count = count;
            } else {
                while (i < nums.length - 1 && nums[i] == nums[i + 1]) {
                    count++;
                    i++;
                }
                prev_count = count;
            }
        }
        return res;
    }
}
```

</details>

<br>

## Approach 4: Using HashMap

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int findLHS(int[] nums) {
        HashMap < Integer, Integer > map = new HashMap < > ();
        int res = 0;
        for (int num: nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        for (int key: map.keySet()) {
            if (map.containsKey(key + 1))
                res = Math.max(res, map.get(key) + map.get(key + 1));
        }
        return res;
    }
}
```

</details>

<br>

## Approach 5: In Single Loop

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int findLHS(int[] nums) {
        HashMap < Integer, Integer > map = new HashMap < > ();
        int res = 0;
        for (int num: nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
            if (map.containsKey(num + 1))
                res = Math.max(res, map.get(num) + map.get(num + 1));
            if (map.containsKey(num - 1))
                res = Math.max(res, map.get(num) + map.get(num - 1));
        }
        return res;
    }
}
```

</details>
