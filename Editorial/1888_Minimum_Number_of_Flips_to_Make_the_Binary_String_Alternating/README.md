# 1888. Minimum Number of Flips to Make the Binary String Alternating

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/)  
`String` `Dynamic Programming` `Sliding Window`

**Problem Link:** [LeetCode 1888 - Minimum Number of Flips to Make the Binary String Alternating](https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/)

## Problem

You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:

- Type-1: Remove the character at the start of the string s and append it to the end of the string.
- Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.

Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

The string is called alternating if no two adjacent characters are equal.

- For example, the strings "010" and "1010" are alternating, while the string "0100" is not.

### Example 1

```text
Input: s = "111000"
Output: 2
Explanation: Use the first operation two times to make s = "100011".
Then, use the second operation on the third and sixth elements to make s = "101010".
```

### Example 2

```text
Input: s = "010"
Output: 0
Explanation: The string is already alternating.
```

### Example 3

```text
Input: s = "1110"
Output: 1
Explanation: Use the second operation on the second element to make s = "1010".
```

## Constraints

- 1 <= s.length <= 105
- s[i] is either '0' or '1'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Operations to Make the Array Alternating](https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1888. Minimum Number of Flips to Make the Binary String Alternating

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Analysis + Prefix Sum + Suffix Sum | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Analysis + Prefix Sum + Suffix Sum

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int I(char ch, int x) { return (ch - '0') == x ? 1 : 0; }

int minFlips(char* s) {
    int n = strlen(s);
    int** pre = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        pre[i] = (int*)malloc(2 * sizeof(int));
    }
    // If n is an odd number, it is also necessary to calculate suf
    int** suf = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        suf[i] = (int*)malloc(2 * sizeof(int));
    }

    // Note the boundary case when i=0
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            pre[i][0] = I(s[i], 1);
            pre[i][1] = I(s[i], 0);
        } else {
            pre[i][0] = pre[i - 1][1] + I(s[i], 1);
            pre[i][1] = pre[i - 1][0] + I(s[i], 0);
        }
    }

    int ans = fmin(pre[n - 1][0], pre[n - 1][1]);
    if (n % 2 == 1) {
        // Note the boundary case when i = n - 1
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) {
                suf[i][0] = I(s[i], 1);
                suf[i][1] = I(s[i], 0);
            } else {
                suf[i][0] = suf[i + 1][1] + I(s[i], 1);
                suf[i][1] = suf[i + 1][0] + I(s[i], 0);
            }
        }
        for (int i = 0; i + 1 < n; ++i) {
            ans = fmin(ans, pre[i][0] + suf[i + 1][0]);
            ans = fmin(ans, pre[i][1] + suf[i + 1][1]);
        }
    }

    // Release suf memory, release pre memory
    for (int i = 0; i < n; i++) {
        free(suf[i]);
        free(pre[i]);
    }
    free(suf);
    free(pre);

    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minFlips(string s) {
        // Characteristic function
        auto I = [](char ch, int x) -> int { return ch - '0' == x; };

        int n = s.size();
        vector<vector<int>> pre(n, vector<int>(2));
        // Note the boundary case when i=0
        for (int i = 0; i < n; ++i) {
            pre[i][0] = (i == 0 ? 0 : pre[i - 1][1]) + I(s[i], 1);
            pre[i][1] = (i == 0 ? 0 : pre[i - 1][0]) + I(s[i], 0);
        }

        int ans = min(pre[n - 1][0], pre[n - 1][1]);
        if (n % 2 == 1) {
            // If n is an odd number, it is also necessary to calculate suf
            vector<vector<int>> suf(n, vector<int>(2));
            // Note the boundary case when i = n - 1
            for (int i = n - 1; i >= 0; --i) {
                suf[i][0] = (i == n - 1 ? 0 : suf[i + 1][1]) + I(s[i], 1);
                suf[i][1] = (i == n - 1 ? 0 : suf[i + 1][0]) + I(s[i], 0);
            }
            for (int i = 0; i + 1 < n; ++i) {
                ans = min(ans, pre[i][0] + suf[i + 1][0]);
                ans = min(ans, pre[i][1] + suf[i + 1][1]);
            }
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
    public int MinFlips(string s) {
        // Characteristic function
        Func<char, int, int> I = (ch, x) => ch - '0' == x ? 1 : 0;
        int n = s.Length;
        int[,] pre = new int[n, 2];

        // Note the boundary case when i=0
        for (int i = 0; i < n; ++i) {
            pre[i, 0] = (i == 0 ? 0 : pre[i - 1, 1]) + I(s[i], 1);
            pre[i, 1] = (i == 0 ? 0 : pre[i - 1, 0]) + I(s[i], 0);
        }

        int ans = Math.Min(pre[n - 1, 0], pre[n - 1, 1]);
        if (n % 2 == 1) {
            // If n is an odd number, it is also necessary to calculate suf
            int[,] suf = new int[n, 2];
            // Note the boundary case when i = n - 1
            for (int i = n - 1; i >= 0; --i) {
                suf[i, 0] = (i == n - 1 ? 0 : suf[i + 1, 1]) + I(s[i], 1);
                suf[i, 1] = (i == n - 1 ? 0 : suf[i + 1, 0]) + I(s[i], 0);
            }
            for (int i = 0; i + 1 < n; ++i) {
                ans = Math.Min(ans, pre[i, 0] + suf[i + 1, 0]);
                ans = Math.Min(ans, pre[i, 1] + suf[i + 1, 1]);
            }
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minFlips(s string) int {
	// Characteristic function
	I := func(ch byte, x int) int {
		if int(ch-'0') == x {
			return 1
		}
		return 0
	}

	n := len(s)
	// Using slice storage
	pre := make([][2]int, n)
	// Note the boundary case when i=0
	for i := 0; i < n; i++ {
		if i == 0 {
			pre[i][0] = I(s[i], 1)
			pre[i][1] = I(s[i], 0)
		} else {
			pre[i][0] = pre[i-1][1] + I(s[i], 1)
			pre[i][1] = pre[i-1][0] + I(s[i], 0)
		}
	}

	ans := min(pre[n-1][0], pre[n-1][1])
	// If the length is odd, consider the move operation
	if n%2 == 1 {
		// If n is an odd number, it is also necessary to calculate suf
		suf := make([][2]int, n)
		// Note the boundary case when i = n - 1
		for i := n - 1; i >= 0; i-- {
			if i == n-1 {
				suf[i][0] = I(s[i], 1)
				suf[i][1] = I(s[i], 0)
			} else {
				suf[i][0] = suf[i+1][1] + I(s[i], 1)
				suf[i][1] = suf[i+1][0] + I(s[i], 0)
			}
		}

		for i := 0; i+1 < n; i++ {
			ans = min(ans, pre[i][0]+suf[i+1][0])
			ans = min(ans, pre[i][1]+suf[i+1][1])
		}
	}

	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minFlips(String s) {
        int n = s.length();
        int[][] pre = new int[n][2];

        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            // Compute the prefix array
            pre[i][0] = (i == 0 ? 0 : pre[i - 1][1]) + (ch == '1' ? 1 : 0);
            pre[i][1] = (i == 0 ? 0 : pre[i - 1][0]) + (ch == '0' ? 1 : 0);
        }

        int ans = Math.min(pre[n - 1][0], pre[n - 1][1]);
        // If the length is odd, consider the move operation
        if (n % 2 == 1) {
            int[][] suf = new int[n][2];
            for (int i = n - 1; i >= 0; i--) {
                char ch = s.charAt(i);
                // Suffix Array Construction
                suf[i][0] =
                    (i == n - 1 ? 0 : suf[i + 1][1]) + (ch == '1' ? 1 : 0);
                suf[i][1] =
                    (i == n - 1 ? 0 : suf[i + 1][0]) + (ch == '0' ? 1 : 0);
            }

            // Traverse all split points
            for (int i = 0; i < n - 1; i++) {
                ans = Math.min(ans, pre[i][0] + suf[i + 1][0]);
                ans = Math.min(ans, pre[i][1] + suf[i + 1][1]);
            }
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minFlips = function (s) {
    // Characteristic function
    const I = (ch, x) => (parseInt(ch) === x ? 1 : 0);

    const n = s.length;
    const pre = new Array(n);
    for (let i = 0; i < n; i++) {
        pre[i] = new Array(2);
    }

    // Note the boundary case when i=0
    for (let i = 0; i < n; ++i) {
        if (i === 0) {
            pre[i][0] = I(s[i], 1);
            pre[i][1] = I(s[i], 0);
        } else {
            pre[i][0] = pre[i - 1][1] + I(s[i], 1);
            pre[i][1] = pre[i - 1][0] + I(s[i], 0);
        }
    }

    let ans = Math.min(pre[n - 1][0], pre[n - 1][1]);
    if (n % 2 === 1) {
        // If n is an odd number, it is also necessary to calculate suf
        const suf = new Array(n);
        for (let i = 0; i < n; i++) {
            suf[i] = new Array(2);
        }

        // Note the boundary case when i = n - 1
        for (let i = n - 1; i >= 0; --i) {
            if (i === n - 1) {
                suf[i][0] = I(s[i], 1);
                suf[i][1] = I(s[i], 0);
            } else {
                suf[i][0] = suf[i + 1][1] + I(s[i], 1);
                suf[i][1] = suf[i + 1][0] + I(s[i], 0);
            }
        }

        for (let i = 0; i + 1 < n; ++i) {
            ans = Math.min(ans, pre[i][0] + suf[i + 1][0]);
            ans = Math.min(ans, pre[i][1] + suf[i + 1][1]);
        }
    }

    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minFlips(self, s: str) -> int:
        # Characteristic function
        I = lambda ch, x: int(ord(ch) - ord("0") == x)

        n = len(s)
        pre = [[0, 0] for _ in range(n)]
        # Note the boundary case when i=0
        for i in range(n):
            pre[i][0] = (0 if i == 0 else pre[i - 1][1]) + I(s[i], 1)
            pre[i][1] = (0 if i == 0 else pre[i - 1][0]) + I(s[i], 0)

        ans = min(pre[n - 1][0], pre[n - 1][1])
        if n % 2 == 1:
            # If n is an odd number, it is also necessary to calculate suf
            suf = [[0, 0] for _ in range(n)]
            # Note the boundary case when i = n - 1
            for i in range(n - 1, -1, -1):
                suf[i][0] = (0 if i == n - 1 else suf[i + 1][1]) + I(s[i], 1)
                suf[i][1] = (0 if i == n - 1 else suf[i + 1][0]) + I(s[i], 0)

            for i in range(n - 1):
                ans = min(ans, pre[i][0] + suf[i + 1][0])
                ans = min(ans, pre[i][1] + suf[i + 1][1])

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minFlips(s: string): number {
    // Characteristic function
    const I = (ch: string, x: number): number => (parseInt(ch) === x ? 1 : 0);

    const n = s.length;
    const pre: number[][] = new Array(n);
    for (let i = 0; i < n; i++) {
        pre[i] = new Array(2);
    }

    // Note the boundary case when i=0
    for (let i = 0; i < n; ++i) {
        if (i === 0) {
            pre[i][0] = I(s[i], 1);
            pre[i][1] = I(s[i], 0);
        } else {
            pre[i][0] = pre[i - 1][1] + I(s[i], 1);
            pre[i][1] = pre[i - 1][0] + I(s[i], 0);
        }
    }

    let ans = Math.min(pre[n - 1][0], pre[n - 1][1]);
    if (n % 2 === 1) {
        // If n is an odd number, it is also necessary to calculate suf
        const suf: number[][] = new Array(n);
        for (let i = 0; i < n; i++) {
            suf[i] = new Array(2);
        }

        // Note the boundary case when i = n - 1
        for (let i = n - 1; i >= 0; --i) {
            if (i === n - 1) {
                suf[i][0] = I(s[i], 1);
                suf[i][1] = I(s[i], 0);
            } else {
                suf[i][0] = suf[i + 1][1] + I(s[i], 1);
                suf[i][1] = suf[i + 1][0] + I(s[i], 0);
            }
        }

        for (let i = 0; i + 1 < n; ++i) {
            ans = Math.min(ans, pre[i][0] + suf[i + 1][0]);
            ans = Math.min(ans, pre[i][1] + suf[i + 1][1]);
        }
    }

    return ans;
}
```

</details>
