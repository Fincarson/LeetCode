# 1295. Find Numbers with Even Number of Digits

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/find-numbers-with-even-number-of-digits/)  
`Array` `Math`

**Problem Link:** [LeetCode 1295 - Find Numbers with Even Number of Digits](https://leetcode.com/problems/find-numbers-with-even-number-of-digits/)

## Problem

Given an array nums of integers, return how many of them contain an even number of digits.

### Example 1

```text
Input: nums = [12,345,2,6,7896]
Output: 2
Explanation:
12 contains 2 digits (even number of digits).
345 contains 3 digits (odd number of digits).
2 contains 1 digit (odd number of digits).
6 contains 1 digit (odd number of digits).
7896 contains 4 digits (even number of digits).
Therefore only 12 and 7896 contain an even number of digits.
```

### Example 2

```text
Input: nums = [555,901,482,1771]
Output: 1
Explanation:
Only 1771 contains an even number of digits.
```

## Constraints

- 1 <= nums.length <= 500
- 1 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Finding 3-Digit Even Numbers](https://leetcode.com/problems/finding-3-digit-even-numbers/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Number of Even and Odd Bits](https://leetcode.com/problems/number-of-even-and-odd-bits/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find if Digit Game Can Be Won](https://leetcode.com/problems/find-if-digit-game-can-be-won/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1295. Find Numbers with Even Number of Digits

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Extract Digits | C, C++, Java, JavaScript, Python3 |
| Convert to String | C, C++, Java, JavaScript, Python3 |
| Using Logarithm | C, C++, Java, JavaScript, Python3 |
| Constraint Analysis | C, C++, Java, JavaScript, Python3 |

## Approach 1: Extract Digits

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Helper function to check if the number of digits is even
bool hasEvenDigits(int num) {
    int digitCount = 0;
    while (num) {
        digitCount++;
        num /= 10;
    }
    return (digitCount & 1) == 0;
}

int findNumbers(int* nums, int numsSize) {
    // Counter to count the number of even digit integers
    int evenDigitCount = 0;

    for (int i = 0; i < numsSize; i++) {
        if (hasEvenDigits(nums[i]))
            evenDigitCount++;
    }

    return evenDigitCount;
};
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Helper function to check if the number of digits is even
    bool hasEvenDigits(int num) {
        int digitCount = 0;
        while (num) {
            digitCount++;
            num /= 10;
        }
        return (digitCount & 1) == 0;
    }

    int findNumbers(vector<int>& nums) {
        // Counter to count the number of even digit integers
        int evenDigitCount = 0;

        for (int num : nums) {
            if (hasEvenDigits(num))
                evenDigitCount++;
        }

        return evenDigitCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Helper function to check if the number of digits is even
    private boolean hasEvenDigits(int num) {
        int digitCount = 0;
        while (num != 0) {
            digitCount++;
            num /= 10;
        }
        return (digitCount & 1) == 0;
    }

    public int findNumbers(int[] nums) {
        // Counter to count the number of even digit integers
        int evenDigitCount = 0;

        for (int num : nums) {
            if (hasEvenDigits(num))
                evenDigitCount++;
        }

        return evenDigitCount;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {number} num
 * @return {boolean}
 */
var hasEvenDigits = function(num) {
    let digitCount = 0;
    while (num) {
        digitCount++;
        num = Math.floor(num / 10);
    }
    return (digitCount & 1) == 0;
};

/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function(nums) {
    // Counter to count the number of even digit integers
    let evenDigitCount = 0;

    for (let num of nums) {
        if (hasEvenDigits(num))
            evenDigitCount++;
    }

    return evenDigitCount;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Helper function to check if the number of digits is even
    def hasEvenDigits(self, num: int) -> bool:
        digit_count = 0
        while num:
            digit_count += 1
            num //= 10
        return digit_count & 1 == 0

    def findNumbers(self, nums: List[int]) -> int:
        # Counter to count the number of even digit integers
        even_digit_count = 0

        for num in nums:
            if self.hasEvenDigits(num):
                even_digit_count += 1

        return even_digit_count
```

</details>

<br>

## Approach 2: Convert to String

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int findNumbers(int* nums, int numsSize) {
    // Counter to count the number of even digit integers
    int evenDigitCount = 0;

    for (int i = 0; i < numsSize; i++) {
        // Convert num to string and find its length
        int length = snprintf(NULL, 0, "%d", nums[i]);
        if (length % 2 == 0)
            evenDigitCount++;
    }

    return evenDigitCount;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        // Counter to count the number of even digit integers
        int evenDigitCount = 0;

        for (int num : nums) {
            // Convert num to string and find its length
            int length = to_string(num).length();
            if (length % 2 == 0)
                evenDigitCount++;
        }

        return evenDigitCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findNumbers(int[] nums) {
        // Counter to count the number of even digit integers
        int evenDigitCount = 0;

        for (int num : nums) {
            // Convert num to string and find its length
            int length = String.valueOf(num).length();
            if (length % 2 == 0)
                evenDigitCount++;
        }

        return evenDigitCount;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function(nums) {
    // Counter to count the number of even digit integers
    let evenDigitCount = 0;

    for (let num of nums) {
        // Convert num to string and find its length
        let length = num.toString().length;
        if (length % 2 == 0)
            evenDigitCount++;
    }

    return evenDigitCount;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        # Counter to count the number of even digit integers
        even_digit_count = 0

        for num in nums:
            # Convert num to string and find its length
            length = len(str(num))
            if length % 2 == 0:
                even_digit_count += 1

        return even_digit_count
```

</details>

<br>

## Approach 3: Using Logarithm

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int findNumbers(int* nums, int numsSize) {
    // Counter to count the number of even digit integers
    int evenDigitCount = 0;

    for (int i = 0; i < numsSize; i++) {
        // Compute the number of digits in the num
        int digitCount = (int) floor(log10(nums[i])) + 1;
        if (digitCount % 2 == 0)
            evenDigitCount++;
    }

    return evenDigitCount;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        // Counter to count the number of even digit integers
        int evenDigitCount = 0;

        for (int num : nums) {
            // Compute the number of digits in the num
            int digitCount = (int) floor(log10(num)) + 1;
            if (digitCount % 2 == 0)
                evenDigitCount++;
        }

        return evenDigitCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findNumbers(int[] nums) {
        // Counter to count the number of even digit integers
        int evenDigitCount = 0;

        for (int num : nums) {
            // Compute the number of digits in the num
            int digitCount = (int) Math.floor(Math.log10(num)) + 1;
            if (digitCount % 2 == 0)
                evenDigitCount++;
        }

        return evenDigitCount;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function(nums) {
    // Counter to count the number of even digit integers
    let evenDigitCount = 0;

    for (let num of nums) {
        // Compute the number of digits in the num
        let digitCount = Math.floor(Math.log10(num)) + 1;
        if (digitCount % 2 == 0)
            evenDigitCount++;
    }

    return evenDigitCount;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        # Counter to count the number of even digit integers
        even_digit_count = 0

        for num in nums:
            # Compute the number of digits in num
            digit_count = int(math.floor(math.log10(num))) + 1
            if digit_count % 2 == 0:
                even_digit_count += 1

        return even_digit_count
```

</details>

<br>

## Approach 4: Constraint Analysis

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int findNumbers(int* nums, int numsSize) {
    // Counter to count the number of even digit integers
    int evenDigitCount = 0;

    for (int i = 0; i < numsSize; i++) {
        if ((nums[i] >= 10 && nums[i] <= 99) || (nums[i] >= 1000 && nums[i] <= 9999)
        || nums[i] == 100000)
            evenDigitCount++;
    }

    return evenDigitCount;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        // Counter to count the number of even digit integers
        int evenDigitCount = 0;

        for (int num : nums) {
            if ((num >= 10 && num <= 99) || (num >= 1000 && num <= 9999) || num == 100000)
                evenDigitCount++;
        }

        return evenDigitCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findNumbers(int[] nums) {
        // Counter to count the number of even digit integers
        int evenDigitCount = 0;

        for (int num : nums) {
            if ((num >= 10 && num <= 99) || (num >= 1000 && num <= 9999) || num == 100000)
                evenDigitCount++;
        }

        return evenDigitCount;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function(nums) {
    // Counter to count the number of even digit integers
    let evenDigitCount = 0;

    for (let num of nums) {
        if ((num >= 10 && num <= 99) || (num >= 1000 && num <= 9999) || num == 100000)
            evenDigitCount++;
    }

    return evenDigitCount;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        # Counter to count the number of even digit integers
        even_digit_count = 0

        for num in nums:
            if (num >= 10 and num <= 99) or (num >= 1000 and num <= 9999)\
            or num == 100000:
                even_digit_count += 1

        return even_digit_count
```

</details>
