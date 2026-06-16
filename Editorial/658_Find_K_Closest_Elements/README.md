# 658. Find K Closest Elements

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-k-closest-elements/)  
`Array` `Two Pointers` `Binary Search` `Sliding Window` `Sorting` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 658 - Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/)

## Problem

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

- |a - x| < |b - x|, or
- |a - x| == |b - x| and a < b

### Example 1

### Example 2

## Constraints

- 1 <= k <= arr.length
- 1 <= arr.length <= 104
- arr is sorted in ascending order.
- -104 <= arr[i], x <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Guess Number Higher or Lower II](https://leetcode.com/problems/guess-number-higher-or-lower-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Find Closest Number to Zero](https://leetcode.com/problems/find-closest-number-to-zero/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 658. Find K Closest Elements

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort With Custom Comparator | Java, Python3 |
| Binary Search + Sliding Window | Java, Python3 |
| Binary Search To Find The Left Bound | Java, Python3 |

## Approach 1: Sort With Custom Comparator

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        // Convert from array to list first to make use of Collections.sort()
        List<Integer> sortedArr = new ArrayList<Integer>();
        for (int num: arr) {
            sortedArr.add(num);
        }
        
        // Sort using custom comparator
        Collections.sort(sortedArr, (num1, num2) -> Math.abs(num1 - x) - Math.abs(num2 - x));
        
        // Only take k elements
        sortedArr = sortedArr.subList(0, k);
        
        // Sort again to have output in ascending order
        Collections.sort(sortedArr);
        return sortedArr;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        # Sort using custom comparator
        sorted_arr = sorted(arr, key = lambda num: abs(x - num))

        # Only take k elements
        result = []
        for i in range(k):
            result.append(sorted_arr[i])
        
        # Sort again to have output in ascending order
        return sorted(result)
```

</details>

<br>

## Approach 2: Binary Search + Sliding Window

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> result = new ArrayList<Integer>();
        
        // Base case
        if (arr.length == k) {
            for (int i = 0; i < k; i++) {
                result.add(arr[i]);
            }
            
            return result;
        }
        
        // Binary search to find the closest element
        int left = 0;
        int right = arr.length;
        int mid = 0;
        while (left < right) {
            mid = (left + right) / 2;
            if (arr[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        // Initialize our sliding window's bounds
        left -= 1;
        right = left + 1;
        
        // While the window size is less than k
        while (right - left - 1 < k) {
            // Be careful to not go out of bounds
            if (left == -1) {
                right += 1;
                continue;
            }
            
            // Expand the window towards the side with the closer number
            // Be careful to not go out of bounds with the pointers
            if (right == arr.length || Math.abs(arr[left] - x) <= Math.abs(arr[right] - x)) {
                left -= 1;
            } else {
                right += 1;
            }
        } 

        // Build and return the window
        for (int i = left + 1; i < right; i++) {
            result.add(arr[i]);
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
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        # Base case
        if len(arr) == k:
            return arr
        
        # Find the closest element and initialize two pointers
        left = bisect_left(arr, x) - 1
        right = left + 1

        # While the window size is less than k
        while right - left - 1 < k:
            # Be careful to not go out of bounds
            if left == -1:
                right += 1
                continue
            
            # Expand the window towards the side with the closer number
            # Be careful to not go out of bounds with the pointers
            if right == len(arr) or abs(arr[left] - x) <= abs(arr[right] - x):
                left -= 1
            else:
                right += 1
        
        # Return the window
        return arr[left + 1:right]
```

</details>

<br>

## Approach 3: Binary Search To Find The Left Bound

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        // Initialize binary search bounds
        int left = 0;
        int right = arr.length - k;
        
        // Binary search against the criteria described
        while (left < right) {
            int mid = (left + right) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        // Create output in correct format
        List<Integer> result = new ArrayList<Integer>();
        for (int i = left; i < left + k; i++) {
            result.add(arr[i]);
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
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        # Initialize binary search bounds
        left = 0
        right = len(arr) - k
        
        # Binary search against the criteria described
        while left < right:
            mid = (left + right) // 2
            if x - arr[mid] > arr[mid + k] - x:
                left = mid + 1
            else:
                right = mid

        return arr[left:left + k]
```

</details>
