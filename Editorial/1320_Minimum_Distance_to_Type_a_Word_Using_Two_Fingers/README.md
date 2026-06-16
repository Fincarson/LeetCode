# 1320. Minimum Distance to Type a Word Using Two Fingers

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/)  
`String` `Dynamic Programming`

**Problem Link:** [LeetCode 1320 - Minimum Distance to Type a Word Using Two Fingers](https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/)

## Problem

You have a keyboard layout as shown above in the X-Y plane, where each English uppercase letter is located at some coordinate.

- For example, the letter 'A' is located at coordinate (0, 0), the letter 'B' is located at coordinate (0, 1), the letter 'P' is located at coordinate (2, 3) and the letter 'Z' is located at coordinate (4, 1).

Given the string word, return the minimum total distance to type such string using only two fingers.

The distance between coordinates (x1, y1) and (x2, y2) is |x1 - x2| + |y1 - y2|.

Note that the initial positions of your two fingers are considered free so do not count towards your total distance, also your two fingers do not have to start at the first letter or the first two letters.

### Example 1

```text
Input: word = "CAKE"
Output: 3
Explanation: Using two fingers, one optimal way to type "CAKE" is:
Finger 1 on letter 'C' -> cost = 0
Finger 1 on letter 'A' -> cost = Distance from letter 'C' to letter 'A' = 2
Finger 2 on letter 'K' -> cost = 0
Finger 2 on letter 'E' -> cost = Distance from letter 'K' to letter 'E' = 1
Total distance = 3
```

### Example 2

```text
Input: word = "HAPPY"
Output: 6
Explanation: Using two fingers, one optimal way to type "HAPPY" is:
Finger 1 on letter 'H' -> cost = 0
Finger 1 on letter 'A' -> cost = Distance from letter 'H' to letter 'A' = 2
Finger 2 on letter 'P' -> cost = 0
Finger 2 on letter 'P' -> cost = Distance from letter 'P' to letter 'P' = 0
Finger 1 on letter 'Y' -> cost = Distance from letter 'A' to letter 'Y' = 4
Total distance = 6
```

## Constraints

