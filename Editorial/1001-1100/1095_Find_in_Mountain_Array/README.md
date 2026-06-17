# 1095. Find in Mountain Array

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/find-in-mountain-array/)  
`Array` `Binary Search` `Interactive`

**Problem Link:** [LeetCode 1095 - Find in Mountain Array](https://leetcode.com/problems/find-in-mountain-array/)

## Problem

(This problem is an interactive problem.)

You may recall that an array arr is a mountain array if and only if:

- arr.length >= 3
- There exists some i with 0 < i < arr.length - 1 such that:

		arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
		arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

- MountainArray.get(k) returns the element of the array at index k (0-indexed).
- MountainArray.length() returns the length of the array.

Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

### Example 1

```text
Input: mountainArr = [1,2,3,4,5,3,1], target = 3
Output: 2
Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.
```

### Example 2

```text
Input: mountainArr = [0,1,2,4,2,1], target = 3
Output: -1
Explanation: 3 does not exist in the array, so we return -1.
```

## Constraints

- 3 <= mountainArr.length() <= 104
- 0 <= target <= 109
- 0 <= mountainArr.get(index) <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Number of Removals to Make Mountain Array](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Find Good Days to Rob the Bank](https://leetcode.com/problems/find-good-days-to-rob-the-bank/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find Indices of Stable Mountains](https://leetcode.com/problems/find-indices-of-stable-mountains/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1095. Find in Mountain Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C, C++, Java, JavaScript, Python3 |
| Minimizing `get` Calls with Early Stopping and Caching | C++, Java, Python3 |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int findInMountainArray(int target, MountainArray *mountainArr) {
    // Save the length of the mountain array
    int size = length(mountainArr);

    // 1. Find the index of the peak element
    int low = 1;
    int high = size - 2;
    while (low != high) {
        int testIndex = (low + high) / 2;
        if (get(mountainArr, testIndex) < get(mountainArr, testIndex + 1)) {
            low = testIndex + 1;
        } else {
            high = testIndex;
        }
    }

    int peakIndex = low;

    // 2. Search in the strictly increasing part of the array
    low = 0;
    high = peakIndex;
    while (low != high) {
        int testIndex = (low + high) / 2;
        if (get(mountainArr, testIndex) < target) {
            low = testIndex + 1;
        } else {
            high = testIndex;
        }
    } 
    // Check if the target is present in the strictly increasing part
    if (get(mountainArr, low) == target) {
        return low;
    }

    // 3. Otherwise, search in the strictly decreasing part
    low = peakIndex + 1;
    high = size - 1;
    while (low != high) {
        int testIndex = (low + high) / 2;
        if (get(mountainArr, testIndex) > target) {
            low = testIndex + 1;
        } else {
            high = testIndex;
        }
    }
    // Check if the target is present in the strictly decreasing part
    if (get(mountainArr, low) == target) {
        return low;
    }

    // Target is not present in the mountain array
    return -1;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // Save the length of the mountain array
        int length = mountainArr.length();

        // 1. Find the index of the peak element
        int low = 1;
        int high = length - 2;
        while (low != high) {
            int testIndex = (low + high) / 2;
            if (mountainArr.get(testIndex) < mountainArr.get(testIndex + 1)) {
                low = testIndex + 1;
            } else {
                high = testIndex;
            }
        }
        int peakIndex = low;

        // 2. Search in the strictly increasing part of the array
        low = 0;
        high = peakIndex;
        while (low != high) {
            int testIndex = (low + high) / 2;
            if (mountainArr.get(testIndex) < target) {
                low = testIndex + 1;
            } else {
                high = testIndex;
            }
        }
        // Check if the target is present in the strictly increasing part
        if (mountainArr.get(low) == target) {
            return low;
        }

        // 3. Otherwise, search in the strictly decreasing part
        low = peakIndex + 1;
        high = length - 1;
        while (low != high) {
            int testIndex = (low + high) / 2;
            if (mountainArr.get(testIndex) > target) {
                low = testIndex + 1;
            } else {
                high = testIndex;
            }
        }
        // Check if the target is present in the strictly decreasing part
        if (mountainArr.get(low) == target) {
            return low;
        }

        // Target is not present in the mountain array
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        // Save the length of the mountain array
        int length = mountainArr.length();

        // 1. Find the index of the peak element
        int low = 1;
        int high = length - 2;
        while (low != high) {
            int testIndex = (low + high) / 2;
            if (mountainArr.get(testIndex) < mountainArr.get(testIndex + 1)) {
                low = testIndex + 1;
            } else {
                high = testIndex;
            }
        }
        int peakIndex = low;

        // 2. Search in the strictly increasing part of the array
        low = 0;
        high = peakIndex;
        while (low != high) {
            int testIndex = (low + high) / 2;
            if (mountainArr.get(testIndex) < target) {
                low = testIndex + 1;
            } else {
                high = testIndex;
            }
        }
        // Check if the target is present in the strictly increasing part
        if (mountainArr.get(low) == target) {
            return low;
        }

        // 3. Otherwise, search in the strictly decreasing part
        low = peakIndex + 1;
        high = length - 1;
        while (low != high) {
            int testIndex = (low + high) / 2;
            if (mountainArr.get(testIndex) > target) {
                low = testIndex + 1;
            } else {
                high = testIndex;
            }
        }
        // Check if the target is present in the strictly decreasing part
        if (mountainArr.get(low) == target) {
            return low;
        }

        // Target is not present in the mountain array
        return -1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var findInMountainArray = function(target, mountainArr) {
    // Save the length of the mountain array
    const length = mountainArr.length();

    // 1. Find the index of the peak element
    let low = 1;
    let high = length - 2;
    while (low !== high) {
        const testIndex = (low + high) / 2;
        if (mountainArr.get(testIndex) < mountainArr.get(testIndex + 1)) {
            low = testIndex + 1;
        } else {
            high = testIndex;
        }
    }
    const peakIndex = low;

    // 2. Search in the strictly increasing part of the array
    low = 0;
    high = peakIndex;
    while (low !== high) {
        const testIndex = (low + high) / 2;
        if (mountainArr.get(testIndex) < target) {
            low = testIndex + 1;
        } else {
            high = testIndex;
        }
    }
    // Check if the target is present in the strictly increasing part
    if (mountainArr.get(low) === target) {
        return low;
    }

    // 3. Otherwise, search in the strictly decreasing part
    low = peakIndex + 1;
    high = length - 1;
    while (low !== high) {
        const testIndex = (low + high) / 2;
        if (mountainArr.get(testIndex) > target) {
            low = testIndex + 1;
        } else {
            high = testIndex;
        }
    }
    // Check if the target is present in the strictly decreasing part
    if (mountainArr.get(low) === target) {
        return low;
    }

    // Target is not present in the mountain array
    return -1;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        # Save the length of the mountain array
        length = mountain_arr.length()

        # 1. Find the index of the peak element
        low = 1
        high = length - 2
        while low != high:
            test_index = (low + high) // 2
            if mountain_arr.get(test_index) < mountain_arr.get(test_index + 1):
                low = test_index + 1
            else:
                high = test_index
        peak_index = low

        # 2. Search in the strictly increasing part of the array
        low = 0
        high = peak_index
        while low != high:
            test_index = (low + high) // 2
            if mountain_arr.get(test_index) < target:
                low = test_index + 1
            else:
                high = test_index    
        # Check if the target is present in the strictly increasing part
        if mountain_arr.get(low) == target:
            return low
        
        # 3. Otherwise, search in the strictly decreasing part
        low = peak_index + 1
        high = length - 1
        while low != high:
            test_index = (low + high) // 2
            if mountain_arr.get(test_index) > target:
                low = test_index + 1
            else:
                high = test_index
        # Check if the target is present in the strictly decreasing part
        if mountain_arr.get(low) == target:
            return low
        
        # Target is not present in the mountain array
        return -1
```

</details>

<br>

## Approach 2: Minimizing `get` Calls with Early Stopping and Caching

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // Save the length of the mountain array
        int length = mountainArr.length();

        // Initialize the cache
        unordered_map<int, int> cache;

        // 1. Find the index of the peak element
        int low = 1;
        int high = length - 2;
        while (low != high) {
            int testIndex = (low + high) >> 1;

            int curr;
            if (cache.find(testIndex) != cache.end()) {
                curr = cache[testIndex];
            } else {
                curr = mountainArr.get(testIndex);
                cache[testIndex] = curr;
            }

            int next;
            if (cache.find(testIndex + 1) != cache.end()) {
                next = cache[testIndex + 1];
            } else {
                next = mountainArr.get(testIndex + 1);
                cache[testIndex + 1] = next;
            }

            if (curr < next) {
                if (curr == target) {
                    return testIndex;
                }
                if (next == target) {
                    return testIndex + 1;
                }
                low = testIndex + 1;
            } else {
                high = testIndex;
            }
        }

        int peakIndex = low;

        // 2. Search in the strictly increasing part of the array
        // If found, will be returned in the loop itself.
        low = 0;
        high = peakIndex;
        while (low <= high) {
            int testIndex = (low + high) >> 1;

            int curr;
            if (cache.find(testIndex) != cache.end()) {
                curr = cache[testIndex];
            } else {
                curr = mountainArr.get(testIndex);
            }
                
            if (curr == target) {
                return testIndex;
            } else if (curr < target) {
                low = testIndex + 1;
            } else {
                high = testIndex - 1;
            }
        }

        // 3. Search in the strictly decreasing part of the array
        // If found, will be returned in the loop itself.
        low = peakIndex + 1;
        high = length - 1;
        while (low <= high) {
            int testIndex = (low + high) >> 1;

            int curr;
            if (cache.find(testIndex) != cache.end()) {
                curr = cache[testIndex];
            } else {
                curr = mountainArr.get(testIndex);
            }
                
            if (curr == target) {
                return testIndex;
            } else if (curr > target) {
                low = testIndex + 1;
            } else {
                high = testIndex - 1;
            }
        }

        // Target is not present in the mountain array
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        // Save the length of the mountain array
        int length = mountainArr.length();

        // Initialize the cache
        Map<Integer, Integer> cache = new HashMap<>();

        // 1. Find the index of the peak element
        int low = 1;
        int high = length - 2;
        while (low != high) {
            int testIndex = (low + high) >> 1;

            int curr;
            if (cache.containsKey(testIndex)) {
                curr = cache.get(testIndex);
            } else {
                curr = mountainArr.get(testIndex);
                cache.put(testIndex, curr);
            }

            int next;
            if (cache.containsKey(testIndex + 1)) {
                next = cache.get(testIndex + 1);
            } else {
                next = mountainArr.get(testIndex + 1);
                cache.put(testIndex + 1, next);
            }

            if (curr < next) {
                if (curr == target) {
                    return testIndex;
                }
                if (next == target) {
                    return testIndex + 1;
                }
                low = testIndex + 1;
            } else {
                high = testIndex;
            }
        }

        int peakIndex = low;

        // 2. Search in the strictly increasing part of the array
        // If found, will be returned in the loop itself.
        low = 0;
        high = peakIndex;
        while (low <= high) {
            int testIndex = (low + high) >> 1;

            int curr;
            if (cache.containsKey(testIndex)) {
                curr = cache.get(testIndex);
            } else {
                curr = mountainArr.get(testIndex);
            }
                
            if (curr == target) {
                return testIndex;
            } else if (curr < target) {
                low = testIndex + 1;
            } else {
                high = testIndex - 1;
            }
        }

        // 3. Search in the strictly decreasing part of the array
        // If found, will be returned in the loop itself.
        low = peakIndex + 1;
        high = length - 1;
        while (low <= high) {
            int testIndex = (low + high) >> 1;

            int curr;
            if (cache.containsKey(testIndex)) {
                curr = cache.get(testIndex);
            } else {
                curr = mountainArr.get(testIndex);
            }
                
            if (curr == target) {
                return testIndex;
            } else if (curr > target) {
                low = testIndex + 1;
            } else {
                high = testIndex - 1;
            }
        }

        // Target is not present in the mountain array
        return -1;        
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        # Save the length of the mountain array
        length = mountain_arr.length()

        # Initialize the cache
        cache = {}

        # 1. Find the index of the peak element
        low = 1
        high = length - 2
        while low != high:
            test_index = (low + high) >> 1

            if test_index in cache:
                curr = cache[test_index]
            else:
                curr = mountain_arr.get(test_index)
                cache[test_index] = curr
            
            if test_index + 1 in cache:
                next = cache[test_index + 1]
            else:
                next = mountain_arr.get(test_index + 1)
                cache[test_index + 1] = next
            
            if curr < next:
                if curr == target:
                    return test_index
                if next == target:
                    return test_index + 1
                low = test_index + 1
            else:
                high = test_index
        
        peak_index = low

        # 2. Search in the strictly increasing part of the array
        # If found, will be returned in the loop itself.
        low = 0
        high = peak_index
        while low <= high:
            test_index = (low + high) >> 1

            if test_index in cache:
                curr = cache[test_index]
            else:
                curr = mountain_arr.get(test_index)
                
            if curr == target:
                return test_index
            elif curr < target:
                low = test_index + 1
            else:
                high = test_index - 1
        
        # 3. Search in the strictly decreasing part of the array
        # If found, will be returned in the loop itself.
        low = peak_index + 1
        high = length - 1
        while low <= high:
            test_index = (low + high) >> 1

            if test_index in cache:
                curr = cache[test_index]
            else:
                curr = mountain_arr.get(test_index)
                
            if curr == target:
                return test_index
            elif curr > target:
                low = test_index + 1
            else:
                high = test_index - 1
        
        # Target is not present in the mountain array
        return -1
```

</details>
