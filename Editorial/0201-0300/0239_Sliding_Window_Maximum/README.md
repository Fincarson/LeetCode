# 239. Sliding Window Maximum

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/sliding-window-maximum/)  
`Array` `Queue` `Sliding Window` `Heap (Priority Queue)` `Monotonic Queue`

**Problem Link:** [LeetCode 239 - Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)

## Problem

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

### Example 1

```text
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

### Example 2

```text
Input: nums = [1], k = 1
Output: [1]
```

## Constraints

- 1 <= nums.length <= 105
- -104 <= nums[i] <= 104
- 1 <= k <= nums.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Min Stack](https://leetcode.com/problems/min-stack/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Longest Substring with At Most Two Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Paint House II](https://leetcode.com/problems/paint-house-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Jump Game VI](https://leetcode.com/problems/jump-game-vi/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Number of Robots Within Budget](https://leetcode.com/problems/maximum-number-of-robots-within-budget/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Maximum Tastiness of Candy Basket](https://leetcode.com/problems/maximum-tastiness-of-candy-basket/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximal Score After Applying K Operations](https://leetcode.com/problems/maximal-score-after-applying-k-operations/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 239. Sliding Window Maximum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Monotonic Deque | C++, Java, Python3 |

## Approach: Monotonic Deque

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);

        for (int i = k; i < nums.size(); i++) {
            if(dq.front() == i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
            res.push_back(nums[dq.front()]);
        }
        
        return res;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> dq = new ArrayDeque<>();
        List<Integer> res = new ArrayList<>();

        for (int i = 0; i < k; i++) {
            while (!dq.isEmpty() && nums[i] >= nums[dq.peekLast()]) {
                dq.pollLast();
            }
            dq.offerLast(i);
        }
        res.add(nums[dq.peekFirst()]);

        for (int i = k; i < nums.length; i++) {
            if (dq.peekFirst() == i - k) {
                dq.pollFirst();
            }
            while (!dq.isEmpty() && nums[i] >= nums[dq.peekLast()]) {
                dq.pollLast();
            }

            dq.offerLast(i);
            res.add(nums[dq.peekFirst()]);
        }
        // Return the result as an array.
        return res.stream().mapToInt(i->i).toArray();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        dq = deque()
        res = []

        for i in range(k):
            while dq and nums[i] >= nums[dq[-1]]:
                dq.pop()
            dq.append(i)

        res.append(nums[dq[0]])

        for i in range(k, len(nums)):
            if dq and dq[0] == i - k:
                dq.popleft()
            while dq and nums[i] >= nums[dq[-1]]:
                dq.pop()

            dq.append(i)
            res.append(nums[dq[0]])

        return res
```

</details>
