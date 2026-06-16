# 832. Flipping an Image

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/flipping-an-image/)  
`Array` `Two Pointers` `Bit Manipulation` `Matrix` `Simulation`

**Problem Link:** [LeetCode 832 - Flipping an Image](https://leetcode.com/problems/flipping-an-image/)

## Problem

Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.

- For example, flipping [1,1,0] horizontally results in [0,1,1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.

- For example, inverting [0,1,1] results in [1,0,0].

### Example 1

```text
Input: image = [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
```

### Example 2

```text
Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
```

## Constraints

- n == image.length
- n == image[i].length
- 1 <= n <= 20
- images[i][j] is either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 832. Flipping an Image

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Direct [Accepted] | Java, Python |

## Approach #1: Direct [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        int C = A[0].length;
        for (int[] row: A)
            for (int i = 0; i < (C + 1) / 2; ++i) {
                int tmp = row[i] ^ 1;
                row[i] = row[C - 1 - i] ^ 1;
                row[C - 1 - i] = tmp;
            }

        return A;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def flipAndInvertImage(self, A):
        for row in A:
            for i in xrange((len(row) + 1) / 2):
                """
                In Python, the shortcut row[~i] = row[-i-1] = row[len(row) - 1 - i]
                helps us find the i-th value of the row, counting from the right.
                """
                row[i], row[~i] = row[~i] ^ 1, row[i] ^ 1
        return A
```

</details>
