# 2579. Count Total Number of Colored Cells

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-total-number-of-colored-cells/)  
`Math`

**Problem Link:** [LeetCode 2579 - Count Total Number of Colored Cells](https://leetcode.com/problems/count-total-number-of-colored-cells/)

## Problem

There exists an infinitely large two-dimensional grid of uncolored unit cells. You are given a positive integer n, indicating that you must do the following routine for n minutes:

- At the first minute, color any arbitrary unit cell blue.
- Every minute thereafter, color blue every uncolored cell that touches a blue cell.

Below is a pictorial representation of the state of the grid after minutes 1, 2, and 3.

Return the number of colored cells at the end of n minutes.

### Example 1

```text
Input: n = 1
Output: 1
Explanation: After 1 minute, there is only 1 blue cell, so we return 1.
```

### Example 2

```text
Input: n = 2
Output: 5
Explanation: After 2 minutes, there are 4 colored cells on the boundary and 1 in the center, so we return 5.
```

## Constraints

- 1 <= n <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Cuts to Divide a Circle](https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2579. Count Total Number of Colored Cells

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iterative Addition | C++, Java, Python3 |
| Mathematical Formula | C++, Java, Python3 |

## Approach 1: Iterative Addition

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long coloredCells(int n) {
        long long numBlueCells = 1;
        int addend = 4;
        while (--n) {
            numBlueCells += addend;
            addend += 4;
        }
        return numBlueCells;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long coloredCells(int n) {
        long numBlueCells = 1;
        int addend = 4;

        // Iterate n - 1 times
        while (--n > 0) {
            // Add and update current multiple of 4
            numBlueCells += addend;
            addend += 4;
        }
        return numBlueCells;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def coloredCells(self, n: int) -> int:
        num_blue_cells = 1
        addend = 4

        # Iterate n - 1 times
        while n - 1:

            # Add and update current multiple of 4
            num_blue_cells += addend
            addend += 4
            n -= 1

        return num_blue_cells
```

</details>

<br>

## Approach 2: Mathematical Formula

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long coloredCells(int n) { return 1 + (long long)n * (n - 1) * 2; }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long coloredCells(int n) {
        return 1 + (long) n * (n - 1) * 2;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def coloredCells(self, n: int) -> int:
        return 1 + n * (n - 1) * 2
```

</details>
