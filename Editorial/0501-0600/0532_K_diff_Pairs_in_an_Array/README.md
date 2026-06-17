# 532. K-diff Pairs in an Array

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/k-diff-pairs-in-an-array/)  
`Array` `Hash Table` `Two Pointers` `Binary Search` `Sorting`

**Problem Link:** [LeetCode 532 - K-diff Pairs in an Array](https://leetcode.com/problems/k-diff-pairs-in-an-array/)

## Problem

Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

- 0 <= i, j < nums.length
- i != j
- |nums[i] - nums[j]| == k

Notice that |val| denotes the absolute value of val.

### Example 1

```text
Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
```

### Example 2

```text
Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
```

### Example 3

```text
Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
```

## Constraints

- 1 <= nums.length <= 104
- -107 <= nums[i] <= 107
- 0 <= k <= 107

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Absolute Difference in BST](https://leetcode.com/problems/minimum-absolute-difference-in-bst/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Count Number of Pairs With Absolute Difference K](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Kth Smallest Product of Two Sorted Arrays](https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Count Number of Bad Pairs](https://leetcode.com/problems/count-number-of-bad-pairs/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Number of Pairs Satisfying Inequality](https://leetcode.com/problems/number-of-pairs-satisfying-inequality/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Minimum Absolute Difference Between Elements With Constraint](https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 532. K-diff Pairs in an Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java, Python3 |
| Two Pointers | Java, Python3 |
| Hashmap | Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
import java.util.Arrays;

public class Solution {
    public int findPairs(int[] nums, int k) {

        Arrays.sort(nums);

        int result = 0;

        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.length; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                if (Math.abs(nums[j] - nums[i]) == k)
                    result++;
            }
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findPairs(self, nums, k):

        s_nums = sorted(nums)

        result = 0

        for i in range(len(s_nums)):
            if (i > 0 and s_nums[i] == s_nums[i - 1]):
                continue
            for j in range(i + 1, len(s_nums)):
                if (j > i + 1 and s_nums[j] == s_nums[j - 1]):
                    continue

                if abs(s_nums[j] - s_nums[i] == k):
                    result += 1

        return result
```

</details>

<br>

## Approach 2: Two Pointers

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
import java.util.Arrays;

public class Solution {
    public int findPairs(int[] nums, int k) {

        Arrays.sort(nums);

        int left = 0, right = 1;
        int result = 0;

        while (left < nums.length && right < nums.length) {
            if (left == right || nums[right] - nums[left] < k) {
                // List item 1 in the text
                right++;      
            } else if (nums[right] - nums[left] > k) {
                // List item 2 in the text
                left++;       
            } else {
                // List item 3 in the text
                left++;
                result++;
                while (left < nums.length && nums[left] == nums[left - 1])
                    left++;
            }
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:

        nums = sorted(nums)

        left = 0
        right = 1

        result = 0

        while (left < len(nums) and right < len(nums)):
            if (left == right or nums[right] - nums[left] < k):
                # List item 1 in the text
                right += 1
            elif nums[right] - nums[left] > k:
                # List item 2 in the text
                left += 1
            else:
                # List item 3 in the text
                left += 1
                result += 1
                while (left < len(nums) and nums[left] == nums[left - 1]):
                    left += 1

        return result
```

</details>

<br>

## Approach 3: Hashmap

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int findPairs(int[] nums, int k) {

        int result = 0;

        HashMap <Integer,Integer> counter = new HashMap<>();
        for (int n: nums) {
            counter.put(n, counter.getOrDefault(n, 0)+1);
        }


        for (Map.Entry <Integer, Integer> entry: counter.entrySet()) {
            int x = entry.getKey();
            int val = entry.getValue();
            if (k > 0 && counter.containsKey(x + k)) {
                result++;
            } else if (k == 0 && val > 1) {
                result++;
            }
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import Counter

class Solution:
    def findPairs(self, nums, k):
        result = 0

        counter = Counter(nums)

        for x in counter:
            if k > 0 and x + k in counter:
                result += 1
            elif k == 0 and counter[x] > 1:
                result += 1
        return result
```

</details>
