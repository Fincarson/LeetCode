# 85. Maximal Rectangle

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/maximal-rectangle/)  
`Array` `Dynamic Programming` `Stack` `Matrix` `Monotonic Stack`

**Problem Link:** [LeetCode 85 - Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)

## Problem

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

### Example 1

```text
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
```

### Example 2

```text
Input: matrix = [["0"]]
Output: 0
```

### Example 3

```text
Input: matrix = [["1"]]
Output: 1
```

## Constraints

- rows == matrix.length
- cols == matrix[i].length
- 1 <= rows, cols <= 200
- matrix[i][j] is '0' or '1'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Maximal Square](https://leetcode.com/problems/maximal-square/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find Sorted Submatrices With Maximum Element at Most K](https://leetcode.com/problems/find-sorted-submatrices-with-maximum-element-at-most-k/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 85. Maximal Rectangle

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming - Better Brute Force on Histograms | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Using Histograms - Stack | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Dynamic Programming - Maximum Height at Each Point | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 2: Dynamic Programming - Better Brute Force on Histograms

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0) return 0;
    int maxarea = 0;
    int dp[matrixSize][*matrixColSize];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (matrix[i][j] == '1') {
                // compute the maximum width and update dp with it
                dp[i][j] = j == 0 ? 1 : dp[i][j - 1] + 1;
                int width = dp[i][j];
                // compute the maximum area rectangle with a lower right corner
                // at [i, j]
                for (int k = i; k >= 0; k--) {
                    width = width < dp[k][j] ? width : dp[k][j];
                    maxarea = maxarea > (width * (i - k + 1))
                                  ? maxarea
                                  : (width * (i - k + 1));
                }
            }
        }
    }
    return maxarea;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int maxarea = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    // compute the maximum width and update dp with it
                    dp[i][j] = j == 0 ? 1 : dp[i][j - 1] + 1;
                    int width = dp[i][j];
                    // compute the maximum area rectangle with a lower right
                    // corner at [i, j]
                    for (int k = i; k >= 0; k--) {
                        width = std::min(width, dp[k][j]);
                        maxarea = std::max(maxarea, width * (i - k + 1));
                    }
                }
            }
        }
        return maxarea;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaximalRectangle(char[][] matrix) {
        if (matrix.Length == 0)
            return 0;
        int maxarea = 0;
        int[][] dp = new int [matrix.Length][];
        for (int a = 0; a < dp.Length; a++) dp[a] = new int[matrix[0].Length];
        for (int i = 0; i < matrix.Length; i++) {
            for (int j = 0; j < matrix[0].Length; j++) {
                if (matrix[i][j] == '1') {
                    // compute the maximum width and update dp with it
                    dp[i][j] = j == 0 ? 1 : dp[i][j - 1] + 1;
                    int width = dp[i][j];
                    // compute the maximum area rectangle with a lower right
                    // corner at [i, j]
                    for (int k = i; k >= 0; k--) {
                        width = Math.Min(width, dp[k][j]);
                        maxarea = Math.Max(maxarea, width * (i - k + 1));
                    }
                }
            }
        }

        return maxarea;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maximalRectangle(matrix [][]byte) int {
    if len(matrix) == 0 {
        return 0
    }
    maxarea := 0
    dp := make([][]int, len(matrix))
    for i := range dp {
        dp[i] = make([]int, len(matrix[0]))
    }
    for i := 0; i < len(matrix); i++ {
        for j := 0; j < len(matrix[0]); j++ {
            if matrix[i][j] == '1' {
                // compute the maximum width and update dp with it
                dp[i][j] = 1
                if j != 0 {
                    dp[i][j] += dp[i][j-1]
                }
                width := dp[i][j]
                // compute the maximum area rectangle with a lower right corner at [i, j]
                for k := i; k >= 0; k-- {
                    width = min(width, dp[k][j])
                    maxarea = max(maxarea, width*(i-k+1))
                }
            }
        }
    }
    return maxarea
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0) return 0;
        int maxarea = 0;
        int[][] dp = new int[matrix.length][matrix[0].length];

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == '1') {
                    // compute the maximum width and update dp with it
                    dp[i][j] = j == 0 ? 1 : dp[i][j - 1] + 1;

                    int width = dp[i][j];

                    // compute the maximum area rectangle with a lower right corner at [i, j]
                    for (int k = i; k >= 0; k--) {
                        width = Math.min(width, dp[k][j]);
                        maxarea = Math.max(maxarea, width * (i - k + 1));
                    }
                }
            }
        }
        return maxarea;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maximalRectangle = function (matrix) {
    if (matrix.length === 0) return 0;
    let maxarea = 0;
    let dp = Array(matrix.length)
        .fill(0)
        .map(() => Array(matrix[0].length).fill(0));
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[0].length; j++) {
            if (matrix[i][j] === "1") {
                // compute the maximum width and update dp with it
                dp[i][j] = j === 0 ? 1 : dp[i][j - 1] + 1;
                let width = dp[i][j];
                // compute the maximum area rectangle with a lower right corner at [i, j]
                for (let k = i; k >= 0; k--) {
                    width = Math.min(width, dp[k][j]);
                    maxarea = Math.max(maxarea, width * (i - k + 1));
                }
            }
        }
    }
    return maxarea;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        maxarea = 0

        dp = [[0] * len(matrix[0]) for _ in range(len(matrix))]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == "0":
                    continue

                # compute the maximum width and update dp with it
                width = dp[i][j] = dp[i][j - 1] + 1 if j else 1

                # compute the maximum area rectangle with a lower right corner at [i, j]
                for k in range(i, -1, -1):
                    width = min(width, dp[k][j])
                    maxarea = max(maxarea, width * (i - k + 1))
        return maxarea
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maximalRectangle(matrix: string[][]): number {
    if (matrix.length === 0) return 0;
    let maxarea = 0;
    let dp = Array(matrix.length)
        .fill(0)
        .map(() => Array(matrix[0].length).fill(0));
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[0].length; j++) {
            if (matrix[i][j] === "1") {
                // compute the maximum width and update dp with it
                dp[i][j] = j === 0 ? 1 : dp[i][j - 1] + 1;
                let width = dp[i][j];
                // compute the maximum area rectangle with a lower right corner at [i, j]
                for (let k = i; k >= 0; k--) {
                    width = Math.min(width, dp[k][j]);
                    maxarea = Math.max(maxarea, width * (i - k + 1));
                }
            }
        }
    }
    return maxarea;
}
```

</details>

<br>

## Approach 3: Using Histograms - Stack

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int largestRectangleArea(int* heights, int heightsSize) {
    int stack[heightsSize];
    int top = -1;
    int maxarea = 0;
    for (int i = 0; i <= heightsSize; ++i) {
        while (top != -1 &&
               (i == heightsSize || heights[stack[top]] >= heights[i])) {
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = height * width;
            if (area > maxarea) maxarea = area;
        }
        stack[++top] = i;
    }
    return maxarea;
}
int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    int maxarea = 0;
    if (matrixSize == 0) return 0;
    int dp[matrixColSize[0]];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
        }
        maxarea = fmax(maxarea, largestRectangleArea(dp, matrixColSize[0]));
    }
    return maxarea;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int leetcode84(vector<int>& heights) {
        vector<int> stack = {-1};
        int maxarea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (stack.back() != -1 && heights[stack.back()] >= heights[i]) {
                int height = heights[stack.back()];
                stack.pop_back();
                maxarea = max(maxarea, height * (i - stack.back() - 1));
            }
            stack.push_back(i);
        }
        while (stack.back() != -1) {
            int height = heights[stack.back()];
            stack.pop_back();
            maxarea = max(maxarea, height * (static_cast<int>(heights.size()) -
                                             stack.back() - 1));
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int maxarea = 0;
        vector<int> dp(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                // update the state of this row's histogram using the last row's
                // histogram by keeping track of the number of consecutive ones
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }
            // update maxarea with the maximum area from this row's histogram
            maxarea = max(maxarea, leetcode84(dp));
        }
        return maxarea;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int Leetcode84(int[] heights) {
        Stack<int> stack = new Stack<int>();
        stack.Push(-1);
        int maxarea = 0;
        for (int i = 0; i < heights.Length; ++i) {
            while (stack.Peek() != -1 && heights[stack.Peek()] >= heights[i])
                maxarea = Math.Max(
                    maxarea, heights[stack.Pop()] * (i - stack.Peek() - 1));
            stack.Push(i);
        }

        while (stack.Peek() != -1)
            maxarea =
                Math.Max(maxarea, heights[stack.Pop()] *
                                      (heights.Length - stack.Peek() - 1));
        return maxarea;
    }

    public int MaximalRectangle(char[][] matrix) {
        if (matrix.Length == 0)
            return 0;
        int maxarea = 0;
        int[] dp = new int[matrix[0].Length];
        for (int i = 0; i < matrix.Length; i++) {
            for (int j = 0; j < matrix[0].Length; j++) {
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }

            maxarea = Math.Max(maxarea, Leetcode84(dp));
        }

        return maxarea;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maximalRectangle(matrix [][]byte) int {
    maxArea := 0
    width := len(matrix[0])
    heights := make([]int, width)
    for i := 0; i < len(matrix); i++ {
        for j := 0; j < len(matrix[i]); j++ {
            if matrix[i][j] == '1' {
                heights[j]++
            } else {
                heights[j] = 0
            }
        }
        maxArea = int(math.Max(float64(maxArea), float64(leetcode84(heights))))
    }
    return maxArea
}

func leetcode84(height []int) float64 {
    maxArea := 0.0
    stack := make([]int, 0)
    stack = append(stack, -1)
    for i := 0; i < len(height); i++ {
        for stack[len(stack)-1] != -1 && height[i] <= height[stack[len(stack)-1]] {
            pop := stack[len(stack)-1]
            stack = stack[:len(stack)-1]
            maxArea = math.Max(
                maxArea,
                float64(height[pop]*(i-stack[len(stack)-1]-1)),
            )
        }
        stack = append(stack, i)
    }
    for stack[len(stack)-1] != -1 {
        pop := stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        maxArea = math.Max(
            maxArea,
            float64(height[pop]*(len(height)-stack[len(stack)-1]-1)),
        )
    }
    return maxArea
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Get the maximum area in a histogram given its heights
    public int leetcode84(int[] heights) {
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);
        int maxarea = 0;
        for (int i = 0; i < heights.length; ++i) {
            while (
                stack.peek() != -1 && heights[stack.peek()] >= heights[i]
            ) maxarea = Math.max(
                maxarea,
                heights[stack.pop()] * (i - stack.peek() - 1)
            );
            stack.push(i);
        }
        while (stack.peek() != -1) maxarea = Math.max(
            maxarea,
            heights[stack.pop()] * (heights.length - stack.peek() - 1)
        );
        return maxarea;
    }

    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0) return 0;
        int maxarea = 0;
        int[] dp = new int[matrix[0].length];

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                // update the state of this row's histogram using the last row's histogram
                // by keeping track of the number of consecutive ones

                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }
            // update maxarea with the maximum area from this row's histogram
            maxarea = Math.max(maxarea, leetcode84(dp));
        }
        return maxarea;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let maximalRectangle = function (matrix) {
    function leetcode84(heights) {
        let stack = [-1];
        let maxarea = 0;
        for (let i = 0; i < heights.length; ++i) {
            while (
                heights[stack[stack.length - 1]] >= heights[i] &&
                stack[stack.length - 1] != -1
            ) {
                maxarea = Math.max(
                    maxarea,
                    heights[stack.pop()] * (i - stack[stack.length - 1] - 1),
                );
            }
            stack.push(i);
        }
        while (stack[stack.length - 1] != -1) {
            maxarea = Math.max(
                maxarea,
                heights[stack.pop()] *
                    (heights.length - stack[stack.length - 1] - 1),
            );
        }
        return maxarea;
    }
    if (!matrix.length) return 0;
    let maxarea = 0;
    let dp = Array(matrix[0].length).fill(0);
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[0].length; j++) {
            dp[j] = matrix[i][j] == "1" ? dp[j] + 1 : 0;
        }
        maxarea = Math.max(maxarea, leetcode84(dp));
    }
    return maxarea;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    # Get the maximum area in a histogram given its heights
    def leetcode84(self, heights):
        stack = [-1]

        maxarea = 0
        for i in range(len(heights)):

            while stack[-1] != -1 and heights[stack[-1]] >= heights[i]:
                maxarea = max(
                    maxarea, heights[stack.pop()] * (i - stack[-1] - 1)
                )
            stack.append(i)

        while stack[-1] != -1:
            maxarea = max(
                maxarea, heights[stack.pop()] * (len(heights) - stack[-1] - 1)
            )
        return maxarea

    def maximalRectangle(self, matrix: List[List[str]]) -> int:

        if not matrix:
            return 0

        maxarea = 0
        dp = [0] * len(matrix[0])
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):

                # update the state of this row's histogram using the last row's histogram
                # by keeping track of the number of consecutive ones

                dp[j] = dp[j] + 1 if matrix[i][j] == "1" else 0

            # update maxarea with the maximum area from this row's histogram
            maxarea = max(maxarea, self.leetcode84(dp))
        return maxarea
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maximalRectangle(matrix: string[][]): number {
    function leetcode84(heights: number[]): number {
        let stack: number[] = [-1];
        let maxarea: number = 0;
        for (let i = 0; i < heights.length; ++i) {
            while (
                heights[stack[stack.length - 1]] >= heights[i] &&
                stack[stack.length - 1] != -1
            ) {
                maxarea = Math.max(
                    maxarea,
                    heights[stack.pop() as number] *
                        (i - stack[stack.length - 1] - 1),
                );
            }
            stack.push(i);
        }
        while (stack[stack.length - 1] != -1) {
            maxarea = Math.max(
                maxarea,
                heights[stack.pop() as number] *
                    (heights.length - stack[stack.length - 1] - 1),
            );
        }
        return maxarea;
    }
    if (!matrix.length) return 0;
    let maxarea: number = 0;
    let dp: number[] = new Array(matrix[0].length).fill(0);
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[0].length; j++) {
            dp[j] = matrix[i][j] == "1" ? dp[j] + 1 : 0;
        }
        maxarea = Math.max(maxarea, leetcode84(dp));
    }
    return maxarea;
}
```

