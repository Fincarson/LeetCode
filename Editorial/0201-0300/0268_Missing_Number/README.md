# 268. Missing Number

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/missing-number/)  
`Array` `Hash Table` `Math` `Binary Search` `Bit Manipulation` `Sorting`

**Problem Link:** [LeetCode 268 - Missing Number](https://leetcode.com/problems/missing-number/)

## Problem

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

### Example 1

### Example 2

### Example 3

## Constraints

- n == nums.length
- 1 <= n <= 104
- 0 <= nums[i] <= n
- All the numbers of nums are unique.

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [First Missing Positive](https://leetcode.com/problems/first-missing-positive/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Single Number](https://leetcode.com/problems/single-number/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Couples Holding Hands](https://leetcode.com/problems/couples-holding-hands/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Find Unique Binary String](https://leetcode.com/problems/find-unique-binary-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find the Largest Almost Missing Integer](https://leetcode.com/problems/find-the-largest-almost-missing-integer/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 268. Missing Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Sorting | Java, Python3 |
| Approach #2 HashSet [Accepted] | Java, Python3 |
| Approach #3 Bit Manipulation | Java, Python3 |
| Approach #4 Gauss' Formula [Accepted] | Java, Python3 |

## Approach #1 Sorting

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int missingNumber(int[] nums) {
        Arrays.sort(nums);

        // Ensure that n is at the last index
        if (nums[nums.length-1] != nums.length) {
            return nums.length;
        }
        // Ensure that 0 is at the first index
        else if (nums[0] != 0) {
            return 0;
        }

        // If we get here, then the missing number is on the range (0, n)
        for (int i = 1; i < nums.length; i++) {
            int expectedNum = nums[i-1] + 1;
            if (nums[i] != expectedNum) {
                return expectedNum;
            }
        }

        // Array was not missing any numbers
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def missingNumber(self, nums):
        nums.sort()

        # Ensure that n is at the last index
        if nums[-1] != len(nums):
            return len(nums)
        # Ensure that 0 is at the first index
        elif nums[0] != 0:
            return 0

        # If we get here, then the missing number is on the range (0, n)
        for i in range(1, len(nums)):
            expected_num = nums[i-1] + 1
            if nums[i] != expected_num:
                return expected_num
```

</details>

<br>

## Approach #2 HashSet [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int missingNumber(int[] nums) {
        Set<Integer> numSet = new HashSet<Integer>();
        for (int num : nums) numSet.add(num);

        int expectedNumCount = nums.length + 1;
        for (int number = 0; number < expectedNumCount; number++) {
            if (!numSet.contains(number)) {
                return number;
            }
        }
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def missingNumber(self, nums):
        num_set = set(nums)
        n = len(nums) + 1
        for number in range(n):
            if number not in num_set:
                return number
```

</details>

<br>

## Approach #3 Bit Manipulation

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int missingNumber(int[] nums) {
        int missing = nums.length;
        for (int i = 0; i < nums.length; i++) {
            missing ^= i ^ nums[i];
        }
        return missing;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def missingNumber(self, nums):
        missing = len(nums)
        for i, num in enumerate(nums):
            missing ^= i ^ num
        return missing
```

</details>

<br>

## Approach #4 Gauss' Formula [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int missingNumber(int[] nums) {
        int expectedSum = nums.length*(nums.length + 1)/2;
        int actualSum = 0;
        for (int num : nums) actualSum += num;
        return expectedSum - actualSum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def missingNumber(self, nums):
        expected_sum = len(nums)*(len(nums)+1)//2
        actual_sum = sum(nums)
        return expected_sum - actual_sum
```

</details>
