# 3783. Mirror Distance of an Integer

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/mirror-distance-of-an-integer/)  
`Math`

**Problem Link:** [LeetCode 3783 - Mirror Distance of an Integer](https://leetcode.com/problems/mirror-distance-of-an-integer/)

## Problem

You are given an integer n.

Define its mirror distance as: abs(n - reverse(n))Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹ where reverse(n) is the integer formed by reversing the digits of n.

Return an integer denoting the mirror distance of nÃ¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹.

abs(x) denotes the absolute value of x.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= n <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3783. Mirror Distance of an Integer

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Mathematics | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Mathematics

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int reverse(int n) {
    int res = 0;
    while (n > 0) {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

int mirrorDistance(int n) { return abs(n - reverse(n)); }
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int reverse(int n) {
        int res = 0;
        while (n > 0) {
            res = res * 10 + n % 10;
            n /= 10;
        }
        return res;
    }

    int mirrorDistance(int n) { return abs(n - reverse(n)); }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int Reverse(int n) {
        int res = 0;
        while (n > 0) {
            res = res * 10 + n % 10;
            n /= 10;
        }
        return res;
    }

    public int MirrorDistance(int n) {
        return Math.Abs(n - Reverse(n));
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func reverse(n int) int {
	res := 0
	for n > 0 {
		res = res*10 + n%10
		n /= 10
	}
	return res
}

func mirrorDistance(n int) int {
	diff := n - reverse(n)
	if diff < 0 {
		return -diff
	}
	return diff
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int reverse(int n) {
        int res = 0;
        while (n > 0) {
            res = res * 10 + (n % 10);
            n /= 10;
        }
        return res;
    }

    public int mirrorDistance(int n) {
        return Math.abs(n - reverse(n));
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var reverse = function (n) {
    let res = 0;
    while (n > 0) {
        res = res * 10 + (n % 10);
        n = Math.floor(n / 10);
    }
    return res;
};

var mirrorDistance = function (n) {
    return Math.abs(n - reverse(n));
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reverse(self, n: int) -> int:
        res = 0
        while n > 0:
            res = res * 10 + n % 10
            n //= 10
        return res

    def mirrorDistance(self, n: int) -> int:
        return abs(n - self.reverse(n))
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function reverse(n: number): number {
    let res = 0;
    while (n > 0) {
        res = res * 10 + (n % 10);
        n = Math.floor(n / 10);
    }
    return res;
}

function mirrorDistance(n: number): number {
    return Math.abs(n - reverse(n));
}
```

</details>
