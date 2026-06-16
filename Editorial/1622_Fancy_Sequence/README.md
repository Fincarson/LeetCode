# 1622. Fancy Sequence

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/fancy-sequence/)  
`Math` `Design` `Segment Tree` `Number Theory`

**Problem Link:** [LeetCode 1622 - Fancy Sequence](https://leetcode.com/problems/fancy-sequence/)

## Problem

Write an API that generates fancy sequences using the append, addAll, and multAll operations.

Implement the Fancy class:

- Fancy() Initializes the object with an empty sequence.
- void append(val) Appends an integer val to the end of the sequence.
- void addAll(inc) Increments all existing values in the sequence by an integer inc.
- void multAll(m) Multiplies all existing values in the sequence by an integer m.
- int getIndex(idx) Gets the current value at index idx (0-indexed) of the sequence modulo 109 + 7. If the index is greater or equal than the length of the sequence, return -1.

### Example 1

```text
Input
["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
[[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
Output
[null, null, null, null, null, 10, null, null, null, 26, 34, 20]

Explanation
Fancy fancy = new Fancy();
fancy.append(2);   // fancy sequence: [2]
fancy.addAll(3);   // fancy sequence: [2+3] -> [5]
fancy.append(7);   // fancy sequence: [5, 7]
fancy.multAll(2);  // fancy sequence: [5*2, 7*2] -> [10, 14]
fancy.getIndex(0); // return 10
fancy.addAll(3);   // fancy sequence: [10+3, 14+3] -> [13, 17]
fancy.append(10);  // fancy sequence: [13, 17, 10]
fancy.multAll(2);  // fancy sequence: [13*2, 17*2, 10*2] -> [26, 34, 20]
fancy.getIndex(0); // return 26
fancy.getIndex(1); // return 34
fancy.getIndex(2); // return 20
```

## Constraints

- 1 <= val, inc, m <= 100
- 0 <= idx <= 105
- At most 105 calls total will be made to append, addAll, multAll, and getIndex.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1622. Fancy Sequence

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Use modular inverse for the `getIndex` operation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Use multiplicative inverse during the `append` operation | C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Use modular inverse for the `getIndex` operation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MOD 1000000007

typedef struct {
    int* data;
    int size;
    int capacity;
} Vector;

Vector* vectorCreate() {
    Vector* vec = (Vector*)malloc(sizeof(Vector));
    vec->size = 0;
    vec->capacity = 16;
    vec->data = (int*)malloc(vec->capacity * sizeof(int));
    return vec;
}

void vectorPushBack(Vector* vec, int val) {
    if (vec->size >= vec->capacity) {
        vec->capacity *= 2;
        vec->data = (int*)realloc(vec->data, vec->capacity * sizeof(int));
    }
    vec->data[vec->size++] = val;
}

int vectorBack(Vector* vec) {
    if (vec->size == 0) return 0;
    return vec->data[vec->size - 1];
}

void vectorSetBack(Vector* vec, int val) {
    if (vec->size == 0) {
        vectorPushBack(vec, val);
    } else {
        vec->data[vec->size - 1] = val;
    }
}

int vectorAt(Vector* vec, int idx) {
    if (idx < 0 || idx >= vec->size) {
        return 0;
    }
    return vec->data[idx];
}

int vectorSize(Vector* vec) { return vec->size; }

void vectorFree(Vector* vec) {
    free(vec->data);
    free(vec);
}

typedef struct {
    Vector* v;
    Vector* a;
    Vector* b;
} Fancy;

// 创建 Fancy 对象
Fancy* fancyCreate() {
    Fancy* obj = (Fancy*)malloc(sizeof(Fancy));
    obj->v = vectorCreate();
    obj->a = vectorCreate();
    obj->b = vectorCreate();
    // 初始化 a[0] = 1, b[0] = 0
    vectorPushBack(obj->a, 1);
    vectorPushBack(obj->b, 0);

    return obj;
}

// fast exponentiation
int quickMul(int x, int y) {
    long long ret = 1;
    long long cur = x;
    while (y) {
        if (y & 1) {
            ret = ret * cur % MOD;
        }
        cur = cur * cur % MOD;
        y >>= 1;
    }
    return (int)ret;
}

// multiplicative inverse
int inv(int x) { return quickMul(x, MOD - 2); }

// 添加值
void fancyAppend(Fancy* obj, int val) {
    if (!obj || !obj->v || !obj->a || !obj->b) {
        return;
    }
    vectorPushBack(obj->v, val);
    vectorPushBack(obj->a, vectorBack(obj->a));
    vectorPushBack(obj->b, vectorBack(obj->b));
}

// 增加所有值
void fancyAddAll(Fancy* obj, int inc) {
    if (!obj || !obj->b) {
        return;
    }
    if (vectorSize(obj->b) > 0) {
        int last = (vectorBack(obj->b) + inc) % MOD;
        vectorSetBack(obj->b, last);
    }
}

// 乘以所有值
void fancyMultAll(Fancy* obj, int m) {
    if (!obj || !obj->a || !obj->b) {
        return;
    }
    if (vectorSize(obj->a) > 0 && vectorSize(obj->b) > 0) {
        int a_last = (int)((long long)vectorBack(obj->a) * m % MOD);
        int b_last = (int)((long long)vectorBack(obj->b) * m % MOD);
        vectorSetBack(obj->a, a_last);
        vectorSetBack(obj->b, b_last);
    }
}

// 获取索引处的值
int fancyGetIndex(Fancy* obj, int idx) {
    if (!obj || !obj->v || !obj->a || !obj->b) {
        return -1;
    }
    if (idx >= vectorSize(obj->v)) {
        return -1;
    }

    long long ao =
        (long long)inv(vectorAt(obj->a, idx)) * vectorBack(obj->a) % MOD;
    long long bo = (vectorBack(obj->b) -
                    (long long)vectorAt(obj->b, idx) * ao % MOD + MOD) %
                   MOD;
    long long ans = (ao * vectorAt(obj->v, idx) % MOD + bo) % MOD;

    return (int)ans;
}

// 释放 Fancy 对象
void fancyFree(Fancy* obj) {
    if (!obj) {
        return;
    }
    if (obj->v) {
        vectorFree(obj->v);
    }
    if (obj->a) {
        vectorFree(obj->a);
    }
    if (obj->b) {
        vectorFree(obj->b);
    }
    free(obj);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Fancy {
private:
    static constexpr int mod = 1000000007;
    vector<int> v, a, b;

public:
    Fancy() {
        a.push_back(1);
        b.push_back(0);
    }

    // fast exponentiation
    int quickmul(int x, int y) {
        int ret = 1;
        int cur = x;
        while (y) {
            if (y & 1) {
                ret = (long long)ret * cur % mod;
            }
            cur = (long long)cur * cur % mod;
            y >>= 1;
        }
        return ret;
    }

    // multiplicative inverse
    int inv(int x) { return quickmul(x, mod - 2); }

    void append(int val) {
        v.push_back(val);
        a.push_back(a.back());
        b.push_back(b.back());
    }

    void addAll(int inc) { b.back() = (b.back() + inc) % mod; }

    void multAll(int m) {
        a.back() = (long long)a.back() * m % mod;
        b.back() = (long long)b.back() * m % mod;
    }

    int getIndex(int idx) {
        if (idx >= v.size()) {
            return -1;
        }
        int ao = (long long)inv(a[idx]) * a.back() % mod;
        int bo = (b.back() - (long long)b[idx] * ao % mod + mod) % mod;
        int ans = ((long long)ao * v[idx] % mod + bo) % mod;
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Fancy {
    const int MOD = 1000000007;
    List<int> v;
    List<int> a;
    List<int> b;

    public Fancy() {
        v = new List<int>();
        a = new List<int>();
        b = new List<int>();
        a.Add(1);
        b.Add(0);
    }

    public void Append(int val) {
        v.Add(val);
        a.Add(a[a.Count - 1]);
        b.Add(b[b.Count - 1]);
    }

    public void AddAll(int inc) {
        int lastIndex = b.Count - 1;
        int lastB = (b[lastIndex] + inc) % MOD;
        b[lastIndex] = lastB;
    }

    public void MultAll(int m) {
        int lastIndex = a.Count - 1;
        long lastA = ((long)a[lastIndex] * m) % MOD;
        a[lastIndex] = (int)lastA;

        long lastB = ((long)b[lastIndex] * m) % MOD;
        b[lastIndex] = (int)lastB;
    }

    public int GetIndex(int idx) {
        if (idx >= v.Count) {
            return -1;
        }

        long ao = ((long)Inv(a[idx]) * a[a.Count - 1]) % MOD;
        long bo = (b[b.Count - 1] - (long)b[idx] * ao % MOD + MOD) % MOD;
        long ans = (ao * v[idx] % MOD + bo) % MOD;
        return (int)ans;
    }

    // fast exponentiation
    private int QuickMul(int x, int y) {
        long ret = 1;
        long cur = x;
        while (y != 0) {
            if ((y & 1) != 0) {
                ret = ret * cur % MOD;
            }
            cur = cur * cur % MOD;
            y >>= 1;
        }
        return (int)ret;
    }

    // multiplicative inverse
    private int Inv(int x) {
        return QuickMul(x, MOD - 2);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
const MOD = 1000000007

type Fancy struct {
	v []int
	a []int
	b []int
}

func Constructor() Fancy {
	return Fancy{
		v: []int{},
		a: []int{1},
		b: []int{0},
	}
}

func (this *Fancy) Append(val int) {
	this.v = append(this.v, val)
	this.a = append(this.a, this.a[len(this.a)-1])
	this.b = append(this.b, this.b[len(this.b)-1])
}

func (this *Fancy) AddAll(inc int) {
	lastIdx := len(this.b) - 1
	this.b[lastIdx] = (this.b[lastIdx] + inc) % MOD
}

func (this *Fancy) MultAll(m int) {
	lastIdx := len(this.a) - 1
	this.a[lastIdx] = (this.a[lastIdx] * m) % MOD
	this.b[lastIdx] = (this.b[lastIdx] * m) % MOD
}

func (this *Fancy) GetIndex(idx int) int {
	if idx >= len(this.v) {
		return -1
	}

	ao := (inv(this.a[idx]) * this.a[len(this.a)-1]) % MOD
	bo := (this.b[len(this.b)-1] - this.b[idx]*ao%MOD + MOD) % MOD
	ans := (ao*this.v[idx]%MOD + bo) % MOD
	return ans
}

// fast exponentiation
func quickMul(x, y int) int {
	ret := 1
	cur := x
	for y != 0 {
		if y&1 != 0 {
			ret = (ret * cur) % MOD
		}
		cur = (cur * cur) % MOD
		y >>= 1
	}
	return ret
}

// multiplicative inverse
func inv(x int) int {
	return quickMul(x, MOD-2)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Fancy {

    static final int MOD = 1000000007;
    List<Integer> v;
    List<Integer> a;
    List<Integer> b;

    public Fancy() {
        v = new ArrayList<Integer>();
        a = new ArrayList<Integer>();
        b = new ArrayList<Integer>();
        a.add(1);
        b.add(0);
    }

    public void append(int val) {
        v.add(val);
        a.add(a.get(a.size() - 1));
        b.add(b.get(b.size() - 1));
    }

    public void addAll(int inc) {
        int bLastIndex = b.size() - 1;
        int bLast = b.get(bLastIndex);
        bLast = (bLast + inc) % MOD;
        b.set(bLastIndex, bLast);
    }

    public void multAll(int m) {
        int aLastIndex = a.size() - 1, bLastIndex = b.size() - 1;
        int aLast = (int) (((long) a.get(aLastIndex) * m) % MOD);
        a.set(aLastIndex, aLast);
        int bLast = (int) (((long) b.get(bLastIndex) * m) % MOD);
        b.set(bLastIndex, bLast);
    }

    public int getIndex(int idx) {
        if (idx >= v.size()) {
            return -1;
        }
        int ao = (int) (((long) inv(a.get(idx)) * a.get(a.size() - 1)) % MOD);
        int bo = (int) (((long) b.get(b.size() - 1) -
                ((long) b.get(idx) * ao) % MOD +
                MOD) %
            MOD);
        int ans = (int) (((((long) ao * v.get(idx)) % MOD) + bo) % MOD);
        return ans;
    }

    // fast exponentiation
    private int quickmul(int x, int y) {
        long ret = 1;
        long cur = x;
        while (y != 0) {
            if ((y & 1) != 0) {
                ret = (ret * cur) % MOD;
            }
            cur = (cur * cur) % MOD;
            y >>= 1;
        }
        return (int) ret;
    }

    // multiplicative inverse
    private int inv(int x) {
        return quickmul(x, MOD - 2);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const MOD = 1000000007n;

var Fancy = function () {
    this.v = [];
    this.a = [1n];
    this.b = [0n];
};

Fancy.prototype.append = function (val) {
    this.v.push(BigInt(val));
    this.a.push(this.a[this.a.length - 1]);
    this.b.push(this.b[this.b.length - 1]);
};

Fancy.prototype.addAll = function (inc) {
    const lastIdx = this.b.length - 1;
    this.b[lastIdx] = (this.b[lastIdx] + BigInt(inc)) % MOD;
};

Fancy.prototype.multAll = function (m) {
    const lastIdx = this.a.length - 1;
    const mBigInt = BigInt(m);
    this.a[lastIdx] = (this.a[lastIdx] * mBigInt) % MOD;
    this.b[lastIdx] = (this.b[lastIdx] * mBigInt) % MOD;
};

// fast exponentiation（返回bigint）
Fancy.prototype.quickMul = function (x, y) {
    let ret = 1n;
    let cur = BigInt(x);
    let power = BigInt(y);
    while (power !== 0n) {
        if ((power & 1n) !== 0n) {
            ret = (ret * cur) % MOD;
        }
        cur = (cur * cur) % MOD;
        power >>= 1n;
    }
    return ret;
};

// multiplicative inverse（返回bigint）
Fancy.prototype.inv = function (x) {
    return this.quickMul(x, MOD - 2n);
};

Fancy.prototype.getIndex = function (idx) {
    if (idx >= this.v.length) {
        return -1;
    }

    const ao =
        (this.inv(Number(this.a[idx])) * this.a[this.a.length - 1]) % MOD;
    const bo =
        (this.b[this.b.length - 1] - ((this.b[idx] * ao) % MOD) + MOD) % MOD;
    const ans = (((ao * this.v[idx]) % MOD) + bo) % MOD;

    return Number(ans);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Fancy:

    def __init__(self):
        self.mod = 10**9 + 7
        self.v = list()
        self.a = [1]
        self.b = [0]

    # fast exponentiation
    def quickmul(self, x: int, y: int) -> int:
        return pow(x, y, self.mod)

    # multiplicative inverse
    def inv(self, x: int) -> int:
        return self.quickmul(x, self.mod - 2)

    def append(self, val: int) -> None:
        self.v.append(val)
        self.a.append(self.a[-1])
        self.b.append(self.b[-1])

    def addAll(self, inc: int) -> None:
        self.b[-1] = (self.b[-1] + inc) % self.mod

    def multAll(self, m: int) -> None:
        self.a[-1] = self.a[-1] * m % self.mod
        self.b[-1] = self.b[-1] * m % self.mod

    def getIndex(self, idx: int) -> int:
        if idx >= len(self.v):
            return -1
        ao = self.inv(self.a[idx]) * self.a[-1]
        bo = self.b[-1] - self.b[idx] * ao
        ans = (ao * self.v[idx] + bo) % self.mod
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const MOD = 1000000007n;

class Fancy {
    private v: bigint[];
    private a: bigint[];
    private b: bigint[];

    constructor() {
        this.v = [];
        this.a = [1n];
        this.b = [0n];
    }

    // 添加值
    append(val: number): void {
        this.v.push(BigInt(val));
        this.a.push(this.a[this.a.length - 1]);
        this.b.push(this.b[this.b.length - 1]);
    }

    // 增加所有值
    addAll(inc: number): void {
        const lastIdx = this.b.length - 1;
        this.b[lastIdx] = (this.b[lastIdx] + BigInt(inc)) % MOD;
    }

    // 乘以所有值
    multAll(m: number): void {
        const lastIdx = this.a.length - 1;
        const mBigInt = BigInt(m);
        this.a[lastIdx] = (this.a[lastIdx] * mBigInt) % MOD;
        this.b[lastIdx] = (this.b[lastIdx] * mBigInt) % MOD;
    }

    // fast exponentiation（使用bigint）
    private quickMul(x: bigint, y: bigint): bigint {
        let ret = 1n;
        let cur = x;
        let power = y;

        while (power !== 0n) {
            if ((power & 1n) !== 0n) {
                ret = (ret * cur) % MOD;
            }
            cur = (cur * cur) % MOD;
            power >>= 1n;
        }
        return ret;
    }

    // multiplicative inverse（使用费马小定理）
    private inv(x: bigint): bigint {
        return this.quickMul(x, MOD - 2n);
    }

    // 获取索引处的值
    getIndex(idx: number): number {
        if (idx >= this.v.length) {
            return -1;
        }

        const ao = (this.inv(this.a[idx]) * this.a[this.a.length - 1]) % MOD;
        const bo =
            (this.b[this.b.length - 1] - ((this.b[idx] * ao) % MOD) + MOD) %
            MOD;
        const ans = (((ao * this.v[idx]) % MOD) + bo) % MOD;
        return Number(ans);
    }
}
```

</details>

<br>

## Approach 2: Use multiplicative inverse during the `append` operation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Fancy {
private:
    static constexpr int mod = 1000000007;
    vector<int> v;
    int a, b;

public:
    Fancy() : a(1), b(0) {}

    // fast exponentiation
    int quickmul(int x, int y) {
        int ret = 1;
        int cur = x;
        while (y) {
            if (y & 1) {
                ret = (long long)ret * cur % mod;
            }
            cur = (long long)cur * cur % mod;
            y >>= 1;
        }
        return ret;
    }

    // multiplicative inverse
    int inv(int x) { return quickmul(x, mod - 2); }

    void append(int val) {
        v.push_back((long long)((val - b + mod) % mod) * inv(a) % mod);
    }

    void addAll(int inc) { b = (b + inc) % mod; }

    void multAll(int m) {
        a = (long long)a * m % mod;
        b = (long long)b * m % mod;
    }

    int getIndex(int idx) {
        if (idx >= v.size()) {
            return -1;
        }
        int ans = ((long long)a * v[idx] % mod + b) % mod;
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Fancy {
    private const int MOD = 1000000007;
    private List<int> v;
    private int a;
    private int b;

    public Fancy() {
        v = new List<int>();
        a = 1;
        b = 0;
    }

    // fast exponentiation
    private int QuickMul(int x, int y) {
        long ret = 1;
        long cur = x;
        while (y != 0) {
            if ((y & 1) != 0) {
                ret = ret * cur % MOD;
            }
            cur = cur * cur % MOD;
            y >>= 1;
        }
        return (int)ret;
    }

    // multiplicative inverse
    private int Inv(int x) {
        return QuickMul(x, MOD - 2);
    }

    public void Append(int val) {
        long adjustedVal = ((long)(val - b + MOD) % MOD) * Inv(a) % MOD;
        v.Add((int)adjustedVal);
    }

    public void AddAll(int inc) {
        b = (b + inc) % MOD;
    }

    public void MultAll(int m) {
        a = (int)((long)a * m % MOD);
        b = (int)((long)b * m % MOD);
    }

    public int GetIndex(int idx) {
        if (idx >= v.Count) {
            return -1;
        }
        int ans = (int)(((long)a * v[idx] % MOD + b) % MOD);
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
const MOD = 1000000007

type Fancy struct {
	v []int
	a int
	b int
}

func Constructor() Fancy {
	return Fancy{
		v: []int{},
		a: 1,
		b: 0,
	}
}

// fast exponentiation
func (this *Fancy) quickMul(x, y int) int {
	ret := 1
	cur := x
	for y > 0 {
		if y&1 != 0 {
			ret = (ret * cur) % MOD
		}
		cur = (cur * cur) % MOD
		y >>= 1
	}
	return ret
}

// multiplicative inverse
func (this *Fancy) inv(x int) int {
	return this.quickMul(x, MOD-2)
}

func (this *Fancy) Append(val int) {
	adjustedVal := ((val - this.b + MOD) % MOD) * this.inv(this.a) % MOD
	this.v = append(this.v, adjustedVal)
}

func (this *Fancy) AddAll(inc int) {
	this.b = (this.b + inc) % MOD
}

func (this *Fancy) MultAll(m int) {
	this.a = (this.a * m) % MOD
	this.b = (this.b * m) % MOD
}

func (this *Fancy) GetIndex(idx int) int {
	if idx >= len(this.v) {
		return -1
	}
	ans := (this.a*this.v[idx]%MOD + this.b) % MOD
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Fancy {

    static final int MOD = 1000000007;
    List<Integer> v;
    int a;
    int b;

    public Fancy() {
        v = new ArrayList<Integer>();
        a = 1;
        b = 0;
    }

    public void append(int val) {
        v.add((int) (((long) ((val - b + MOD) % MOD) * inv(a)) % MOD));
    }

    public void addAll(int inc) {
        b = (b + inc) % MOD;
    }

    public void multAll(int m) {
        a = (int) ((((long) a * m) % MOD));
        b = (int) ((((long) b * m) % MOD));
    }

    public int getIndex(int idx) {
        if (idx >= v.size()) {
            return -1;
        }
        int ans = (int) (((((long) a * v.get(idx)) % MOD) + b) % MOD);
        return ans;
    }

    // fast exponentiation
    private int quickmul(int x, int y) {
        long ret = 1;
        long cur = x;
        while (y != 0) {
            if ((y & 1) != 0) {
                ret = (ret * cur) % MOD;
            }
            cur = (cur * cur) % MOD;
            y >>= 1;
        }
        return (int) ret;
    }

    // multiplicative inverse
    private int inv(int x) {
        return quickmul(x, MOD - 2);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const MOD = 1000000007n;

var Fancy = function () {
    this.v = [];
    this.a = 1n;
    this.b = 0n;
};

// fast exponentiation
Fancy.prototype.quickMul = function (x, y) {
    let ret = 1n;
    let cur = BigInt(x);
    let power = BigInt(y);
    while (power !== 0n) {
        if ((power & 1n) !== 0n) {
            ret = (ret * cur) % MOD;
        }
        cur = (cur * cur) % MOD;
        power >>= 1n;
    }
    return Number(ret);
};

// multiplicative inverse
Fancy.prototype.inv = function (x) {
    return this.quickMul(x, MOD - 2n);
};

Fancy.prototype.append = function (val) {
    const adjustedVal =
        (((BigInt(val) - this.b + MOD) % MOD) *
            BigInt(this.inv(Number(this.a)))) %
        MOD;
    this.v.push(Number(adjustedVal));
};

Fancy.prototype.addAll = function (inc) {
    this.b = (this.b + BigInt(inc)) % MOD;
};

Fancy.prototype.multAll = function (m) {
    this.a = (this.a * BigInt(m)) % MOD;
    this.b = (this.b * BigInt(m)) % MOD;
};

Fancy.prototype.getIndex = function (idx) {
    if (idx >= this.v.length) {
        return -1;
    }
    const ans = (((this.a * BigInt(this.v[idx])) % MOD) + this.b) % MOD;
    return Number(ans);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Fancy:

    def __init__(self):
        self.mod = 10**9 + 7
        self.v = list()
        self.a = 1
        self.b = 0

    # fast exponentiation
    def quickmul(self, x: int, y: int) -> int:
        return pow(x, y, self.mod)

    # multiplicative inverse
    def inv(self, x: int) -> int:
        return self.quickmul(x, self.mod - 2)

    def append(self, val: int) -> None:
        self.v.append((val - self.b) * self.inv(self.a) % self.mod)

    def addAll(self, inc: int) -> None:
        self.b = (self.b + inc) % self.mod

    def multAll(self, m: int) -> None:
        self.a = self.a * m % self.mod
        self.b = self.b * m % self.mod

    def getIndex(self, idx: int) -> int:
        if idx >= len(self.v):
            return -1
        return (self.a * self.v[idx] + self.b) % self.mod
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const MOD = 1000000007n;

class Fancy {
    private v: number[];
    private a: bigint;
    private b: bigint;

    constructor() {
        this.v = [];
        this.a = 1n;
        this.b = 0n;
    }

    // fast exponentiation
    private quickMul(x: number, y: bigint): number {
        let ret = 1n;
        let cur = BigInt(x);
        let power = y;
        while (power !== 0n) {
            if ((power & 1n) !== 0n) {
                ret = (ret * cur) % MOD;
            }
            cur = (cur * cur) % MOD;
            power >>= 1n;
        }
        return Number(ret);
    }

    // multiplicative inverse
    private inv(x: number): number {
        return this.quickMul(x, MOD - 2n);
    }

    append(val: number): void {
        const adjustedVal =
            (((BigInt(val) - this.b + MOD) % MOD) *
                BigInt(this.inv(Number(this.a)))) %
            MOD;
        this.v.push(Number(adjustedVal));
    }

    addAll(inc: number): void {
        this.b = (this.b + BigInt(inc)) % MOD;
    }

    multAll(m: number): void {
        this.a = (this.a * BigInt(m)) % MOD;
        this.b = (this.b * BigInt(m)) % MOD;
    }

    getIndex(idx: number): number {
        if (idx >= this.v.length) {
            return -1;
        }
        const ans = (((this.a * BigInt(this.v[idx])) % MOD) + this.b) % MOD;
        return Number(ans);
    }
}
```

</details>
