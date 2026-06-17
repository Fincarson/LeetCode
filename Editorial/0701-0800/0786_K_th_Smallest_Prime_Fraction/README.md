# 786. K-th Smallest Prime Fraction

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/k-th-smallest-prime-fraction/)  
`Array` `Two Pointers` `Binary Search` `Sorting` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 786 - K-th Smallest Prime Fraction](https://leetcode.com/problems/k-th-smallest-prime-fraction/)

## Problem

You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.

For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].

### Example 1

```text
Input: arr = [1,2,3,5], k = 3
Output: [2,5]
Explanation: The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
The third fraction is 2/5.
```

### Example 2

```text
Input: arr = [1,7], k = 1
Output: [1,7]
```

## Constraints

- 2 <= arr.length <= 1000
- 1 <= arr[i] <= 3 * 104
- arr[0] == 1
- arr[i] is a prime number for i > 0.
- All the numbers of arr are unique and sorted in strictly increasing order.
- 1 <= k <= arr.length * (arr.length - 1) / 2

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Kth Smallest Number in Multiplication Table](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Find K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 786. K-th Smallest Prime Fraction

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C++, Java, Python3 |
| Priority Queue | C++, Java, Python3 |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0, right = 1.0;
        
        // Binary search for finding the kth smallest prime fraction
        while (left < right){
            // Calculate the middle value
            double mid = (left + right) / 2;
            
            // Initialize variables to keep track of maximum fraction and indices
            double maxFraction = 0.0;
            int totalSmallerFractions = 0, numeratorIdx = 0, denominatorIdx = 0;
            int j = 1;
            
            // Iterate through the array to find fractions smaller than mid
            for (int i = 0; i < n - 1; i++){
                while (j < n && arr[i] >= mid * arr[j]){
                    j++;
                }

                // Count smaller fractions
                totalSmallerFractions += (n - j);
                
                // If we have exhausted the array, break
                if (j == n) break;
                
                // Calculate the fraction
                double fraction = static_cast<double>(arr[i]) / arr[j];
                
                // Update maxFraction and indices if necessary
                if (fraction > maxFraction) {
                  numeratorIdx = i;
                  denominatorIdx = j;
                  maxFraction = fraction;
                }
            }
            
            // Check if we have found the kth smallest prime fraction
            if (totalSmallerFractions == k) {
                return {arr[numeratorIdx], arr[denominatorIdx]};
            } else if (totalSmallerFractions > k) {
                right = mid; // Adjust the range for binary search
            } else {
                left = mid; // Adjust the range for binary search
            }
        }
        return {}; // Return empty vector if kth smallest prime fraction not found
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        int n = arr.length;
        double left = 0, right = 1.0;
        
        // Binary search for finding the kth smallest prime fraction
        while (left < right) {
            // Calculate the middle value
            double mid = (left + right) / 2;
            
            // Initialize variables to keep track of maximum fraction and indices
            double maxFraction = 0.0;
            int totalSmallerFractions = 0, numeratorIdx = 0, denominatorIdx = 0;
            int j = 1;
            
            // Iterate through the array to find fractions smaller than mid
            for (int i = 0; i < n - 1; i++) {
                while (j < n && arr[i] >= mid * arr[j]) {
                    j++;
                }

                // Count smaller fractions
                totalSmallerFractions += (n - j);

                // If we have exhausted the array, break
                if (j == n) break;

                // Calculate the fraction
                double fraction = (double) arr[i] / arr[j];

                // Update maxFraction and indices if necessary
                if (fraction > maxFraction) {
                    numeratorIdx = i;
                    denominatorIdx = j;
                    maxFraction = fraction;
                }
            }

            // Check if we have found the kth smallest prime fraction
            if (totalSmallerFractions == k) {
                return new int[]{arr[numeratorIdx], arr[denominatorIdx]};
            } else if (totalSmallerFractions > k) {
                right = mid; // Adjust the range for binary search
            } else {
                left = mid; // Adjust the range for binary search
            }
        }
        return new int[]{}; // Return empty array if kth smallest prime fraction not found
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def kthSmallestPrimeFraction(self, arr, k):
        n = len(arr)
        left, right = 0, 1.0
        
        # Binary search for finding the kth smallest prime fraction
        while left < right:
            # Calculate the middle value
            mid = (left + right) / 2
            # Initialize variables to keep track of maximum fraction and indices
            max_fraction = 0.0
            total_smaller_fractions = 0
            numerator_idx, denominator_idx = 0, 0
            j = 1
            
            # Iterate through the array to find fractions smaller than mid
            for i in range(n - 1):
                while j < n and arr[i] >= mid * arr[j]:
                    j += 1

                # Count smaller fractions
                total_smaller_fractions += (n - j)

                # If we have exhausted the array, break
                if j == n:
                    break

                # Calculate the fraction
                fraction = arr[i] / arr[j]

                # Update max_fraction and indices if necessary
                if fraction > max_fraction:
                    numerator_idx = i
                    denominator_idx = j
                    max_fraction = fraction

            # Check if we have found the kth smallest prime fraction
            if total_smaller_fractions == k:
                return [arr[numerator_idx], arr[denominator_idx]]
            elif total_smaller_fractions > k:
                right = mid  # Adjust the range for binary search
            else:
                left = mid  # Adjust the range for binary search
                
        return []  # Return empty list if kth smallest prime fraction not found
```

</details>

<br>

## Approach 2: Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // Create a priority queue to store pairs of fractions
        priority_queue<pair<double, pair<int, int>>> pq;

        // Push the fractions formed by dividing each element by
        // the largest element into the priority queue
        for (int i = 0; i < arr.size() - 1; i++)
            pq.push({-1.0 * arr[i] / arr.back(), {i, arr.size() - 1}});
        
        // Iteratively remove the top element (smallest fraction) 
        // and replace it with the next smallest fraction
        while (--k > 0) {
            pair<int, int> cur = pq.top().second;
            pq.pop();
            cur.second--;
            pq.push({-1.0 * arr[cur.first] / arr[cur.second], 
                    {cur.first, cur.second}});
        }
        
        // Retrieve the kth smallest fraction from 
        // the top of the priority queue
        pair<int, int> result = pq.top().second;
        return {arr[result.first], arr[result.second]};
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        // Create a priority queue to store pairs of fractions
        PriorityQueue<double[]> pq = new PriorityQueue<>((a, b) -> Double.compare(b[0], a[0]));

        // Push the fractions formed by dividing each element by
        // the largest element into the priority queue
        for (int i = 0; i < arr.length - 1; i++) {
            pq.offer(new double[] {
                -1.0 * arr[i] / arr[arr.length - 1], 
                i, 
                arr.length - 1
            });
        }

        // Iteratively remove the top element (smallest fraction) 
        // and replace it with the next smallest fraction
        while (--k > 0) {
            double[] cur = pq.poll();
            int numeratorIndex = (int) cur[1];
            int denominatorIndex = (int) cur[2] - 1;
            if (denominatorIndex > numeratorIndex) {
                pq.offer(new double[] {
                        -1.0 * arr[numeratorIndex] / arr[denominatorIndex], 
                        numeratorIndex, 
                        denominatorIndex
                });
            }
        }

        // Retrieve the kth smallest fraction from 
        // the top of the priority queue
        double[] result = pq.poll();
        return new int[]{arr[(int) result[1]], arr[(int) result[2]]};
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def kthSmallestPrimeFraction(self, arr, k):
        # Create a priority queue to store pairs of fractions
        pq = []

        # Custom comparator for priority queue
        def compare(a, b):
            return a[0] - b[0]

        # Push the fractions formed by dividing each element by
        # the largest element into the priority queue
        for i in range(len(arr) - 1):
            heapq.heappush(pq, ((arr[i] / arr[-1]), i, len(arr) - 1))

        # Iteratively remove the top element (smallest fraction) 
        # and replace it with the next smallest fraction
        for _ in range(k - 1):
            cur = heapq.heappop(pq)
            numerator_index = cur[1]
            denominator_index = cur[2] - 1
            if denominator_index > numerator_index:
                heapq.heappush(pq, (
                    (arr[numerator_index] / arr[denominator_index]), 
                    numerator_index, 
                    denominator_index
                ))

        # Retrieve the kth smallest fraction from 
        # the top of the priority queue
        result = heapq.heappop(pq)
        return [arr[result[1]], arr[result[2]]]
```

</details>
