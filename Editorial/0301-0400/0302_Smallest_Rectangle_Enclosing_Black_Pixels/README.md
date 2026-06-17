# 302. Smallest Rectangle Enclosing Black Pixels

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/)  
`Array` `Binary Search` `Depth-First Search` `Breadth-First Search` `Matrix`

**Problem Link:** [LeetCode 302 - Smallest Rectangle Enclosing Black Pixels](https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/)

## Problem

You are given an m x n binary matrix image where 0 represents a white pixel and 1 represents a black pixel.

The black pixels are connected (i.e., there is only one black region). Pixels are connected horizontally and vertically.

Given two integers x and y that represents the location of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

You must write an algorithm with less than O(mn) runtime complexity

### Example 1

```text
Input: image = [["0","0","1","0"],["0","1","1","0"],["0","1","0","0"]], x = 0, y = 2
Output: 6
```

### Example 2

```text
Input: image = [["1"]], x = 0, y = 0
Output: 1
```

## Constraints

- m == image.length
- n == image[i].length
- 1 <= m, n <= 100
- image[i][j] is either '0' or '1'.
- 0 <= x < m
- 0 <= y < n
- image[x][y] == '1'.
- The black pixels in the image only form one component.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find the Minimum Area to Cover All Ones II](https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Find the Minimum Area to Cover All Ones I](https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 302. Smallest Rectangle Enclosing Black Pixels

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Naive Linear Search | Java |
| DFS or BFS | Java |
| Binary Search | Java |

## Approach 1: Naive Linear Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int minArea(char[][] image, int x, int y) {
        int top = x, bottom = x;
        int left = y, right = y;
        for (x = 0; x < image.length; ++x) {
            for (y = 0; y < image[0].length; ++y) {
                if (image[x][y] == '1') {
                    top = Math.min(top, x);
                    bottom = Math.max(bottom, x + 1);
                    left = Math.min(left, y);
                    right = Math.max(right, y + 1);
                }
            }
        }
        return (right - left) * (bottom - top);
    }
}
```

</details>

<br>

## Approach 2: DFS or BFS

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    private int top, bottom, left, right;
    public int minArea(char[][] image, int x, int y) {
        if(image.length == 0 || image[0].length == 0) return 0;
        top = bottom = x;
        left = right = y;
        dfs(image, x, y);
        return (right - left) * (bottom - top);
    }
    private void dfs(char[][] image, int x, int y){
        if(x < 0 || y < 0 || x >= image.length || y >= image[0].length ||
          image[x][y] == '0')
            return;
        image[x][y] = '0'; // mark visited black pixel as white
        top = Math.min(top, x);
        bottom = Math.max(bottom, x + 1);
        left = Math.min(left, y);
        right = Math.max(right, y + 1);
        dfs(image, x + 1, y);
        dfs(image, x - 1, y);
        dfs(image, x, y - 1);
        dfs(image, x, y + 1);
    }
}
```

</details>

<br>

## Approach 3: Binary Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int minArea(char[][] image, int x, int y) {
        int m = image.length, n = image[0].length;
        int left = searchColumns(image, 0, y, 0, m, true);
        int right = searchColumns(image, y + 1, n, 0, m, false);
        int top = searchRows(image, 0, x, left, right, true);
        int bottom = searchRows(image, x + 1, m, left, right, false);
        return (right - left) * (bottom - top);
    }
    private int searchColumns(char[][] image, int i, int j, int top, int bottom, boolean whiteToBlack) {
        while (i != j) {
            int k = top, mid = (i + j) / 2;
            while (k < bottom && image[k][mid] == '0') ++k;
            if (k < bottom == whiteToBlack) // k < bottom means the column mid has black pixel
                j = mid; //search the boundary in the smaller half
            else
                i = mid + 1; //search the boundary in the greater half
        }
        return i;
    }
    private int searchRows(char[][] image, int i, int j, int left, int right, boolean whiteToBlack) {
        while (i != j) {
            int k = left, mid = (i + j) / 2;
            while (k < right && image[mid][k] == '0') ++k;
            if (k < right == whiteToBlack) // k < right means the row mid has black pixel
                j = mid;
            else
                i = mid + 1;
        }
        return i;
    }
}
```

</details>
