# 1855. Maximum Distance Between a Pair of Values

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/)  
`Array` `Two Pointers` `Binary Search`

**Problem Link:** [LeetCode 1855 - Maximum Distance Between a Pair of Values](https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/)

## Problem

You are given two non-increasing 0-indexed integer arrays nums1Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹ and nums2Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹.

A pair of indices (i, j), where 0 <= i < nums1.length and 0 <= j < nums2.length, is valid if both i <= j and nums1[i] <= nums2[j]. The distance of the pair is j - iÃ¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹.

Return the maximum distance of any valid pair (i, j). If there are no valid pairs, return 0.

An array arr is non-increasing if arr[i-1] >= arr[i] for every 1 <= i < arr.length.

### Example 1

```text
Input: nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
Output: 2
Explanation: The valid pairs are (0,0), (2,2), (2,3), (2,4), (3,3), (3,4), and (4,4).
The maximum distance is 2 with pair (2,4).
```

### Example 2

```text
Input: nums1 = [2,2,2], nums2 = [10,10,1]
Output: 1
Explanation: The valid pairs are (0,0), (0,1), and (1,1).
The maximum distance is 1 with pair (0,1).
```

### Example 3

```text
Input: nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]
Output: 2
Explanation: The valid pairs are (2,2), (2,3), (2,4), (3,3), and (3,4).
The maximum distance is 2 with pair (2,4).
```

## Constraints

- 1 <= nums1.length, nums2.length <= 105
- 1 <= nums1[i], nums2[j] <= 105
- Both nums1 and nums2 are non-increasing.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Two Furthest Houses With Different Colors](https://leetcode.com/problems/two-furthest-houses-with-different-colors/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1855. Maximum Distance Between a Pair of Values

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C++, Java, Python |
| Two Pointers | C++, Java, Python3 |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = int(nums1.size()), n = int(nums2.size());
        int ans = 0;
        
        // Iterate over nums1 and find insertion position to nums2.
        for (int i = 0; i < m; ++i) {
            int k = nums2.rend() - lower_bound(nums2.rbegin(), nums2.rend(), nums1[i]);
            if (k > 0) {
                ans = max(ans, k - i - 1);
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
    public int maxDistance(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        int ans = 0;

        // Iterate over nums1 and find insertion position to nums2.
        for (int i = 0; i < m; ++i) {
            int k = binarySearch(nums2, nums1[i]);
            if (k > i) {
                ans = Math.max(ans, k - i);
            }
        }
        return ans;
    }
    public int binarySearch(int[] nums, int a) {
        int left = 0, right = nums.length - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] < a) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return left;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        m, n = len(nums1), len(nums2)
        ans = 0

        # Iterate over nums1 and find insertion position to nums2.
        nums2.reverse()
        for i in range(m):
            k = bisect.bisect_left(nums2, nums1[i])
            ans = max(ans, n - k - 1 - i)
        return ans
```

</details>

<br>

## Approach 2: Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, p1 = 0, p2 = 0;
        
        while (p1 < nums1.size() && p2 < nums2.size()) {
            // If p1 is larger, we should move on to a smaller p1.
            if (nums1[p1] > nums2[p2]) {
                p1++;
            }
            
            // Otherwise, get their distance and move on to a smaller p2.
            else {
                ans = max(ans, p2 - p1);
                p2++;
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
    public int maxDistance(int[] nums1, int[] nums2) {
        int ans = 0, p1 = 0, p2 = 0;
        while (p1 < nums1.length && p2 < nums2.length) {
            // If p1 is larger, we should move on to a smaller p1.
            if (nums1[p1] > nums2[p2]) {
                p1++;
            }
            
            // Otherwise, get their distance and move on to a smaller p2.
            else {
                ans = Math.max(ans, p2 - p1);
                p2++;
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
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        ans = 0
        p1, p2 = 0, 0
        
        while p1 < len(nums1) and p2 < len(nums2):
            # If p1 is larger, we should move on to a smaller p1.
            if nums1[p1] > nums2[p2]:
                p1 += 1
                
            # Otherwise, get their distance and move on to a smaller p2.
            else: 
                ans = max(ans, p2 - p1)
                p2 += 1
        
        return ans
```

</details>
