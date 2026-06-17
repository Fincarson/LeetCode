# 1502. Can Make Arithmetic Progression From Sequence

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/)  
`Array` `Sorting`

**Problem Link:** [LeetCode 1502 - Can Make Arithmetic Progression From Sequence](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/)

## Problem

A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.

### Example 1

```text
Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.
```

### Example 2

```text
Input: arr = [1,2,4]
Output: false
Explanation: There is no way to reorder the elements to obtain an arithmetic progression.
```

## Constraints

- 2 <= arr.length <= 1000
- -106 <= arr[i] <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Arithmetic Subarrays](https://leetcode.com/problems/arithmetic-subarrays/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1502. Can Make Arithmetic Progression From Sequence

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort | C++, Java, Python3 |
| Set | C++, Java, Python3 |
| In-place Modification | C++, Java, Python3 |

## Approach 1: Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        
        for (int i = 2; i < arr.size(); ++i) {
            if (arr[i] - arr[i - 1] != diff) {
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
    public boolean canMakeArithmeticProgression(int[] arr) {
        Arrays.sort(arr);
        int diff = arr[1] - arr[0];
        
        for (int i = 2; i < arr.length; ++i) {
            if (arr[i] - arr[i - 1] != diff) {
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
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr.sort()
        diff = arr[1] - arr[0]
        for i in range(2, len(arr)):
            if arr[i] - arr[i - 1] != diff:
                return False
        return True
```

</details>

<br>

## Approach 2: Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int minValue = *min_element(arr.begin(), arr.end());
        int maxValue = *max_element(arr.begin(), arr.end());
        int n = arr.size();
        
        if (maxValue - minValue == 0) {
            return true;
        }
        
        if ((maxValue - minValue) % (n - 1) != 0) {
            return false;
        }
        
        int diff = (maxValue - minValue) / (n - 1);
        unordered_set<int> numberSet;
        
        for (int i = 0; i < n; i++) {
            if ((arr[i] - minValue) % diff != 0) {
                return false;
            }
            numberSet.insert(arr[i]);
        }
        
        return numberSet.size() == n;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean canMakeArithmeticProgression(int[] arr) {
        int minValue = Arrays.stream(arr).min().getAsInt();
        int maxValue = Arrays.stream(arr).max().getAsInt();
        int n = arr.length;
        
        if (maxValue - minValue == 0) {
            return true;
        }
        
        if ((maxValue - minValue) % (n - 1) != 0) {
            return false;
        }
        
        int diff = (maxValue - minValue) / (n - 1);
        Set<Integer> numberSet = new HashSet<>();
        
        for (int i = 0; i < n; i++) {
            if ((arr[i] - minValue) % diff != 0) {
                return false;
            }
            numberSet.add(arr[i]);
        }
        
        return numberSet.size() == n;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        min_value, max_value = min(arr), max(arr)
        n = len(arr)
        
        if max_value - min_value == 0:
            return True
        if (max_value - min_value) % (n - 1):

            return False
        
        diff = (max_value - min_value) // (n - 1)
        number_set = set()
        
        for a in arr:
            if (a - min_value) % diff:
                return False
            number_set.add(a)
        
        return len(number_set) == n
```

</details>

<br>

## Approach 3: In-place Modification

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canMakeArithmeticProgression(std::vector<int>& arr) {
        int minValue = *std::min_element(arr.begin(), arr.end());
        int maxValue = *std::max_element(arr.begin(), arr.end());
        int n = arr.size();
        
        if ((maxValue - minValue) % (n - 1) != 0) {
            return false;
        }
        
        int diff = (maxValue - minValue) / (n - 1);
        int i = 0;
        
        while (i < n) {
            // If arr[i] is at the correct index, move on.
            if (arr[i] == minValue + i * diff) {
                i += 1;
                
            // If arr[i] doesn't belong to this arithmetic sequence, return false.
            } else if ((arr[i] - minValue) % diff != 0) {
                return false;
                
            // Otherwise, find the index j to which arr[i] belongs, swap arr[j] with arr[i].
            } else {
                int j = (arr[i] - minValue) / diff;
                
                // If we find duplicated elements, return False.
                if (arr[i] == arr[j]) {
                    return false;
                }
                
                // Swap arr[i] with arr[j].
                swap(arr[i], arr[j]);
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
    public boolean canMakeArithmeticProgression(int[] arr) {
        int minValue = Arrays.stream(arr).min().getAsInt();
        int maxValue = Arrays.stream(arr).max().getAsInt();
        int n = arr.length;
        if ((maxValue - minValue) % (n - 1) != 0) {
            return false;
        }
        
        int diff = (maxValue - minValue) / (n - 1);
        int i = 0;
        
        while (i < n) {
            // If arr[i] is at the correct index, move on.
            if (arr[i] == minValue + i * diff) {
                i += 1;
                
            // If arr[i] doesn't belong to this arithmetic sequence, return false.
            } else if ((arr[i] - minValue) % diff != 0) {
                return false;
                
            // Otherwise, find the index j to which arr[i] belongs, swap arr[j] with arr[i].
            } else {
                int j = (arr[i] - minValue) / diff;
                
                // If we find duplicated elements, return False.
                if (arr[i] == arr[j]) {
                    return false;
                }
                
                // Swap arr[i] with arr[j].
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
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
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        min_value, max_value = min(arr), max(arr)
        n = len(arr)
        if (max_value - min_value) % (n - 1):
            return False
        
        diff = (max_value - min_value) // (n - 1)
        i = 0
        
        while i < n:
            # If arr[i] is at the correct index, move on.
            if arr[i] == min_value + i * diff:
                i += 1
                
            # If arr[i] doesn't belong to this arithmetic sequence, return False.
            elif (arr[i] - min_value) % diff:
                return False
            
            # Otherwise, find the index j to which arr[i] belongs, swap arr[j] with arr[i].
            else:
                j = (arr[i] - min_value) // diff
                
                # If we find duplicated elements, return False.
                if arr[i] == arr[j]:
                    return False
                
                # Swap arr[i] with arr[j].
                arr[i], arr[j] = arr[j], arr[i]
        
        return True
```

</details>
