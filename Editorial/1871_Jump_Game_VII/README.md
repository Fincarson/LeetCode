# 1871. Jump Game VII

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/jump-game-vii/)  
`String` `Dynamic Programming` `Sliding Window` `Prefix Sum`

**Problem Link:** [LeetCode 1871 - Jump Game VII](https://leetcode.com/problems/jump-game-vii/)

## Problem

You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:

- i + minJump <= j <= min(i + maxJump, s.length - 1), and
- s[j] == '0'.

Return true if you can reach index s.length - 1 in s, or false otherwise.

### Example 1

```text
Input: s = "011010", minJump = 2, maxJump = 3
Output: true
Explanation:
In the first step, move from index 0 to index 3.
In the second step, move from index 3 to index 5.
```

### Example 2

```text
Input: s = "01101110", minJump = 2, maxJump = 3
Output: false
```

## Constraints

- 2 <= s.length <= 105
- s[i] is either '0' or '1'.
- s[0] == '0'
- 1 <= minJump <= maxJump < s.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Jump Game II](https://leetcode.com/problems/jump-game-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Jump Game](https://leetcode.com/problems/jump-game/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Jump Game III](https://leetcode.com/problems/jump-game-iii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Jump Game IV](https://leetcode.com/problems/jump-game-iv/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Jump Game V](https://leetcode.com/problems/jump-game-v/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Jump Game VI](https://leetcode.com/problems/jump-game-vi/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Jump Game VII](https://leetcode.com/problems/jump-game-vii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Jump Game VIII](https://leetcode.com/problems/jump-game-viii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count Vowel Strings in Ranges](https://leetcode.com/problems/count-vowel-strings-in-ranges/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Number of Jumps to Reach the Last Index](https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1871. Jump Game VII

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Dynamic Programming + Prefix Sum Optimization | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Dynamic Programming + Prefix Sum Optimization

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool canReach(char* s, int minJump, int maxJump) {
    int n = strlen(s);
    int* f = (int*)calloc(n, sizeof(int));
    int* pre = (int*)malloc(n * sizeof(int));
    f[0] = 1;
    // since we start dynamic programming from i=minJump, we need to precompute
    // the prefix sums for the part [0, minJump)
    for (int i = 0; i < minJump; i++) {
        pre[i] = 1;
    }
    for (int i = minJump; i < n; i++) {
        int left = i - maxJump;
        int right = i - minJump;
        if (s[i] == '0') {
            int total = pre[right];
            if (left > 0) {
                total -= pre[left - 1];
            }
            f[i] = total != 0 ? 1 : 0;
        }
        pre[i] = pre[i - 1] + f[i];
    }
    bool result = (f[n - 1] == 1);
    free(f);
    free(pre);
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> f(n), pre(n);
        f[0] = 1;
        // since we start dynamic programming from i=minJump, we need to
        // precompute the prefix sums for the part [0, minJump)
        for (int i = 0; i < minJump; ++i) {
            pre[i] = 1;
        }
        for (int i = minJump; i < n; ++i) {
            int left = i - maxJump, right = i - minJump;
            if (s[i] == '0') {
                int total = pre[right] - (left <= 0 ? 0 : pre[left - 1]);
                f[i] = (total != 0);
            }
            pre[i] = pre[i - 1] + f[i];
        }
        return f[n - 1];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool CanReach(string s, int minJump, int maxJump) {
        int n = s.Length;
        int[] f = new int[n];
        int[] pre = new int[n];
        f[0] = 1;
        // since we start dynamic programming from i=minJump, we need to
        // precompute the prefix sums for the part [0, minJump)
        for (int i = 0; i < minJump; i++) {
            pre[i] = 1;
        }
        for (int i = minJump; i < n; i++) {
            int left = i - maxJump;
            int right = i - minJump;
            if (s[i] == '0') {
                int total = pre[right] - (left <= 0 ? 0 : pre[left - 1]);
                f[i] = total != 0 ? 1 : 0;
            }
            pre[i] = pre[i - 1] + f[i];
        }
        return f[n - 1] == 1;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func canReach(s string, minJump int, maxJump int) bool {
	n := len(s)
	f := make([]int, n)
	pre := make([]int, n)
	f[0] = 1
	// since we start dynamic programming from i=minJump, we need to precompute
	// the prefix sums for the part [0, minJump)
	for i := 0; i < minJump; i++ {
		pre[i] = 1
	}
	for i := minJump; i < n; i++ {
		left := i - maxJump
		right := i - minJump
		if s[i] == '0' {
			total := pre[right]
			if left > 0 {
				total -= pre[left-1]
			}
			if total != 0 {
				f[i] = 1
			} else {
				f[i] = 0
			}
		}
		pre[i] = pre[i-1] + f[i]
	}
	return f[n-1] == 1
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canReach(String s, int minJump, int maxJump) {
        int n = s.length();
        int[] f = new int[n];
        int[] pre = new int[n];
        f[0] = 1;
        // since we start dynamic programming from i=minJump, we need to precompute the prefix sums for the part [0, minJump)
        for (int i = 0; i < minJump; i++) {
            pre[i] = 1;
        }
        for (int i = minJump; i < n; i++) {
            int left = i - maxJump;
            int right = i - minJump;
            if (s.charAt(i) == '0') {
                int total = pre[right] - (left <= 0 ? 0 : pre[left - 1]);
                f[i] = total != 0 ? 1 : 0;
            }
            pre[i] = pre[i - 1] + f[i];
        }
        return f[n - 1] == 1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var canReach = function (s, minJump, maxJump) {
    const n = s.length;
    const f = new Array(n).fill(0);
    const pre = new Array(n).fill(0);
    f[0] = 1;
    // since we start dynamic programming from i=minJump, we need to precompute the prefix sums for the part [0, minJump)
    for (let i = 0; i < minJump; i++) {
        pre[i] = 1;
    }
    for (let i = minJump; i < n; i++) {
        const left = i - maxJump;
        const right = i - minJump;
        if (s[i] === "0") {
            const total = pre[right] - (left <= 0 ? 0 : pre[left - 1]);
            f[i] = total !== 0 ? 1 : 0;
        }
        pre[i] = pre[i - 1] + f[i];
    }
    return f[n - 1] === 1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        n = len(s)
        f, pre = [0] * n, [0] * n
        f[0] = 1
        # since we start dynamic programming from i=minJump, we need to precompute the prefix sums for the part [0, minJump)
        for i in range(minJump):
            pre[i] = 1
        for i in range(minJump, n):
            left, right = i - maxJump, i - minJump
            if s[i] == "0":
                total = pre[right] - (0 if left <= 0 else pre[left - 1])
                f[i] = int(total != 0)
            pre[i] = pre[i - 1] + f[i]

        return bool(f[n - 1])
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function canReach(s: string, minJump: number, maxJump: number): boolean {
    const n: number = s.length;
    const f: number[] = new Array(n).fill(0);
    const pre: number[] = new Array(n).fill(0);
    f[0] = 1;
    // since we start dynamic programming from i=minJump, we need to precompute the prefix sums for the part [0, minJump)
    for (let i = 0; i < minJump; i++) {
        pre[i] = 1;
    }
    for (let i = minJump; i < n; i++) {
        const left: number = i - maxJump;
        const right: number = i - minJump;
        if (s[i] === "0") {
            const total: number = pre[right] - (left <= 0 ? 0 : pre[left - 1]);
            f[i] = total !== 0 ? 1 : 0;
        }
        pre[i] = pre[i - 1] + f[i];
    }
    return f[n - 1] === 1;
}
```

</details>
