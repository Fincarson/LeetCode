# 2999. Count the Number of Powerful Integers

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/count-the-number-of-powerful-integers/)  
`Math` `String` `Dynamic Programming`

**Problem Link:** [LeetCode 2999 - Count the Number of Powerful Integers](https://leetcode.com/problems/count-the-number-of-powerful-integers/)

## Problem

You are given three integers start, finish, and limit. You are also given a 0-indexed string s representing a positive integer.

A positive integer x is called powerful if it ends with s (in other words, s is a suffix of x) and each digit in x is at most limit.

Return the total number of powerful integers in the range [start..finish].

A string x is a suffix of a string y if and only if x is a substring of y that starts from some index (including 0) in y and extends to the index y.length - 1. For example, 25 is a suffix of 5125 whereas 512 is not.

### Example 1

```text
Input: start = 1, finish = 6000, limit = 4, s = "124"
Output: 5
Explanation: The powerful integers in the range [1..6000] are 124, 1124, 2124, 3124, and, 4124. All these integers have each digit <= 4, and "124" as a suffix. Note that 5124 is not a powerful integer because the first digit is 5 which is greater than 4.
It can be shown that there are only 5 powerful integers in this range.
```

### Example 2

```text
Input: start = 15, finish = 215, limit = 6, s = "10"
Output: 2
Explanation: The powerful integers in the range [15..215] are 110 and 210. All these integers have each digit <= 6, and "10" as a suffix.
It can be shown that there are only 2 powerful integers in this range.
```

### Example 3

```text
Input: start = 1000, finish = 2000, limit = 4, s = "3000"
Output: 0
Explanation: All integers in the range [1000..2000] are smaller than 3000, hence "3000" cannot be a suffix of any integer in this range.
```

## Constraints

- 1 <= start <= finish <= 1015
- 1 <= limit <= 9
- 1 <= s.length <= floor(log10(finish)) + 1
- s only consists of numeric digits which are at most limit.
- s does not have leading zeros.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Powerful Integers](https://leetcode.com/problems/powerful-integers/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Numbers With Repeated Digits](https://leetcode.com/problems/numbers-with-repeated-digits/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2999. Count the Number of Powerful Integers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Digital Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Combinatorial mathematics | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Digital Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
long long dfs(int i, bool limit_low, bool limit_high, const char* low,
              const char* high, int limit, const char* s, int pre_len,
              long long* memo, int n) {
    // recursive boundary
    if (i == n) {
        return 1;
    }
    if (!limit_low && !limit_high && memo[i] != -1) {
        return memo[i];
    }

    int lo = limit_low ? low[i] - '0' : 0;
    int hi = limit_high ? high[i] - '0' : 9;
    long long res = 0;
    if (i < pre_len) {
        for (int digit = lo; digit <= fmin(hi, limit); digit++) {
            res += dfs(i + 1, limit_low && digit == (low[i] - '0'),
                       limit_high && digit == (high[i] - '0'), low, high, limit,
                       s, pre_len, memo, n);
        }
    } else {
        int x = s[i - pre_len] - '0';
        if (lo <= x && x <= fmin(hi, limit)) {
            res = dfs(i + 1, limit_low && x == (low[i] - '0'),
                      limit_high && x == (high[i] - '0'), low, high, limit, s,
                      pre_len, memo, n);
        }
    }
    if (!limit_low && !limit_high) {
        memo[i] = res;
    }
    return res;
}

long long numberOfPowerfulInt(long long start, long long finish, int limit,
                              char* s) {
    char low[32], high[32];
    sprintf(low, "%lld", start);
    sprintf(high, "%lld", finish);
    int n = strlen(high);
    char* padded_low = (char*)malloc(n + 1);

    memset(padded_low, '0', sizeof(char) * n);
    sprintf(padded_low + n - strlen(low), "%s", low);  // align digits
    int pre_len = n - strlen(s);                       // prefix length
    long long* memo = (long long*)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        memo[i] = -1;
    }
    long long result =
        dfs(0, true, true, padded_low, high, limit, s, pre_len, memo, n);
    free(padded_low);
    free(memo);

    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s) {
        string low = to_string(start);
        string high = to_string(finish);
        int n = high.size();
        low = string(n - low.size(), '0') + low;  // align digits
        int pre_len = n - s.size();               // prefix length

        vector<long long> memo(n, -1);
        function<long long(int, bool, bool)> dfs =
            [&](int i, bool limit_low, bool limit_high) -> long long {
            // recursive boundary
            if (i == low.size()) {
                return 1;
            }

            if (!limit_low && !limit_high && memo[i] != -1) {
                return memo[i];
            }

            int lo = limit_low ? low[i] - '0' : 0;
            int hi = limit_high ? high[i] - '0' : 9;

            long long res = 0;
            if (i < pre_len) {
                for (int digit = lo; digit <= min(hi, limit); digit++) {
                    res += dfs(i + 1, limit_low && digit == lo,
                               limit_high && digit == hi);
                }
            } else {
                int x = s[i - pre_len] - '0';
                if (lo <= x && x <= min(hi, limit)) {
                    res =
                        dfs(i + 1, limit_low && x == lo, limit_high && x == hi);
                }
            }

            if (!limit_low && !limit_high) {
                memo[i] = res;
            }
            return res;
        };
        return dfs(0, true, true);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public long NumberOfPowerfulInt(long start, long finish, int limit,
                                    string s) {
        string low = start.ToString();
        string high = finish.ToString();
        int n = high.Length;
        low = low.PadLeft(n, '0');   // align digits
        int pre_len = n - s.Length;  // prefix length
        long[] memo = new long[n];
        Array.Fill(memo, -1);

        return Dfs(0, true, true, low, high, limit, s, pre_len, memo);
    }

    private long Dfs(int i, bool limitLow, bool limitHigh, string low,
                     string high, int limit, string s, int preLen,
                     long[] memo) {
        // recursive boundary
        if (i == low.Length) {
            return 1;
        }
        if (!limitLow && !limitHigh && memo[i] != -1) {
            return memo[i];
        }
        int lo = limitLow ? low[i] - '0' : 0;
        int hi = limitHigh ? high[i] - '0' : 9;
        long res = 0;
        if (i < preLen) {
            for (int digit = lo; digit <= Math.Min(hi, limit); digit++) {
                res += Dfs(i + 1, limitLow && digit == lo,
                           limitHigh && digit == hi, low, high, limit, s,
                           preLen, memo);
            }
        } else {
            int x = s[i - preLen] - '0';
            if (lo <= x && x <= Math.Min(hi, limit)) {
                res = Dfs(i + 1, limitLow && x == lo, limitHigh && x == hi, low,
                          high, limit, s, preLen, memo);
            }
        }

        if (!limitLow && !limitHigh) {
            memo[i] = res;
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func numberOfPowerfulInt(start int64, finish int64, limit int, s string) int64 {
	low := fmt.Sprintf("%d", start)
	high := fmt.Sprintf("%d", finish)
	n := len(high)
	low = strings.Repeat("0", n - len(low)) + low // align digits
	pre_len := n - len(s)                       // prefix length
	memo := make([]int64, n)
	for i := range memo {
		memo[i] = -1
	}

	var dfs func(int, bool, bool) int64
	dfs = func(i int, limit_low, limit_high bool) int64 {
		// recursive boundary
		if i == n {
			return 1
		}
		if !limit_low && !limit_high && memo[i] != -1 {
			return memo[i]
		}
		lo := 0
		if limit_low {
			lo = int(low[i] - '0')
		}
		hi := 9
		if limit_high {
			hi = int(high[i] - '0')
		}

		var res int64 = 0
		if i < pre_len {
			for digit := lo; digit <= min(hi, limit); digit++ {
				res += dfs(i + 1, limit_low && digit == lo, limit_high && digit == hi)
			}
		} else {
			x := int(s[i - pre_len] - '0')
			if lo <= x && x <= min(hi, limit) {
				res = dfs(i + 1, limit_low && x == lo, limit_high && x == hi)
			}
		}

		if !limit_low && !limit_high {
			memo[i] = res
		}
		return res
	}
	return dfs(0, true, true)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long numberOfPowerfulInt(
        long start,
        long finish,
        int limit,
        String s
    ) {
        String low = Long.toString(start);
        String high = Long.toString(finish);
        int n = high.length();
        low = String.format("%" + n + "s", low).replace(' ', '0'); // align digits
        int pre_len = n - s.length(); // prefix length
        long[] memo = new long[n];
        Arrays.fill(memo, -1);

        return dfs(0, true, true, low, high, limit, s, pre_len, memo);
    }

    private long dfs(
        int i,
        boolean limit_low,
        boolean limit_high,
        String low,
        String high,
        int limit,
        String s,
        int pre_len,
        long[] memo
    ) {
        // recursive boundary
        if (i == low.length()) {
            return 1;
        }
        if (!limit_low && !limit_high && memo[i] != -1) {
            return memo[i];
        }

        int lo = limit_low ? low.charAt(i) - '0' : 0;
        int hi = limit_high ? high.charAt(i) - '0' : 9;
        long res = 0;
        if (i < pre_len) {
            for (int digit = lo; digit <= Math.min(hi, limit); digit++) {
                res += dfs(
                    i + 1,
                    limit_low && digit == lo,
                    limit_high && digit == hi,
                    low,
                    high,
                    limit,
                    s,
                    pre_len,
                    memo
                );
            }
        } else {
            int x = s.charAt(i - pre_len) - '0';
            if (lo <= x && x <= Math.min(hi, limit)) {
                res = dfs(
                    i + 1,
                    limit_low && x == lo,
                    limit_high && x == hi,
                    low,
                    high,
                    limit,
                    s,
                    pre_len,
                    memo
                );
            }
        }
        if (!limit_low && !limit_high) {
            memo[i] = res;
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numberOfPowerfulInt = function (start, finish, limit, s) {
    let low = start.toString();
    let high = finish.toString();
    const n = high.length;
    low = low.padStart(n, "0"); // align digits
    const pre_len = n - s.length; // prefix length
    const memo = new Array(n).fill(-1);

    function dfs(i, limit_low, limit_high) {
        // recursive boundary
        if (i === n) {
            return 1;
        }
        if (!limit_low && !limit_high && memo[i] !== -1) {
            return memo[i];
        }

        const lo = limit_low ? parseInt(low[i]) : 0;
        const hi = limit_high ? parseInt(high[i]) : 9;
        let res = 0;
        if (i < pre_len) {
            for (let digit = lo; digit <= Math.min(hi, limit); digit++) {
                res += dfs(
                    i + 1,
                    limit_low && digit === lo,
                    limit_high && digit === hi,
                );
            }
        } else {
            const x = parseInt(s[i - pre_len]);
            if (lo <= x && x <= Math.min(hi, limit)) {
                res = dfs(i + 1, limit_low && x === lo, limit_high && x === hi);
            }
        }
        if (!limit_low && !limit_high) {
            memo[i] = res;
        }

        return res;
    }

    return dfs(0, true, true);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfPowerfulInt(
        self, start: int, finish: int, limit: int, s: str
    ) -> int:
        low = str(start)
        high = str(finish)
        n = len(high)
        low = low.zfill(n)  # align digits
        pre_len = n - len(s)  # prefix length

        @cache
        def dfs(i, limit_low, limit_high):
            # recursive boundary
            if i == n:
                return 1
            lo = int(low[i]) if limit_low else 0
            hi = int(high[i]) if limit_high else 9
            res = 0
            if i < pre_len:
                for digit in range(lo, min(hi, limit) + 1):
                    res += dfs(
                        i + 1,
                        limit_low and digit == lo,
                        limit_high and digit == hi,
                    )
            else:
                x = int(s[i - pre_len])
                if lo <= x <= min(hi, limit):
                    res = dfs(
                        i + 1, limit_low and x == lo, limit_high and x == hi
                    )

            return res

        return dfs(0, True, True)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function numberOfPowerfulInt(
    start: number,
    finish: number,
    limit: number,
    s: string,
): number {
    let low = start.toString();
    let high = finish.toString();
    const n = high.length;
    low = low.padStart(n, "0"); // align digits
    const pre_len = n - s.length; // prefix length
    const memo: number[] = new Array(n).fill(-1);

    function dfs(i: number, limit_low: boolean, limit_high: boolean): number {
        // recursive boundary
        if (i === n) {
            return 1;
        }
        if (!limit_low && !limit_high && memo[i] !== -1) {
            return memo[i];
        }

        const lo = limit_low ? parseInt(low[i]) : 0;
        const hi = limit_high ? parseInt(high[i]) : 9;
        let res = 0;
        if (i < pre_len) {
            for (let digit = lo; digit <= Math.min(hi, limit); digit++) {
                res += dfs(
                    i + 1,
                    limit_low && digit === lo,
                    limit_high && digit === hi,
                );
            }
        } else {
            const x = parseInt(s[i - pre_len]);
            if (lo <= x && x <= Math.min(hi, limit)) {
                res = dfs(i + 1, limit_low && x === lo, limit_high && x === hi);
            }
        }
        if (!limit_low && !limit_high) {
            memo[i] = res;
        }

        return res;
    }

    return dfs(0, true, true);
}
```

</details>

<br>

## Approach 2: Combinatorial mathematics

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
long long calculate(const char* x, const char* s, int limit) {
    int x_len = strlen(x);
    int s_len = strlen(s);
    if (x_len < s_len) {
        return 0;
    }
    if (x_len == s_len) {
        return strcmp(x, s) >= 0 ? 1 : 0;
    }

    char* suffix = (char*)malloc(s_len + 1);
    strncpy(suffix, x + x_len - s_len, s_len);
    suffix[s_len] = '\0';
    long long count = 0;
    int preLen = x_len - s_len;

    for (int i = 0; i < preLen; i++) {
        int digit = x[i] - '0';
        if (limit < digit) {
            count += (long long)pow(limit + 1, preLen - i);
            free(suffix);
            return count;
        }
        count += (long long)digit * (long long)pow(limit + 1, preLen - 1 - i);
    }
    if (strcmp(suffix, s) >= 0) {
        count++;
    }
    free(suffix);
    return count;
}

long long numberOfPowerfulInt(long long start, long long finish, int limit,
                              const char* s) {
    char start_[20], finish_[20];
    sprintf(start_, "%lld", start - 1);
    sprintf(finish_, "%lld", finish);
    return calculate(finish_, s, limit) - calculate(start_, s, limit);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s) {
        string start_ = to_string(start - 1), finish_ = to_string(finish);
        return calculate(finish_, s, limit) - calculate(start_, s, limit);
    }

    long long calculate(string x, string s, int limit) {
        if (x.length() < s.length()) {
            return 0;
        }
        if (x.length() == s.length()) {
            return x >= s ? 1 : 0;
        }

        string suffix = x.substr(x.length() - s.length(), s.length());
        long long count = 0;
        int preLen = x.length() - s.length();

        for (int i = 0; i < preLen; i++) {
            if (limit < (x[i] - '0')) {
                count += (long)pow(limit + 1, preLen - i);
                return count;
            }
            count += (long)(x[i] - '0') * (long)pow(limit + 1, preLen - 1 - i);
        }
        if (suffix >= s) {
            count++;
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public long NumberOfPowerfulInt(long start, long finish, int limit,
                                    string s) {
        string start_ = (start - 1).ToString();
        string finish_ = finish.ToString();
        return Calculate(finish_, s, limit) - Calculate(start_, s, limit);
    }

    private long Calculate(string x, string s, int limit) {
        if (x.Length < s.Length) {
            return 0;
        }
        if (x.Length == s.Length) {
            return string.Compare(x, s) >= 0 ? 1 : 0;
        }

        string suffix = x.Substring(x.Length - s.Length);
        long count = 0;
        int preLen = x.Length - s.Length;

        for (int i = 0; i < preLen; i++) {
            int digit = x[i] - '0';
            if (limit < digit) {
                count += (long)Math.Pow(limit + 1, preLen - i);
                return count;
            }
            count += (long)digit * (long)Math.Pow(limit + 1, preLen - 1 - i);
        }
        if (string.Compare(suffix, s) >= 0) {
            count++;
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func numberOfPowerfulInt(start int64, finish int64, limit int, s string) int64 {
    start_ := strconv.FormatInt(start - 1, 10)
	finish_ := strconv.FormatInt(finish, 10)
	return calculate(finish_, s, limit) - calculate(start_, s, limit)
}

func calculate(x string, s string, limit int) int64 {
	if len(x) < len(s) {
		return 0
	}
	if len(x) == len(s) {
		if x >= s {
			return 1
		}
		return 0
	}

	suffix := x[len(x) - len(s):]
	var count int64
	preLen := len(x) - len(s)

	for i := 0; i < preLen; i++ {
		digit := int(x[i] - '0')
		if limit < digit {
			count += int64(math.Pow(float64(limit + 1), float64(preLen - i)))
			return count
		}
		count += int64(digit) * int64(math.Pow(float64(limit + 1), float64(preLen - 1- i)))
	}
	if suffix >= s {
		count++
	}
	return count
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long numberOfPowerfulInt(
        long start,
        long finish,
        int limit,
        String s
    ) {
        String start_ = Long.toString(start - 1);
        String finish_ = Long.toString(finish);
        return calculate(finish_, s, limit) - calculate(start_, s, limit);
    }

    private long calculate(String x, String s, int limit) {
        if (x.length() < s.length()) {
            return 0;
        }
        if (x.length() == s.length()) {
            return x.compareTo(s) >= 0 ? 1 : 0;
        }

        String suffix = x.substring(x.length() - s.length());
        long count = 0;
        int preLen = x.length() - s.length();

        for (int i = 0; i < preLen; i++) {
            int digit = x.charAt(i) - '0';
            if (limit < digit) {
                count += (long) Math.pow(limit + 1, preLen - i);
                return count;
            }
            count +=
                (long) (digit) * (long) Math.pow(limit + 1, preLen - 1 - i);
        }
        if (suffix.compareTo(s) >= 0) {
            count++;
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numberOfPowerfulInt = function (start, finish, limit, s) {
    const start_ = (start - 1).toString();
    const finish_ = finish.toString();
    return calculate(finish_, s, limit) - calculate(start_, s, limit);
};

function calculate(x, s, limit) {
    if (x.length < s.length) {
        return 0;
    }
    if (x.length === s.length) {
        return x >= s ? 1 : 0;
    }

    const suffix = x.slice(-s.length);
    let count = 0;
    const preLen = x.length - s.length;

    for (let i = 0; i < preLen; i++) {
        const digit = parseInt(x[i]);
        if (limit < digit) {
            count += Math.pow(limit + 1, preLen - i);
            return count;
        }
        count += digit * Math.pow(limit + 1, preLen - 1 - i);
    }
    if (suffix >= s) {
        count++;
    }
    return count;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfPowerfulInt(
        self, start: int, finish: int, limit: int, s: str
    ) -> int:
        start_ = str(start - 1)
        finish_ = str(finish)
        return self.calculate(finish_, s, limit) - self.calculate(
            start_, s, limit
        )

    def calculate(self, x: str, s: str, limit: int) -> int:
        if len(x) < len(s):
            return 0
        if len(x) == len(s):
            return 1 if x >= s else 0

        suffix = x[len(x) - len(s) :]
        count = 0
        pre_len = len(x) - len(s)

        for i in range(pre_len):
            if limit < int(x[i]):
                count += (limit + 1) ** (pre_len - i)
                return count
            count += int(x[i]) * (limit + 1) ** (pre_len - 1 - i)

        if suffix >= s:
            count += 1

        return count
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function numberOfPowerfulInt(
    start: number,
    finish: number,
    limit: number,
    s: string,
): number {
    const start_ = (start - 1).toString();
    const finish_ = finish.toString();
    return calculate(finish_, s, limit) - calculate(start_, s, limit);
}

function calculate(x: string, s: string, limit: number): number {
    if (x.length < s.length) {
        return 0;
    }
    if (x.length === s.length) {
        return x >= s ? 1 : 0;
    }

    const suffix = x.slice(-s.length);
    let count = 0;
    const preLen = x.length - s.length;

    for (let i = 0; i < preLen; i++) {
        const digit = parseInt(x[i]);
        if (limit < digit) {
            count += Math.pow(limit + 1, preLen - i);
            return count;
        }
        count += digit * Math.pow(limit + 1, preLen - 1 - i);
    }
    if (suffix >= s) {
        count++;
    }
    return count;
}
```

</details>
