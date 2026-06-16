# 1539. Kth Missing Positive Number

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/kth-missing-positive-number/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 1539 - Kth Missing Positive Number](https://leetcode.com/problems/kth-missing-positive-number/)

## Problem

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

### Example 1

```text
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
```

### Example 2

```text
Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
```

## Constraints

- 1 <= arr.length <= 1000
- 1 <= arr[i] <= 1000
- 1 <= k <= 1000
- arr[i] < arr[j] for 1 <= i < j <= arr.length

Follow up:

Could you solve this problem in less than O(n) complexity?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Append K Integers With Minimal Sum](https://leetcode.com/problems/append-k-integers-with-minimal-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1539. Kth Missing Positive Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force, $$\mathcal{O}(N)$$ time | Java, Python3 |
| Binary Search, $$\mathcal{O}(\log N)$$ time | Java, Python3 |

## Approach 1: Brute Force, $$\mathcal{O}(N)$$ time

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findKthPositive(int[] arr, int k) {
        for (int num : arr) {
            if (num <= k) {
                k++;
            } else {
                break;
            }
        }
        return k;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        for num in arr:
            if num <= k:
                k += 1
            elif num > k:
                break
        return k
```

</details>

<br>

## Approach 2: Binary Search, $$\mathcal{O}(\log N)$$ time

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findKthPositive(int[] arr, int k) {
        int left = 0, right = arr.length - 1;
        while (left <= right) {
            int pivot = left + (right - left) / 2;
            // If number of positive integers
            // which are missing before arr[pivot]
            // is less than k -->
            // continue to search on the right.
            if (arr[pivot] - pivot - 1 < k) {
                left = pivot + 1;
            // Otherwise, go left.
            } else {
                right = pivot - 1;
            }
        }

        // At the end of the loop, left = right + 1,
        // and the kth missing is in-between arr[right] and arr[left].
        // The number of integers missing before arr[right] is
        // arr[right] - right - 1 -->
        // the number to return is
        // arr[right] + k - (arr[right] - right - 1) = k + left
        return left + k;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        left, right = 0, len(arr) - 1
        while left <= right:
            pivot = (left + right) // 2
            # If number of positive integers
            # which are missing before arr[pivot]
            # is less than k -->
            # continue to search on the right.
            if arr[pivot] - pivot - 1 < k:
                left = pivot + 1
            # Otherwise, go left.
            else:
                right = pivot - 1

        # At the end of the loop, left = right + 1,
        # and the kth missing is in-between arr[right] and arr[left].
        # The number of integers missing before arr[right] is
        # arr[right] - right - 1 -->
        # the number to return is
        # arr[right] + k - (arr[right] - right - 1) = k + left
        return left + k
```

</details>
