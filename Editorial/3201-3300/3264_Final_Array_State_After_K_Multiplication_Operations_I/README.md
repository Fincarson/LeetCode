# 3264. Final Array State After K Multiplication Operations I

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/)  
`Array` `Math` `Heap (Priority Queue)` `Simulation`

**Problem Link:** [LeetCode 3264 - Final Array State After K Multiplication Operations I](https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/)

## Problem

You are given an integer array nums, an integer k, and an integer multiplier.

You need to perform k operations on nums. In each operation:

- Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
- Replace the selected minimum value x with x * multiplier.

Return an integer array denoting the final state of nums after performing all k operations.

### Example 1

### Example 2

## Constraints

- 1 <= nums.length <= 100
- 1 <= nums[i] <= 100
- 1 <= k <= 10
- 1 <= multiplier <= 5

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3264. Final Array State After K Multiplication Operations I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| K Full Array Scans for Minimum Element Multiplication | C++, Java, Python3 |
| Heap-Optimized K Minimum Value Multiplication | C++, Java, Python3 |

## Approach 1: K Full Array Scans for Minimum Element Multiplication

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        while (k--) {
            // Find the index of the smallest element in the array
            int minIndex = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] < nums[minIndex]) {
                    minIndex = i;
                }
            }

            // Multiply the smallest element by the multiplier
            nums[minIndex] *= multiplier;
        }

        return nums;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] getFinalState(int[] nums, int k, int multiplier) {
        int n = nums.length;

        for (int j = 0; j < k; j++) {
            // Find the index of the smallest element in the array
            int minIndex = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] < nums[minIndex]) {
                    minIndex = i;
                }
            }

            // Multiply the smallest element by the multiplier
            nums[minIndex] *= multiplier;
        }

        return nums;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int):
        n = len(nums)

        for _ in range(k):
            # Find the index of the smallest element in the array
            min_index = 0
            for i in range(n):
                if nums[i] < nums[min_index]:
                    min_index = i

            # Multiply the smallest element by the multiplier
            nums[min_index] *= multiplier

        return nums
```

</details>

<br>

## Approach 2: Heap-Optimized K Minimum Value Multiplication

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<pair<int, int>> heap;
        for (int i = 0; i < nums.size(); i++) {
            heap.push_back({nums[i], i});
        }

        make_heap(heap.begin(), heap.end(), greater<>());

        while (k--) {
            pop_heap(heap.begin(), heap.end(), greater<>());
            auto [value, i] = heap.back();
            heap.pop_back();

            nums[i] *= multiplier;
            heap.push_back({nums[i], i});
            push_heap(heap.begin(), heap.end(), greater<>());
        }

        return nums;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
 class Solution {

    public int[] getFinalState(int[] nums, int k, int multiplier) {
        PriorityQueue<int[]> heap = new PriorityQueue<>((a, b) -> {
            int valueComparison = Integer.compare(a[0], b[0]);
            if (valueComparison == 0) {
                return Integer.compare(a[1], b[1]);
            }
            return valueComparison;
        });

        for (int i = 0; i < nums.length; i++) {
            heap.offer(new int[] { nums[i], i });
        }

        while (k-- > 0) {
            int[] smallest = heap.poll();
            int index = smallest[1];

            nums[index] *= multiplier;
            heap.offer(new int[] { nums[index], index });
        }

        return nums;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int):
        pq = [(val, i) for i, val in enumerate(nums)]
        heapify(pq)

        for _ in range(k):
            _, i = heappop(pq)
            nums[i] *= multiplier
            heappush(pq, (nums[i], i))

        return nums
```

</details>
