# 1696. Jump Game VI

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/jump-game-vi/)  
`Array` `Dynamic Programming` `Queue` `Heap (Priority Queue)` `Monotonic Queue`

**Problem Link:** [LeetCode 1696 - Jump Game VI](https://leetcode.com/problems/jump-game-vi/)

## Problem

You are given a 0-indexed integer array nums and an integer k.

You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array. That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.

You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.

Return the maximum score you can get.

### Example 1

```text
Input: nums = [1,-1,-2,4,-7,3], k = 2
Output: 7
Explanation: You can choose your jumps forming the subsequence [1,-1,4,3] (underlined above). The sum is 7.
```

### Example 2

```text
Input: nums = [10,-5,-2,4,0,3], k = 3
Output: 17
Explanation: You can choose your jumps forming the subsequence [10,4,3] (underlined above). The sum is 17.
```

### Example 3

```text
Input: nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
Output: 0
```

## Constraints

- 1 <= nums.length, k <= 105
- -104 <= nums[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Jump Game VII](https://leetcode.com/problems/jump-game-vii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Jump Game VIII](https://leetcode.com/problems/jump-game-viii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximize Value of Function in a Ball Passing Game](https://leetcode.com/problems/maximize-value-of-function-in-a-ball-passing-game/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1696. Jump Game VI

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming + Deque | C++, Java, Python3 |

## Approach 1: Dynamic Programming + Deque

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> score(n);
        score[0] = nums[0];
        deque<int> dq;
        dq.push_back(0);
        for (int i = 1; i < n; i++) {
            // pop the old index
            while (!dq.empty() && dq.front() < i - k) {
                dq.pop_front();
            }
            score[i] = score[dq.front()] + nums[i];
            // pop the smaller value
            while (!dq.empty() && score[i] >= score[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return score[n - 1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxResult(int[] nums, int k) {
        int n = nums.length;
        int[] score = new int[n];
        score[0] = nums[0];
        Deque<Integer> dq = new LinkedList<>();
        dq.offerLast(0);
        for (int i = 1; i < n; i++) {
            // pop the old index
            while (dq.peekFirst() != null && dq.peekFirst() < i - k) {
                dq.pollFirst();
            }
            score[i] = score[dq.peek()] + nums[i];
            // pop the smaller value
            while (dq.peekLast() != null && score[i] >= score[dq.peekLast()]) {
                dq.pollLast();
            }
            dq.offerLast(i);
        }
        return score[n - 1];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        n = len(nums)
        score = [0]*n
        score[0] = nums[0]
        dq = deque()
        dq.append(0)
        for i in range(1, n):
            # pop the old index
            while dq and dq[0] < i-k:
                dq.popleft()
            score[i] = score[dq[0]] + nums[i]
            # pop the smaller value
            while dq and score[i] >= score[dq[-1]]:
                dq.pop()
            dq.append(i)
        return score[-1]
```

</details>
