# 1464. Maximum Product of Two Elements in an Array

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/)  
`Array` `Sorting` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 1464 - Maximum Product of Two Elements in an Array](https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/)

## Problem

### Example 1

```text
Input: nums = [3,4,5,2]
Output: 12
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12.
```

### Example 2

```text
Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.
```

### Example 3

```text
Input: nums = [3,7]
Output: 12
```

## Constraints

- 2 <= nums.length <= 500
- 1 <= nums[i] <= 10^3

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1464. Maximum Product of Two Elements in an Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Sort | C++, Java, Python3 |
| Track Second Biggest | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                ans = max(ans, (nums[i] - 1) * (nums[j] - 1));
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
    public int maxProduct(int[] nums) {
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                ans = Math.max(ans, (nums[i] - 1) * (nums[j] - 1));
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
    def maxProduct(self, nums: List[int]) -> int:
        ans = 0
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                ans = max(ans, (nums[i] - 1) * (nums[j] - 1))
        
        return ans
```

</details>

<br>

## Approach 2: Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int x = nums[nums.size() - 1];
        int y = nums[nums.size() - 2];
        return (x - 1) * (y - 1);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxProduct(int[] nums) {
        Arrays.sort(nums);
        int x = nums[nums.length - 1];
        int y = nums[nums.length - 2];
        return (x - 1) * (y - 1);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        nums.sort()
        x = nums[-1]
        y = nums[-2]
        return (x - 1) * (y - 1)
```

</details>

<br>

## Approach 3: Track Second Biggest

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int biggest = 0;
        int secondBiggest = 0;
        for (int num : nums) {
            if (num > biggest) {
                secondBiggest = biggest;
                biggest = num;
            } else {
                secondBiggest = max(secondBiggest, num);
            }
        }
        
        return (biggest - 1) * (secondBiggest - 1);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxProduct(int[] nums) {
        int biggest = 0;
        int secondBiggest = 0;
        for (int num : nums) {
            if (num > biggest) {
                secondBiggest = biggest;
                biggest = num;
            } else {
                secondBiggest = Math.max(secondBiggest, num);
            }
        }
        
        return (biggest - 1) * (secondBiggest - 1);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        biggest = 0
        second_biggest = 0
        for num in nums:
            if num > biggest:
                second_biggest = biggest
                biggest = num
            else:
                second_biggest = max(second_biggest, num)
        
        return (biggest - 1) * (second_biggest - 1)
```

</details>
