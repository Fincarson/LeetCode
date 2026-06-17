# 2601. Prime Subtraction Operation

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/prime-subtraction-operation/)  
`Array` `Math` `Binary Search` `Greedy` `Number Theory`

**Problem Link:** [LeetCode 2601 - Prime Subtraction Operation](https://leetcode.com/problems/prime-subtraction-operation/)

## Problem

You are given a 0-indexed integer array nums of length n.

You can perform the following operation as many times as you want:

- Pick an index i that you havenÃ¢â‚¬â„¢t picked before, and pick a prime p strictly less than nums[i], then subtract p from nums[i].

Return true if you can make nums a strictly increasing array using the above operation and false otherwise.

A strictly increasing array is an array whose each element is strictly greater than its preceding element.

### Example 1

```text
Input: nums = [4,9,6,10]
Output: true
Explanation: In the first operation: Pick i = 0 and p = 3, and then subtract 3 from nums[0], so that nums becomes [1,9,6,10].
In the second operation: i = 1, p = 7, subtract 7 from nums[1], so nums becomes equal to [1,2,6,10].
After the second operation, nums is sorted in strictly increasing order, so the answer is true.
```

### Example 2

```text
Input: nums = [6,8,11,12]
Output: true
Explanation: Initially nums is sorted in strictly increasing order, so we don't need to make any operations.
```

### Example 3

```text
Input: nums = [5,8,3]
Output: false
Explanation: It can be proven that there is no way to perform operations to make nums sorted in strictly increasing order, so the answer is false.
```

## Constraints

- 1 <= nums.length <= 1000
- 1 <= nums[i] <= 1000
- nums.length == n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2601. Prime Subtraction Operation

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Storing the primes | C++, Java, Python3 |
| Sieve of Eratosthenes + Two Pointers | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool checkPrime(int x) {
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) {
                return 0;
            }
        }
        return 1;
    }
    bool primeSubOperation(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int bound;
            // In case of first index, we need to find the largest prime less
            // than nums[0].
            if (i == 0) {
                bound = nums[0];
            } else {
                // Otherwise, we need to find the largest prime, that makes the
                // current element closest to the previous element.
                bound = nums[i] - nums[i - 1];
            }

            // If the bound is less than or equal to 0, then the array cannot be
            // made strictly increasing.
            if (bound <= 0) {
                return 0;
            }

            // Find the largest prime less than bound.
            int largestPrime = 0;
            for (int j = bound - 1; j >= 2; j--) {
                if (checkPrime(j)) {
                    largestPrime = j;
                    break;
                }
            }

            // Subtract this value from nums[i].
            nums[i] = nums[i] - largestPrime;
        }
        return 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public boolean checkPrime(int x) {
        for (int i = 2; i <= Math.sqrt(x); i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    public boolean primeSubOperation(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            int bound;
            // In case of first index, we need to find the largest prime less than nums[0].
            if (i == 0) {
                bound = nums[0];
            } else {
                // Otherwise, we need to find the largest prime, that makes the current element closest to the previous element.
                bound = nums[i] - nums[i - 1];
            }

            // If the bound is less than or equal to 0, then the array cannot be made strictly increasing.
            if (bound <= 0) {
                return false;
            }

            // Find the largest prime less than bound.
            int largestPrime = 0;
            for (int j = bound - 1; j >= 2; j--) {
                if (checkPrime(j)) {
                    largestPrime = j;
                    break;
                }
            }

            // Subtract this value from nums[i].
            nums[i] = nums[i] - largestPrime;
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
    def check_prime(self, x: int) -> bool:
        for i in range(2, int(x**0.5) + 1):
            if x % i == 0:
                return False
        return True

    def primeSubOperation(self, nums: List[int]) -> bool:
        for i in range(len(nums)):
            # In case of first index, we need to find the largest prime less than nums[0].
            if i == 0:
                bound = nums[0]
            else:
                # Otherwise, we need to find the largest prime, that makes the current element
                # closest to the previous element.
                bound = nums[i] - nums[i - 1]

            # If the bound is less than or equal to 0, then the array cannot be made strictly increasing.
            if bound <= 0:
                return False

            # Find the largest prime less than bound.
            largest_prime = 0
            for j in range(bound - 1, 1, -1):
                if self.check_prime(j):
                    largest_prime = j
                    break

            # Subtract this value from nums[i].
            nums[i] = nums[i] - largest_prime
        return True
```

</details>

<br>

## Approach 2: Storing the primes

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool checkPrime(int x) {
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) {
                return 0;
            }
        }
        return 1;
    }
    bool primeSubOperation(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());

        // Store the previousPrime array.
        vector<int> previousPrime(maxElement + 1, 0);
        for (int i = 2; i <= maxElement; i++) {
            if (checkPrime(i)) {
                previousPrime[i] = i;
            } else {
                previousPrime[i] = previousPrime[i - 1];
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            int bound;
            // In case of first index, we need to find the largest prime less
            // than nums[0].
            if (i == 0) {
                bound = nums[0];
            } else {
                // Otherwise, we need to find the largest prime, that makes the
                // current element closest to the previous element.
                bound = nums[i] - nums[i - 1];
            }

            // If the bound is less than or equal to 0, then the array cannot be
            // made strictly increasing.
            if (bound <= 0) {
                return 0;
            }

            // Find the largest prime less than bound.
            int largestPrime = previousPrime[bound - 1];

            // Subtract this value from nums[i].
            nums[i] = nums[i] - largestPrime;
        }
        return 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean isPrime(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    public boolean primeSubOperation(int[] nums) {
        int maxElement = Integer.MIN_VALUE;
        for (int num : nums) {
            maxElement = Math.max(maxElement, num);
        }

        // Store the previousPrime array.
        int[] previousPrime = new int[maxElement + 1];
        for (int i = 2; i <= maxElement; i++) {
            if (isPrime(i)) {
                previousPrime[i] = i;
            } else {
                previousPrime[i] = previousPrime[i - 1];
            }
        }

        for (int i = 0; i < nums.length; i++) {
            int bound;
            // In case of first index, we need to find the largest prime less
            // than nums[0].
            if (i == 0) {
                bound = nums[0];
            } else {
                // Otherwise, we need to find the largest prime, that makes the
                // current element closest to the previous element.
                bound = nums[i] - nums[i - 1];
            }

            // If the bound is less than or equal to 0, then the array cannot be
            // made strictly increasing.
            if (bound <= 0) {
                return false;
            }

            // Find the largest prime less than bound.
            int largestPrime = previousPrime[bound - 1];

            // Subtract this value from nums[i].
            nums[i] -= largestPrime;
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
    def isprime(self, n):
        for i in range(2, isqrt(n) + 1):
            if n % i == 0:
                return False
        return True

    def primeSubOperation(self, nums):
        maxElement = max(nums)

        # Store the previousPrime array.
        previous_prime = [0] * (maxElement + 1)
        for i in range(2, maxElement + 1):
            if self.isprime(i):
                previous_prime[i] = i
            else:
                previous_prime[i] = previous_prime[i - 1]

        for i in range(len(nums)):

            # In case of first index, we need to find the largest prime less
            # than nums[0].
            if i == 0:
                bound = nums[0]
            else:
                # Otherwise, we need to find the largest prime, that makes the
                # current element closest to the previous element.
                bound = nums[i] - nums[i - 1]

            # If the bound is less than or equal to 0, then the array cannot be
            # made strictly increasing.
            if bound <= 0:
                return False

            # Find the largest prime less than bound.
            largest_prime = previous_prime[bound - 1]

            # Subtract this value from nums[i].
            nums[i] -= largest_prime

        return True
```

</details>

<br>

## Approach 3: Sieve of Eratosthenes + Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());

        // Store the sieve array.
        vector<int> sieve(maxElement + 1, 1);
        sieve[1] = 0;
        for (int i = 2; i <= sqrt(maxElement + 1); i++) {
            if (sieve[i] == 1) {
                for (int j = i * i; j <= maxElement; j += i) {
                    sieve[j] = 0;
                }
            }
        }

        // Start by storing the currValue as 1, and the initial index as 0.
        int currValue = 1;
        int i = 0;
        while (i < nums.size()) {
            // Store the difference needed to make nums[i] equal to currValue.
            int difference = nums[i] - currValue;

            // If difference is less than 0, then nums[i] is already less than
            // currValue. Return false in this case.
            if (difference < 0) {
                return 0;
            }

            // If the difference is prime or zero, then nums[i] can be made
            // equal to currValue.
            if (sieve[difference] == 1 or difference == 0) {
                i++;
                currValue++;
            } else {
                // Otherwise, try for the next currValue.
                currValue++;
            }
        }
        return 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean primeSubOperation(int[] nums) {
        int maxElement = getMaxElement(nums);

        // Store the sieve array.
        boolean[] sieve = new boolean[maxElement + 1];
        fill(sieve, true);
        sieve[1] = false;
        for (int i = 2; i <= Math.sqrt(maxElement + 1); i++) {
            if (sieve[i]) {
                for (int j = i * i; j <= maxElement; j += i) {
                    sieve[j] = false;
                }
            }
        }

        // Start by storing the currValue as 1, and the initial index as 0.
        int currValue = 1;
        int i = 0;
        while (i < nums.length) {
            // Store the difference needed to make nums[i] equal to currValue.
            int difference = nums[i] - currValue;

            // If difference is less than 0, then nums[i] is already less than
            // currValue. Return false in this case.
            if (difference < 0) {
                return false;
            }

            // If the difference is prime or zero, then nums[i] can be made
            // equal to currValue.
            if (sieve[difference] == true || difference == 0) {
                i++;
                currValue++;
            } else {
                // Otherwise, try for the next currValue.
                currValue++;
            }
        }
        return true;
    }

    private int getMaxElement(int[] nums) {
        int max = -1;
        for (int num : nums) {
            if (num > max) {
                max = num;
            }
        }
        return max;
    }

    private void fill(boolean[] arr, boolean value) {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = value;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def primeSubOperation(self, nums):
        max_element = max(nums)

        # Store the sieve array.
        sieve = [1] * (max_element + 1)
        sieve[1] = 0
        for i in range(2, int(math.sqrt(max_element + 1)) + 1):
            if sieve[i] == 1:
                for j in range(i * i, max_element + 1, i):
                    sieve[j] = 0

        # Start by storing the currValue as 1, and the initial index as 0.
        curr_value = 1
        i = 0
        while i < len(nums):
            # Store the difference needed to make nums[i] equal to currValue.
            difference = nums[i] - curr_value

            # If difference is less than 0, then nums[i] is already less than
            # currValue. Return false in this case.
            if difference < 0:
                return False

            # If the difference is prime or zero, then nums[i] can be made
            # equal to currValue.
            if sieve[difference] or difference == 0:
                i += 1
                curr_value += 1
            else:
                # Otherwise, try for the next currValue.
                curr_value += 1
        return True
```

</details>
