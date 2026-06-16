# 3021. Alice and Bob Playing Flower Game

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/alice-and-bob-playing-flower-game/)  
`Math`

**Problem Link:** [LeetCode 3021 - Alice and Bob Playing Flower Game](https://leetcode.com/problems/alice-and-bob-playing-flower-game/)

## Problem

Alice and Bob are playing a turn-based game on a field, with two lanes of flowers between them. There are x flowers in the first lane between Alice and Bob, and y flowers in the second lane between them.

The game proceeds as follows:

Given two integers, n and m, the task is to compute the number of possible pairs (x, y) that satisfy the conditions:

- Alice must win the game according to the described rules.
- The number of flowers x in the first lane must be in the range [1,n].
- The number of flowers y in the second lane must be in the range [1,m].

Return the number of possible pairs (x, y) that satisfy the conditions mentioned in the statement.

### Example 1

```text
Input: n = 3, m = 2
Output: 3
Explanation: The following pairs satisfy conditions described in the statement: (1,2), (3,2), (2,1).
```

### Example 2

```text
Input: n = 1, m = 1
Output: 0
Explanation: No pairs satisfy the conditions described in the statement.
```

## Constraints

- 1 <= n, m <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3021. Alice and Bob Playing Flower Game

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
long long flowerGame(int n, int m) { return (long long)m * n / 2; }
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long flowerGame(int n, int m) { return (long long)m * n / 2; }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public long FlowerGame(int n, int m) {
        return (long)m * n / 2;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func flowerGame(n int, m int) int64 {
	return int64(m) * int64(n) / 2
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long flowerGame(int n, int m) {
        return ((long) m * n) / 2;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var flowerGame = function (n, m) {
    return Math.floor((m * n) / 2);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        return (m * n) // 2
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function flowerGame(n: number, m: number): number {
    return Math.floor((m * n) / 2);
}
```

</details>
