# 307. Range Sum Query - Mutable

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/range-sum-query-mutable/)  
`Array` `Divide and Conquer` `Design` `Binary Indexed Tree` `Segment Tree`

**Problem Link:** [LeetCode 307 - Range Sum Query - Mutable](https://leetcode.com/problems/range-sum-query-mutable/)

## Problem

Given an integer array nums, handle multiple queries of the following types:

Implement the NumArray class:

- NumArray(int[] nums) Initializes the object with the integer array nums.
- void update(int index, int val) Updates the value of nums[index] to be val.
- int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

### Example 1

```text
Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
```

## Constraints

- 1 <= nums.length <= 3 * 104
- -100 <= nums[i] <= 100
- 0 <= index < nums.length
- -100 <= val <= 100
- 0 <= left <= right < nums.length
- At most 3 * 104 calls will be made to update and sumRange.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Range Sum Query 2D - Mutable](https://leetcode.com/problems/range-sum-query-2d-mutable/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Shifting Letters II](https://leetcode.com/problems/shifting-letters-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 307. Range Sum Query - Mutable

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Naive | Java |
| Sqrt Decomposition | Java |
| Segment Tree | Java |

## Approach 1: Naive

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
private int[] nums;
public int sumRange(int i, int j) {
    int sum = 0;
    for (int l = i; l <= j; l++) {
        sum += data[l];
    }
    return sum;
}

public int update(int i, int val) {
    nums[i] = val;
}
// Time Limit Exceeded
```

</details>

<br>

## Approach 2: Sqrt Decomposition

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
private int[] b;
private int len;
private int[] nums;

public NumArray(int[] nums) {
    this.nums = nums;
    double l = Math.sqrt(nums.length);
    len = (int) Math.ceil(nums.length/l);
    b = new int [len];
    for (int i = 0; i < nums.length; i++)
        b[i / len] += nums[i];
}

public int sumRange(int i, int j) {
    int sum = 0;
    int startBlock = i / len;
    int endBlock = j / len;
    if (startBlock == endBlock) {
        for (int k = i; k <= j; k++)
            sum += nums[k];
    } else {
        for (int k = i; k <= (startBlock + 1) * len - 1; k++)
            sum += nums[k];
        for (int k = startBlock + 1; k <= endBlock - 1; k++)
            sum += b[k];
        for (int k = endBlock * len; k <= j; k++)
            sum += nums[k];
    }
    return sum;
}

public void update(int i, int val) {
    int b_l = i / len;
    b[b_l] = b[b_l] - nums[i] + val;
    nums[i] = val;
}
// Accepted
```

</details>

<br>

## Approach 3: Segment Tree

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
int[] tree;
int n;
public NumArray(int[] nums) {
    if (nums.length > 0) {
        n = nums.length;
        tree = new int[n * 2];
        buildTree(nums);
    }
}
private void buildTree(int[] nums) {
    for (int i = n, j = 0;  i < 2 * n; i++,  j++)
        tree[i] = nums[j];
    for (int i = n - 1; i > 0; --i)
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
}
```

</details>
