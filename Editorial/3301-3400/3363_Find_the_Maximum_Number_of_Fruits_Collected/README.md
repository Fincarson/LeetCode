# 3363. Find the Maximum Number of Fruits Collected

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/)  
`Array` `Dynamic Programming` `Matrix`

**Problem Link:** [LeetCode 3363 - Find the Maximum Number of Fruits Collected](https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/)

## Problem

There is a game dungeon comprised of n x n rooms arranged in a grid.

You are given a 2D array fruits of size n x n, where fruits[i][j] represents the number of fruits in the room (i, j). Three children will play in the game dungeon, with initial positions at the corner rooms (0, 0), (0, n - 1), and (n - 1, 0).

The children will make exactly n - 1 moves according to the following rules to reach the room (n - 1, n - 1):

- The child starting from (0, 0) must move from their current room (i, j) to one of the rooms (i + 1, j + 1), (i + 1, j), and (i, j + 1) if the target room exists.
- The child starting from (0, n - 1) must move from their current room (i, j) to one of the rooms (i + 1, j - 1), (i + 1, j), and (i + 1, j + 1) if the target room exists.
- The child starting from (n - 1, 0) must move from their current room (i, j) to one of the rooms (i - 1, j + 1), (i, j + 1), and (i + 1, j + 1) if the target room exists.

When a child enters a room, they will collect all the fruits there. If two or more children enter the same room, only one child will collect the fruits, and the room will be emptied after they leave.

Return the maximum number of fruits the children can collect from the dungeon.

### Example 1

### Example 2

## Constraints

