# 553. Optimal Division

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/optimal-division/)  
`Array` `Math` `Dynamic Programming`

**Problem Link:** [LeetCode 553 - Optimal Division](https://leetcode.com/problems/optimal-division/)

## Problem

You are given an integer array nums. The adjacent integers in nums will perform the float division.

- For example, for nums = [2,3,4], we will evaluate the expression "2/3/4".

However, you can add any number of parenthesis at any position to change the priority of operations. You want to add these parentheses such the value of the expression after the evaluation is maximum.

Return the corresponding expression that has the maximum value in string format.

Note: your expression should not contain redundant parenthesis.

### Example 1

```text
Input: nums = [1000,100,10,2]
Output: "1000/(100/10/2)"
Explanation: 1000/(100/10/2) = 1000/((100/10)/2) = 200
However, the bold parenthesis in "1000/((100/10)/2)" are redundant since they do not influence the operation priority.
So you should return "1000/(100/10/2)".
Other cases:
1000/(100/10)/2 = 50
1000/(100/(10/2)) = 50
1000/100/10/2 = 0.5
1000/100/(10/2) = 2
```

### Example 2

```text
Input: nums = [2,3,4]
Output: "2/(3/4)"
Explanation: (2/(3/4)) = 8/3 = 2.667
It can be shown that after trying all possibilities, we cannot get an expression with evaluation greater than 2.667
```

## Constraints

- 1 <= nums.length <= 10
- 2 <= nums[i] <= 1000
- There is only one optimal division for the given input.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 553. Optimal Division

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Brute Force [Accepted] | Java |
| Approach #2 Using Memorization [Accepted] | Java |
| Approach #3 Using some Math [Accepted] | Java |

## Approach #1 Brute Force [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public String optimalDivision(int[] nums) {
        T t = optimal(nums, 0, nums.length - 1, "");
        return t.max_str;
    }
    class T {
        float max_val, min_val;
        String min_str, max_str;
    }
    public T optimal(int[] nums, int start, int end, String res) {
        T t = new T();
        if (start == end) {
            t.max_val = nums[start];
            t.min_val = nums[start];
            t.min_str = "" + nums[start];
            t.max_str = "" + nums[start];
            return t;
        }
        t.min_val = Float.MAX_VALUE;
        t.max_val = Float.MIN_VALUE;
        t.min_str = t.max_str = "";
        for (int i = start; i < end; i++) {
            T left = optimal(nums, start, i, "");
            T right = optimal(nums, i + 1, end, "");
            if (t.min_val > left.min_val / right.max_val) {
                t.min_val = left.min_val / right.max_val;
                t.min_str = left.min_str + "/" + (i + 1 != end ? "(" : "") + right.max_str + (i + 1 != end ? ")" : "");
            }
            if (t.max_val < left.max_val / right.min_val) {
                t.max_val = left.max_val / right.min_val;
                t.max_str = left.max_str + "/" + (i + 1 != end ? "(" : "") + right.min_str + (i + 1 != end ? ")" : "");
            }
        }
        return t;
    }
}
```

</details>

<br>

## Approach #2 Using Memorization [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    class T {
        float max_val, min_val;
        String min_str, max_str;
    }
    public String optimalDivision(int[] nums) {
        T[][] memo = new T[nums.length][nums.length];
        T t = optimal(nums, 0, nums.length - 1, "", memo);
        return t.max_str;
    }
    public T optimal(int[] nums, int start, int end, String res, T[][] memo) {
        if (memo[start][end] != null)
            return memo[start][end];
        T t = new T();
        if (start == end) {
            t.max_val = nums[start];
            t.min_val = nums[start];
            t.min_str = "" + nums[start];
            t.max_str = "" + nums[start];
            memo[start][end] = t;
            return t;
        }
        t.min_val = Float.MAX_VALUE;
        t.max_val = Float.MIN_VALUE;
        t.min_str = t.max_str = "";
        for (int i = start; i < end; i++) {
            T left = optimal(nums, start, i, "", memo);
            T right = optimal(nums, i + 1, end, "", memo);
            if (t.min_val > left.min_val / right.max_val) {
                t.min_val = left.min_val / right.max_val;
                t.min_str = left.min_str + "/" + (i + 1 != end ? "(" : "") + right.max_str + (i + 1 != end ? ")" : "");
            }
            if (t.max_val < left.max_val / right.min_val) {
                t.max_val = left.max_val / right.min_val;
                t.max_str = left.max_str + "/" + (i + 1 != end ? "(" : "") + right.min_str + (i + 1 != end ? ")" : "");
            }
        }
        memo[start][end] = t;
        return t;
    }
}
```

</details>

<br>

## Approach #3 Using some Math [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public String optimalDivision(int[] nums) {
        if (nums.length == 1)
            return nums[0] + "";
        if (nums.length == 2)
            return nums[0] + "/" + nums[1];
        StringBuilder res = new StringBuilder(nums[0] + "/(" + nums[1]);
        for (int i = 2; i < nums.length; i++) {
            res.append("/" + nums[i]);
        }
        res.append(")");
        return res.toString();
    }
}
```

</details>
