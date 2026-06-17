# 1207. Unique Number of Occurrences

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/unique-number-of-occurrences/)  
`Array` `Hash Table`

**Problem Link:** [LeetCode 1207 - Unique Number of Occurrences](https://leetcode.com/problems/unique-number-of-occurrences/)

## Problem

Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

### Example 1

```text
Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
```

### Example 2

```text
Input: arr = [1,2]
Output: false
```

### Example 3

```text
Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
```

## Constraints

- 1 <= arr.length <= 1000
- -1000 <= arr[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1207. Unique Number of Occurrences

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Counting Sort | C++, Java |
| HashMap & HashSet | C++, Java |

## Approach 1: Counting Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Constant to make elements non-negative.
    static constexpr int K = 1000;
    
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> freq(2 * K  + 1);
    
        // Store the frequency of elements in the unordered map.
        for (int num : arr) {
            freq[num + K]++;
        }
        
        // Sort the frequency count.
        sort(freq.begin(), freq.end());
        
        // If the adjacent freq count is equal, then the freq count isn't unique.
        for (int i = 0; i < 2 * K; i++) {
            if (freq[i] && freq[i] == freq[i + 1]) {
                return false;
            }
        }
        
        // If all the elements are traversed, it implies frequency counts are unique.
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Constant to make elements non-negative.
    final int K = 1000;
    
    public boolean uniqueOccurrences(int[] arr) {
        int freq[] = new int[2 * K + 1];
      
        // Store the frequency of elements in the unordered map.
        for (int num : arr) {
            freq[num + K]++;
        }
        
        // Sort the frequency count.
        Arrays.sort(freq);
        
        // If the adjacent freq count is equal, then the freq count isn't unique.
        for (int i = 0; i < 2 * K; i++) {
            if (freq[i] != 0 && freq[i] == freq[i + 1]) {
                return false;
            }
        }
        
        // If all the elements are traversed, it implies frequency counts are unique.
        return true;
    }
}
```

</details>

<br>

## Approach 2: HashMap & HashSet

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Store the frequency of elements in the unordered map.
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        
        // Store the frequency count of elements in the unordered set.
        unordered_set<int> freqSet;
        for (auto [key, value] : freq) {
            freqSet.insert(value);
        }
        
        // If the set size is equal to the map size, 
        // It implies frequency counts are unique.
        return freqSet.size() == freq.size();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        // Store the frequency of elements in the unordered map.
        Map<Integer, Integer> freq = new HashMap<>();
        for (int num : arr) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }
        
        // Store the frequency count of elements in the unordered set.
        Set<Integer> freqSet = new HashSet<>(freq.values());
        
        // If the set size is equal to the map size, 
        // It implies frequency counts are unique.
        return freq.size() == freqSet.size();
    }
}
```

</details>
