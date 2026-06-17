# 2833. Furthest Point From Origin

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/furthest-point-from-origin/)  
`String` `Counting`

**Problem Link:** [LeetCode 2833 - Furthest Point From Origin](https://leetcode.com/problems/furthest-point-from-origin/)

## Problem

You are given a string moves of length n consisting only of characters 'L', 'R', and '_'. The string represents your movement on a number line starting from the origin 0.

In the ith move, you can choose one of the following directions:

- move to the left if moves[i] = 'L' or moves[i] = '_'
- move to the right if moves[i] = 'R' or moves[i] = '_'

Return the distance from the origin of the furthest point you can get to after n moves.

### Example 1

```text
Input: moves = "L_RL__R"
Output: 3
Explanation: The furthest point we can reach from the origin 0 is point -3 through the following sequence of moves "LLRLLLR".
```

### Example 2

```text
Input: moves = "_R__LL_"
Output: 5
Explanation: The furthest point we can reach from the origin 0 is point -5 through the following sequence of moves "LRLLLLL".
```

### Example 3

```text
Input: moves = "_______"
Output: 7
Explanation: The furthest point we can reach from the origin 0 is point 7 through the following sequence of moves "RRRRRRR".
```

## Constraints

- 1 <= moves.length == n <= 50
- moves consists only of characters 'L', 'R' and '_'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Robot Return to Origin](https://leetcode.com/problems/robot-return-to-origin/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2833. Furthest Point From Origin

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: One Pass | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: One Pass

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int furthestDistanceFromOrigin(char* moves) {
    int L = 0, R = 0, B = 0;
    int len = strlen(moves);
    for (int i = 0; i < len; i++) {
        char c = moves[i];
        if (c == 'L') {
            L++;
        } else if (c == 'R') {
            R++;
        } else {
            B++;
        }
    }
    return abs(L - R) + B;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0, R = 0, B = 0;
        for (auto c : moves) {
            if (c == 'L') {
                L++;
            } else if (c == 'R') {
                R++;
            } else {
                B++;
            }
        }
        return abs(L - R) + B;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int FurthestDistanceFromOrigin(string moves) {
        int L = 0, R = 0, B = 0;
        foreach (char c in moves) {
            if (c == 'L') {
                L++;
            } else if (c == 'R') {
                R++;
            } else {
                B++;
            }
        }
        return Math.Abs(L - R) + B;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func furthestDistanceFromOrigin(moves string) int {
	L, R, B := 0, 0, 0
	for _, c := range moves {
		if c == 'L' {
			L++
		} else if c == 'R' {
			R++
		} else {
			B++
		}
	}
	return int(math.Abs(float64(L-R))) + B
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int furthestDistanceFromOrigin(String moves) {
        int L = 0;
        int R = 0;
        int B = 0;
        for (char c : moves.toCharArray()) {
            if (c == 'L') {
                L++;
            } else if (c == 'R') {
                R++;
            } else {
                B++;
            }
        }
        return Math.abs(L - R) + B;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var furthestDistanceFromOrigin = function (moves) {
    let L = 0,
        R = 0,
        B = 0;
    for (const c of moves) {
        if (c === "L") {
            L++;
        } else if (c === "R") {
            R++;
        } else {
            B++;
        }
    }
    return Math.abs(L - R) + B;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        return abs(moves.count("R") - moves.count("L")) + moves.count("_")
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function furthestDistanceFromOrigin(moves: string): number {
    let L = 0,
        R = 0,
        B = 0;
    for (const c of moves) {
        if (c === "L") {
            L++;
        } else if (c === "R") {
            R++;
        } else {
            B++;
        }
    }
    return Math.abs(L - R) + B;
}
```

</details>
