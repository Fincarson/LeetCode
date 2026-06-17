# 3304. Find the K-th Character in String Game I

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/)  
`Math` `Bit Manipulation` `Recursion` `Simulation`

**Problem Link:** [LeetCode 3304 - Find the K-th Character in String Game I](https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/)

## Problem

Alice and Bob are playing a game. Initially, Alice has a string word = "a".

You are given a positive integer k.

Now Bob will ask Alice to perform the following operation forever:

- Generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word.

For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".

Return the value of the kth character in word, after enough operations have been done for word to have at least k characters.

### Example 1

### Example 2

## Constraints

- 1 <= k <= 500

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Shifting Letters](https://leetcode.com/problems/shifting-letters/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3304. Find the K-th Character in String Game I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Iteration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Iteration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char kthCharacter(int k) {
    int ans = 0;
    int t;
    while (k != 1) {
        t = 31 - __builtin_clz(k);
        if ((1 << t) == k) {
            t--;
        }
        k = k - (1 << t);
        ans++;
    }
    return 'a' + ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    char kthCharacter(int k) {
        int ans = 0;
        int t;
        while (k != 1) {
            t = __lg(k);
            if ((1 << t) == k) {
                t--;
            }
            k = k - (1 << t);
            ans++;
        }
        return 'a' + ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public char KthCharacter(int k) {
        int ans = 0;
        int t;
        while (k != 1) {
            t = (int)Math.Log(k, 2);
            if ((1 << t) == k) {
                t--;
            }
            k = k - (1 << t);
            ans++;
        }
        return (char)('a' + ans);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func kthCharacter(k int) byte {
	ans := 0
	for k != 1 {
		t := bits.Len(uint(k)) - 1
		if 1<<t == k {
			t--
		}
		k -= 1 << t
		ans++
	}
	return byte('a' + ans)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public char kthCharacter(int k) {
        int ans = 0;
        int t;
        while (k != 1) {
            t = 31 - Integer.numberOfLeadingZeros(k);
            if ((1 << t) == k) {
                t--;
            }
            k = k - (1 << t);
            ans++;
        }
        return (char) ('a' + ans);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var kthCharacter = function (k) {
    let ans = 0;
    while (k !== 1) {
        let t = 31 - Math.clz32(k);
        if (1 << t === k) {
            t--;
        }
        k -= 1 << t;
        ans++;
    }
    return String.fromCharCode("a".charCodeAt(0) + ans);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def kthCharacter(self, k: int) -> str:
        ans = 0
        while k != 1:
            t = k.bit_length() - 1
            if (1 << t) == k:
                t -= 1
            k -= 1 << t
            ans += 1
        return chr(ord("a") + ans)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function kthCharacter(k: number): string {
    let ans = 0;
    while (k !== 1) {
        let t = 31 - Math.clz32(k);
        if (1 << t === k) {
            t--;
        }
        k -= 1 << t;
        ans++;
    }
    return String.fromCharCode("a".charCodeAt(0) + ans);
}
```

</details>
