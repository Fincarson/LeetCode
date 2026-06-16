# 1228. Missing Number In Arithmetic Progression

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/missing-number-in-arithmetic-progression/)  
`Array` `Math`

**Problem Link:** [LeetCode 1228 - Missing Number In Arithmetic Progression](https://leetcode.com/problems/missing-number-in-arithmetic-progression/)

## Problem

In some array arr, the values were in arithmetic progression: the values arr[i + 1] - arr[i] are all equal for every 0 <= i < arr.length - 1.

A value from arr was removed that was not the first or last value in the array.

Given arr, return the removed value.

### Example 1

```text
Input: arr = [5,7,11,13]
Output: 9
Explanation: The previous array was [5,7,9,11,13].
```

### Example 2

```text
Input: arr = [15,13,12]
Output: 14
Explanation: The previous array was [15,14,13,12].
```

## Constraints

- 3 <= arr.length <= 1000
- 0 <= arr[i] <= 105
- The given array is guaranteed to be a valid array.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1228. Missing Number In Arithmetic Progression

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Linear search | C++, Java |
| Binary Search | C++, Java |

## Approach 1: Linear search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();

        // 1. Get the difference `difference`.
        int difference = (arr.back() - arr.front()) / n;

        // 2. The expected element equals the starting element.
        int expected = arr.front();

        for (int &val : arr) {
            // Return the expected value that doesn't match val.
            if (val != expected) return expected;

            // Next element will be expected element + `difference`.
            expected += difference;
        }
        return expected;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int missingNumber(int[] arr) {
        int n = arr.length;

        // Get the difference `difference`.
        int difference = (arr[arr.length - 1] - arr[0]) / n;

        // The expected element equals the starting element.
        int expected = arr[0];

        for (int val : arr) {
            // Return the expected value that doesn't match val.
            if (val != expected) return expected;

            // Next element will be expected element + `difference`.
            expected += difference;
        }
        return expected;
    }
}
```

</details>

<br>

## Approach 2: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();

        // Get the difference `difference`.
        int difference = (arr.back() - arr.front()) / n;
        int lo = 0;
        int hi = n - 1;

        // Basic binary search template.
        while (lo < hi) {
            int mid = (lo + hi) / 2;

            // All numbers upto `mid` have no missing number, so search on the right side.
            if (arr[mid] == arr.front() + mid * difference) {
                lo = mid + 1;
            }

            // A number is missing before `mid` inclusive of `mid` itself.
            else {
                hi = mid;
            }
        }

        // Index `lo` will be the position with the first incorrect number.
        // Return the value that was supposed to be at this index.
        return arr.front() + difference * lo;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int missingNumber(int arr[]) {
        int n = arr.length;

        // 1. Get the difference `difference`.
        int difference = (arr[n - 1] - arr[0]) / n;
        int lo = 0;
        int hi = n - 1;

        // Basic binary search template.
        while (lo < hi) {
            int mid = (lo + hi) / 2;

            // All numbers upto `mid` have no missing number, so search on the right side.
            if (arr[mid] == arr[0] + mid * difference) {
                lo = mid + 1;
            }

            // A number is missing before `mid` inclusive of `mid` itself.
            else {
                hi = mid;
            }
        }

        // Index `lo` will be the position with the first incorrect number.
        // Return the value that was supposed to be at this index.
        return arr[0] + difference * lo;
    }
}
```

</details>
