# 3577. Count the Number of Computer Unlocking Permutations

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/)  
`Array` `Math` `Brainteaser` `Combinatorics`

**Problem Link:** [LeetCode 3577 - Count the Number of Computer Unlocking Permutations](https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/)

## Problem

You are given an array complexity of length n.

There are n locked computers in a room with labels from 0 to n - 1, each with its own unique password. The password of the computer i has a complexity complexity[i].

The password for the computer labeled 0 is already decrypted and serves as the root. All other computers must be unlocked using it or another previously unlocked computer, following this information:

- You can decrypt the password for the computer i using the password for computer j, where j is any integer less than i with a lower complexity. (i.e. j < i and complexity[j] < complexity[i])
- To decrypt the password for computer i, you must have already unlocked a computer j such that j < i and complexity[j] < complexity[i].

Find the number of permutations of [0, 1, 2, ..., (n - 1)] that represent a valid order in which the computers can be unlocked, starting from computer 0 as the only initially unlocked one.

Since the answer may be large, return it modulo 109 + 7.

Note that the password for the computer with label 0 is decrypted, and not the computer with the first position in the permutation.

### Example 1

### Example 2

## Constraints

- 2 <= complexity.length <= 105
- 1 <= complexity[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Clumsy Factorial](https://leetcode.com/problems/clumsy-factorial/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3577. Count the Number of Computer Unlocking Permutations

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Brain Teaser | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Brain Teaser

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int countPermutations(int* complexity, int complexitySize) {
    int n = complexitySize;
    for (int i = 1; i < n; i++) {
        if (complexity[i] <= complexity[0]) {
            return 0;
        }
    }

    long long ans = 1;
    int mod = 1000000007;
    for (int i = 2; i < n; i++) {
        ans = ans * i % mod;
    }
    return (int)ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        if (*min_element(complexity.begin() + 1, complexity.end()) <=
            complexity[0]) {
            return 0;
        }

        int mod = 1000000007;
        int ans = 1;
        for (int i = 2; i < n; ++i) {
            ans = static_cast<long long>(ans) * i % mod;
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int CountPermutations(int[] complexity) {
        int n = complexity.Length;
        for (int i = 1; i < n; i++) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
        }

        int ans = 1;
        int mod = 1000000007;
        for (int i = 2; i < n; i++) {
            ans = (int)((long)ans * i % mod);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func countPermutations(complexity []int) int {
	n := len(complexity)
	for i := 1; i < n; i++ {
		if complexity[i] <= complexity[0] {
			return 0
		}
	}

	ans := 1
	mod := 1000000007
	for i := 2; i < n; i++ {
		ans = ans * i % mod
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countPermutations(int[] complexity) {
        int n = complexity.length;
        for (int i = 1; i < n; i++) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
        }

        int ans = 1;
        int mod = 1000000007;
        for (int i = 2; i < n; i++) {
            ans = (int) (((long) ans * i) % mod);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countPermutations = function (complexity) {
    const n = complexity.length;
    for (let i = 1; i < n; i++) {
        if (complexity[i] <= complexity[0]) {
            return 0;
        }
    }

    let ans = 1;
    const mod = 1000000007;
    for (let i = 2; i < n; i++) {
        ans = (ans * i) % mod;
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countPermutations(self, complexity: List[int]) -> int:
        n = len(complexity)
        for i in range(1, n):
            if complexity[i] <= complexity[0]:
                return 0

        ans, mod = 1, 10**9 + 7
        for i in range(2, n):
            ans = ans * i % mod
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countPermutations(complexity: number[]): number {
    const n = complexity.length;
    for (let i = 1; i < n; i++) {
        if (complexity[i] <= complexity[0]) {
            return 0;
        }
    }

    let ans = 1;
    const mod = 1000000007;
    for (let i = 2; i < n; i++) {
        ans = (ans * i) % mod;
    }
    return ans;
}
```

</details>
