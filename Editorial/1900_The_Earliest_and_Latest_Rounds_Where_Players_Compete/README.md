# 1900. The Earliest and Latest Rounds Where Players Compete

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/)  
`Dynamic Programming` `Memoization`

**Problem Link:** [LeetCode 1900 - The Earliest and Latest Rounds Where Players Compete](https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/)

## Problem

There is a tournament where n players are participating. The players are standing in a single row and are numbered from 1 to n based on their initial standing position (player 1 is the first player in the row, player 2 is the second player in the row, etc.).

The tournament consists of multiple rounds (starting from round number 1). In each round, the ith player from the front of the row competes against the ith player from the end of the row, and the winner advances to the next round. When the number of players is odd for the current round, the player in the middle automatically advances to the next round.

- For example, if the row consists of players 1, 2, 4, 6, 7

		Player 1 competes against player 7.
		Player 2 competes against player 6.
		Player 4 automatically advances to the next round.

After each round is over, the winners are lined back up in the row based on the original ordering assigned to them initially (ascending order).

The players numbered firstPlayer and secondPlayer are the best in the tournament. They can win against any other player before they compete against each other. If any two other players compete against each other, either of them might win, and thus you may choose the outcome of this round.

Given the integers n, firstPlayer, and secondPlayer, return an integer array containing two values, the earliest possible round number and the latest possible round number in which these two players will compete against each other, respectively.

### Example 1

```text
Input: n = 11, firstPlayer = 2, secondPlayer = 4
Output: [3,4]
Explanation:
One possible scenario which leads to the earliest round number:
First round: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
Second round: 2, 3, 4, 5, 6, 11
Third round: 2, 3, 4
One possible scenario which leads to the latest round number:
First round: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
Second round: 1, 2, 3, 4, 5, 6
Third round: 1, 2, 4
Fourth round: 2, 4
```

### Example 2

```text
Input: n = 5, firstPlayer = 1, secondPlayer = 5
Output: [1,1]
Explanation: The players numbered 1 and 5 compete in the first round.
There is no way to make them compete in any other round.
```

## Constraints

- 2 <= n <= 28
- 1 <= firstPlayer < secondPlayer <= n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1900. The Earliest and Latest Rounds Where Players Compete

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Analyze Fundamentally Different Standing Situations + Memoized Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Analyze Fundamentally Different Standing Situations + Memoized Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int F[30][30][30] = {0};
int G[30][30][30] = {0};

void dp(int n, int f, int s, int* earliest, int* latest) {
    if (F[n][f][s]) {
        *earliest = F[n][f][s];
        *latest = G[n][f][s];
        return;
    }
    if (f + s == n + 1) {
        *earliest = 1;
        *latest = 1;
        return;
    }

    // F(n,f,s) = F(n,n+1-s,n+1-f)
    if (f + s > n + 1) {
        int x, y;
        dp(n, n + 1 - s, n + 1 - f, &x, &y);
        F[n][f][s] = x;
        G[n][f][s] = y;
        *earliest = x;
        *latest = y;
        return;
    }

    int min_earliest = INT_MAX;
    int max_latest = INT_MIN;
    int n_half = (n + 1) / 2;

    if (s <= n_half) {
        // On the left or in the middle
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < s - f; ++j) {
                int x, y;
                dp(n_half, i + 1, i + j + 2, &x, &y);
                if (x < min_earliest) {
                    min_earliest = x;
                }
                if (y > max_latest) {
                    max_latest = y;
                }
            }
        }
    } else {
        // s on the right
        int s_prime = n + 1 - s;
        int mid = (n - 2 * s_prime + 1) / 2;
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < s_prime - f; ++j) {
                int x, y;
                dp(n_half, i + 1, i + j + mid + 2, &x, &y);
                if (x < min_earliest) {
                    min_earliest = x;
                }
                if (y > max_latest) {
                    max_latest = y;
                }
            }
        }
    }

    F[n][f][s] = min_earliest + 1;
    G[n][f][s] = max_latest + 1;
    *earliest = F[n][f][s];
    *latest = G[n][f][s];
}

int* earliestAndLatest(int n, int firstPlayer, int secondPlayer,
                       int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));

    // F(n,f,s) = F(n,s,f)
    if (firstPlayer > secondPlayer) {
        int temp = firstPlayer;
        firstPlayer = secondPlayer;
        secondPlayer = temp;
    }

    int earliest, latest;
    dp(n, firstPlayer, secondPlayer, &earliest, &latest);
    result[0] = earliest;
    result[1] = latest;
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int F[30][30][30], G[30][30][30];

