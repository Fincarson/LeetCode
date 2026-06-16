# 3227. Vowels Game in a String

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/vowels-game-in-a-string/)  
`Math` `String` `Brainteaser` `Game Theory`

**Problem Link:** [LeetCode 3227 - Vowels Game in a String](https://leetcode.com/problems/vowels-game-in-a-string/)

## Problem

Alice and Bob are playing a game on a string.

You are given a string s, Alice and Bob will take turns playing the following game where Alice starts first:

- On Alice's turn, she has to remove any non-empty substring from s that contains an odd number of vowels.
- On Bob's turn, he has to remove any non-empty substring from s that contains an even number of vowels.

The first player who cannot make a move on their turn loses the game. We assume that both Alice and Bob play optimally.

Return true if Alice wins the game, and false otherwise.

The English vowels are: a, e, i, o, and u.

### Example 1

### Example 2

## Constraints

- 1 <= s.length <= 105
- s consists only of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3227. Vowels Game in a String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool doesAliceWin(char* s) { return strpbrk(s, "aeiou") != NULL; }
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool doesAliceWin(string s) {
        return ranges::any_of(s, [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        });
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool DoesAliceWin(string s) {
        return s.Any(c => "aeiou".Contains(c));
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func doesAliceWin(s string) bool {
	return strings.ContainsAny(s, "aeiou")
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean doesAliceWin(String s) {
        return s
            .chars()
            .anyMatch(c -> {
                return "aeiou".indexOf(c) != -1;
            });
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var doesAliceWin = function (s) {
    return [...s].some((c) => "aeiou".includes(c));
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def doesAliceWin(self, s: str) -> bool:
        return any(c in "aeiou" for c in s)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function doesAliceWin(s: string): boolean {
    return [...s].some((c) => "aeiou".includes(c));
}
```

</details>
