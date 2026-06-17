# 2657. Find the Prefix Common Array of Two Arrays

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/)  
`Array` `Hash Table` `Bit Manipulation`

**Problem Link:** [LeetCode 2657 - Find the Prefix Common Array of Two Arrays](https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/)

## Problem

You are given two 0-indexed integer permutations A and B of length n.

A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.

Return the prefix common array of A and B.

A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

### Example 1

```text
Input: A = [1,3,2,4], B = [3,1,2,4]
Output: [0,2,3,4]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.
```

### Example 2

```text
Input: A = [2,3,1], B = [3,1,2]
Output: [0,1,3]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: only 3 is common in A and B, so C[1] = 1.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
```

## Constraints

- 1 <= A.length == B.length == n <= 50
- 1 <= A[i], B[i] <= n
- It is guaranteed that A and B are both a permutation of n integers.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2657. Find the Prefix Common Array of Two Arrays

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Hash Set | C++, Java, Python3 |
| Single Pass with Frequency Array | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> prefixCommonArray(n);

        // Loop through each index to calculate common elements for each prefix
        for (int currentIndex = 0; currentIndex < n; ++currentIndex) {
            int commonCount = 0;

            // Compare elements in A and B within the range of current prefix
            for (int aIndex = 0; aIndex <= currentIndex; ++aIndex) {
                for (int bIndex = 0; bIndex <= currentIndex; ++bIndex) {
                    // Check if elements match, and count if they do
                    if (A[aIndex] == B[bIndex]) {
                        ++commonCount;
                        break;
                    }
                }
            }

            // Store the count of common elements for the current prefix
            prefixCommonArray[currentIndex] = commonCount;
        }

        // Return the final array with counts of common elements in each prefix
        return prefixCommonArray;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] prefixCommonArray = new int[n];

        // Loop through each index to calculate common elements for each prefix
        for (int currentIndex = 0; currentIndex < n; ++currentIndex) {
            int commonCount = 0;

            // Compare elements in A and B within the range of current prefix
            for (int aIndex = 0; aIndex <= currentIndex; ++aIndex) {
                for (int bIndex = 0; bIndex <= currentIndex; ++bIndex) {
                    // Check if elements match, and count if they do
                    if (A[aIndex] == B[bIndex]) {
                        ++commonCount;
                        break; // Prevent counting duplicates
                    }
                }
            }

            // Store the count of common elements for the current prefix
            prefixCommonArray[currentIndex] = commonCount;
        }

        // Return the final array with counts of common elements in each prefix
        return prefixCommonArray;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findThePrefixCommonArray(self, A: list, B: list) -> list:
        n = len(A)
        prefix_common_array = [0] * n

        # Loop through each index to calculate common elements for each prefix
        for current_index in range(n):
            common_count = 0

            # Compare elements in A and B within the range of current prefix
            for a_index in range(current_index + 1):
                for b_index in range(current_index + 1):

                    # Check if elements match, and count if they do
                    if A[a_index] == B[b_index]:
                        common_count += 1
                        break  # Prevent counting duplicates

            # Store the count of common elements for the current prefix
            prefix_common_array[current_index] = common_count

        # Return the final list with counts of common elements in each prefix
        return prefix_common_array
