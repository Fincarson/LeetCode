# 2523. Closest Prime Numbers in Range

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/closest-prime-numbers-in-range/)  
`Math` `Number Theory`

**Problem Link:** [LeetCode 2523 - Closest Prime Numbers in Range](https://leetcode.com/problems/closest-prime-numbers-in-range/)

## Problem

Given two positive integers left and right, find the two integers num1 and num2 such that:

- left <= num1 < num2 <= right .
- Both num1 and num2 are prime numbers.
- num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.

Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].

### Example 1

```text
Input: left = 10, right = 19
Output: [11,13]
Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
Since 11 is smaller than 17, we return the first pair.
```

### Example 2

```text
Input: left = 4, right = 6
Output: [-1,-1]
Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.
```

## Constraints

- 1 <= left <= right <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Ways to Make Array With Product](https://leetcode.com/problems/count-ways-to-make-array-with-product/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2523. Closest Prime Numbers in Range

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sieve of Eratosthenes | C++, Java, Python3 |
| Analyze Distance between twin primes | C++, Java, Python3 |

## Approach 1: Sieve of Eratosthenes

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int upperLimit = right;
        // Step 1: Get all prime numbers up to 'right' using sieve
        vector<int> sieveArray = sieve(upperLimit);

        vector<int>
            primeNumbers;  // Store all primes in the range [left, right]
        for (int num = left; num <= right; num++) {
            // If number is prime add to the primeNumbers list
            if (sieveArray[num] == 1) {
                primeNumbers.push_back(num);
            }
        }

        // Step 2: Find the closest prime pair
        if (primeNumbers.size() < 2)
            return vector<int>{-1, -1};  // Less than two primes available

        int minDifference = INT_MAX;
        vector<int> closestPair(2, -1);  // setting initial values

        for (int index = 1; index < primeNumbers.size(); index++) {
            int difference = primeNumbers[index] - primeNumbers[index - 1];
            if (difference < minDifference) {
                minDifference = difference;
                closestPair[0] = primeNumbers[index - 1];
                closestPair[1] = primeNumbers[index];
            }
        }

        return closestPair;
    }

