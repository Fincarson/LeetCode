# 3047. Find the Largest Area of Square Inside Two Rectangles

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/)  
`Array` `Math` `Geometry`

**Problem Link:** [LeetCode 3047 - Find the Largest Area of Square Inside Two Rectangles](https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/)

## Problem

There exist n rectangles in a 2D plane with edges parallel to the x and y axis. You are given two 2D integer arrays bottomLeft and topRight where bottomLeft[i] = [a_i, b_i] and topRight[i] = [c_i, d_i] represent the bottom-left and top-right coordinates of the ith rectangle, respectively.

You need to find the maximum area of a square that can fit inside the intersecting region of at least two rectangles. Return 0 if such a square does not exist.

### Example 1

Input: bottomLeft = [[1,1],[2,2],[3,1]], topRight = [[3,3],[4,4],[6,6]]

Output: 1

Explanation:

A square with side length 1 can fit inside either the intersecting region of rectangles 0 and 1 or the intersecting region of rectangles 1 and 2. Hence the maximum area is 1. It can be shown that a square with a greater side length can not fit inside any intersecting region of two rectangles.

### Example 2

Input: bottomLeft = [[1,1],[1,3],[1,5]], topRight = [[5,5],[5,7],[5,9]]

Output: 4

Explanation:

A square with side length 2 can fit inside either the intersecting region of rectangles 0 and 1 or the intersecting region of rectangles 1 and 2. Hence the maximum area is 2 * 2 = 4. It can be shown that a square with a greater side length can not fit inside any intersecting region of two rectangles.

### Example 3

Input: bottomLeft = [[1,1],[2,2],[1,2]], topRight = [[3,3],[4,4],[3,4]]

Output: 1

Explanation:

A square with side length 1 can fit inside the intersecting region of any two rectangles. Also, no larger square can, so the maximum area is 1. Note that the region can be formed by the intersection of more than 2 rectangles.

### Example 4

Input: bottomLeft = [[1,1],[3,3],[3,1]], topRight = [[2,2],[4,4],[4,2]]

Output: 0

Explanation:

No pair of rectangles intersect, hence, the answer is 0.

## Constraints

- n == bottomLeft.length == topRight.length
- 2 <= n <= 103
- bottomLeft[i].length == topRight[i].length == 2
- 1 <= bottomLeft[i][0], bottomLeft[i][1] <= 107
- 1 <= topRight[i][0], topRight[i][1] <= 107
- bottomLeft[i][0] < topRight[i][0]
- bottomLeft[i][1] < topRight[i][1]

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Rectangle Area](https://leetcode.com/problems/rectangle-area/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3047. Find the Largest Area of Square Inside Two Rectangles

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Traversal + Computational Geometry | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Traversal + Computational Geometry

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
long long largestSquareArea(int** bottomLeft, int bottomLeftSize,
                            int* bottomLeftColSize, int** topRight,
                            int topRightSize, int* topRightColSize) {
    int n = bottomLeftSize;
    long long maxSide = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int w = fmin(topRight[i][0], topRight[j][0]) -
                    fmax(bottomLeft[i][0], bottomLeft[j][0]);
            int h = fmin(topRight[i][1], topRight[j][1]) -
                    fmax(bottomLeft[i][1], bottomLeft[j][1]);
            if (w > 0 && h > 0) {
                int side = fmin(w, h);
                if ((long long)side > maxSide) {
                    maxSide = (long long)side;
                }
            }
        }
    }

    return maxSide * maxSide;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        int maxSide = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int w = min(topRight[i][0], topRight[j][0]) -
                        max(bottomLeft[i][0], bottomLeft[j][0]);
                int h = min(topRight[i][1], topRight[j][1]) -
                        max(bottomLeft[i][1], bottomLeft[j][1]);

                maxSide = max(maxSide, min(w, h));
            }
        }

        return 1LL * maxSide * maxSide;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public long LargestSquareArea(int[][] bottomLeft, int[][] topRight) {
        int n = bottomLeft.Length;
        long maxSide = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int w = Math.Min(topRight[i][0], topRight[j][0]) -
                        Math.Max(bottomLeft[i][0], bottomLeft[j][0]);
                int h = Math.Min(topRight[i][1], topRight[j][1]) -
                        Math.Max(bottomLeft[i][1], bottomLeft[j][1]);

                maxSide = Math.Max(maxSide, Math.Min(w, h));
            }
        }

        return maxSide * maxSide;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func largestSquareArea(bottomLeft [][]int, topRight [][]int) int64 {
    n := len(bottomLeft)
    var maxSide int64 = 0

    for i := 0; i < n; i++ {
        for j := i + 1; j < n; j++ {
            w := min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0])
            h := min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1])
            
            if w > 0 && h > 0 {
                side := min(w, h)
                if int64(side) > maxSide {
                    maxSide = int64(side)
                }
            }
        }
    }

    return maxSide * maxSide
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long largestSquareArea(int[][] bottomLeft, int[][] topRight) {
        int n = bottomLeft.length;
        long maxSide = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int w =
                    Math.min(topRight[i][0], topRight[j][0]) -
                    Math.max(bottomLeft[i][0], bottomLeft[j][0]);
                int h =
                    Math.min(topRight[i][1], topRight[j][1]) -
                    Math.max(bottomLeft[i][1], bottomLeft[j][1]);
                int side = Math.min(w, h);

                maxSide = Math.max(maxSide, side);
            }
        }

        return maxSide * maxSide;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var largestSquareArea = function (bottomLeft, topRight) {
    const n = bottomLeft.length;
    let maxSide = 0;

    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            const w =
                Math.min(topRight[i][0], topRight[j][0]) -
                Math.max(bottomLeft[i][0], bottomLeft[j][0]);
            const h =
                Math.min(topRight[i][1], topRight[j][1]) -
                Math.max(bottomLeft[i][1], bottomLeft[j][1]);

            maxSide = Math.max(maxSide, Math.min(w, h));
        }
    }

    return maxSide * maxSide;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestSquareArea(
        self, bottomLeft: List[List[int]], topRight: List[List[int]]
    ) -> int:
        max_size = 0

        for (bottom_left_i, top_right_i), (
            bottom_left_j,
            top_right_j,
        ) in combinations(zip(bottomLeft, topRight), 2):
            w = min(top_right_i[0], top_right_j[0]) - max(
                bottom_left_i[0], bottom_left_j[0]
            )
            h = min(top_right_i[1], top_right_j[1]) - max(
                bottom_left_i[1], bottom_left_j[1]
            )

            max_size = max(max_size, min(w, h))

        return max_size * max_size
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function largestSquareArea(
    bottomLeft: number[][],
    topRight: number[][],
): number {
    const n = bottomLeft.length;
    let maxSide = 0;

    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            const w =
                Math.min(topRight[i][0], topRight[j][0]) -
                Math.max(bottomLeft[i][0], bottomLeft[j][0]);
            const h =
                Math.min(topRight[i][1], topRight[j][1]) -
                Math.max(bottomLeft[i][1], bottomLeft[j][1]);

            maxSide = Math.max(maxSide, Math.min(w, h));
        }
    }

    return maxSide * maxSide;
}
```

</details>
