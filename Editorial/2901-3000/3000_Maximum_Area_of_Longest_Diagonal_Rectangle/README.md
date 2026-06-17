# 3000. Maximum Area of Longest Diagonal Rectangle

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/)  
`Array`

**Problem Link:** [LeetCode 3000 - Maximum Area of Longest Diagonal Rectangle](https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/)

## Problem

You are given a 2D 0-indexed integer array dimensions.

For all indices i, 0 <= i < dimensions.length, dimensions[i][0] represents the length and dimensions[i][1] represents the width of the rectangle i.

Return the area of the rectangle having the longest diagonal. If there are multiple rectangles with the longest diagonal, return the area of the rectangle having the maximum area.

### Example 1

```text
Input: dimensions = [[9,3],[8,6]]
Output: 48
Explanation:
For index = 0, length = 9 and width = 3. Diagonal length = sqrt(9 * 9 + 3 * 3) = sqrt(90) Ã¢â€°Ë† 9.487.
For index = 1, length = 8 and width = 6. Diagonal length = sqrt(8 * 8 + 6 * 6) = sqrt(100) = 10.
So, the rectangle at index 1 has a greater diagonal length therefore we return area = 8 * 6 = 48.
```

### Example 2

```text
Input: dimensions = [[3,4],[4,3]]
Output: 12
Explanation: Length of diagonal is the same for both which is 5, so maximum area = 12.
```

## Constraints

- 1 <= dimensions.length <= 100
- dimensions[i].length == 2
- 1 <= dimensions[i][0], dimensions[i][1] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3000. Maximum Area of Longest Diagonal Rectangle

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Enumeration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int areaOfMaxDiagonal(int** dimensions, int dimensionsSize,
                      int* dimensionsColSize) {
    int maxDiaSq = 0;
    int maxArea = 0;
    for (int i = 0; i < dimensionsSize; i++) {
        int l = dimensions[i][0];
        int w = dimensions[i][1];
        int diaSq = l * l + w * w;
        int area = l * w;
        if (diaSq > maxDiaSq) {
            maxDiaSq = diaSq;
            maxArea = area;
        } else if (diaSq == maxDiaSq) {
            if (area > maxArea) {
                maxArea = area;
            }
        }
    }
    return maxArea;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiaSq = 0, maxArea = 0;
        for (const auto& dim : dimensions) {
            int l = dim[0], w = dim[1];
            int diaSq = l * l + w * w, area = l * w;
            if (diaSq > maxDiaSq) {
                maxDiaSq = diaSq;
                maxArea = area;
            } else if (diaSq == maxDiaSq) {
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int AreaOfMaxDiagonal(int[][] dimensions) {
        int maxDiaSq = 0;
        int maxArea = 0;
        foreach (var dim in dimensions) {
            int l = dim[0];
            int w = dim[1];
            int diaSq = l * l + w * w;
            int area = l * w;
            if (diaSq > maxDiaSq) {
                maxDiaSq = diaSq;
                maxArea = area;
            } else if (diaSq == maxDiaSq) {
                maxArea = Math.Max(maxArea, area);
            }
        }
        return maxArea;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func areaOfMaxDiagonal(dimensions [][]int) int {
	maxDiaSq := 0
	maxArea := 0
	for _, dim := range dimensions {
		l := dim[0]
		w := dim[1]
		diaSq := l*l + w*w
		area := l * w
		if diaSq > maxDiaSq {
			maxDiaSq = diaSq
			maxArea = area
		} else if diaSq == maxDiaSq {
			if area > maxArea {
				maxArea = area
			}
		}
	}
	return maxArea
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int areaOfMaxDiagonal(int[][] dimensions) {
        int maxDiaSq = 0;
        int maxArea = 0;
        for (int[] dim : dimensions) {
            int l = dim[0];
            int w = dim[1];
            int diaSq = l * l + w * w;
            int area = l * w;
            if (diaSq > maxDiaSq) {
                maxDiaSq = diaSq;
                maxArea = area;
            } else if (diaSq == maxDiaSq) {
                maxArea = Math.max(maxArea, area);
            }
        }
        return maxArea;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var areaOfMaxDiagonal = function (dimensions) {
    let maxDiaSq = 0;
    let maxArea = 0;
    for (const dim of dimensions) {
        const l = dim[0];
        const w = dim[1];
        const diaSq = l * l + w * w;
        const area = l * w;
        if (diaSq > maxDiaSq) {
            maxDiaSq = diaSq;
            maxArea = area;
        } else if (diaSq === maxDiaSq) {
            maxArea = Math.max(maxArea, area);
        }
    }
    return maxArea;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        max_dia_sq = 0
        max_area = 0
        for l, w in dimensions:
            dia_sq = l * l + w * w
            area = l * w
            if dia_sq > max_dia_sq:
                max_dia_sq = dia_sq
                max_area = area
            elif dia_sq == max_dia_sq:
                max_area = max(max_area, area)
        return max_area
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function areaOfMaxDiagonal(dimensions: number[][]): number {
    let maxDiaSq = 0;
    let maxArea = 0;
    for (const dim of dimensions) {
        const l = dim[0];
        const w = dim[1];
        const diaSq = l * l + w * w;
        const area = l * w;
        if (diaSq > maxDiaSq) {
            maxDiaSq = diaSq;
            maxArea = area;
        } else if (diaSq === maxDiaSq) {
            maxArea = Math.max(maxArea, area);
        }
    }
    return maxArea;
}
```

</details>
