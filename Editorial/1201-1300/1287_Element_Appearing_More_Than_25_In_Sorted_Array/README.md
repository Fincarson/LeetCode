# 1287. Element Appearing More Than 25% In Sorted Array

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/)  
`Array`

**Problem Link:** [LeetCode 1287 - Element Appearing More Than 25% In Sorted Array](https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/)

## Problem

Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

### Example 1

```text
Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6
```

### Example 2

```text
Input: arr = [1,1]
Output: 1
```

## Constraints

- 1 <= arr.length <= 104
- 0 <= arr[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1287. Element Appearing More Than 25% In Sorted Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Count With Hash Map | C++, Java, Python3 |
| Check the Element N/4 Ahead | C++, Java, Python3 |
| Binary Search | C++, Java, Python3 |

## Approach 1: Count With Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> counts;
        for (int num : arr) {
            counts[num]++;
        }
        
        int target = arr.size() / 4;
        for (auto& [key, value] : counts) {
            if (value > target) {
                return key;
            }
        }
        
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findSpecialInteger(int[] arr) {
        Map<Integer, Integer> counts = new HashMap();
        for (int num : arr) {
            counts.put(num, counts.getOrDefault(num, 0) + 1);
        }
        
        int target = arr.length / 4;
        for (int key : counts.keySet()) {
            if (counts.get(key) > target) {
                return key;
            }
        }
        
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        counts = defaultdict(int)
        for num in arr:
            counts[num] += 1
            
        target = len(arr) / 4
        for key, value in counts.items():
            if value > target:
                return key
            
        return -1
```

</details>

<br>

## Approach 2: Check the Element N/4 Ahead

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int size = arr.size() / 4;
        for (int i = 0; i < arr.size() - size; i++) {
            if (arr[i] == arr[i + size]) {
                return arr[i];
            }
        }
        
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findSpecialInteger(int[] arr) {
        int size = arr.length / 4;
        for (int i = 0; i < arr.length - size; i++) {
            if (arr[i] == arr[i + size]) {
                return arr[i];
            }
        }
        
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        size = len(arr) // 4
        for i in range(len(arr) - size):
            if arr[i] == arr[i + size]:
                return arr[i]
        
        return -1
```

</details>

<br>

## Approach 3: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        vector<int> candidates = {arr[n / 4], arr[n / 2], arr[3 * n / 4]};
        int target = n / 4;
        
        for (int candidate : candidates) {
            int left = lower_bound(arr.begin(), arr.end(), candidate) - arr.begin();
            int right = upper_bound(arr.begin(), arr.end(), candidate) - arr.begin() - 1;
            if (right - left + 1 > target) {
                return candidate;
            }
        }
        
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findSpecialInteger(int[] arr) {
        int n = arr.length;
        int[] candidates = {arr[n / 4], arr[n / 2], arr[3 * n / 4]};
        int target = n / 4;
        
        for (int candidate : candidates) {
            int left = lower_bound(arr, candidate);
            int right = upper_bound(arr, candidate) - 1;
            if (right - left + 1 > target) {
                return candidate;
            }
        }
        
        return -1;
    }
    
    public int upper_bound(int[] arr, int target) {
        int left = 0;
        int right = arr.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
    
    public int lower_bound(int[] arr, int target) {
        int left = 0;
        int right = arr.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        n = len(arr)
        candidates = [arr[n // 4], arr[n // 2], arr[3 * n // 4]]
        target = n / 4
        
        for candidate in candidates:
            left = bisect_left(arr, candidate)
            right = bisect_right(arr, candidate) - 1
            if right - left + 1 > target:
                return candidate
            
        return -1
```

</details>