- 2 <= word.length <= 300
- word consists of uppercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Time to Type Word Using Special Typewriter](https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1320. Minimum Distance to Type a Word Using Two Fingers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Dynamic Programming + Space Optimization | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int getDistance(int p, int q) {
    int x1 = p / 6, y1 = p % 6;
    int x2 = q / 6, y2 = q % 6;
    return abs(x1 - x2) + abs(y1 - y2);
}

int minimumDistance(char* word) {
    int n = strlen(word);
    int*** dp = (int***)malloc(n * sizeof(int**));
    for (int i = 0; i < n; ++i) {
        dp[i] = (int**)malloc(26 * sizeof(int*));
        for (int j = 0; j < 26; ++j) {
            dp[i][j] = (int*)malloc(26 * sizeof(int));
            for (int k = 0; k < 26; ++k) {
                dp[i][j][k] = INT_MAX / 2;
            }
        }
    }

    for (int i = 0; i < 26; ++i) {
        dp[0][i][word[0] - 'A'] = 0;
        dp[0][word[0] - 'A'][i] = 0;
    }
    for (int i = 1; i < n; ++i) {
        int cur = word[i] - 'A';
        int prev = word[i - 1] - 'A';
        int d = getDistance(prev, cur);

        for (int j = 0; j < 26; ++j) {
            dp[i][cur][j] = fmin(dp[i][cur][j], dp[i - 1][prev][j] + d);
            dp[i][j][cur] = fmin(dp[i][j][cur], dp[i - 1][j][prev] + d);

            if (prev == j) {
                for (int k = 0; k < 26; ++k) {
                    int d0 = getDistance(k, cur);
                    dp[i][cur][j] = fmin(dp[i][cur][j], dp[i - 1][k][j] + d0);
                    dp[i][j][cur] = fmin(dp[i][j][cur], dp[i - 1][j][k] + d0);
                }
            }
        }
    }

    int ans = INT_MAX / 2;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (ans > dp[n - 1][i][j]) {
                ans = dp[n - 1][i][j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            free(dp[i][j]);
        }
        free(dp[i]);
    }
    free(dp);

    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int getDistance(int p, int q) {
        int x1 = p / 6, y1 = p % 6;
        int x2 = q / 6, y2 = q % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        int n = word.size();
        int dp[n][26][26];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                fill(dp[i][j], dp[i][j] + 26, INT_MAX >> 1);
            }
        }
        for (int i = 0; i < 26; ++i) {
            dp[0][i][word[0] - 'A'] = dp[0][word[0] - 'A'][i] = 0;
        }

        for (int i = 1; i < n; ++i) {
            int cur = word[i] - 'A';
            int prev = word[i - 1] - 'A';
            int d = getDistance(prev, cur);
            for (int j = 0; j < 26; ++j) {
                dp[i][cur][j] = min(dp[i][cur][j], dp[i - 1][prev][j] + d);
                dp[i][j][cur] = min(dp[i][j][cur], dp[i - 1][j][prev] + d);
                if (prev == j) {
                    for (int k = 0; k < 26; ++k) {
                        int d0 = getDistance(k, cur);
                        dp[i][cur][j] =
                            min(dp[i][cur][j], dp[i - 1][k][j] + d0);
                        dp[i][j][cur] =
                            min(dp[i][j][cur], dp[i - 1][j][k] + d0);
                    }
                }
            }
        }

        int ans = INT_MAX >> 1;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                ans = min(ans, dp[n - 1][i][j]);
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
    private int GetDistance(int p, int q) {
        int x1 = p / 6, y1 = p % 6;
        int x2 = q / 6, y2 = q % 6;
        return Math.Abs(x1 - x2) + Math.Abs(y1 - y2);
    }

    public int MinimumDistance(string word) {
        int n = word.Length;
        int[,,] dp = new int[n, 26, 26];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                for (int k = 0; k < 26; ++k) {
                    dp[i, j, k] = int.MaxValue / 2;
                }
            }
        }

        for (int i = 0; i < 26; ++i) {
            dp[0, i, word[0] - 'A'] = 0;
            dp[0, word[0] - 'A', i] = 0;
        }
        for (int i = 1; i < n; ++i) {
            int cur = word[i] - 'A';
            int prev = word[i - 1] - 'A';
            int d = GetDistance(prev, cur);

            for (int j = 0; j < 26; ++j) {
                dp[i, cur, j] = Math.Min(dp[i, cur, j], dp[i - 1, prev, j] + d);
                dp[i, j, cur] = Math.Min(dp[i, j, cur], dp[i - 1, j, prev] + d);

                if (prev == j) {
                    for (int k = 0; k < 26; ++k) {
                        int d0 = GetDistance(k, cur);
                        dp[i, cur, j] =
                            Math.Min(dp[i, cur, j], dp[i - 1, k, j] + d0);
                        dp[i, j, cur] =
                            Math.Min(dp[i, j, cur], dp[i - 1, j, k] + d0);
                    }
                }
            }
        }

        int ans = int.MaxValue / 2;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                ans = Math.Min(ans, dp[n - 1, i, j]);
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
func getDistance(p, q int) int {
	x1, y1 := p/6, p%6
	x2, y2 := q/6, q%6
	return abs(x1-x2) + abs(y1-y2)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func minimumDistance(word string) int {
	n := len(word)
	dp := make([][26][26]int, n)

	for i := 0; i < n; i++ {
		for j := 0; j < 26; j++ {
			for k := 0; k < 26; k++ {
				dp[i][j][k] = 1 << 30
			}
		}
	}

	firstChar := int(word[0] - 'A')
	for i := 0; i < 26; i++ {
		dp[0][i][firstChar] = 0
		dp[0][firstChar][i] = 0
	}

	for i := 1; i < n; i++ {
		cur := int(word[i] - 'A')
		prev := int(word[i-1] - 'A')
		d := getDistance(prev, cur)

		for j := 0; j < 26; j++ {
			dp[i][cur][j] = min(dp[i][cur][j], dp[i-1][prev][j]+d)
			dp[i][j][cur] = min(dp[i][j][cur], dp[i-1][j][prev]+d)

			if prev == j {
				for k := 0; k < 26; k++ {
					d0 := getDistance(k, cur)
					dp[i][cur][j] = min(dp[i][cur][j], dp[i-1][k][j]+d0)
					dp[i][j][cur] = min(dp[i][j][cur], dp[i-1][j][k]+d0)
				}
			}
		}
	}

	ans := 1 << 30
	for i := 0; i < 26; i++ {
		for j := 0; j < 26; j++ {
			ans = min(ans, dp[n-1][i][j])
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

    private int getDistance(int p, int q) {
        int x1 = p / 6;
        int y1 = p % 6;
        int x2 = q / 6;
        int y2 = q % 6;
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }

    public int minimumDistance(String word) {
        int n = word.length();
        int[][][] dp = new int[n][26][26];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                for (int k = 0; k < 26; ++k) {
                    dp[i][j][k] = Integer.MAX_VALUE / 2;
                }
            }
        }

        for (int i = 0; i < 26; ++i) {
            dp[0][i][word.charAt(0) - 'A'] = 0;
            dp[0][word.charAt(0) - 'A'][i] = 0;
        }

        for (int i = 1; i < n; ++i) {
            int cur = word.charAt(i) - 'A';
            int prev = word.charAt(i - 1) - 'A';
            int d = getDistance(prev, cur);

            for (int j = 0; j < 26; ++j) {
                dp[i][cur][j] = Math.min(dp[i][cur][j], dp[i - 1][prev][j] + d);
                dp[i][j][cur] = Math.min(dp[i][j][cur], dp[i - 1][j][prev] + d);

                if (prev == j) {
                    for (int k = 0; k < 26; ++k) {
                        int d0 = getDistance(k, cur);
                        dp[i][cur][j] = Math.min(
                            dp[i][cur][j],
                            dp[i - 1][k][j] + d0
                        );
                        dp[i][j][cur] = Math.min(
                            dp[i][j][cur],
                            dp[i - 1][j][k] + d0
                        );
                    }
                }
            }
        }

        int ans = Integer.MAX_VALUE / 2;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                ans = Math.min(ans, dp[n - 1][i][j]);
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
var minimumDistance = function (word) {
    const n = word.length;
    const getDistance = (p, q) => {
        const x1 = Math.floor(p / 6),
            y1 = p % 6;
        const x2 = Math.floor(q / 6),
            y2 = q % 6;
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    };

    const dp = new Array(n);
    for (let i = 0; i < n; i++) {
        dp[i] = new Array(26);
        for (let j = 0; j < 26; j++) {
            dp[i][j] = new Array(26).fill(
                Math.floor(Number.MAX_SAFE_INTEGER / 2),
            );
        }
    }

    const firstChar = word.charCodeAt(0) - 65;
    for (let i = 0; i < 26; i++) {
        dp[0][i][firstChar] = 0;
        dp[0][firstChar][i] = 0;
    }

    for (let i = 1; i < n; i++) {
        const cur = word.charCodeAt(i) - 65;
        const prev = word.charCodeAt(i - 1) - 65;
        const d = getDistance(prev, cur);

        for (let j = 0; j < 26; j++) {
            dp[i][cur][j] = Math.min(dp[i][cur][j], dp[i - 1][prev][j] + d);
            dp[i][j][cur] = Math.min(dp[i][j][cur], dp[i - 1][j][prev] + d);

            if (prev === j) {
                for (let k = 0; k < 26; k++) {
                    const d0 = getDistance(k, cur);
                    dp[i][cur][j] = Math.min(
                        dp[i][cur][j],
                        dp[i - 1][k][j] + d0,
                    );
                    dp[i][j][cur] = Math.min(
                        dp[i][j][cur],
                        dp[i - 1][j][k] + d0,
                    );
                }
            }
        }
    }

    let ans = Number.MAX_SAFE_INTEGER;
    for (let i = 0; i < 26; i++) {
        for (let j = 0; j < 26; j++) {
            ans = Math.min(ans, dp[n - 1][i][j]);
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
    def minimumDistance(self, word: str) -> int:
        n = len(word)
        BIG = 2**30
        dp = [[[BIG] * 26 for x in range(26)] for y in range(n)]
        for i in range(26):
            dp[0][i][ord(word[0]) - 65] = 0
            dp[0][ord(word[0]) - 65][i] = 0

        def getDistance(p, q):
            x1, y1 = p // 6, p % 6
            x2, y2 = q // 6, q % 6
            return abs(x1 - x2) + abs(y1 - y2)

        for i in range(1, n):
            cur, prev = ord(word[i]) - 65, ord(word[i - 1]) - 65
            d = getDistance(prev, cur)
            for j in range(26):
                dp[i][cur][j] = min(dp[i][cur][j], dp[i - 1][prev][j] + d)
                dp[i][j][cur] = min(dp[i][j][cur], dp[i - 1][j][prev] + d)
                if prev == j:
                    for k in range(26):
                        d0 = getDistance(k, cur)
                        dp[i][cur][j] = min(dp[i][cur][j], dp[i - 1][k][j] + d0)
                        dp[i][j][cur] = min(dp[i][j][cur], dp[i - 1][j][k] + d0)

        ans = min(min(dp[n - 1][x]) for x in range(26))
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumDistance(word: string): number {
    const n = word.length;
    const getDistance = (p: number, q: number): number => {
        const x1 = Math.floor(p / 6),
            y1 = p % 6;
        const x2 = Math.floor(q / 6),
            y2 = q % 6;
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    };

    const dp: number[][][] = new Array(n);
    for (let i = 0; i < n; i++) {
        dp[i] = new Array(26);
        for (let j = 0; j < 26; j++) {
            dp[i][j] = new Array(26).fill(
                Math.floor(Number.MAX_SAFE_INTEGER / 2),
            );
        }
    }
    const firstChar = word.charCodeAt(0) - 65;
    for (let i = 0; i < 26; i++) {
        dp[0][i][firstChar] = 0;
        dp[0][firstChar][i] = 0;
    }

    for (let i = 1; i < n; i++) {
        const cur = word.charCodeAt(i) - 65;
        const prev = word.charCodeAt(i - 1) - 65;
        const d = getDistance(prev, cur);

        for (let j = 0; j < 26; j++) {
            dp[i][cur][j] = Math.min(dp[i][cur][j], dp[i - 1][prev][j] + d);
            dp[i][j][cur] = Math.min(dp[i][j][cur], dp[i - 1][j][prev] + d);

            if (prev === j) {
                for (let k = 0; k < 26; k++) {
                    const d0 = getDistance(k, cur);
                    dp[i][cur][j] = Math.min(
                        dp[i][cur][j],
                        dp[i - 1][k][j] + d0,
                    );
                    dp[i][j][cur] = Math.min(
                        dp[i][j][cur],
                        dp[i - 1][j][k] + d0,
                    );
                }
            }
        }
    }

    let ans = Number.MAX_SAFE_INTEGER;
    for (let i = 0; i < 26; i++) {
        for (let j = 0; j < 26; j++) {
            ans = Math.min(ans, dp[n - 1][i][j]);
        }
    }
    return ans;
}
```

</details>

<br>

## Approach 2: Dynamic Programming + Space Optimization

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int getDistance(int p, int q) {
    int x1 = p / 6, y1 = p % 6;
    int x2 = q / 6, y2 = q % 6;
    return abs(x1 - x2) + abs(y1 - y2);
}

int minimumDistance(char* word) {
    int n = strlen(word);
    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc(26 * sizeof(int));
        for (int j = 0; j < 26; j++) {
            dp[i][j] = INT_MAX / 2;
        }
    }
    for (int j = 0; j < 26; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i < n; i++) {
        int cur = word[i] - 'A';
        int prev = word[i - 1] - 'A';
        int d = getDistance(prev, cur);

        for (int j = 0; j < 26; j++) {
            dp[i][j] = fmin(dp[i][j], dp[i - 1][j] + d);
            if (prev == j) {
                for (int k = 0; k < 26; k++) {
                    int d0 = getDistance(k, cur);
                    dp[i][j] = fmin(dp[i][j], dp[i - 1][k] + d0);
                }
            }
        }
    }

    int ans = INT_MAX / 2;
    for (int j = 0; j < 26; j++) {
        if (ans > dp[n - 1][j]) {
            ans = dp[n - 1][j];
        }
    }
    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);

    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int getDistance(int p, int q) {
        int x1 = p / 6, y1 = p % 6;
        int x2 = q / 6, y2 = q % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        int n = word.size();
        vector<vector<int>> dp(n, vector<int>(26, INT_MAX >> 1));
        fill(dp[0].begin(), dp[0].end(), 0);

        for (int i = 1; i < n; ++i) {
            int cur = word[i] - 'A';
            int prev = word[i - 1] - 'A';
            int d = getDistance(prev, cur);
            for (int j = 0; j < 26; ++j) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + d);
                if (prev == j) {
                    for (int k = 0; k < 26; ++k) {
                        int d0 = getDistance(k, cur);
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + d0);
                    }
                }
            }
        }

        int ans = *min_element(dp[n - 1].begin(), dp[n - 1].end());
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private int GetDistance(int p, int q) {
        int x1 = p / 6, y1 = p % 6;
        int x2 = q / 6, y2 = q % 6;
        return Math.Abs(x1 - x2) + Math.Abs(y1 - y2);
    }

    public int MinimumDistance(string word) {
        int n = word.Length;
        int[,] dp = new int[n, 26];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                dp[i, j] = int.MaxValue / 2;
            }
        }

        for (int j = 0; j < 26; j++) {
            dp[0, j] = 0;
        }
        for (int i = 1; i < n; i++) {
            int cur = word[i] - 'A';
            int prev = word[i - 1] - 'A';
            int d = GetDistance(prev, cur);

            for (int j = 0; j < 26; j++) {
                dp[i, j] = Math.Min(dp[i, j], dp[i - 1, j] + d);
                if (prev == j) {
                    for (int k = 0; k < 26; k++) {
                        int d0 = GetDistance(k, cur);
                        dp[i, j] = Math.Min(dp[i, j], dp[i - 1, k] + d0);
                    }
                }
            }
        }

        int ans = int.MaxValue / 2;
        for (int j = 0; j < 26; j++) {
            ans = Math.Min(ans, dp[n - 1, j]);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func getDistance(p, q int) int {
	x1, y1 := p/6, p%6
	x2, y2 := q/6, q%6
	return abs(x1-x2) + abs(y1-y2)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func minimumDistance(word string) int {
	n := len(word)
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, 26)
		for j := range dp[i] {
			dp[i][j] = 1 << 30
		}
	}
	for j := 0; j < 26; j++ {
		dp[0][j] = 0
	}

	for i := 1; i < n; i++ {
		cur := int(word[i] - 'A')
		prev := int(word[i-1] - 'A')
		d := getDistance(prev, cur)

		for j := 0; j < 26; j++ {
			dp[i][j] = min(dp[i][j], dp[i-1][j]+d)
			if prev == j {
				for k := 0; k < 26; k++ {
					d0 := getDistance(k, cur)
					dp[i][j] = min(dp[i][j], dp[i-1][k]+d0)
				}
			}
		}
	}

	ans := 1 << 30
	for j := 0; j < 26; j++ {
		ans = min(ans, dp[n-1][j])
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int getDistance(int p, int q) {
        int x1 = p / 6;
        int y1 = p % 6;
        int x2 = q / 6;
        int y2 = q % 6;
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }

    public int minimumDistance(String word) {
        int n = word.length();
        int[][] dp = new int[n][26];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE / 2);
        }
        Arrays.fill(dp[0], 0);

        for (int i = 1; i < n; i++) {
            int cur = word.charAt(i) - 'A';
            int prev = word.charAt(i - 1) - 'A';
            int d = getDistance(prev, cur);

            for (int j = 0; j < 26; j++) {
                dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + d);
                if (prev == j) {
                    for (int k = 0; k < 26; k++) {
                        int d0 = getDistance(k, cur);
                        dp[i][j] = Math.min(dp[i][j], dp[i - 1][k] + d0);
                    }
                }
            }
        }

        int ans = Integer.MAX_VALUE / 2;
        for (int value : dp[n - 1]) {
            ans = Math.min(ans, value);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumDistance = function (word) {
    const n = word.length;
    const getDistance = (p, q) => {
        const x1 = Math.floor(p / 6),
            y1 = p % 6;
        const x2 = Math.floor(q / 6),
            y2 = q % 6;
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    };

    const dp = new Array(n);
    for (let i = 0; i < n; i++) {
        dp[i] = new Array(26).fill(Math.floor(Number.MAX_SAFE_INTEGER / 2));
    }

    for (let j = 0; j < 26; j++) {
        dp[0][j] = 0;
    }

    for (let i = 1; i < n; i++) {
        const cur = word.charCodeAt(i) - 65;
        const prev = word.charCodeAt(i - 1) - 65;
        const d = getDistance(prev, cur);

        for (let j = 0; j < 26; j++) {
            dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + d);

            if (prev === j) {
                for (let k = 0; k < 26; k++) {
                    const d0 = getDistance(k, cur);
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][k] + d0);
                }
            }
        }
    }

    let ans = Math.floor(Number.MAX_SAFE_INTEGER / 2);
    for (let j = 0; j < 26; j++) {
        ans = Math.min(ans, dp[n - 1][j]);
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDistance(self, word: str) -> int:
        n = len(word)
        BIG = 2**30
        dp = [[0] * 26] + [[BIG] * 26 for _ in range(n - 1)]

        def getDistance(p, q):
            x1, y1 = p // 6, p % 6
            x2, y2 = q // 6, q % 6
            return abs(x1 - x2) + abs(y1 - y2)

        for i in range(1, n):
            cur, prev = ord(word[i]) - 65, ord(word[i - 1]) - 65
            d = getDistance(prev, cur)
            for j in range(26):
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + d)
                if prev == j:
                    for k in range(26):
                        d0 = getDistance(k, cur)
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + d0)

        ans = min(dp[n - 1])
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumDistance(word: string): number {
    const n = word.length;
    const getDistance = (p: number, q: number): number => {
        const x1 = Math.floor(p / 6),
            y1 = p % 6;
        const x2 = Math.floor(q / 6),
            y2 = q % 6;
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    };

    const dp: number[][] = new Array(n);
    for (let i = 0; i < n; i++) {
        dp[i] = new Array(26).fill(Math.floor(Number.MAX_SAFE_INTEGER / 2));
    }
    for (let j = 0; j < 26; j++) {
        dp[0][j] = 0;
    }

    for (let i = 1; i < n; i++) {
        const cur = word.charCodeAt(i) - 65;
        const prev = word.charCodeAt(i - 1) - 65;
        const d = getDistance(prev, cur);

        for (let j = 0; j < 26; j++) {
            dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + d);

            if (prev === j) {
                for (let k = 0; k < 26; k++) {
                    const d0 = getDistance(k, cur);
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][k] + d0);
                }
            }
        }
    }

    let ans = Math.floor(Number.MAX_SAFE_INTEGER / 2);
    for (let j = 0; j < 26; j++) {
        ans = Math.min(ans, dp[n - 1][j]);
    }
    return ans;
}
```

</details>
