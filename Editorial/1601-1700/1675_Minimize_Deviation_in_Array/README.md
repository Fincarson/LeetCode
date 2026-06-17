# 1675. Minimize Deviation in Array

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/minimize-deviation-in-array/)  
`Array` `Greedy` `Heap (Priority Queue)` `Ordered Set`

**Problem Link:** [LeetCode 1675 - Minimize Deviation in Array](https://leetcode.com/problems/minimize-deviation-in-array/)

## Problem

You are given an array nums of n positive integers.

You can perform two types of operations on any element of the array any number of times:

- If the element is even, divide it by 2.

		For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
- If the element is odd, multiply it by 2.

		For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].

The deviation of the array is the maximum difference between any two elements in the array.

Return the minimum deviation the array can have after performing some number of operations.

### Example 1

```text
Input: nums = [1,2,3,4]
Output: 1
Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.
```

### Example 2

```text
Input: nums = [4,1,5,20,3]
Output: 3
Explanation: You can transform the array after two operations to [4,2,5,5,3], then the deviation will be 5 - 2 = 3.
```

### Example 3

```text
Input: nums = [2,10,8]
Output: 3
```

## Constraints

- n == nums.length
- 2 <= n <= 5 * 104
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

# Editorial - 1675. Minimize Deviation in Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulation + Heap | C++, Java, Python3 |

## Approach 1: Simulation + Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> evens;
        int minimum = INT_MAX;
        for (int num : nums) {
            if (num % 2 == 0) {
                evens.push(num);
                minimum = min(minimum, num);
            } else {
                evens.push(num * 2);
                minimum = min(minimum, num * 2);
            }
        }
        int minDeviation = INT_MAX;
        while (!evens.empty()) {
            int currentValue = evens.top();
            evens.pop();
            minDeviation = min(minDeviation, currentValue - minimum);
            if (currentValue % 2 == 0) {
                evens.push(currentValue / 2);
                minimum = min(minimum, currentValue / 2);
            } else {
                // if the maximum is odd, break and return
                break;
            }
        }
        return minDeviation;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minimumDeviation(int[] nums) {
        PriorityQueue<Integer> evens = new PriorityQueue<>(Collections.reverseOrder());
        int minimum = Integer.MAX_VALUE;
        for (int num : nums) {
            if (num % 2 == 0) {
                evens.offer(num);
                minimum = Math.min(minimum, num);
            } else {
                evens.offer(num * 2);
                minimum = Math.min(minimum, num * 2);
            }
        }
        int minDeviation = Integer.MAX_VALUE;

        while (!evens.isEmpty()) {
            int currentValue = evens.poll();
            minDeviation = Math.min(minDeviation, currentValue - minimum);
            if (currentValue % 2 == 0) {
                evens.offer(currentValue / 2);
                minimum = Math.min(minimum, currentValue / 2);
            } else {
                // if the maximum is odd, break and return
                break;
            }
        }
        return minDeviation;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        # since heapq is a min-heap
        # we use negative of the numbers to mimic a max-heap
        evens = []
        minimum = inf
        for num in nums:
            if num % 2 == 0:
                evens.append(-num)
                minimum = min(minimum, num)
            else:
                evens.append(-num*2)
                minimum = min(minimum, num*2)
        heapq.heapify(evens)
        min_deviation = inf
        while evens:
            current_value = -heapq.heappop(evens)
            min_deviation = min(min_deviation, current_value-minimum)
            if current_value % 2 == 0:
                minimum = min(minimum, current_value//2)
                heapq.heappush(evens, -current_value//2)
            else:
                # if the maximum is odd, break and return
                break
        return min_deviation
```

</details>