</details>

<br>

## Approach 4: Dynamic Programming - Maximum Height at Each Point

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0) return 0;
    int m = matrixSize;
    int n = matrixColSize[0];
    int left[n];
    int right[n];
    int height[n];
    memset(height, 0, sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        left[i] = 0;
        right[i] = n;
    }
    int maxarea = 0;
    for (int i = 0; i < m; i++) {
        int cur_left = 0, cur_right = n;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1')
                height[j]++;
            else
                height[j] = 0;
        }
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1')
                left[j] = max(left[j], cur_left);
            else {
                left[j] = 0;
                cur_left = j + 1;
            }
        }
        for (int j = n - 1; j >= 0; j--) {
            if (matrix[i][j] == '1')
                right[j] = min(right[j], cur_right);
            else {
                right[j] = n;
                cur_right = j;
            }
        }
        for (int j = 0; j < n; j++)
            maxarea = max(maxarea, (right[j] - left[j]) * height[j]);
    }
    return maxarea;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> left(n), right(n), height(n);
        fill(right.begin(), right.end(), n);
        int maxarea = 0;
        for (int i = 0; i < m; i++) {
            int cur_left = 0, cur_right = n;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    left[j] = max(left[j], cur_left);
                else {
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1')
                    right[j] = min(right[j], cur_right);
                else {
                    right[j] = n;
                    cur_right = j;
                }
            }
            for (int j = 0; j < n; j++) {
                maxarea = max(maxarea, (right[j] - left[j]) * height[j]);
            }
        }
        return maxarea;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaximalRectangle(char[][] matrix) {
        if (matrix.Length == 0)
            return 0;
        int m = matrix.Length;
        int n = matrix[0].Length;
        int[] left = new int[n];
        int[] right = new int[n];
        int[] height = new int[n];
        for (int i = 0; i < n; i++) right[i] = n;
        int maxarea = 0;
        for (int i = 0; i < m; i++) {
            int cur_left = 0, cur_right = n;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    left[j] = Math.Max(left[j], cur_left);
                else {
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }

            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1')
                    right[j] = Math.Min(right[j], cur_right);
                else {
                    right[j] = n;
                    cur_right = j;
                }
            }

            for (int j = 0; j < n; j++) {
                maxarea = Math.Max(maxarea, (right[j] - left[j]) * height[j]);
            }
        }

        return maxarea;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maximalRectangle(matrix [][]byte) int {
    if len(matrix) == 0 {
        return 0
    }
    m := len(matrix)
    n := len(matrix[0])
    left := make([]int, n)
    right := make([]int, n)
    height := make([]int, n)
    for i := range right {
        right[i] = n
    }
    maxarea := 0
    for i := 0; i < m; i++ {
        cur_left := 0
        cur_right := n
        for j := 0; j < n; j++ {
            if matrix[i][j] == '1' {
                height[j]++
            } else {
                height[j] = 0
            }
        }
        for j := 0; j < n; j++ {
            if matrix[i][j] == '1' {
                left[j] = max(left[j], cur_left)
            } else {
                left[j] = 0
                cur_left = j + 1
            }
        }
        for j := n - 1; j >= 0; j-- {
            if matrix[i][j] == '1' {
                right[j] = min(right[j], cur_right)
            } else {
                right[j] = n
                cur_right = j
            }
        }
        for j := 0; j < n; j++ {
            maxarea = max(maxarea, (right[j]-left[j])*height[j])
        }
    }
    return maxarea
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0) return 0;
        int m = matrix.length;
        int n = matrix[0].length;

        int[] left = new int[n]; // initialize left as the leftmost boundary possible
        int[] right = new int[n];
        int[] height = new int[n];

        Arrays.fill(right, n); // initialize right as the rightmost boundary possible

        int maxarea = 0;
        for (int i = 0; i < m; i++) {
            int cur_left = 0, cur_right = n;
            // update height
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            // update left
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') left[j] = Math.max(left[j], cur_left);
                else {
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }
            // update right
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') right[j] = Math.min(
                    right[j],
                    cur_right
                );
                else {
                    right[j] = n;
                    cur_right = j;
                }
            }
            // update area
            for (int j = 0; j < n; j++) {
                maxarea = Math.max(maxarea, (right[j] - left[j]) * height[j]);
            }
        }
        return maxarea;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maximalRectangle = function (matrix) {
    if (matrix.length === 0) return 0;
    let m = matrix.length;
    let n = matrix[0].length;
    let left = Array(n).fill(0);
    let right = Array(n).fill(n);
    let height = Array(n).fill(0);
    let maxarea = 0;
    for (let i = 0; i < m; i++) {
        let cur_left = 0,
            cur_right = n;
        for (let j = 0; j < n; j++) {
            if (matrix[i][j] === "1") height[j]++;
            else height[j] = 0;
        }
        for (let j = 0; j < n; j++) {
            if (matrix[i][j] === "1") left[j] = Math.max(left[j], cur_left);
            else {
                left[j] = 0;
                cur_left = j + 1;
            }
        }
        for (let j = n - 1; j >= 0; j--) {
            if (matrix[i][j] === "1") right[j] = Math.min(right[j], cur_right);
            else {
                right[j] = n;
                cur_right = j;
            }
        }
        for (let j = 0; j < n; j++) {
            maxarea = Math.max(maxarea, (right[j] - left[j]) * height[j]);
        }
    }
    return maxarea;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0

        m = len(matrix)
        n = len(matrix[0])

        left = [0] * n  # initialize left as the leftmost boundary possible
        right = [n] * n  # initialize right as the rightmost boundary possible
        height = [0] * n

        maxarea = 0

        for i in range(m):

            cur_left, cur_right = 0, n
            # update height
            for j in range(n):
                if matrix[i][j] == "1":
                    height[j] += 1
                else:
                    height[j] = 0
            # update left
            for j in range(n):
                if matrix[i][j] == "1":
                    left[j] = max(left[j], cur_left)
                else:
                    left[j] = 0
                    cur_left = j + 1
            # update right
            for j in range(n - 1, -1, -1):
                if matrix[i][j] == "1":
                    right[j] = min(right[j], cur_right)
                else:
                    right[j] = n
                    cur_right = j
            # update the area
            for j in range(n):
                maxarea = max(maxarea, height[j] * (right[j] - left[j]))

        return maxarea
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maximalRectangle(matrix: string[][]): number {
    if (matrix.length === 0) return 0;
    let m = matrix.length;
    let n = matrix[0].length;
    let left: number[] = Array(n).fill(0);
    let right: number[] = Array(n).fill(n);
    let height: number[] = Array(n).fill(0);
    let maxarea = 0;
    for (let i = 0; i < m; i++) {
        let cur_left = 0,
            cur_right = n;
        for (let j = 0; j < n; j++) {
            if (matrix[i][j] === "1") height[j]++;
            else height[j] = 0;
        }
        for (let j = 0; j < n; j++) {
            if (matrix[i][j] === "1") left[j] = Math.max(left[j], cur_left);
            else {
                left[j] = 0;
                cur_left = j + 1;
            }
        }
        for (let j = n - 1; j >= 0; j--) {
            if (matrix[i][j] === "1") right[j] = Math.min(right[j], cur_right);
            else {
                right[j] = n;
                cur_right = j;
            }
        }
        for (let j = 0; j < n; j++) {
            maxarea = Math.max(maxarea, (right[j] - left[j]) * height[j]);
        }
    }
    return maxarea;
}
```

</details>
