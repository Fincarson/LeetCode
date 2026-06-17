# 1846. Maximum Element After Decreasing and Rearranging

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/)  
`Array` `Greedy` `Sorting`

**Problem Link:** [LeetCode 1846 - Maximum Element After Decreasing and Rearranging](https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/)

## Problem

You are given an array of positive integers arr. Perform some operations (possibly none) on arr so that it satisfies these conditions:

- The value of the first element in arr must be 1.
- The absolute difference between any 2 adjacent elements must be less than or equal to 1. In other words, abs(arr[i] - arr[i - 1]) <= 1 for each i where 1 <= i < arr.length (0-indexed). abs(x) is the absolute value of x.

There are 2 types of operations that you can perform any number of times:

- Decrease the value of any element of arr to a smaller positive integer.
- Rearrange the elements of arr to be in any order.

Return the maximum possible value of an element in arr after performing the operations to satisfy the conditions.

### Example 1

```text
Input: arr = [2,2,1,2,1]
Output: 2
Explanation:
We can satisfy the conditions by rearranging arr so it becomes [1,2,2,2,1].
The largest element in arr is 2.
```

### Example 2

```text
Input: arr = [100,1,1000]
Output: 3
Explanation:
One possible way to satisfy the conditions is by doing the following:
1. Rearrange arr so it becomes [1,100,1000].
2. Decrease the value of the second element to 2.
3. Decrease the value of the third element to 3.
Now arr = [1,2,3], which satisfies the conditions.
The largest element in arr is 3.
```

### Example 3

```text
Input: arr = [1,2,3,4,5]
Output: 5
Explanation: The array already satisfies the conditions, and the largest element is 5.
```

## Constraints

- 1 <= arr.length <= 105
- 1 <= arr[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1846. Maximum Element After Decreasing and Rearranging

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy | C++, Java, Python3 |
| No Sort | C++, Java, Python3 |

## Approach 1: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 1;
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] >= ans + 1) {
                ans++;
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
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        Arrays.sort(arr);
        int ans = 1;
        
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] >= ans + 1) {
                ans++;
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
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        arr.sort()
        ans = 1
        for i in range(1, len(arr)):
            if arr[i] >= ans + 1:
                ans += 1

        return ans
```

</details>

<br>

## Approach 2: No Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> counts = vector(n + 1, 0);
        
        for (int num : arr) {
            counts[min(num, n)]++;
        }
        
        int ans = 1;
        for (int num = 2; num <= n; num++) {
            ans = min(ans + counts[num], num);
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
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        int n = arr.length;
        int[] counts = new int[n + 1];
        
        for (int num : arr) {
            counts[Math.min(num, n)]++;
        }
        
        int ans = 1;
        for (int num = 2; num <= n; num++) {
            ans = Math.min(ans + counts[num], num);
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
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        n = len(arr)
        counts = [0] * (n + 1)
        
        for num in arr:
            counts[min(num, n)] += 1
        
        ans = 1
        for num in range(2, n + 1):
            ans = min(ans + counts[num], num)
    
        return ans
```

</details>
