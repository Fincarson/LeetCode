# 1574. Shortest Subarray to be Removed to Make Array Sorted

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/)  
`Array` `Two Pointers` `Binary Search` `Stack` `Monotonic Stack`

**Problem Link:** [LeetCode 1574 - Shortest Subarray to be Removed to Make Array Sorted](https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/)

## Problem

Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.

Return the length of the shortest subarray to remove.

A subarray is a contiguous subsequence of the array.

### Example 1

```text
Input: arr = [1,2,3,10,4,2,3,5]
Output: 3
Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
Another correct solution is to remove the subarray [3,10,4].
```

### Example 2

```text
Input: arr = [5,4,3,2,1]
Output: 4
Explanation: Since the array is strictly decreasing, we can only keep a single element. Therefore we need to remove a subarray of length 4, either [5,4,3,2] or [4,3,2,1].
```

### Example 3

```text
Input: arr = [1,2,3]
Output: 0
Explanation: The array is already non-decreasing. We do not need to remove any elements.
```

## Constraints

- 1 <= arr.length <= 105
- 0 <= arr[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count the Number of Incremovable Subarrays II](https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Count the Number of Incremovable Subarrays I](https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1574. Shortest Subarray to be Removed to Make Array Sorted

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C++, Java, Python3 |
| Two Pointers | C++, Java, Python3 |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int helperBinarySearch(vector<int>& arr, int left, int right, int target) {
        // Find the first index where arr[mid] >= target
        // finding lowerbound
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;

        // Find the longest non-decreasing subarray from the left
        while (left + 1 < n && arr[left] <= arr[left + 1]) left++;

        // Find the longest non-decreasing subarray from the right
        while (right - 1 >= 0 && arr[right] >= arr[right - 1]) right--;

        // If the entire array is already sorted
        if (left >= right) return 0;

        // Start with removing either left or right part completely
        int ans = min(n - (left + 1), right);

        // Try to merge the left and right parts
        for (int i = 0; i <= left; i++) {
            int target = arr[i];
            int j = helperBinarySearch(arr, right, n, target);
            ans = min(ans, j - (i + 1));
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

    private int helperBinarySearch(int[] arr, int left, int right, int target) {
        // Find the first index where arr[mid] >= target
        // finding lowerbound
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= target) right = mid;
            else left = mid + 1;
        }
        return left;
    }

    public int findLengthOfShortestSubarray(int[] arr) {
        int n = arr.length;
        int left = 0, right = n - 1;

        // Find the longest non-decreasing subarray from the left
        while (left + 1 < n && arr[left] <= arr[left + 1]) left++;

        // Find the longest non-decreasing subarray from the right
        while (right - 1 >= 0 && arr[right] >= arr[right - 1]) right--;

        // If the entire array is already sorted
        if (left >= right) return 0;

        // Start with removing either left or right part completely
        int ans = Math.min(n - (left + 1), right);

        // Try to merge the left and right parts
        for (int i = 0; i <= left; i++) {
            int target = arr[i];
            int j = helperBinarySearch(arr, right, n, target);
            ans = Math.min(ans, j - (i + 1));
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
    def helper_binary_search(self, arr, left, right, target):
        # Find the first index where arr[mid] >= target
        # finding lowerbound
        while left < right:
            mid = left + (right - left) // 2
            if arr[mid] >= target:
                right = mid
            else:
                left = mid + 1
        return left

    def findLengthOfShortestSubarray(self, arr):
        n = len(arr)
        left, right = 0, n - 1

        # Find the longest non-decreasing subarray from the left
        while left + 1 < n and arr[left] <= arr[left + 1]:
            left += 1

        # Find the longest non-decreasing subarray from the right
        while right - 1 >= 0 and arr[right] >= arr[right - 1]:
            right -= 1

        # If the entire array is already sorted
        if left >= right:
            return 0

        # Start with removing either left or right part completely
        ans = min(n - (left + 1), right)

        # Try to merge the left and right parts
        for i in range(left + 1):
            j = self.helper_binary_search(arr, right, n, arr[i])
            ans = min(ans, j - (i + 1))

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
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int right = arr.size() - 1;
        while (right > 0 && arr[right] >= arr[right - 1]) {
            right--;
        }

        int ans = right;
        int left = 0;
        while (left < right && (left == 0 || arr[left - 1] <= arr[left])) {
            // find next valid number after arr[left]
            while (right < arr.size() && arr[left] > arr[right]) {
                right++;
            }
            // save length of removed subarray
            ans = min(ans, right - left - 1);
            left++;
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

    public int findLengthOfShortestSubarray(int[] arr) {
        int right = arr.length - 1;
        while (right > 0 && arr[right] >= arr[right - 1]) {
            right--;
        }

        int ans = right;
        int left = 0;
        while (left < right && (left == 0 || arr[left - 1] <= arr[left])) {
            // find next valid number after arr[left]
            while (right < arr.length && arr[left] > arr[right]) {
                right++;
            }
            // save length of removed subarray
            ans = Math.min(ans, right - left - 1);
            left++;
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
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        right = len(arr) - 1
        while right > 0 and arr[right] >= arr[right - 1]:
            right -= 1

        ans = right
        left = 0
        while left < right and (left == 0 or arr[left - 1] <= arr[left]):
            # find next valid number after arr[left]
            while right < len(arr) and arr[left] > arr[right]:
                right += 1
            # save length of removed subarray
            ans = min(ans, right - left - 1)
            left += 1
        return ans
```

</details>
