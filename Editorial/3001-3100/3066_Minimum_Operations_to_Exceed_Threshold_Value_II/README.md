# 3066. Minimum Operations to Exceed Threshold Value II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/)  
`Array` `Heap (Priority Queue)` `Simulation`

**Problem Link:** [LeetCode 3066 - Minimum Operations to Exceed Threshold Value II](https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/)

## Problem

You are given a 0-indexed integer array nums, and an integer k.

You are allowed to perform some operations on nums, where in a single operation, you can:

- Select the two smallest integers x and y from nums.
- Remove x and y from nums.
- Insert (min(x, y) * 2 + max(x, y)) at any position in the array.

Note that you can only apply the described operation if nums contains at least two elements.

Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.

### Example 1

### Example 2

## Constraints

- 2 <= nums.length <= 2 * 105
- 1 <= nums[i] <= 109
- 1 <= k <= 109
- The input is generated such that an answer always exists. That is, after performing some number of operations, all elements of the array are greater than or equal to k.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Operations to Halve Array Sum](https://leetcode.com/problems/minimum-operations-to-halve-array-sum/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3066. Minimum Operations to Exceed Threshold Value II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Priority Queue | C++, Java, Python3 |

## Approach: Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> min_heap(nums.begin(),
                                                                   nums.end());
        int num_operations = 0;

        while (min_heap.top() < k) {
            long x = min_heap.top();
            min_heap.pop();
            long y = min_heap.top();
            min_heap.pop();
            min_heap.push(min(x, y) * 2 + max(x, y));

            num_operations++;
        }
        return num_operations;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minOperations(int[] nums, int k) {
        PriorityQueue<Long> minHeap = new PriorityQueue<Long>(
            Arrays.stream(nums)
                .mapToLong(i -> (long) i)
                .boxed()
                .collect(Collectors.toList())
        );
        int numOperations = 0;

        while (minHeap.peek() < k) {
            long x = minHeap.remove();
            long y = minHeap.remove();
            minHeap.add(Math.min(x, y) * 2 + Math.max(x, y));

            numOperations++;
        }
        return numOperations;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        heapq.heapify(nums)

        num_operations = 0
        while nums[0] < k:
            x = heapq.heappop(nums)
            y = heapq.heappop(nums)
            heapq.heappush(nums, min(x, y) * 2 + max(x, y))

            num_operations += 1

        return num_operations
```

</details>
