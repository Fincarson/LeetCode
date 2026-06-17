# 448. Find All Numbers Disappeared in an Array

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)  
`Array` `Hash Table`

**Problem Link:** [LeetCode 448 - Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)

## Problem

Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

### Example 1

```text
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
```

### Example 2

```text
Input: nums = [1,1]
Output: [2]
```

## Constraints

- n == nums.length
- 1 <= n <= 105
- 1 <= nums[i] <= n

Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [First Missing Positive](https://leetcode.com/problems/first-missing-positive/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find Unique Binary String](https://leetcode.com/problems/find-unique-binary-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Append K Integers With Minimal Sum](https://leetcode.com/problems/append-k-integers-with-minimal-sum/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Replace Elements in an Array](https://leetcode.com/problems/replace-elements-in-an-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Number of Integers to Choose From a Range I](https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Number of Integers to Choose From a Range II](https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 448. Find All Numbers Disappeared in an Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Hash Map | Java, Python |
| O(1) Space InPlace Modification Solution | Java, Python |

## Approach 1: Using Hash Map

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        
        // Hash table for keeping track of the numbers in the array
        // Note that we can also use a set here since we are not 
        // really concerned with the frequency of numbers.
        HashMap<Integer, Boolean> hashTable = new HashMap<Integer, Boolean>();
        
        // Add each of the numbers to the hash table
        for (int i = 0; i < nums.length; i++) {
            hashTable.put(nums[i], true);
        }
        
        // Response array that would contain the missing numbers
        List<Integer> result = new LinkedList<Integer>();
        
        // Iterate over the numbers from 1 to N and add all those
        // that don't appear in the hash table. 
        for (int i = 1; i <= nums.length; i++) {
            if (!hashTable.containsKey(i)) {
                result.add(i);
            }
        }
        
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        # Hash table for keeping track of the numbers in the array
        # Note that we can also use a set here since we are not 
        # really concerned with the frequency of numbers.
        hash_table = {}
        
        # Add each of the numbers to the hash table
        for num in nums:
            hash_table[num] = 1
        
        # Response array that would contain the missing numbers
        result = []    
        
        # Iterate over the numbers from 1 to N and add all those
        # that don't appear in the hash table. 
        for num in range(1, len(nums) + 1):
            if num not in hash_table:
                result.append(num)
                
        return result
```

</details>

<br>

## Approach 2: O(1) Space InPlace Modification Solution

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        
        // Iterate over each of the elements in the original array
        for (int i = 0; i < nums.length; i++) {
            
            // Treat the value as the new index
            int newIndex = Math.abs(nums[i]) - 1;
            
            // Check the magnitude of value at this new index
            // If the magnitude is positive, make it negative 
            // thus indicating that the number nums[i] has 
            // appeared or has been visited.
            if (nums[newIndex] > 0) {
                nums[newIndex] *= -1;
            }
        }
        
        // Response array that would contain the missing numbers
        List<Integer> result = new LinkedList<Integer>();
        
        // Iterate over the numbers from 1 to N and add all those
        // that have positive magnitude in the array
        for (int i = 1; i <= nums.length; i++) {
            
            if (nums[i - 1] > 0) {
                result.add(i);
            }
        }
        
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        # Iterate over each of the elements in the original array
        for i in range(len(nums)):
            
            # Treat the value as the new index
            new_index = abs(nums[i]) - 1
            
            # Check the magnitude of value at this new index
            # If the magnitude is positive, make it negative 
            # thus indicating that the number nums[i] has 
            # appeared or has been visited.
            if nums[new_index] > 0:
                nums[new_index] *= -1
        
        # Response array that would contain the missing numbers
        result = []    
        
        # Iterate over the numbers from 1 to N and add all those
        # that have positive magnitude in the array 
        for i in range(1, len(nums) + 1):
            if nums[i - 1] > 0:
                result.append(i)
                
        return result
```

</details>
