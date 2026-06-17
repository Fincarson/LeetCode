# 548. Split Array with Equal Sum

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/split-array-with-equal-sum/)  
`Array` `Hash Table` `Prefix Sum`

**Problem Link:** [LeetCode 548 - Split Array with Equal Sum](https://leetcode.com/problems/split-array-with-equal-sum/)

## Problem

Given an integer array nums of length n, return true if there is a triplet (i, j, k) which satisfies the following conditions:

- 0 < i, i + 1 < j, j + 1 < k < n - 1
- The sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1) is equal.

### Example 1

```text
Input: nums = [1,2,1,2,1,2,1]
Output: true
Explanation:
i = 1, j = 3, k = 5.
sum(0, i - 1) = sum(0, 0) = 1
sum(i + 1, j - 1) = sum(2, 2) = 1
sum(j + 1, k - 1) = sum(4, 4) = 1
sum(k + 1, n - 1) = sum(6, 6) = 1
```

### Example 2

```text
Input: nums = [1,2,1,2,1,2,1,2]
Output: false
```

## Constraints

- n == nums.length
- 1 <= n <= 2000
- -106 <= nums[i] <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Fair Distribution of Cookies](https://leetcode.com/problems/fair-distribution-of-cookies/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Number of Ways to Split a String](https://leetcode.com/problems/number-of-ways-to-split-a-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 548. Split Array with Equal Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Brute Force [Time Limit Exceeded] | Java |
| Approach #2 Cumulative Sum [Time Limit Exceeded] | Java |
| Approach #3 Slightly Better Approach [Time Limit Exceeded] | Java |
| Approach #4 Using HashMap [Time limit Exceeded] | Java |
| Approach #5 Using Cumulative Sum and HashSet [Accepted] | Java |

## Approach #1 Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

public class Solution {

    public int sum(int[] nums, int l, int r) {
        int summ = 0;
        for (int i = l; i < r; i++)
            summ += nums[i];
        return summ;
    }

    public boolean splitArray(int[] nums) {
        if (nums.length < 7)
            return false;
        for (int i = 1; i < nums.length - 5; i++) {
            int sum1 = sum(nums, 0, i);
            for (int j = i + 2; j < nums.length - 3; j++) {
                int sum2 = sum(nums, i + 1, j);
                for (int k = j + 2; k < nums.length - 1; k++) {
                    int sum3 = sum(nums, j + 1, k);
                    int sum4 = sum(nums, k + 1, nums.length);
                    if (sum1 == sum2 && sum3 == sum4 && sum2 == sum4)
                        return true;
                }
            }
        }
        return false;
    }
}
```

</details>

<br>

## Approach #2 Cumulative Sum [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean splitArray(int[] nums) {
        if (nums.length < 7)
            return false;
        int[] sum = new int[nums.length];
        sum[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
        for (int i = 1; i < nums.length - 5; i++) {
            int sum1 = sum[i - 1];
            for (int j = i + 2; j < nums.length - 3; j++) {
                int sum2 = sum[j - 1] - sum[i];
                for (int k = j + 2; k < nums.length - 1; k++) {
                    int sum3 = sum[k - 1] - sum[j];
                    int sum4 = sum[nums.length - 1] - sum[k];
                    if (sum1 == sum2 && sum3 == sum4 && sum2 == sum4)
                        return true;
                }
            }
        }
        return false;
    }
}
```

</details>

<br>

## Approach #3 Slightly Better Approach [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean splitArray(int[] nums) {
        if (nums.length < 7)
            return false;

        int[] sum = new int[nums.length];
        sum[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
        for (int i = 1; i < nums.length - 5; i++) {
            int sum1 = sum[i - 1];
            for (int j = i + 2; j < nums.length - 3; j++) {
                int sum2 = sum[j - 1] - sum[i];
                if (sum1 != sum2)
                    continue;
                for (int k = j + 2; k < nums.length - 1; k++) {
                    int sum3 = sum[k - 1] - sum[j];
                    int sum4 = sum[nums.length - 1] - sum[k];
                    if (sum3 == sum4 && sum2 == sum4)
                        return true;
                }
            }
        }
        return false;
    }
}
```

</details>

<br>

## Approach #4 Using HashMap [Time limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean splitArray(int[] nums) {
        HashMap < Integer, ArrayList < Integer >> map = new HashMap < > ();
        int summ = 0, tot = 0;
        for (int i = 0; i < nums.length; i++) {
            summ += nums[i];
            if (map.containsKey(summ))
                map.get(summ).add(i);
            else {
                map.put(summ, new ArrayList < Integer > ());
                map.get(summ).add(i);
            }
            tot += nums[i];
        }
        summ = nums[0];
        for (int i = 1; i < nums.length - 5; i++) {
            if (map.containsKey(2 * summ + nums[i])) {
                for (int j: map.get(2 * summ + nums[i])) {
                    j++;
                    if (j > i + 1 && j < nums.length - 3 && map.containsKey(3 * summ + nums[i] + nums[j])) {
                        for (int k: map.get(3 * summ + nums[j] + nums[i])) {
                            k++;
                            if (k < nums.length - 1 && k > j + 1 && 4 * summ + nums[i] + nums[j] + nums[k] == tot)
                                return true;
                        }
                    }
                }
            }
            summ += nums[i];
        }
        return false;
    }
}
```

</details>

<br>

## Approach #5 Using Cumulative Sum and HashSet [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean splitArray(int[] nums) {
        if (nums.length < 7)
            return false;
        int[] sum = new int[nums.length];
        sum[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
        for (int j = 3; j < nums.length - 3; j++) {
            HashSet < Integer > set = new HashSet < > ();
            for (int i = 1; i < j - 1; i++) {
                if (sum[i - 1] == sum[j - 1] - sum[i])
                    set.add(sum[i - 1]);
            }
            for (int k = j + 2; k < nums.length - 1; k++) {
                if (sum[nums.length - 1] - sum[k] == sum[k - 1] - sum[j] && set.contains(sum[k - 1] - sum[j]))
                    return true;
            }
        }
        return false;
    }
}
```

</details>
