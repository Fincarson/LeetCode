# 2485. Find the Pivot Integer

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/find-the-pivot-integer/)  
`Math` `Prefix Sum`

**Problem Link:** [LeetCode 2485 - Find the Pivot Integer](https://leetcode.com/problems/find-the-pivot-integer/)

## Problem

Given a positive integer n, find the pivot integer x such that:

- The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.

Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.

### Example 1

```text
Input: n = 8
Output: 6
Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.
```

### Example 2

```text
Input: n = 1
Output: 1
Explanation: 1 is the pivot integer since: 1 = 1.
```

### Example 3

```text
Input: n = 4
Output: -1
Explanation: It can be proved that no such integer exist.
```

## Constraints

- 1 <= n <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Bulb Switcher](https://leetcode.com/problems/bulb-switcher/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2485. Find the Pivot Integer

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Two Pointer | C++, Java, Python3 |
| Binary Search | C++, Java, Python3 |
| Pre-Compute and Cache in a Lookup Table | C++, Java, Python3 |
| Using Math | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int pivotInteger(int n) {
        // Iterate through possible pivot values
        for (int i = 1; i <= n; i++) {
            int sumLeft = 0;
            int sumRight = 0;

            // Calculate the sum of elements on the left side of the pivot
            for (int j = 1; j <= i; j++) {
                sumLeft += j;
            }

            // Calculate the sum of elements on the right side of the pivot
            for (int k = i; k <= n; k++) {
                sumRight += k;
            }

            // Check if the sums on both sides are equal
            if (sumLeft == sumRight) {
                return i; // Return the pivot value if found
            }
        }

        return -1; // Return -1 if no pivot is found
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int pivotInteger(int n) {
        // Iterate through possible pivot values
        for (int i = 1; i <= n; i++) {
            int sumLeft = 0;
            int sumRight = 0;

            // Calculate the sum of elements on the left side of the pivot
            for (int j = 1; j <= i; j++) {
                sumLeft += j;
            }

            // Calculate the sum of elements on the right side of the pivot
            for (int k = i; k <= n; k++) {
                sumRight += k;
            }

            // Check if the sums on both sides are equal
            if (sumLeft == sumRight) {
                return i; // Return the pivot value if found
            }
        }

        return -1; // Return -1 if no pivot is found
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def pivotInteger(self, n: int) -> int:
        # Iterate through possible pivot values
        for i in range(1, n + 1):
            # Calculate the sum of elements on the left side of the pivot
            sum_left = sum(range(1, i + 1)) 
            # Calculate the sum of elements on the right side of the pivot
            sum_right = sum(range(i, n + 1)) 

            # Check if the sums on both sides are equal
            if sum_left == sum_right:
                return i  # Return the pivot value if found

        return -1  # Return -1 if no pivot is found
```

</details>

<br>

## Approach 2: Two Pointer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int pivotInteger(int n) {
        int leftValue = 1;
        int rightValue = n;
        int sumLeft = leftValue;
        int sumRight = rightValue;

        if (n == 1) return n;
        
        // Iterate until the pointers meet
        while (leftValue < rightValue) {
            // Adjust sums and pointers based on comparison
            if (sumLeft < sumRight) {
                sumLeft += ++leftValue;
            } else {
                sumRight += --rightValue;
            }

            // Check for pivot condition
            if (sumLeft == sumRight && leftValue + 1 == rightValue - 1) {
                return leftValue + 1;
            }
        }

        return -1; // Return -1 if no pivot is found
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int pivotInteger(int n) {
        int leftValue = 1;
        int rightValue = n;
        int sumLeft = leftValue;
        int sumRight = rightValue;

        if (n == 1) return n;

        // Iterate until the pointers meet
        while (leftValue < rightValue) {
            // Adjust sums and pointers based on comparison
            if (sumLeft < sumRight) {
                sumLeft += ++leftValue;
            } else {
                sumRight += --rightValue;
            }

            // Check for pivot condition
            if (sumLeft == sumRight && leftValue + 1 == rightValue - 1) {
                return leftValue + 1;
            }
        }

        return -1; // Return -1 if no pivot is found
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def pivotInteger(self, n: int) -> int:
        left_value = 1
        right_value = n
        sum_left = left_value
        sum_right = right_value

        if n == 1:
            return n

        # Iterate until the pointers meet
        while left_value < right_value:
            # Adjust sums and pointers based on comparison
            if sum_left < sum_right:
                sum_left += left_value + 1
                left_value += 1
            else:
                sum_right += right_value - 1
                right_value -= 1

            # Check for pivot condition
            if sum_left == sum_right and left_value + 1 == right_value - 1:
                return left_value + 1

        return -1  # Return -1 if no pivot is found
```

</details>

<br>

## Approach 3: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int pivotInteger(int n) {
        // Initialize left and right pointers for binary search
        int left = 1, right = n;
        
        // Calculate the total sum of the sequence
        int totalSum = n * (n + 1) / 2;

        // Binary search for the pivot point
        while (left < right) {
            // Calculate the mid-point
            int mid = (left + right) / 2;

            // Check if the difference between the square of mid and the total sum is negative
            if (mid * mid - totalSum < 0) {
                left = mid + 1; // Adjust the left bound if the sum is smaller
            } else {
                right = mid; // Adjust the right bound if the sum is equal or greater
            }
        }

        // Check if the square of the left pointer minus the total sum is zero
        if (left * left - totalSum == 0) {
            return left;
        } else {
            return -1;
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int pivotInteger(int n) {
        // Initialize left and right pointers for binary search
        int left = 1, right = n;
        
        // Calculate the total sum of the sequence
        int totalSum = n * (n + 1) / 2;

        // Binary search for the pivot point
        while (left < right) {
            // Calculate the mid-point
            int mid = (left + right) / 2;

            // Check if the difference between the square of mid and the total sum is negative
            if (mid * mid - totalSum < 0) {
                left = mid + 1; // Adjust the left bound if the sum is smaller
            } else {
                right = mid; // Adjust the right bound if the sum is equal or greater
            }
        }

        // Check if the square of the left pointer minus the total sum is zero
        if (left * left - totalSum == 0) {
            return left;
        } else {
            return -1;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def pivotInteger(self, n: int) -> int:
        # Initialize left and right pointers for binary search
        left, right = 1, n
        
        # Calculate the total sum of the sequence
        total_sum = n * (n + 1) // 2

        # Binary search for the pivot point
        while left < right:
            # Calculate the mid-point
            mid = (left + right) // 2

            # Check if the difference between the square of mid and the total sum is negative
            if mid * mid - total_sum < 0:
                left = mid + 1  # Adjust the left bound if the sum is smaller
            else:
                right = mid  # Adjust the right bound if the sum is equal or greater

        # Check if the square of the left pointer minus the total sum is zero
        if left * left - total_sum == 0:
            return left
        else:
            return -1
```

</details>

<br>

## Approach 4: Pre-Compute and Cache in a Lookup Table

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
const int maxValue = 1000;
// Array to store precomputed pivot values
int precompute[maxValue + 1] = {0}; // Initializing to 0

class Solution {
public:
    int pivotInteger(int n) {
        // Check if precompute array is not initialized
        if (precompute[1] == 0) {
            for (int i = 1, j = 1; i <= maxValue; ++i) {
                int sum = i * (i + 1) / 2;

                // Find the first square greater than or equal to sum
                while (j * j < sum) {
                    ++j;
                }

                // Check if j * j is equal to sum (pivot found), otherwise set to -1
                precompute[i] = j * j == sum ? j : -1;
            }
        }

        return precompute[n];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    private static final int maxValue = 1000;
    // Array to store precomputed pivot values
    private static int[] precompute = new int[maxValue + 1];

    public int pivotInteger(int n) {
        // Initializing to 0
        for (int i = 0; i <= maxValue; i++) {
            precompute[i] = 0;
        }

        // Check if precompute array is not initialized
        if (precompute[1] == 0) {
            for (int i = 1, j = 1; i <= maxValue; ++i) {
                int sum = i * (i + 1) / 2;

                // Find the first square greater than or equal to sum
                while (j * j < sum) {
                    ++j;
                }

                // Check if j * j is equal to sum (pivot found), otherwise set to -1
                precompute[i] = j * j == sum ? j : -1;
            }
        }

        return precompute[n];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    maxValue = 1000
    # Array to store precomputed pivot values
    precompute = [0] * (maxValue + 1) # Initializing to 0

    def pivotInteger(self, n: int) -> int:
        # Check if precompute array is not initialized
        if self.precompute[1] == 0:
            for i in range(1, self.maxValue + 1):
                sum_val = i * (i + 1) // 2

                j = 1
                # Find the first square greater than or equal to sum
                while j * j < sum_val:
                    j += 1

                # Check if j * j is equal to sum (pivot found), otherwise set to -1
                self.precompute[i] = j if j * j == sum_val else -1

        return self.precompute[n]
```

</details>

<br>

## Approach 5: Using Math

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
 public:
  int pivotInteger(int n) {
        const int sum = (n * (n + 1) / 2);
        const int pivot = sqrt(sum);
        // If pivot * pivot is equal to sum (pivot found) return pivot, else return -1
        return pivot * pivot == sum ? pivot : -1;
  }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int pivotInteger(int n) {
        final int sum = (n * (n + 1) / 2);
        final int pivot = (int) Math.sqrt(sum);
        // If pivot * pivot is equal to sum (pivot found) return pivot, else return -1
        return pivot * pivot == sum ? pivot : -1;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
  def pivotInteger(self, n: int) -> int:
        sum = (n * (n + 1) // 2)
        pivot = int(math.sqrt(sum))
        # If pivot * pivot is equal to sum (pivot found) return pivot, else return -1
        return pivot if pivot * pivot == sum else -1
```

</details>
