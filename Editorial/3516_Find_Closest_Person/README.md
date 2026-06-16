# 3516. Find Closest Person

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/find-closest-person/)  
`Math`

**Problem Link:** [LeetCode 3516 - Find Closest Person](https://leetcode.com/problems/find-closest-person/)

## Problem

You are given three integers x, y, and z, representing the positions of three people on a number line:

- x is the position of Person 1.
- y is the position of Person 2.
- z is the position of Person 3, who does not move.

Both Person 1 and Person 2 move toward Person 3 at the same speed.

Determine which person reaches Person 3 first:

- Return 1 if Person 1 arrives first.
- Return 2 if Person 2 arrives first.
- Return 0 if both arrive at the same time.

Return the result accordingly.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= x, y, z <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3516. Find Closest Person

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
int findClosest(int x, int y, int z) {
    int dxz = abs(x - z), dyz = abs(y - z);
    if (dxz < dyz) {
        return 1;
    } else if (dxz > dyz) {
        return 2;
    } else {
        return 0;
    }
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dxz = abs(x - z), dyz = abs(y - z);
        if (dxz < dyz) {
            return 1;
        } else if (dxz > dyz) {
            return 2;
        } else {
            return 0;
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int FindClosest(int x, int y, int z) {
        int dxz = Math.Abs(x - z), dyz = Math.Abs(y - z);
        if (dxz < dyz) {
            return 1;
        } else if (dxz > dyz) {
            return 2;
        } else {
            return 0;
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func findClosest(x int, y int, z int) int {
	dxz := int(math.Abs(float64(x - z)))
	dyz := int(math.Abs(float64(y - z)))
	if dxz < dyz {
		return 1
	} else if dxz > dyz {
		return 2
	} else {
		return 0
	}
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int findClosest(int x, int y, int z) {
        int dxz = Math.abs(x - z);
        int dyz = Math.abs(y - z);
        if (dxz < dyz) {
            return 1;
        } else if (dxz > dyz) {
            return 2;
        } else {
            return 0;
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var findClosest = function (x, y, z) {
    const dxz = Math.abs(x - z),
        dyz = Math.abs(y - z);
    if (dxz < dyz) {
        return 1;
    } else if (dxz > dyz) {
        return 2;
    } else {
        return 0;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        dxz = abs(x - z)
        dyz = abs(y - z)
        if dxz < dyz:
            return 1
        elif dxz > dyz:
            return 2
        else:
            return 0
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findClosest(x: number, y: number, z: number): number {
    const dxz = Math.abs(x - z),
        dyz = Math.abs(y - z);
    if (dxz < dyz) {
        return 1;
    } else if (dxz > dyz) {
        return 2;
    } else {
        return 0;
    }
}
```

</details>
