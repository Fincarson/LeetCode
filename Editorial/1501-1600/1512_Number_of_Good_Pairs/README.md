# 1512. Number of Good Pairs

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/number-of-good-pairs/)  
`Array` `Hash Table` `Math` `Counting`

**Problem Link:** [LeetCode 1512 - Number of Good Pairs](https://leetcode.com/problems/number-of-good-pairs/)

## Problem

Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

### Example 1

```text
Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
```

### Example 2

```text
Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.
```

### Example 3

```text
Input: nums = [1,2,3]
Output: 0
```

## Constraints

- 1 <= nums.length <= 100
- 1 <= nums[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Pairs of Interchangeable Rectangles](https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Substrings That Begin and End With the Same Letter](https://leetcode.com/problems/substrings-that-begin-and-end-with-the-same-letter/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1512. Number of Good Pairs

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Check All Pairs | C++, Java, Python3 |
| Hash Map | C++, Java, Python3 |

## Approach 1: Check All Pairs

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    ans++;
                }
            }
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
    public int numIdenticalPairs(int[] nums) {
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] == nums[j]) {
                    ans++;
                }
            }
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
    def numIdenticalPairs(self, nums: List[int]) -> int:
        ans = 0
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] == nums[j]:
                    ans += 1
        
        return ans
```

</details>

<br>

## Approach 2: Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> counts;
        int ans = 0;
        
        for (int num: nums) {
            ans += counts[num];
            counts[num]++;
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
    public int numIdenticalPairs(int[] nums) {
        Map<Integer, Integer> counts = new HashMap<>();
        int ans = 0;

        for (int num: nums) {
            ans += counts.getOrDefault(num, 0);
            counts.put(num, counts.getOrDefault(num, 0) + 1);
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
    def numIdenticalPairs(self, nums: List[int]) -> int:
        counts = defaultdict(int)
        ans = 0
        
        for num in nums:
            ans += counts[num]
            counts[num] += 1
        
        return ans
```

</details>
