# 11. Container With Most Water

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/container-with-most-water/)  
`Array` `Two Pointers` `Greedy`

**Problem Link:** [LeetCode 11 - Container With Most Water](https://leetcode.com/problems/container-with-most-water/)

## Problem

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

### Example 1

```text
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
```

### Example 2

```text
Input: height = [1,1]
Output: 1
```

## Constraints

- n == height.length
- 2 <= n <= 105
- 0 <= height[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Maximum Tastiness of Candy Basket](https://leetcode.com/problems/maximum-tastiness-of-candy-basket/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [House Robber IV](https://leetcode.com/problems/house-robber-iv/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 11. Container With Most Water

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Two Pointer Approach | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int max(int a, int b) { return a > b ? a : b; }

int min(int a, int b) { return a < b ? a : b; }

int maxArea(int* height, int heightSize) {
    int maxarea = 0;

    for (int left = 0; left < heightSize; left++) {
        for (int right = left + 1; right < heightSize; right++) {
            int width = right - left;
            maxarea = max(maxarea, min(height[left], height[right]) * width);
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
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        for (int left = 0; left < height.size(); left++) {
            for (int right = left + 1; right < height.size(); right++) {
                int width = right - left;
                maxarea = max(maxarea, min(height[left], height[right]) * width);
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
    public int MaxArea(int[] height) {
        int maxarea = 0;

        for (int left = 0; left < height.Length; left++) {
            for (int right = left + 1; right < height.Length; right++) {
                int width = right - left;
                maxarea = Math.Max(
                    maxarea, Math.Min(height[left], height[right]) * width);
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
func maxArea(height []int) int {
    maxarea := 0

    for left := 0; left < len(height); left++ {
        for right := left + 1; right < len(height); right++ {
            width := right - left
            maxarea = max(maxarea, min(height[left], height[right])*width)
        }
    }

    return maxarea
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int maxArea(int[] height) {
        int maxarea = 0;
        for (int left = 0; left < height.length; left++) {
            for (int right = left + 1; right < height.length; right++) {
                int width = right - left;
                maxarea = Math.max(
                    maxarea,
                    Math.min(height[left], height[right]) * width
                );
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
var maxArea = function (height) {
    var maxarea = 0;

    for (var left = 0; left < height.length; left++) {
        for (var right = left + 1; right < height.length; right++) {
            var width = right - left;
            maxarea = Math.max(
                maxarea,
                Math.min(height[left], height[right]) * width,
            );
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
    def maxArea(self, height: List[int]) -> int:
        maxarea = 0
        for left in range(len(height)):
            for right in range(left + 1, len(height)):
                width = right - left
                maxarea = max(maxarea, min(height[left], height[right]) * width)

        return maxarea
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxArea(height: number[]): number {
    let maxarea = 0;

    for (let left = 0; left < height.length; left++) {
        for (let right = left + 1; right < height.length; right++) {
            let width = right - left;
            maxarea = Math.max(
                maxarea,
                Math.min(height[left], height[right]) * width,
            );
        }
    }

    return maxarea;
}
```

</details>

<br>

## Approach 2: Two Pointer Approach

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int max(int a, int b) { return a > b ? a : b; }

int min(int a, int b) { return a < b ? a : b; }

int maxArea(int* height, int heightSize) {
    int maxArea = 0;
    int left = 0;
    int right = heightSize - 1;

    while (left < right) {
        int width = right - left;
        maxArea = max(maxArea, min(height[left], height[right]) * width);
        if (height[left] <= height[right]) {
            left++;
        } else {
            right--;
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
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int width = right - left;
            maxArea = max(maxArea, min(height[left], height[right]) * width);
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
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
    public int MaxArea(int[] height) {
        int maxArea = 0;
        int left = 0;
        int right = height.Length - 1;

        while (left < right) {
            int width = right - left;
            maxArea = Math.Max(maxArea,
                               Math.Min(height[left], height[right]) * width);
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
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
func maxArea(height []int) int {
    maxArea := 0
    left := 0
    right := len(height) - 1

    for left < right {
        width := right - left
        maxArea = max(maxArea, min(height[left], height[right])*width)
        if height[left] <= height[right] {
            left++
        } else {
            right--
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
    public int maxArea(int[] height) {
        int maxarea = 0;
        int left = 0;
        int right = height.length - 1;
        while (left < right) {
            int width = right - left;
            maxarea = Math.max(
                maxarea,
                Math.min(height[left], height[right]) * width
            );
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
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
var maxArea = function (height) {
    let maxArea = 0;
    let left = 0;
    let right = height.length - 1;

    while (left < right) {
        let width = right - left;
        maxArea = Math.max(
            maxArea,
            Math.min(height[left], height[right]) * width,
        );
        if (height[left] <= height[right]) {
            left++;
        } else {
            right--;
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
    def maxArea(self, height: List[int]) -> int:
        maxarea = 0
        left = 0
        right = len(height) - 1

        while left < right:
            width = right - left
            maxarea = max(maxarea, min(height[left], height[right]) * width)
            if height[left] <= height[right]:
                left += 1
            else:
                right -= 1

        return maxarea
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxArea(height: number[]): number {
    let maxArea = 0;
    let left = 0;
    let right = height.length - 1;

    while (left < right) {
        let width = right - left;
        maxArea = Math.max(
            maxArea,
            Math.min(height[left], height[right]) * width,
        );
        if (height[left] <= height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxArea;
}
```

</details>
