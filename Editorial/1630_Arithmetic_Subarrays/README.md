# 1630. Arithmetic Subarrays

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/arithmetic-subarrays/)  
`Array` `Hash Table` `Sorting`

**Problem Link:** [LeetCode 1630 - Arithmetic Subarrays](https://leetcode.com/problems/arithmetic-subarrays/)

## Problem

A sequence of numbers is called arithmetic if it consists of at least two elements, and the difference between every two consecutive elements is the same. More formally, a sequence s is arithmetic if and only if s[i+1] - s[i] == s[1] - s[0] for all valid i.

For example, these are arithmetic sequences:

```text
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
```

The following sequence is not arithmetic:

```text
1, 1, 2, 5, 7
```

You are given an array of n integers, nums, and two arrays of m integers each, l and r, representing the m range queries, where the ith query is the range [l[i], r[i]]. All the arrays are 0-indexed.

Return a list of boolean elements answer, where answer[i] is true if the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]] can be rearranged to form an arithmetic sequence, and false otherwise.

### Example 1

```text
Input: nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
Output: [true,false,true]
Explanation:
In the 0th query, the subarray is [4,6,5]. This can be rearranged as [6,5,4], which is an arithmetic sequence.
In the 1st query, the subarray is [4,6,5,9]. This cannot be rearranged as an arithmetic sequence.
In the 2nd query, the subarray is [5,9,3,7]. This can be rearranged as [3,5,7,9], which is an arithmetic sequence.
```

### Example 2

```text
Input: nums = [-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10], l = [0,1,6,4,8,7], r = [4,4,9,7,9,10]
Output: [false,true,false,false,true,true]
```

## Constraints

- n == nums.length
- m == l.length
- m == r.length
- 2 <= n <= 500
- 1 <= m <= 500
- 0 <= l[i] < r[i] < n
- -105 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Can Make Arithmetic Progression From Sequence](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1630. Arithmetic Subarrays

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort and Check | C++, Java, Python3 |
| No Sorting | C++, Java, Python3 |

## Approach 1: Sort and Check

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool check(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != diff) {
                return false;
            }
        }
        
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for (int i = 0; i < l.size(); i++) {
            vector<int> arr(begin(nums) + l[i], begin(nums) + r[i] + 1);
            ans.push_back(check(arr));
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
    public Boolean check(int[] arr) {
        Arrays.sort(arr);
        int diff = arr[1] - arr[0];
        
        for (int i = 2; i < arr.length; i++) {
            if (arr[i] - arr[i - 1] != diff) {
                return false;
            }
        }
        
        return true;
    }
    
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<Boolean> ans = new ArrayList();
        for (int i = 0; i < l.length; i++) {
            int[] arr = new int[r[i] - l[i] + 1];
            for (int j = 0; j < arr.length; j++) {
                arr[j] = nums[l[i] + j];
            }
            
            ans.add(check(arr));
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
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        def check(arr):
            arr.sort()
            diff = arr[1] - arr[0]
            
            for i in range(2, len(arr)):
                if arr[i] - arr[i - 1] != diff:
                    return False
                
            return True
        
        ans = []
        for i in range(len(l)):
            arr = nums[l[i] : r[i] + 1]
            ans.append(check(arr))
        
        return ans
```

</details>

<br>

## Approach 2: No Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool check(vector<int>& arr) {
        int minElement = INT_MAX;
        int maxElement = INT_MIN;
        unordered_set<int> arrSet;
        
        for (int num : arr) {
            minElement = min(minElement, num);
            maxElement = max(maxElement, num);
            arrSet.insert(num);
        }
        
        if ((maxElement - minElement) % (arr.size() - 1) != 0) {
            return false;
        }
        
        int diff = (maxElement - minElement) / (arr.size() - 1);
        int curr = minElement + diff;
        
        while (curr < maxElement) {
            if (arrSet.find(curr) == arrSet.end()) {
                return false;
            }
            
            curr += diff;
        }
        
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for (int i = 0; i < l.size(); i++) {
            vector<int> arr(begin(nums) + l[i], begin(nums) + r[i] + 1);
            ans.push_back(check(arr));
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
    public Boolean check(int[] arr) {
        int minElement = Integer.MAX_VALUE;
        int maxElement = Integer.MIN_VALUE;
        Set<Integer> arrSet = new HashSet();
        
        for (int num : arr) {
            minElement = Math.min(minElement, num);
            maxElement = Math.max(maxElement, num);
            arrSet.add(num);
        }
        
        if ((maxElement - minElement) % (arr.length - 1) != 0) {
            return false;
        }
        
        int diff = (maxElement - minElement) / (arr.length - 1);
        int curr = minElement + diff;
        
        while (curr < maxElement) {
            if (!arrSet.contains(curr)) {
                return false;
            }
            
            curr += diff;
        }
        
        return true;
    }
    
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<Boolean> ans = new ArrayList();
        for (int i = 0; i < l.length; i++) {
            int[] arr = new int[r[i] - l[i] + 1];
            for (int j = 0; j < arr.length; j++) {
                arr[j] = nums[l[i] + j];
            }
            
            ans.add(check(arr));
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
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        def check(arr):
            min_element = min(arr)
            max_element = max(arr)

            if (max_element - min_element) % (len(arr) - 1) != 0:
                return False

            diff = (max_element - min_element) / (len(arr) - 1)
            
            arr_set = set(arr)
            curr = min_element + diff
            while curr < max_element:
                if curr not in arr_set:
                    return False
                
                curr += diff
            
            return True

        ans = []
        for i in range(len(l)):
            arr = nums[l[i] : r[i] + 1]
            ans.append(check(arr))
        
        return ans
```

</details>
