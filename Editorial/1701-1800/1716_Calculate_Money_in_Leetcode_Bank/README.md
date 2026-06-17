# 1716. Calculate Money in Leetcode Bank

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/calculate-money-in-leetcode-bank/)  
`Math`

**Problem Link:** [LeetCode 1716 - Calculate Money in Leetcode Bank](https://leetcode.com/problems/calculate-money-in-leetcode-bank/)

## Problem

Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.

He starts by putting in $1 on Monday, the first day. Every day from Tuesday to Sunday, he will put in $1 more than the day before. On every subsequent Monday, he will put in $1 more than the previous Monday.

Given n, return the total amount of money he will have in the Leetcode bank at the end of the nth day.

### Example 1

```text
Input: n = 4
Output: 10
Explanation: After the 4th day, the total is 1 + 2 + 3 + 4 = 10.
```

### Example 2

```text
Input: n = 10
Output: 37
Explanation: After the 10th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37. Notice that on the 2nd Monday, Hercy only puts in $2.
```

### Example 3

```text
Input: n = 20
Output: 96
Explanation: After the 20th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96.
```

## Constraints

- 1 <= n <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Distribute Money to Maximum Children](https://leetcode.com/problems/distribute-money-to-maximum-children/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1716. Calculate Money in Leetcode Bank

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulate | C++, Java, Python3 |
| Math | C++, Java, Python3 |

## Approach 1: Simulate

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int monday = 1;
        
        while (n > 0) {
            for (int day = 0; day < min(n, 7); day++) {
                ans += monday + day;
            }
            
            n -= 7;
            monday++;
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
    public int totalMoney(int n) {
        int ans = 0;
        int monday = 1;
        
        while (n > 0) {
            for (int day = 0; day < Math.min(n, 7); day++) {
                ans += monday + day;
            }
            
            n -= 7;
            monday++;
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
    def totalMoney(self, n: int) -> int:
        ans = 0
        monday = 1
        
        while n > 0:
            for day in range(min(n, 7)):
                ans += monday + day
            
            n -= 7
            monday += 1

        return ans
```

</details>

<br>

## Approach 2: Math

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int totalMoney(int n) {
        int k = n / 7;
        int F = 28;
        int L = 28 + (k - 1) * 7;
        int arithmeticSum = k * (F + L) / 2;
        
        int monday = 1 + k;
        int finalWeek = 0;
        for (int day = 0; day < n % 7; day++) {
            finalWeek += monday + day;
        }
        
        return arithmeticSum + finalWeek;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int totalMoney(int n) {
        int k = n / 7;
        int F = 28;
        int L = 28 + (k - 1) * 7;
        int arithmeticSum = k * (F + L) / 2;
        
        int monday = 1 + k;
        int finalWeek = 0;
        for (int day = 0; day < n % 7; day++) {
            finalWeek += monday + day;
        }
        
        return arithmeticSum + finalWeek;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def totalMoney(self, n: int) -> int:
        k = n // 7
        F = 28
        L = 28 + (k - 1) * 7
        arithmetic_sum = k * (F + L) // 2
        
        monday = 1 + k
        final_week = 0
        for day in range(n % 7):
            final_week += monday + day
        
        return arithmetic_sum + final_week
```

</details>
