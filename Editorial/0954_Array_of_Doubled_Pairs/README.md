# 954. Array of Doubled Pairs

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/array-of-doubled-pairs/)  
`Array` `Hash Table` `Greedy` `Sorting`

**Problem Link:** [LeetCode 954 - Array of Doubled Pairs](https://leetcode.com/problems/array-of-doubled-pairs/)

## Problem

Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.

### Example 1

```text
Input: arr = [3,1,3,6]
Output: false
```

### Example 2

```text
Input: arr = [2,1,2,6]
Output: false
```

### Example 3

```text
Input: arr = [4,-2,2,-4]
Output: true
Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
```

## Constraints

- 2 <= arr.length <= 3 * 104
- arr.length is even.
- -105 <= arr[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find Original Array From Doubled Array](https://leetcode.com/problems/find-original-array-from-doubled-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 954. Array of Doubled Pairs

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy | Java, Python |

## Approach 1: Greedy

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean canReorderDoubled(int[] A) {
        // count[x] = the number of occurrences of x in A
        Map<Integer, Integer> count = new HashMap();
        for (int x: A)
            count.put(x, count.getOrDefault(x, 0) + 1);

        // B = A as Integer[], sorted by absolute value
        Integer[] B = new Integer[A.length];
        for (int i = 0; i < A.length; ++i)
            B[i] = A[i];
        Arrays.sort(B, Comparator.comparingInt(Math::abs));

        for (int x: B) {
            // If this can't be consumed, skip
            if (count.get(x) == 0) continue;
            // If this doesn't have a doubled partner, the answer is false
            if (count.getOrDefault(2*x, 0) <= 0) return false;

            // Write x, 2*x
            count.put(x, count.get(x) - 1);
            count.put(2*x, count.get(2*x) - 1);
        }

        // If we have written everything, the answer is true
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def canReorderDoubled(self, A):
        count = collections.Counter(A)
        for x in sorted(A, key = abs):
            if count[x] == 0: continue
            if count[2*x] == 0: return False
            count[x] -= 1
            count[2*x] -= 1

        return True
```

</details>
