# 42. Trapping Rain Water

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/trapping-rain-water/)  
`Array` `Two Pointers` `Dynamic Programming` `Stack` `Monotonic Stack`

**Problem Link:** [LeetCode 42 - Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)

## Problem

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

### Example 1

```text
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
```

### Example 2

```text
Input: height = [4,2,0,3,2,5]
Output: 9
```

## Constraints

- n == height.length
- 1 <= n <= 2 * 104
- 0 <= height[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Trapping Rain Water II](https://leetcode.com/problems/trapping-rain-water-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Pour Water](https://leetcode.com/problems/pour-water/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Value of an Ordered Triplet II](https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 42. Trapping Rain Water

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute force | C++, Java, Python3 |
| Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Using stacks | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Using 2 pointers | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Brute force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int size = height.size();
        for (int i = 1; i < size - 1; i++) {
            int left_max = 0, right_max = 0;
            // Search the left part for max bar size
            for (int j = i; j >= 0; j--) {
                left_max = max(left_max, height[j]);
            }
            // Search the right part for max bar size
            for (int j = i; j < size; j++) {
                right_max = max(right_max, height[j]);
            }
            ans += min(left_max, right_max) - height[i];
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int trap(int[] height) {
        int ans = 0;
        int size = height.length;
        for (int i = 1; i < size - 1; i++) {
            int left_max = 0, right_max = 0;
            // Search the left part for max bar size
            for (int j = i; j >= 0; j--) {
                left_max = Math.max(left_max, height[j]);
            }
            // Search the right part for max bar size
            for (int j = i; j < size; j++) {
                right_max = Math.max(right_max, height[j]);
            }
            ans += Math.min(left_max, right_max) - height[i];
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
    def trap(self, height):
        ans = 0
        size = len(height)
        for i in range(1, size - 1):
            left_max = 0
            right_max = 0
            # Search the left part for max bar size
            for j in range(i, -1, -1):
                left_max = max(left_max, height[j])
            # Search the right part for max bar size
            for j in range(i, size):
                right_max = max(right_max, height[j])
            ans += min(left_max, right_max) - height[i]
        return ans
```

</details>

<br>

## Approach 2: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int trap(int* height, int heightSize) {
    // Case of empty height array
    if (heightSize == 0) return 0;
    int ans = 0;
    // Create left and right max arrays
    int* left_max = (int*)calloc(heightSize, sizeof(int));
    int* right_max = (int*)calloc(heightSize, sizeof(int));
    // Initialize first height into left max
    left_max[0] = height[0];
    for (int i = 1; i < heightSize; i++) {
        // update left max with current max
        left_max[i] = height[i] > left_max[i - 1] ? height[i] : left_max[i - 1];
    }
    // Initialize last height into right max
    right_max[heightSize - 1] = height[heightSize - 1];
    for (int i = heightSize - 2; i >= 0; i--) {
        // update right max with current max
        right_max[i] =
            height[i] > right_max[i + 1] ? height[i] : right_max[i + 1];
    }
    // Calculate the trapped water
    for (int i = 1; i < heightSize - 1; i++) {
        int min_height =
            left_max[i] < right_max[i] ? left_max[i] : right_max[i];
        ans += min_height - height[i];
    }
    // free the arrays
    free(left_max);
    free(right_max);
    // Return amount of trapped water
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int ans = 0;
        int size = height.size();
        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; i++) {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        for (int i = 1; i < size - 1; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
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
    public int Trap(int[] height) {
        // Case of empty height array
        if (height.Length == 0)
            return 0;
        int ans = 0;
        int size = height.Length;
        // Create left and right max arrays
        int[] left_max = new int[size];
        int[] right_max = new int[size];
        // Initialize first height into left max
        left_max[0] = height[0];
        for (int i = 1; i < size; i++) {
            // update left max with current max
            left_max[i] = Math.Max(height[i], left_max[i - 1]);
        }

        // Initialize last height into right max
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            // update right max with current max
            right_max[i] = Math.Max(height[i], right_max[i + 1]);
        }

        // Calculate the trapped water
        for (int i = 1; i < size - 1; i++) {
            ans += Math.Min(left_max[i], right_max[i]) - height[i];
        }

        // Return amount of trapped water
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func trap(height []int) int {
    // Case of empty height array
    if len(height) == 0 {
        return 0
    }
    ans := 0
    size := len(height)
    // Create left and right max arrays
    left_max, right_max := make([]int, size), make([]int, size)
    // Initialize first height into left max
    left_max[0] = height[0]
    for i := 1; i < size; i++ {
        // update left max with current max
        if height[i] > left_max[i-1] {
            left_max[i] = height[i]
        } else {
            left_max[i] = left_max[i-1]
        }
    }
    // Initialize last height into right max
    right_max[size-1] = height[size-1]
    for i := size - 2; i >= 0; i-- {
        // update right max with current max
        if height[i] > right_max[i+1] {
            right_max[i] = height[i]
        } else {
            right_max[i] = right_max[i+1]
        }
    }
    // Calculate the trapped water
    for i := 1; i < size-1; i++ {
        if left_max[i] < right_max[i] {
            ans += left_max[i] - height[i]
        } else {
            ans += right_max[i] - height[i]
        }
    }
    // Return amount of trapped water
    return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int trap(int[] height) {
        // Case of empty height array
        if (height.length == 0) return 0;
        int ans = 0;
        int size = height.length;
        // Create left and right max arrays
        int[] left_max = new int[size];
        int[] right_max = new int[size];
        // Initialize first height into left max
        left_max[0] = height[0];
        for (int i = 1; i < size; i++) {
            // update left max with current max
            left_max[i] = Math.max(height[i], left_max[i - 1]);
        }
        // Initialize last height into right max
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            // update right max with current max
            right_max[i] = Math.max(height[i], right_max[i + 1]);
        }
        // Calculate the trapped water
        for (int i = 1; i < size - 1; i++) {
            ans += Math.min(left_max[i], right_max[i]) - height[i];
        }
        // Return amount of trapped water
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var trap = function (height) {
    // Case of empty height array
    if (height.length == 0) return 0;
    let ans = 0;
    let size = height.length;
    // Create left and right max arrays
    let left_max = new Array(size).fill(0),
        right_max = new Array(size).fill(0);
    // Initialize first height into left max
    left_max[0] = height[0];
    for (let i = 1; i < size; i++) {
        // update left max with current max
        left_max[i] = Math.max(height[i], left_max[i - 1]);
    }
    // Initialize last height into right max
    right_max[size - 1] = height[size - 1];
    for (let i = size - 2; i >= 0; i--) {
        // update right max with current max
        right_max[i] = Math.max(height[i], right_max[i + 1]);
    }
    // Calculate the trapped water
    for (let i = 1; i < size - 1; i++) {
        ans += Math.min(left_max[i], right_max[i]) - height[i];
    }
    // Return amount of trapped water
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def trap(self, height: List[int]) -> int:
        # Case of empty height list
        if len(height) == 0:
            return 0
        ans = 0
        size = len(height)
        # Create left and right max arrays
        left_max, right_max = [0] * size, [0] * size
        # Initialize first height into left max
        left_max[0] = height[0]
        for i in range(1, size):
            # update left max with current max
            left_max[i] = max(height[i], left_max[i - 1])
        # Initialize last height into right max
        right_max[size - 1] = height[size - 1]
        for i in range(size - 2, -1, -1):
            # update right max with current max
            right_max[i] = max(height[i], right_max[i + 1])
        # Calculate the trapped water
        for i in range(1, size - 1):
            ans += min(left_max[i], right_max[i]) - height[i]
        # Return amount of trapped water
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function trap(height: number[]): number {
    // Case of empty height array
    if (height.length == 0) return 0;
    let ans = 0;
    let size = height.length;
    // Create left and right max arrays
    let left_max: number[] = new Array(size).fill(0);
    let right_max: number[] = new Array(size).fill(0);
    // Initialize first height into left max
    left_max[0] = height[0];
    for (let i = 1; i < size; i++) {
        // update left max with current max
        left_max[i] = Math.max(height[i], left_max[i - 1]);
    }
    // Initialize last height into right max
    right_max[size - 1] = height[size - 1];
    for (let i = size - 2; i >= 0; i--) {
        // update right max with current max
        right_max[i] = Math.max(height[i], right_max[i + 1]);
    }
    // Calculate the trapped water
    for (let i = 1; i < size - 1; i++) {
        ans += Math.min(left_max[i], right_max[i]) - height[i];
    }
    // Return amount of trapped water
    return ans;
}
```

</details>

<br>

## Approach 3: Using stacks

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int trap(int* height, int heightSize) {
    int ans = 0, current = 0;
    int* st = malloc(heightSize * sizeof(int));
    int stSize = 0;
    while (current < heightSize) {
        while (stSize != 0 && height[current] > height[st[stSize - 1]]) {
            int top = st[stSize - 1];
            stSize--;
            if (stSize == 0) break;
            int distance = current - st[stSize - 1] - 1;
            int bounded_height =
                fmin(height[current], height[st[stSize - 1]]) - height[top];
            ans += distance * bounded_height;
        }
        st[stSize++] = current++;
    }
    free(st);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, current = 0;
        stack<int> st;
        while (current < height.size()) {
            while (!st.empty() && height[current] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) break;
                int distance = current - st.top() - 1;
                int bounded_height =
                    min(height[current], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(current++);
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
    public int Trap(int[] height) {
        int ans = 0, current = 0;
        Stack<int> st = new Stack<int>();
        while (current < height.Length) {
            while (st.Count != 0 && height[current] > height[st.Peek()]) {
                int top = st.Peek();
                st.Pop();
                if (st.Count == 0)
                    break;
                int distance = current - st.Peek() - 1;
                int bounded_height =
                    Math.Min(height[current], height[st.Peek()]) - height[top];
                ans += distance * bounded_height;
            }

            st.Push(current++);
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func trap(height []int) int {
    ans := 0
    current := 0
    var st []int = make([]int, 0)
    for current < len(height) {
        for len(st) != 0 && height[current] > height[st[len(st)-1]] {
            top := st[len(st)-1]
            st = st[:len(st)-1]
            if len(st) == 0 {
                break
            }
            distance := current - st[len(st)-1] - 1
            bounded_height := min(
                height[current],
                height[st[len(st)-1]],
            ) - height[top]
            ans += distance * bounded_height
        }
        st = append(st, current)
        current++
    }
    return ans
}

func min(a int, b int) int {
    if a < b {
        return a
    } else {
        return b
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int trap(int[] height) {
        int ans = 0, current = 0;
        Deque<Integer> st = new LinkedList<Integer>();
        while (current < height.length) {
            while (!st.isEmpty() && height[current] > height[st.peek()]) {
                int top = st.peek();
                st.pop();
                if (st.isEmpty()) break;
                int distance = current - st.peek() - 1;
                int bounded_height =
                    Math.min(height[current], height[st.peek()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var trap = function (height) {
    var ans = 0;
    var current = 0;
    var st = [];
    while (current < height.length) {
        while (st.length !== 0 && height[current] > height[st[st.length - 1]]) {
            var top = st[st.length - 1];
            st.pop();
            if (st.length === 0) break;
            var distance = current - st[st.length - 1] - 1;
            var bounded_height =
                Math.min(height[current], height[st[st.length - 1]]) -
                height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def trap(self, height):
        ans = 0
        current = 0
        st = []
        while current < len(height):
            while len(st) != 0 and height[current] > height[st[-1]]:
                top = st[-1]
                st.pop()
                if len(st) == 0:
                    break
                distance = current - st[-1] - 1
                bounded_height = (
                    min(height[current], height[st[-1]]) - height[top]
                )
                ans += distance * bounded_height
            st.append(current)
            current += 1
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function trap(height: number[]): number {
    let ans = 0;
    let current = 0;
    let st = [];
    while (current < height.length) {
        while (st.length !== 0 && height[current] > height[st[st.length - 1]]) {
            let top = st[st.length - 1];
            st.pop();
            if (st.length === 0) break;
            let distance = current - st[st.length - 1] - 1;
            let bounded_height =
                Math.min(height[current], height[st[st.length - 1]]) -
                height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
}
```

</details>

<br>

## Approach 4: Using 2 pointers

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int trap(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left])
                                     : (ans += (left_max - height[left]));
            ++left;
        } else {
            height[right] >= right_max ? (right_max = height[right])
                                       : (ans += (right_max - height[right]));
            --right;
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
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= left_max ? (left_max = height[left])
                                         : ans += (left_max - height[left]);
                ++left;
            } else {
                height[right] >= right_max ? (right_max = height[right])
                                           : ans += (right_max - height[right]);
                --right;
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
    public int Trap(int[] height) {
        int left = 0, right = height.Length - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                left_max = Math.Max(left_max, height[left]);
                ans += left_max - height[left];
                ++left;
            } else {
                right_max = Math.Max(right_max, height[right]);
                ans += right_max - height[right];
                --right;
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
func trap(height []int) int {
    left := 0
    right := len(height) - 1
    ans := 0
    left_max := 0
    right_max := 0
    for left < right {
        if height[left] < height[right] {
            if height[left] >= left_max {
                left_max = height[left]
            } else {
                ans += left_max - height[left]
            }
            left++
        } else {
            if height[right] >= right_max {
                right_max = height[right]
            } else {
                ans += right_max - height[right]
            }
            right--
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
    public int trap(int[] height) {
        int left = 0, right = height.length - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                left_max = Math.max(left_max, height[left]);
                ans += left_max - height[left];
                ++left;
            } else {
                right_max = Math.max(right_max, height[right]);
                ans += right_max - height[right];
                --right;
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
var trap = function (height) {
    let left = 0,
        right = height.length - 1;
    let ans = 0;
    let left_max = 0,
        right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            left_max = Math.max(left_max, height[left]);
            ans += left_max - height[left];
            ++left;
        } else {
            right_max = Math.max(right_max, height[right]);
            ans += right_max - height[right];
            --right;
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
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left, right = 0, len(height) - 1
        ans = 0
        left_max, right_max = 0, 0
        while left < right:
            if height[left] < height[right]:
                left_max = max(left_max, height[left])
                ans += left_max - height[left]
                left += 1
            else:
                right_max = max(right_max, height[right])
                ans += right_max - height[right]
                right -= 1
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function trap(height: number[]): number {
    let left = 0,
        right = height.length - 1;
    let ans = 0;
    let left_max = 0,
        right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            left_max = Math.max(left_max, height[left]);
            ans += left_max - height[left];
            ++left;
        } else {
            right_max = Math.max(right_max, height[right]);
            ans += right_max - height[right];
            --right;
        }
    }
    return ans;
}
```

</details>
