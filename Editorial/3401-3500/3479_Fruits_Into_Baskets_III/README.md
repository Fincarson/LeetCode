# 3479. Fruits Into Baskets III

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/fruits-into-baskets-iii/)  
`Array` `Binary Search` `Segment Tree` `Ordered Set`

**Problem Link:** [LeetCode 3479 - Fruits Into Baskets III](https://leetcode.com/problems/fruits-into-baskets-iii/)

## Problem

You are given two arrays of integers, fruits and baskets, each of length n, where fruits[i] represents the quantity of the ith type of fruit, and baskets[j] represents the capacity of the jth basket.

From left to right, place the fruits according to these rules:

- Each fruit type must be placed in the leftmost available basket with a capacity greater than or equal to the quantity of that fruit type.
- Each basket can hold only one type of fruit.
- If a fruit type cannot be placed in any basket, it remains unplaced.

Return the number of fruit types that remain unplaced after all possible allocations are made.

### Example 1

### Example 2

## Constraints

- n == fruits.length == baskets.length
- 1 <= n <= 105
- 1 <= fruits[i], baskets[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Block Placement Queries](https://leetcode.com/problems/block-placement-queries/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3479. Fruits Into Baskets III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Square Root Decomposition | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Segment Tree + Binary Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Square Root Decomposition

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int numOfUnplacedFruits(int* fruits, int fruitsSize, int* baskets,
                        int basketsSize) {
    int n = basketsSize;
    int m = (int)sqrt(n);
    int section = (n + m - 1) / m;
    int count = 0;
    int* maxV = (int*)calloc(section, sizeof(int));

    for (int i = 0; i < n; i++) {
        int block = i / m;
        maxV[block] = maxV[block] > baskets[i] ? maxV[block] : baskets[i];
    }

    for (int j = 0; j < fruitsSize; j++) {
        int fruit = fruits[j];
        int unset = 1;
        for (int sec = 0; sec < section; sec++) {
            if (maxV[sec] < fruit) {
                continue;
            }
            int choose = 0;
            maxV[sec] = 0;
            for (int i = 0; i < m; i++) {
                int pos = sec * m + i;
                if (pos < n && baskets[pos] >= fruit && !choose) {
                    baskets[pos] = 0;
                    choose = 1;
                }
                if (pos < n) {
                    maxV[sec] =
                        maxV[sec] > baskets[pos] ? maxV[sec] : baskets[pos];
                }
            }
            unset = 0;
            break;
        }
        count += unset;
    }

    free(maxV);
    return count;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int m = sqrt(n);
        int section = (n + m - 1) / m;
        int count = 0;
        vector<int> maxV(section);
        for (int i = 0; i < n; i++) {
            maxV[i / m] = max(maxV[i / m], baskets[i]);
        }
        for (int fruit : fruits) {
            int sec;
            int unset = 1;
            for (sec = 0; sec < section; sec++) {
                if (maxV[sec] < fruit) {
                    continue;
                }
                int choose = 0;
                maxV[sec] = 0;
                for (int i = 0; i < m; i++) {
                    int pos = sec * m + i;
                    if (pos < n && baskets[pos] >= fruit && !choose) {
                        baskets[pos] = 0;
                        choose = 1;
                    }
                    if (pos < n) {
                        maxV[sec] = max(maxV[sec], baskets[pos]);
                    }
                }
                unset = 0;
                break;
            }
            count += unset;
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
    public int NumOfUnplacedFruits(int[] fruits, int[] baskets) {
        int n = baskets.Length;
        int m = (int)Math.Sqrt(n);
        int section = (n + m - 1) / m;
        int count = 0;
        int[] maxV = new int[section];
        Array.Fill(maxV, 0);

        for (int i = 0; i < n; i++) {
            maxV[i / m] = Math.Max(maxV[i / m], baskets[i]);
        }

        foreach (int fruit in fruits) {
            int unset = 1;
            for (int sec = 0; sec < section; sec++) {
                if (maxV[sec] < fruit) {
                    continue;
                }
                int choose = 0;
                maxV[sec] = 0;
                for (int i = 0; i < m; i++) {
                    int pos = sec * m + i;
                    if (pos < n && baskets[pos] >= fruit && choose == 0) {
                        baskets[pos] = 0;
                        choose = 1;
                    }
                    if (pos < n) {
                        maxV[sec] = Math.Max(maxV[sec], baskets[pos]);
                    }
                }
                unset = 0;
                break;
            }
            count += unset;
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func numOfUnplacedFruits(fruits []int, baskets []int) int {
	n := len(baskets)
	m := int(math.Sqrt(float64(n)))
	section := (n + m - 1) / m
	count := 0
	maxV := make([]int, section)

	for i := 0; i < n; i++ {
		sec := i / m
		maxV[sec] = max(maxV[sec], baskets[i])
	}

	for _, fruit := range fruits {
		unset := 1
		for sec := 0; sec < section; sec++ {
			if maxV[sec] < fruit {
				continue
			}
			choose := 0
			maxV[sec] = 0
			for i := 0; i < m; i++ {
				pos := sec*m + i
				if pos < n && baskets[pos] >= fruit && choose == 0 {
					baskets[pos] = 0
					choose = 1
				}
				if pos < n {
					maxV[sec] = max(maxV[sec], baskets[pos])
				}
			}
			unset = 0
			break
		}
		count += unset
	}
	return count
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        int n = baskets.length;
        int m = (int) Math.sqrt(n);
        int section = (n + m - 1) / m;
        int count = 0;
        int[] maxV = new int[section];
        Arrays.fill(maxV, 0);

        for (int i = 0; i < n; i++) {
            maxV[i / m] = Math.max(maxV[i / m], baskets[i]);
        }

        for (int fruit : fruits) {
            int sec;
            int unset = 1;
            for (sec = 0; sec < section; sec++) {
                if (maxV[sec] < fruit) {
                    continue;
                }
                int choose = 0;
                maxV[sec] = 0;
                for (int i = 0; i < m; i++) {
                    int pos = sec * m + i;
                    if (pos < n && baskets[pos] >= fruit && choose == 0) {
                        baskets[pos] = 0;
                        choose = 1;
                    }
                    if (pos < n) {
                        maxV[sec] = Math.max(maxV[sec], baskets[pos]);
                    }
                }
                unset = 0;
                break;
            }
            count += unset;
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numOfUnplacedFruits = function (fruits, baskets) {
    const n = baskets.length;
    const m = Math.floor(Math.sqrt(n));
    const section = Math.ceil(n / m);
    let count = 0;
    const maxV = new Array(section).fill(0);

    for (let i = 0; i < n; i++) {
        const sec = Math.floor(i / m);
        maxV[sec] = Math.max(maxV[sec], baskets[i]);
    }

    for (const fruit of fruits) {
        let unset = 1;
        for (let sec = 0; sec < section; sec++) {
            if (maxV[sec] < fruit) {
                continue;
            }
            let choose = 0;
            maxV[sec] = 0;
            for (let i = 0; i < m; i++) {
                const pos = sec * m + i;
                if (pos < n && baskets[pos] >= fruit && !choose) {
                    baskets[pos] = 0;
                    choose = 1;
                }
                if (pos < n) {
                    maxV[sec] = Math.max(maxV[sec], baskets[pos]);
                }
            }
            unset = 0;
            break;
        }
        count += unset;
    }
    return count;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        n = len(baskets)
        m = int(math.sqrt(n))
        section = (n + m - 1) // m
        count = 0
        maxV = [0] * section

        for i in range(n):
            maxV[i // m] = max(maxV[i // m], baskets[i])

        for fruit in fruits:
            unset = 1
            for sec in range(section):
                if maxV[sec] < fruit:
                    continue
                choose = 0
                maxV[sec] = 0
                for i in range(m):
                    pos = sec * m + i
                    if pos < n and baskets[pos] >= fruit and not choose:
                        baskets[pos] = 0
                        choose = 1
                    if pos < n:
                        maxV[sec] = max(maxV[sec], baskets[pos])
                unset = 0
                break
            count += unset
        return count
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function numOfUnplacedFruits(fruits: number[], baskets: number[]): number {
    const n = baskets.length;
    const m = Math.floor(Math.sqrt(n));
    const section = Math.ceil(n / m);
    let count = 0;
    const maxV: number[] = new Array(section).fill(0);

    for (let i = 0; i < n; i++) {
        const sec = Math.floor(i / m);
        maxV[sec] = Math.max(maxV[sec], baskets[i]);
    }

    for (const fruit of fruits) {
        let unset = 1;
        for (let sec = 0; sec < section; sec++) {
            if (maxV[sec] < fruit) {
                continue;
            }
            let choose = 0;
            maxV[sec] = 0;
            for (let i = 0; i < m; i++) {
                const pos = sec * m + i;
                if (pos < n && baskets[pos] >= fruit && !choose) {
                    baskets[pos] = 0;
                    choose = 1;
                }
                if (pos < n) {
                    maxV[sec] = Math.max(maxV[sec], baskets[pos]);
                }
            }
            unset = 0;
            break;
        }
        count += unset;
    }
    return count;
}
```

</details>

<br>

## Approach 2: Segment Tree + Binary Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MAX_SIZE 400007

int segTree[MAX_SIZE];
int* baskets;

int max(int a, int b) { return a > b ? a : b; }

void build(int p, int l, int r) {
    if (l == r) {
        segTree[p] = baskets[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    segTree[p] = max(segTree[p << 1], segTree[p << 1 | 1]);
}

int query(int p, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) {
        return INT_MIN;
    }
    if (ql <= l && r <= qr) {
        return segTree[p];
    }
    int mid = (l + r) >> 1;
    return max(query(p << 1, l, mid, ql, qr),
               query(p << 1 | 1, mid + 1, r, ql, qr));
}

void update(int p, int l, int r, int pos, int val) {
    if (l == r) {
        segTree[p] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) {
        update(p << 1, l, mid, pos, val);
    } else {
        update(p << 1 | 1, mid + 1, r, pos, val);
    }
    segTree[p] = max(segTree[p << 1], segTree[p << 1 | 1]);
}

int numOfUnplacedFruits(int* fruits, int fruitsSize, int* basketsArr,
                        int basketsSize) {
    baskets = basketsArr;
    int m = basketsSize;
    int count = 0;
    if (m == 0) {
        return fruitsSize;
    }
    for (int i = 0; i < MAX_SIZE; i++) {
        segTree[i] = INT_MIN;
    }
    build(1, 0, m - 1);
    for (int i = 0; i < fruitsSize; i++) {
        int l = 0, r = m - 1, res = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (query(1, 0, m - 1, 0, mid) >= fruits[i]) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (res != -1 && baskets[res] >= fruits[i]) {
            update(1, 0, m - 1, res, INT_MIN);
        } else {
            count++;
        }
    }
    return count;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int segTree[400007];
    vector<int> baskets;

    void build(int p, int l, int r) {
        if (l == r) {
            segTree[p] = baskets[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        segTree[p] = max(segTree[p << 1], segTree[p << 1 | 1]);
    }

    int query(int p, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) {
            return INT_MIN;
        }
        if (ql <= l && r <= qr) {
            return segTree[p];
        }
        int mid = (l + r) >> 1;
        return max(query(p << 1, l, mid, ql, qr),
                   query(p << 1 | 1, mid + 1, r, ql, qr));
    }

    void update(int p, int l, int r, int pos, int val) {
        if (l == r) {
            segTree[p] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            update(p << 1, l, mid, pos, val);
        } else {
            update(p << 1 | 1, mid + 1, r, pos, val);
        }
        segTree[p] = max(segTree[p << 1], segTree[p << 1 | 1]);
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        this->baskets = baskets;
        int m = baskets.size();
        int count = 0;
        if (m == 0) {
            return fruits.size();
        }
        build(1, 0, m - 1);
        for (int i = 0; i < m; i++) {
            int l = 0, r = m - 1, res = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (query(1, 0, m - 1, 0, mid) >= fruits[i]) {
                    res = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (res != -1 && baskets[res] >= fruits[i]) {
                update(1, 0, m - 1, res, INT_MIN);
            } else {
                count++;
            }
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
    private int[] segTree = new int[400007];
    private int[] baskets;

    private void Build(int p, int l, int r) {
        if (l == r) {
            segTree[p] = baskets[l];
            return;
        }
        int mid = (l + r) >> 1;
        Build(p << 1, l, mid);
        Build(p << 1 | 1, mid + 1, r);
        segTree[p] = Math.Max(segTree[p << 1], segTree[p << 1 | 1]);
    }

    private int Query(int p, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) {
            return int.MinValue;
        }
        if (ql <= l && r <= qr) {
            return segTree[p];
        }
        int mid = (l + r) >> 1;
        return Math.Max(Query(p << 1, l, mid, ql, qr),
                        Query(p << 1 | 1, mid + 1, r, ql, qr));
    }

    private void Update(int p, int l, int r, int pos, int val) {
        if (l == r) {
            segTree[p] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            Update(p << 1, l, mid, pos, val);
        } else {
            Update(p << 1 | 1, mid + 1, r, pos, val);
        }
        segTree[p] = Math.Max(segTree[p << 1], segTree[p << 1 | 1]);
    }

    public int NumOfUnplacedFruits(int[] fruits, int[] baskets) {
        this.baskets = baskets;
        int m = baskets.Length;
        int count = 0;
        if (m == 0) {
            return fruits.Length;
        }
        Array.Fill(segTree, int.MinValue);
        Build(1, 0, m - 1);
        for (int i = 0; i < fruits.Length; i++) {
            int l = 0, r = m - 1, res = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (Query(1, 0, m - 1, 0, mid) >= fruits[i]) {
                    res = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (res != -1 && baskets[res] >= fruits[i]) {
                Update(1, 0, m - 1, res, int.MinValue);
            } else {
                count++;
            }
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
const (
	INT_MIN = math.MinInt32
)

type SegTree struct {
	segNode []int
	baskets []int
}

func (this *SegTree) build(p, l, r int) {
	if l == r {
		this.segNode[p] = this.baskets[l]
		return
	}
	mid := (l + r) >> 1
	this.build(p<<1, l, mid)
	this.build(p<<1|1, mid+1, r)
	this.segNode[p] = max(this.segNode[p<<1], this.segNode[p<<1|1])
}

func (this *SegTree) query(p, l, r, ql, qr int) int {
	if ql > r || qr < l {
		return INT_MIN
	}
	if ql <= l && r <= qr {
		return this.segNode[p]
	}
	mid := (l + r) >> 1
	return max(this.query(p<<1, l, mid, ql, qr),
		this.query(p<<1|1, mid+1, r, ql, qr))
}

func (this *SegTree) update(p, l, r, pos, val int) {
	if l == r {
		this.segNode[p] = val
		return
	}
	mid := (l + r) >> 1
	if pos <= mid {
		this.update(p<<1, l, mid, pos, val)
	} else {
		this.update(p<<1|1, mid+1, r, pos, val)
	}
	this.segNode[p] = max(this.segNode[p<<1], this.segNode[p<<1|1])
}

func numOfUnplacedFruits(fruits []int, baskets []int) int {
	m := len(baskets)
	if m == 0 {
		return len(fruits)
	}

	tree := SegTree{
		segNode: make([]int, 4*m+7),
		baskets: baskets,
	}
	tree.build(1, 0, m-1)

	count := 0
	for i := 0; i < len(fruits); i++ {
		l, r, res := 0, m-1, -1
		for l <= r {
			mid := (l + r) >> 1
			if tree.query(1, 0, m-1, 0, mid) >= fruits[i] {
				res = mid
				r = mid - 1
			} else {
				l = mid + 1
			}
		}
		if res != -1 && tree.baskets[res] >= fruits[i] {
			tree.update(1, 0, m-1, res, INT_MIN)
		} else {
			count++
		}
	}

	return count
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int[] segTree = new int[400007];
    private int[] baskets;

    private void build(int p, int l, int r) {
        if (l == r) {
            segTree[p] = baskets[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build((p << 1) | 1, mid + 1, r);
        segTree[p] = Math.max(segTree[p << 1], segTree[(p << 1) | 1]);
    }

    private int query(int p, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) {
            return Integer.MIN_VALUE;
        }
        if (ql <= l && r <= qr) {
            return segTree[p];
        }
        int mid = (l + r) >> 1;
        return Math.max(
            query(p << 1, l, mid, ql, qr),
            query((p << 1) | 1, mid + 1, r, ql, qr)
        );
    }

    private void update(int p, int l, int r, int pos, int val) {
        if (l == r) {
            segTree[p] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            update(p << 1, l, mid, pos, val);
        } else {
            update((p << 1) | 1, mid + 1, r, pos, val);
        }
        segTree[p] = Math.max(segTree[p << 1], segTree[(p << 1) | 1]);
    }

    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        this.baskets = baskets;
        int m = baskets.length;
        int count = 0;
        if (m == 0) {
            return fruits.length;
        }
        Arrays.fill(segTree, Integer.MIN_VALUE);
        build(1, 0, m - 1);
        for (int i = 0; i < fruits.length; i++) {
            int l = 0;
            int r = m - 1;
            int res = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (query(1, 0, m - 1, 0, mid) >= fruits[i]) {
                    res = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (res != -1 && baskets[res] >= fruits[i]) {
                update(1, 0, m - 1, res, Integer.MIN_VALUE);
            } else {
                count++;
            }
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class SegTree {
    constructor(baskets) {
        this.baskets = baskets;
        this.n = baskets.length;
        this.segNode = new Array(4 * this.n).fill(0);
        this.build(1, 0, this.n - 1);
    }

    build(p, l, r) {
        if (l === r) {
            this.segNode[p] = this.baskets[l];
            return;
        }
        const mid = Math.floor((l + r) / 2);
        this.build(p * 2, l, mid);
        this.build(p * 2 + 1, mid + 1, r);
        this.segNode[p] = Math.max(
            this.segNode[p * 2],
            this.segNode[p * 2 + 1],
        );
    }

    query(p, l, r, ql, qr) {
        if (ql > r || qr < l) {
            return Number.MIN_SAFE_INTEGER;
        }
        if (ql <= l && r <= qr) {
            return this.segNode[p];
        }
        const mid = Math.floor((l + r) / 2);
        return Math.max(
            this.query(p * 2, l, mid, ql, qr),
            this.query(p * 2 + 1, mid + 1, r, ql, qr),
        );
    }

    update(p, l, r, pos, val) {
        if (l === r) {
            this.segNode[p] = val;
            return;
        }
        const mid = Math.floor((l + r) / 2);
        if (pos <= mid) {
            this.update(p * 2, l, mid, pos, val);
        } else {
            this.update(p * 2 + 1, mid + 1, r, pos, val);
        }
        this.segNode[p] = Math.max(
            this.segNode[p * 2],
            this.segNode[p * 2 + 1],
        );
    }
}

var numOfUnplacedFruits = function (fruits, baskets) {
    const m = baskets.length;
    if (m === 0) {
        return fruits.length;
    }
    const tree = new SegTree(baskets);
    let count = 0;

    for (const fruit of fruits) {
        let l = 0,
            r = m - 1,
            res = -1;
        while (l <= r) {
            const mid = Math.floor((l + r) / 2);
            if (tree.query(1, 0, m - 1, 0, mid) >= fruit) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (res !== -1 && tree.baskets[res] >= fruit) {
            tree.update(1, 0, m - 1, res, Number.MIN_SAFE_INTEGER);
        } else {
            count++;
        }
    }

    return count;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class SegTree:
    def __init__(self, baskets):
        self.n = len(baskets)
        size = 2 << (self.n - 1).bit_length()
        self.seg = [0] * size
        self._build(baskets, 1, 0, self.n - 1)

    def _maintain(self, o):
        self.seg[o] = max(self.seg[o * 2], self.seg[o * 2 + 1])

    def _build(self, a, o, l, r):
        if l == r:
            self.seg[o] = a[l]
            return
        m = (l + r) // 2
        self._build(a, o * 2, l, m)
        self._build(a, o * 2 + 1, m + 1, r)
        self._maintain(o)

    def find_first_and_update(self, o, l, r, x):
        if self.seg[o] < x:
            return -1
        if l == r:
            self.seg[o] = -1
            return l
        m = (l + r) // 2
        i = self.find_first_and_update(o * 2, l, m, x)
        if i == -1:
            i = self.find_first_and_update(o * 2 + 1, m + 1, r, x)
        self._maintain(o)
        return i


class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        m = len(baskets)
        if m == 0:
            return len(fruits)

        tree = SegTree(baskets)
        count = 0

        for fruit in fruits:
            if tree.find_first_and_update(1, 0, m - 1, fruit) == -1:
                count += 1

        return count
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class SegTree {
    private segNode: number[];
    public baskets: number[];
    private n: number;

    constructor(baskets: number[]) {
        this.baskets = baskets;
        this.n = baskets.length;
        this.segNode = new Array(4 * this.n + 7).fill(0);
        this.build(1, 0, this.n - 1);
    }

    private build(p: number, l: number, r: number): void {
        if (l === r) {
            this.segNode[p] = this.baskets[l];
            return;
        }
        const mid = Math.floor((l + r) / 2);
        this.build(p * 2, l, mid);
        this.build(p * 2 + 1, mid + 1, r);
        this.segNode[p] = Math.max(
            this.segNode[p * 2],
            this.segNode[p * 2 + 1],
        );
    }

    query(p: number, l: number, r: number, ql: number, qr: number): number {
        if (ql > r || qr < l) {
            return Number.MIN_SAFE_INTEGER;
        }
        if (ql <= l && r <= qr) {
            return this.segNode[p];
        }
        const mid = Math.floor((l + r) / 2);
        return Math.max(
            this.query(p * 2, l, mid, ql, qr),
            this.query(p * 2 + 1, mid + 1, r, ql, qr),
        );
    }

    update(p: number, l: number, r: number, pos: number, val: number): void {
        if (l === r) {
            this.segNode[p] = val;
            return;
        }
        const mid = Math.floor((l + r) / 2);
        if (pos <= mid) {
            this.update(p * 2, l, mid, pos, val);
        } else {
            this.update(p * 2 + 1, mid + 1, r, pos, val);
        }
        this.segNode[p] = Math.max(
            this.segNode[p * 2],
            this.segNode[p * 2 + 1],
        );
    }
}

function numOfUnplacedFruits(fruits: number[], baskets: number[]): number {
    const m = baskets.length;
    if (m === 0) {
        return fruits.length;
    }
    const tree = new SegTree(baskets);
    let count = 0;

    for (const fruit of fruits) {
        let l = 0,
            r = m - 1,
            res = -1;
        while (l <= r) {
            const mid = Math.floor((l + r) / 2);
            if (tree.query(1, 0, m - 1, 0, mid) >= fruit) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (res !== -1 && tree.baskets[res] >= fruit) {
            tree.update(1, 0, m - 1, res, Number.MIN_SAFE_INTEGER);
        } else {
            count++;
        }
    }

    return count;
}
```

</details>
