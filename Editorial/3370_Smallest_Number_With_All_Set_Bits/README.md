# 3370. Smallest Number With All Set Bits

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/smallest-number-with-all-set-bits/)  
`Math` `Bit Manipulation`

**Problem Link:** [LeetCode 3370 - Smallest Number With All Set Bits](https://leetcode.com/problems/smallest-number-with-all-set-bits/)

## Problem

You are given a positive number n.

Return the smallest number x greater than or equal to n, such that the binary representation of x contains only set bits

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= n <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Number of K Consecutive Bit Flips](https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Bit Flips to Convert Number](https://leetcode.com/problems/minimum-bit-flips-to-convert-number/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find Sum of Array Product of Magical Sequences](https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3370. Smallest Number With All Set Bits

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Find The Pattern | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Find The Pattern

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int smallestNumber(int n) {
    int x = 1;
    while (x < n) {
        x = x * 2 + 1;
    }
    return x;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int smallestNumber(int n) {
        int x = 1;
        while (x < n) {
            x = x * 2 + 1;
        }
        return x;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int SmallestNumber(int n) {
        int x = 1;
        while (x < n) {
            x = x * 2 + 1;
        }
        return x;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func smallestNumber(n int) int {
	x := 1
	for x < n {
		x = x*2 + 1
	}
	return x
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int smallestNumber(int n) {
        int x = 1;
        while (x < n) {
            x = x * 2 + 1;
        }
        return x;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var smallestNumber = function (n) {
    let x = 1;
    while (x < n) {
        x = x * 2 + 1;
    }
    return x;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def smallestNumber(self, n: int) -> int:
        x = 1
        while x < n:
            x = x * 2 + 1
        return x
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function smallestNumber(n: number): number {
    let x = 1;
    while (x < n) {
        x = x * 2 + 1;
    }
    return x;
}
```

</details>
