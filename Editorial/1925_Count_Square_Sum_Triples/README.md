# 1925. Count Square Sum Triples

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/count-square-sum-triples/)  
`Math` `Enumeration`

**Problem Link:** [LeetCode 1925 - Count Square Sum Triples](https://leetcode.com/problems/count-square-sum-triples/)

## Problem

A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.

Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.

### Example 1

```text
Input: n = 5
Output: 2
Explanation: The square triples are (3,4,5) and (4,3,5).
```

### Example 2

```text
Input: n = 10
Output: 4
Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).
```

## Constraints

- 1 <= n <= 250

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Unequal Triplets in Array](https://leetcode.com/problems/number-of-unequal-triplets-in-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1925. Count Square Sum Triples

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Enumeration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int countTriples(int n) {
    int res = 0;
    // enumerate a and b
    for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <= n; ++b) {
            // determine if it meets the requirements
            int c = (int)sqrt(a * a + b * b + 1.0);
            if (c <= n && c * c == a * a + b * b) {
                ++res;
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
    int countTriples(int n) {
        int res = 0;
        // enumerate a and b
        for (int a = 1; a <= n; ++a) {
            for (int b = 1; b <= n; ++b) {
                // determine if it meets the requirements
                int c = int(sqrt(a * a + b * b + 1.0));
                if (c <= n && c * c == a * a + b * b) {
                    ++res;
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
    public int CountTriples(int n) {
        int res = 0;
        // enumerate a and b
        for (int a = 1; a <= n; ++a) {
            for (int b = 1; b <= n; ++b) {
                // determine if it meets the requirements
                int c = (int)Math.Sqrt(a * a + b * b + 1.0);
                if (c <= n && c * c == a * a + b * b) {
                    ++res;
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
func countTriples(n int) int {
	res := 0
	// enumerate a and b
	for a := 1; a <= n; a++ {
		for b := 1; b <= n; b++ {
			// determine if it meets the requirements
			c := int(math.Sqrt(float64(a*a + b*b + 1)))
			if c <= n && c*c == a*a+b*b {
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

    public int countTriples(int n) {
        int res = 0;
        // enumerate a and b
        for (int a = 1; a <= n; ++a) {
            for (int b = 1; b <= n; ++b) {
                // determine if it meets the requirements
                int c = (int) Math.sqrt(a * a + b * b + 1.0);
                if (c <= n && c * c == a * a + b * b) {
                    ++res;
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
var countTriples = function (n) {
    let res = 0;
    // enumerate a and b
    for (let a = 1; a <= n; a++) {
        for (let b = 1; b <= n; b++) {
            // determine if it meets the requirements
            let c = Math.floor(Math.sqrt(a * a + b * b + 1));
            if (c <= n && c * c === a * a + b * b) {
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
from math import sqrt


class Solution:
    def countTriples(self, n: int) -> int:
        res = 0
        # enumerate a and b
        for a in range(1, n + 1):
            for b in range(1, n + 1):
                # determine if it meets the requirements
                c = int(sqrt(a**2 + b**2 + 1))
                if c <= n and c**2 == a**2 + b**2:
                    res += 1
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countTriples(n: number): number {
    let res = 0;
    // enumerate a and b
    for (let a = 1; a <= n; a++) {
        for (let b = 1; b <= n; b++) {
            // determine if it meets the requirements
            let c = Math.floor(Math.sqrt(a * a + b * b + 1));
            if (c <= n && c * c === a * a + b * b) {
                res++;
            }
        }
    }
    return res;
}
```

</details>
