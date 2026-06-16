# 3753. Total Waviness of Numbers in Range II

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/total-waviness-of-numbers-in-range-ii/)  
`Math` `Dynamic Programming`

**Problem Link:** [LeetCode 3753 - Total Waviness of Numbers in Range II](https://leetcode.com/problems/total-waviness-of-numbers-in-range-ii/)

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

- 1 <= num1 <= num2 <= 1015​​​​​​​

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3753. Total Waviness of Numbers in Range II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Digit Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Bottom-Up Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Digit Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    long long cnt;
    long long sum;
} Result;

Result dfs(const char* s, int n, long long memo_cnt[20][10][10],
           long long memo_sum[20][10][10], int pos, int prev, int curr,
           int isLimit, int isLeading) {
    // end position
    if (pos == n) {
        return (Result){1, 0};
    }
    // use memoization only when not bounded by an upper limit and without
    // leading zeros
    if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
        if (memo_cnt[pos][prev][curr] != -1) {
            return (Result){memo_cnt[pos][prev][curr],
                            memo_sum[pos][prev][curr]};
        }
    }

    // calculate the number of schemes and fluctuation value under the current
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
        // only calculate the fluctuation value when there are no leading zeros
        if (!newLeading && prev >= 0 && curr >= 0) {
            // when the digit is a peak or a valley, update the current
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

// calculate the sum of the volatility values of all numbers in [0, num]
long long solve(long long num) {
    // if the fluctuation value of numbers less than 3 is 0
    if (num < 100) {
        return 0;
    }

    char s[20];
    sprintf(s, "%lld", num);
    int n = strlen(s);

    // memoized search uses two independent arrays
    // memo_cnt[pos][x][y]: the number of valid filling schemes where the
    // current digit is at position pos, and the previous two digits are x and y
    long long memo_cnt[20][10][10];
    // memo_sum[pos][x][y]: the fluctuation value when the current position is
    // pos, and the two left digits are x and y
    long long memo_sum[20][10][10];
    // initialize the memoization array
    memset(memo_cnt, -1, sizeof(memo_cnt));
    memset(memo_sum, -1, sizeof(memo_sum));

    Result result = dfs(s, n, memo_cnt, memo_sum, 0, -1, -1, 1, 1);
    return result.sum;
}

long long totalWaviness(long long num1, long long num2) {
    return solve(num2) - solve(num1 - 1);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        using ll = long long;
        // calculate the sum of the volatility values of all numbers in [0, num]
        auto solve = [&](ll num) -> ll {
            // if the fluctuation value of numbers less than 3 is 0
            if (num < 100) {
                return 0;
            }
            string s = to_string(num);
            int n = s.size();

            // memoized search uses two independent arrays
            // memo_cnt[pos][x][y]: the number of valid filling schemes where
            // the current digit is at position pos, and the previous two digits
            // are x and y
            ll memo_cnt[16][10][10];
            // memo_sum[pos][x][y]: the fluctuation value when the current
            // position is pos, and the two left digits are x and y
            ll memo_sum[16][10][10];
            memset(memo_cnt, -1, sizeof(memo_cnt));
            memset(memo_sum, -1, sizeof(memo_sum));

            auto dfs = [&](this auto&& dfs, int pos, int prev, int curr,
                           bool isLimit, bool isLeading) -> pair<ll, ll> {
                // end position
                if (pos == n) {
                    return {1, 0};
                }
                // use memoization only when not bounded by an upper limit and
                // without leading zeros
                if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                    if (memo_cnt[pos][prev][curr] != -1) {
                        return {memo_cnt[pos][prev][curr],
                                memo_sum[pos][prev][curr]};
                    }
                }

                // calculate the number of schemes and fluctuation value under
                // the current conditions
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
                    // only calculate the fluctuation value when there are no
                    // leading zeros
                    if (!newLeading && prev >= 0 && curr >= 0) {
                        // when the digit is a peak or a valley, update the
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

            // pass dfs as the first parameter
            auto [_, totalSum] = dfs(0, -1, -1, true, true);
            return totalSum;
        };

        return solve(num2) - solve(num1 - 1);
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

    public long TotalWaviness(long num1, long num2) {
        return Solve(num2) - Solve(num1 - 1);
    }

    // calculate the sum of fluctuation values of all numbers in the range [0,
    // num]
    private long Solve(long num) {
        // if the fluctuation value of numbers less than 3 is 0
        if (num < 100) {
            return 0L;
        }
        s = num.ToString();
        n = s.Length;

        // memoized search uses two independent arrays
        // memo_cnt[pos][x][y]: the number of valid filling schemes where the
        // current digit is at position pos, and the previous two digits are x
        // and y
        memo_cnt = new long[16, 10, 10];
        // memo_sum[pos][x][y]: the fluctuation value when the current position
        // is pos, and the two left digits are x and y
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
        // use memoization only when not bounded by an upper limit and without
        // leading zeros
        if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
            if (memo_cnt[pos, prev, curr] != -1) {
                return new long[] { memo_cnt[pos, prev, curr],
                                    memo_sum[pos, prev, curr] };
            }
        }

        // calculate the number of schemes and fluctuation value under the
        // current conditions
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
            // only calculate the fluctuation value when there are no leading
            // zeros
            if (!newLeading && prev >= 0 && curr >= 0) {
                // when the digit is a peak or a valley, update the current
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
func totalWaviness(num1 int64, num2 int64) int64 {
    // calculate the sum of fluctuation values of all numbers in the range [0, num]
    solve := func(num int64) int64 {
        // if the fluctuation value of numbers less than 3 is 0
        if num < 100 {
            return 0
        }
        s := fmt.Sprintf("%d", num)
        n := len(s)
        
        // memoized search uses two independent arrays
        // memo_cnt[pos][x][y]: the number of valid filling schemes where the current digit is at position pos, and the previous two digits are x and y
        memo_cnt := make([][][]int64, 16)
        // memo_sum[pos][x][y]: the fluctuation value when the current position is pos, and the two left digits are x and y
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
            // use memoization only when not bounded by an upper limit and without leading zeros
            if !isLimit && !isLeading && prev >= 0 && curr >= 0 {
                if memo_cnt[pos][prev][curr] != -1 {
                    return memo_cnt[pos][prev][curr], memo_sum[pos][prev][curr]
                }
            }
            
            // calculate the number of schemes and fluctuation value under the current conditions
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
                // only calculate the fluctuation value when there are no leading zeros
                if !newLeading && prev >= 0 && curr >= 0 {
                    // when the digit is a peak or a valley, update the current fluctuation value
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
    
    return solve(num2) - solve(num1-1)
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

    public long totalWaviness(long num1, long num2) {
        return solve(num2) - solve(num1 - 1);
    }

    // calculate the sum of fluctuation values of all numbers in the range [0, num]
    private long solve(long num) {
        // if the fluctuation value of numbers less than 3 is 0
        if (num < 100) {
            return 0L;
        }
        s = Long.toString(num);
        n = s.length();

        // memoized search uses two independent arrays
        // memo_cnt[pos][x][y]: the number of valid filling schemes where the current digit is at position pos, and the previous two digits are x and y
        memo_cnt = new long[16][10][10];
        // memo_sum[pos][x][y]: the fluctuation value when the current position is pos, and the two left digits are x and y
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
        // use memoization only when not bounded by an upper limit and without leading zeros
        if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
            if (memo_cnt[pos][prev][curr] != -1) {
                return new long[] {
                    memo_cnt[pos][prev][curr],
                    memo_sum[pos][prev][curr],
                };
            }
        }

        // calculate the number of schemes and fluctuation value under the current conditions
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
            // only calculate the fluctuation value when there are no leading zeros
            if (!newLeading && prev >= 0 && curr >= 0) {
                // when the digit is a peak or a valley, update the current fluctuation value
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
    // calculate the sum of the volatility values of all numbers in [0, num]
    const solve = (num) => {
        // if the fluctuation value of numbers less than 3 is 0
        if (num < 100) {
            return 0;
        }
        const s = num.toString();
        const n = s.length;

        // memoized search uses two independent arrays
        // memo_cnt[pos][x][y]: the number of valid filling schemes where the current digit is at position pos, and the previous two digits are x and y
        const memo_cnt = Array(16)
            .fill()
            .map(() =>
                Array(10)
                    .fill()
                    .map(() => Array(10).fill(-1)),
            );
        // memo_sum[pos][x][y]: the fluctuation value when the current position is pos, and the two left digits are x and y
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
            // use memoization only when not bounded by an upper limit and without leading zeros
            if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                if (memo_cnt[pos][prev][curr] !== -1) {
                    return [
                        memo_cnt[pos][prev][curr],
                        memo_sum[pos][prev][curr],
                    ];
                }
            }

            // calculate the number of schemes and fluctuation value under the current conditions
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
                // only calculate the fluctuation value when there are no leading zeros
                if (!newLeading && prev >= 0 && curr >= 0) {
                    // when the digit is a peak or a valley, update the current fluctuation value
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
        #  calculate the sum of fluctuation values of all numbers in the range [0, num]
        def solve(num: int) -> int:
            # if the fluctuation value of numbers less than 3 is 0
            if num < 100:
                return 0
            s = str(num)
            n = len(s)

            # memoized search uses two independent arrays
            # memo_cnt[pos][x][y]: the number of valid filling schemes where the current digit is at position pos, and the previous two digits are x and y
            memo_cnt = [[[-1] * 10 for _ in range(10)] for _ in range(16)]
            # memo_sum[pos][x][y]: the fluctuation value when the current position is pos, and the two left digits are x and y
            memo_sum = [[[-1] * 10 for _ in range(10)] for _ in range(16)]

            from functools import lru_cache

            @lru_cache(None)
            def dfs(
                pos: int, prev: int, curr: int, isLimit: bool, isLeading: bool
            ):
                # end position
                if pos == n:
                    return 1, 0

                # calculate the number of filling schemes and fluctuation value under current conditions
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
                    # only calculate the fluctuation value when there are no leading zeros
                    if not newLeading and prev >= 0 and curr >= 0:
                        # when the digit is a peak or a valley, update the current fluctuation value
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
    // calculate the sum of the volatility values of all numbers in [0, num]
    const solve = (num: number): number => {
        // if the fluctuation value of numbers less than 3 is 0
        if (num < 100) {
            return 0;
        }
        const s: string = num.toString();
        const n: number = s.length;

        // memoized search uses two independent arrays
        // memo_cnt[pos][x][y]: the number of valid filling schemes where the current digit is at position pos, and the previous two digits are x and y
        const memo_cnt: number[][][] = Array(16)
            .fill(null)
            .map(() =>
                Array(10)
                    .fill(null)
                    .map(() => Array(10).fill(-1)),
            );
        // memo_sum[pos][x][y]: the fluctuation value when the current position is pos, and the two left digits are x and y
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
            // use memoization only when not bounded by an upper limit and without leading zeros
            if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                if (memo_cnt[pos][prev][curr] !== -1) {
                    return [
                        memo_cnt[pos][prev][curr],
                        memo_sum[pos][prev][curr],
                    ];
                }
            }

            // calculate the number of schemes and fluctuation value under the current conditions
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
                // only calculate the fluctuation value when there are no leading zeros
                if (!newLeading && prev >= 0 && curr >= 0) {
                    // when the digit is a peak or a valley, update the current fluctuation value
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

<br>

## Approach 2: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int prev, curr, tight, lead;
    long long cnt, sum;
} State;

long long solve(long long num) {
    // if the number has fewer than 3 digits, the fluctuation value is 0
    if (num < 100) {
        return 0;
    }

    char s[20];
    sprintf(s, "%lld", num);
    int n = strlen(s);

    State currStates[500];
    int currSize = 0;

    // digit 10 represents the invalid state when there is a leading zero
    currStates[currSize++] = (State){10, 10, 1, 1, 1, 0};

    for (int pos = 0; pos < n; ++pos) {
        int limit = s[pos] - '0';

        // use a four-dimensional array for temporary storage, dimensions:
        // [tight][lead][prev][curr]
        long long cnt[2][2][11][11] = {0};
        long long sum[2][2][11][11] = {0};

        for (int i = 0; i < currSize; ++i) {
            State st = currStates[i];
            int maxDigit = st.tight ? limit : 9;

            for (int digit = 0; digit <= maxDigit; ++digit) {
                int newLead = (st.lead && digit == 0) ? 1 : 0;
                int newPrev = st.curr;
                int newCurr = newLead ? 10 : digit;
                int newTight = (st.tight && digit == maxDigit) ? 1 : 0;

                long long add = 0;
                // calculate fluctuation only when there are three significant
                // digits (both prev and curr are valid and not leading zeros)
                if (!newLead && st.prev != 10 && st.curr != 10) {
                    if ((st.prev < st.curr && st.curr > digit) ||
                        (st.prev > st.curr && st.curr < digit)) {
                        add = st.cnt;
                    }
                }

                cnt[newTight][newLead][newPrev][newCurr] += st.cnt;
                sum[newTight][newLead][newPrev][newCurr] += st.sum + add;
            }
        }

        // collect legal states
        State nextStates[500];
        int nextSize = 0;

        for (int tight = 0; tight < 2; ++tight) {
            for (int lead = 0; lead < 2; ++lead) {
                for (int prev = 0; prev <= 10; ++prev) {
                    for (int curr = 0; curr <= 10; ++curr) {
                        long long c = cnt[tight][lead][prev][curr];
                        long long s_val = sum[tight][lead][prev][curr];
                        // if the current state is valid, proceed to the next
                        // round of calculation
                        if (c != 0) {
                            nextStates[nextSize++] =
                                (State){prev, curr, tight, lead, c, s_val};
                        }
                    }
                }
            }
        }

        // switch to the next round state
        memcpy(currStates, nextStates, nextSize * sizeof(State));
        currSize = nextSize;
    }

    // sum of fluctuation values of all valid states
    long long ans = 0;
    for (int i = 0; i < currSize; ++i) {
        ans += currStates[i].sum;
    }
    return ans;
}

long long totalWaviness(long long num1, long long num2) {
    return solve(num2) - solve(num1 - 1);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    using ll = long long;

    struct State {
        int prev, curr, tight, lead;
        ll cnt, sum;
    };

    ll solve(ll num) {
        // if the number has fewer than 3 digits, the fluctuation value is 0
        if (num < 100) {
            return 0;
        }
        string s = to_string(num);
        int n = s.size();

        vector<State> currStates;
        // digit 10 indicates the invalid invalid state when there are leading
        // zeros
        currStates.push_back({10, 10, 1, 1, 1, 0});
        for (int pos = 0; pos < n; ++pos) {
            int limit = s[pos] - '0';
            ll cnt[2][2][11][11] = {0};
            ll sum[2][2][11][11] = {0};

            for (const auto& st : currStates) {
                int maxDigit = st.tight ? limit : 9;
                for (int digit = 0; digit <= maxDigit; ++digit) {
                    int newLead = st.lead && (digit == 0);
                    int newPrev = st.curr;
                    int newCurr = newLead ? 10 : digit;
                    int newTight = st.tight && (digit == maxDigit);

                    ll add = 0;
                    // calculate fluctuation only when there are three
                    // significant digits (both prev and curr are valid and not
                    // leading zeros)
                    if (!newLead && st.prev != 10 && st.curr != 10) {
                        if ((st.prev < st.curr && st.curr > digit) ||
                            (st.prev > st.curr && st.curr < digit)) {
                            add = st.cnt;
                        }
                    }

                    cnt[newTight][newLead][newPrev][newCurr] += st.cnt;
                    sum[newTight][newLead][newPrev][newCurr] += st.sum + add;
                }
            }

            // collect legal states
            vector<State> nextStates;
            for (int tight = 0; tight < 2; ++tight) {
                for (int lead = 0; lead < 2; ++lead) {
                    for (int prev = 0; prev <= 10; ++prev) {
                        for (int curr = 0; curr <= 10; ++curr) {
                            ll c = cnt[tight][lead][prev][curr];
                            ll s = sum[tight][lead][prev][curr];
                            // if the current state is valid, proceed to the
                            // next round of calculation
                            if (c != 0) {
                                nextStates.push_back(
                                    {prev, curr, tight, lead, c, s});
                            }
                        }
                    }
                }
            }

            currStates.swap(nextStates);
        }

        // sum of fluctuation values of all valid states
        ll ans = 0;
        for (const auto& st : currStates) {
            ans += st.sum;
        }
        return ans;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private class State {
        public int prev, curr, tight, lead;
        public long cnt, sum;

        public State(int prev, int curr, int tight, int lead, long cnt,
                     long sum) {
            this.prev = prev;
            this.curr = curr;
            this.tight = tight;
            this.lead = lead;
            this.cnt = cnt;
            this.sum = sum;
        }
    }

    private long Solve(long num) {
        // if the number has fewer than 3 digits, the fluctuation value is 0
        if (num < 100) {
            return 0;
        }
        string s = num.ToString();
        int n = s.Length;

        List<State> currStates = new List<State>();
        // digit 10 represents the invalid state when there is a leading zero
        currStates.Add(new State(10, 10, 1, 1, 1, 0));

        for (int pos = 0; pos < n; ++pos) {
            int limit = s[pos] - '0';
            long[,,,] cnt = new long[2, 2, 11, 11];
            long[,,,] sum = new long[2, 2, 11, 11];

            foreach (State st in currStates) {
                int maxDigit = st.tight == 1 ? limit : 9;
                for (int digit = 0; digit <= maxDigit; ++digit) {
                    int newLead = (st.lead == 1 && digit == 0) ? 1 : 0;
                    int newPrev = st.curr;
                    int newCurr = newLead == 1 ? 10 : digit;
                    int newTight = (st.tight == 1 && digit == maxDigit) ? 1 : 0;

                    long add = 0;
                    // calculate fluctuation only when there are three
                    // significant digits (both prev and curr are valid and not
                    // leading zeros)
                    if (newLead == 0 && st.prev != 10 && st.curr != 10) {
                        if ((st.prev < st.curr && st.curr > digit) ||
                            (st.prev > st.curr && st.curr < digit)) {
                            add = st.cnt;
                        }
                    }

                    cnt[newTight, newLead, newPrev, newCurr] += st.cnt;
                    sum[newTight, newLead, newPrev, newCurr] += st.sum + add;
                }
            }

            // collect legal states
            List<State> nextStates = new List<State>();
            for (int tight = 0; tight < 2; ++tight) {
                for (int lead = 0; lead < 2; ++lead) {
                    for (int prev = 0; prev <= 10; ++prev) {
                        for (int curr = 0; curr <= 10; ++curr) {
                            long c = cnt[tight, lead, prev, curr];
                            long sVal = sum[tight, lead, prev, curr];
                            // if the current state is valid, proceed to the
                            // next round of calculation
                            if (c != 0) {
                                nextStates.Add(new State(prev, curr, tight,
                                                         lead, c, sVal));
                            }
                        }
                    }
                }
            }

            currStates = nextStates;
        }

        // sum of fluctuation values of all valid states
        long ans = 0;
        foreach (State st in currStates) {
            ans += st.sum;
        }
        return ans;
    }

    public long TotalWaviness(long num1, long num2) {
        return Solve(num2) - Solve(num1 - 1);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type State struct {
    prev, curr, tight, lead int
    cnt, sum                 int64
}

func solve(num int64) int64 {
    // if the number has fewer than 3 digits, the fluctuation value is 0
    if num < 100 {
        return 0
    }
    s := fmt.Sprintf("%d", num)
    n := len(s)

    currStates := []State{{10, 10, 1, 1, 1, 0}}

    for pos := 0; pos < n; pos++ {
        limit := int(s[pos] - '0')
        cnt := [2][2][11][11]int64{}
        sum := [2][2][11][11]int64{}

        for _, st := range currStates {
            maxDigit := limit
            if st.tight == 0 {
                maxDigit = 9
            }
            for digit := 0; digit <= maxDigit; digit++ {
                newLead := 0
                if st.lead == 1 && digit == 0 {
                    newLead = 1
                }
                newPrev := st.curr
                newCurr := digit
                if newLead == 1 {
                    newCurr = 10
                }
                newTight := 0
                if st.tight == 1 && digit == maxDigit {
                    newTight = 1
                }

                add := int64(0)
                // calculate fluctuation only when there are three significant digits (both prev and curr are valid and not leading zeros)
                if newLead == 0 && st.prev != 10 && st.curr != 10 {
                    if (st.prev < st.curr && st.curr > digit) ||
                        (st.prev > st.curr && st.curr < digit) {
                        add = st.cnt
                    }
                }

                cnt[newTight][newLead][newPrev][newCurr] += st.cnt
                sum[newTight][newLead][newPrev][newCurr] += st.sum + add
            }
        }

        // collect legal states
        nextStates := []State{}
        for tight := 0; tight < 2; tight++ {
            for lead := 0; lead < 2; lead++ {
                for prev := 0; prev <= 10; prev++ {
                    for curr := 0; curr <= 10; curr++ {
                        c := cnt[tight][lead][prev][curr]
                        sVal := sum[tight][lead][prev][curr]
                        // if the current state is valid, proceed to the next round of calculation
                        if c != 0 {
                            nextStates = append(nextStates, State{prev, curr, tight, lead, c, sVal})
                        }
                    }
                }
            }
        }
        currStates = nextStates
    }

    // sum of fluctuation values of all valid states
    var ans int64 = 0
    for _, st := range currStates {
        ans += st.sum
    }
    return ans
}

func totalWaviness(num1 int64, num2 int64) int64 {
    return solve(num2) - solve(num1-1)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    static class State {

        int prev, curr, tight, lead;
        long cnt, sum;

        State(int prev, int curr, int tight, int lead, long cnt, long sum) {
            this.prev = prev;
            this.curr = curr;
            this.tight = tight;
            this.lead = lead;
            this.cnt = cnt;
            this.sum = sum;
        }
    }

    private long solve(long num) {
        // if the number has fewer than 3 digits, the fluctuation value is 0
        if (num < 100) {
            return 0;
        }
        String str = Long.toString(num);
        int n = str.length();

        List<State> currStates = new ArrayList<>();
        // digit 10 represents the invalid state when there is a leading zero
        currStates.add(new State(10, 10, 1, 1, 1, 0));

        for (int pos = 0; pos < n; ++pos) {
            int limit = str.charAt(pos) - '0';
            long[][][][] cnt = new long[2][2][11][11];
            long[][][][] sum = new long[2][2][11][11];

            for (State st : currStates) {
                int maxDigit = st.tight == 1 ? limit : 9;
                for (int digit = 0; digit <= maxDigit; ++digit) {
                    int newLead = (st.lead == 1 && digit == 0) ? 1 : 0;
                    int newPrev = st.curr;
                    int newCurr = newLead == 1 ? 10 : digit;
                    int newTight = (st.tight == 1 && digit == maxDigit) ? 1 : 0;

                    long add = 0;
                    // calculate fluctuation only when there are three significant digits (both prev and curr are valid and not leading zeros)
                    if (newLead == 0 && st.prev != 10 && st.curr != 10) {
                        if (
                            (st.prev < st.curr && st.curr > digit) ||
                            (st.prev > st.curr && st.curr < digit)
                        ) {
                            add = st.cnt;
                        }
                    }

                    cnt[newTight][newLead][newPrev][newCurr] += st.cnt;
                    sum[newTight][newLead][newPrev][newCurr] += st.sum + add;
                }
            }

            // collect legal states
            List<State> nextStates = new ArrayList<>();
            for (int tight = 0; tight < 2; ++tight) {
                for (int lead = 0; lead < 2; ++lead) {
                    for (int prev = 0; prev <= 10; ++prev) {
                        for (int curr = 0; curr <= 10; ++curr) {
                            long c = cnt[tight][lead][prev][curr];
                            long s = sum[tight][lead][prev][curr];
                            // if the current state is valid, proceed to the next round of calculation
                            if (c != 0) {
                                nextStates.add(
                                    new State(prev, curr, tight, lead, c, s)
                                );
                            }
                        }
                    }
                }
            }

            currStates = nextStates;
        }

        // sum of fluctuation values of all valid states
        long ans = 0;
        for (State st : currStates) {
            ans += st.sum;
        }
        return ans;
    }

    public long totalWaviness(long num1, long num2) {
        return solve(num2) - solve(num1 - 1);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var totalWaviness = function (num1, num2) {
    // calculate the sum of the volatility values of all numbers in [0, num]
    const solve = (num) => {
        // if the number has fewer than 3 digits, the fluctuation value is 0
        if (num < 100) {
            return 0;
        }

        const s = num.toString();
        const n = s.length;
        let currStates = [];
        // digit 10 represents the invalid state when there is a leading zero
        currStates.push({
            prev: 10,
            curr: 10,
            tight: 1,
            lead: 1,
            cnt: 1,
            sum: 0,
        });

        for (let pos = 0; pos < n; ++pos) {
            const limit = parseInt(s[pos]);

            // use a four-dimensional array for temporary storage, dimensions: [tight][lead][prev][curr]
            const cnt = Array(2)
                .fill()
                .map(() =>
                    Array(2)
                        .fill()
                        .map(() =>
                            Array(11)
                                .fill()
                                .map(() => Array(11).fill(0)),
                        ),
                );
            const sumArr = Array(2)
                .fill()
                .map(() =>
                    Array(2)
                        .fill()
                        .map(() =>
                            Array(11)
                                .fill()
                                .map(() => Array(11).fill(0)),
                        ),
                );

            for (const st of currStates) {
                const maxDigit = st.tight ? limit : 9;

                for (let digit = 0; digit <= maxDigit; ++digit) {
                    const newLead = st.lead && digit === 0 ? 1 : 0;
                    const newPrev = st.curr;
                    const newCurr = newLead ? 10 : digit;
                    const newTight = st.tight && digit === maxDigit ? 1 : 0;

                    let add = 0;
                    // calculate fluctuation only when there are three significant digits (both prev and curr are valid and not leading zeros)
                    if (!newLead && st.prev !== 10 && st.curr !== 10) {
                        if (
                            (st.prev < st.curr && st.curr > digit) ||
                            (st.prev > st.curr && st.curr < digit)
                        ) {
                            add = st.cnt;
                        }
                    }

                    cnt[newTight][newLead][newPrev][newCurr] += st.cnt;
                    sumArr[newTight][newLead][newPrev][newCurr] += st.sum + add;
                }
            }

            // collect legal states
            const nextStates = [];
            for (let tight = 0; tight < 2; ++tight) {
                for (let lead = 0; lead < 2; ++lead) {
                    for (let prev = 0; prev <= 10; ++prev) {
                        for (let curr = 0; curr <= 10; ++curr) {
                            const c = cnt[tight][lead][prev][curr];
                            const sVal = sumArr[tight][lead][prev][curr];
                            // if the current state is valid, proceed to the next round of calculation
                            if (c !== 0) {
                                nextStates.push({
                                    prev,
                                    curr,
                                    tight,
                                    lead,
                                    cnt: c,
                                    sum: sVal,
                                });
                            }
                        }
                    }
                }
            }

            currStates = nextStates;
        }

        // sum of fluctuation values of all valid states
        let ans = 0;
        for (const st of currStates) {
            ans += st.sum;
        }
        return ans;
    };

    return solve(num2) - solve(num1 - 1);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def solve(self, num: int) -> int:
        # if the number has fewer than 3 digits, the fluctuation value is 0
        if num < 100:
            return 0
        s = str(num)
        n = len(s)

        # digit 10 represents the invalid state when there is a leading zero
        curr_states = [
            (10, 10, 1, 1, 1, 0)
        ]  # (prev, curr, tight, lead, cnt, sum)

        for pos in range(n):
            limit = int(s[pos])
            cnt = [
                [[[0] * 11 for _ in range(11)] for _ in range(2)]
                for _ in range(2)
            ]
            sum_arr = [
                [[[0] * 11 for _ in range(11)] for _ in range(2)]
                for _ in range(2)
            ]

            for prev, curr, tight, lead, c, s_val in curr_states:
                max_digit = limit if tight else 9
                for digit in range(max_digit + 1):
                    new_lead = 1 if (lead and digit == 0) else 0
                    new_prev = curr
                    new_curr = 10 if new_lead else digit
                    new_tight = 1 if (tight and digit == max_digit) else 0

                    add = 0
                    # calculate fluctuation only when there are three significant digits (both prev and curr are valid and not leading zeros)
                    if not new_lead and prev != 10 and curr != 10:
                        if (prev < curr and curr > digit) or (
                            prev > curr and curr < digit
                        ):
                            add = c

                    cnt[new_tight][new_lead][new_prev][new_curr] += c
                    sum_arr[new_tight][new_lead][new_prev][new_curr] += (
                        s_val + add
                    )

            # collect legal states
            next_states = []
            for tight in range(2):
                for lead in range(2):
                    for prev in range(11):
                        for cur in range(11):
                            c = cnt[tight][lead][prev][cur]
                            if c != 0:
                                next_states.append(
                                    (
                                        prev,
                                        cur,
                                        tight,
                                        lead,
                                        c,
                                        sum_arr[tight][lead][prev][cur],
                                    )
                                )
            curr_states = next_states

        # sum of fluctuation values of all valid states
        ans = 0
        for _, _, _, _, _, s_val in curr_states:
            ans += s_val
        return ans

    def totalWaviness(self, num1: int, num2: int) -> int:
        return self.solve(num2) - self.solve(num1 - 1)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function totalWaviness(num1: number, num2: number): number {
    // calculate the sum of the volatility values of all numbers in [0, num]
    const solve = (num: number): number => {
        // if the number has fewer than 3 digits, the fluctuation value is 0
        if (num < 100) {
            return 0;
        }

        const s: string = num.toString();
        const n: number = s.length;

        interface State {
            prev: number;
            curr: number;
            tight: number;
            lead: number;
            cnt: number;
            sum: number;
        }

        let currStates: State[] = [];
        // digit 10 represents the invalid state when there is a leading zero
        currStates.push({
            prev: 10,
            curr: 10,
            tight: 1,
            lead: 1,
            cnt: 1,
            sum: 0,
        });
        for (let pos = 0; pos < n; ++pos) {
            const limit: number = parseInt(s[pos]);

            // use a four-dimensional array for temporary storage, dimensions: [tight][lead][prev][curr]
            const cnt: number[][][][] = Array(2)
                .fill(null)
                .map(() =>
                    Array(2)
                        .fill(null)
                        .map(() =>
                            Array(11)
                                .fill(null)
                                .map(() => Array(11).fill(0)),
                        ),
                );
            const sumArr: number[][][][] = Array(2)
                .fill(null)
                .map(() =>
                    Array(2)
                        .fill(null)
                        .map(() =>
                            Array(11)
                                .fill(null)
                                .map(() => Array(11).fill(0)),
                        ),
                );

            for (const st of currStates) {
                const maxDigit: number = st.tight ? limit : 9;

                for (let digit = 0; digit <= maxDigit; ++digit) {
                    const newLead: number = st.lead && digit === 0 ? 1 : 0;
                    const newPrev: number = st.curr;
                    const newCurr: number = newLead ? 10 : digit;
                    const newTight: number =
                        st.tight && digit === maxDigit ? 1 : 0;

                    let add: number = 0;
                    // calculate fluctuation only when there are three significant digits (both prev and curr are valid and not leading zeros)
                    if (!newLead && st.prev !== 10 && st.curr !== 10) {
                        if (
                            (st.prev < st.curr && st.curr > digit) ||
                            (st.prev > st.curr && st.curr < digit)
                        ) {
                            add = st.cnt;
                        }
                    }

                    cnt[newTight][newLead][newPrev][newCurr] += st.cnt;
                    sumArr[newTight][newLead][newPrev][newCurr] += st.sum + add;
                }
            }

            // collect legal states
            const nextStates: State[] = [];
            for (let tight = 0; tight < 2; ++tight) {
                for (let lead = 0; lead < 2; ++lead) {
                    for (let prev = 0; prev <= 10; ++prev) {
                        for (let curr = 0; curr <= 10; ++curr) {
                            const c: number = cnt[tight][lead][prev][curr];
                            const sVal: number =
                                sumArr[tight][lead][prev][curr];
                            // if the current state is valid, proceed to the next round of calculation
                            if (c !== 0) {
                                nextStates.push({
                                    prev,
                                    curr,
                                    tight,
                                    lead,
                                    cnt: c,
                                    sum: sVal,
                                });
                            }
                        }
                    }
                }
            }

            currStates = nextStates;
        }

        // sum of fluctuation values of all valid states
        let ans: number = 0;
        for (const st of currStates) {
            ans += st.sum;
        }
        return ans;
    };

    return solve(num2) - solve(num1 - 1);
}
```

</details>