private:
    vector<int> sieve(int upperLimit) {
        // Initiate an int array to mark prime numbers
        vector<int> sieve(upperLimit + 1,
                          1);  // Assuming all numbers as prime initially

        // 0 and 1 are not prime
        sieve[0] = 0;
        sieve[1] = 0;

        for (int number = 2; number * number <= upperLimit; number++) {
            if (sieve[number] == 1) {
                // Mark all multiples of 'number' as non-prime
                for (int multiple = number * number; multiple <= upperLimit;
                     multiple += number) {
                    sieve[multiple] = 0;
                }
            }
        }
        return sieve;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] closestPrimes(int left, int right) {
        // Step 1: Get all prime numbers up to 'right' using sieve
        int[] sieveArray = sieve(right);

        List<Integer> primeNumbers = new ArrayList<>(); // Store all primes in the range [left, right]
        for (int num = left; num <= right; num++) {
            // If number is prime add to the primeNumbers list
            if (sieveArray[num] == 1) {
                primeNumbers.add(num);
            }
        }

        // Step 2: Find the closest prime pair
        if (primeNumbers.size() < 2) return new int[] { -1, -1 }; // Less than two primes available

        int minDifference = Integer.MAX_VALUE;
        int[] closestPair = new int[2];
        // setting initial values
        Arrays.fill(closestPair, -1);

        for (int index = 1; index < primeNumbers.size(); index++) {
            int difference =
                primeNumbers.get(index) - primeNumbers.get(index - 1);
            if (difference < minDifference) {
                minDifference = difference;
                closestPair[0] = primeNumbers.get(index - 1);
                closestPair[1] = primeNumbers.get(index);
            }
        }

        return closestPair;
    }

    private int[] sieve(int upperLimit) {
        // Initiate an int array to mark prime numbers (1 = prime, else it's not)
        int[] sieve = new int[upperLimit + 1];
        // Assuming all numbers as prime initially
        Arrays.fill(sieve, 1);

        // 0 and 1 are not prime
        sieve[0] = 0;
        sieve[1] = 0;

        for (int number = 2; number * number <= upperLimit; number++) {
            if (sieve[number] == 1) {
                // Mark all multiples of 'number' as non-prime
                for (
                    int multiple = number * number;
                    multiple <= upperLimit;
                    multiple += number
                ) {
                    sieve[multiple] = 0;
                }
            }
        }
        return sieve;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def _sieve(self, upper_limit):
        # Create an integer list to mark prime numbers (True = prime, False = not prime)
        sieve = [True] * (upper_limit + 1)
        sieve[0] = sieve[1] = False  # 0 and 1 are not prime

        for number in range(2, int(upper_limit**0.5) + 1):
            if sieve[number]:
                # Mark all multiples of 'number' as non-prime
                for multiple in range(number * number, upper_limit + 1, number):
                    sieve[multiple] = False
        return sieve

    def closestPrimes(self, left, right):
        # Step 1: Get all prime numbers up to 'right' using sieve
        sieve_array = self._sieve(right)

        prime_numbers = [
            num for num in range(left, right + 1) if sieve_array[num]
        ]

        # Step 2: Find the closest prime pair
        if len(prime_numbers) < 2:
            return -1, -1  # Less than two primes

        min_difference = float("inf")
        closest_pair = (-1, -1)

        for index in range(1, len(prime_numbers)):
            difference = prime_numbers[index] - prime_numbers[index - 1]
            if difference < min_difference:
                min_difference = difference
                closest_pair = prime_numbers[index - 1], prime_numbers[index]

        return closest_pair
```

</details>

<br>

## Approach 2: Analyze Distance between twin primes

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // Step 1: Handle special (2, 3) case
        if (left <= 2 && right >= 3)
            return {2, 3};

        int prevPrime = -1, closestA = -1, closestB = -1;
        int minDifference = 1e6;

        // Step 2: Iterate and find primes
        for (int candidate = left; candidate <= right; candidate++) {
            if (isPrime(candidate)) {
                if (prevPrime != -1) {
                    int difference = candidate - prevPrime;
                    if (difference < minDifference) {
                        minDifference = difference;
                        closestA = prevPrime;
                        closestB = candidate;
                    }
                    // Twin prime optimization
                    if (difference == 2)
                        return {prevPrime, candidate};
                }
                prevPrime = candidate;
            }
        }

        // Step 3: Return result
        return {closestA, closestB};
    }

private:
    bool isPrime(int number) {
        if (number < 2) return false;
        if (number == 2 || number == 3) return true;
        if (number % 2 == 0) return false;
        for (int divisor = 3; divisor * divisor <= number; divisor += 2) {
            if (number % divisor == 0) return false;
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] closestPrimes(int left, int right) {
        // Step 1: Handle special (2, 3) case
        if (left <= 2 && right >= 3)
            return new int[] {2, 3};

        int prevPrime = -1, closestA = -1, closestB = -1;
        int minDifference = (int) 1e6;

        // Step 2: Iterate and find primes
        for (int candidate = left; candidate <= right; candidate++) {
            if (isPrime(candidate)) {
                if (prevPrime != -1) {
                    int difference = candidate - prevPrime;
                    if (difference < minDifference) {
                        minDifference = difference;
                        closestA = prevPrime;
                        closestB = candidate;
                    }
                    // Twin prime optimization
                    if (difference == 2)
                        return new int[] {prevPrime, candidate};
                }
                prevPrime = candidate;
            }
        }

        // Step 3: Return result
        return new int[] {closestA, closestB};
    }

    private boolean isPrime(int number) {
        if (number < 2) return false;
        if (number == 2 || number == 3) return true;
        if (number % 2 == 0) return false;
        for (int divisor = 3; divisor * divisor <= number; divisor += 2) {
            if (number % divisor == 0) return false;
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isPrime(self, num):
        if num < 2:
            return False
        if num == 2 or num == 3:
            return True
        if num % 2 == 0:
            return False
        divisor = 3
        while divisor * divisor <= num:
            if num % divisor == 0:
                return False
            divisor += 2
        return True

    def closestPrimes(self, left, right):
        # Step 1: Handle special (2, 3) case
        if left <= 2 and right >= 3:
            return [2, 3]

        prev_prime = -1
        closestA = -1
        closestB = -1
        min_difference = float("inf")

        # Step 2: Iterate and find primes
        for candidate in range(left, right + 1):
            if self.isPrime(candidate):
                if prev_prime != -1:
                    difference = candidate - prev_prime
                    if difference < min_difference:
                        min_difference = difference
                        closestA = prev_prime
                        closestB = candidate
                    # Twin prime optimization
                    if difference == 2:
                        return [prev_prime, candidate]
                prev_prime = candidate

        # Step 3: Return result
        return [closestA, closestB]
```

</details>
