# 862. Shortest Subarray with Sum at Least K

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/)  
`Array` `Binary Search` `Queue` `Sliding Window` `Heap (Priority Queue)` `Prefix Sum` `Monotonic Queue`

**Problem Link:** [LeetCode 862 - Shortest Subarray with Sum at Least K](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/)

## Problem

Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.

### Example 1

```text
Input: nums = [1], k = 1
Output: 1
```

### Example 2

```text
Input: nums = [1,2], k = 4
Output: -1
```

### Example 3

```text
Input: nums = [2,-1,2], k = 3
Output: 3
```

## Constraints

- 1 <= nums.length <= 105
- -105 <= nums[i] <= 105
- 1 <= k <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Shortest Subarray With OR at Least K II](https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Shortest Subarray With OR at Least K I](https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-i/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 862. Shortest Subarray with Sum at Least K

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Priority Queue | C++, Java, Python3 |
| Monotonic Stack + Binary Search | C++, Java, Python3 |
| Deque | C++, Java, Python3 |

## Approach 1: Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        // Initialize result to the maximum possible integer value
        int shortestSubarrayLength = INT_MAX;

        long long cumulativeSum = 0;

        // Min-heap to store cumulative sum and its corresponding index
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            prefixSumHeap;

        // Iterate through the array
        for (int i = 0; i < n; i++) {
            // Update cumulative sum
            cumulativeSum += nums[i];

            // If cumulative sum is already >= k, update shortest length
            if (cumulativeSum >= k) {
                shortestSubarrayLength = min(shortestSubarrayLength, i + 1);
            }

            // Remove subarrays from heap that can form a valid subarray
            while (!prefixSumHeap.empty() &&
                   cumulativeSum - prefixSumHeap.top().first >= k) {
                // Update shortest subarray length
                shortestSubarrayLength =
                    min(shortestSubarrayLength, i - prefixSumHeap.top().second);
                prefixSumHeap.pop();
            }

            // Add current cumulative sum and index to heap
            prefixSumHeap.emplace(cumulativeSum, i);
        }

        // Return -1 if no valid subarray found
        return shortestSubarrayLength == INT_MAX ? -1 : shortestSubarrayLength;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int shortestSubarray(int[] nums, int k) {
        int n = nums.length;

        // Initialize result to the maximum possible integer value
        int shortestSubarrayLength = Integer.MAX_VALUE;

        long cumulativeSum = 0;

        // Min-heap to store cumulative sum and its corresponding index
        PriorityQueue<Pair<Long, Integer>> prefixSumHeap = new PriorityQueue<>(
            (a, b) -> Long.compare(a.getKey(), b.getKey())
        );

        // Iterate through the array
        for (int i = 0; i < n; i++) {
            // Update cumulative sum
            cumulativeSum += nums[i];

            // If cumulative sum is already >= k, update shortest length
            if (cumulativeSum >= k) {
                shortestSubarrayLength = Math.min(
                    shortestSubarrayLength,
                    i + 1
                );
            }

            // Remove subarrays from heap that can form a valid subarray
            while (
                !prefixSumHeap.isEmpty() &&
                cumulativeSum - prefixSumHeap.peek().getKey() >= k
            ) {
                // Update shortest subarray length
                shortestSubarrayLength = Math.min(
                    shortestSubarrayLength,
                    i - prefixSumHeap.poll().getValue()
                );
            }

            // Add current cumulative sum and index to heap
            prefixSumHeap.offer(new Pair<>(cumulativeSum, i));
        }

        // Return -1 if no valid subarray found
        return shortestSubarrayLength == Integer.MAX_VALUE
            ? -1
            : shortestSubarrayLength;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        n = len(nums)

        # Initialize result to the maximum possible integer value
        shortest_subarray_length = float("inf")

        cumulative_sum = 0

        # Min-heap to store cumulative sum and its corresponding index
        prefix_sum_heap = []

        # Iterate through the array
        for i, num in enumerate(nums):
            # Update cumulative sum
            cumulative_sum += num

            # If cumulative sum is already >= k, update shortest length
            if cumulative_sum >= k:
                shortest_subarray_length = min(shortest_subarray_length, i + 1)

            # Remove subarrays from heap that can form a valid subarray
            while (
                prefix_sum_heap and cumulative_sum - prefix_sum_heap[0][0] >= k
            ):
                # Update shortest subarray length
                shortest_subarray_length = min(
                    shortest_subarray_length, i - heappop(prefix_sum_heap)[1]
                )

            # Add current cumulative sum and index to heap
            heappush(prefix_sum_heap, (cumulative_sum, i))

        # Return -1 if no valid subarray found
        return (
            -1
            if shortest_subarray_length == float("inf")
            else shortest_subarray_length
        )
```

</details>

<br>

## Approach 2: Monotonic Stack + Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        // Stack-like list to store cumulative sums and their indices
        vector<pair<long long, int>> cumulativeSumStack;
        cumulativeSumStack.emplace_back(0LL, -1);

        long long runningCumulativeSum = 0;
        int shortestSubarrayLength = INT_MAX;

        for (int i = 0; i < n; i++) {
            // Update cumulative sum
            runningCumulativeSum += nums[i];

            // Remove entries from stack that are larger than current cumulative
            // sum
            while (!cumulativeSumStack.empty() &&
                   runningCumulativeSum <= cumulativeSumStack.back().first) {
                cumulativeSumStack.pop_back();
            }

            // Add current cumulative sum and index to stack
            cumulativeSumStack.emplace_back(runningCumulativeSum, i);

            int candidateIndex = findCandidateIndex(cumulativeSumStack,
                                                    runningCumulativeSum - k);

            // If a valid candidate is found, update the shortest subarray
            // length
            if (candidateIndex != -1) {
                shortestSubarrayLength =
                    min(shortestSubarrayLength,
                        i - cumulativeSumStack[candidateIndex].second);
            }
        }

        // Return -1 if no valid subarray found
        return shortestSubarrayLength == INT_MAX ? -1 : shortestSubarrayLength;
    }

private:
    // Binary search to find the largest index where cumulative sum is <= target
    int findCandidateIndex(const vector<pair<long long, int>>& nums,
                           long long target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid].first <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int shortestSubarray(int[] nums, int k) {
        int n = nums.length;

        // Stack-like list to store cumulative sums and their indices
        List<Pair<Long, Integer>> cumulativeSumStack = new ArrayList<>();
        cumulativeSumStack.add(new Pair<>(0L, -1));

        long runningCumulativeSum = 0;
        int shortestSubarrayLength = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            // Update cumulative sum
            runningCumulativeSum += nums[i];

            // Remove entries from stack that are larger than current cumulative sum
            while (
                !cumulativeSumStack.isEmpty() &&
                runningCumulativeSum <=
                cumulativeSumStack.get(cumulativeSumStack.size() - 1).getKey()
            ) {
                cumulativeSumStack.remove(cumulativeSumStack.size() - 1);
            }

            // Add current cumulative sum and index to stack
            cumulativeSumStack.add(new Pair<>(runningCumulativeSum, i));

            int candidateIndex = findCandidateIndex(
                cumulativeSumStack,
                runningCumulativeSum - k
            );

            // If a valid candidate is found, update the shortest subarray length
            if (candidateIndex != -1) {
                shortestSubarrayLength = Math.min(
                    shortestSubarrayLength,
                    i - cumulativeSumStack.get(candidateIndex).getValue()
                );
            }
        }

        // Return -1 if no valid subarray found
        return shortestSubarrayLength == Integer.MAX_VALUE
            ? -1
            : shortestSubarrayLength;
    }

    // Binary search to find the largest index where cumulative sum is <= target
    private int findCandidateIndex(
        List<Pair<Long, Integer>> nums,
        long target
    ) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums.get(mid).getKey() <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        n = len(nums)

        # Stack-like list to store cumulative sums and their indices
        cumulative_sum_stack = [(0, -1)]

        running_cumulative_sum = 0
        shortest_subarray_length = float("inf")

        for i in range(n):
            # Update cumulative sum
            running_cumulative_sum += nums[i]

            # Remove entries from stack that are larger than current cumulative sum
            while (
                cumulative_sum_stack
                and running_cumulative_sum <= cumulative_sum_stack[-1][0]
            ):
                cumulative_sum_stack.pop()

            # Add current cumulative sum and index to stack
            cumulative_sum_stack.append((running_cumulative_sum, i))

            candidate_index = self._find_candidate_index(
                cumulative_sum_stack, running_cumulative_sum - k
            )

            # If a valid candidate is found, update the shortest subarray length
            if candidate_index != -1:
                shortest_subarray_length = min(
                    shortest_subarray_length,
                    i - cumulative_sum_stack[candidate_index][1],
                )

        # Return -1 if no valid subarray found
        return (
            shortest_subarray_length
            if shortest_subarray_length != float("inf")
            else -1
        )

    # Binary search to find the largest index where cumulative sum is <= target
    def _find_candidate_index(
        self, nums: List[Tuple[int, int]], target: int
    ) -> int:
        left, right = 0, len(nums) - 1

        while left <= right:
            mid = left + (right - left) // 2

            if nums[mid][0] <= target:
                left = mid + 1
            else:
                right = mid - 1

        return right
```

</details>

<br>

## Approach 3: Deque

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int targetSum) {
        int n = nums.size();

        // Size is n+1 to handle subarrays starting from index 0
        vector<long long> prefixSums(n + 1, 0);

        // Calculate prefix sums
        for (int i = 1; i <= n; i++) {
            prefixSums[i] = prefixSums[i - 1] + nums[i - 1];
        }

        deque<int> candidateIndices;

        int shortestSubarrayLength = INT_MAX;

        for (int i = 0; i <= n; i++) {
            // Remove candidates from front of deque where subarray sum meets
            // target
            while (!candidateIndices.empty() &&
                   prefixSums[i] - prefixSums[candidateIndices.front()] >=
                       targetSum) {
                // Update shortest subarray length
                shortestSubarrayLength =
                    min(shortestSubarrayLength, i - candidateIndices.front());
                candidateIndices.pop_front();
            }

            // Maintain monotonicity by removing indices with larger prefix sums
            while (!candidateIndices.empty() &&
                   prefixSums[i] <= prefixSums[candidateIndices.back()]) {
                candidateIndices.pop_back();
            }

            // Add current index to candidates
            candidateIndices.push_back(i);
        }

        // Return -1 if no valid subarray found
        return shortestSubarrayLength == INT_MAX ? -1 : shortestSubarrayLength;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int shortestSubarray(int[] nums, int targetSum) {
        int n = nums.length;

        // Size is n+1 to handle subarrays starting from index 0
        long[] prefixSums = new long[n + 1];

        // Calculate prefix sums
        for (int i = 1; i <= n; i++) {
            prefixSums[i] = prefixSums[i - 1] + nums[i - 1];
        }

        Deque<Integer> candidateIndices = new ArrayDeque<>();

        int shortestSubarrayLength = Integer.MAX_VALUE;

        for (int i = 0; i <= n; i++) {
            // Remove candidates from front of deque where subarray sum meets target
            while (
                !candidateIndices.isEmpty() &&
                prefixSums[i] - prefixSums[candidateIndices.peekFirst()] >=
                targetSum
            ) {
                // Update shortest subarray length
                shortestSubarrayLength = Math.min(
                    shortestSubarrayLength,
                    i - candidateIndices.pollFirst()
                );
            }

            // Maintain monotonicity by removing indices with larger prefix sums
            while (
                !candidateIndices.isEmpty() &&
                prefixSums[i] <= prefixSums[candidateIndices.peekLast()]
            ) {
                candidateIndices.pollLast();
            }

            // Add current index to candidates
            candidateIndices.offerLast(i);
        }

        // Return -1 if no valid subarray found
        return shortestSubarrayLength == Integer.MAX_VALUE
            ? -1
            : shortestSubarrayLength;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestSubarray(self, nums: List[int], target_sum: int) -> int:
        n = len(nums)

        # Size is n+1 to handle subarrays starting from index 0
        prefix_sums = [0] * (n + 1)

        # Calculate prefix sums
        for i in range(1, n + 1):
            prefix_sums[i] = prefix_sums[i - 1] + nums[i - 1]

        candidate_indices = deque()

        shortest_subarray_length = float("inf")

        for i in range(n + 1):
            # Remove candidates from front of deque where subarray sum meets target
            while (
                candidate_indices
                and prefix_sums[i] - prefix_sums[candidate_indices[0]]
                >= target_sum
            ):
                # Update shortest subarray length
                shortest_subarray_length = min(
                    shortest_subarray_length, i - candidate_indices.popleft()
                )

            # Maintain monotonicity by removing indices with larger prefix sums
            while (
                candidate_indices
                and prefix_sums[i] <= prefix_sums[candidate_indices[-1]]
            ):
                candidate_indices.pop()

            # Add current index to candidates
            candidate_indices.append(i)

        # Return -1 if no valid subarray found
        return (
            shortest_subarray_length
            if shortest_subarray_length != float("inf")
            else -1
        )
```

</details>
