# 2749. Minimum Operations to Make the Integer Zero

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/)  
`Bit Manipulation` `Brainteaser` `Enumeration`

**Problem Link:** [LeetCode 2749 - Minimum Operations to Make the Integer Zero](https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/)

## Problem

You are given two integers num1 and num2.

In one operation, you can choose integer i in the range [0, 60] and subtract 2i + num2 from num1.

Return the integer denoting the minimum number of operations needed to make num1 equal to 0.

If it is impossible to make num1 equal to 0, return -1.

### Example 1

```text
Input: num1 = 3, num2 = -2
Output: 3
Explanation: We can make 3 equal to 0 with the following operations:
- We choose i = 2 and subtract 22 + (-2) from 3, 3 - (4 + (-2)) = 1.
- We choose i = 2 and subtract 22 + (-2) from 1, 1 - (4 + (-2)) = -1.
- We choose i = 0 and subtract 20 + (-2) from -1, (-1) - (1 + (-2)) = 0.
It can be proven, that 3 is the minimum number of operations that we need to perform.
```

### Example 2

```text
Input: num1 = 5, num2 = 7
Output: -1
Explanation: It can be proven, that it is impossible to make 5 equal to 0 with the given operation.
```

## Constraints

- 1 <= num1 <= 109
- -109 <= num2 <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Broken Calculator](https://leetcode.com/problems/broken-calculator/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Operations to Reduce X to Zero](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2749. Minimum Operations to Make the Integer Zero

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
int makeTheIntegerZero(int num1, int num2) {
    int k = 1;
    while (1) {
        long long x = (long long)num1 - (long long)num2 * k;
        if (x < k) {
            return -1;
        }
        if (k >= __builtin_popcountll(x)) {
            return k;
        }
        k++;
    }
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int k = 1;
        while (true) {
            long long x = num1 - static_cast<long long>(num2) * k;
            if (x < k) {
                return -1;
            }
            if (k >= __builtin_popcountll(x)) {
                return k;
            }
            k++;
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MakeTheIntegerZero(int num1, int num2) {
        int k = 1;
        while (true) {
            long x = num1 - (long)num2 * k;
            if (x < k) {
                return -1;
            }
            if (k >= BitCount(x)) {
                return k;
            }
            k++;
        }
    }

    private int BitCount(long n) {
        int count = 0;
        while (n != 0) {
            count++;
            n &= (n - 1);
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func makeTheIntegerZero(num1 int, num2 int) int {
	k := 1
	for {
		x := int64(num1) - int64(num2)*int64(k)
		if x < int64(k) {
			return -1
		}
		if k >= bitCount(x) {
			return k
		}
		k++
	}
}

func bitCount(n int64) int {
	count := 0
	for n != 0 {
		count++
		n &= n - 1
	}
	return count
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int makeTheIntegerZero(int num1, int num2) {
        int k = 1;
        while (true) {
            long x = num1 - (long) num2 * k;
            if (x < k) {
                return -1;
            }
            if (k >= Long.bitCount(x)) {
                return k;
            }
            k++;
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var makeTheIntegerZero = function (num1, num2) {
    let k = 1;
    while (true) {
        let x = BigInt(num1) - BigInt(num2) * BigInt(k);
        if (x < BigInt(k)) {
            return -1;
        }
        if (k >= bitCount(x)) {
            return k;
        }
        k++;
    }
};

function bitCount(n) {
    let count = 0;
    while (n !== 0n) {
        count++;
        n &= n - 1n;
    }
    return count;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        k = 1
        while True:
            x = num1 - num2 * k
            if x < k:
                return -1
            if k >= x.bit_count():
                return k
            k += 1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function makeTheIntegerZero(num1: number, num2: number): number {
    let k = 1;
    while (true) {
        let x: bigint = BigInt(num1) - BigInt(num2) * BigInt(k);
        if (x < BigInt(k)) {
            return -1;
        }
        if (k >= bitCount(x)) {
            return k;
        }
        k++;
    }
}

function bitCount(n: bigint): number {
    let count = 0;
    while (n !== 0n) {
        count++;
        n &= n - 1n;
    }
    return count;
}
```

</details>
