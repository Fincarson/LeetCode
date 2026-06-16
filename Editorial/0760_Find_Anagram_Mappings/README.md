# 760. Find Anagram Mappings

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/find-anagram-mappings/)  
`Array` `Hash Table`

**Problem Link:** [LeetCode 760 - Find Anagram Mappings](https://leetcode.com/problems/find-anagram-mappings/)

## Problem

You are given two integer arrays nums1 and nums2 where nums2 is an anagram of nums1. Both arrays may contain duplicates.

Return an index mapping array mapping from nums1 to nums2 where mapping[i] = j means the ith element in nums1 appears in nums2 at index j. If there are multiple answers, return any of them.

An array a is an anagram of an array b means b is made by randomizing the order of the elements in a.

### Example 1

```text
Input: nums1 = [12,28,46,32,50], nums2 = [50,12,32,46,28]
Output: [1,4,3,2,0]
Explanation: As mapping[0] = 1 because the 0th element of nums1 appears at nums2[1], and mapping[1] = 4 because the 1st element of nums1 appears at nums2[4], and so on.
```

### Example 2

```text
Input: nums1 = [84,46], nums2 = [84,46]
Output: [0,1]
```

## Constraints

- 1 <= nums1.length <= 100
- nums2.length == nums1.length
- 0 <= nums1[i], nums2[i] <= 105
- nums2 is an anagram of nums1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 760. Find Anagram Mappings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java |
| HashMap | C++, Java |
| Bit Manipulation + Sorting | C++, Java |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        // List to store the anagram mappings.
        vector<int> mappings;
        
        for (int num : nums1) {
            for (int i = 0; i < nums2.size(); i++) {
                // Store the corresponding index of number in the second list.
                if (num == nums2[i]) {
                    mappings.push_back(i);
                    break;
                }
            }
        }
        return mappings;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] anagramMappings(int[] nums1, int[] nums2) {
        // List to store the anagram mappings.
        int[] mappings = new int[nums1.length];
        
        for (int i = 0; i < nums1.length; i++) {
            for (int j = 0; j < nums2.length; j++) {
                // Store the corresponding index of number in the second list.
                if (nums1[i] == nums2[j]) {
                    mappings[i] = j;
                    break;
                }
            }
        }
        return mappings;
    }
}
```

</details>

<br>

## Approach 2: HashMap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        // Store the index corresponding to the value in the second list.
        unordered_map<int, int> valueToPos;
        for (int i = 0; i < nums2.size(); i++) {
            valueToPos[nums2[i]] = i;
        }
        
        // List to store the anagram mappings.
        vector<int> mappings;
        for (int num : nums1) {
            mappings.push_back(valueToPos[num]);
        }
        
        return mappings;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int[] anagramMappings(int[] nums1, int[] nums2) {
    // Store the index corresponding to the value in the second list.
    HashMap<Integer,Integer> valueToPos = new HashMap<>();
    for (int i = 0; i < nums2.length; i++) {
      valueToPos.put(nums2[i], i);
    }

    // List to store the anagram mappings.
    int[] mappings = new int[nums1.length];
    for (int i = 0; i < nums1.length; i++) {
      mappings[i]  = valueToPos.get(nums1[i]);
    }

    return mappings;
  }
}
```

</details>

<br>

## Approach 3: Bit Manipulation + Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    const int bitsToShift = 7;
    const int numToGetLastBits = (1 << bitsToShift) - 1;
    
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        // Store the index within the integer itself.
        for (int i = 0; i < nums1.size(); i++) {
            nums1[i] = (nums1[i] << bitsToShift) + i;
            nums2[i] = (nums2[i] << bitsToShift) + i;
        }
        
        // Sort both lists so that the original integers end up at the same index.
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        // List to store the anagram mappings.
        vector<int> mappings(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            // Store the index in the second list corresponding to the integer index in the first list.
            mappings[nums1[i] & numToGetLastBits] = (nums2[i] & numToGetLastBits);
        }

        return mappings;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  final int bitsToShift = 7;
  final int numToGetLastBits = (1 << bitsToShift) - 1;

  public int[] anagramMappings(int[] nums1, int[] nums2) {
    // Store the index within the integer itself.
    for (int i = 0; i < nums1.length; i++) {
      nums1[i] = (nums1[i] << bitsToShift) + i;
      nums2[i] = (nums2[i] << bitsToShift) + i;
    }

    // Sort both lists so that the original integers end up at the same index.
    Arrays.sort(nums1);
    Arrays.sort(nums2);

    // List to store the anagram mappings.
    int[] mappings = new int[nums1.length];
    for (int i = 0; i < nums1.length; i++) {
      // Store the index in the second list corresponding to the integer index in the first list.
      mappings[nums1[i] & numToGetLastBits] = (nums2[i] & numToGetLastBits);
    }

    return mappings;
  }
}
```

</details>
