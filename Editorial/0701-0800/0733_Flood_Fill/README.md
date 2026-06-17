# 733. Flood Fill

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/flood-fill/)  
`Array` `Depth-First Search` `Breadth-First Search` `Matrix`

**Problem Link:** [LeetCode 733 - Flood Fill](https://leetcode.com/problems/flood-fill/)

## Problem

You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Return the modified image after performing the flood fill.

### Example 1

### Example 2

## Constraints

- m == image.length
- n == image[i].length
- 1 <= m, n <= 50
- 0 <= image[i][j], color < 216
- 0 <= sr < m
- 0 <= sc < n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Island Perimeter](https://leetcode.com/problems/island-perimeter/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 733. Flood Fill

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Depth-First Search [Accepted] | Java, Python |

## Approach #1: Depth-First Search [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color != newColor) {
            dfs(image, sr, sc, color, newColor);
        }
        return image;
    }
    public void dfs(int[][] image, int r, int c, int color, int newColor) {
        if (image[r][c] == color) {
            image[r][c] = newColor;
            if (r >= 1) {
                dfs(image, r - 1, c, color, newColor);
            }
            if (c >= 1) {
                dfs(image, r, c - 1, color, newColor);
            }
            if (r + 1 < image.length) {
                dfs(image, r + 1, c, color, newColor);
            }
            if (c + 1 < image[0].length) {
                dfs(image, r, c + 1, color, newColor);
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def floodFill(self, image, sr, sc, newColor):
        R, C = len(image), len(image[0])
        color = image[sr][sc]
        if color == newColor:
            return image
        def dfs(r, c):
            if image[r][c] == color:
                image[r][c] = newColor
                if r >= 1:
                    dfs(r-1, c)
                if r + 1 < R:
                    dfs(r + 1, c)
                if c >= 1:
                    dfs(r, c - 1)
                if c + 1 < C:
                    dfs(r, c + 1)

        dfs(sr, sc)
        return image
```

</details>
