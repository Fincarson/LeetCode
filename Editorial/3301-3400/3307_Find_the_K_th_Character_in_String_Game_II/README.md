# 3307. Find the K-th Character in String Game II

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/)  
`Math` `Bit Manipulation` `Recursion`

**Problem Link:** [LeetCode 3307 - Find the K-th Character in String Game II](https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/)

## Problem

Alice and Bob are playing a game. Initially, Alice has a string word = "a".

You are given a positive integer k. You are also given an integer array operations, where operations[i] represents the type of the ith operation.

Now Bob will ask Alice to perform all operations in sequence:

- If operations[i] == 0, append a copy of word to itself.
- If operations[i] == 1, generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word. For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".

Return the value of the kth character in word after performing all the operations.

Note that the character 'z' can be changed to 'a' in the second type of operation.

### Example 1

### Example 2

## Constraints

- 1 <= k <= 1014
- 1 <= operations.length <= 100
- operations[i] is either 0 or 1.
- The input is generated such that word has at least k characters after all operations.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Shifting Letters](https://leetcode.com/problems/shifting-letters/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3307. Find the K-th Character in String Game II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iteration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Mathematics | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Iteration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char kthCharacter(long long k, int* operations, int operationsSize) {
    int ans = 0;
    int t;
    while (k != 1) {
        t = 63 - __builtin_clzll(k);
        if ((1LL << t) == k) {
            t--;
        }
        k = k - (1LL << t);
        if (operations[t]) {
            ans++;
        }
    }
    return 'a' + (ans % 26);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int ans = 0;
        int t;
        while (k != 1) {
            t = __lg(k);
            if (((long long)1 << t) == k) {
                t--;
            }
            k = k - ((long long)1 << t);
            if (operations[t]) {
                ans++;
            }
        }
        return 'a' + (ans % 26);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public char KthCharacter(long k, int[] operations) {
        int ans = 0;
        int t;
        while (k != 1) {
            t = (int)Math.Log(k, 2);
            if ((1L << t) == k) {
                t--;
            }
            k -= (1L << t);
            if (operations[t] != 0) {
                ans++;
            }
        }
        return (char)('a' + (ans % 26));
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func kthCharacter(k int64, operations []int) byte {
	ans := 0
	for k != 1 {
		t := bits.Len64(uint64(k)) - 1
		if (1 << t) == k {
			t--
		}
		k -= (1 << t)
		if operations[t] != 0 {
			ans++
		}
	}
	return byte('a' + (ans % 26))
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public char kthCharacter(long k, int[] operations) {
        int ans = 0;
        int t;
        while (k != 1) {
            t = 63 - Long.numberOfLeadingZeros(k);
            if ((1L << t) == k) {
                t--;
            }
            k = k - (1L << t);
            if (operations[t] != 0) {
                ans++;
            }
        }
        return (char) ('a' + (ans % 26));
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var kthCharacter = function (k, operations) {
    let ans = 0;
    while (k !== 1) {
        let t = Math.floor(Math.log2(k));
        if (Number(1n << BigInt(t)) === k) {
            t--;
        }
        k -= Number(1n << BigInt(t));
        if (operations[t]) {
            ans++;
        }
    }
    return String.fromCharCode("a".charCodeAt(0) + (ans % 26));
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def kthCharacter(self, k: int, operations: List[int]) -> str:
        ans = 0
        while k != 1:
            t = k.bit_length() - 1
            if (1 << t) == k:
                t -= 1
            k -= 1 << t
            if operations[t]:
                ans += 1
        return chr(ord("a") + (ans % 26))
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function kthCharacter(k: number, operations: number[]): string {
    let ans = 0;
    while (k !== 1) {
        let t = Math.floor(Math.log2(k));
        if (Number(1n << BigInt(t)) === k) {
            t--;
        }
        k -= Number(1n << BigInt(t));
        if (operations[t]) {
            ans++;
        }
    }
    return String.fromCharCode("a".charCodeAt(0) + (ans % 26));
}
```

</details>

<br>

## Approach 2: Mathematics

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char kthCharacter(long long k, int* operations, int operationsSize) {
    int ans = 0;
    k--;
    for (int i = (int)log2(k); i >= 0; i--) {
        if ((k >> i) & 1) {
            ans += operations[i];
        }
    }
    return 'a' + (ans % 26);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int ans = 0;
        k--;
        for (int i = __lg(k); i >= 0; i--) {
            if (k >> i & 1) {
                ans += operations[i];
            }
        }
        return 'a' + (ans % 26);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public char KthCharacter(long k, int[] operations) {
        int ans = 0;
        k--;
        for (int i = (int)Math.Log(k, 2); i >= 0; i--) {
            if ((k >> i & 1) == 1) {
                ans += operations[i];
            }
        }
        return (char)('a' + (ans % 26));
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func kthCharacter(k int64, operations []int) byte {
	ans := 0
	k--
	for i := bits.Len64(uint64(k)) - 1; i >= 0; i-- {
		if (k>>i)&1 == 1 {
			ans += operations[i]
		}
	}
	return byte('a' + (ans % 26))
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public char kthCharacter(long k, int[] operations) {
        int ans = 0;
        k--;
        for (int i = 63 - Long.numberOfLeadingZeros(k); i >= 0; i--) {
            if (((k >> i) & 1) == 1) {
                ans += operations[i];
            }
        }
        return (char) ('a' + (ans % 26));
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var kthCharacter = function (k, operations) {
    let ans = 0;
    k--;
    for (let i = Math.floor(Math.log2(k)); i >= 0; i--) {
        if ((BigInt(k) >> BigInt(i)) & 1n) {
            ans += operations[i];
        }
    }
    return String.fromCharCode("a".charCodeAt(0) + (ans % 26));
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def kthCharacter(self, k: int, operations: List[int]) -> str:
        ans = 0
        k -= 1
        for i in range(k.bit_length() - 1, -1, -1):
            if (k >> i) & 1:
                ans += operations[i]
        return chr(ord("a") + (ans % 26))
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function kthCharacter(k: number, operations: number[]): string {
    let ans = 0;
    k--;
    for (let i = Math.floor(Math.log2(k)); i >= 0; i--) {
        if ((BigInt(k) >> BigInt(i)) & 1n) {
            ans += operations[i];
        }
    }
    return String.fromCharCode("a".charCodeAt(0) + (ans % 26));
}
```

</details>
