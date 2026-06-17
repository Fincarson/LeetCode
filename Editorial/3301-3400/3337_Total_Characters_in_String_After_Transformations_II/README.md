# 3337. Total Characters in String After Transformations II

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/)  
`Hash Table` `Math` `String` `Dynamic Programming` `Counting`

**Problem Link:** [LeetCode 3337 - Total Characters in String After Transformations II](https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/)

## Problem

You are given a string s consisting of lowercase English letters, an integer t representing the number of transformations to perform, and an array nums of size 26. In one transformation, every character in s is replaced according to the following rules:

- Replace s[i] with the next nums[s[i] - 'a'] consecutive characters in the alphabet. For example, if s[i] = 'a' and nums[0] = 3, the character 'a' transforms into the next 3 consecutive characters ahead of it, which results in "bcd".
- The transformation wraps around the alphabet if it exceeds 'z'. For example, if s[i] = 'y' and nums[24] = 3, the character 'y' transforms into the next 3 consecutive characters ahead of it, which results in "zab".

Return the length of the resulting string after exactly t transformations.

Since the answer may be very large, return it modulo 109 + 7.

### Example 1

### Example 2

## Constraints

- 1 <= s.length <= 105
- s consists only of lowercase English letters.
- 1 <= t <= 109
- nums.length == 26
- 1 <= nums[i] <= 25

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3337. Total Characters in String After Transformations II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Matrix Multiplication + Matrix Exponentiation By Squaring | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Matrix Multiplication + Matrix Exponentiation By Squaring

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MOD 1000000007
#define L 26

typedef struct {
    int a[L][L];
} Mat;

/* identity matrix */
Mat I() {
    Mat m;
    memset(&m, 0, sizeof(m));
    for (int i = 0; i < L; i++) {
        m.a[i][i] = 1;
    }
    return m;
}

Mat mul(Mat x, Mat y) {
    Mat res;
    memset(&res, 0, sizeof(res));
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            for (int k = 0; k < L; k++) {
                res.a[i][j] =
                    (res.a[i][j] + (long long)x.a[i][k] * y.a[k][j]) % MOD;
            }
        }
    }
    return res;
}

/* matrix exponentiation by squaring */
Mat quickmul(Mat x, int y) {
    Mat ans = I();
    Mat cur = x;
    while (y > 0) {
        if (y & 1) {
            ans = mul(ans, cur);
        }
        cur = mul(cur, cur);
        y >>= 1;
    }
    return ans;
}

int lengthAfterTransformations(char* s, int t, int* nums, int numsSize) {
    Mat T;
    memset(&T, 0, sizeof(T));
    for (int i = 0; i < L; i++) {
        for (int j = 1; j <= nums[i]; j++) {
            T.a[(i + j) % L][i] = 1;
        }
    }

    Mat res = quickmul(T, t);

    int f[L] = {0};
    for (char* p = s; *p; p++) {
        f[*p - 'a']++;
    }

    int ans = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            ans = (ans + (long long)res.a[i][j] * f[j]) % MOD;
        }
    }
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
static constexpr int L = 26;
static constexpr int mod = 1000000007;

struct Mat {
    Mat() { memset(a, 0, sizeof(a)); }
    Mat(const Mat& that) {
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < L; ++j) {
                a[i][j] = that.a[i][j];
            }
        }
    }
    Mat& operator=(const Mat& that) {
        if (this != &that) {
            for (int i = 0; i < L; ++i) {
                for (int j = 0; j < L; ++j) {
                    a[i][j] = that.a[i][j];
                }
            }
        }
        return *this;
    }

    int a[L][L];
};

Mat operator*(const Mat& u, const Mat& v) {
    Mat w;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < L; ++j) {
            for (int k = 0; k < L; ++k) {
                w.a[i][j] =
                    (w.a[i][j] + (long long)u.a[i][k] * v.a[k][j]) % mod;
            }
        }
    }
    return w;
}

