# 927. Three Equal Parts

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/three-equal-parts/)  
`Array` `Math`

**Problem Link:** [LeetCode 927 - Three Equal Parts](https://leetcode.com/problems/three-equal-parts/)

## Problem

You are given an array arr which consists of only zeros and ones, divide the array into three non-empty parts such that all of these parts represent the same binary value.

If it is possible, return any [i, j] with i + 1 < j, such that:

- arr[0], arr[1], ..., arr[i] is the first part,
- arr[i + 1], arr[i + 2], ..., arr[j - 1] is the second part, and
- arr[j], arr[j + 1], ..., arr[arr.length - 1] is the third part.
- All three parts have equal binary values.

If it is not possible, return [-1, -1].

Note that the entire part is used when considering what binary value it represents. For example, [1,1,0] represents 6 in decimal, not 3. Also, leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.

### Example 1

```text
Input: arr = [1,0,1,0,1]
Output: [0,3]
```

### Example 2

```text
Input: arr = [1,1,0,1,1]
Output: [-1,-1]
```

### Example 3

```text
Input: arr = [1,1,0,0,1]
Output: [0,2]
```

## Constraints

- 3 <= arr.length <= 3 * 104
- arr[i] is 0 or 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 927. Three Equal Parts

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Equal Ones | Java, Python3 |

## Approach 1: Equal Ones

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private static final int[] IMPOSSIBLE = new int[] {-1, -1};

    public int[] threeEqualParts(int[] arr) {
        int n = arr.length;
        
        // Count how many 1s are in arr.
        int totalOnes = 0;
        for (int bit : arr) {
            totalOnes += bit;
        }
        
        // If total number of ones is not evenly divisible by 3, then no solution exists.
        if (totalOnes % 3 != 0) {
            return IMPOSSIBLE;
        }
        
        // Otherwise, each part should contain an equal amount of 1s.
        int targetOnes = totalOnes / 3;
        if (targetOnes == 0) {
            return new int[] {0, n - 1};
        }

        // i1, j1 marks the index of the first and last one in the first block of 1s, etc.
        int i1 = -1, j1 = -1, i2 = -1, j2 = -1, i3 = -1, j3 = -1;
        
        //Find the index of the first and last 1 in each block of ones.
        int oneCount = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 1) {
                oneCount += 1;
                if (oneCount == 1) i1 = i;
                if (oneCount == targetOnes) j1 = i;
                if (oneCount == targetOnes + 1) i2 = i;
                if (oneCount == 2 * targetOnes) j2 = i;
                if (oneCount == 2 * targetOnes + 1) i3 = i;
                if (oneCount == 3 * targetOnes) j3 = i;
            }
        }

        // The array is in the form W [i1, j1] X [i2, j2] Y [i3, j3] Z
        // where each [i, j] is a block of 1s and W, X, Y, and Z represent blocks of 0s.
        int[] part1 = Arrays.copyOfRange(arr, i1, j1 + 1);
        int[] part2 = Arrays.copyOfRange(arr, i2, j2 + 1);
        int[] part3 = Arrays.copyOfRange(arr, i3, j3 + 1);

        if (!Arrays.equals(part1, part2) || !Arrays.equals(part1, part3)) {
            return IMPOSSIBLE;
        }

        // The number of zeros after the left, middle, and right parts
        int trailingZerosLeft = i2 - j1 - 1;
        int trailingZerosMid = i3 - j2 - 1;
        int trailingZeros = n - j3 - 1;

        if (trailingZeros > Math.min(trailingZerosLeft, trailingZerosMid)) {
            return IMPOSSIBLE;
        }
        return new int[] {j1 + trailingZeros, j2 + trailingZeros + 1};
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def threeEqualParts(self, arr: List[int]) -> List[int]:
        IMPOSSIBLE = [-1, -1]
        
        # If total number of ones is not evenly divisible by 3, then no solution exists.
        total_ones = sum(arr)
        if total_ones % 3: 
            return IMPOSSIBLE
        
        # Otherwise, each part should contain an equal amount of ones.
        target_ones = total_ones // 3
        if target_ones == 0:
            return [0, len(arr) - 1]

        # Find the index of the first and last 1 in each block of ones.
        breaks = []
        one_count = 0
        for i, bit in enumerate(arr):
            if bit == 1:
                one_count += bit
                if one_count in {1, target_ones + 1, 2 * target_ones + 1}:
                    breaks.append(i)
                if one_count in {target_ones, 2 * target_ones, 3 * target_ones}:
                    breaks.append(i)

        # i1, j1 marks the index of the first and last one in the first block of 1s, etc.
        i1, j1, i2, j2, i3, j3 = breaks

        # The array is in the form W [i1, j1] X [i2, j2] Y [i3, j3] Z
        # where each [i, j] is a block of 1s and W, X, Y, and Z represent blocks of 0s.
        if not(arr[i1 : j1 + 1] == arr[i2 : j2 + 1] == arr[i3 : j3 + 1]):
            return [-1, -1]

        # The number of zeros after the left, middle, and right parts
        trailing_zeros_left = i2 - j1 - 1
        trailing_zeros_mid = i3 - j2 - 1
        trailing_zeros = len(arr) - j3 - 1

        if trailing_zeros > min(trailing_zeros_left, trailing_zeros_mid): 
            return IMPOSSIBLE
        
        j1 += trailing_zeros
        j2 += trailing_zeros
        return [j1, j2 + 1]
```

</details>
