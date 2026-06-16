# 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)  
`Array` `Queue` `Sliding Window` `Heap (Priority Queue)` `Ordered Set` `Monotonic Queue`

**Problem Link:** [LeetCode 1438 - Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)

## Problem

Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

### Example 1

```text
Input: nums = [8,2,4,7], limit = 4
Output: 2
Explanation: All subarrays are:
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4.
Therefore, the size of the longest subarray is 2.
```

### Example 2

```text
Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
```

### Example 3

```text
Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109
- 0 <= limit <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Partition Array Such That Maximum Difference Is K](https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count Subarrays With Fixed Bounds](https://leetcode.com/problems/count-subarrays-with-fixed-bounds/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Heaps | C++, Java, Python3 |
| Multiset | C++, Java, Python3 |
| Two Deques | C++, Java, Python3 |

## Approach 1: Two Heaps

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int, int>> maxHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;

        int left = 0, maxLength = 0;

        for (int right = 0; right < nums.size(); ++right) {
            maxHeap.push({nums[right], right});
            minHeap.push({nums[right], right});

            // Check if the absolute difference between the maximum and minimum
            // values in the current window exceeds the limit
            while (maxHeap.top().first - minHeap.top().first > limit) {
                // Move the left pointer to the right until the condition is
                // satisfied. This ensures we remove the element causing the
                // violation
                left = min(maxHeap.top().second, minHeap.top().second) + 1;

                // Remove elements from the heaps that are outside the current
                // window
                while (maxHeap.top().second < left) {
                    maxHeap.pop();
                }
                while (minHeap.top().second < left) {
                    minHeap.pop();
                }
            }

            // Update maxLength with the length of the current valid window
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int longestSubarray(int[] nums, int limit) {
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>(
            (a, b) -> b[0] - a[0]
        );
        PriorityQueue<int[]> minHeap = new PriorityQueue<>(
            Comparator.comparingInt(a -> a[0])
        );

        int left = 0, maxLength = 0;

        for (int right = 0; right < nums.length; ++right) {
            maxHeap.offer(new int[] { nums[right], right });
            minHeap.offer(new int[] { nums[right], right });

            // Check if the absolute difference between the maximum and minimum values in the current window exceeds the limit
            while (maxHeap.peek()[0] - minHeap.peek()[0] > limit) {
                // Move the left pointer to the right until the condition is satisfied.
                // This ensures we remove the element causing the violation
                left = Math.min(maxHeap.peek()[1], minHeap.peek()[1]) + 1;

                // Remove elements from the heaps that are outside the current window
                while (maxHeap.peek()[1] < left) {
                    maxHeap.poll();
                }
                while (minHeap.peek()[1] < left) {
                    minHeap.poll();
                }
            }

            // Update maxLength with the length of the current valid window
            maxLength = Math.max(maxLength, right - left + 1);
        }

        return maxLength;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestSubarray(self, nums, limit):
        max_heap = []
        min_heap = []

        left = 0
        max_length = 0

        for right in range(len(nums)):
            heapq.heappush(max_heap, (-nums[right], right))
            heapq.heappush(min_heap, (nums[right], right))

            # Check if the absolute difference between the maximum and minimum values in the current window exceeds the limit
            while -max_heap[0][0] - min_heap[0][0] > limit:
                # Move the left pointer to the right until the condition is satisfied.
                # This ensures we remove the element causing the violation
                left = min(max_heap[0][1], min_heap[0][1]) + 1

                # Remove elements from the heaps that are outside the current window
                while max_heap[0][1] < left:
                    heapq.heappop(max_heap)
                while min_heap[0][1] < left:
                    heapq.heappop(min_heap)

            # Update max_length with the length of the current valid window
            max_length = max(max_length, right - left + 1)

        return max_length
```

</details>

<br>

