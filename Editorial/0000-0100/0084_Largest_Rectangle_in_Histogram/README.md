# 84. Largest Rectangle in Histogram

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/largest-rectangle-in-histogram/)  
`Array` `Stack` `Monotonic Stack`

**Problem Link:** [LeetCode 84 - Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)

## Problem

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

### Example 1

```text
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
```

### Example 2

```text
Input: heights = [2,4]
Output: 4
```

## Constraints

- 1 <= heights.length <= 105
- 0 <= heights[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Maximum Score of a Good Subarray](https://leetcode.com/problems/maximum-score-of-a-good-subarray/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 84. Largest Rectangle in Histogram

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Better Brute Force | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Divide and Conquer Approach | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Using Stack | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int largestRectangleArea(int* heights, int heightsSize) {
    int max_area = 0, min_height, i, j, k;
    for (i = 0; i < heightsSize; i++) {
        for (j = i; j < heightsSize; j++) {
            min_height = INT_MAX;
            for (k = i; k <= j; k++) {
                min_height = min_height < heights[k] ? min_height : heights[k];
            }
            max_area = max_area > min_height * (j - i + 1)
                           ? max_area
                           : min_height * (j - i + 1);
        }
    }
    return max_area;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        size_t max_area = 0;
        for (size_t i = 0; i < heights.size(); i++) {
            for (size_t j = i; j < heights.size(); j++) {
                int min_height = INT_MAX;
                for (size_t k = i; k <= j; k++) {
                    min_height = min(min_height, heights[k]);
                }
                max_area = max(max_area, min_height * (j - i + 1));
            }
        }
        return max_area;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int LargestRectangleArea(int[] heights) {
        int max_area = 0;
        for (int i = 0; i < heights.Length; i++) {
            for (int j = i; j < heights.Length; j++) {
                int min_height = Int32.MaxValue;
                for (int k = i; k <= j; k++) {
                    min_height = Math.Min(min_height, heights[k]);
                }

                max_area = Math.Max(max_area, min_height * (j - i + 1));
            }
        }

        return max_area;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func largestRectangleArea(heights []int) int {
    max_area := 0
    inf := int(^uint(0) >> 1)
    for i := 0; i < len(heights); i++ {
        for j := i; j < len(heights); j++ {
            min_height := inf
            for k := i; k <= j; k++ {
                if heights[k] < min_height {
                    min_height = heights[k]
                }
            }
            if min_height*(j-i+1) > max_area {
                max_area = min_height * (j - i + 1)
            }
        }
    }
    return max_area
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int largestRectangleArea(int[] heights) {
        int maxarea = 0;
        for (int i = 0; i < heights.length; i++) {
            for (int j = i; j < heights.length; j++) {
                int minheight = Integer.MAX_VALUE;
                for (int k = i; k <= j; k++) minheight = Math.min(
                    minheight,
                    heights[k]
                );
                maxarea = Math.max(maxarea, minheight * (j - i + 1));
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
/**
 * @param {number[]} heights
 * @return {number}
 */
var largestRectangleArea = function (heights) {
    let max_area = 0;
    for (let i = 0; i < heights.length; i++) {
        for (let j = i; j < heights.length; j++) {
            let min_height = Infinity;
            for (let k = i; k <= j; k++) {
                min_height = Math.min(min_height, heights[k]);
            }
            max_area = Math.max(max_area, min_height * (j - i + 1));
        }
    }
    return max_area;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        max_area = 0
        for i in range(len(heights)):
            for j in range(i, len(heights)):
                min_height = inf
                for k in range(i, j + 1):
                    min_height = min(min_height, heights[k])
                max_area = max(max_area, min_height * (j - i + 1))
        return max_area
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function largestRectangleArea(heights: number[]): number {
    let max_area = 0;
    for (let i = 0; i < heights.length; i++) {
        for (let j = i; j < heights.length; j++) {
            let min_height = Infinity;
            for (let k = i; k <= j; k++)
                min_height = Math.min(min_height, heights[k]);
            max_area = Math.max(max_area, min_height * (j - i + 1));
        }
    }
    return max_area;
}
```

</details>

<br>

## Approach 2: Better Brute Force

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int largestRectangleArea(int* heights, int heightsSize) {
    int max_area = 0;
    for (int i = 0; i < heightsSize; i++) {
        int min_height = INT_MAX;
        for (int j = i; j < heightsSize; j++) {
            min_height = min_height < heights[j] ? min_height : heights[j];
            max_area = max_area > min_height * (j - i + 1)
                           ? max_area
                           : min_height * (j - i + 1);
        }
    }
    return max_area;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        size_t max_area = 0;
        for (size_t i = 0; i < heights.size(); i++) {
            int min_height = INT_MAX;
            for (size_t j = i; j < heights.size(); j++) {
                min_height = min(min_height, heights[j]);
                max_area = max(max_area, min_height * (j - i + 1));
            }
        }
        return max_area;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int LargestRectangleArea(int[] heights) {
        int maxArea = 0;
        int length = heights.Length;
        for (int i = 0; i < length; i++) {
            int minHeight = int.MaxValue;
            for (int j = i; j < length; j++) {
                minHeight = Math.Min(minHeight, heights[j]);
                maxArea = Math.Max(maxArea, minHeight * (j - i + 1));
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
func largestRectangleArea(heights []int) int {
    maxArea := 0
    length := len(heights)
    for i := 0; i < length; i++ {
        minHeight := int(^uint(0) >> 1) // set to maximum int value
        for j := i; j < length; j++ {
            if minHeight > heights[j] {
                minHeight = heights[j]
            }
            area := minHeight * (j - i + 1)
            if maxArea < area {
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
public class Solution {
    public int largestRectangleArea(int[] heights) {
        int maxArea = 0;
        int length = heights.length;
        for (int i = 0; i < length; i++) {
            int minHeight = Integer.MAX_VALUE;
            for (int j = i; j < length; j++) {
                minHeight = Math.min(minHeight, heights[j]);
                maxArea = Math.max(maxArea, minHeight * (j - i + 1));
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
var largestRectangleArea = function (heights) {
    var maxArea = 0;
    var length = heights.length;
    for (var i = 0; i < length; i++) {
        var minHeight = Infinity;
        for (var j = i; j < length; j++) {
            minHeight = Math.min(minHeight, heights[j]);
            maxArea = Math.max(maxArea, minHeight * (j - i + 1));
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
    def largestRectangleArea(self, heights: List[int]) -> int:
        max_area = 0
        for i in range(len(heights)):
            min_height = inf
            for j in range(i, len(heights)):
                min_height = min(min_height, heights[j])
                max_area = max(max_area, min_height * (j - i + 1))
        return max_area
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function largestRectangleArea(heights: number[]): number {
    var maxArea = 0;
    var length = heights.length;
    for (var i = 0; i < length; i++) {
        var minHeight = Infinity;
        for (var j = i; j < length; j++) {
            minHeight = Math.min(minHeight, heights[j]);
            maxArea = Math.max(maxArea, minHeight * (j - i + 1));
        }
    }
    return maxArea;
}
```

</details>

<br>

## Approach 3: Divide and Conquer Approach

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int max(int a, int b) { return (a > b) ? a : b; }
int calculateArea(int* heights, int start, int end) {
    if (start > end) return 0;
    int min_index = start;
    for (int i = start; i <= end; i++)
        if (heights[min_index] > heights[i]) min_index = i;
    return max(heights[min_index] * (end - start + 1),
               max(calculateArea(heights, start, min_index - 1),
                   calculateArea(heights, min_index + 1, end)));
}
int largestRectangleArea(int* heights, int heightsSize) {
    return calculateArea(heights, 0, heightsSize - 1);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int calculateArea(vector<int>& heights, int start, int end) {
        if (start > end) {
            return 0;
        }
        int min_index = start;
        for (int i = start; i <= end; i++) {
            if (heights[min_index] > heights[i]) {
                min_index = i;
            }
        }
        return max({heights[min_index] * (end - start + 1),
                    calculateArea(heights, start, min_index - 1),
                    calculateArea(heights, min_index + 1, end)});
    }

    int largestRectangleArea(vector<int>& heights) {
        return calculateArea(heights, 0, heights.size() - 1);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int CalculateArea(int[] heights, int start, int end) {
        if (start > end)
            return 0;
        int min_index = start;
        for (int i = start; i <= end; i++)
            if (heights[min_index] > heights[i])
                min_index = i;
        return Math.Max(heights[min_index] * (end - start + 1),
                        Math.Max(CalculateArea(heights, start, min_index - 1),
                                 CalculateArea(heights, min_index + 1, end)));
    }

    public int LargestRectangleArea(int[] heights) {
        return CalculateArea(heights, 0, heights.Length - 1);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func calculateArea(heights []int, start int, end int) int {
    if start > end {
        return 0
    }
    min_index := start
    for i := start; i <= end; i++ {
        if heights[min_index] > heights[i] {
            min_index = i
        }
    }
    return max(heights[min_index]*(end-start+1),
        max(calculateArea(heights, start, min_index-1),
            calculateArea(heights, min_index+1, end)))
}

func largestRectangleArea(heights []int) int {
    return calculateArea(heights, 0, len(heights)-1)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int calculateArea(int[] heights, int start, int end) {
        if (start > end) return 0;
        int minindex = start;
        for (int i = start; i <= end; i++) if (
            heights[minindex] > heights[i]
        ) minindex = i;
        return Math.max(
            heights[minindex] * (end - start + 1),
            Math.max(
                calculateArea(heights, start, minindex - 1),
                calculateArea(heights, minindex + 1, end)
            )
        );
    }

    public int largestRectangleArea(int[] heights) {
        return calculateArea(heights, 0, heights.length - 1);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var largestRectangleArea = function (heights) {
    function calculateArea(heights, start, end) {
        if (start > end) return 0;
        let min_index = start;
        for (let i = start; i <= end; i++)
            if (heights[min_index] > heights[i]) min_index = i;
        return Math.max(
            heights[min_index] * (end - start + 1),
            Math.max(
                calculateArea(heights, start, min_index - 1),
                calculateArea(heights, min_index + 1, end),
            ),
        );
    }
    return calculateArea(heights, 0, heights.length - 1);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        def calculateArea(heights: List[int], start: int, end: int) -> int:
            if start > end:
                return 0
            min_index = start
            for i in range(start, end + 1):
                if heights[min_index] > heights[i]:
                    min_index = i
            return max(
                heights[min_index] * (end - start + 1),
                calculateArea(heights, start, min_index - 1),
                calculateArea(heights, min_index + 1, end),
            )

        return calculateArea(heights, 0, len(heights) - 1)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function calculateArea(heights: number[], start: number, end: number) {
    if (start > end) return 0;
    let min_index = start;
    for (let i = start; i <= end; i++)
        if (heights[min_index] > heights[i]) min_index = i;
    return Math.max(
        heights[min_index] * (end - start + 1),
        Math.max(
            calculateArea(heights, start, min_index - 1),
            calculateArea(heights, min_index + 1, end),
        ),
    );
}
function largestRectangleArea(heights: number[]): number {
    return calculateArea(heights, 0, heights.length - 1);
}
```

</details>

<br>

## Approach 5: Using Stack

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int largestRectangleArea(int* heights, int heightsSize) {
    int* stack = (int*)malloc((heightsSize + 1) * sizeof(int));
    int top = -1;
    stack[++top] = -1;
    int maxArea = 0;
    for (int i = 0; i < heightsSize; i++) {
        while (top != 0 && heights[stack[top]] >= heights[i]) {
            int currentHeight = heights[stack[top--]];
            int currentWidth = i - stack[top] - 1;
            maxArea = (currentHeight * currentWidth > maxArea)
                          ? currentHeight * currentWidth
                          : maxArea;
        }
        stack[++top] = i;
    }
    while (top != 0) {
        int currentHeight = heights[stack[top--]];
        int currentWidth = heightsSize - stack[top] - 1;
        maxArea = (currentHeight * currentWidth > maxArea)
                      ? currentHeight * currentWidth
                      : maxArea;
    }
    free(stack);
    return maxArea;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        stk.push(-1);
        int max_area = 0;
        for (size_t i = 0; i < heights.size(); i++) {
            while (stk.top() != -1 and heights[stk.top()] >= heights[i]) {
                int current_height = heights[stk.top()];
                stk.pop();
                int current_width = i - stk.top() - 1;
                max_area = max(max_area, current_height * current_width);
            }
            stk.push(i);
        }
        while (stk.top() != -1) {
            int current_height = heights[stk.top()];
            stk.pop();
            int current_width = heights.size() - stk.top() - 1;
            max_area = max(max_area, current_height * current_width);
        }
        return max_area;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int LargestRectangleArea(int[] heights) {
        Stack<int> stack = new Stack<int>();
        stack.Push(-1);
        int maxArea = 0;
        for (int i = 0; i < heights.Length; i++) {
            while (stack.Peek() != -1 && heights[stack.Peek()] >= heights[i]) {
                int currentHeight = heights[stack.Pop()];
                int currentWidth = i - stack.Peek() - 1;
                maxArea = Math.Max(maxArea, currentHeight * currentWidth);
            }

            stack.Push(i);
        }

        while (stack.Peek() != -1) {
            int currentHeight = heights[stack.Pop()];
            int currentWidth = heights.Length - stack.Peek() - 1;
            maxArea = Math.Max(maxArea, currentHeight * currentWidth);
        }

        return maxArea;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func largestRectangleArea(heights []int) int {
    stack := []int{-1}
    maxArea := 0
    for i := range heights {
        for len(stack) > 1 && heights[stack[len(stack)-1]] >= heights[i] {
            currentHeight := heights[stack[len(stack)-1]]
            stack = stack[:len(stack)-1]
            currentWidth := i - stack[len(stack)-1] - 1
            if currentArea := currentHeight * currentWidth; currentArea > maxArea {
                maxArea = currentArea
            }
        }
        stack = append(stack, i)
    }
    for len(stack) > 1 {
        currentHeight := heights[stack[len(stack)-1]]
        stack = stack[:len(stack)-1]
        currentWidth := len(heights) - stack[len(stack)-1] - 1
        if currentArea := currentHeight * currentWidth; currentArea > maxArea {
            maxArea = currentArea
        }
    }
    return maxArea
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int largestRectangleArea(int[] heights) {
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(-1);
        int length = heights.length;
        int maxArea = 0;
        for (int i = 0; i < length; i++) {
            while (
                (stack.peek() != -1) && (heights[stack.peek()] >= heights[i])
            ) {
                int currentHeight = heights[stack.pop()];
                int currentWidth = i - stack.peek() - 1;
                maxArea = Math.max(maxArea, currentHeight * currentWidth);
            }
            stack.push(i);
        }
        while (stack.peek() != -1) {
            int currentHeight = heights[stack.pop()];
            int currentWidth = length - stack.peek() - 1;
            maxArea = Math.max(maxArea, currentHeight * currentWidth);
        }
        return maxArea;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var largestRectangleArea = function (heights) {
    let stack = [-1];
    let max_area = 0;
    for (let i = 0; i < heights.length; i++) {
        while (
            stack[stack.length - 1] != -1 &&
            heights[stack[stack.length - 1]] >= heights[i]
        ) {
            let current_height = heights[stack.pop()];
            let current_width = i - stack[stack.length - 1] - 1;
            max_area = Math.max(max_area, current_height * current_width);
        }
        stack.push(i);
    }
    while (stack[stack.length - 1] != -1) {
        let current_height = heights[stack.pop()];
        let current_width = heights.length - stack[stack.length - 1] - 1;
        max_area = Math.max(max_area, current_height * current_width);
    }
    return max_area;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = [-1]
        max_area = 0
        for i in range(len(heights)):
            while stack[-1] != -1 and heights[stack[-1]] >= heights[i]:
                current_height = heights[stack.pop()]
                current_width = i - stack[-1] - 1
                max_area = max(max_area, current_height * current_width)
            stack.append(i)

        while stack[-1] != -1:
            current_height = heights[stack.pop()]
            current_width = len(heights) - stack[-1] - 1
            max_area = max(max_area, current_height * current_width)
        return max_area
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function largestRectangleArea(heights: number[]): number {
    let stack = [-1];
    let max_area = 0;
    for (let i = 0; i < heights.length; i++) {
        while (
            stack[stack.length - 1] !== -1 &&
            heights[stack[stack.length - 1]] >= heights[i]
        ) {
            let current_height = heights[stack.pop()!];
            let current_width = i - stack[stack.length - 1] - 1;
            max_area = Math.max(max_area, current_height * current_width);
        }
        stack.push(i);
    }
    while (stack[stack.length - 1] !== -1) {
        let current_height = heights[stack.pop()!];
        let current_width = heights.length - stack[stack.length - 1] - 1;
        max_area = Math.max(max_area, current_height * current_width);
    }
    return max_area;
}
```

</details>
