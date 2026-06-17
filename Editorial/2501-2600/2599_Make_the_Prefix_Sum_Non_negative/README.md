# 2599. Make the Prefix Sum Non-negative

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/make-the-prefix-sum-non-negative/)  
`Array` `Greedy` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 2599 - Make the Prefix Sum Non-negative](https://leetcode.com/problems/make-the-prefix-sum-non-negative/)

## Problem

You are given a 0-indexed integer array nums. You can apply the following operation any number of times:

- Pick any element from nums and put it at the end of nums.

The prefix sum array of nums is an array prefix of the same length as nums such that prefix[i] is the sum of all the integers nums[j] where j is in the inclusive range [0, i].

Return the minimum number of operations such that the prefix sum array does not contain negative integers. The test cases are generated such that it is always possible to make the prefix sum array non-negative.

### Example 1

```text
Input: nums = [2,3,-5,4]
Output: 0
Explanation: we do not need to do any operations.
The array is [2,3,-5,4]. The prefix sum array is [2, 5, 0, 4].
```

### Example 2

```text
Input: nums = [3,-5,-2,6]
Output: 1
Explanation: we can do one operation on index 1.
The array after the operation is [3,-2,6,-5]. The prefix sum array is [3, 1, 7, 2].
```

## Constraints

- 1 <= nums.length <= 105
- -109 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Furthest Building You Can Reach](https://leetcode.com/problems/furthest-building-you-can-reach/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Transactions Without Negative Balance](https://leetcode.com/problems/maximum-transactions-without-negative-balance/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2599. Make the Prefix Sum Non-negative

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy | C++, Java, Python3 |

## Approach: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        int operations = 0;
        long prefixSum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) {
            // Push negative elements to the mim heap.
            if (num < 0) {
                pq.push(num);
            }

            prefixSum += num;
            // Pop the minimum element from the heap and subtract from the sum.
            if (prefixSum < 0) {
                prefixSum -= pq.top();
                pq.pop();
                // Increment the operations required.
                operations++;
            }
        }

        return operations;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int makePrefSumNonNegative(int[] nums) {
        int operations = 0;
        long prefixSum = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int num : nums) {
            // Push negative elements to the min heap.
            if (num < 0) {
                pq.offer(num);
            }

            prefixSum += num;
            // Pop the minimum element from the heap and subtract from the sum.
            if (prefixSum < 0) {
                prefixSum -= pq.poll();
                // Increment the operations required.
                operations++;
            }
        }

        return operations;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def makePrefSumNonNegative(self, nums):
        operations = 0
        prefix_sum = 0
        pq = []

        for num in nums:
            # Push negative elements to the min heap.
            if num < 0:
                heapq.heappush(pq, num)

            prefix_sum += num
            # Pop the minimum element from the heap and subtract from the sum.
            if prefix_sum < 0:
                prefix_sum -= heapq.heappop(pq)
                # Increment the operations required.
                operations += 1

        return operations
```

</details>