// identity matrix
Mat I() {
    Mat w;
    for (int i = 0; i < L; ++i) {
        w.a[i][i] = 1;
    }
    return w;
}

// matrix exponentiation by squaring
Mat quickmul(const Mat& x, int y) {
    Mat ans = I(), cur = x;
    while (y) {
        if (y & 1) {
            ans = ans * cur;
        }
        cur = cur * cur;
        y >>= 1;
    }
    return ans;
}

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        Mat T;
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                T.a[(i + j) % 26][i] = 1;
            }
        }
        Mat res = quickmul(T, t);
        int ans = 0;
        vector<int> f(26);
        for (char ch : s) {
            ++f[ch - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                ans = (ans + (long long)res.a[i][j] * f[j]) % mod;
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
    private const int MOD = (int)1e9 + 7;
    private const int L = 26;

    private class Mat {
        public int[,] a = new int[L, L];

        public Mat() {}

        public Mat(Mat copyFrom) {
            for (int i = 0; i < L; i++) {
                for (int j = 0; j < L; j++) {
                    this.a[i, j] = copyFrom.a[i, j];
                }
            }
        }

        public Mat Mul(Mat other) {
            Mat result = new Mat();
            for (int i = 0; i < L; i++) {
                for (int j = 0; j < L; j++) {
                    for (int k = 0; k < L; k++) {
                        result.a[i, j] =
                            (int)((result.a[i, j] +
                                   (long)this.a[i, k] * other.a[k, j]) %
                                  MOD);
                    }
                }
            }
            return result;
        }
    }
    /* identity matrix */
    private Mat I() {
        Mat m = new Mat();
        for (int i = 0; i < L; i++) {
            m.a[i, i] = 1;
        }
        return m;
    }
    /* matrix exponentiation by squaring */
    private Mat QuickMul(Mat x, int y) {
        Mat ans = I();
        Mat cur = new Mat(x);
        while (y > 0) {
            if ((y & 1) == 1) {
                ans = ans.Mul(cur);
            }
            cur = cur.Mul(cur);
            y >>= 1;
        }
        return ans;
    }

    public int LengthAfterTransformations(string s, int t, IList<int> nums) {
        Mat T = new Mat();
        for (int i = 0; i < L; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                T.a[(i + j) % L, i] = 1;
            }
        }

        Mat res = QuickMul(T, t);
        int[] f = new int[L];
        foreach (char ch in s) {
            f[ch - 'a']++;
        }

        int ans = 0;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) {
                ans = (int)((ans + (long)res.a[i, j] * f[j]) % MOD);
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
const MOD = 1e9 + 7
const L = 26

func lengthAfterTransformations(s string, t int, nums []int) int {
    T := NewMat()
    for i := 0; i < L; i++ {
        for j := 1; j <= nums[i]; j++ {
            T.a[(i + j) % L][i] = 1
        }
    }

    res := quickMul(T, t)
    f := make([]int, L)
    for _, ch := range s {
        f[ch - 'a']++
    }

    ans := 0
    for i := 0; i < L; i++ {
        for j := 0; j < L; j++ {
            ans = (ans + res.a[i][j] * f[j]) % MOD
        }
    }
    return ans
}

type Mat struct {
    a [L][L]int
}

func NewMat() *Mat {
    return &Mat{}
}

func NewMatCopy(from *Mat) *Mat {
    m := &Mat{}
    for i := 0; i < L; i++ {
        for j := 0; j < L; j++ {
            m.a[i][j] = from.a[i][j]
        }
    }
    return m
}

func (m *Mat) Mul(other *Mat) *Mat {
    result := NewMat()
    for i := 0; i < L; i++ {
        for j := 0; j < L; j++ {
            for k := 0; k < L; k++ {
                result.a[i][j] = (result.a[i][j] + m.a[i][k] * other.a[k][j]) % MOD
            }
        }
    }
    return result
}

/* identity matrix */
func I() *Mat {
    m := NewMat()
    for i := 0; i < L; i++ {
        m.a[i][i] = 1
    }
    return m
}

/* matrix exponentiation by squaring */
func quickMul(x *Mat, y int) *Mat {
    ans := I()
    cur := NewMatCopy(x)
    for y > 0 {
        if y&1 == 1 {
            ans = ans.Mul(cur)
        }
        cur = cur.Mul(cur)
        y >>= 1
    }
    return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final int MOD = (int) 1e9 + 7;
    private static final int L = 26;

    private static class Mat {

        int[][] a = new int[L][L];

        Mat() {}

        Mat(Mat copyFrom) {
            for (int i = 0; i < L; i++) {
                System.arraycopy(copyFrom.a[i], 0, this.a[i], 0, L);
            }
        }

        Mat mul(Mat other) {
            Mat result = new Mat();
            for (int i = 0; i < L; i++) {
                for (int j = 0; j < L; j++) {
                    for (int k = 0; k < L; k++) {
                        result.a[i][j] = (int) ((result.a[i][j] +
                                (long) this.a[i][k] * other.a[k][j]) %
                            MOD);
                    }
                }
            }
            return result;
        }
    }

    /* identity matrix */
    private Mat I() {
        Mat m = new Mat();
        for (int i = 0; i < L; i++) {
            m.a[i][i] = 1;
        }
        return m;
    }

    /* matrix exponentiation by squaring */
    private Mat quickmul(Mat x, int y) {
        Mat ans = I();
        Mat cur = new Mat(x);
        while (y > 0) {
            if ((y & 1) == 1) {
                ans = ans.mul(cur);
            }
            cur = cur.mul(cur);
            y >>= 1;
        }
        return ans;
    }

    public int lengthAfterTransformations(String s, int t, List<Integer> nums) {
        Mat T = new Mat();
        for (int i = 0; i < L; i++) {
            for (int j = 1; j <= nums.get(i); j++) {
                T.a[(i + j) % L][i] = 1;
            }
        }

        Mat res = quickmul(T, t);
        int[] f = new int[L];
        for (char ch : s.toCharArray()) {
            f[ch - 'a']++;
        }
        int ans = 0;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) {
                ans = (int) ((ans + (long) res.a[i][j] * f[j]) % MOD);
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
class Mat {
    constructor(copyFrom = null) {
        this.a = Array.from({ length: 26 }, () => new Array(26).fill(0n));
        if (copyFrom) {
            for (let i = 0; i < 26; i++) {
                for (let j = 0; j < 26; j++) {
                    this.a[i][j] = copyFrom.a[i][j];
                }
            }
        }
    }

    mul(other) {
        const MOD = BigInt(1e9 + 7);
        const result = new Mat();
        for (let i = 0; i < 26; i++) {
            for (let j = 0; j < 26; j++) {
                for (let k = 0; k < 26; k++) {
                    result.a[i][j] =
                        (result.a[i][j] + this.a[i][k] * other.a[k][j]) % MOD;
                }
            }
        }
        return result;
    }
}

/* identity matrix */
function I() {
    const m = new Mat();
    for (let i = 0; i < 26; i++) {
        m.a[i][i] = 1n;
    }
    return m;
}

/* matrix exponentiation by squaring */
function quickmul(x, y) {
    let ans = I();
    let cur = new Mat(x);
    while (y > 0n) {
        if (y & (1n != 0n)) {
            ans = ans.mul(cur);
        }
        cur = cur.mul(cur);
        y >>= 1;
    }
    return ans;
}

var lengthAfterTransformations = function (s, t, nums) {
    const MOD = BigInt(1e9 + 7);
    const T = new Mat();
    for (let i = 0; i < 26; i++) {
        for (let j = 1; j <= nums[i]; j++) {
            T.a[(i + j) % 26][i] = 1n;
        }
    }

    const res = quickmul(T, t);
    const f = new Array(26).fill(0n);
    for (const ch of s) {
        f[ch.charCodeAt(0) - "a".charCodeAt(0)]++;
    }

    let ans = 0n;
    for (let i = 0; i < 26; i++) {
        for (let j = 0; j < 26; j++) {
            ans = (ans + res.a[i][j] * f[j]) % MOD;
        }
    }
    return Number(ans);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
MOD = 10**9 + 7
L = 26


class Mat:
    def __init__(self, copy_from: "Mat" = None) -> None:
        self.a: List[List[int]] = [[0] * L for _ in range(L)]
        if copy_from:
            for i in range(L):
                for j in range(L):
                    self.a[i][j] = copy_from.a[i][j]

    def __mul__(self, other: "Mat") -> "Mat":
        result = Mat()
        for i in range(L):
            for j in range(L):
                for k in range(L):
                    result.a[i][j] = (
                        result.a[i][j] + self.a[i][k] * other.a[k][j]
                    ) % MOD
        return result


# identity matrix
def I() -> Mat:
    m = Mat()
    for i in range(L):
        m.a[i][i] = 1
    return m


# matrix exponentiation by squaring
def quickmul(x: Mat, y: int) -> Mat:
    ans = I()
    cur = x
    while y:
        if y & 1:
            ans = ans * cur
        cur = cur * cur
        y >>= 1
    return ans


class Solution:
    def lengthAfterTransformations(
        self, s: str, t: int, nums: List[int]
    ) -> int:
        T = Mat()
        for i in range(26):
            for j in range(1, nums[i] + 1):
                T.a[(i + j) % 26][i] = 1

        res = quickmul(T, t)

        f = [0] * 26
        for ch in s:
            f[ord(ch) - ord("a")] += 1

        ans = 0
        for i in range(26):
            for j in range(26):
                ans = (ans + res.a[i][j] * f[j]) % MOD

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const MOD = BigInt(1e9 + 7);
const L = 26;

class Mat {
    a: bigint[][];

    constructor(copyFrom: Mat | null = null) {
        this.a = Array.from({ length: L }, () => new Array(L).fill(0n));
        if (copyFrom) {
            for (let i = 0; i < L; i++) {
                for (let j = 0; j < L; j++) {
                    this.a[i][j] = copyFrom.a[i][j];
                }
            }
        }
    }

    mul(other: Mat): Mat {
        const result = new Mat();
        for (let i = 0; i < L; i++) {
            for (let j = 0; j < L; j++) {
                for (let k = 0; k < L; k++) {
                    result.a[i][j] =
                        (result.a[i][j] + this.a[i][k] * other.a[k][j]) % MOD;
                }
            }
        }
        return result;
    }
}

/* identity matrix */
function I(): Mat {
    const m = new Mat();
    for (let i = 0; i < L; i++) {
        m.a[i][i] = 1n;
    }
    return m;
}

/* matrix exponentiation by squaring */
function quickMul(x: Mat, y: number): Mat {
    let ans = I();
    let cur = new Mat(x);
    while (y > 0) {
        if (y & 1) {
            ans = ans.mul(cur);
        }
        cur = cur.mul(cur);
        y >>= 1;
    }
    return ans;
}

function lengthAfterTransformations(
    s: string,
    t: number,
    nums: number[],
): number {
    const T = new Mat();
    for (let i = 0; i < L; i++) {
        for (let j = 1; j <= nums[i]; j++) {
            T.a[(i + j) % L][i] = 1n;
        }
    }

    const res = quickMul(T, t);
    const f = new Array(L).fill(0n);
    for (const ch of s) {
        f[ch.charCodeAt(0) - "a".charCodeAt(0)] += 1n;
    }

    let ans = 0n;
    for (let i = 0; i < L; i++) {
        for (let j = 0; j < L; j++) {
            ans = (ans + res.a[i][j] * f[j]) % MOD;
        }
    }
    return Number(ans);
}
```

</details>