- 2 <= n == fruits.length == fruits[i].length <= 1000
- 0 <= fruits[i][j] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3363. Find the Maximum Number of Fruits Collected

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxCollectedFruits(int** fruits, int fruitsSize, int* fruitsColSize) {
    int ans = 0;
    int n = fruitsSize;
    for (int i = 0; i < n; ++i) ans += fruits[i][i];

    int dp() {
        int* prev = malloc(sizeof(int) * n);
        int* curr = malloc(sizeof(int) * n);
        for (int i = 0; i < n; ++i) prev[i] = INT_MIN;
        prev[n - 1] = fruits[0][n - 1];

        for (int i = 1; i < n - 1; ++i) {
            for (int j = 0; j < n; ++j) curr[j] = INT_MIN;
            for (int j = (n - 1 - i > i + 1 ? n - 1 - i : i + 1); j < n; ++j) {
                int best = prev[j];
                if (j - 1 >= 0) {
                    best = best > prev[j - 1] ? best : prev[j - 1];
                }
                if (j + 1 < n) {
                    best = best > prev[j + 1] ? best : prev[j + 1];
                }
                curr[j] = best + fruits[i][j];
            }
            int* tmp = prev;
            prev = curr;
            curr = tmp;
        }

        int result = prev[n - 1];
        free(prev);
        free(curr);
        return result;
    }

    ans += dp();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int temp = fruits[j][i];
            fruits[j][i] = fruits[i][j];
            fruits[i][j] = temp;
        }
    }

    ans += dp();
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += fruits[i][i];
        }

        auto dp = [&]() -> int {
            vector<int> prev(n, INT_MIN), curr(n, INT_MIN);
            prev[n - 1] = fruits[0][n - 1];
            for (int i = 1; i < n - 1; ++i) {
                for (int j = max(n - 1 - i, i + 1); j < n; ++j) {
                    int best = prev[j];
                    if (j - 1 >= 0) {
                        best = max(best, prev[j - 1]);
                    }
                    if (j + 1 < n) {
                        best = max(best, prev[j + 1]);
                    }
                    curr[j] = best + fruits[i][j];
                }
                swap(prev, curr);
            }
            return prev[n - 1];
        };

        ans += dp();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(fruits[j][i], fruits[i][j]);
            }
        }

        ans += dp();
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxCollectedFruits(int[][] fruits) {
        int n = fruits.Length;
        int ans = 0;
        for (int i = 0; i < n; ++i) ans += fruits[i][i];

        int dp() {
            int[] prev = Enumerable.Repeat(int.MinValue, n).ToArray();
            int[] curr = new int[n];
            prev[n - 1] = fruits[0][n - 1];
            for (int i = 1; i < n - 1; ++i) {
                Array.Fill(curr, int.MinValue);
                for (int j = Math.Max(n - 1 - i, i + 1); j < n; ++j) {
                    int best = prev[j];
                    if (j - 1 >= 0) {
                        best = Math.Max(best, prev[j - 1]);
                    }
                    if (j + 1 < n) {
                        best = Math.Max(best, prev[j + 1]);
                    }
                    curr[j] = best + fruits[i][j];
                }
                var temp = prev;
                prev = curr;
                curr = temp;
            }
            return prev[n - 1];
        }

        ans += dp();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                var temp = fruits[j][i];
                fruits[j][i] = fruits[i][j];
                fruits[i][j] = temp;
            }
        }

        ans += dp();
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxCollectedFruits(fruits [][]int) int {
	n := len(fruits)
	ans := 0
	for i := 0; i < n; i++ {
		ans += fruits[i][i]
	}

	dp := func() int {
		prev := make([]int, n)
		curr := make([]int, n)
		for i := range prev {
			prev[i] = math.MinInt
		}
		prev[n-1] = fruits[0][n-1]
		for i := 1; i < n-1; i++ {
			for j := range curr {
				curr[j] = math.MinInt
			}
			for j := max(n-1-i, i+1); j < n; j++ {
				best := prev[j]
				if j-1 >= 0 {
					best = max(best, prev[j-1])
				}
				if j+1 < n {
					best = max(best, prev[j+1])
				}
				curr[j] = best + fruits[i][j]
			}
			prev, curr = curr, prev
		}
		return prev[n-1]
	}

	ans += dp()
	for i := 0; i < n; i++ {
		for j := 0; j < i; j++ {
			fruits[i][j], fruits[j][i] = fruits[j][i], fruits[i][j]
		}
	}
	ans += dp()
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxCollectedFruits(int[][] fruits) {
        int n = fruits.length;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += fruits[i][i];
        }

        java.util.function.Supplier<Integer> dp = () -> {
            int[] prev = new int[n];
            int[] curr = new int[n];
            java.util.Arrays.fill(prev, Integer.MIN_VALUE);
            java.util.Arrays.fill(curr, Integer.MIN_VALUE);
            prev[n - 1] = fruits[0][n - 1];
            for (int i = 1; i < n - 1; ++i) {
                for (int j = Math.max(n - 1 - i, i + 1); j < n; ++j) {
                    int best = prev[j];
                    if (j - 1 >= 0) best = Math.max(best, prev[j - 1]);
                    if (j + 1 < n) best = Math.max(best, prev[j + 1]);
                    curr[j] = best + fruits[i][j];
                }
                int[] temp = prev;
                prev = curr;
                curr = temp;
            }
            return prev[n - 1];
        };

        ans += dp.get();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int temp = fruits[j][i];
                fruits[j][i] = fruits[i][j];
                fruits[i][j] = temp;
            }
        }

        ans += dp.get();
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxCollectedFruits = function (fruits) {
    const n = fruits.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) ans += fruits[i][i];

    function dp() {
        let prev = Array(n).fill(-Infinity);
        let curr = Array(n).fill(-Infinity);
        prev[n - 1] = fruits[0][n - 1];

        for (let i = 1; i < n - 1; ++i) {
            for (let j = Math.max(n - 1 - i, i + 1); j < n; ++j) {
                let best = prev[j];
                if (j - 1 >= 0) {
                    best = Math.max(best, prev[j - 1]);
                }
                if (j + 1 < n) {
                    best = Math.max(best, prev[j + 1]);
                }
                curr[j] = best + fruits[i][j];
            }
            [prev, curr] = [curr, prev];
        }
        return prev[n - 1];
    }

    ans += dp();
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            [fruits[i][j], fruits[j][i]] = [fruits[j][i], fruits[i][j]];
        }
    }

    ans += dp();
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxCollectedFruits(self, fruits):
        n = len(fruits)
        ans = sum(fruits[i][i] for i in range(n))

        def dp():
            prev = [float("-inf")] * n
            curr = [float("-inf")] * n
            prev[n - 1] = fruits[0][n - 1]
            for i in range(1, n - 1):
                for j in range(max(n - 1 - i, i + 1), n):
                    best = prev[j]
                    if j - 1 >= 0:
                        best = max(best, prev[j - 1])
                    if j + 1 < n:
                        best = max(best, prev[j + 1])
                    curr[j] = best + fruits[i][j]
                prev, curr = curr, prev
            return prev[n - 1]

        ans += dp()

        for i in range(n):
            for j in range(i):
                fruits[i][j], fruits[j][i] = fruits[j][i], fruits[i][j]

        ans += dp()
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxCollectedFruits(fruits: number[][]): number {
    const n = fruits.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) ans += fruits[i][i];

    const dp = (): number => {
        let prev: number[] = Array(n).fill(Number.MIN_SAFE_INTEGER);
        let curr: number[] = Array(n).fill(Number.MIN_SAFE_INTEGER);
        prev[n - 1] = fruits[0][n - 1];

        for (let i = 1; i < n - 1; ++i) {
            for (let j = Math.max(n - 1 - i, i + 1); j < n; ++j) {
                let best = prev[j];
                if (j - 1 >= 0) {
                    best = Math.max(best, prev[j - 1]);
                }
                if (j + 1 < n) {
                    best = Math.max(best, prev[j + 1]);
                }
                curr[j] = best + fruits[i][j];
            }
            [prev, curr] = [curr, prev];
        }

        return prev[n - 1];
    };

    ans += dp();
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            [fruits[i][j], fruits[j][i]] = [fruits[j][i], fruits[i][j]];
        }
    }
    ans += dp();
    return ans;
}
```

</details>
