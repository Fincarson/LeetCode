# 453. Minimum Moves to Equal Array Elements

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-moves-to-equal-array-elements/)  
`Array` `Math`

**Problem Link:** [LeetCode 453 - Minimum Moves to Equal Array Elements](https://leetcode.com/problems/minimum-moves-to-equal-array-elements/)

## Problem

Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment n - 1 elements of the array by 1.

### Example 1

```text
Input: nums = [1,2,3]
Output: 3
Explanation: Only three moves are needed (remember each move increments two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
```

### Example 2

```text
Input: nums = [1,1,1]
Output: 0
```

## Constraints

- n == nums.length
- 1 <= nums.length <= 105
- -109 <= nums[i] <= 109
- The answer is guaranteed to fit in a 32-bit integer.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Moves to Equal Array Elements II](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Running Time of N Computers](https://leetcode.com/problems/maximum-running-time-of-n-computers/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Pour Water Between Buckets to Make Water Levels Equal](https://leetcode.com/problems/pour-water-between-buckets-to-make-water-levels-equal/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Divide Players Into Teams of Equal Skill](https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find Minimum Operations to Make All Elements Divisible by Three](https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 453. Minimum Moves to Equal Array Elements

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force [Time Limit Exceeded] | Java |
| Better Brute Force[Time Limit Exceeded] | Java |
| Using Sorting [Accepted] | Java |
| Using DP [Accepted] | Java |
| Using Math[Accepted] | Java |
| Modified Approach Using Maths[Accepted] | Java |

## Approach 1: Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int minMoves(int[] nums) {
        int min = 0, max = nums.length - 1, count = 0;
        while (true) {
            for (int i = 0; i < nums.length; i++) {
                if (nums[max] < nums[i]) {
                    max = i;
                }
                if (nums[min] > nums[i]) {
                    min = i;
                }
            }
            if (nums[max] == nums[min]) {
                break;
            }
            for (int i = 0; i < nums.length; i++) {
                if (i != max) {
                    nums[i]++;
                }
            }
            count++;
        }
        return count;
    }
}
```

</details>

<br>

## Approach 2: Better Brute Force[Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int minMoves(int[] nums) {
        int min = 0, max = nums.length - 1, count = 0;
        while (true) {
            for (int i = 0; i < nums.length; i++) {
                if (nums[max] < nums[i]) {
                    max = i;
                }
                if (nums[min] > nums[i]) {
                    min = i;
                }
            }
            int diff = nums[max] - nums[min];
            if (diff == 0) {
                break;
            }
            count += diff;
            for (int i = 0; i < nums.length; i++) {
                if (i != max) {
                    nums[i] = nums[i] + diff;
                }
            }
        }
        return count;
    }
}
```

</details>

<br>

## Approach 3: Using Sorting [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int minMoves(int[] nums) {
        Arrays.sort(nums);
        int count = 0;
        for (int i = nums.length - 1; i > 0; i--) {
            count += nums[i] - nums[0];
        }
        return count;
    }
}
```

</details>

<br>

## Approach 4: Using DP [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int minMoves(int[] nums) {
        Arrays.sort(nums);
        int moves = 0;
        for (int i = 1; i < nums.length; i++) {
            int diff = (moves + nums[i]) - nums[i - 1];
            nums[i] += moves;
            moves += diff;
        }
        return moves;
    }
}
```

</details>

<br>

## Approach 5: Using Math[Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int minMoves(int[] nums) {
        int moves = 0, min = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length; i++) {
            moves += nums[i];
            min = Math.min(min, nums[i]);
        }
        return moves - min * nums.length;
    }
}
```

</details>

<br>

## Approach 6: Modified Approach Using Maths[Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int minMoves(int[] nums) {
        int moves = 0, min = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length; i++) {
            min = Math.min(min, nums[i]);
        }
        for (int i = 0; i < nums.length; i++) {
            moves += nums[i] - min;
        }
        return moves;
    }
}
```

</details>
