# 503. Next Greater Element II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/next-greater-element-ii/)  
`Array` `Stack` `Monotonic Stack`

**Problem Link:** [LeetCode 503 - Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/)

## Problem

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

### Example 1

```text
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2;
The number 2 can't find next greater number.
The second 1's next greater number needs to search circularly, which is also 2.
```

### Example 2

```text
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
```

## Constraints

- 1 <= nums.length <= 104
- -109 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Next Greater Element III](https://leetcode.com/problems/next-greater-element-iii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum and Minimum Sums of at Most Size K Subarrays](https://leetcode.com/problems/maximum-and-minimum-sums-of-at-most-size-k-subarrays/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 503. Next Greater Element II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force (using Double Length Array) [Time Limit Exceeded] | Java |
| Better Brute Force [Accepted] | Java |
| Using Stack [Accepted] | Java |

## Approach 1: Brute Force (using Double Length Array) [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
 public class Solution {

    public int[] nextGreaterElements(int[] nums) {
        int[] res = new int[nums.length];
        int[] doublenums = new int[nums.length * 2];
        System.arraycopy(nums, 0, doublenums, 0, nums.length);
        System.arraycopy(nums, 0, doublenums, nums.length, nums.length);
        for (int i = 0; i < nums.length; i++) {
            res[i]=-1;
            for (int j = i + 1; j < doublenums.length; j++) {
                if (doublenums[j] > doublenums[i]) {
                    res[i] = doublenums[j];
                    break;
                }
            }
        }
        return res;
    }
}
```

</details>

<br>

## Approach 2: Better Brute Force [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
 public class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int[] res = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            res[i] = -1;
            for (int j = 1; j < nums.length; j++) {
                if (nums[(i + j) % nums.length] > nums[i]) {
                    res[i] = nums[(i + j) % nums.length];
                    break;
                }
            }
        }
        return res;
    }
}
```

</details>

<br>

## Approach 3: Using Stack [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int[] nextGreaterElements(int[] nums) {
        int[] res = new int[nums.length];
        Stack<Integer> stack = new Stack<>();
        for (int i = 2 * nums.length - 1; i >= 0; --i) {
            while (!stack.empty() && nums[stack.peek()] <= nums[i % nums.length]) {
                stack.pop();
            }
            res[i % nums.length] = stack.empty() ? -1 : nums[stack.peek()];
            stack.push(i % nums.length);
        }
        return res;
    }
}
```

</details>