```

</details>

<br>

## Approach 2: Hash Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> prefixCommonArray(n);

        // Initialize sets to store elements from A and B
        unordered_set<int> elementsInA, elementsInB;

        // Iterate through the elements of both arrays
        for (int currentIndex = 0; currentIndex < n; ++currentIndex) {
            // Add current elements from A and B to respective sets
            elementsInA.insert(A[currentIndex]);
            elementsInB.insert(B[currentIndex]);

            int commonCount = 0;

            // Count common elements between the sets
            for (int element : elementsInA) {
                if (elementsInB.count(element)) {
                    ++commonCount;
                }
            }

            // Store the count of common elements for the current prefix
            prefixCommonArray[currentIndex] = commonCount;
        }

        // Return the final array with counts of common elements in each prefix
        return prefixCommonArray;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] prefixCommonArray = new int[n];

        // Initialize sets to store elements from A and B
        Set<Integer> elementsInA = new HashSet<Integer>();
        Set<Integer> elementsInB = new HashSet<Integer>();

        // Iterate through the elements of both arrays
        for (int currentIndex = 0; currentIndex < n; ++currentIndex) {
            // Add current elements from A and B to respective sets
            elementsInA.add(A[currentIndex]);
            elementsInB.add(B[currentIndex]);

            int commonCount = 0;

            // Count common elements between the sets
            for (int element : elementsInA) {
                if (elementsInB.contains(element)) {
                    ++commonCount;
                }
            }

            // Store the count of common elements for the current prefix
            prefixCommonArray[currentIndex] = commonCount;
        }

        // Return the final array with counts of common elements in each prefix
        return prefixCommonArray;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        prefix_common_array = [0] * n

        # Initialize sets to store elements from A and B
        elements_in_A, elements_in_B = set(), set()

        # Iterate through the elements of both arrays
        for current_index in range(n):

            # Add current elements from A and B to respective sets
            elements_in_A.add(A[current_index])
            elements_in_B.add(B[current_index])

            common_count = 0

            # Count common elements between the sets
            for element in elements_in_A:
                if element in elements_in_B:
                    common_count += 1

            # Store the count of common elements for the current prefix
            prefix_common_array[current_index] = common_count

        # Return the final array with counts of common elements in each prefix
        return prefix_common_array
```

</details>

<br>

## Approach 3: Single Pass with Frequency Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> prefixCommonArray(n), frequency(n + 1, 0);
        int commonCount = 0;

        // Iterate through the elements of both arrays
        for (int currentIndex = 0; currentIndex < n; ++currentIndex) {
            // Increment frequency of current elements in A and B
            // Check if the element in A has appeared before (common in prefix)
            if (++frequency[A[currentIndex]] == 2) ++commonCount;

            // Check if the element in B has appeared before (common in prefix)
            if (++frequency[B[currentIndex]] == 2) ++commonCount;

            // Store the count of common elements for the current prefix
            prefixCommonArray[currentIndex] = commonCount;
        }

        // Return the final array with counts of common elements in each prefix
        return prefixCommonArray;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] prefixCommonArray = new int[n];
        int[] frequency = new int[n + 1];
        int commonCount = 0;

        // Iterate through the elements of both arrays
        for (int currentIndex = 0; currentIndex < n; ++currentIndex) {
            // Increment frequency of current elements in A and B
            // Check if the element in A has appeared before (common in prefix)
            frequency[A[currentIndex]] += 1;
            if (frequency[A[currentIndex]] == 2) ++commonCount;

            // Check if the element in B has appeared before (common in prefix)
            frequency[B[currentIndex]] += 1;
            if (frequency[B[currentIndex]] == 2) ++commonCount;

            // Store the count of common elements for the current prefix
            prefixCommonArray[currentIndex] = commonCount;
        }

        // Return the final array with counts of common elements in each prefix
        return prefixCommonArray;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        prefix_common_array = [0 for _ in range(n)]
        frequency = [0 for _ in range(n + 1)]
        common_count = 0

        # Iterate through the elements of both arrays
        for current_index in range(n):

            # Increment frequency of current elements in A and B
            # Check if the element in A has appeared before (common in prefix)
            frequency[A[current_index]] += 1
            if frequency[A[current_index]] == 2:
                common_count += 1

            # Check if the element in B has appeared before (common in prefix)
            frequency[B[current_index]] += 1
            if frequency[B[current_index]] == 2:
                common_count += 1

            # Store the count of common elements for the current prefix
            prefix_common_array[current_index] = common_count

        # Return the final array with counts of common elements in each prefix
        return prefix_common_array
```

</details>
