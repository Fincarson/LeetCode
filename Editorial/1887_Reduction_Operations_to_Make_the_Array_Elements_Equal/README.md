# 1887. Reduction Operations to Make the Array Elements Equal

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/)  
`Array` `Sorting`

**Problem Link:** [LeetCode 1887 - Reduction Operations to Make the Array Elements Equal](https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/)

## Problem

Given an integer array nums, your goal is to make all elements in nums equal. To complete one operation, follow these steps:

Return the number of operations to make all elements in nums equal.

### Example 1

```text
Input: nums = [5,1,3]
Output: 3
Explanation: It takes 3 operations to make all elements in nums equal:
1. largest = 5 at index 0. nextLargest = 3. Reduce nums[0] to 3. nums = [3,1,3].
2. largest = 3 at index 0. nextLargest = 1. Reduce nums[0] to 1. nums = [1,1,3].
3. largest = 3 at index 2. nextLargest = 1. Reduce nums[2] to 1. nums = [1,1,1].
```

### Example 2

```text
Input: nums = [1,1,1]
Output: 0
Explanation: All elements in nums are already equal.
```

### Example 3

```text
Input: nums = [1,1,2,2,3]
Output: 4
Explanation: It takes 4 operations to make all elements in nums equal:
1. largest = 3 at index 4. nextLargest = 2. Reduce nums[4] to 2. nums = [1,1,2,2,2].
2. largest = 2 at index 2. nextLargest = 1. Reduce nums[2] to 1. nums = [1,1,1,2,2].
3. largest = 2 at index 3. nextLargest = 1. Reduce nums[3] to 1. nums = [1,1,1,1,2].
4. largest = 2 at index 4. nextLargest = 1. Reduce nums[4] to 1. nums = [1,1,1,1,1].
```

## Constraints

- 1 <= nums.length <= 5 * 104
- 1 <= nums[i] <= 5 * 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1887. Reduction Operations to Make the Array Elements Equal

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sort and Count | C++, Java, Python3 |

## Approach: Sort and Count

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int up = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                up++;
            }
            
            ans += up;
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
    public int reductionOperations(int[] nums) {
        Arrays.sort(nums);
        int ans = 0;
        int up = 0;
        
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i - 1]) {
                up++;
            }
            
            ans += up;
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
    def reductionOperations(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        up = 0
        
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                up += 1
                
            ans += up
        
        return ans
```

</details>