public:
    pair<int, int> dp(int n, int f, int s) {
        if (F[n][f][s]) {
            return {F[n][f][s], G[n][f][s]};
        }
        if (f + s == n + 1) {
            return {1, 1};
        }

        // F(n,f,s)=F(n,n+1-s,n+1-f)
        if (f + s > n + 1) {
            tie(F[n][f][s], G[n][f][s]) = dp(n, n + 1 - s, n + 1 - f);
            return {F[n][f][s], G[n][f][s]};
        }

        int earliest = INT_MAX, latest = INT_MIN;
        int n_half = (n + 1) / 2;

        if (s <= n_half) {
            // On the left or in the middle
            for (int i = 0; i < f; ++i) {
                for (int j = 0; j < s - f; ++j) {
                    auto [x, y] = dp(n_half, i + 1, i + j + 2);
                    earliest = min(earliest, x);
                    latest = max(latest, y);
                }
            }
        } else {
            // s on the right
            // s'
            int s_prime = n + 1 - s;
            int mid = (n - 2 * s_prime + 1) / 2;
            for (int i = 0; i < f; ++i) {
                for (int j = 0; j < s_prime - f; ++j) {
                    auto [x, y] = dp(n_half, i + 1, i + j + mid + 2);
                    earliest = min(earliest, x);
                    latest = max(latest, y);
                }
            }
        }

        return {F[n][f][s] = earliest + 1, G[n][f][s] = latest + 1};
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        memset(F, 0, sizeof(F));
        memset(G, 0, sizeof(G));

        // F(n,f,s) = F(n,s,f)
        if (firstPlayer > secondPlayer) {
            swap(firstPlayer, secondPlayer);
        }

        auto [earliest, latest] = dp(n, firstPlayer, secondPlayer);
        return {earliest, latest};
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private int[,,] F = new int[30, 30, 30];
    private int[,,] G = new int[30, 30, 30];

    private int[] Dp(int n, int f, int s) {
        if (F[n, f, s] != 0) {
            return new int[] { F[n, f, s], G[n, f, s] };
        }
        if (f + s == n + 1) {
            return new int[] { 1, 1 };
        }

        // F(n,f,s) = F(n,n+1-s,n+1-f)
        if (f + s > n + 1) {
            int[] res = Dp(n, n + 1 - s, n + 1 - f);
            F[n, f, s] = res[0];
            G[n, f, s] = res[1];
            return new int[] { F[n, f, s], G[n, f, s] };
        }

        int earliest = int.MaxValue, latest = int.MinValue;
        int n_half = (n + 1) / 2;
        if (s <= n_half) {
            // On the left or in the middle
            for (int i = 0; i < f; ++i) {
                for (int j = 0; j < s - f; ++j) {
                    int[] res = Dp(n_half, i + 1, i + j + 2);
                    earliest = Math.Min(earliest, res[0]);
                    latest = Math.Max(latest, res[1]);
                }
            }
        } else {
            // s on the right
            int s_prime = n + 1 - s;
            int mid = (n - 2 * s_prime + 1) / 2;
            for (int i = 0; i < f; ++i) {
                for (int j = 0; j < s_prime - f; ++j) {
                    int[] res = Dp(n_half, i + 1, i + j + mid + 2);
                    earliest = Math.Min(earliest, res[0]);
                    latest = Math.Max(latest, res[1]);
                }
            }
        }

        F[n, f, s] = earliest + 1;
        G[n, f, s] = latest + 1;
        return new int[] { F[n, f, s], G[n, f, s] };
    }

    public int[] EarliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        // F(n,f,s) = F(n,s,f)
        if (firstPlayer > secondPlayer) {
            int temp = firstPlayer;
            firstPlayer = secondPlayer;
            secondPlayer = temp;
        }

        int[] res = Dp(n, firstPlayer, secondPlayer);
        return new int[] { res[0], res[1] };
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func earliestAndLatest(n int, firstPlayer int, secondPlayer int) []int {
	const maxN = 30
	var F [maxN][maxN][maxN]int
	var G [maxN][maxN][maxN]int
	if firstPlayer > secondPlayer {
		firstPlayer, secondPlayer = secondPlayer, firstPlayer
	}

	var dp func(n, f, s int) (int, int)
	dp = func(n, f, s int) (int, int) {
		if F[n][f][s] != 0 {
			return F[n][f][s], G[n][f][s]
		}
		if f+s == n+1 {
			return 1, 1
		}
		// F(n,f,s) = F(n,n+1-s,n+1-f)
		if f+s > n+1 {
			x, y := dp(n, n+1-s, n+1-f)
			F[n][f][s] = x
			G[n][f][s] = y
			return x, y
		}

		earliest := math.MaxInt32
		latest := math.MinInt32
		n_half := (n + 1) / 2
		if s <= n_half {
			// On the left or in the middle
			for i := 0; i < f; i++ {
				for j := 0; j < s-f; j++ {
					x, y := dp(n_half, i+1, i+j+2)
					earliest = min(earliest, x)
					latest = max(latest, y)
				}
			}
		} else {
			// s on the right
			s_prime := n + 1 - s
			mid := (n - 2*s_prime + 1) / 2
			for i := 0; i < f; i++ {
				for j := 0; j < s_prime-f; j++ {
					x, y := dp(n_half, i+1, i+j+mid+2)
					earliest = min(earliest, x)
					latest = max(latest, y)
				}
			}
		}

		F[n][f][s] = earliest + 1
		G[n][f][s] = latest + 1
		return F[n][f][s], G[n][f][s]
	}

	earliest, latest := dp(n, firstPlayer, secondPlayer)
	return []int{earliest, latest}
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int[][][] F = new int[30][30][30];
    private int[][][] G = new int[30][30][30];

    private int[] dp(int n, int f, int s) {
        if (F[n][f][s] != 0) {
            return new int[] { F[n][f][s], G[n][f][s] };
        }
        if (f + s == n + 1) {
            return new int[] { 1, 1 };
        }
        // F(n,f,s) = F(n, n + 1 - s, n + 1 - f)
        if (f + s > n + 1) {
            int[] res = dp(n, n + 1 - s, n + 1 - f);
            F[n][f][s] = res[0];
            G[n][f][s] = res[1];
            return new int[] { F[n][f][s], G[n][f][s] };
        }

        int earliest = Integer.MAX_VALUE;
        int latest = Integer.MIN_VALUE;
        int n_half = (n + 1) / 2;
        if (s <= n_half) {
            // On the left or in the middle
            for (int i = 0; i < f; ++i) {
                for (int j = 0; j < s - f; ++j) {
                    int[] res = dp(n_half, i + 1, i + j + 2);
                    earliest = Math.min(earliest, res[0]);
                    latest = Math.max(latest, res[1]);
                }
            }
        } else {
            // s on the right
            int s_prime = n + 1 - s;
            int mid = (n - 2 * s_prime + 1) / 2;
            for (int i = 0; i < f; ++i) {
                for (int j = 0; j < s_prime - f; ++j) {
                    int[] res = dp(n_half, i + 1, i + j + mid + 2);
                    earliest = Math.min(earliest, res[0]);
                    latest = Math.max(latest, res[1]);
                }
            }
        }

        F[n][f][s] = earliest + 1;
        G[n][f][s] = latest + 1;
        return new int[] { F[n][f][s], G[n][f][s] };
    }

    public int[] earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        // F(n,f,s) = F(n,s,f)
        if (firstPlayer > secondPlayer) {
            int temp = firstPlayer;
            firstPlayer = secondPlayer;
            secondPlayer = temp;
        }

        int[] res = dp(n, firstPlayer, secondPlayer);
        return new int[] { res[0], res[1] };
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var earliestAndLatest = function (n, firstPlayer, secondPlayer) {
    F = Array.from({ length: 30 }, () =>
        Array.from({ length: 30 }, () => Array(30).fill(0)),
    );
    G = Array.from({ length: 30 }, () =>
        Array.from({ length: 30 }, () => Array(30).fill(0)),
    );

    const dp = (n, f, s) => {
        if (this.F[n][f][s]) {
            return [F[n][f][s], G[n][f][s]];
        }
        if (f + s === n + 1) {
            return [1, 1];
        }
        // F(n,f,s)=F(n,n+1-s,n+1-f)
        if (f + s > n + 1) {
            const [x, y] = dp(n, n + 1 - s, n + 1 - f);
            F[n][f][s] = x;
            G[n][f][s] = y;
            return [x, y];
        }

        let earliest = Infinity;
        let latest = -Infinity;
        const n_half = Math.floor((n + 1) / 2);
        if (s <= n_half) {
            // On the left or in the middle
            for (let i = 0; i < f; i++) {
                for (let j = 0; j < s - f; j++) {
                    const [x, y] = dp(n_half, i + 1, i + j + 2);
                    earliest = Math.min(earliest, x);
                    latest = Math.max(latest, y);
                }
            }
        } else {
            // s on the right
            const s_prime = n + 1 - s;
            const mid = Math.floor((n - 2 * s_prime + 1) / 2);
            for (let i = 0; i < f; i++) {
                for (let j = 0; j < s_prime - f; j++) {
                    const [x, y] = dp(n_half, i + 1, i + j + mid + 2);
                    earliest = Math.min(earliest, x);
                    latest = Math.max(latest, y);
                }
            }
        }

        F[n][f][s] = earliest + 1;
        G[n][f][s] = latest + 1;
        return [F[n][f][s], G[n][f][s]];
    };

    // F(n,f,s) = F(n,s,f)
    if (firstPlayer > secondPlayer) {
        [firstPlayer, secondPlayer] = [secondPlayer, firstPlayer];
    }
    const [earliest, latest] = dp(n, firstPlayer, secondPlayer);
    return [earliest, latest];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def earliestAndLatest(
        self, n: int, firstPlayer: int, secondPlayer: int
    ) -> List[int]:
        @cache
        def dp(n: int, f: int, s: int) -> (int, int):
            if f + s == n + 1:
                return (1, 1)

            # F(n,f,s)=F(n,n+1-s,n+1-f)
            if f + s > n + 1:
                return dp(n, n + 1 - s, n + 1 - f)

            earliest, latest = float("inf"), float("-inf")
            n_half = (n + 1) // 2

            if s <= n_half:
                # s On the left or in the middle
                for i in range(f):
                    for j in range(s - f):
                        x, y = dp(n_half, i + 1, i + j + 2)
                        earliest = min(earliest, x)
                        latest = max(latest, y)
            else:
                # s on the right
                # s'
                s_prime = n + 1 - s
                mid = (n - 2 * s_prime + 1) // 2
                for i in range(f):
                    for j in range(s_prime - f):
                        x, y = dp(n_half, i + 1, i + j + mid + 2)
                        earliest = min(earliest, x)
                        latest = max(latest, y)

            return (earliest + 1, latest + 1)

        # F(n,f,s) = F(n,s,f)
        if firstPlayer > secondPlayer:
            firstPlayer, secondPlayer = secondPlayer, firstPlayer

        earliest, latest = dp(n, firstPlayer, secondPlayer)
        dp.cache_clear()
        return [earliest, latest]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function earliestAndLatest(
    n: number,
    firstPlayer: number,
    secondPlayer: number,
): number[] {
    const F = Array.from({ length: 30 }, () =>
        Array.from({ length: 30 }, () => Array(30).fill(0)),
    );
    const G = Array.from({ length: 30 }, () =>
        Array.from({ length: 30 }, () => Array(30).fill(0)),
    );

    function dp(n: number, f: number, s: number): [number, number] {
        if (F[n][f][s]) {
            return [F[n][f][s], G[n][f][s]];
        }
        if (f + s === n + 1) {
            return [1, 1];
        }

        // F(n,f,s)=F(n,n+1-s,n+1-f)
        if (f + s > n + 1) {
            const [x, y] = dp(n, n + 1 - s, n + 1 - f);
            F[n][f][s] = x;
            G[n][f][s] = y;
            return [x, y];
        }

        let earliest = Infinity;
        let latest = -Infinity;
        const n_half = Math.floor((n + 1) / 2);

        if (s <= n_half) {
            // On the left or in the middle
            for (let i = 0; i < f; i++) {
                for (let j = 0; j < s - f; j++) {
                    const [x, y] = dp(n_half, i + 1, i + j + 2);
                    earliest = Math.min(earliest, x);
                    latest = Math.max(latest, y);
                }
            }
        } else {
            // s on the right
            const s_prime = n + 1 - s;
            const mid = Math.floor((n - 2 * s_prime + 1) / 2);
            for (let i = 0; i < f; i++) {
                for (let j = 0; j < s_prime - f; j++) {
                    const [x, y] = dp(n_half, i + 1, i + j + mid + 2);
                    earliest = Math.min(earliest, x);
                    latest = Math.max(latest, y);
                }
            }
        }

        F[n][f][s] = earliest + 1;
        G[n][f][s] = latest + 1;
        return [F[n][f][s], G[n][f][s]];
    }

    // F(n,f,s) = F(n,s,f)
    if (firstPlayer > secondPlayer) {
        [firstPlayer, secondPlayer] = [secondPlayer, firstPlayer];
    }

    const [earliest, latest] = dp(n, firstPlayer, secondPlayer);
    return [earliest, latest];
}
```

</details>
