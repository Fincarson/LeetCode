# 303. Range Sum Query - Immutable

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/range-sum-query-immutable/)  
`Array` `Design` `Prefix Sum`

**Problem Link:** [LeetCode 303 - Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)

## Problem

Given an integer array nums, handle multiple queries of the following type:

Implement the NumArray class:

- NumArray(int[] nums) Initializes the object with the integer array nums.
- int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

### Example 1

```text
Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
```

## Constraints

- 1 <= nums.length <= 104
- -105 <= nums[i] <= 105
- 0 <= left <= right < nums.length
- At most 104 calls will be made to sumRange.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Range Sum Query - Mutable](https://leetcode.com/problems/range-sum-query-mutable/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Size Subarray Sum Equals k](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Sum of Variable Length Subarrays](https://leetcode.com/problems/sum-of-variable-length-subarrays/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 303. Range Sum Query - Immutable

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force [Time Limit Exceeded] | Java |
| Caching [Accepted] | Java |
| PrefixSum, Caching [Accepted] | Java |

## Approach 1: Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
private int[] data;

public NumArray(int[] nums) {
    data = nums;
}

public int sumRange(int i, int j) {
    int sum = 0;
    for (int k = i; k <= j; k++) {
        sum += data[k];
    }
    return sum;
}
```

</details>

<br>

## Approach 2: Caching [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
private Map<Pair<Integer, Integer>, Integer> map = new HashMap<>();

public NumArray(int[] nums) {
    for (int i = 0; i < nums.length; i++) {
        int sum = 0;
        for (int j = i; j < nums.length; j++) {
            sum += nums[j];
            map.put(Pair.create(i, j), sum);
        }
    }
}

public int sumRange(int i, int j) {
    return map.get(Pair.create(i, j));
}
```

</details>

<br>

## Approach 3: PrefixSum, Caching [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
private int[] sum;

public NumArray(int[] nums) {
    sum = new int[nums.length + 1];
    for (int i = 0; i < nums.length; i++) {
        sum[i + 1] = sum[i] + nums[i];
    }
}

public int sumRange(int i, int j) {
    return sum[j + 1] - sum[i];
}
```

</details>
