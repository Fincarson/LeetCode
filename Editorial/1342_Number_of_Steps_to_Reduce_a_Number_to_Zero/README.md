# 1342. Number of Steps to Reduce a Number to Zero

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/)  
`Math` `Bit Manipulation`

**Problem Link:** [LeetCode 1342 - Number of Steps to Reduce a Number to Zero](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/)

## Problem

Given an integer num, return the number of steps to reduce it to zero.

In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.

### Example 1

```text
Input: num = 14
Output: 6
Explanation:
Step 1) 14 is even; divide by 2 and obtain 7.
Step 2) 7 is odd; subtract 1 and obtain 6.
Step 3) 6 is even; divide by 2 and obtain 3.
Step 4) 3 is odd; subtract 1 and obtain 2.
Step 5) 2 is even; divide by 2 and obtain 1.
Step 6) 1 is odd; subtract 1 and obtain 0.
```

### Example 2

```text
Input: num = 8
Output: 4
Explanation:
Step 1) 8 is even; divide by 2 and obtain 4.
Step 2) 4 is even; divide by 2 and obtain 2.
Step 3) 2 is even; divide by 2 and obtain 1.
Step 4) 1 is odd; subtract 1 and obtain 0.
```

### Example 3

```text
Input: num = 123
Output: 12
```

## Constraints

- 0 <= num <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Moves to Reach Target Score](https://leetcode.com/problems/minimum-moves-to-reach-target-score/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count Operations to Obtain Zero](https://leetcode.com/problems/count-operations-to-obtain-zero/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1342. Number of Steps to Reduce a Number to Zero

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulation | C++, Java, Python3 |
| Counting Bits | Java |
| Counting Bits with Bitwise Operators | Java, Python3 |

## Approach 1: Simulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;
        while (num != 0) {
            if (num % 2 == 0) {
                num = num / 2;
            } else {
                num = num - 1;
            }
            steps = steps + 1;
        }
        return steps;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public int numberOfSteps(int num) {
    int steps = 0; // We need to keep track of how many steps this takes.
    while (num != 0) { // Remember, we're taking steps until num is 0.
        if (num % 2 == 0) { // Modulus operator tells us num is *even*.
            num = num / 2; // So we divide num by 2.
        } else { // Otherwise, num must be *odd*.
            num = num - 1; // So we subtract 1 from num.
        }
        steps = steps + 1; // We *always* increment steps by 1.
    }
    return steps; // And at the end, the answer is in steps so we return it.
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfSteps(self, num: int) -> int:
        count = 0
        while num != 0:
            if num % 2 == 0:
                num /= 2
            else:
                num -= 1
            count += 1
        return count
```

</details>

<br>

## Approach 2: Counting Bits

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public int numberOfSteps(int num) {
    // Get the binary for num, as a String.
    String binaryString = Integer.toBinaryString(num);

    int steps = 0;
    // Iterate over all the bits in the binary string.
    for (char bit : binaryString.toCharArray()) {
        if (bit == '1') { // If the bit is a 1
            steps = steps + 2; // Then it'll take 2 to remove.
        } else { // bit == '0'
            steps = steps + 1; // Then it'll take 1 to remove.
        }
    }

    // We need to subtract 1, because the last bit was over-counted.
    return steps - 1;
}
```

</details>

<br>

## Approach 3: Counting Bits with Bitwise Operators

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public int numberOfSteps(int num) {
    // We need to handle this as a special case, otherwise it'll return -1.
    if (num == 0) return 0;

    int steps = 0;

    for (int powerOfTwo = 1; powerOfTwo <= num; powerOfTwo = powerOfTwo * 2) {
        // Apply the bit mask to check if the bit at "powerOfTwo" is a 1.
        if ((powerOfTwo & num) != 0) {
            steps = steps + 2;
        } else {
            steps = steps + 1;
        }
    }

    // We need to subtract 1, because the last bit was over-counted.
    return steps - 1;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfSteps(self, num: int) -> int:
        if num == 0:
            return 0

        steps = 0
        powerOfTwo = 1
        while powerOfTwo <= num:
            if (powerOfTwo & num) != 0:
                steps = steps + 2
            else:
                steps = steps + 1
            powerOfTwo = powerOfTwo * 2

        return steps - 1
```

</details>
