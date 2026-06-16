# 2870. Minimum Number of Operations to Make Array Empty

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/)  
`Array` `Hash Table` `Greedy` `Counting`

**Problem Link:** [LeetCode 2870 - Minimum Number of Operations to Make Array Empty](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/)

## Problem

You are given a 0-indexed array nums consisting of positive integers.

There are two types of operations that you can apply on the array any number of times:

- Choose two elements with equal values and delete them from the array.
- Choose three elements with equal values and delete them from the array.

Return the minimum number of operations required to make the array empty, or -1 if it is not possible.

### Example 1

```text
Input: nums = [2,3,3,2,2,4,2,3,4]
Output: 4
Explanation: We can apply the following operations to make the array empty:
- Apply the first operation on the elements at indices 0 and 3. The resulting array is nums = [3,3,2,4,2,3,4].
- Apply the first operation on the elements at indices 2 and 4. The resulting array is nums = [3,3,4,3,4].
- Apply the second operation on the elements at indices 0, 1, and 3. The resulting array is nums = [4,4].
- Apply the first operation on the elements at indices 0 and 1. The resulting array is nums = [].
It can be shown that we cannot make the array empty in less than 4 operations.
```

### Example 2

```text
Input: nums = [2,1,2,2,3,3]
Output: -1
Explanation: It is impossible to empty the array.
```

## Constraints

- 2 <= nums.length <= 105
- 1 <= nums[i] <= 106

Note: This question is the same as 2244: Minimum Rounds to Complete All Tasks.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2870. Minimum Number of Operations to Make Array Empty

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Counting | C++, Java, JavaScript, Python3 |

## Approach: Counting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int num : nums) {
            counter[num]++;
        }
        int ans = 0;
        for (auto [_, c]: counter) {
            if (c == 1) {
                return -1;
            }
            ans += ceil((double)(c) / 3);
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
    public int minOperations(int[] nums) {
        var counter = new HashMap<Integer, Integer>();
        for (int num: nums) {
            counter.put(num, counter.getOrDefault(num, 0) + 1);
        }
        int ans = 0;
        for (int c: counter.values()) {
            if (c == 1) {
                return -1;
            }
            ans += Math.ceil((double) c / 3);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minOperations = function(nums) {
    const counter = new Map();
    for (const num of nums) {
        counter.set(num, (counter.get(num) || 0) + 1);
    }
    let ans = 0;
    for (const c of counter.values()) {
        if (c === 1) {
            return -1;
        }
        ans += Math.ceil(c / 3);
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        counter = Counter(nums)
        ans = 0
        for c in counter.values():
            if c == 1: 
                return -1
            ans += ceil(c / 3)
        return ans
```

</details>
