# 3751. Total Waviness of Numbers in Range I

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/)  
`Math` `Dynamic Programming` `Enumeration`

**Problem Link:** [LeetCode 3751 - Total Waviness of Numbers in Range I](https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/)

## Problem

You are given two integers num1 and num2 representing an inclusive range [num1, num2].

The waviness of a number is defined as the total count of its peaks and valleys:

- A digit is a peak if it is strictly greater than both of its immediate neighbors.
- A digit is a valley if it is strictly less than both of its immediate neighbors.
- The first and last digits of a number cannot be peaks or valleys.
- Any number with fewer than 3 digits has a waviness of 0.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= num1 <= num2 <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3751. Total Waviness of Numbers in Range I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Enumeration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Digit Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int getWaviness(int x) {
    char s[12];
    sprintf(s, "%d", x);
    int waviness = 0;
    int len = strlen(s);

    for (int i = 1; i < len - 1; i++) {
        int isPeak = s[i] > s[i - 1] && s[i] > s[i + 1];
        int isValley = s[i] < s[i - 1] && s[i] < s[i + 1];
        if (isPeak || isValley) {
            waviness++;
        }
    }

    return waviness;
}

int totalWaviness(int num1, int num2) {
    int total = 0;
    for (int i = num1; i <= num2; i++) {
        total += getWaviness(i);
    }
    return total;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        auto getWaviness = [](int x) -> int {
            string s = to_string(x);
            int waviness = 0;

            for (size_t i = 1; i < s.size() - 1; ++i) {
                bool isPeak = s[i] > s[i - 1] && s[i] > s[i + 1];
                bool isValley = s[i] < s[i - 1] && s[i] < s[i + 1];
                if (isPeak || isValley) {
                    ++waviness;
                }
            }

            return waviness;
        };

        int total = 0;
        for (int i = num1; i <= num2; ++i) {
            total += getWaviness(i);
        }

        return total;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int TotalWaviness(int num1, int num2) {
        int total = 0;
        for (int i = num1; i <= num2; i++) {
            total += GetWaviness(i);
        }
        return total;
    }

    private int GetWaviness(int x) {
        string s = x.ToString();
        int waviness = 0;

        for (int i = 1; i < s.Length - 1; i++) {
            bool isPeak = s[i] > s[i - 1] && s[i] > s[i + 1];
            bool isValley = s[i] < s[i - 1] && s[i] < s[i + 1];
            if (isPeak || isValley) {
                waviness++;
            }
        }

        return waviness;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func totalWaviness(num1 int, num2 int) int {
	getWaviness := func(x int) int {
		str := strconv.Itoa(x)
		waviness := 0

		for i := 1; i < len(str)-1; i++ {
			isPeak := str[i] > str[i-1] && str[i] > str[i+1]
			isValley := str[i] < str[i-1] && str[i] < str[i+1]
			if isPeak || isValley {
				waviness++
			}
		}

		return waviness
	}

	total := 0
	for i := num1; i <= num2; i++ {
		total += getWaviness(i)
	}

	return total
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int totalWaviness(int num1, int num2) {
        int total = 0;
        for (int i = num1; i <= num2; i++) {
            total += getWaviness(i);
        }
        return total;
    }

    private int getWaviness(int x) {
        String s = Integer.toString(x);
        int waviness = 0;

        for (int i = 1; i < s.length() - 1; i++) {
            boolean isPeak =
                s.charAt(i) > s.charAt(i - 1) && s.charAt(i) > s.charAt(i + 1);
            boolean isValley =
                s.charAt(i) < s.charAt(i - 1) && s.charAt(i) < s.charAt(i + 1);
            if (isPeak || isValley) {
                waviness++;
            }
        }

        return waviness;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var totalWaviness = function (num1, num2) {
    const getWaviness = (x) => {
        const s = x.toString();
        let waviness = 0;

        for (let i = 1; i < s.length - 1; i++) {
            const isPeak = s[i] > s[i - 1] && s[i] > s[i + 1];
            const isValley = s[i] < s[i - 1] && s[i] < s[i + 1];
            if (isPeak || isValley) {
                waviness++;
            }
        }

        return waviness;
    };

    let total = 0;
    for (let i = num1; i <= num2; i++) {
        total += getWaviness(i);
    }

    return total;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        def waviness(n: int) -> int:
            s = str(n)
            return sum(
                (a < b > c) or (a > b < c) for a, b, c in zip(s, s[1:], s[2:])
            )

        return sum(waviness(n) for n in range(num1, num2 + 1))
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function totalWaviness(num1: number, num2: number): number {
    const getWaviness = (x: number): number => {
        const s: string = x.toString();
        let waviness: number = 0;

        for (let i = 1; i < s.length - 1; i++) {
            const isPeak: boolean = s[i] > s[i - 1] && s[i] > s[i + 1];
            const isValley: boolean = s[i] < s[i - 1] && s[i] < s[i + 1];
            if (isPeak || isValley) {
                waviness++;
            }
        }

        return waviness;
    };

    let total: number = 0;
    for (let i = num1; i <= num2; i++) {
        total += getWaviness(i);
    }

    return total;
}
```

</details>

<br>

## Approach 2: Digit Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    long long cnt;
    long long sum;
} Result;

Result dfs(const char* s, int n, long long memo_cnt[16][10][10],
           long long memo_sum[16][10][10], int pos, int prev, int curr,
           int isLimit, int isLeading) {
    // end position
    if (pos == n) {
        return (Result){1, 0};
    }
    // only use memoization when not limited by an upper bound and not
    // containing leading zeros
    if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
        if (memo_cnt[pos][prev][curr] != -1) {
            return (Result){memo_cnt[pos][prev][curr],
                            memo_sum[pos][prev][curr]};
        }
    }

    // calculate the number of solutions and volatility value under current
    // conditions
    long long cnt = 0, sum = 0;
    int up = isLimit ? (s[pos] - '0') : 9;
    for (int digit = 0; digit <= up; ++digit) {
        int newLeading = isLeading && (digit == 0);
        // the previous number is updated to curr
        int newPrev = curr;
        // the current number is updated to digit
        int newCurr = newLeading ? -1 : digit;
        Result sub = dfs(s, n, memo_cnt, memo_sum, pos + 1, newPrev, newCurr,
                         isLimit && (digit == up), newLeading);
        // only calculate the volatility value when there are no leading zeros
        if (!newLeading && prev >= 0 && curr >= 0) {
            // when the value is a peak or a trough, update the current
            // fluctuation value
            if ((prev < curr && curr > digit) ||
                (prev > curr && curr < digit)) {
                sum += sub.cnt;
            }
        }

        cnt += sub.cnt;
        sum += sub.sum;
    }

    if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
        // update the memoization array
        memo_cnt[pos][prev][curr] = cnt;
        memo_sum[pos][prev][curr] = sum;
    }

    return (Result){cnt, sum};
}

// calculate the sum of fluctuation values of all numbers in [0, num]
long long solve(long long num) {
    // if the number is less than 3, the fluctuation value is 0
    if (num < 100) {
        return 0;
    }

    char s[16];
    sprintf(s, "%lld", num);
    int n = strlen(s);

    // memoized search uses two independent arrays
    // memo_cnt[pos][x][y]: the number of valid filling schemes where the
    // current position is pos, and the previous two positions are x, y
    long long memo_cnt[16][10][10];
    // memo_sum[pos][x][y]: the fluctuation value when the current position is
    // pos and the two left digits are x and y
    long long memo_sum[16][10][10];
    // initialize the memoization array
    memset(memo_cnt, -1, sizeof(memo_cnt));
    memset(memo_sum, -1, sizeof(memo_sum));

    Result result = dfs(s, n, memo_cnt, memo_sum, 0, -1, -1, 1, 1);
    return result.sum;
}

int totalWaviness(int num1, int num2) {
    return (int)(solve(num2) - solve(num1 - 1));
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        using ll = long long;
        // calculate the sum of fluctuation values of all numbers in [0, num]
        auto solve = [&](ll num) -> ll {
            // if the number is less than 3, the fluctuation value is 0
            if (num < 100) {
                return 0;
            }
            string s = to_string(num);
            int n = s.size();

            // memoized search uses two independent arrays
            // memo_cnt[pos][x][y]: the number of valid filling schemes where
            // the current position is pos, and the previous two positions are
            // x, y
            ll memo_cnt[16][10][10];
            // memo_sum[pos][x][y]: the fluctuation value when the current
            // position is pos and the two left digits are x and y
            ll memo_sum[16][10][10];
            memset(memo_cnt, -1, sizeof(memo_cnt));
            memset(memo_sum, -1, sizeof(memo_sum));

            auto dfs = [&](this auto&& dfs, int pos, int prev, int curr,
                           bool isLimit, bool isLeading) -> pair<ll, ll> {
                // end position
                if (pos == n) {
                    return {1, 0};
                }
                // only use memoization when not limited by an upper bound and
                // not containing leading zeros
                if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                    if (memo_cnt[pos][prev][curr] != -1) {
                        return {memo_cnt[pos][prev][curr],
                                memo_sum[pos][prev][curr]};
                    }
                }

                // calculate the number of solutions and volatility value under
                // current conditions
                ll cnt = 0, sum = 0;
                int up = isLimit ? s[pos] - '0' : 9;
                for (int digit = 0; digit <= up; ++digit) {
                    bool newLeading = isLeading && (digit == 0);
                    // the previous number is updated to curr
                    int newPrev = curr;
                    // the current number is updated to digit
                    int newCurr = newLeading ? -1 : digit;
                    auto [subCnt, subSum] =
                        dfs(pos + 1, newPrev, newCurr, isLimit && (digit == up),
                            newLeading);
                    // only calculate the volatility value when there are no
                    // leading zeros
                    if (!newLeading && prev >= 0 && curr >= 0) {
                        // when the value is a peak or a trough, update the
                        // current fluctuation value
                        if ((prev < curr && curr > digit) ||
                            (prev > curr && curr < digit)) {
                            sum += subCnt;
                        }
                    }

                    cnt += subCnt;
                    sum += subSum;
                }

                if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                    // update the memoization array
                    memo_cnt[pos][prev][curr] = cnt;
                    memo_sum[pos][prev][curr] = sum;
                }

                return {cnt, sum};
            };

            auto [_, totalSum] = dfs(0, -1, -1, true, true);
            return totalSum;
        };

        return (int)(solve(num2) - solve(num1 - 1));
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private string s;
    private int n;
    private long[,,] memo_cnt;
    private long[,,] memo_sum;

    public int TotalWaviness(int num1, int num2) {
        return (int)(Solve(num2) - Solve(num1 - 1));
    }

    // calculate the sum of the volatility values of all numbers in the range
    // [0, num]
    private long Solve(long num) {
        // if the number is less than 3, the fluctuation value is 0
        if (num < 100) {
            return 0L;
        }
        s = num.ToString();
        n = s.Length;

        // memoized search uses two independent arrays
        // memo_cnt[pos][x][y]: the number of valid filling schemes where the
        // current position is pos, and the previous two positions are x, y
        memo_cnt = new long[16, 10, 10];
        // memo_sum[pos][x][y]: the fluctuation value when the current position
        // is pos and the two left digits are x and y
        memo_sum = new long[16, 10, 10];
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    memo_cnt[i, j, k] = -1;
                    memo_sum[i, j, k] = -1;
                }
            }
        }

        long[] result = Dfs(0, -1, -1, true, true);
        return result[1];
    }

    private long[] Dfs(int pos, int prev, int curr, bool isLimit,
                       bool isLeading) {
        // end position
        if (pos == n) {
            return new long[] { 1L, 0L };
        }
        // only use memoization when not limited by an upper bound and not
        // containing leading zeros
        if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
            if (memo_cnt[pos, prev, curr] != -1) {
                return new long[] { memo_cnt[pos, prev, curr],
                                    memo_sum[pos, prev, curr] };
            }
        }

        // calculate the number of solutions and volatility value under current
        // conditions
        long cnt = 0, sum = 0;
        int up = isLimit ? (s[pos] - '0') : 9;
        for (int digit = 0; digit <= up; ++digit) {
            bool newLeading = isLeading && (digit == 0);
            // the previous number is updated to curr
            int newPrev = curr;
            // the current number is updated to digit
            int newCurr = newLeading ? -1 : digit;
            long[] sub = Dfs(pos + 1, newPrev, newCurr,
                             isLimit && (digit == up), newLeading);
            long subCnt = sub[0], subSum = sub[1];
            // only calculate the volatility value when there are no leading
            // zeros
            if (!newLeading && prev >= 0 && curr >= 0) {
                // when the value is a peak or a trough, update the current
                // fluctuation value
                if ((prev < curr && curr > digit) ||
                    (prev > curr && curr < digit)) {
                    sum += subCnt;
                }
            }

            cnt += subCnt;
            sum += subSum;
        }

        if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
            // update the memoization array
            memo_cnt[pos, prev, curr] = cnt;
            memo_sum[pos, prev, curr] = sum;
        }

        return new long[] { cnt, sum };
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func totalWaviness(num1 int, num2 int) int {
    // calculate the sum of the volatility values of all numbers in the range [0, num]
    solve := func(num int64) int64 {
        // if the number is less than 3, the fluctuation value is 0
        if num < 100 {
            return 0
        }
        s := fmt.Sprintf("%d", num)
        n := len(s)
        
        // memoized search uses two independent arrays
        // memo_cnt[pos][x][y]: the number of valid filling schemes where the current position is pos, and the previous two positions are x, y
        memo_cnt := make([][][]int64, 16)
        // memo_sum[pos][x][y]: the fluctuation value when the current position is pos and the two left digits are x and y
        memo_sum := make([][][]int64, 16)
        for i := 0; i < 16; i++ {
            memo_cnt[i] = make([][]int64, 10)
            memo_sum[i] = make([][]int64, 10)
            for j := 0; j < 10; j++ {
                memo_cnt[i][j] = make([]int64, 10)
                memo_sum[i][j] = make([]int64, 10)
                for k := 0; k < 10; k++ {
                    memo_cnt[i][j][k] = -1
                    memo_sum[i][j][k] = -1
                }
            }
        }
        
        var dfs func(pos int, prev int, curr int, isLimit bool, isLeading bool) (int64, int64)
        dfs = func(pos int, prev int, curr int, isLimit bool, isLeading bool) (int64, int64) {
            // end position
            if pos == n {
                return 1, 0
            }
            // only use memoization when not limited by an upper bound and not containing leading zeros
            if !isLimit && !isLeading && prev >= 0 && curr >= 0 {
                if memo_cnt[pos][prev][curr] != -1 {
                    return memo_cnt[pos][prev][curr], memo_sum[pos][prev][curr]
                }
            }
            
            // calculate the number of solutions and volatility value under current conditions
            var cnt, sum int64 = 0, 0
            up := 9
            if isLimit {
                up = int(s[pos] - '0')
            }
            for digit := 0; digit <= up; digit++ {
                newLeading := isLeading && (digit == 0)
                // the previous number is updated to curr
                newPrev := curr
                // the current number is updated to digit
                newCurr := digit
                if newLeading {
                    newCurr = -1
                }
                subCnt, subSum := dfs(pos+1, newPrev, newCurr, isLimit && (digit == up), newLeading)
                // only calculate the volatility value when there are no leading zeros
                if !newLeading && prev >= 0 && curr >= 0 {
                    // when the value is a peak or a trough, update the current fluctuation value
                    if (prev < curr && curr > digit) || (prev > curr && curr < digit) {
                        sum += subCnt
                    }
                }
                
                cnt += subCnt
                sum += subSum
            }
            
            if !isLimit && !isLeading && prev >= 0 && curr >= 0 {
                // update the memoization array
                memo_cnt[pos][prev][curr] = cnt
                memo_sum[pos][prev][curr] = sum
            }
            
            return cnt, sum
        }
        
        _, totalSum := dfs(0, -1, -1, true, true)
        return totalSum
    }
    
    return int(solve(int64(num2)) - solve(int64(num1-1)))
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private String s;
    private int n;
    private long[][][] memo_cnt;
    private long[][][] memo_sum;

    public int totalWaviness(int num1, int num2) {
        return (int) (solve(num2) - solve(num1 - 1));
    }

    // calculate the sum of the volatility values of all numbers in the range [0, num]
    private long solve(long num) {
        // if the number is less than 3, the fluctuation value is 0
        if (num < 100) {
            return 0L;
        }
        s = Long.toString(num);
        n = s.length();

        // memoized search uses two independent arrays
        // memo_cnt[pos][x][y]: the number of valid filling schemes where the current position is pos, and the previous two positions are x, y
        memo_cnt = new long[16][10][10];
        // memo_sum[pos][x][y]: the fluctuation value when the current position is pos and the two left digits are x and y
        memo_sum = new long[16][10][10];
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 10; j++) {
                Arrays.fill(memo_cnt[i][j], -1);
                Arrays.fill(memo_sum[i][j], -1);
            }
        }

        long[] result = dfs(0, -1, -1, true, true);
        return result[1];
    }

    private long[] dfs(
        int pos,
        int prev,
        int curr,
        boolean isLimit,
        boolean isLeading
    ) {
        // end position
        if (pos == n) {
            return new long[] { 1L, 0L };
        }
        // only use memoization when not limited by an upper bound and not containing leading zeros
        if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
            if (memo_cnt[pos][prev][curr] != -1) {
                return new long[] {
                    memo_cnt[pos][prev][curr],
                    memo_sum[pos][prev][curr],
                };
            }
        }

        // calculate the number of solutions and volatility value under current conditions
        long cnt = 0;
        long sum = 0;
        int up = isLimit ? (s.charAt(pos) - '0') : 9;
        for (int digit = 0; digit <= up; ++digit) {
            boolean newLeading = isLeading && (digit == 0);
            // the previous number is updated to curr
            int newPrev = curr;
            // the current number is updated to digit
            int newCurr = newLeading ? -1 : digit;
            long[] sub = dfs(
                pos + 1,
                newPrev,
                newCurr,
                isLimit && (digit == up),
                newLeading
            );
            long subCnt = sub[0];
            long subSum = sub[1];
            // only calculate the volatility value when there are no leading zeros
            if (!newLeading && prev >= 0 && curr >= 0) {
                // when the value is a peak or a trough, update the current fluctuation value
                if (
                    (prev < curr && curr > digit) ||
                    (prev > curr && curr < digit)
                ) {
                    sum += subCnt;
                }
            }

            cnt += subCnt;
            sum += subSum;
        }

        if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
            // update the memoization array
            memo_cnt[pos][prev][curr] = cnt;
            memo_sum[pos][prev][curr] = sum;
        }

        return new long[] { cnt, sum };
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var totalWaviness = function (num1, num2) {
    // calculate the sum of fluctuation values of all numbers in [0, num]
    const solve = (num) => {
        // if the number is less than 3, the fluctuation value is 0
        if (num < 100) {
            return 0;
        }
        const s = num.toString();
        const n = s.length;

        // memoized search uses two independent arrays
        // memo_cnt[pos][x][y]: the number of valid filling schemes where the current position is pos, and the previous two positions are x, y
        const memo_cnt = Array(16)
            .fill()
            .map(() =>
                Array(10)
                    .fill()
                    .map(() => Array(10).fill(-1)),
            );
        // memo_sum[pos][x][y]: the fluctuation value when the current position is pos and the two left digits are x and y
        const memo_sum = Array(16)
            .fill()
            .map(() =>
                Array(10)
                    .fill()
                    .map(() => Array(10).fill(-1)),
            );

        const dfs = (pos, prev, curr, isLimit, isLeading) => {
            // end position
            if (pos === n) {
                return [1, 0];
            }
            // only use memoization when not limited by an upper bound and not containing leading zeros
            if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                if (memo_cnt[pos][prev][curr] !== -1) {
                    return [
                        memo_cnt[pos][prev][curr],
                        memo_sum[pos][prev][curr],
                    ];
                }
            }

            // calculate the number of solutions and volatility value under current conditions
            let cnt = 0,
                sum = 0;
            const up = isLimit ? parseInt(s[pos]) : 9;
            for (let digit = 0; digit <= up; ++digit) {
                const newLeading = isLeading && digit === 0;
                // the previous number is updated to curr
                const newPrev = curr;
                // the current number is updated to digit
                const newCurr = newLeading ? -1 : digit;
                const [subCnt, subSum] = dfs(
                    pos + 1,
                    newPrev,
                    newCurr,
                    isLimit && digit === up,
                    newLeading,
                );
                // only calculate the volatility value when there are no leading zeros
                if (!newLeading && prev >= 0 && curr >= 0) {
                    // when the value is a peak or a trough, update the current fluctuation value
                    if (
                        (prev < curr && curr > digit) ||
                        (prev > curr && curr < digit)
                    ) {
                        sum += subCnt;
                    }
                }

                cnt += subCnt;
                sum += subSum;
            }

            if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                // update the memoization array
                memo_cnt[pos][prev][curr] = cnt;
                memo_sum[pos][prev][curr] = sum;
            }

            return [cnt, sum];
        };

        const [_, totalSum] = dfs(0, -1, -1, true, true);
        return totalSum;
    };

    return solve(num2) - solve(num1 - 1);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        #  calculate the sum of the volatility values of all numbers in the range [0, num]
        def solve(num: int) -> int:
            # if the number is less than 3, the fluctuation value is 0
            if num < 100:
                return 0
            s = str(num)
            n = len(s)

            # memoized search uses two independent arrays
            # memo_cnt[pos][x][y]: the number of valid filling schemes where the current position is pos, and the previous two positions are x, y
            memo_cnt = [[[-1] * 10 for _ in range(10)] for _ in range(16)]
            # memo_sum[pos][x][y]: the fluctuation value when the current position is pos and the two left digits are x and y
            memo_sum = [[[-1] * 10 for _ in range(10)] for _ in range(16)]

            from functools import lru_cache

            @lru_cache(None)
            def dfs(
                pos: int, prev: int, curr: int, isLimit: bool, isLeading: bool
            ):
                # end position
                if pos == n:
                    return 1, 0

                # calculate the number of filling schemes and the fluctuation value under current conditions
                cnt = 0
                waviness = 0
                up = int(s[pos]) if isLimit else 9
                for digit in range(up + 1):
                    newLeading = isLeading and (digit == 0)
                    # the previous number is updated to curr
                    newPrev = curr
                    # the current number is updated to digit
                    newCurr = -1 if newLeading else digit
                    subCnt, subSum = dfs(
                        pos + 1,
                        newPrev,
                        newCurr,
                        isLimit and (digit == up),
                        newLeading,
                    )
                    # only calculate the volatility value when there are no leading zeros
                    if not newLeading and prev >= 0 and curr >= 0:
                        # when the value is a peak or a trough, update the current fluctuation value
                        if (prev < curr and curr > digit) or (
                            prev > curr and curr < digit
                        ):
                            waviness += subCnt

                    cnt += subCnt
                    waviness += subSum

                return cnt, waviness

            _, totalSum = dfs(0, -1, -1, True, True)
            return totalSum

        return solve(num2) - solve(num1 - 1)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function totalWaviness(num1: number, num2: number): number {
    // calculate the sum of fluctuation values of all numbers in [0, num]
    const solve = (num: number): number => {
        // if the number is less than 3, the fluctuation value is 0
        if (num < 100) {
            return 0;
        }
        const s: string = num.toString();
        const n: number = s.length;

        // memoized search uses two independent arrays
        // memo_cnt[pos][x][y]: the number of valid filling schemes where the current position is pos, and the previous two positions are x, y
        const memo_cnt: number[][][] = Array(16)
            .fill(null)
            .map(() =>
                Array(10)
                    .fill(null)
                    .map(() => Array(10).fill(-1)),
            );
        // memo_sum[pos][x][y]: the fluctuation value when the current position is pos and the two left digits are x and y
        const memo_sum: number[][][] = Array(16)
            .fill(null)
            .map(() =>
                Array(10)
                    .fill(null)
                    .map(() => Array(10).fill(-1)),
            );

        const dfs = (
            pos: number,
            prev: number,
            curr: number,
            isLimit: boolean,
            isLeading: boolean,
        ): [number, number] => {
            // end position
            if (pos === n) {
                return [1, 0];
            }
            // only use memoization when not limited by an upper bound and not containing leading zeros
            if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                if (memo_cnt[pos][prev][curr] !== -1) {
                    return [
                        memo_cnt[pos][prev][curr],
                        memo_sum[pos][prev][curr],
                    ];
                }
            }

            // calculate the number of solutions and volatility value under current conditions
            let cnt: number = 0,
                sum: number = 0;
            const up: number = isLimit ? parseInt(s[pos]) : 9;
            for (let digit = 0; digit <= up; ++digit) {
                const newLeading: boolean = isLeading && digit === 0;
                // the previous number is updated to curr
                const newPrev: number = curr;
                // the current number is updated to digit
                const newCurr: number = newLeading ? -1 : digit;
                const [subCnt, subSum] = dfs(
                    pos + 1,
                    newPrev,
                    newCurr,
                    isLimit && digit === up,
                    newLeading,
                );
                // only calculate the volatility value when there are no leading zeros
                if (!newLeading && prev >= 0 && curr >= 0) {
                    // when the value is a peak or a trough, update the current fluctuation value
                    if (
                        (prev < curr && curr > digit) ||
                        (prev > curr && curr < digit)
                    ) {
                        sum += subCnt;
                    }
                }

                cnt += subCnt;
                sum += subSum;
            }

            if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                // update the memoization array
                memo_cnt[pos][prev][curr] = cnt;
                memo_sum[pos][prev][curr] = sum;
            }

            return [cnt, sum];
        };

        const [_, totalSum] = dfs(0, -1, -1, true, true);
        return totalSum;
    };

    return solve(num2) - solve(num1 - 1);
}
```

</details>
