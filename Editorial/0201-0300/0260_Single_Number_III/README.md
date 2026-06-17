# 260. Single Number III

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/single-number-iii/)  
`Array` `Bit Manipulation`

**Problem Link:** [LeetCode 260 - Single Number III](https://leetcode.com/problems/single-number-iii/)

## Problem

Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

### Example 1

```text
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
```

### Example 2

```text
Input: nums = [-1,0]
Output: [-1,0]
```

### Example 3

```text
Input: nums = [0,1]
Output: [1,0]
```

## Constraints

- 2 <= nums.length <= 3 * 104
- -231 <= nums[i] <= 231 - 1
- Each integer in nums will appear twice, only two integers will appear once.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Single Number](https://leetcode.com/problems/single-number/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Single Number II](https://leetcode.com/problems/single-number-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find The Original Array of Prefix Xor](https://leetcode.com/problems/find-the-original-array-of-prefix-xor/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find the XOR of Numbers Which Appear Twice](https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 260. Single Number III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hashmap | Java, Python |
| Two bitmasks | Java, Python |

## Approach 1: Hashmap

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int[] singleNumber(int[] nums) {
    Map<Integer, Integer> hashmap = new HashMap();
    for (int n : nums)
      hashmap.put(n, hashmap.getOrDefault(n, 0) + 1);

    int[] output = new int[2];
    int idx = 0;
    for (Map.Entry<Integer, Integer> item : hashmap.entrySet())
      if (item.getValue() == 1) output[idx++] = item.getKey();

    return output;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
from collections import Counter
class Solution:
    def singleNumber(self, nums: int) -> List[int]:
        hashmap = Counter(nums)
        return [x for x in hashmap if hashmap[x] == 1]
```

</details>

<br>

## Approach 2: Two bitmasks

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int[] singleNumber(int[] nums) {
    // difference between two numbers (x and y) which were seen only once
    int bitmask = 0;
    for (int num : nums) bitmask ^= num;

    // rightmost 1-bit diff between x and y
    int diff = bitmask & (-bitmask);

    int x = 0;
    // bitmask which will contain only x
    for (int num : nums) if ((num & diff) != 0) x ^= num;

    return new int[]{x, bitmask^x};
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def singleNumber(self, nums: int) -> List[int]:
        # difference between two numbers (x and y) which were seen only once
        bitmask = 0
        for num in nums:
            bitmask ^= num
        
        # rightmost 1-bit diff between x and y
        diff = bitmask & (-bitmask)
        
        x = 0
        for num in nums:
            # bitmask which will contain only x
            if num & diff:
                x ^= num
        
        return [x, bitmask^x]
```

</details>