## Approach 2: Multiset

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // multiset to maintain the elements within the current window
        multiset<int> window;
        int left = 0, maxLength = 0;

        for (int right = 0; right < nums.size(); ++right) {
            window.insert(nums[right]);

            // Check if the absolute difference between the maximum and minimum
            // values in the current window exceeds the limit
            while (*window.rbegin() - *window.begin() > limit) {
                // Remove the element at the left pointer from the multiset
                window.erase(window.find(nums[left]));
                // Move the left pointer to the right to exclude the element
                // causing the violation
                ++left;
            }

            // Update maxLength with the length of the current valid window
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int longestSubarray(int[] nums, int limit) {
        // TreeMap to maintain the elements within the current window
        TreeMap<Integer, Integer> window = new TreeMap<>();
        int left = 0, maxLength = 0;

        for (int right = 0; right < nums.length; ++right) {
            window.put(nums[right], window.getOrDefault(nums[right], 0) + 1);

            // Check if the absolute difference between the maximum and minimum values in the current window exceeds the limit
            while (window.lastKey() - window.firstKey() > limit) {
                // Remove the element at the left pointer from the TreeMap
                window.put(nums[left], window.get(nums[left]) - 1);
                if (window.get(nums[left]) == 0) {
                    window.remove(nums[left]);
                }
                // Move the left pointer to the right to exclude the element causing the violation
                ++left;
            }

            // Update maxLength with the length of the current valid window
            maxLength = Math.max(maxLength, right - left + 1);
        }

        return maxLength;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from sortedcontainers import SortedDict


class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        # SortedDict to maintain the elements within the current window
        window = SortedDict()
        left = 0
        max_length = 0

        for right in range(len(nums)):
            if nums[right] in window:
                window[nums[right]] += 1
            else:
                window[nums[right]] = 1

            # Check if the absolute difference between the maximum and minimum values in the current window exceed the limit
            while window.peekitem(-1)[0] - window.peekitem(0)[0] > limit:
                # Remove the element at the left pointer from the SortedDict
                window[nums[left]] -= 1
                if window[nums[left]] == 0:
                    window.pop(nums[left])
                # Move the left pointer to the right to exclude the element causing the violation
                left += 1

            # Update maxLength with the length of the current valid window
            max_length = max(max_length, right - left + 1)

        return max_length
```

</details>

<br>

## Approach 3: Two Deques

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int left = 0, right;
        int maxLength = 0;

        for (right = 0; right < nums.size(); ++right) {
            // Maintain the maxDeque in decreasing order
            while (!maxDeque.empty() && maxDeque.back() < nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(nums[right]);

            // Maintain the minDeque in increasing order
            while (!minDeque.empty() && minDeque.back() > nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(nums[right]);

            // Check if the current window exceeds the limit
            while (maxDeque.front() - minDeque.front() > limit) {
                // Remove the elements that are out of the current window
                if (maxDeque.front() == nums[left]) {
                    maxDeque.pop_front();
                }
                if (minDeque.front() == nums[left]) {
                    minDeque.pop_front();
                }
                ++left;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int longestSubarray(int[] nums, int limit) {
        Deque<Integer> maxDeque = new LinkedList<>();
        Deque<Integer> minDeque = new LinkedList<>();
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < nums.length; ++right) {
            // Maintain the maxDeque in decreasing order
            while (!maxDeque.isEmpty() && maxDeque.peekLast() < nums[right]) {
                maxDeque.pollLast();
            }
            maxDeque.offerLast(nums[right]);

            // Maintain the minDeque in increasing order
            while (!minDeque.isEmpty() && minDeque.peekLast() > nums[right]) {
                minDeque.pollLast();
            }
            minDeque.offerLast(nums[right]);

            // Check if the current window exceeds the limit
            while (maxDeque.peekFirst() - minDeque.peekFirst() > limit) {
                // Remove the elements that are out of the current window
                if (maxDeque.peekFirst() == nums[left]) {
                    maxDeque.pollFirst();
                }
                if (minDeque.peekFirst() == nums[left]) {
                    minDeque.pollFirst();
                }
                ++left;
            }

            maxLength = Math.max(maxLength, right - left + 1);
        }

        return maxLength;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        max_deque = deque()
        min_deque = deque()
        left = 0
        max_length = 0

        for right in range(len(nums)):
            # Maintain the max_deque in decreasing order
            while max_deque and max_deque[-1] < nums[right]:
                max_deque.pop()
            max_deque.append(nums[right])

            # Maintain the min_deque in increasing order
            while min_deque and min_deque[-1] > nums[right]:
                min_deque.pop()
            min_deque.append(nums[right])

            # Check if the current window exceeds the limit
            while max_deque[0] - min_deque[0] > limit:
                # Remove the elements that are out of the current window
                if max_deque[0] == nums[left]:
                    max_deque.popleft()
                if min_deque[0] == nums[left]:
                    min_deque.popleft()
                left += 1

            max_length = max(max_length, right - left + 1)

        return max_length
```

</details>
