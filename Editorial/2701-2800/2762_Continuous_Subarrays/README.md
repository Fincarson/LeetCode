# 2762. Continuous Subarrays

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/continuous-subarrays/)  
`Array` `Queue` `Sliding Window` `Heap (Priority Queue)` `Ordered Set` `Monotonic Queue`

**Problem Link:** [LeetCode 2762 - Continuous Subarrays](https://leetcode.com/problems/continuous-subarrays/)

## Problem

You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:

- Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.

Return the total number of continuous subarrays.

A subarray is a contiguous non-empty sequence of elements within an array.

### Example 1

```text
Input: nums = [5,4,2,4]
Output: 8
Explanation:
Continuous subarray of size 1: [5], [4], [2], [4].
Continuous subarray of size 2: [5,4], [4,2], [2,4].
Continuous subarray of size 3: [4,2,4].
There are no subarrys of size 4.
Total continuous subarrays = 4 + 3 + 1 = 8.
It can be shown that there are no more continuous subarrays.
```

### Example 2

```text
Input: nums = [1,2,3]
Output: 6
Explanation:
Continuous subarray of size 1: [1], [2], [3].
Continuous subarray of size 2: [1,2], [2,3].
Continuous subarray of size 3: [1,2,3].
Total continuous subarrays = 3 + 2 + 1 = 6.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2762. Continuous Subarrays

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorted Map | C++, Java, Python3 |
| Priority Queue | C++, Java, Python3 |
| Monotonic Deque | C++, Java, Python3 |
| Optimized Two Pointer | C++, Java, Python3 |

## Approach 1: Sorted Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        // Map to maintain sorted frequency map of current window
        map<int, int> freq;
        int left = 0, right = 0;
        int n = nums.size();
        long long count = 0;  // Total count of valid subarrays

        while (right < n) {
            // Add current element to frequency map
            freq[nums[right]]++;

            // While window violates the condition |nums[i] - nums[j]| Ã¢â€°Â¤ 2
            // Shrink window from left
            while (freq.rbegin()->first - freq.begin()->first > 2) {
                // Remove leftmost element from frequency map
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }

            // Add count of all valid subarrays ending at right
            count += right - left + 1;
            right++;
        }

        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long continuousSubarrays(int[] nums) {
        // TreeMap to maintain sorted frequency map of current window
        TreeMap<Integer, Integer> freq = new TreeMap<>();
        int left = 0, right = 0;
        int n = nums.length;
        long count = 0; // Total count of valid subarrays

        while (right < n) {
            // Add current element to frequency map
            freq.put(nums[right], freq.getOrDefault(nums[right], 0) + 1);

            // While window violates the condition |nums[i] - nums[j]| Ã¢â€°Â¤ 2
            // Shrink window from left
            while (freq.lastEntry().getKey() - freq.firstEntry().getKey() > 2) {
                // Remove leftmost element from frequency map
                freq.put(nums[left], freq.get(nums[left]) - 1);
                if (freq.get(nums[left]) == 0) {
                    freq.remove(nums[left]);
                }
                left++;
            }

            // Add count of all valid subarrays ending at right
            count += right - left + 1;
            right++;
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        # Map to maintain sorted frequency map of current window
        freq = {}
        left = right = 0
        count = 0  # Total count of valid subarrays

        while right < len(nums):
            # Add current element to frequency map
            freq[nums[right]] = freq.get(nums[right], 0) + 1

            # While window violates the condition |nums[i] - nums[j]| Ã¢â€°Â¤ 2
            # Shrink window from left
            while max(freq) - min(freq) > 2:
                # Remove leftmost element from frequency map
                freq[nums[left]] -= 1
                if freq[nums[left]] == 0:
                    del freq[nums[left]]
                left += 1

            # Add count of all valid subarrays ending at right
            count += right - left + 1
            right += 1

        return count
```

</details>

<br>

## Approach 2: Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int left = 0, right = 0;
        long long count = 0;  // Total count of valid subarrays

        // Min and max heaps storing indices, sorted by nums[index] values
        priority_queue<int, vector<int>, function<bool(int, int)>> minHeap(
            [&nums](int a, int b) { return nums[a] > nums[b]; });
        priority_queue<int, vector<int>, function<bool(int, int)>> maxHeap(
            [&nums](int a, int b) { return nums[a] < nums[b]; });

        while (right < nums.size()) {
            // Add current index to both heaps
            minHeap.push(right);
            maxHeap.push(right);

            // While window violates |nums[i] - nums[j]| Ã¢â€°Â¤ 2 condition
            // Shrink window from left and remove outdated indices
            while (left < right &&
                   nums[maxHeap.top()] - nums[minHeap.top()] > 2) {
                left++;

                // Remove indices that are now outside window
                while (!maxHeap.empty() && maxHeap.top() < left) {
                    maxHeap.pop();
                }
                while (!minHeap.empty() && minHeap.top() < left) {
                    minHeap.pop();
                }
            }

            // Add count of all valid subarrays ending at right
            count += right - left + 1;
            right++;
        }

        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long continuousSubarrays(int[] nums) {
        int left = 0, right = 0;
        long count = 0; // Total count of valid subarrays

        // Min and max heaps storing indices, sorted by nums[index] values
        PriorityQueue<Integer> minHeap = new PriorityQueue<>(
            (a, b) -> nums[a] - nums[b]
        );
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(
            (a, b) -> nums[b] - nums[a]
        );

        while (right < nums.length) {
            // Add current index to both heaps
            minHeap.add(right);
            maxHeap.add(right);

            // While window violates |nums[i] - nums[j]| Ã¢â€°Â¤ 2 condition
            // Shrink window from left and remove outdated indices
            while (
                left < right && nums[maxHeap.peek()] - nums[minHeap.peek()] > 2
            ) {
                left++;

                // Remove indices that are now outside window
                while (!maxHeap.isEmpty() && maxHeap.peek() < left) {
                    maxHeap.poll();
                }
                while (!minHeap.isEmpty() && minHeap.peek() < left) {
                    minHeap.poll();
                }
            }

            // Add count of all valid subarrays ending at right
            count += right - left + 1;
            right++;
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        # Two heaps to track min/max indices, sorted by nums[index]
        min_heap = []  # (nums[i], i) tuples for min tracking
        max_heap = []  # (-nums[i], i) tuples for max tracking
        left = right = 0
        count = 0

        while right < len(nums):
            # Add current index to both heaps
            # For max heap, negate value to convert min heap to max heap
            heapq.heappush(min_heap, (nums[right], right))
            heapq.heappush(max_heap, (-nums[right], right))

            # While window violates |nums[i] - nums[j]| Ã¢â€°Â¤ 2
            # Shrink window from left and remove outdated indices
            while left < right and -max_heap[0][0] - min_heap[0][0] > 2:
                left += 1

                # Remove indices outside window from both heaps
                while min_heap and min_heap[0][1] < left:
                    heapq.heappop(min_heap)
                while max_heap and max_heap[0][1] < left:
                    heapq.heappop(max_heap)

            count += right - left + 1
            right += 1

        return count
```

</details>

<br>

## Approach 3: Monotonic Deque

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        // Monotonic deque to track maximum and minimum elements
        deque<int> maxQ, minQ;
        int left = 0;
        long long count = 0;

        for (int right = 0; right < nums.size(); right++) {
            // Maintain decreasing monotonic deque for maximum values
            while (!maxQ.empty() && nums[maxQ.back()] < nums[right]) {
                maxQ.pop_back();
            }
            maxQ.push_back(right);

            // Maintain increasing monotonic deque for minimum values
            while (!minQ.empty() && nums[minQ.back()] > nums[right]) {
                minQ.pop_back();
            }
            minQ.push_back(right);

            // Shrink window if max-min difference exceeds 2
            while (!maxQ.empty() && !minQ.empty() &&
                   nums[maxQ.front()] - nums[minQ.front()] > 2) {
                // Move left pointer past the element that breaks the condition
                if (maxQ.front() < minQ.front()) {
                    left = maxQ.front() + 1;
                    maxQ.pop_front();
                } else {
                    left = minQ.front() + 1;
                    minQ.pop_front();
                }
            }

            // Add count of all valid subarrays ending at current right pointer
            count += right - left + 1;
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long continuousSubarrays(int[] nums) {
        // Monotonic deque to track maximum and minimum elements
        Deque<Integer> maxQ = new ArrayDeque<>();
        Deque<Integer> minQ = new ArrayDeque<>();
        int left = 0;
        long count = 0;

        for (int right = 0; right < nums.length; right++) {
            // Maintain decreasing monotonic queue for maximum values
            while (!maxQ.isEmpty() && nums[maxQ.peekLast()] < nums[right]) {
                maxQ.pollLast();
            }
            maxQ.offerLast(right);

            // Maintain increasing monotonic queue for minimum values
            while (!minQ.isEmpty() && nums[minQ.peekLast()] > nums[right]) {
                minQ.pollLast();
            }
            minQ.offerLast(right);

            // Shrink window if max-min difference exceeds 2
            while (
                !maxQ.isEmpty() &&
                !minQ.isEmpty() &&
                nums[maxQ.peekFirst()] - nums[minQ.peekFirst()] > 2
            ) {
                // Move left pointer past the element that breaks the condition
                if (maxQ.peekFirst() < minQ.peekFirst()) {
                    left = maxQ.peekFirst() + 1;
                    maxQ.pollFirst();
                } else {
                    left = minQ.peekFirst() + 1;
                    minQ.pollFirst();
                }
            }

            // Add count of all valid subarrays ending at current right pointer
            count += right - left + 1;
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        # Monotonic deque to track maximum and minimum elements
        max_q = deque()
        min_q = deque()
        left = 0
        count = 0

        for right, num in enumerate(nums):
            # Maintain decreasing monotonic deque for maximum values
            while max_q and nums[max_q[-1]] < num:
                max_q.pop()
            max_q.append(right)

            # Maintain increasing monotonic deque for minimum values
            while min_q and nums[min_q[-1]] > num:
                min_q.pop()
            min_q.append(right)

            # Shrink window if max-min difference exceeds 2
            while max_q and min_q and nums[max_q[0]] - nums[min_q[0]] > 2:
                # Move left pointer past the element that breaks the condition
                if max_q[0] < min_q[0]:
                    left = max_q[0] + 1
                    max_q.popleft()
                else:
                    left = min_q[0] + 1
                    min_q.popleft()

            # Add count of all valid subarrays ending at current right pointer
            count += right - left + 1

        return count
```

</details>

<br>

## Approach 4: Optimized Two Pointer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int right = 0, left = 0;
        int curMin, curMax;
        long long windowLen = 0, total = 0;

        // Initialize window with the first element
        curMin = curMax = nums[right];

        for (right = 0; right < nums.size(); right++) {
            // Update min and max for the current window
            curMin = min(curMin, nums[right]);
            curMax = max(curMax, nums[right]);

            // If window condition breaks (diff > 2)
            if (curMax - curMin > 2) {
                // Add subarrays from the previous valid window
                windowLen = right - left;
                total += (windowLen * (windowLen + 1) / 2);

                // Start a new window at the current position
                left = right;
                curMin = curMax = nums[right];

                // Expand left boundary while maintaining the condition
                while (left > 0 && abs(nums[right] - nums[left - 1]) <= 2) {
                    left--;
                    curMin = min(curMin, nums[left]);
                    curMax = max(curMax, nums[left]);
                }

                // Remove overcounted subarrays if left boundary expanded
                if (left < right) {
                    windowLen = right - left;
                    total -= (windowLen * (windowLen + 1) / 2);
                }
            }
        }

        // Add subarrays from the final window
        windowLen = right - left;
        total += (windowLen * (windowLen + 1) / 2);

        return total;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long continuousSubarrays(int[] nums) {
        int right = 0, left = 0;
        int curMin, curMax;
        long windowLen = 0, total = 0;

        // Initialize window with first element
        curMin = curMax = nums[right];

        for (right = 0; right < nums.length; right++) {
            // Update min and max for current window
            curMin = Math.min(curMin, nums[right]);
            curMax = Math.max(curMax, nums[right]);

            // If window condition breaks (diff > 2)
            if (curMax - curMin > 2) {
                // Add subarrays from previous valid window
                windowLen = right - left;
                total += ((windowLen * (windowLen + 1)) / 2);

                // Start new window at current position
                left = right;
                curMin = curMax = nums[right];

                // Expand left boundary while maintaining condition
                while (
                    left > 0 && Math.abs(nums[right] - nums[left - 1]) <= 2
                ) {
                    left--;
                    curMin = Math.min(curMin, nums[left]);
                    curMax = Math.max(curMax, nums[left]);
                }

                // Remove overcounted subarrays if left boundary expanded
                if (left < right) {
                    windowLen = right - left;
                    total -= ((windowLen * (windowLen + 1)) / 2);
                }
            }
        }

        // Add subarrays from final window
        windowLen = right - left;
        total += ((windowLen * (windowLen + 1)) / 2);

        return total;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        right = left = 0
        window_len = total = 0

        # Initialize window with first element
        cur_min = cur_max = nums[right]

        for right in range(len(nums)):
            # Update min and max for current window
            cur_min = min(cur_min, nums[right])
            cur_max = max(cur_max, nums[right])

            # If window condition breaks (diff > 2)
            if cur_max - cur_min > 2:
                # Add subarrays from previous valid window
                window_len = right - left
                total += window_len * (window_len + 1) // 2

                # Start new window at current position
                left = right
                cur_min = cur_max = nums[right]

                # Expand left boundary while maintaining condition
                while left > 0 and abs(nums[right] - nums[left - 1]) <= 2:
                    left -= 1
                    cur_min = min(cur_min, nums[left])
                    cur_max = max(cur_max, nums[left])

                # Remove overcounted subarrays if left boundary expanded
                if left < right:
                    window_len = right - left
                    total -= window_len * (window_len + 1) // 2

        # Add subarrays from final window
        window_len = right - left + 1
        total += window_len * (window_len + 1) // 2

        return total
```

</details>
