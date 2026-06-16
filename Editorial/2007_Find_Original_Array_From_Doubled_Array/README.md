# 2007. Find Original Array From Doubled Array

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-original-array-from-doubled-array/)  
`Array` `Hash Table` `Greedy` `Sorting`

**Problem Link:** [LeetCode 2007 - Find Original Array From Doubled Array](https://leetcode.com/problems/find-original-array-from-doubled-array/)

## Problem

An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.

Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.

### Example 1

```text
Input: changed = [1,3,4,2,6,8]
Output: [1,3,4]
Explanation: One possible original array could be [1,3,4]:
- Twice the value of 1 is 1 * 2 = 2.
- Twice the value of 3 is 3 * 2 = 6.
- Twice the value of 4 is 4 * 2 = 8.
Other original arrays could be [4,3,1] or [3,1,4].
```

### Example 2

```text
Input: changed = [6,3,0,1]
Output: []
Explanation: changed is not a doubled array.
```

### Example 3

```text
Input: changed = [1]
Output: []
Explanation: changed is not a doubled array.
```

## Constraints

- 1 <= changed.length <= 105
- 0 <= changed[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Array of Doubled Pairs](https://leetcode.com/problems/array-of-doubled-pairs/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Recover the Original Array](https://leetcode.com/problems/recover-the-original-array/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2007. Find Original Array From Doubled Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort + HashMap | C++, Java |
| Counting Sort | C++, Java |

## Approach 1: Sort + HashMap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        // It can't be doubled array, if the size is odd
        if (changed.size() % 2) {
            return {};
        }
        
        // Sort in ascending order
        sort(changed.begin(), changed.end());
        unordered_map<int, int> freq;
        // Store the frequency in the map
        for (int num : changed) {
            freq[num]++;
        }
        
        vector<int> original;
        for (int num : changed) {
            // If element exists
            if (freq[num]) {
				freq[num]--;
                int twiceNum = num * 2;
                if (freq[twiceNum] > 0) {
                    // Pair up the elements, decrement the count
                    freq[twiceNum]--;
                    // Add the original number to answer
                    original.push_back(num);
                } else {
                    return {};
                }
            }
        }
        
        return original;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] findOriginalArray(int[] changed) {
        // It can't be doubled array, if the size is odd
        if (changed.length % 2 == 1) {
            return new int[0];
        }
        
        // Sort in ascending order
        Arrays.sort(changed);
        Map<Integer, Integer> freq = new HashMap<>();
        // Store the frequency in the map
        for (int num : changed) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }
        
        int[] original= new int[changed.length / 2];
        int index = 0;
        for (int num : changed) {
            // If element exists
            if (freq.get(num) > 0) {
				freq.put(num, freq.get(num) - 1);
                int twiceNum = num * 2;
                if (freq.containsKey(twiceNum) && freq.get(twiceNum) > 0) {
                    // Pair up the elements, decrement the count
                    freq.put(twiceNum, freq.get(twiceNum) - 1);
                    // Add the original number to answer
                    original[index++] = num;
                } else {
                    return new int[0];
                }
            }
        }
        
        return original;
    }
}
```

</details>

<br>

## Approach 2: Counting Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        // It can't be doubled array, if the size is odd
        if (changed.size() % 2) {
            return {};
        }
        
        int maxNum = 0;
        // Find the max element in the array
        for (int num : changed) {
            maxNum = max(maxNum, num);
        }
        
        vector<int> freq(2 * maxNum + 1, 0);
        // Store the frequency in the map
        for (int num : changed) {
            freq[num]++;
        }
        
        vector<int> original;
        for (int num = 0; num <= maxNum; num++) {
            // If element exists
            if (freq[num]) {
                freq[num]--;
                
                int twiceNum = num * 2;
                if (freq[twiceNum] > 0) {
                    // Pair up the elements, decrement the count
                    freq[twiceNum]--;
                    // Add the original number to answer
                    original.push_back(num);
                    num--;
                } else {
                    return {};
                }
            }
        }
        
        return original;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] findOriginalArray(int[] changed) {
        // It can't be doubled array, if the size is odd
        if (changed.length % 2 == 1) {
            return new int[0];
        }
        
        int maxNum = 0;
        // Find the max element in the array
        for (int num : changed) {
            maxNum = Math.max(maxNum, num);
        }
        
        int[] freq = new int[2 * maxNum + 1];
        // Store the frequency in the map
        for (int num : changed) {
            freq[num]++;
        }
        
        int[] original = new int[changed.length / 2];
        int index = 0;
        for (int num = 0; num <= maxNum; num++) {
            // If element exists
            if (freq[num] > 0) {
                freq[num]--;
                
                int twiceNum = num * 2;
                if (freq[twiceNum] > 0) {
                    // Pair up the elements, decrement the count
                    freq[twiceNum]--;
                    // Add the original number to answer
                    original[index++] = num;
                    num--;
                } else {
                    return new int[0];
                }
            }
        }
        
        return original;
    }
};
```

</details>
