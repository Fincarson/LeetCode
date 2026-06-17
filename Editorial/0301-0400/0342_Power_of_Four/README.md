# 342. Power of Four

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/power-of-four/)  
`Math` `Bit Manipulation` `Recursion`

**Problem Link:** [LeetCode 342 - Power of Four](https://leetcode.com/problems/power-of-four/)

## Problem

Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

### Example 1

```text
Input: n = 16
Output: true
```

### Example 2

```text
Input: n = 5
Output: false
```

### Example 3

```text
Input: n = 1
Output: true
```

## Constraints

- -231 <= n <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Power of Two](https://leetcode.com/problems/power-of-two/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Power of Three](https://leetcode.com/problems/power-of-three/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 342. Power of Four

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force + Precomputations | Java, Python |
| Math | Java, Python |
| Bit Manipulation | Java, Python |
| Bit Manipulation + Math | Java, Python |

## Approach 1: Brute Force + Precomputations

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Powers {
  private int n = 15;
  public List<Integer> nums = new ArrayList();
  Powers() {
    int lastNum = 1;
    nums.add(lastNum);
    for (int i = 1; i < n + 1; ++i) {
      lastNum = lastNum * 4;
      nums.add(lastNum);
    }
  }
}

class Solution {
  public static Powers p = new Powers();
  public boolean isPowerOfFour(int num) {
    return p.nums.contains(num);
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Powers:
    def __init__(self):
        max_power = 15
        self.nums = nums = [1] * (max_power + 1)
        for i in range(1, max_power + 1):
            nums[i] = 4 * nums[i - 1]

class Solution:
    p = Powers()
    def isPowerOfFour(self, num: int) -> bool:
        return num in self.p.nums
```

</details>

<br>

## Approach 2: Math

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public boolean isPowerOfFour(int num) {
    return (num > 0) && (Math.log(num) / Math.log(2) % 2 == 0);
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
from math import log2
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        return num > 0 and log2(num) % 2 == 0
```

</details>

<br>

## Approach 3: Bit Manipulation

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public boolean isPowerOfFour(int num) {
    return (num > 0) && ((num & (num - 1)) == 0) && ((num & 0xaaaaaaaa) == 0);
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        return num > 0 and num & (num - 1) == 0 and num & 0xaaaaaaaa == 0
```

</details>

<br>

## Approach 4: Bit Manipulation + Math

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public boolean isPowerOfFour(int num) {
    return (num > 0) && ((num & (num - 1)) == 0) && (num % 3 == 1);
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        return num > 0 and num & (num - 1) == 0 and num % 3 == 1
```

</details>
