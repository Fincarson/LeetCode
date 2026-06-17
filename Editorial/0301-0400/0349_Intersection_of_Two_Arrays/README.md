# 349. Intersection of Two Arrays

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/intersection-of-two-arrays/)  
`Array` `Hash Table` `Two Pointers` `Binary Search` `Sorting`

**Problem Link:** [LeetCode 349 - Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/)

## Problem

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

### Example 1

```text
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
```

### Example 2

```text
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
```

## Constraints

- 1 <= nums1.length, nums2.length <= 1000
- 0 <= nums1[i], nums2[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Intersection of Three Sorted Arrays](https://leetcode.com/problems/intersection-of-three-sorted-arrays/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Find the Difference of Two Arrays](https://leetcode.com/problems/find-the-difference-of-two-arrays/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Count Common Words With One Occurrence](https://leetcode.com/problems/count-common-words-with-one-occurrence/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Choose Numbers From Two Arrays in Range](https://leetcode.com/problems/choose-numbers-from-two-arrays-in-range/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Intersection of Multiple Arrays](https://leetcode.com/problems/intersection-of-multiple-arrays/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Minimum Common Value](https://leetcode.com/problems/minimum-common-value/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Maximum Size of a Set After Removals](https://leetcode.com/problems/maximum-size-of-a-set-after-removals/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 349. Intersection of Two Arrays

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting and Two Pointers | Java, Python |
| Built-in Set Intersection | Java, Python |
| Two Sets | Java, Python |
| One Dictionary | Java, Python |

## Approach 1: Sorting and Two Pointers

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        // Sort both arrays
        Arrays.sort(nums1);
        Arrays.sort(nums2);

        // Initialize two pointers
        int N = nums1.length;
        int M = nums2.length;
        int p1 = 0;
        int p2 = 0;
        
        // Create set that stores integers appearing in both arrays
        Set<Integer> intersection = new HashSet<>();

        // Iterate the pointers from left to right
        while (p1 < N && p2 < M) {
            // Add a value to the set if values at both pointers equal
            if (nums1[p1] == nums2[p2]) {
                intersection.add(nums1[p1]);
                p1++;
                p2++;
            }
            // Otherwise, increment the pointer of the smaller integer
            else if (nums1[p1] < nums2[p2]) {
                p1++;
            }
            else {
                p2++;
            }
        }

        // Convert intersection to an array
        int K = intersection.size();
        int[] result = new int[K];
        int curr = 0;
        for (int x: intersection) {
            result[curr++] = x;
        }

        //Return the result
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        # Sort both arrays
        nums1.sort()
        nums2.sort()

        # Initialize two pointers
        N = len(nums1)
        M = len(nums2)
        p1 = 0
        p2 = 0

        # Create set that stores integers appearing in both arrays
        intersection = set()

        while p1 < N and p2 < M:
            # Add a value to the set if values at both pointers equal
            if nums1[p1] == nums2[p2]:
                intersection.add(nums1[p1])
                p1 += 1
                p2 += 1
            elif nums1[p1] < nums2[p2]:
                p1 += 1
            else:
                p2 += 1

        # Convert intersection to an array
        result = []
        for x in intersection:
            result.append(x)

        # Return the result
        return result
```

</details>

<br>

## Approach 2: Built-in Set Intersection

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int[] intersection(int[] nums1, int[] nums2) {
    Set<Integer> set1 = new HashSet<>();
    for (Integer n : nums1) {
        set1.add(n);
    } 
    Set<Integer> set2 = new HashSet<>();
    for (Integer n : nums2) {
        set2.add(n);
    }
    set1.retainAll(set2);
    int[] output = new int[set1.size()];
    int idx = 0;
    for (int s : set1) {
        output[idx++] = s;
    }
    return output;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """  
        set1 = set(nums1)
        set2 = set(nums2)
        return list(set2 & set1)
```

</details>

<br>

## Approach 3: Two Sets

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int[] setIntersection(Set<Integer> set1, Set<Integer> set2) {
    int[] output = new int[set1.size()];
    int idx = 0;
    for (Integer s : set1) {
        if (set2.contains(s)){
            output[idx++] = s;
        } 
    }
    return Arrays.copyOf(output, idx);
  }
  public int[] intersection(int[] nums1, int[] nums2) {
    Set<Integer> set1 = new HashSet<>();
    for (Integer n : nums1) {
        set1.add(n);
    } 
    Set<Integer> set2 = new HashSet<>();
    for (Integer n : nums2) {
        set2.add(n);
    }
    if (set1.size() < set2.size()){
        return setIntersection(set1, set2);
    } else {
        return setIntersection(set2, set1);
    } 
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def set_intersection(self, set1, set2):
        return [x for x in set1 if x in set2]
        
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """  
        set1 = set(nums1)
        set2 = set(nums2)
        
        if len(set1) < len(set2):
            return self.set_intersection(set1, set2)
        else:
            return self.set_intersection(set2, set1)
```

</details>

<br>

## Approach 4: One Dictionary

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        
        // Initialize seen map and result list
        Map<Integer, Integer> seen = new HashMap<>();
        List<Integer> result = new ArrayList<>();

        // Mark values occurring in nums1
        for (int x : nums1) {
            seen.put(x, 1);
        }

        // Check if n is in dictionary and not in the result
        for (int x : nums2) {
            if (seen.containsKey(x) && seen.get(x) == 1) {
                result.add(x);
                seen.put(x, 0);
            }
        }

        // Convert to int array and result the result
        return result.stream().mapToInt(i->i).toArray();
        
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def intersection(self, nums1, nums2):

        # Initialize seen dictionary and res array
        seen = {}
        result = []

        # mark values occurring in nums1
        for x in nums1:
          seen[x] = 1
          
        for x in nums2:
          # Check if x is in the dictionary and not in the result
          if x in seen and seen[x] == 1:
            result.append(x)
            seen[x] = 0

        # Return the result
        return result
```

</details>
