# 3254. Find the Power of K-Size Subarrays I

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/)  
`Array` `Sliding Window`

**Problem Link:** [LeetCode 3254 - Find the Power of K-Size Subarrays I](https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/)

## Problem

You are given an array of integers nums of length n and a positive integer k.

The power of an array is defined as:

- Its maximum element if all of its elements are consecutive and sorted in ascending order.
- -1 otherwise.

You need to find the power of all subarrays of nums of size k.

Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= n == nums.length <= 500
- 1 <= nums[i] <= 105
- 1 <= k <= n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Sum of Distinct Subarrays With Length K](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3254. Find the Power of K-Size Subarrays I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Sliding Window with Deque | C++, Java, Python3 |
| Optimized Via Counter | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int length = nums.size();
        vector<int> result(length - k + 1);

        for (int start = 0; start <= length - k; start++) {
            bool isConsecutiveAndSorted = true;

            // Check if the current subarray is sorted and consecutive
            for (int index = start; index < start + k - 1; index++) {
                if (nums[index + 1] != nums[index] + 1) {
                    isConsecutiveAndSorted = false;
                    break;
                }
            }

            // If valid, take the maximum of the subarray, otherwise set to -1
            if (isConsecutiveAndSorted) {
                // Maximum element of this subarray
                result[start] = nums[start + k - 1];
            } else {
                result[start] = -1;
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

    public int[] resultsArray(int[] nums, int k) {
        int length = nums.length;
        int[] result = new int[length - k + 1];

        for (int start = 0; start <= length - k; start++) {
            boolean isConsecutiveAndSorted = true;

            // Check if the current subarray is sorted and consecutive
            for (int index = start; index < start + k - 1; index++) {
                if (nums[index + 1] != nums[index] + 1) {
                    isConsecutiveAndSorted = false;
                    break;
                }
            }

            // If valid, take the maximum of the subarray, otherwise set to -1
            if (isConsecutiveAndSorted) {
                // Maximum element of this subarray
                result[start] = nums[start + k - 1];
            } else {
                result[start] = -1;
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
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        length = len(nums)
        result = [0] * (length - k + 1)

        for start in range(length - k + 1):
            is_consecutive_and_sorted = True

            # Check if the current subarray is sorted and consecutive
            for index in range(start, start + k - 1):
                if nums[index + 1] != nums[index] + 1:
                    is_consecutive_and_sorted = False
                    break

            # If valid, take the maximum of the subarray, otherwise set to -1
            if is_consecutive_and_sorted:
                # Maximum element of this subarray
                result[start] = nums[start + k - 1]
            else:
                result[start] = -1

        return result
```

</details>

<br>

## Approach 2: Sliding Window with Deque

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int length = nums.size();
        vector<int> result(length - k + 1, -1);
        deque<int> indexDeque;

        for (int currentIndex = 0; currentIndex < length; currentIndex++) {
            // Remove elements that are out of the window
            if (!indexDeque.empty() &&
                indexDeque.front() < currentIndex - k + 1) {
                indexDeque.pop_front();
            }

            // Check if current element breaks the consecutive and sorted condition
            if (!indexDeque.empty() &&
                nums[currentIndex] != nums[currentIndex - 1] + 1) {
                indexDeque.clear();  // Invalidate the entire deque if condition breaks
            }

            // Add current element index to the deque
            indexDeque.push_back(currentIndex);

            // Check if the window is of size k and update result
            if (currentIndex >= k - 1) {
                if (indexDeque.size() == k) {  // Valid window of size k
                    result[currentIndex - k + 1] = nums[indexDeque.back()];
                } else {
                    result[currentIndex - k + 1] = -1;  // Not valid, return -1
                }
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

    public int[] resultsArray(int[] nums, int k) {
        int length = nums.length;
        int[] result = new int[length - k + 1];
        Deque<Integer> indexDeque = new ArrayDeque<>();

        for (int currentIndex = 0; currentIndex < length; currentIndex++) {
            // Remove elements that are out of the window
            if (
                !indexDeque.isEmpty() &&
                indexDeque.peekFirst() < currentIndex - k + 1
            ) {
                indexDeque.pollFirst();
            }

            // Check if current element breaks the consecutive and sorted condition
            if (
                !indexDeque.isEmpty() &&
                nums[currentIndex] != nums[currentIndex - 1] + 1
            ) {
                indexDeque.clear(); // Invalidate the entire deque if condition breaks
            }

            // Add current element index to the deque
            indexDeque.offerLast(currentIndex);

            // Check if the window is of size k and update result
            if (currentIndex >= k - 1) {
                if (indexDeque.size() == k) { // Valid window of size k
                    result[currentIndex - k + 1] = nums[indexDeque.peekLast()];
                } else {
                    result[currentIndex - k + 1] = -1; // Not valid, return -1
                }
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
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        length = len(nums)
        result = [-1] * (length - k + 1)
        index_deque = collections.deque()

        for current_index in range(length):
            # Remove elements that are out of the window
            if index_deque and index_deque[0] < current_index - k + 1:
                index_deque.popleft()
            # Check if current element breaks the consecutive and sorted condition
            if (
                index_deque
                and nums[current_index] != nums[current_index - 1] + 1
            ):
                index_deque.clear()  # Invalidate the entire deque if condition breaks

            # Add current element index to the deque
            index_deque.append(current_index)

            # Check if the window is of size k and update result
            if current_index >= k - 1:
                if len(index_deque) == k:  # Valid window of size k
                    result[current_index - k + 1] = nums[index_deque[-1]]
                else:
                    result[current_index - k + 1] = -1  # Not valid, return -1

        return result
```

</details>

<br>

## Approach 3: Optimized Via Counter

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;  // If k is 1, every single element is a valid subarray
        }

        size_t length = nums.size();
        vector<int> result(length - k + 1, -1);  // Initialize results with -1
        int consecutiveCount = 1;  // Count of consecutive elements

        for (size_t index = 0; index < length - 1; index++) {
            if (nums[index] + 1 == nums[index + 1]) {
                consecutiveCount++;
            } else {
                consecutiveCount = 1;  // Reset count if not consecutive
            }

            // If we have enough consecutive elements, update the result
            if (consecutiveCount >= k) {
                result[index - k + 2] = nums[index + 1];
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

    public int[] resultsArray(int[] nums, int k) {
        if (k == 1) {
            return nums; // If k is 1, every single element is a valid subarray
        }

        int length = nums.length;
        int[] result = new int[length - k + 1];
        Arrays.fill(result, -1); // Initialize results to -1
        int consecutiveCount = 1; // Count of consecutive elements

        for (int index = 0; index < length - 1; index++) {
            if (nums[index] + 1 == nums[index + 1]) {
                consecutiveCount++;
            } else {
                consecutiveCount = 1; // Reset count if not consecutive
            }

            // If we have enough consecutive elements, update the result
            if (consecutiveCount >= k) {
                result[index - k + 2] = nums[index + 1];
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
    def resultsArray(self, nums, k):
        if k == 1:
            return nums  # If k is 1, every single element is a valid subarray

        length = len(nums)
        result = [-1] * (length - k + 1)
        consecutive_count = 1  # Count of consecutive elements

        for index in range(length - 1):
            if nums[index] + 1 == nums[index + 1]:
                consecutive_count += 1
            else:
                consecutive_count = 1  # Reset count if not consecutive

            # If we have enough consecutive elements, update the result
            if consecutive_count >= k:
                result[index - k + 2] = nums[index + 1]

        return result
```

</details>
