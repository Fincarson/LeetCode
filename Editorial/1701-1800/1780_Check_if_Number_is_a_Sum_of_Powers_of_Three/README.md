# 1780. Check if Number is a Sum of Powers of Three

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/)  
`Math`

**Problem Link:** [LeetCode 1780 - Check if Number is a Sum of Powers of Three](https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/)

## Problem

Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3x.

### Example 1

```text
Input: n = 12
Output: true
Explanation: 12 = 31 + 32
```

### Example 2

```text
Input: n = 91
Output: true
Explanation: 91 = 30 + 32 + 34
```

### Example 3

```text
Input: n = 21
Output: false
```

## Constraints

- 1 <= n <= 107

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Power of Three](https://leetcode.com/problems/power-of-three/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1780. Check if Number is a Sum of Powers of Three

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking (Brute Force) | C++, Java, Python3 |
| Optimized Iterative Approach | C++, Java, Python3 |
| Ternary Representation | C++, Java, Python3 |

## Approach 1: Backtracking (Brute Force)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool checkPowersOfThree(int n) { return checkPowersOfThreeHelper(0, n); }

private:
    bool checkPowersOfThreeHelper(int power, int n) {
        // Base case: if n becomes 0, we have successfully formed the sum
        if (n == 0) return true;

        // If the current power of 3 exceeds n, we can't use it, so return false
        if (pow(3, power) > n) return false;

        // Option 1: Include the current power of 3 and subtract it from n
        bool addPower = checkPowersOfThreeHelper(power + 1, n - pow(3, power));

        // Option 2: Skip the current power of 3 and try with the next power
        bool skipPower = checkPowersOfThreeHelper(power + 1, n);

        // Return true if either option leads to a valid solution
        return addPower || skipPower;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean checkPowersOfThree(int n) {
        return checkPowersOfThreeHelper(0, n);
    }

    private boolean checkPowersOfThreeHelper(int power, int n) {
        // Base case: if n becomes 0, we have successfully formed the sum
        if (n == 0) return true;

        // If the current power of 3 exceeds n, we can't use it, so return false
        if (Math.pow(3, power) > n) return false;

        // Option 1: Include the current power of 3 and subtract it from n
        boolean addPower = checkPowersOfThreeHelper(
            power + 1,
            n - (int) Math.pow(3, power)
        );

        // Option 2: Skip the current power of 3 and try with the next power
        boolean skipPower = checkPowersOfThreeHelper(power + 1, n);

        // Return true if either option leads to a valid solution
        return addPower || skipPower;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        return self._check_powers_of_three_helper(0, n)

    def _check_powers_of_three_helper(self, power: int, n: int) -> bool:
        # Base case: if n becomes 0, we have successfully formed the sum
        if n == 0:
            return True

        # If the current power of 3 exceeds n, we can't use it, so return false
        if 3**power > n:
            return False

        # Option 1: Include the current power of 3 and subtract it from n
        add_power = self._check_powers_of_three_helper(power + 1, n - 3**power)

        # Option 2: Skip the current power of 3 and try with the next power
        skip_power = self._check_powers_of_three_helper(power + 1, n)

        # Return true if either option leads to a valid solution
        return add_power or skip_power
```

</details>

<br>

## Approach 2: Optimized Iterative Approach

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool checkPowersOfThree(int n) {
        int power = 0;

        // Find the largest power that is smaller or equal to n
        while (pow(3, power) <= n) {
            power++;
        }

        while (n > 0) {
            // Add current power to the sum
            if (n >= pow(3, power)) n -= pow(3, power);
            // We cannot use the same power twice
            if (n >= pow(3, power)) return false;
            // Move to the next power
            power--;
        }

        // n has reached 0
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean checkPowersOfThree(int n) {
        int power = 0;

        // Find the largest power that is smaller or equal to n
        while (Math.pow(3, power) <= n) {
            power++;
        }

        while (n > 0) {
            // Subtract current power from n
            if (n >= Math.pow(3, power)) {
                n -= (int) Math.pow(3, power);
            }
            // We cannot use the same power twice
            if (n >= Math.pow(3, power)) {
                return false;
            }
            // Move to the next lower power
            power--;
        }

        // n has reached 0
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        power = 0

        # Find the largest power that is smaller or equal to n
        while 3**power <= n:
            power += 1

        while n > 0:
            # Subtract current power from n
            if n >= 3**power:
                n -= 3**power
            # We cannot use the same power twice
            if n >= 3**power:
                return False
            # Move to the next lower power
            power -= 1

        # n has reached 0
        return True
```

</details>

<br>

## Approach 3: Ternary Representation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            // Check if this power should be used twice
            if (n % 3 == 2) return false;

            // Divide n by 3 to move to the next greater power
            n /= 3;
        }

        // The ternary representation of n consists only of 0s and 1s
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean checkPowersOfThree(int n) {
        while (n > 0) {
            // Check if this power should be used twice
            if (n % 3 == 2) {
                return false;
            }
            // Divide n by 3 to move to the next greater power
            n /= 3;
        }
        // The ternary representation of n consists only of 0s and 1s
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        while n > 0:
            # Check if this power should be used twice
            if n % 3 == 2:
                return False
            # Divide n by 3 to move to the next greater power
            n //= 3
        # The ternary representation of n consists only of 0s and 1s
        return True
```

</details>
