# 440. K-th Smallest in Lexicographical Order

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/)  
`Trie`

**Problem Link:** [LeetCode 440 - K-th Smallest in Lexicographical Order](https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/)

## Problem

Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

### Example 1

```text
Input: n = 13, k = 2
Output: 10
Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
```

### Example 2

```text
Input: n = 1, k = 1
Output: 1
```

## Constraints

- 1 <= k <= n <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Special Integers](https://leetcode.com/problems/count-special-integers/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 440. K-th Smallest in Lexicographical Order

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Prefix Tree | C++, Java, Python3 |

## Approach: Prefix Tree

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;

        while (k > 0) {
            int step = countSteps(n, curr, curr + 1);
            if (step <= k) {
                curr++;
                k -= step;
            } else {
                curr *= 10;
                k--;
            }
        }

        return curr;
    }

private:
    int countSteps(int n, long prefix1, long prefix2) {
        int steps = 0;
        while (prefix1 <= n) {
            steps += min((long)(n + 1), prefix2) - prefix1;
            prefix1 *= 10;
            prefix2 *= 10;
        }
        return steps;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int findKthNumber(int n, int k) {
        int curr = 1;
        k--;

        while (k > 0) {
            int step = countSteps(n, curr, curr + 1);
            // If the steps are less than or equal to k, we skip this prefix's subtree
            if (step <= k) {
                // Move to the next prefix and decrease k by the number of steps we skip
                curr++;
                k -= step;
            } else {
                // Move to the next level of the tree and decrement k by 1
                curr *= 10;
                k--;
            }
        }

        return curr;
    }

    // To count how many numbers exist between prefix1 and prefix2
    private int countSteps(int n, long prefix1, long prefix2) {
        int steps = 0;
        while (prefix1 <= n) {
            steps += Math.min(n + 1, prefix2) - prefix1;
            prefix1 *= 10;
            prefix2 *= 10;
        }
        return steps;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def findKthNumber(self, n, k):
        curr = 1
        k -= 1

        while k > 0:
            step = self._count_steps(n, curr, curr + 1)
            # If the steps are less than or equal to k, we skip this prefix's subtree
            if step <= k:
                # Move to the next prefix and decrease k by the number of steps we skip
                curr += 1
                k -= step
            else:
                # Move to the next level of the tree and decrement k by 1
                curr *= 10
                k -= 1

        return curr

    # To count how many numbers exist between prefix1 and prefix2
    def _count_steps(self, n, prefix1, prefix2):
        steps = 0
        while prefix1 <= n:
            steps += min(n + 1, prefix2) - prefix1
            prefix1 *= 10
            prefix2 *= 10
        return steps
```

</details>
