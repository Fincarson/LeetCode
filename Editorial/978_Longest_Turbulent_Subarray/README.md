# 978. Longest Turbulent Subarray

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/longest-turbulent-subarray/)  
`Array` `Dynamic Programming` `Sliding Window`

**Problem Link:** [LeetCode 978 - Longest Turbulent Subarray](https://leetcode.com/problems/longest-turbulent-subarray/)

## Problem

Given an integer array arr, return the length of a maximum size turbulent subarray of arr.

A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:

- For i <= k < j:

		arr[k] > arr[k + 1] when k is odd, and
		arr[k] < arr[k + 1] when k is even.
- Or, for i <= k < j:

		arr[k] > arr[k + 1] when k is even, and
		arr[k] < arr[k + 1] when k is odd.

### Example 1

```text
Input: arr = [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
```

### Example 2

```text
Input: arr = [4,8,12,16]
Output: 2
```

### Example 3

```text
Input: arr = [100]
Output: 1
```

## Constraints

- 1 <= arr.length <= 4 * 104
- 0 <= arr[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Alternating Subarray](https://leetcode.com/problems/longest-alternating-subarray/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 978. Longest Turbulent Subarray

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sliding Window | C++, Java, Python3 |

## Approach: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxTurbulenceSize(std::vector<int>& A) {
        int N = A.size();
        if (N < 2) return N;

        int ans = 1;
        int anchor = 0;

        auto compare = [&](int x, int y) {
            if (x < y) return -1;
            if (x > y) return 1;
            return 0;
        };

        for (int i = 1; i < N; ++i) {
            int c = compare(A[i - 1], A[i]);
            if (c == 0) {
                anchor = i;
            } else {
                if (i == N - 1 || c * compare(A[i], A[i + 1]) != -1) {
                    ans = std::max(ans, i - anchor + 1);
                    anchor = i;
                }
            }
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxTurbulenceSize(int[] A) {
        int N = A.length;
        int ans = 1;
        int anchor = 0;

        for (int i = 1; i < N; ++i) {
            int c = Integer.compare(A[i-1], A[i]);
            if (c == 0) {
                anchor = i;
            } else if (i == N-1 || c * Integer.compare(A[i], A[i+1]) != -1) {
                ans = Math.max(ans, i - anchor + 1);
                anchor = i;
            }
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxTurbulenceSize(self, A):
        N = len(A)
        if N < 2:
            return N

        ans = 1
        anchor = 0

        def compare(x, y):
            if x < y:
                return -1
            if x > y:
                return 1
            return 0

        for i in range(1, N):
            c = compare(A[i - 1], A[i])
            if c == 0:
                anchor = i
            else:
                if i == N - 1 or c * compare(A[i], A[i + 1]) != -1:
                    ans = max(ans, i - anchor + 1)
                    anchor = i
        return ans
```

</details>
