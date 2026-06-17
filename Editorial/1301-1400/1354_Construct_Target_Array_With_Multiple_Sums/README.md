# 1354. Construct Target Array With Multiple Sums

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/construct-target-array-with-multiple-sums/)  
`Array` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 1354 - Construct Target Array With Multiple Sums](https://leetcode.com/problems/construct-target-array-with-multiple-sums/)

## Problem

You are given an array target of n integers. From a starting array arr consisting of n 1's, you may perform the following procedure :

- let x be the sum of all elements currently in your array.
- choose index i, such that 0 <= i < n and set the value of arr at index i to x.
- You may repeat this procedure as many times as needed.

Return true if it is possible to construct the target array from arr, otherwise, return false.

### Example 1

```text
Input: target = [9,3,5]
Output: true
Explanation: Start with arr = [1, 1, 1]
[1, 1, 1], sum = 3 choose index 1
[1, 3, 1], sum = 5 choose index 2
[1, 3, 5], sum = 9 choose index 0
[9, 3, 5] Done
```

### Example 2

```text
Input: target = [1,1,1,2]
Output: false
Explanation: Impossible to create target array from [1,1,1,1].
```

### Example 3

```text
Input: target = [8,5]
Output: true
```

## Constraints

- n == target.length
- 1 <= n <= 5 * 104
- 1 <= target[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Amount of Time to Fill Cups](https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1354. Construct Target Array With Multiple Sums

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Working Backward | Java, Python |
| Working Backward with Optimizations | Java, Python |

## Approach 1: Working Backward

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isPossible(int[] target) {
        
        // Handle the n = 1 case.
        if (target.length == 1) {
            return target[0] == 1;
        }
        
        int totalSum = Arrays.stream(target).sum();
        
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());
        for (int num : target) {
            pq.add(num);
        }
        
        while (pq.element() > 1) {
            int largest = pq.remove();
            int x = largest - (totalSum - largest);
            if (x < 1) return false;
            pq.add(x);
            totalSum = totalSum - largest + x;
        }
        
        return true; 
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def isPossible(self, target: List[int]) -> bool:

    # Handle the n = 1 case.
    if len(target) == 1:
        return target == [1]
    
    total_sum = sum(target)
    
    # Because Python's heapq is a min-heap, we need to 
    # do the negation to make it like a max-heap.
    target = [-num for num in target]
    heapq.heapify(target)
    
    # Note the negative sign before target[0] :-)
    while -target[0] > 1:
        largest = -target[0]
        x = largest - (total_sum - largest)
        if x < 1:
            return False
    
        # Pops the minimum and *then* adds new. Is slightly 
        # more efficient than doing seperate pop and push.
        heapq.heapreplace(target, -x)
        total_sum = total_sum - largest + x
    
    return True
```

</details>

<br>

## Approach 2: Working Backward with Optimizations

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isPossible(int[] target) {
        
        // Handle the n = 1 case.
        if (target.length == 1) {
            return target[0] == 1;
        }
        
        int totalSum = Arrays.stream(target).sum();
        
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());
        for (int num : target) {
            pq.add(num);
        }
        
        while (pq.element() > 1) {
            int largest = pq.remove();
            int rest = totalSum - largest;
            
            // This will only occur if n = 2.
            if (rest == 1) {
                return true;
            }
            int x = largest % rest;
            
            // If x is now 0 (invalid) or didn't
            // change, then we know this is impossible.
            if (x == 0 || x == largest) {
                return false;
            }
            pq.add(x);
            totalSum = totalSum - largest + x;
        }
        
        return true; 
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def isPossible(self, target: List[int]) -> bool:
        
    # Handle the n = 1 case.
    if len(target) == 1:
        return target == [1]
    
    total_sum = sum(target)
    
    target = [-num for num in target]
    heapq.heapify(target)
    while -target[0] > 1:
        largest = -target[0]
        rest = total_sum - largest
        
        # This will only occur if n = 2.
        if rest == 1:
            return True
        
        x = largest % rest
        
        # If x is now 0 (invalid) or didn't
        # change, then we know this is impossible.
        if x == 0 or x == largest:
            return False
        heapq.heapreplace(target, -x)
        total_sum = total_sum - largest + x
    
    return True
```

</details>
