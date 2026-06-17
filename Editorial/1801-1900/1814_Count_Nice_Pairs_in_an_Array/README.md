# 1814. Count Nice Pairs in an Array

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/count-nice-pairs-in-an-array/)  
`Array` `Hash Table` `Math` `Counting`

**Problem Link:** [LeetCode 1814 - Count Nice Pairs in an Array](https://leetcode.com/problems/count-nice-pairs-in-an-array/)

## Problem

You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:

- 0 <= i < j < nums.length
- nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])

Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.

### Example 1

```text
Input: nums = [42,11,1,97]
Output: 2
Explanation: The two pairs are:
 - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
```

### Example 2

```text
Input: nums = [13,10,35,24,76]
Output: 4
```

## Constraints

- 1 <= nums.length <= 105
- 0 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Pairs of Interchangeable Rectangles](https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Number of Bad Pairs](https://leetcode.com/problems/count-number-of-bad-pairs/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Number of Pairs Satisfying Inequality](https://leetcode.com/problems/number-of-pairs-satisfying-inequality/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1814. Count Nice Pairs in an Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Counting With Hash Map | C++, Java, Python3 |

## Approach: Counting With Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        vector<int> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back(nums[i] - rev(nums[i]));
        }
        
        unordered_map<int, int> dic;
        int ans = 0;
        int MOD = 1e9 + 7;
        for (int num : arr) {
            ans = (ans + dic[num]) % MOD;
            dic[num]++;
        }
        
        return ans;
    }
    
    int rev(int num) {
        int result = 0;
        while (num > 0) {
            result = result * 10 + num % 10;
            num /= 10;
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
    public int countNicePairs(int[] nums) {
        int[] arr = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            arr[i] = nums[i] - rev(nums[i]);
        }
        
        Map<Integer, Integer> dic = new HashMap();
        int ans = 0;
        int MOD = (int) 1e9 + 7;
        for (int num : arr) {
            ans = (ans + dic.getOrDefault(num, 0)) % MOD;
            dic.put(num, dic.getOrDefault(num, 0) + 1);
        }
        
        return ans;
    }
    
    public int rev(int num) {
        int result = 0;
        while (num > 0) {
            result = result * 10 + num % 10;
            num /= 10;
        }
        
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        def rev(num):
            result = 0
            while num:
                result = result * 10 + num % 10
                num //= 10
            
            return result

        arr = []
        for i in range(len(nums)):
            arr.append(nums[i] - rev(nums[i]))
        
        dic = defaultdict(int)
        ans = 0
        MOD = 10 ** 9 + 7
        for num in arr:
            ans = (ans + dic[num]) % MOD
            dic[num] += 1
        
        return ans
```

</details>
