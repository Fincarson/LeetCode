# 2145. Count the Hidden Sequences

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/count-the-hidden-sequences/)  
`Array` `Prefix Sum`

**Problem Link:** [LeetCode 2145 - Count the Hidden Sequences](https://leetcode.com/problems/count-the-hidden-sequences/)

## Problem

You are given a 0-indexed array of n integers differences, which describes the differences between each pair of consecutive integers of a hidden sequence of length (n + 1). More formally, call the hidden sequence hidden, then we have that differences[i] = hidden[i + 1] - hidden[i].

You are further given two integers lower and upper that describe the inclusive range of values [lower, upper] that the hidden sequence can contain.

- For example, given differences = [1, -3, 4], lower = 1, upper = 6, the hidden sequence is a sequence of length 4 whose elements are in between 1 and 6 (inclusive).

		[3, 4, 1, 5] and [4, 5, 2, 6] are possible hidden sequences.
		[5, 6, 3, 7] is not possible since it contains an element greater than 6.
		[1, 2, 3, 4] is not possible since the differences are not correct.

Return the number of possible hidden sequences there are. If there are no possible sequences, return 0.

### Example 1

```text
Input: differences = [1,-3,4], lower = 1, upper = 6
Output: 2
Explanation: The possible hidden sequences are:
- [3, 4, 1, 5]
- [4, 5, 2, 6]
Thus, we return 2.
```

### Example 2

```text
Input: differences = [3,-4,5,1,-2], lower = -4, upper = 5
Output: 4
Explanation: The possible hidden sequences are:
- [-3, 0, -4, 1, 2, 0]
- [-2, 1, -3, 2, 3, 1]
- [-1, 2, -2, 3, 4, 2]
- [0, 3, -1, 4, 5, 3]
Thus, we return 4.
```

### Example 3

```text
Input: differences = [4,-7,2], lower = 3, upper = 6
Output: 0
Explanation: There are no possible hidden sequences. Thus, we return 0.
```

## Constraints

- n == differences.length
- 1 <= n <= 105
- -105 <= differences[i] <= 105
- -105 <= lower <= upper <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2145. Count the Hidden Sequences

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Determine the Difference Between the Hidden Array's Upper and Lower Bounds | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Determine the Difference Between the Hidden Array's Upper and Lower Bounds

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int numberOfArrays(int* differences, int differencesSize, int lower,
                   int upper) {
    int x = 0, y = 0, cur = 0;
    for (int i = 0; i < differencesSize; i++) {
        cur += differences[i];
        x = (x < cur) ? x : cur;
        y = (y > cur) ? y : cur;
        if (y - x > upper - lower) {
            return 0;
        }
    }
    return (upper - lower) - (y - x) + 1;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int x = 0, y = 0, cur = 0;
        for (int d : differences) {
            cur += d;
            x = min(x, cur);
            y = max(y, cur);
            if (y - x > upper - lower) {
                return 0;
            }
        }
        return (upper - lower) - (y - x) + 1;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int NumberOfArrays(int[] differences, int lower, int upper) {
        int x = 0, y = 0, cur = 0;
        foreach (var d in differences) {
            cur += d;
            x = Math.Min(x, cur);
            y = Math.Max(y, cur);
            if (y - x > upper - lower) {
                return 0;
            }
        }
        return (upper - lower) - (y - x) + 1;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func numberOfArrays(differences []int, lower int, upper int) int {
	var x, y, cur int
	for _, d := range differences {
		cur += d
		x, y = min(x, cur), max(y, cur)
		if y-x > upper-lower {
			return 0
		}
	}
	return (upper - lower) - (y - x) + 1
}

func min(x, y int) int {
	if x > y {
		return y
	}
	return x
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numberOfArrays(int[] differences, int lower, int upper) {
        int x = 0, y = 0, cur = 0;
        for (int d : differences) {
            cur += d;
            x = Math.min(x, cur);
            y = Math.max(y, cur);
            if (y - x > upper - lower) {
                return 0;
            }
        }
        return (upper - lower) - (y - x) + 1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numberOfArrays = function (differences, lower, upper) {
    let x = 0,
        y = 0,
        cur = 0;
    for (let d of differences) {
        cur += d;
        x = Math.min(x, cur);
        y = Math.max(y, cur);
        if (y - x > upper - lower) {
            return 0;
        }
    }
    return upper - lower - (y - x) + 1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfArrays(
        self, differences: List[int], lower: int, upper: int
    ) -> int:
        x = y = cur = 0
        for d in differences:
            cur += d
            x = min(x, cur)
            y = max(y, cur)
            if y - x > upper - lower:
                return 0
        return (upper - lower) - (y - x) + 1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function numberOfArrays(
    differences: number[],
    lower: number,
    upper: number,
): number {
    let x = 0,
        y = 0,
        cur = 0;
    for (let d of differences) {
        cur += d;
        x = Math.min(x, cur);
        y = Math.max(y, cur);
        if (y - x > upper - lower) {
            return 0;
        }
    }
    return upper - lower - (y - x) + 1;
}
```

</details>
