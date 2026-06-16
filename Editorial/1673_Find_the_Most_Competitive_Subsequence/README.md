# 1673. Find the Most Competitive Subsequence

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-the-most-competitive-subsequence/)  
`Array` `Stack` `Greedy` `Monotonic Stack`

**Problem Link:** [LeetCode 1673 - Find the Most Competitive Subsequence](https://leetcode.com/problems/find-the-most-competitive-subsequence/)

## Problem

Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.

An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.

We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first position where a and b differ, subsequence a has a number less than the corresponding number in b. For example, [1,3,4] is more competitive than [1,3,5] because the first position they differ is at the final number, and 4 is less than 5.

### Example 1

```text
Input: nums = [3,5,2,6], k = 2
Output: [2,6]
Explanation: Among the set of every possible subsequence: {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]}, [2,6] is the most competitive.
```

### Example 2

```text
Input: nums = [2,4,3,3,5,4,9,6], k = 4
Output: [2,3,3,4]
```

## Constraints

- 1 <= nums.length <= 105
- 0 <= nums[i] <= 109
- 1 <= k <= nums.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove K Digits](https://leetcode.com/problems/remove-k-digits/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Smallest Subsequence of Distinct Characters](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1673. Find the Most Competitive Subsequence

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Double-Ended Queue | C++, Java |

## Approach 1: Using Double-Ended Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        deque<int> queue;
        int additionalCount = nums.size() - k;
        for (int i = 0; i < nums.size(); i++) {
            while (!queue.empty() && queue.back() > nums[i] &&
                   additionalCount > 0) {
                queue.pop_back();
                additionalCount--;
            }
            queue.push_back(nums[i]);
        }
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(queue.front());
            queue.pop_front();
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] mostCompetitive(int[] nums, int k) {
        Deque<Integer> queue = new ArrayDeque<Integer>();
        int additionalCount = nums.length - k;
        for (int i = 0; i < nums.length; i++) {
            while (!queue.isEmpty() && queue.peekLast() > nums[i] && additionalCount > 0) {
                queue.pollLast();
                additionalCount--;
            }
            queue.addLast(nums[i]);
        }
        int[] result = new int[k];
        for (int i = 0; i < k; i++) {
            result[i] = queue.pollFirst();
        }
        return result;
    }
}
```

</details>
