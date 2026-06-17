# 2843.   Count Symmetric Integers

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/count-symmetric-integers/)  
`Math` `Enumeration`

**Problem Link:** [LeetCode 2843 -   Count Symmetric Integers](https://leetcode.com/problems/count-symmetric-integers/)

## Problem

You are given two positive integers low and high.

An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to the sum of the last n digits of x. Numbers with an odd number of digits are never symmetric.

Return the number of symmetric integers in the range [low, high].

### Example 1

```text
Input: low = 1, high = 100
Output: 9
Explanation: There are 9 symmetric integers between 1 and 100: 11, 22, 33, 44, 55, 66, 77, 88, and 99.
```

### Example 2

```text
Input: low = 1200, high = 1230
Output: 4
Explanation: There are 4 symmetric integers between 1200 and 1230: 1203, 1212, 1221, and 1230.
```

## Constraints

- 1 <= low <= high <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Sum of Digits in Base K](https://leetcode.com/problems/sum-of-digits-in-base-k/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2843.   Count Symmetric Integers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Enumeration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int countSymmetricIntegers(int low, int high) {
    int res = 0;
    for (int a = low; a <= high; ++a) {
        if (a < 100 && a % 11 == 0) {
            res++;
        } else if (1000 <= a && a < 10000) {
            int left = a / 1000 + (a % 1000) / 100;
            int right = (a % 100) / 10 + a % 10;
            if (left == right) {
                res++;
            }
        }
    }
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for (int a = low; a <= high; ++a) {
            if (a < 100 && a % 11 == 0) {
                res++;
            } else if (1000 <= a && a < 10000) {
                int left = a / 1000 + (a % 1000) / 100;
                int right = (a % 100) / 10 + a % 10;
                if (left == right) {
                    res++;
                }
            }
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int CountSymmetricIntegers(int low, int high) {
        int res = 0;
        for (int a = low; a <= high; ++a) {
            if (a < 100 && a % 11 == 0) {
                res++;
            } else if (1000 <= a && a < 10000) {
                int left = a / 1000 + (a % 1000) / 100;
                int right = (a % 100) / 10 + a % 10;
                if (left == right) {
                    res++;
                }
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func countSymmetricIntegers(low int, high int) int {
	res := 0
	for a := low; a <= high; a++ {
		if a < 100 && a%11 == 0 {
			res++
		} else if 1000 <= a && a < 10000 {
			left := a/1000 + (a%1000)/100
			right := (a%100)/10 + a%10
			if left == right {
				res++
			}
		}
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for (int a = low; a <= high; ++a) {
            if (a < 100 && a % 11 == 0) {
                res++;
            } else if (1000 <= a && a < 10000) {
                int left = a / 1000 + (a % 1000) / 100;
                int right = (a % 100) / 10 + (a % 10);
                if (left == right) {
                    res++;
                }
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countSymmetricIntegers = function (low, high) {
    let res = 0;
    for (let a = low; a <= high; ++a) {
        if (a < 100 && a % 11 === 0) {
            res++;
        } else if (1000 <= a && a < 10000) {
            const left = Math.floor(a / 1000) + Math.floor((a % 1000) / 100);
            const right = Math.floor((a % 100) / 10) + (a % 10);
            if (left === right) {
                res++;
            }
        }
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        res = 0
        for a in range(low, high + 1):
            if a < 100 and a % 11 == 0:
                res += 1
            if 1000 <= a < 10000:
                left = a // 1000 + a % 1000 // 100
                right = a % 100 // 10 + a % 10
                if left == right:
                    res += 1
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countSymmetricIntegers(low: number, high: number): number {
    let res = 0;
    for (let a = low; a <= high; ++a) {
        if (a < 100 && a % 11 === 0) {
            res++;
        } else if (1000 <= a && a < 10000) {
            const left = Math.floor(a / 1000) + Math.floor((a % 1000) / 100);
            const right = Math.floor((a % 100) / 10) + (a % 10);
            if (left === right) {
                res++;
            }
        }
    }
    return res;
}
```

</details>
