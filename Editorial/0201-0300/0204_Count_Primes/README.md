# 204. Count Primes

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/count-primes/)  
`Array` `Math` `Enumeration` `Number Theory`

**Problem Link:** [LeetCode 204 - Count Primes](https://leetcode.com/problems/count-primes/)

## Problem

Given an integer n, return the number of prime numbers that are strictly less than n.

### Example 1

```text
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
```

### Example 2

```text
Input: n = 0
Output: 0
```

### Example 3

```text
Input: n = 1
Output: 0
```

## Constraints

- 0 <= n <= 5 * 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Ugly Number](https://leetcode.com/problems/ugly-number/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Ugly Number II](https://leetcode.com/problems/ugly-number-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Perfect Squares](https://leetcode.com/problems/perfect-squares/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Number of Common Factors](https://leetcode.com/problems/number-of-common-factors/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Prime Pairs With Target Sum](https://leetcode.com/problems/prime-pairs-with-target-sum/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find the Count of Numbers Which Are Not Special](https://leetcode.com/problems/find-the-count-of-numbers-which-are-not-special/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 204. Count Primes

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sieve of Eratosthenes | C++, Java, Python3 |

## Approach: Sieve of Eratosthenes

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        vector<bool> numbers(n, true);  // Initialize vector with n true values
        for (int p = 2; p <= sqrt(n); ++p) {
            if (numbers[p]) {
                for (int j = p * p; j < n; j += p) {
                    numbers[j] = false;
                }
            }
        }

        int numberOfPrimes = 0;
        for (int i = 2; i < n; i++) {
            if (numbers[i]) {
                ++numberOfPrimes;
            }
        }

        return numberOfPrimes;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        boolean[] numbers = new boolean[n];
        for (int p = 2; p <= (int) Math.sqrt(n); ++p) {
            if (numbers[p] == false) {
                for (int j = p * p; j < n; j += p) {
                    numbers[j] = true;
                }
            }
        }

        int numberOfPrimes = 0;
        for (int i = 2; i < n; i++) {
            if (numbers[i] == false) {
                ++numberOfPrimes;
            }
        }

        return numberOfPrimes;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 2:
            return 0

        # Initialize numbers[0] and numbers[1] as False because 0 and 1 are not prime.
        # Initialze numbers[2] through numbers[n-1] as True because we assume each number
        # is prime until we find a prime number (p) that is a divisor of the number
        numbers = [False, False] + [True] * (n - 2)
        for p in range(2, int(sqrt(n)) + 1):
            if numbers[p]:
                # Set all multiples of p to false because they are not prime.
                for multiple in range(p * p, n, p):
                    numbers[multiple] = False

        # numbers[index] will only be true where index is a prime number
        # return the number of indices whose value is true.
        return sum(numbers)
```

</details>
