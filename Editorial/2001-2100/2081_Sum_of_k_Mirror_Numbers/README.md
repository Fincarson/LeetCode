# 2081. Sum of k-Mirror Numbers

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/sum-of-k-mirror-numbers/)  
`Math` `Enumeration`

**Problem Link:** [LeetCode 2081 - Sum of k-Mirror Numbers](https://leetcode.com/problems/sum-of-k-mirror-numbers/)

## Problem

A k-mirror number is a positive integer without leading zeros that reads the same both forward and backward in base-10 as well as in base-k.

- For example, 9 is a 2-mirror number. The representation of 9 in base-10 and base-2 are 9 and 1001 respectively, which read the same both forward and backward.
- On the contrary, 4 is not a 2-mirror number. The representation of 4 in base-2 is 100, which does not read the same both forward and backward.

Given the base k and the number n, return the sum of the n smallest k-mirror numbers.

### Example 1

```text
Input: k = 2, n = 5
Output: 25
Explanation:
The 5 smallest 2-mirror numbers and their representations in base-2 are listed as follows:
  base-10    base-2
    1          1
    3          11
    5          101
    7          111
    9          1001
Their sum = 1 + 3 + 5 + 7 + 9 = 25.
```

### Example 2

```text
Input: k = 3, n = 7
Output: 499
Explanation:
The 7 smallest 3-mirror numbers are and their representations in base-3 are listed as follows:
  base-10    base-3
    1          1
    2          2
    4          11
    8          22
    121        11111
    151        12121
    212        21212
Their sum = 1 + 2 + 4 + 8 + 121 + 151 + 212 = 499.
```

### Example 3

```text
Input: k = 7, n = 17
Output: 20379000
Explanation: The 17 smallest 7-mirror numbers are:
1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312, 4602064, 6597956, 6958596
```

## Constraints

- 2 <= k <= 9
- 1 <= n <= 30

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Strobogrammatic Number II](https://leetcode.com/problems/strobogrammatic-number-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Prime Palindrome](https://leetcode.com/problems/prime-palindrome/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2081. Sum of k-Mirror Numbers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Enumeration With Optimization | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Preprocessing | C, C++, C#, Java, JavaScript, Python3, TypeScript |

## Approach 1: Enumeration With Optimization

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isPalindrome(int64_t x, int k, int *digit) {
    int length = -1;
    while (x > 0) {
        ++length;
        digit[length] = x % k;
        x /= k;
    }
    for (int i = 0, j = length; i < j; ++i, --j) {
        if (digit[i] != digit[j]) {
            return false;
        }
    }
    return true;
}

long long kMirror(int k, int n) {
    int left = 1, count = 0;
    long long ans = 0;
    int digit[100];
    while (count < n) {
        int right = left * 10;
        // op = 0 indicates enumerating odd-length palindromes
        // op = 1 indicates enumerating even-length palindromes
        for (int op = 0; op < 2; ++op) {
            // enumerate i'
            for (int i = left; i < right && count < n; ++i) {
                int64_t combined = i;
                int x = (op == 0 ? i / 10 : i);
                while (x > 0) {
                    combined = combined * 10 + x % 10;
                    x /= 10;
                }
                if (isPalindrome(combined, k, digit)) {
                    ++count;
                    ans += combined;
                }
            }
        }
        left = right;
    }
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int digit[100];

public:
    long long kMirror(int k, int n) {
        auto isPalindrome = [&](long long x) -> bool {
            int length = -1;
            while (x) {
                ++length;
                digit[length] = x % k;
                x /= k;
            }
            for (int i = 0, j = length; i < j; ++i, --j) {
                if (digit[i] != digit[j]) {
                    return false;
                }
            }
            return true;
        };

        int left = 1, count = 0;
        long long ans = 0;
        while (count < n) {
            int right = left * 10;
            // op = 0 indicates enumerating odd-length palindromes
            // op = 1 indicates enumerating even-length palindromes
            for (int op = 0; op < 2; ++op) {
                // enumerate i'
                for (int i = left; i < right && count < n; ++i) {
                    long long combined = i;
                    int x = (op == 0 ? i / 10 : i);
                    while (x) {
                        combined = combined * 10 + x % 10;
                        x /= 10;
                    }
                    if (isPalindrome(combined)) {
                        ++count;
                        ans += combined;
                    }
                }
            }
            left = right;
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
    private int[] digit = new int[100];

    public long KMirror(int k, int n) {
        int left = 1, count = 0;
        long ans = 0;
        while (count < n) {
            int right = left * 10;
            // op = 0 indicates enumerating odd-length palindromes
            // op = 1 indicates enumerating even-length palindromes
            for (int op = 0; op < 2; ++op) {
                // enumerate i'
                for (int i = left; i < right && count < n; ++i) {
                    long combined = i;
                    int x = (op == 0 ? i / 10 : i);
                    while (x > 0) {
                        combined = combined * 10 + x % 10;
                        x /= 10;
                    }
                    if (IsPalindrome(combined, k)) {
                        ++count;
                        ans += combined;
                    }
                }
            }
            left = right;
        }
        return ans;
    }

    private bool IsPalindrome(long x, int k) {
        int length = -1;
        while (x > 0) {
            ++length;
            digit[length] = (int)(x % k);
            x /= k;
        }
        for (int i = 0, j = length; i < j; ++i, --j) {
            if (digit[i] != digit[j]) {
                return false;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func kMirror(k int, n int) int64 {
	digit := make([]int, 100)
	left, count, ans := 1, 0, int64(0)
	for count < n {
		right := left * 10
		// op = 0 indicates enumerating odd-length palindromes,
		// op = 1 indicates enumerating even-length palindromes
		for op := 0; op < 2; op++ {
			// enumerate i'
			for i := left; i < right && count < n; i++ {
				combined := int64(i)
				x := i
				if op == 0 {
					x = i / 10
				}
				for x > 0 {
					combined = combined*10 + int64(x%10)
					x /= 10
				}
				if isPalindrome(combined, k, digit) {
					count++
					ans += combined
				}
			}
		}
		left = right
	}
	return ans
}

func isPalindrome(x int64, k int, digit []int) bool {
	length := -1
	for x > 0 {
		length++
		digit[length] = int(x % int64(k))
		x /= int64(k)
	}
	for i, j := 0, length; i < j; i, j = i+1, j-1 {
		if digit[i] != digit[j] {
			return false
		}
	}
	return true
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int[] digit = new int[100];

    public long kMirror(int k, int n) {
        int left = 1,
            count = 0;
        long ans = 0;
        while (count < n) {
            int right = left * 10;
            // op = 0 indicates enumerating odd-length palindromes
            // op = 1 indicates enumerating even-length palindromes
            for (int op = 0; op < 2; ++op) {
                // enumerate i'
                for (int i = left; i < right && count < n; ++i) {
                    long combined = i;
                    int x = (op == 0 ? i / 10 : i);
                    while (x > 0) {
                        combined = combined * 10 + (x % 10);
                        x /= 10;
                    }
                    if (isPalindrome(combined, k)) {
                        ++count;
                        ans += combined;
                    }
                }
            }
            left = right;
        }
        return ans;
    }

    private boolean isPalindrome(long x, int k) {
        int length = -1;
        while (x > 0) {
            ++length;
            digit[length] = (int) (x % k);
            x /= k;
        }
        for (int i = 0, j = length; i < j; ++i, --j) {
            if (digit[i] != digit[j]) {
                return false;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var kMirror = function (k, n) {
    const digit = new Array(100);
    let left = 1,
        count = 0,
        ans = 0n;
    while (count < n) {
        const right = left * 10;
        // op = 0 indicates enumerating odd-length palindromes
        // op = 1 indicates enumerating even-length palindromes
        for (let op = 0; op < 2; ++op) {
            // enumerate i'
            for (let i = left; i < right && count < n; ++i) {
                let combined = BigInt(i);
                let x = op === 0 ? Math.floor(i / 10) : i;
                while (x > 0) {
                    combined = combined * 10n + BigInt(x % 10);
                    x = Math.floor(x / 10);
                }
                if (isPalindrome(combined, k, digit)) {
                    ++count;
                    ans += combined;
                }
            }
        }
        left = right;
    }
    return Number(ans);
};

function isPalindrome(x, k, digit) {
    let length = -1;
    while (x > 0n) {
        ++length;
        digit[length] = Number(x % BigInt(k));
        x /= BigInt(k);
    }
    for (let i = 0, j = length; i < j; ++i, --j) {
        if (digit[i] !== digit[j]) {
            return false;
        }
    }
    return true;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def kMirror(self, k: int, n: int) -> int:
        def isPalindrome(x: int) -> bool:
            digit = list()
            while x:
                digit.append(x % k)
                x //= k
            return digit == digit[::-1]

        left, cnt, ans = 1, 0, 0
        while cnt < n:
            right = left * 10
            # op = 0 indicates enumerating odd-length palindromes
            # op = 1 indicates enumerating even-length palindromes
            for op in [0, 1]:
                # enumerate i'
                for i in range(left, right):
                    if cnt == n:
                        break

                    combined = i
                    x = i // 10 if op == 0 else i
                    while x:
                        combined = combined * 10 + x % 10
                        x //= 10
                    if isPalindrome(combined):
                        cnt += 1
                        ans += combined
            left = right

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function kMirror(k: number, n: number): number {
    const digit: number[] = new Array(100);
    let left = 1,
        count = 0,
        ans = 0n;
    while (count < n) {
        const right = left * 10;
        // op = 0 indicates enumerating odd-length palindromes
        // op = 1 indicates enumerating even-length palindromes
        for (let op = 0; op < 2; ++op) {
            // enumerate i'
            for (let i = left; i < right && count < n; ++i) {
                let combined = BigInt(i);
                let x = op === 0 ? Math.floor(i / 10) : i;
                while (x > 0) {
                    combined = combined * 10n + BigInt(x % 10);
                    x = Math.floor(x / 10);
                }
                if (isPalindrome(combined, k, digit)) {
                    ++count;
                    ans += combined;
                }
            }
        }
        left = right;
    }
    return Number(ans);
}

function isPalindrome(x: bigint, k: number, digit: number[]): boolean {
    let length = -1;
    while (x > 0n) {
        ++length;
        digit[length] = Number(x % BigInt(k));
        x /= BigInt(k);
    }
    for (let i = 0, j = length; i < j; ++i, --j) {
        if (digit[i] !== digit[j]) {
            return false;
        }
    }
    return true;
}
```

</details>

<br>

## Approach 2: Preprocessing

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
long long kMirror(int k, int n) {
    long long ans[8][30] = {
        {1,       3,       5,        7,         9,         33,
         99,      313,     585,      717,       7447,      9009,
         15351,   32223,   39993,    53235,     53835,     73737,
         585585,  1758571, 1934391,  1979791,   3129213,   5071705,
         5259525, 5841485, 13500531, 719848917, 910373019, 939474939},
        {1,       2,       4,       8,       121,      151,
         212,     242,     484,     656,     757,      29092,
         48884,   74647,   75457,   76267,   92929,    93739,
         848848,  1521251, 2985892, 4022204, 4219124,  4251524,
         4287824, 5737375, 7875787, 7949497, 27711772, 83155138},
        {1,       2,       3,        5,         55,        373,
         393,     666,     787,      939,       7997,      53235,
         55255,   55655,   57675,    506605,    1801081,   2215122,
         3826283, 3866683, 5051505,  5226225,   5259525,   5297925,
         5614165, 5679765, 53822835, 623010326, 954656459, 51717171715},
        {1,          2,          3,          4,           6,
         88,         252,        282,        626,         676,
         1221,       15751,      18881,      10088001,    10400401,
         27711772,   30322303,   47633674,   65977956,    808656808,
         831333138,  831868138,  836131638,  836181638,   2512882152,
         2596886952, 2893553982, 6761551676, 12114741121, 12185058121},
        {1,       2,       3,       4,       5,       7,      55,     111,
         141,     191,     343,     434,     777,     868,    1441,   7667,
         7777,    22022,   39893,   74647,   168861,  808808, 909909, 1867681,
         3097903, 4232324, 4265624, 4298924, 4516154, 4565654},
        {1,           2,           3,           4,           5,
         6,           8,           121,         171,         242,
         292,         16561,       65656,       2137312,     4602064,
         6597956,     6958596,     9470749,     61255216,    230474032,
         466828664,   485494584,   638828836,   657494756,   858474858,
         25699499652, 40130703104, 45862226854, 61454945416, 64454545446},
        {1,      2,       3,       4,       5,       6,       7,      9,
         121,    292,     333,     373,     414,     585,     3663,   8778,
         13131,  13331,   26462,   26662,   30103,   30303,   207702, 628826,
         660066, 1496941, 1935391, 1970791, 4198914, 55366355},
        {1,       2,       3,       4,       5,       6,       7,       8,
         191,     282,     373,     464,     555,     646,     656,     6886,
         25752,   27472,   42324,   50605,   626626,  1540451, 1713171, 1721271,
         1828281, 1877781, 1885881, 2401042, 2434342, 2442442}};

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ans[k - 2][i];
    }
    return sum;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    static constexpr long long ans[][30] = {
        {1,       3,       5,        7,         9,         33,
         99,      313,     585,      717,       7447,      9009,
         15351,   32223,   39993,    53235,     53835,     73737,
         585585,  1758571, 1934391,  1979791,   3129213,   5071705,
         5259525, 5841485, 13500531, 719848917, 910373019, 939474939},
        {1,       2,       4,       8,       121,      151,
         212,     242,     484,     656,     757,      29092,
         48884,   74647,   75457,   76267,   92929,    93739,
         848848,  1521251, 2985892, 4022204, 4219124,  4251524,
         4287824, 5737375, 7875787, 7949497, 27711772, 83155138},
        {1,       2,       3,        5,         55,        373,
         393,     666,     787,      939,       7997,      53235,
         55255,   55655,   57675,    506605,    1801081,   2215122,
         3826283, 3866683, 5051505,  5226225,   5259525,   5297925,
         5614165, 5679765, 53822835, 623010326, 954656459, 51717171715},
        {1,          2,          3,          4,           6,
         88,         252,        282,        626,         676,
         1221,       15751,      18881,      10088001,    10400401,
         27711772,   30322303,   47633674,   65977956,    808656808,
         831333138,  831868138,  836131638,  836181638,   2512882152,
         2596886952, 2893553982, 6761551676, 12114741121, 12185058121},
        {1,       2,       3,       4,       5,       7,      55,     111,
         141,     191,     343,     434,     777,     868,    1441,   7667,
         7777,    22022,   39893,   74647,   168861,  808808, 909909, 1867681,
         3097903, 4232324, 4265624, 4298924, 4516154, 4565654},
        {1,           2,           3,           4,           5,
         6,           8,           121,         171,         242,
         292,         16561,       65656,       2137312,     4602064,
         6597956,     6958596,     9470749,     61255216,    230474032,
         466828664,   485494584,   638828836,   657494756,   858474858,
         25699499652, 40130703104, 45862226854, 61454945416, 64454545446},
        {1,      2,       3,       4,       5,       6,       7,      9,
         121,    292,     333,     373,     414,     585,     3663,   8778,
         13131,  13331,   26462,   26662,   30103,   30303,   207702, 628826,
         660066, 1496941, 1935391, 1970791, 4198914, 55366355},
        {1,       2,       3,       4,       5,       6,       7,       8,
         191,     282,     373,     464,     555,     646,     656,     6886,
         25752,   27472,   42324,   50605,   626626,  1540451, 1713171, 1721271,
         1828281, 1877781, 1885881, 2401042, 2434342, 2442442}};

public:
    long long kMirror(int k, int n) {
        return accumulate(ans[k - 2], ans[k - 2] + n, 0LL);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public long KMirror(int k, int n) {
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ans[k - 2][i];
        }
        return sum;
    }

    private static readonly long[][] ans = {
        new long[] { 1,       3,        5,         7,         9,
                     33,      99,       313,       585,       717,
                     7447,    9009,     15351,     32223,     39993,
                     53235,   53835,    73737,     585585,    1758571,
                     1934391, 1979791,  3129213,   5071705,   5259525,
                     5841485, 13500531, 719848917, 910373019, 939474939 },
        new long[] { 1,       2,       4,       8,       121,      151,
                     212,     242,     484,     656,     757,      29092,
                     48884,   74647,   75457,   76267,   92929,    93739,
                     848848,  1521251, 2985892, 4022204, 4219124,  4251524,
                     4287824, 5737375, 7875787, 7949497, 27711772, 83155138 },
        new long[] { 1,       2,        3,         5,         55,
                     373,     393,      666,       787,       939,
                     7997,    53235,    55255,     55655,     57675,
                     506605,  1801081,  2215122,   3826283,   3866683,
                     5051505, 5226225,  5259525,   5297925,   5614165,
                     5679765, 53822835, 623010326, 954656459, 51717171715 },
        new long[] { 1,           2,          3,          4,
                     6,           88,         252,        282,
                     626,         676,        1221,       15751,
                     18881,       10088001,   10400401,   27711772,
                     30322303,    47633674,   65977956,   808656808,
                     831333138,   831868138,  836131638,  836181638,
                     2512882152,  2596886952, 2893553982, 6761551676,
                     12114741121, 12185058121 },
        new long[] { 1,       2,       3,       4,       5,       7,
                     55,      111,     141,     191,     343,     434,
                     777,     868,     1441,    7667,    7777,    22022,
                     39893,   74647,   168861,  808808,  909909,  1867681,
                     3097903, 4232324, 4265624, 4298924, 4516154, 4565654 },
        new long[] { 1,           2,           3,           4,
                     5,           6,           8,           121,
                     171,         242,         292,         16561,
                     65656,       2137312,     4602064,     6597956,
                     6958596,     9470749,     61255216,    230474032,
                     466828664,   485494584,   638828836,   657494756,
                     858474858,   25699499652, 40130703104, 45862226854,
                     61454945416, 64454545446 },
        new long[] { 1,      2,       3,       4,       5,       6,
                     7,      9,       121,     292,     333,     373,
                     414,    585,     3663,    8778,    13131,   13331,
                     26462,  26662,   30103,   30303,   207702,  628826,
                     660066, 1496941, 1935391, 1970791, 4198914, 55366355 },
        new long[] { 1,       2,       3,       4,       5,       6,
                     7,       8,       191,     282,     373,     464,
                     555,     646,     656,     6886,    25752,   27472,
                     42324,   50605,   626626,  1540451, 1713171, 1721271,
                     1828281, 1877781, 1885881, 2401042, 2434342, 2442442 }
    };
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long kMirror(int k, int n) {
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ans[k - 2][i];
        }
        return sum;
    }

    private static final long[][] ans = {
        {
            1L,
            3L,
            5L,
            7L,
            9L,
            33L,
            99L,
            313L,
            585L,
            717L,
            7447L,
            9009L,
            15351L,
            32223L,
            39993L,
            53235L,
            53835L,
            73737L,
            585585L,
            1758571L,
            1934391L,
            1979791L,
            3129213L,
            5071705L,
            5259525L,
            5841485L,
            13500531L,
            719848917L,
            910373019L,
            939474939L,
        },
        {
            1L,
            2L,
            4L,
            8L,
            121L,
            151L,
            212L,
            242L,
            484L,
            656L,
            757L,
            29092L,
            48884L,
            74647L,
            75457L,
            76267L,
            92929L,
            93739L,
            848848L,
            1521251L,
            2985892L,
            4022204L,
            4219124L,
            4251524L,
            4287824L,
            5737375L,
            7875787L,
            7949497L,
            27711772L,
            83155138L,
        },
        {
            1L,
            2L,
            3L,
            5L,
            55L,
            373L,
            393L,
            666L,
            787L,
            939L,
            7997L,
            53235L,
            55255L,
            55655L,
            57675L,
            506605L,
            1801081L,
            2215122L,
            3826283L,
            3866683L,
            5051505L,
            5226225L,
            5259525L,
            5297925L,
            5614165L,
            5679765L,
            53822835L,
            623010326L,
            954656459L,
            51717171715L,
        },
        {
            1L,
            2L,
            3L,
            4L,
            6L,
            88L,
            252L,
            282L,
            626L,
            676L,
            1221L,
            15751L,
            18881L,
            10088001L,
            10400401L,
            27711772L,
            30322303L,
            47633674L,
            65977956L,
            808656808L,
            831333138L,
            831868138L,
            836131638L,
            836181638L,
            2512882152L,
            2596886952L,
            2893553982L,
            6761551676L,
            12114741121L,
            12185058121L,
        },
        {
            1L,
            2L,
            3L,
            4L,
            5L,
            7L,
            55L,
            111L,
            141L,
            191L,
            343L,
            434L,
            777L,
            868L,
            1441L,
            7667L,
            7777L,
            22022L,
            39893L,
            74647L,
            168861L,
            808808L,
            909909L,
            1867681L,
            3097903L,
            4232324L,
            4265624L,
            4298924L,
            4516154L,
            4565654L,
        },
        {
            1L,
            2L,
            3L,
            4L,
            5L,
            6L,
            8L,
            121L,
            171L,
            242L,
            292L,
            16561L,
            65656L,
            2137312L,
            4602064L,
            6597956L,
            6958596L,
            9470749L,
            61255216L,
            230474032L,
            466828664L,
            485494584L,
            638828836L,
            657494756L,
            858474858L,
            25699499652L,
            40130703104L,
            45862226854L,
            61454945416L,
            64454545446L,
        },
        {
            1L,
            2L,
            3L,
            4L,
            5L,
            6L,
            7L,
            9L,
            121L,
            292L,
            333L,
            373L,
            414L,
            585L,
            3663L,
            8778L,
            13131L,
            13331L,
            26462L,
            26662L,
            30103L,
            30303L,
            207702L,
            628826L,
            660066L,
            1496941L,
            1935391L,
            1970791L,
            4198914L,
            55366355L,
        },
        {
            1L,
            2L,
            3L,
            4L,
            5L,
            6L,
            7L,
            8L,
            191L,
            282L,
            373L,
            464L,
            555L,
            646L,
            656L,
            6886L,
            25752L,
            27472L,
            42324L,
            50605L,
            626626L,
            1540451L,
            1713171L,
            1721271L,
            1828281L,
            1877781L,
            1885881L,
            2401042L,
            2434342L,
            2442442L,
        },
    };
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var kMirror = function (k, n) {
    const ans = [
        [
            1, 3, 5, 7, 9, 33, 99, 313, 585, 717, 7447, 9009, 15351, 32223,
            39993, 53235, 53835, 73737, 585585, 1758571, 1934391, 1979791,
            3129213, 5071705, 5259525, 5841485, 13500531, 719848917, 910373019,
            939474939,
        ],
        [
            1, 2, 4, 8, 121, 151, 212, 242, 484, 656, 757, 29092, 48884, 74647,
            75457, 76267, 92929, 93739, 848848, 1521251, 2985892, 4022204,
            4219124, 4251524, 4287824, 5737375, 7875787, 7949497, 27711772,
            83155138,
        ],
        [
            1, 2, 3, 5, 55, 373, 393, 666, 787, 939, 7997, 53235, 55255, 55655,
            57675, 506605, 1801081, 2215122, 3826283, 3866683, 5051505, 5226225,
            5259525, 5297925, 5614165, 5679765, 53822835, 623010326, 954656459,
            51717171715,
        ],
        [
            1, 2, 3, 4, 6, 88, 252, 282, 626, 676, 1221, 15751, 18881, 10088001,
            10400401, 27711772, 30322303, 47633674, 65977956, 808656808,
            831333138, 831868138, 836131638, 836181638, 2512882152, 2596886952,
            2893553982, 6761551676, 12114741121, 12185058121,
        ],
        [
            1, 2, 3, 4, 5, 7, 55, 111, 141, 191, 343, 434, 777, 868, 1441, 7667,
            7777, 22022, 39893, 74647, 168861, 808808, 909909, 1867681, 3097903,
            4232324, 4265624, 4298924, 4516154, 4565654,
        ],
        [
            1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312,
            4602064, 6597956, 6958596, 9470749, 61255216, 230474032, 466828664,
            485494584, 638828836, 657494756, 858474858, 25699499652,
            40130703104, 45862226854, 61454945416, 64454545446,
        ],
        [
            1, 2, 3, 4, 5, 6, 7, 9, 121, 292, 333, 373, 414, 585, 3663, 8778,
            13131, 13331, 26462, 26662, 30103, 30303, 207702, 628826, 660066,
            1496941, 1935391, 1970791, 4198914, 55366355,
        ],
        [
            1, 2, 3, 4, 5, 6, 7, 8, 191, 282, 373, 464, 555, 646, 656, 6886,
            25752, 27472, 42324, 50605, 626626, 1540451, 1713171, 1721271,
            1828281, 1877781, 1885881, 2401042, 2434342, 2442442,
        ],
    ];

    let sum = 0n;
    for (let i = 0; i < n; i++) {
        sum += BigInt(ans[k - 2][i]);
    }
    return Number(sum);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    ANS = [
        [
            1,
            3,
            5,
            7,
            9,
            33,
            99,
            313,
            585,
            717,
            7447,
            9009,
            15351,
            32223,
            39993,
            53235,
            53835,
            73737,
            585585,
            1758571,
            1934391,
            1979791,
            3129213,
            5071705,
            5259525,
            5841485,
            13500531,
            719848917,
            910373019,
            939474939,
        ],
        [
            1,
            2,
            4,
            8,
            121,
            151,
            212,
            242,
            484,
            656,
            757,
            29092,
            48884,
            74647,
            75457,
            76267,
            92929,
            93739,
            848848,
            1521251,
            2985892,
            4022204,
            4219124,
            4251524,
            4287824,
            5737375,
            7875787,
            7949497,
            27711772,
            83155138,
        ],
        [
            1,
            2,
            3,
            5,
            55,
            373,
            393,
            666,
            787,
            939,
            7997,
            53235,
            55255,
            55655,
            57675,
            506605,
            1801081,
            2215122,
            3826283,
            3866683,
            5051505,
            5226225,
            5259525,
            5297925,
            5614165,
            5679765,
            53822835,
            623010326,
            954656459,
            51717171715,
        ],
        [
            1,
            2,
            3,
            4,
            6,
            88,
            252,
            282,
            626,
            676,
            1221,
            15751,
            18881,
            10088001,
            10400401,
            27711772,
            30322303,
            47633674,
            65977956,
            808656808,
            831333138,
            831868138,
            836131638,
            836181638,
            2512882152,
            2596886952,
            2893553982,
            6761551676,
            12114741121,
            12185058121,
        ],
        [
            1,
            2,
            3,
            4,
            5,
            7,
            55,
            111,
            141,
            191,
            343,
            434,
            777,
            868,
            1441,
            7667,
            7777,
            22022,
            39893,
            74647,
            168861,
            808808,
            909909,
            1867681,
            3097903,
            4232324,
            4265624,
            4298924,
            4516154,
            4565654,
        ],
        [
            1,
            2,
            3,
            4,
            5,
            6,
            8,
            121,
            171,
            242,
            292,
            16561,
            65656,
            2137312,
            4602064,
            6597956,
            6958596,
            9470749,
            61255216,
            230474032,
            466828664,
            485494584,
            638828836,
            657494756,
            858474858,
            25699499652,
            40130703104,
            45862226854,
            61454945416,
            64454545446,
        ],
        [
            1,
            2,
            3,
            4,
            5,
            6,
            7,
            9,
            121,
            292,
            333,
            373,
            414,
            585,
            3663,
            8778,
            13131,
            13331,
            26462,
            26662,
            30103,
            30303,
            207702,
            628826,
            660066,
            1496941,
            1935391,
            1970791,
            4198914,
            55366355,
        ],
        [
            1,
            2,
            3,
            4,
            5,
            6,
            7,
            8,
            191,
            282,
            373,
            464,
            555,
            646,
            656,
            6886,
            25752,
            27472,
            42324,
            50605,
            626626,
            1540451,
            1713171,
            1721271,
            1828281,
            1877781,
            1885881,
            2401042,
            2434342,
            2442442,
        ],
    ]

    def kMirror(self, k: int, n: int) -> int:
        return sum(Solution.ANS[k - 2][:n])
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function kMirror(k: number, n: number): number {
    const ans = [
        [
            1, 3, 5, 7, 9, 33, 99, 313, 585, 717, 7447, 9009, 15351, 32223,
            39993, 53235, 53835, 73737, 585585, 1758571, 1934391, 1979791,
            3129213, 5071705, 5259525, 5841485, 13500531, 719848917, 910373019,
            939474939,
        ],
        [
            1, 2, 4, 8, 121, 151, 212, 242, 484, 656, 757, 29092, 48884, 74647,
            75457, 76267, 92929, 93739, 848848, 1521251, 2985892, 4022204,
            4219124, 4251524, 4287824, 5737375, 7875787, 7949497, 27711772,
            83155138,
        ],
        [
            1, 2, 3, 5, 55, 373, 393, 666, 787, 939, 7997, 53235, 55255, 55655,
            57675, 506605, 1801081, 2215122, 3826283, 3866683, 5051505, 5226225,
            5259525, 5297925, 5614165, 5679765, 53822835, 623010326, 954656459,
            51717171715,
        ],
        [
            1, 2, 3, 4, 6, 88, 252, 282, 626, 676, 1221, 15751, 18881, 10088001,
            10400401, 27711772, 30322303, 47633674, 65977956, 808656808,
            831333138, 831868138, 836131638, 836181638, 2512882152, 2596886952,
            2893553982, 6761551676, 12114741121, 12185058121,
        ],
        [
            1, 2, 3, 4, 5, 7, 55, 111, 141, 191, 343, 434, 777, 868, 1441, 7667,
            7777, 22022, 39893, 74647, 168861, 808808, 909909, 1867681, 3097903,
            4232324, 4265624, 4298924, 4516154, 4565654,
        ],
        [
            1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312,
            4602064, 6597956, 6958596, 9470749, 61255216, 230474032, 466828664,
            485494584, 638828836, 657494756, 858474858, 25699499652,
            40130703104, 45862226854, 61454945416, 64454545446,
        ],
        [
            1, 2, 3, 4, 5, 6, 7, 9, 121, 292, 333, 373, 414, 585, 3663, 8778,
            13131, 13331, 26462, 26662, 30103, 30303, 207702, 628826, 660066,
            1496941, 1935391, 1970791, 4198914, 55366355,
        ],
        [
            1, 2, 3, 4, 5, 6, 7, 8, 191, 282, 373, 464, 555, 646, 656, 6886,
            25752, 27472, 42324, 50605, 626626, 1540451, 1713171, 1721271,
            1828281, 1877781, 1885881, 2401042, 2434342, 2442442,
        ],
    ];

    let sum = 0n;
    for (let i = 0; i < n; i++) {
        sum += BigInt(ans[k - 2][i]);
    }
    return Number(sum);
}
```

</details>
