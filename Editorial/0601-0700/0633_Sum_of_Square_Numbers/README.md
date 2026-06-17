# 633. Sum of Square Numbers

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/sum-of-square-numbers/)  
`Math` `Two Pointers` `Binary Search`

**Problem Link:** [LeetCode 633 - Sum of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers/)

## Problem

Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

### Example 1

```text
Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
```

### Example 2

```text
Input: c = 3
Output: false
```

## Constraints

- 0 <= c <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Sum of Squares of Special Elements ](https://leetcode.com/problems/sum-of-squares-of-special-elements/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 633. Sum of Square Numbers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Better Brute Force | C++, Java, Python3 |
| Using Sqrt Function | C++, Java, Python3 |
| Binary Search | C++, Java, Python3 |
| Fermat Theorem | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            for (long b = 0; b * b <= c; b++) {
                if (a * a + b * b == c) return true;
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public boolean judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            for (long b = 0; b * b <= c; b++) {
                if (a * a + b * b == c) return true;
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        a = 0
        while a * a <= c:
            b = 0
            while b * b <= c:
                if a * a + b * b == c:
                    return True
                b += 1
            a += 1
        return False
```

</details>

<br>

## Approach 2: Better Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            long b = c - (a * a);
            long i = 1, sum = 0;
            while (sum < b) {
                sum += i;
                i += 2;
            }
            if (sum == b) return true;
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public boolean judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            int b = c - (int) (a * a);
            int i = 1, sum = 0;
            while (sum < b) {
                sum += i;
                i += 2;
            }
            if (sum == b) return true;
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        a = 0
        while a * a <= c:
            b = c - a * a
            i = 1
            sum = 0
            while sum < b:
                sum += i
                i += 2
            if sum == b:
                return True
            a += 1
        return False
```

</details>

<br>

## Approach 3: Using Sqrt Function

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            double b = sqrt(c - a * a);
            if (b == (int)b) return true;
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public boolean judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            double b = Math.sqrt(c - a * a);
            if (b == (int) b) return true;
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def judgeSquareSum(self, c):
        a = 0
        while a * a <= c:
            b = (c - a * a) ** 0.5
            if b == int(b):
                return True
            a += 1
        return False
```

</details>

<br>

## Approach 4: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            int b = c - (int)(a * a);
            if (binary_search(0, b, b)) return true;
        }
        return false;
    }
    bool binary_search(long s, long e, int n) {
        if (s > e) return false;
        long mid = s + (e - s) / 2;
        if (mid * mid == n) return true;
        if (mid * mid > n) return binary_search(s, mid - 1, n);
        return binary_search(mid + 1, e, n);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public boolean judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            int b = c - (int) (a * a);
            if (binary_search(0, b, b)) return true;
        }
        return false;
    }

    public boolean binary_search(long s, long e, int n) {
        if (s > e) return false;
        long mid = s + (e - s) / 2;
        if (mid * mid == n) return true;
        if (mid * mid > n) return binary_search(s, mid - 1, n);
        return binary_search(mid + 1, e, n);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def judgeSquareSum(self, c):
        def binary_search(s, e, n):
            if s > e:
                return False
            mid = s + (e - s) // 2
            if mid * mid == n:
                return True
            elif mid * mid > n:
                return binary_search(s, mid - 1, n)
            else:
                return binary_search(mid + 1, e, n)

        for a in range(
            int(c**0.5) + 1
        ):  # equivalent to `for (long a = 0; a * a <= c; a++)` in Java
            b = c - a * a
            if binary_search(0, b, b):
                return True
        return False
```

</details>

<br>

## Approach 5: Fermat Theorem

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = 2; i * i <= c; i++) {
            int count = 0;
            while (c % i == 0) {
                count++;
                c /= i;
            }
            if (i % 4 == 3 && count % 2 != 0) return false;
        }
        return c % 4 != 3;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public boolean judgeSquareSum(int c) {
        for (int i = 2; i * i <= c; i++) {
            int count = 0;
            if (c % i == 0) {
                while (c % i == 0) {
                    count++;
                    c /= i;
                }
                if (i % 4 == 3 && count % 2 != 0) return false;
            }
        }
        return c % 4 != 3;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        i = 2
        while i * i <= c:
            count = 0
            while c % i == 0:
                count += 1
                c //= i
            if i % 4 == 3 and count % 2 != 0:
                return False
            i += 1
        return c % 4 != 3
```

</details>
