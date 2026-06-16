# 264. Ugly Number II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/ugly-number-ii/)  
`Hash Table` `Math` `Dynamic Programming` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 264 - Ugly Number II](https://leetcode.com/problems/ugly-number-ii/)

## Problem

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

### Example 1

```text
Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
```

### Example 2

```text
Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
```

## Constraints

- 1 <= n <= 1690

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Count Primes](https://leetcode.com/problems/count-primes/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Ugly Number](https://leetcode.com/problems/ugly-number/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Perfect Squares](https://leetcode.com/problems/perfect-squares/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Super Ugly Number](https://leetcode.com/problems/super-ugly-number/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Ugly Number III](https://leetcode.com/problems/ugly-number-iii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 264. Ugly Number II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Set | C++, Java, Python3 |
| Min-Heap/Priority Queue | C++, Java, Python3 |
| Dynamic Programming (DP) | C++, Java, Python3 |

## Approach 1: Using Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> uglyNumbersSet;  // Set to store potential ugly numbers
        uglyNumbersSet.insert(1);  // Start with 1, the first ugly number

        long currentUgly = 1;
        for (int i = 0; i < n; i++) {
            currentUgly =
                *uglyNumbersSet
                     .begin();  // Get the smallest number from the set
            uglyNumbersSet.erase(
                uglyNumbersSet.begin());  // Remove it from the set

            // Insert the next potential ugly numbers
            uglyNumbersSet.insert(currentUgly * 2);
            uglyNumbersSet.insert(currentUgly * 3);
            uglyNumbersSet.insert(currentUgly * 5);
        }

        return static_cast<int>(currentUgly);  // Return the nth ugly number
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int nthUglyNumber(int n) {
        TreeSet<Long> uglyNumbersSet = new TreeSet<>(); // TreeSet to store potential ugly numbers
        uglyNumbersSet.add(1L); // Start with 1, the first ugly number
        // TreeSet automatically sorts elements in ascending order and does not
        // allow duplicate entries, just like a HashSet in python

        Long currentUgly = 1L;
        for (int i = 0; i < n; i++) {
            currentUgly = uglyNumbersSet.pollFirst(); // Get the smallest number from the set and remove it

            // Insert the next potential ugly numbers into the set
            uglyNumbersSet.add(currentUgly * 2);
            uglyNumbersSet.add(currentUgly * 3);
            uglyNumbersSet.add(currentUgly * 5);
        }

        return currentUgly.intValue(); // Return the nth ugly number
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        # Set to store potential ugly numbers
        ugly_numbers_set = set()
        # Start with 1, the first ugly number
        ugly_numbers_set.add(1)

        current_ugly = 1
        for i in range(n):
            # Get the smallest number from the set
            current_ugly = min(ugly_numbers_set)
            # Remove it from the set
            ugly_numbers_set.remove(current_ugly)

            # Insert the next potential ugly numbers
            ugly_numbers_set.add(current_ugly * 2)
            ugly_numbers_set.add(current_ugly * 3)
            ugly_numbers_set.add(current_ugly * 5)

        # Return the nth ugly number
        return current_ugly
```

</details>

<br>

## Approach 2: Min-Heap/Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        // Min-heap to store and retrieve the smallest ugly number
        priority_queue<long, vector<long>, greater<long>> minHeap;
        unordered_set<long> seenNumbers;  // Set to avoid duplicates
        vector<int> primeFactors = {
            2, 3, 5};  // Factors for generating new ugly numbers

        minHeap.push(1);
        seenNumbers.insert(1);

        long currentUgly = 1;
        for (int i = 0; i < n; ++i) {
            currentUgly = minHeap.top();  // Get the smallest number
            minHeap.pop();                // Remove it from the heap

            // Generate and push the next ugly numbers
            for (int prime : primeFactors) {
                long nextUgly = currentUgly * prime;
                if (seenNumbers.find(nextUgly) ==
                    seenNumbers.end()) {  // Avoid duplicates
                    minHeap.push(nextUgly);
                    seenNumbers.insert(nextUgly);
                }
            }
        }

        return static_cast<int>(currentUgly);  // Return the nth ugly number
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int nthUglyNumber(int n) {
        PriorityQueue<Long> minHeap = new PriorityQueue<>();
        Set<Long> seenNumbers = new HashSet<>(); // Set to avoid duplicates
        int[] primeFactors = { 2, 3, 5 }; // Factors for generating new ugly numbers

        minHeap.offer(1L);
        seenNumbers.add(1L);

        long currentUgly = 1L;
        for (int i = 0; i < n; i++) {
            currentUgly = minHeap.poll(); // Get the smallest number

            // Generate and push the next ugly numbers
            for (int prime : primeFactors) {
                long nextUgly = currentUgly * prime;
                if (seenNumbers.add(nextUgly)) { // Avoid duplicates
                    minHeap.offer(nextUgly);
                }
            }
        }

        return (int) currentUgly; // Return the nth ugly number
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
import heapq


class Solution:
    def nthUglyNumber(self, n: int) -> int:
        min_heap = []  # min-heap to store and retrieve the smallest ugly number
        seen_numbers = set()  # set to avoid duplicates
        prime_factors = [2, 3, 5]  # factors for generating new ugly numbers

        heapq.heappush(min_heap, 1)
        seen_numbers.add(1)

        current_ugly = 1
        for _ in range(n):
            current_ugly = heapq.heappop(min_heap)  # get the smallest number

            # generate and push the next ugly numbers
            for prime in prime_factors:
                next_ugly = current_ugly * prime
                if next_ugly not in seen_numbers:  # avoid duplicates
                    heapq.heappush(min_heap, next_ugly)
                    seen_numbers.add(next_ugly)

        return current_ugly  # return the nth ugly number
```

</details>

<br>

## Approach 3: Dynamic Programming (DP)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNumbers(n);  // DP array to store ugly numbers
        uglyNumbers[0] = 1;          // The first ugly number is 1

        // Three pointers for the multiples of 2, 3, and 5
        int indexMultipleOf2 = 0, indexMultipleOf3 = 0, indexMultipleOf5 = 0;
        int nextMultipleOf2 = 2, nextMultipleOf3 = 3, nextMultipleOf5 = 5;

        // Generate ugly numbers until we reach the nth one
        for (int i = 1; i < n; i++) {
            // Find the next ugly number as the minimum of the next multiples
            int nextUglyNumber =
                min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));
            uglyNumbers[i] = nextUglyNumber;

            // Update the corresponding pointer and next multiple
            if (nextUglyNumber == nextMultipleOf2) {
                indexMultipleOf2++;
                nextMultipleOf2 = uglyNumbers[indexMultipleOf2] * 2;
            }
            if (nextUglyNumber == nextMultipleOf3) {
                indexMultipleOf3++;
                nextMultipleOf3 = uglyNumbers[indexMultipleOf3] * 3;
            }
            if (nextUglyNumber == nextMultipleOf5) {
                indexMultipleOf5++;
                nextMultipleOf5 = uglyNumbers[indexMultipleOf5] * 5;
            }
        }

        return uglyNumbers[n - 1];  // Return the nth ugly number
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int nthUglyNumber(int n) {
        int[] uglyNumbers = new int[n]; // DP array to store ugly numbers
        uglyNumbers[0] = 1; // The first ugly number is 1

        // Three pointers for the multiples of 2, 3, and 5
        int indexMultipleOf2 = 0, indexMultipleOf3 = 0, indexMultipleOf5 = 0;
        int nextMultipleOf2 = 2, nextMultipleOf3 = 3, nextMultipleOf5 = 5;

        // Generate ugly numbers until we reach the nth one
        for (int i = 1; i < n; i++) {
            // Find the next ugly number as the minimum of the next multiples
            int nextUglyNumber = Math.min(
                nextMultipleOf2,
                Math.min(nextMultipleOf3, nextMultipleOf5)
            );
            uglyNumbers[i] = nextUglyNumber;

            // Update the corresponding pointer and next multiple
            if (nextUglyNumber == nextMultipleOf2) {
                indexMultipleOf2++;
                nextMultipleOf2 = uglyNumbers[indexMultipleOf2] * 2;
            }
            if (nextUglyNumber == nextMultipleOf3) {
                indexMultipleOf3++;
                nextMultipleOf3 = uglyNumbers[indexMultipleOf3] * 3;
            }
            if (nextUglyNumber == nextMultipleOf5) {
                indexMultipleOf5++;
                nextMultipleOf5 = uglyNumbers[indexMultipleOf5] * 5;
            }
        }

        return uglyNumbers[n - 1]; // Return the nth ugly number
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ugly_numbers = [0] * n  # DP array to store ugly numbers
        ugly_numbers[0] = 1  # The first ugly number is 1

        # Three pointers for the multiples of 2, 3, and 5
        index_multiple_of_2, index_multiple_of_3, index_multiple_of_5 = 0, 0, 0
        next_multiple_of_2, next_multiple_of_3, next_multiple_of_5 = 2, 3, 5

        # Generate ugly numbers until we reach the nth one
        for i in range(1, n):
            # Find the next ugly number as the minimum of the next multiples
            next_ugly_number = min(
                [next_multiple_of_2, next_multiple_of_3, next_multiple_of_5]
            )
            ugly_numbers[i] = next_ugly_number

            # Update the corresponding pointer and next multiple
            if next_ugly_number == next_multiple_of_2:
                index_multiple_of_2 += 1
                next_multiple_of_2 = ugly_numbers[index_multiple_of_2] * 2
            if next_ugly_number == next_multiple_of_3:
                index_multiple_of_3 += 1
                next_multiple_of_3 = ugly_numbers[index_multiple_of_3] * 3
            if next_ugly_number == next_multiple_of_5:
                index_multiple_of_5 += 1
                next_multiple_of_5 = ugly_numbers[index_multiple_of_5] * 5

        return ugly_numbers[n - 1]  # Return the nth ugly number
```

</details>
