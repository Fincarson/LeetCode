# 1425. Constrained Subsequence Sum

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/constrained-subsequence-sum/)  
`Array` `Dynamic Programming` `Queue` `Sliding Window` `Heap (Priority Queue)` `Monotonic Queue`

**Problem Link:** [LeetCode 1425 - Constrained Subsequence Sum](https://leetcode.com/problems/constrained-subsequence-sum/)

## Problem

Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.

### Example 1

```text
Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subsequence is [10, 2, 5, 20].
```

### Example 2

```text
Input: nums = [-1,-2,-3], k = 1
Output: -1
Explanation: The subsequence must be non-empty, so we choose the largest number.
```

### Example 3

```text
Input: nums = [10,-2,-10,-5,20], k = 2
Output: 23
Explanation: The subsequence is [10, -2, -5, 20].
```

## Constraints

- 1 <= k <= nums.length <= 105
- -104 <= nums[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Element-Sum of a Complete Subset of Indices](https://leetcode.com/problems/maximum-element-sum-of-a-complete-subset-of-indices/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1425. Constrained Subsequence Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Heap/Priority Queue | C++, Java, Python3 |
| TreeMap-Like Data Structure | C++, Java, Python3 |
| Monotonic Deque | C++, Java, Python3 |

## Approach 1: Heap/Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;
        heap.push({nums[0], 0});
        int ans = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            while (i - heap.top().second > k) {
                heap.pop();
            }

            int curr = max(0, heap.top().first) + nums[i];
            ans = max(ans, curr);
            heap.push({curr, i});
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
    public int constrainedSubsetSum(int[] nums, int k) {
        PriorityQueue<int[]> heap = new PriorityQueue<>((a, b) -> {
            return b[0] - a[0];
        });
        
        heap.add(new int[] {nums[0], 0});
        int ans = nums[0];
        
        for (int i = 1; i < nums.length; i++) {
            while (i - heap.peek()[1] > k) {
                heap.remove();
            }
            
            int curr = Math.max(0, heap.peek()[0]) + nums[i];
            ans = Math.max(ans, curr);
            heap.add(new int[] {curr, i});
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
import heapq

class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        heap = [(-nums[0], 0)]
        ans = nums[0]
        
        for i in range(1, len(nums)):
            while i - heap[0][1] > k:
                heapq.heappop(heap)

            curr = max(0, -heap[0][0]) + nums[i]
            ans = max(ans, curr)
            heapq.heappush(heap, (-curr, i))

        return ans
```

</details>

<br>

## Approach 2: TreeMap-Like Data Structure

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        map<int, int> window;
        window[0] = 0;
        vector<int> dp(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = nums[i] + window.rbegin()->first;
            window[dp[i]]++;
            
            if (i >= k) {
                window[dp[i - k]]--;
                if (window[dp[i - k]] == 0) {
                    window.erase(dp[i - k]);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int constrainedSubsetSum(int[] nums, int k) {
        TreeMap<Integer, Integer> window = new TreeMap();
        window.put(0, 0);
        
        int dp[] = new int[nums.length];
        
        for (int i = 0; i < nums.length; i++) {
            dp[i] = nums[i] + window.lastKey();
            window.put(dp[i], window.getOrDefault(dp[i], 0) + 1);
            
            if (i >= k) {
                window.put(dp[i - k], window.get(dp[i - k]) - 1);
                if (window.get(dp[i - k]) == 0) {
                    window.remove(dp[i - k]);
                }
            }
        }
        
        int ans = Integer.MIN_VALUE;
        for (int num : dp) {
            ans = Math.max(ans, num);
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from sortedcontainers import SortedList

class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        window = SortedList([0])
        dp = [0] * len(nums)
        
        for i in range(len(nums)):
            dp[i] = nums[i] + window[-1]
            window.add(dp[i])
            if i >= k:
                window.remove(dp[i - k])
        
        return max(dp)
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
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> queue;
        vector<int> dp(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            if (!queue.empty() && i - queue.front() > k) {
                queue.pop_front();
            }
            
            dp[i] = (!queue.empty() ? dp[queue.front()] : 0) + nums[i];
            while (!queue.empty() && dp[queue.back()] < dp[i]) {
                queue.pop_back();
            }
            
            if (dp[i] > 0) {
                queue.push_back(i);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int constrainedSubsetSum(int[] nums, int k) {
        Deque<Integer> queue = new ArrayDeque<>();
        int dp[] = new int[nums.length];
        
        for (int i = 0; i < nums.length; i++) {
            if (!queue.isEmpty() && i - queue.peek() > k) {
                queue.poll();
            }
            
            dp[i] = (!queue.isEmpty() ? dp[queue.peek()] : 0) + nums[i];
            while (!queue.isEmpty() && dp[queue.peekLast()] < dp[i]) {
                queue.pollLast();
            }
            
            if (dp[i] > 0) {
                queue.offer(i);
            }
        }
        
        int ans = Integer.MIN_VALUE;
        for (int num : dp) {
            ans = Math.max(ans, num);
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
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        queue = deque()
        dp = [0] * len(nums)
        
        for i in range(len(nums)):
            if queue and i - queue[0] > k:
                queue.popleft()
            
            dp[i] = (dp[queue[0]] if queue else 0) + nums[i]
            while queue and dp[queue[-1]] < dp[i]:
                queue.pop()
            
            if dp[i] > 0:
                queue.append(i)
                
        return max(dp)
```

</details>
