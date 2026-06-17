# 1460. Make Two Arrays Equal by Reversing Subarrays

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/)  
`Array` `Hash Table` `Sorting`

**Problem Link:** [LeetCode 1460 - Make Two Arrays Equal by Reversing Subarrays](https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/)

## Problem

You are given two integer arrays of equal length target and arr. In one step, you can select any non-empty subarray of arr and reverse it. You are allowed to make any number of steps.

Return true if you can make arr equal to target or false otherwise.

### Example 1

```text
Input: target = [1,2,3,4], arr = [2,4,1,3]
Output: true
Explanation: You can follow the next steps to convert arr to target:
1- Reverse subarray [2,4,1], arr becomes [1,4,2,3]
2- Reverse subarray [4,2], arr becomes [1,2,4,3]
3- Reverse subarray [4,3], arr becomes [1,2,3,4]
There are multiple ways to convert arr to target, this is not the only way to do so.
```

### Example 2

```text
Input: target = [7], arr = [7]
Output: true
Explanation: arr is equal to target without any reverses.
```

### Example 3

```text
Input: target = [3,7,9], arr = [3,7,11]
Output: false
Explanation: arr does not have value 9 and it can never be converted to target.
```

## Constraints

- target.length == arr.length
- 1 <= target.length <= 1000
- 1 <= target[i] <= 1000
- 1 <= arr[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1460. Make Two Arrays Equal by Reversing Subarrays

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting | C++, Java, Python3 |
| Frequency Counting With 2 Dictionaries | C++, Java, Python3 |

## Approach 1: Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(arr.begin(), arr.end());
        sort(target.begin(), target.end());
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != target[i]) return false;
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canBeEqual(int[] target, int[] arr) {
        Arrays.sort(arr);
        Arrays.sort(target);
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != target[i]) return false;
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        arr.sort()
        target.sort()
        for i in range(len(arr)):
            if arr[i] != target[i]:
                return False
        return True
```

</details>

<br>

## Approach 2: Frequency Counting With 2 Dictionaries

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // Dictionary to maintain frequency count for arr
        unordered_map<int, int> arrFreq;
        for (int num : arr) {
            arrFreq[num]++;
        }

        // Dictionary to maintain frequency count for target
        unordered_map<int, int> targetFreq;
        for (int num : target) {
            targetFreq[num]++;
        }

        // Number of distinct elements of the 2 arrays are not equal
        if (arrFreq.size() != targetFreq.size()) {
            return false;
        }

        for (auto it : arrFreq) {
            // Frequency for num differs
            if (targetFreq[it.first] != it.second) {
                return false;
            }
        }

        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canBeEqual(int[] target, int[] arr) {
        // Dictionary to maintain frequency count for arr
        Map<Integer, Integer> arrFreq = new HashMap<>();
        for (int num : arr) {
            arrFreq.put(num, arrFreq.getOrDefault(num, 0) + 1);
        }

        // Dictionary to maintain frequency count for target
        Map<Integer, Integer> targetFreq = new HashMap<>();
        for (int num : target) {
            targetFreq.put(num, targetFreq.getOrDefault(num, 0) + 1);
        }

        // Number of distinct elements of the 2 arrays are not equal
        if (arrFreq.keySet().size() != targetFreq.keySet().size()) {
            return false;
        }

        for (int num : arrFreq.keySet()) {
            // Frequency for num differs
            if (targetFreq.getOrDefault(num, 0) != arrFreq.get(num)) {
                return false;
            }
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        # Dictionary to maintain frequency count for arr
        arrFreq = {}
        for num in arr:
            if num not in arrFreq:
                arrFreq[num] = 1
            else:
                arrFreq[num] += 1

        # Dictionary to maintain frequency count for arr
        targetFreq = {}
        for num in target:
            if num not in targetFreq:
                targetFreq[num] = 1
            else:
                targetFreq[num] += 1

        # Number of distinct elements of the 2 arrays are not equal
        if len(arrFreq) != len(targetFreq):
            return False

        for key in arrFreq:
            # Frequency for num differs
            if arrFreq[key] != targetFreq.get(key, 0):
                return False

        return True
```

</details>
