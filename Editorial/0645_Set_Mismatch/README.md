# 645. Set Mismatch

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/set-mismatch/)  
`Array` `Hash Table` `Bit Manipulation` `Sorting`

**Problem Link:** [LeetCode 645 - Set Mismatch](https://leetcode.com/problems/set-mismatch/)

## Problem

You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

### Example 1

```text
Input: nums = [1,2,2,4]
Output: [2,3]
```

### Example 2

```text
Input: nums = [1,1]
Output: [1,2]
```

## Constraints

- 2 <= nums.length <= 104
- 1 <= nums[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 645. Set Mismatch

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java |
| Better Brute Force | Java |
| Using Sorting | Java |
| Using Map | Java |
| Using Extra Array | Java |
| Using Constant Space | Java |
| Using XOR | Java |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int[] findErrorNums(int[] nums) {
        int dup = -1, missing = -1;
        for (int i = 1; i <= nums.length; i++) {
            int count = 0;
            for (int j = 0; j < nums.length; j++) {
                if (nums[j] == i)
                    count++;
            }
            if (count == 2)
                dup = i;
            else if (count == 0)
                missing = i;
        }
        return new int[] {dup, missing};
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
    public int[] findErrorNums(int[] nums) {
        int dup = -1, missing = -1;;
        for (int i = 1; i <= nums.length; i++) {
            int count = 0;
            for (int j = 0; j < nums.length; j++) {
                if (nums[j] == i)
                    count++;
            }
            if (count == 2)
                dup = i;
            else if (count == 0)
                missing = i;
            if (dup > 0 && missing > 0)
                break;
        }
        return new int[] {dup, missing};
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
    public int[] findErrorNums(int[] nums) {
        Arrays.sort(nums);
        int dup = -1, missing = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i - 1])
                dup = nums[i];
            else if (nums[i] > nums[i - 1] + 1)
                missing = nums[i - 1] + 1;
        }
        return new int[] {dup, nums[nums.length - 1] != nums.length ? nums.length : missing};
    }
}
```

</details>

<br>

## Approach 4: Using Map

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int[] findErrorNums(int[] nums) {
        Map < Integer, Integer > map = new HashMap();
        int dup = -1, missing = 1;
        for (int n: nums) {
            map.put(n, map.getOrDefault(n, 0) + 1);
        }
        for (int i = 1; i <= nums.length; i++) {
            if (map.containsKey(i)) {
                if (map.get(i) == 2)
                    dup = i;
            } else
                missing = i;
        }
        return new int[]{dup, missing};
    }
}
```

</details>

<br>

## Approach 5: Using Extra Array

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int[] findErrorNums(int[] nums) {
        int[] arr = new int[nums.length + 1];
        int dup = -1, missing = 1;
        for (int i = 0; i < nums.length; i++) {
            arr[nums[i]] += 1;
        }
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] == 0)
                missing = i;
            else if (arr[i] == 2)
                dup = i;
        }
        return new int[]{dup, missing};
    }
}
```

</details>

<br>

## Approach 6: Using Constant Space

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int[] findErrorNums(int[] nums) {
        int dup = -1, missing = 1;
        for (int n: nums) {
            if (nums[Math.abs(n) - 1] < 0)
                dup = Math.abs(n);
            else
                nums[Math.abs(n) - 1] *= -1;
        }
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > 0)
                missing = i + 1;
        }
        return new int[]{dup, missing};
    }
}
```

</details>

<br>

## Approach 7: Using XOR

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int[] findErrorNums(int[] nums) {
        int xor = 0, xor0 = 0, xor1 = 0;
        for (int n: nums)
            xor ^= n;
        for (int i = 1; i <= nums.length; i++)
            xor ^= i;
        int rightmostbit = xor & ~(xor - 1);
        for (int n: nums) {
            if ((n & rightmostbit) != 0)
                xor1 ^= n;
            else
                xor0 ^= n;
        }
        for (int i = 1; i <= nums.length; i++) {
            if ((i & rightmostbit) != 0)
                xor1 ^= i;
            else
                xor0 ^= i;
        }
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == xor0)
                return new int[]{xor0, xor1};
        }
        return new int[]{xor1, xor0};
    }
}
```

</details>
