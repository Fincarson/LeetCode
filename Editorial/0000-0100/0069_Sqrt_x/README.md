# 69. Sqrt(x)

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/sqrtx/)  
`Math` `Binary Search`

**Problem Link:** [LeetCode 69 - Sqrt(x)](https://leetcode.com/problems/sqrtx/)

## Problem

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

- For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

### Example 1

```text
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
```

### Example 2

```text
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
```

## Constraints

- 0 <= x <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Pow(x, n)](https://leetcode.com/problems/powx-n/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 69. Sqrt(x)

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Pocket Calculator Algorithm | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Binary Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Recursion + Bit Shifts | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Newton's Method | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Pocket Calculator Algorithm

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int mySqrt(int x) {
    if (x < 2) return x;
    long left = (long)(exp(0.5 * log(x)));
    long right = left + 1;
    return right * right > x ? left : right;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        long left = static_cast<long>(exp(0.5 * log(x)));
        long right = left + 1;
        return right * right > x ? left : right;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MySqrt(int x) {
        if (x < 2)
            return x;
        long left = (long)Math.Exp(0.5 * Math.Log(x));
        long right = left + 1;
        return right * right > x ? (int)left : (int)right;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func mySqrt(x int) int {
    if x < 2 {
        return x
    }
    left := int(math.Pow(math.E, 0.5*math.Log(float64(x))))
    right := left + 1
    if right*right > x {
        return left
    }
    return right
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int mySqrt(int x) {
        if (x < 2) return x;

        int left = (int) Math.pow(Math.E, 0.5 * Math.log(x));
        int right = left + 1;
        return (long) right * right > x ? left : right;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var mySqrt = function (x) {
    if (x < 2) return x;
    let left = Math.floor(Math.pow(Math.E, 0.5 * Math.log(x)));
    let right = left + 1;
    return right * right > x ? left : right;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from math import e, log


class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x

        left = int(e ** (0.5 * log(x)))
        right = left + 1
        return left if right * right > x else right
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function mySqrt(x: number): number {
    if (x < 2) return x;
    let left = Math.floor(Math.pow(Math.E, 0.5 * Math.log(x)));
    let right = left + 1;
    return right * right > x ? left : right;
}
```

</details>

<br>

## Approach 2: Binary Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// The use of long long is for the prevention of overflow.
int mySqrt(int x) {
    if (x < 2) return x;
    long long num;
    int pivot, left = 2, right = x / 2;
    while (left <= right) {
        pivot = left + (right - left) / 2;
        num = (long long)pivot * pivot;
        if (num > x)
            right = pivot - 1;
        else if (num < x)
            left = pivot + 1;
        else
            return pivot;
    }
    return right;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        long num;
        int pivot, left = 2, right = x / 2;
        while (left <= right) {
            pivot = left + (right - left) / 2;
            num = (long)pivot * pivot;
            if (num > x)
                right = pivot - 1;
            else if (num < x)
                left = pivot + 1;
            else
                return pivot;
        }
        return right;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MySqrt(int x) {
        if (x < 2)
            return x;
        long num;
        int pivot, left = 2, right = x / 2;
        while (left <= right) {
            pivot = left + (right - left) / 2;
            num = (long)pivot * pivot;
            if (num > x)
                right = pivot - 1;
            else if (num < x)
                left = pivot + 1;
            else
                return pivot;
        }

        return right;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func mySqrt(x int) int {
    if x < 2 {
        return x
    }
    var num int
    pivot, left, right := 2, 2, x/2
    for left <= right {
        pivot = left + (right-left)/2
        num = pivot * pivot
        if num > x {
            right = pivot - 1
        } else if num < x {
            left = pivot + 1
        } else {
            return pivot
        }
    }
    return right
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int mySqrt(int x) {
        if (x < 2) return x;

        long num;
        int pivot, left = 2, right = x / 2;
        while (left <= right) {
            pivot = left + (right - left) / 2;
            num = (long) pivot * pivot;
            if (num > x) right = pivot - 1;
            else if (num < x) left = pivot + 1;
            else return pivot;
        }

        return right;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var mySqrt = function (x) {
    if (x < 2) return x;
    let num;
    let pivot,
        left = 2,
        right = Math.floor(x / 2);
    while (left <= right) {
        pivot = left + Math.floor((right - left) / 2);
        num = pivot * pivot;
        if (num > x) right = pivot - 1;
        else if (num < x) left = pivot + 1;
        else return pivot;
    }
    return right;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x

        left, right = 2, x // 2

        while left <= right:
            pivot = left + (right - left) // 2
            num = pivot * pivot
            if num > x:
                right = pivot - 1
            elif num < x:
                left = pivot + 1
            else:
                return pivot

        return right
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function mySqrt(x: number): number {
    if (x < 2) return x;
    let num: number;
    let pivot,
        left = 2,
        right = Math.floor(x / 2);
    while (left <= right) {
        pivot = left + Math.floor((right - left) / 2);
        num = pivot * pivot;
        if (num > x) right = pivot - 1;
        else if (num < x) left = pivot + 1;
        else return pivot;
    }
    return right;
}
```

</details>

<br>

## Approach 3: Recursion + Bit Shifts

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// C translation
int mySqrt(int x) {
    if (x < 2) return x;
    int left = mySqrt(x >> 2) << 1;
    int right = left + 1;
    return (((long long int)right * right) > x) ? left : right;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int left = mySqrt(x >> 2) << 1;
        int right = left + 1;
        return (long long)right * right > x ? left : right;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MySqrt(int x) {
        if (x < 2)
            return x;
        int left = MySqrt(x >> 2) << 1;
        int right = left + 1;
        return (long)right * right > x ? left : right;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// Golang translation
func mySqrt(x int) int {
    if x < 2 {
        return x
    }
    left := mySqrt(x>>2) << 1
    right := left + 1
    if right*right > x {
        return left
    }
    return right
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int mySqrt(int x) {
        if (x < 2) return x;

        int left = mySqrt(x >> 2) << 1;
        int right = left + 1;
        return (long) right * right > x ? left : right;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var mySqrt = function (x) {
    if (x < 2) return x;
    var left = mySqrt(x >> 2) << 1;
    var right = left + 1;
    return right * right > x ? left : right;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x

        left = self.mySqrt(x >> 2) << 1
        right = left + 1
        return left if right * right > x else right
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function mySqrt(x: number): number {
    if (x < 2) return x;
    let left = mySqrt(x >> 2) << 1;
    let right = left + 1;
    return right * right > x ? left : right;
}
```

</details>

<br>

## Approach 4: Newton's Method

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int mySqrt(int x) {
    if (x < 2) return x;
    double x0 = x;
    double x1 = (x0 + x / x0) / 2.0;
    while (fabs(x0 - x1) >= 1) {
        x0 = x1;
        x1 = (x0 + x / x0) / 2.0;
    }
    return (int)x1;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        double x0 = x;
        double x1 = (x0 + x / x0) / 2.0;
        while (abs(x0 - x1) >= 1) {
            x0 = x1;
            x1 = (x0 + x / x0) / 2.0;
        }
        return (int)x1;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MySqrt(int x) {
        if (x < 2)
            return x;
        double x0 = x;
        double x1 = (x0 + x / x0) / 2.0;
        while (Math.Abs(x0 - x1) >= 1) {
            x0 = x1;
            x1 = (x0 + x / x0) / 2.0;
        }

        return (int)x1;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func mySqrt(x int) int {
    if x < 2 {
        return x
    }
    x0 := float64(x)
    x1 := (x0 + float64(x)/x0) / 2.0
    for math.Abs(x0-x1) >= 1 {
        x0 = x1
        x1 = (x0 + float64(x)/x0) / 2.0
    }
    return int(x1)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int mySqrt(int x) {
        if (x < 2) return x;

        double x0 = x;
        double x1 = (x0 + x / x0) / 2.0;
        while (Math.abs(x0 - x1) >= 1) {
            x0 = x1;
            x1 = (x0 + x / x0) / 2.0;
        }

        return (int) x1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var mySqrt = function (x) {
    if (x < 2) return x;
    let x0 = x;
    let x1 = (x0 + x / x0) / 2.0;
    while (Math.abs(x0 - x1) >= 1) {
        x0 = x1;
        x1 = (x0 + x / x0) / 2.0;
    }
    return Math.floor(x1);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x

        x0 = x
        x1 = (x0 + x / x0) / 2
        while abs(x0 - x1) >= 1:
            x0 = x1
            x1 = (x0 + float(x) / x0) / 2

        return int(x1)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function mySqrt(x: number): number {
    if (x < 2) return x;
    let x0 = x;
    let x1 = (x0 + x / x0) / 2.0;
    while (Math.abs(x0 - x1) >= 1) {
        x0 = x1;
        x1 = (x0 + x / x0) / 2.0;
    }
    return Math.floor(x1);
}
```

</details>
