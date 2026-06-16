# 1891. Cutting Ribbons

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/cutting-ribbons/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 1891 - Cutting Ribbons](https://leetcode.com/problems/cutting-ribbons/)

## Problem

You are given an integer array ribbons, where ribbons[i] represents the length of the ith ribbon, and an integer k. You may cut any of the ribbons into any number of segments of positive integer lengths, or perform no cuts at all.

- For example, if you have a ribbon of length 4, you can:

		Keep the ribbon of length 4,
		Cut it into one ribbon of length 3 and one ribbon of length 1,
		Cut it into two ribbons of length 2,
		Cut it into one ribbon of length 2 and two ribbons of length 1, or
		Cut it into four ribbons of length 1.

Your task is to determine the maximum length of ribbon, x, that allows you to cut at least k ribbons, each of length x. You can discard any leftover ribbon from the cuts. If it is impossible to cut k ribbons of the same length, return 0.

### Example 1

```text
Input: ribbons = [9,7,5], k = 3
Output: 5
Explanation:
- Cut the first ribbon to two ribbons, one of length 5 and one of length 4.
- Cut the second ribbon to two ribbons, one of length 5 and one of length 2.
- Keep the third ribbon as it is.
Now you have 3 ribbons of length 5.
```

### Example 2

```text
Input: ribbons = [7,5,9], k = 4
Output: 4
Explanation:
- Cut the first ribbon to two ribbons, one of length 4 and one of length 3.
- Cut the second ribbon to two ribbons, one of length 4 and one of length 1.
- Cut the third ribbon to three ribbons, two of length 4 and one of length 1.
Now you have 4 ribbons of length 4.
```

### Example 3

```text
Input: ribbons = [5,7,9], k = 22
Output: 0
Explanation: You cannot obtain k ribbons of the same positive integer length.
```

## Constraints

- 1 <= ribbons.length <= 105
- 1 <= ribbons[i] <= 105
- 1 <= k <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Add Minimum Number of Rungs](https://leetcode.com/problems/add-minimum-number-of-rungs/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1891. Cutting Ribbons

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Binary Search on The Answer | C++, Java, Python3 |

## Approach: Binary Search on The Answer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        // Binary search bounds
        int left = 0;
        int right = *max_element(ribbons.begin(), ribbons.end());

        // Perform binary search on the ribbon length
        while (left < right) {
            int middle = (left + right + 1) /
                         2;  // Use upper mid to prevent infinite loops
            if (isPossible(middle, ribbons, k)) {
                // If it's possible to make `k` pieces of length `middle`,
                // search the higher range
                left = middle;
            } else {
                // Otherwise, search the lower range
                right = middle - 1;
            }
        }
        return left;
    }

private:
    // Helper function to determine if it's possible to cut the ribbons into at
    // least `k` pieces of the given `x`
    bool isPossible(int x, vector<int>& ribbons, int k) {
        int totalRibbons = 0;
        for (int ribbon : ribbons) {
            // Number of pieces the current ribbon can contribute
            int pieces = ribbon / x;
            totalRibbons += pieces;
            // If the total reaches or exceeds `k`, we can stop early
            if (totalRibbons >= k) return true;
        }
        // It's not possible to make the cut
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxLength(int[] ribbons, int k) {
        // Binary search bounds
        int left = 0;
        int right = Arrays.stream(ribbons).max().getAsInt();

        // Perform binary search on the ribbon length
        while (left < right) {
            int middle = (left + right + 1) / 2; // Use upper mid to prevent infinite loops
            if (isPossible(middle, ribbons, k)) {
                // If it's possible to make `k` pieces of length `middle`, search the higher range
                left = middle;
            } else {
                // Otherwise, search the lower range
                right = middle - 1;
            }
        }
        return left;
    }

    // Helper function to determine if it's possible to cut the ribbons into at least `k` pieces
    // of the given `x`
    private boolean isPossible(int x, int[] ribbons, int k) {
        int totalRibbons = 0;
        for (int ribbon : ribbons) {
            // Number of pieces the current ribbon can contribute
            totalRibbons += ribbon / x;
            // If the total reaches or exceeds `k`, we can stop early
            if (totalRibbons >= k) {
                return true;
            }
        }
        // It's not possible to make the cut
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxLength(self, ribbons: list[int], k: int) -> int:
        # Binary search bounds
        left = 0
        right = max(ribbons)

        # Perform binary search on the ribbon length
        while left < right:
            middle = (
                left + right + 1
            ) // 2  # Use upper mid to prevent infinite loops
            if self._is_possible(middle, ribbons, k):
                # If it's possible to make `k` pieces of length `middle`, search the higher range
                left = middle
            else:
                # Otherwise, search the lower range
                right = middle - 1

        return left

    def _is_possible(self, x: int, ribbons: list[int], k: int) -> bool:
        total_ribbons = 0
        for ribbon in ribbons:
            # Number of pieces the current ribbon can contribute
            total_ribbons += ribbon // x
            # If the total reaches or exceeds `k`, we can stop early
            if total_ribbons >= k:
                return True
        # It's not possible to make the cut
        return False
```

</details>
