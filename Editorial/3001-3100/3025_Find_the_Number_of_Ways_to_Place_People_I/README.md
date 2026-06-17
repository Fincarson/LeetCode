# 3025. Find the Number of Ways to Place People I

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/)  
`Array` `Math` `Geometry` `Sorting` `Enumeration`

**Problem Link:** [LeetCode 3025 - Find the Number of Ways to Place People I](https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/)

## Problem

You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 2D plane, where points[i] = [xi, yi].

Count the number of pairs of points (A, B), where

- A is on the upper left side of B, and
- there are no other points in the rectangle (or line) they make (including the border), except for the points A and B.

Return the count.

### Example 1

### Example 2

### Example 3

## Constraints

- 2 <= n <= 50
- points[i].length == 2
- 0 <= points[i][0], points[i][1] <= 50
- All points[i] are distinct.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Rectangle Area](https://leetcode.com/problems/rectangle-area/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3025. Find the Number of Ways to Place People I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Triple Loop Enumeration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Sorting + Monotonic Scan | C++, Java, Python3 |

## Approach 1: Triple Loop Enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int numberOfPairs(int** points, int pointsSize, int* pointsColSizes) {
    int ans = 0;

    for (int i = 0; i < pointsSize; i++) {
        int* pointA = points[i];
        for (int j = 0; j < pointsSize; j++) {
            int* pointB = points[j];
            if (i == j || !(pointA[0] <= pointB[0] && pointA[1] >= pointB[1])) {
                continue;
            }
            if (pointsSize == 2) {
                ans++;
                continue;
            }

            int illegal = 0;
            for (int k = 0; k < pointsSize; k++) {
                if (k == i || k == j) {
                    continue;
                }

                int* pointTmp = points[k];
                int isXContained =
                    pointTmp[0] >= pointA[0] && pointTmp[0] <= pointB[0];
                int isYContained =
                    pointTmp[1] <= pointA[1] && pointTmp[1] >= pointB[1];
                if (isXContained && isYContained) {
                    illegal = 1;
                    break;
                }
            }
            if (!illegal) {
                ans++;
            }
        }
    }
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            auto& pointA = points[i];
            for (int j = 0; j < n; j++) {
                vector<int> pointB = points[j];
                if (i == j ||
                    !(pointA[0] <= pointB[0] && pointA[1] >= pointB[1])) {
                    continue;
                }
                if (n == 2) {
                    ans++;
                    continue;
                }

                bool illegal = false;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) {
                        continue;
                    }

                    auto& pointTmp = points[k];
                    bool isXContained =
                        pointTmp[0] >= pointA[0] && pointTmp[0] <= pointB[0];
                    bool isYContained =
                        pointTmp[1] <= pointA[1] && pointTmp[1] >= pointB[1];
                    if (isXContained && isYContained) {
                        illegal = true;
                        break;
                    }
                }
                if (!illegal) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int NumberOfPairs(int[][] points) {
        int ans = 0;
        int n = points.Length;

        for (int i = 0; i < n; i++) {
            int[] pointA = points[i];
            for (int j = 0; j < n; j++) {
                int[] pointB = points[j];
                if (i == j ||
                    !(pointA[0] <= pointB[0] && pointA[1] >= pointB[1])) {
                    continue;
                }
                if (n == 2) {
                    ans++;
                    continue;
                }

                bool illegal = false;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) {
                        continue;
                    }

                    int[] pointTmp = points[k];
                    bool isXContained =
                        pointTmp[0] >= pointA[0] && pointTmp[0] <= pointB[0];
                    bool isYContained =
                        pointTmp[1] <= pointA[1] && pointTmp[1] >= pointB[1];
                    if (isXContained && isYContained) {
                        illegal = true;
                        break;
                    }
                }
                if (!illegal) {
                    ans++;
                }
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func numberOfPairs(points [][]int) int {
    ans := 0
    n := len(points)

    for i := 0; i < n; i++ {
        pointA := points[i]
        for j := 0; j < n; j++ {
            pointB := points[j]
            if i == j || !(pointA[0] <= pointB[0] && pointA[1] >= pointB[1]) {
                continue
            }
            if n == 2 {
                ans++
                continue
            }

            illegal := false
            for k := 0; k < n; k++ {
                if k == i || k == j {
                    continue
                }

                pointTmp := points[k]
                isXContained := pointTmp[0] >= pointA[0] && pointTmp[0] <= pointB[0]
                isYContained := pointTmp[1] <= pointA[1] && pointTmp[1] >= pointB[1]
                if isXContained && isYContained {
                    illegal = true
                    break
                }
            }
            if !illegal {
                ans++
            }
        }
    }
    return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int numberOfPairs(int[][] points) {
        int ans = 0;
        int n = points.length;

        for (int i = 0; i < n; i++) {
            int[] pointA = points[i];
            for (int j = 0; j < n; j++) {
                int[] pointB = points[j];
                if (
                    i == j ||
                    !(pointA[0] <= pointB[0] && pointA[1] >= pointB[1])
                ) {
                    continue;
                }
                if (n == 2) {
                    ans++;
                    continue;
                }

                boolean illegal = false;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) {
                        continue;
                    }

                    int[] pointTmp = points[k];
                    boolean isXContained =
                        pointTmp[0] >= pointA[0] && pointTmp[0] <= pointB[0];
                    boolean isYContained =
                        pointTmp[1] <= pointA[1] && pointTmp[1] >= pointB[1];
                    if (isXContained && isYContained) {
                        illegal = true;
                        break;
                    }
                }
                if (!illegal) {
                    ans++;
                }
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numberOfPairs = function (points) {
    let ans = 0;
    let n = points.length;
    for (let i = 0; i < points.length; i++) {
        const pointA = points[i];
        for (let j = 0; j < points.length; j++) {
            const pointB = points[j];
            if (
                i === j ||
                !(pointA[0] <= pointB[0] && pointA[1] >= pointB[1])
            ) {
                continue;
            }

            if (points.length === 2) {
                ans++;
                continue;
            }

            let illegal = false;

            for (const pointTmp of points) {
                if (pointA === pointTmp || pointB === pointTmp) {
                    continue;
                }

                const isXContained =
                    pointTmp[0] >= pointA[0] && pointTmp[0] <= pointB[0];
                const isYContained =
                    pointTmp[1] <= pointA[1] && pointTmp[1] >= pointB[1];

                illegal = isXContained && isYContained;

                if (illegal) {
                    break;
                }
            }

            if (!illegal) {
                ans++;
            }
        }
    }

    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        ans = 0
        n = len(points)

        for i in range(n):
            pointA = points[i]
            for j in range(n):
                pointB = points[j]
                if i == j or not (
                    pointA[0] <= pointB[0] and pointA[1] >= pointB[1]
                ):
                    continue
                if n == 2:
                    ans += 1
                    continue

                illegal = False
                for k in range(n):
                    if k == i or k == j:
                        continue

                    pointTmp = points[k]
                    isXContained = (
                        pointTmp[0] >= pointA[0] and pointTmp[0] <= pointB[0]
                    )
                    isYContained = (
                        pointTmp[1] <= pointA[1] and pointTmp[1] >= pointB[1]
                    )
                    if isXContained and isYContained:
                        illegal = True
                        break
                if not illegal:
                    ans += 1
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function numberOfPairs(points: number[][]): number {
    let ans = 0;
    let n = points.length;
    for (let i = 0; i < points.length; i++) {
        const pointA = points[i];
        for (let j = 0; j < points.length; j++) {
            const pointB = points[j];
            if (
                i === j ||
                !(pointA[0] <= pointB[0] && pointA[1] >= pointB[1])
            ) {
                continue;
            }

            if (points.length === 2) {
                ans++;
                continue;
            }

            let illegal = false;

            for (const pointTmp of points) {
                if (pointA === pointTmp || pointB === pointTmp) {
                    continue;
                }

                const isXContained =
                    pointTmp[0] >= pointA[0] && pointTmp[0] <= pointB[0];
                const isYContained =
                    pointTmp[1] <= pointA[1] && pointTmp[1] >= pointB[1];

                illegal = isXContained && isYContained;

                if (illegal) {
                    break;
                }
            }

            if (!illegal) {
                ans++;
            }
        }
    }

    return ans;
}
```

</details>

<br>

## Approach 2: Sorting + Monotonic Scan

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // Sort by x ascending, and if tie, y descending
        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int n = points.size();
        int ans = 0;

        // Iterate over all left points
        for (int i = 0; i < n - 1; i++) {
            int pi2 = points[i][1];
            int minh = INT_MIN;

            // Check right-side points
            for (int j = i + 1; j < n; j++) {
                if (points[j][1] > minh && points[j][1] <= pi2) {
                    ans++;
                    minh = points[j][1];
                }
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int numberOfPairs(int[][] points) {
        // Sort by x ascending, and y descending
        Arrays.sort(points, (a, b) -> {
            if (a[0] == b[0]) return b[1] - a[1];
            return a[0] - b[0];
        });

        int n = points.length;
        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            int pi2 = points[i][1];
            int minh = Integer.MIN_VALUE;

            for (int j = i + 1; j < n; j++) {
                if (points[j][1] > minh && points[j][1] <= pi2) {
                    ans++;
                    minh = points[j][1];
                }
            }
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        # Sort points by x ascending, and for ties by y descending
        points.sort(key=lambda p: (p[0], -p[1]))

        n = len(points)
        ans = 0

        # For each left point
        for i in range(n - 1):
            pi2 = points[i][1]
            min_h = float("-inf")

            # Scan right-side points
            for j in range(i + 1, n):
                if points[j][1] > min_h and points[j][1] <= pi2:
                    ans += 1
                    min_h = points[j][1]

        return ans
```

</details>
