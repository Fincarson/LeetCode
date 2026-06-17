# 2215. Find the Difference of Two Arrays

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/find-the-difference-of-two-arrays/)  
`Array` `Hash Table`

**Problem Link:** [LeetCode 2215 - Find the Difference of Two Arrays](https://leetcode.com/problems/find-the-difference-of-two-arrays/)

## Problem

Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

- answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
- answer[1] is a list of all distinct integers in nums2 which are not present in nums1.

Note that the integers in the lists may be returned in any order.

### Example 1

```text
Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums1. Therefore, answer[1] = [4,6].
```

### Example 2

```text
Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
```

## Constraints

- 1 <= nums1.length, nums2.length <= 1000
- -1000 <= nums1[i], nums2[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Intersection of Multiple Arrays](https://leetcode.com/problems/intersection-of-multiple-arrays/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2215. Find the Difference of Two Arrays

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java |
| HashSet | C++, Java |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Returns the elements in the first arg nums1 that don't exist in the second arg nums2.
    vector<int> getElementsOnlyInFirstList(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> onlyInNums1;
        
        // Iterate over each element in the list nums1.
        for (int num : nums1) {
            bool existInNums2 = false;
            // Check if num is present in the second arg nums2.
            for (int x : nums2) {
                if (x == num) {
                    existInNums2 = true;
                    break;
                }
            }
            
            if (!existInNums2) {
                onlyInNums1.insert(num);
            }
        }
        
        // Convert to vector.
        return vector<int> (onlyInNums1.begin(), onlyInNums1.end());
    }
    
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {getElementsOnlyInFirstList(nums1, nums2), getElementsOnlyInFirstList(nums2, nums1)};
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Returns the elements in the first arg nums1 that don't exist in the second arg nums2.
    List<Integer> getElementsOnlyInFirstList(int[] nums1, int[] nums2) {
        Set<Integer> onlyInNums1 = new HashSet<> (); 
        
        // Iterate over each element in the list nums1.
        for (int num : nums1) {
            boolean existInNums2 = false;
            // Check if num is present in the second arg nums2.
            for (int x : nums2) {
                if (x == num) {
                    existInNums2 = true;
                    break;
                }
            }
            
            if (!existInNums2) {
                onlyInNums1.add(num);
            }
        }
        
        // Convert to vector.
        return new ArrayList<>(onlyInNums1);
    }
    
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        return Arrays.asList(getElementsOnlyInFirstList(nums1, nums2), getElementsOnlyInFirstList(nums2, nums1));
    }
}
```

</details>

<br>

## Approach 2: HashSet

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Returns the elements in the first arg nums1 that don't exist in the second arg nums2.
    vector<int> getElementsOnlyInFirstList(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> onlyInNums1;
        
        // Store nums2 elements in an unordered set. 
        unordered_set<int> existsInNums2;
        for (int num : nums2) {
            existsInNums2.insert(num);
        }
        
        // Iterate over each element in the list nums1.
        for (int num : nums1) {
            if (existsInNums2.find(num) == existsInNums2.end()) {
                onlyInNums1.insert(num);
            }
        }
        
        // Convert to vector.
        return vector<int> (onlyInNums1.begin(), onlyInNums1.end());
    }
    
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {getElementsOnlyInFirstList(nums1, nums2), getElementsOnlyInFirstList(nums2, nums1)};
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Returns the elements in the first arg nums1 that don't exist in the second arg nums2.
    List<Integer> getElementsOnlyInFirstList(int[] nums1, int[] nums2) {
        Set<Integer> onlyInNums1 = new HashSet<> (); 
        
        // Store nums2 elements in an unordered set. 
        Set<Integer> existsInNums2 = new HashSet<> (); 
        for (int num : nums2) {
            existsInNums2.add(num);
        }
        
        // Iterate over each element in the list nums1.
        for (int num : nums1) {
            if (!existsInNums2.contains(num)) {
                onlyInNums1.add(num);
            }
        }
        
        // Convert to vector.
        return new ArrayList<>(onlyInNums1);
    }
    
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        return Arrays.asList(getElementsOnlyInFirstList(nums1, nums2), getElementsOnlyInFirstList(nums2, nums1));
    }
}
```

</details>
