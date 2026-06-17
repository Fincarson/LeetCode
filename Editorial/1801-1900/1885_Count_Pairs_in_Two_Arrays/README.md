# 1885. Count Pairs in Two Arrays

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/count-pairs-in-two-arrays/)  
`Array` `Two Pointers` `Binary Search` `Sorting`

**Problem Link:** [LeetCode 1885 - Count Pairs in Two Arrays](https://leetcode.com/problems/count-pairs-in-two-arrays/)

## Problem

Given two integer arrays nums1 and nums2 of length n, count the pairs of indices (i, j) such that i < j and nums1[i] + nums1[j] > nums2[i] + nums2[j].

Return the number of pairs satisfying the condition.

### Example 1

```text
Input: nums1 = [2,1,2,1], nums2 = [1,2,1,2]
Output: 1
Explanation: The pairs satisfying the condition are:
- (0, 2) where 2 + 2 > 1 + 1.
```

### Example 2

```text
Input: nums1 = [1,10,6,2], nums2 = [1,4,1,5]
Output: 5
Explanation: The pairs satisfying the condition are:
- (0, 1) where 1 + 10 > 1 + 4.
- (0, 2) where 1 + 6 > 1 + 1.
- (1, 2) where 10 + 6 > 4 + 1.
- (1, 3) where 10 + 2 > 4 + 5.
- (2, 3) where 6 + 2 > 1 + 5.
```

## Constraints

- n == nums1.length == nums2.length
- 1 <= n <= 105
- 1 <= nums1[i], nums2[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Max Value of Equation](https://leetcode.com/problems/max-value-of-equation/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Substrings That Begin and End With the Same Letter](https://leetcode.com/problems/substrings-that-begin-and-end-with-the-same-letter/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1885. Count Pairs in Two Arrays

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C++, Java, Python3 |
| Sort and Two Pointer | C++, Java, Python3 |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();  // nums2 is the same length

        // Difference[i] stores nums1[i] - nums2[i]
        vector<long long> difference(N);
        for (int i = 0; i < N; i++) {
            difference[i] = static_cast<long>(nums1[i]) - nums2[i];
        }
        sort(difference.begin(), difference.end());

        // Count the number of valid pairs
        long long result = 0;
        for (int i = 0; i < N; i++) {
            // All indices j following i make a valid pair
            if (difference[i] > 0) {
                result += N - i - 1;
            } else {
                // Binary search to find the first index j
                // that makes a valid pair with i
                int left = i + 1;
                int right = N - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    // If difference[mid] is a valid pair, search in left half
                    if (difference[i] + difference[mid] > 0) {
                        right = mid - 1;
                    // If difference[mid] does not make a valid pair, search in right half
                    } else {
                        left = mid + 1;
                    }
                }
                // After the search left points to the first index j that makes
                // a valid pair with i so we count that and all following indices
                result += N - left;
            }
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long countPairs(int[] nums1, int[] nums2) {
        int N = nums1.length;  // nums2 is the same length

        // Difference[i] stores nums1[i] - nums2[i]
        long[] difference = new long[N];
        for (int i = 0; i < N; i++) {
            difference[i] = nums1[i] - nums2[i];
        }
        Arrays.sort(difference);

        // Count the number of valid pairs
        long result = 0;
        for (int i = 0; i < N; i++) {
            // All indices j following i make a valid pair
            if (difference[i] > 0) {
                result += N - i - 1;
            } else {
                // Binary search to find the first index j
                // that makes a valid pair with i
                int left = i + 1;
                int right = N - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    // If difference[mid] is a valid pair, search in left half
                    if (difference[i] + difference[mid] > 0) {
                        right = mid - 1;
                    // If difference[mid] does not make a valid pair, search in right half
                    } else {
                        left = mid + 1;
                    }
                }
                // After the search left points to the first index j that makes
                // a valid pair with i so we count that and all following indices
                result += N - left;
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
    def countPairs(self, nums1, nums2):
        N = len(nums1)  # nums2 is the same length

        # Difference[i] stores nums1[i] - nums2[i]
        difference = [nums1[i] - nums2[i] for i in range(N)]
        difference.sort()

        # Count the number of valid pairs
        result = 0
        for i in range(0, N):
            # All indices j following i make a valid pair
            if difference[i] > 0:
                result += N - i - 1
                
            # Binary search to find the first index j
            # that makes a valid pair with i
            else:
                left = i + 1
                right = N - 1
                while left <= right:
                    mid = (left + right) // 2
                    # If difference[mid] is a valid pair, search in left half
                    if difference[i] + difference[mid] > 0:
                        right = mid - 1
                    # If difference[mid] does not make a valid pair, search in right half
                    else:
                        left = mid + 1

                # After the search left points to the first index j that makes
                # a valid pair with i so we count that and all following indices
                result += N - left

        return result
```

</details>

<br>

## Approach 2: Sort and Two Pointer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size(); // nums2 is the same length

        // Difference[i] stores nums1[i] - nums2[i]
        vector<int> difference(N);
        for (int i = 0; i < N; i++) {
            difference[i] = nums1[i] - nums2[i];
        }
        sort(begin(difference), end(difference));

        // Count the number of valid pairs
        long long result = 0;
        int left = 0;
        int right = N - 1;
        while (left < right) {
            // Left makes a valid pair with right
            // Right also makes a valid pair with the indices between the pointers
            if (difference[left] + difference[right] > 0) {
                result += right - left;
                right--;
            // Left and right are not a valid pair
            } else {
                left++;
            }
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long countPairs(int[] nums1, int[] nums2) {
        int N = nums1.length; // nums2 is the same length

        // Difference[i] stores nums1[i] - nums2[i]
        long[] difference = new long[N];
        for (int i = 0; i < N; i++) {
            difference[i] = nums1[i] - nums2[i];
        }
        Arrays.sort(difference);

        // Count the number of valid pairs
        long result = 0;
        int left = 0;
        int right = N - 1;
        while (left < right) {
            // Left makes a valid pair with right
            // Right also makes a valid pair with the indices between the pointers
            if (difference[left] + difference[right] > 0) {
                result += right - left;
                right--;
            // Left and right are not a valid pair
            } else {
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
    def countPairs(self, nums1, nums2):
        N = len(nums1)  # nums2 is the same length

        # Difference[i] stores nums1[i] - nums2[i]
        difference = [nums1[i] - nums2[i] for i in range(N)]
        difference.sort()

        # Count the number of valid pairs
        result = 0
        left = 0
        right = N - 1
        while left < right:
            # Left makes a valid pair with right
            # Right also makes a valid pair with the indices between the pointers
            if difference[left] + difference[right] > 0:
                result += right - left
                right -= 1
            # Left and right are not a valid pair
            else:
                left += 1
        return result
```

</details>
