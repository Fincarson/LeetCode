# 386. Lexicographical Numbers

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/lexicographical-numbers/)  
`Depth-First Search` `Trie`

**Problem Link:** [LeetCode 386 - Lexicographical Numbers](https://leetcode.com/problems/lexicographical-numbers/)

## Problem

Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space.

### Example 1

```text
Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
```

### Example 2

```text
Input: n = 2
Output: [1,2]
```

## Constraints

- 1 <= n <= 5 * 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 386. Lexicographical Numbers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| DFS Approach | C++, Java, Python3 |
| Iterative Approach | C++, Java, Python3 |

## Approach 1: DFS Approach

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexicographicalNumbers;
        // Start generating numbers from 1 to 9
        for (int start = 1; start <= 9; ++start) {
            generateLexicalNumbers(start, n, lexicographicalNumbers);
        }
        return lexicographicalNumbers;
    }

private:
    void generateLexicalNumbers(int currentNumber, int limit,
                                vector<int>& result) {
        // If the current number exceeds the limit, stop recursion
        if (currentNumber > limit) return;

        // Add the current number to the result
        result.push_back(currentNumber);

        // Try to append digits from 0 to 9 to the current number
        for (int nextDigit = 0; nextDigit <= 9; ++nextDigit) {
            int nextNumber = currentNumber * 10 + nextDigit;
            // If the next number is within the limit, continue recursion
            if (nextNumber <= limit) {
                generateLexicalNumbers(nextNumber, limit, result);
            } else {
                break;  // No need to continue if nextNumber exceeds limit
            }
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public List<Integer> lexicalOrder(int n) {
        List<Integer> lexicographicalNumbers = new ArrayList<>();
        // Start generating numbers from 1 to 9
        for (int start = 1; start <= 9; ++start) {
            generateLexicalNumbers(start, n, lexicographicalNumbers);
        }
        return lexicographicalNumbers;
    }

    private void generateLexicalNumbers(
        int currentNumber,
        int limit,
        List<Integer> result
    ) {
        // If the current number exceeds the limit, stop recursion
        if (currentNumber > limit) return;

        // Add the current number to the result
        result.add(currentNumber);

        // Try to append digits from 0 to 9 to the current number
        for (int nextDigit = 0; nextDigit <= 9; ++nextDigit) {
            int nextNumber = currentNumber * 10 + nextDigit;
            // If the next number is within the limit, continue recursion
            if (nextNumber <= limit) {
                generateLexicalNumbers(nextNumber, limit, result);
            } else {
                break; // No need to continue if nextNumber exceeds limit
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        lexicographical_numbers = []
        # Start generating numbers from 1 to 9
        for start in range(1, 10):
            self._generate_lexical_numbers(start, n, lexicographical_numbers)
        return lexicographical_numbers

    def _generate_lexical_numbers(
        self, current_number: int, limit: int, result: List[int]
    ):
        # If the current number exceeds the limit, stop recursion
        if current_number > limit:
            return
        # Add the current number to the result
        result.append(current_number)

        # Try to append digits from 0 to 9 to the current number
        for next_digit in range(10):
            next_number = current_number * 10 + next_digit
            # If the next number is within the limit, continue recursion
            if next_number <= limit:
                self._generate_lexical_numbers(next_number, limit, result)
            else:
                break  # No need to continue if next_number exceeds limit
```

</details>

<br>

## Approach 2: Iterative Approach

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexicographicalNumbers;
        int currentNumber = 1;

        // Generate numbers from 1 to n
        for (int i = 0; i < n; ++i) {
            lexicographicalNumbers.push_back(currentNumber);

            // If multiplying the current number by 10 is within the limit, do
            // it
            if (currentNumber * 10 <= n) {
                currentNumber *= 10;
            } else {
                // Adjust the current number by moving up one digit
                while (currentNumber % 10 == 9 || currentNumber >= n) {
                    currentNumber /= 10;  // Remove the last digit
                }
                currentNumber += 1;  // Increment the number
            }
        }

        return lexicographicalNumbers;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> lexicalOrder(int n) {
        List<Integer> lexicographicalNumbers = new ArrayList<>();
        int currentNumber = 1;

        // Generate numbers from 1 to n
        for (int i = 0; i < n; ++i) {
            lexicographicalNumbers.add(currentNumber);

            // If multiplying the current number by 10 is within the limit, do it
            if (currentNumber * 10 <= n) {
                currentNumber *= 10;
            } else {
                // Adjust the current number by moving up one digit
                while (currentNumber % 10 == 9 || currentNumber >= n) {
                    currentNumber /= 10; // Remove the last digit
                }
                currentNumber += 1; // Increment the number
            }
        }

        return lexicographicalNumbers;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        lexicographical_numbers = []
        current_number = 1

        # Generate numbers from 1 to n
        for _ in range(n):
            lexicographical_numbers.append(current_number)

            # If multiplying the current number by 10 is within the limit, do it
            if current_number * 10 <= n:
                current_number *= 10
            else:
                # Adjust the current number by moving up one digit
                while current_number % 10 == 9 or current_number >= n:
                    current_number //= 10  # Remove the last digit
                current_number += 1  # Increment the number

        return lexicographical_numbers
```

</details>
