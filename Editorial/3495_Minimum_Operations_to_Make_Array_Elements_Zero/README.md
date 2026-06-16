# 3495. Minimum Operations to Make Array Elements Zero

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/)  
`Array` `Math` `Bit Manipulation`

**Problem Link:** [LeetCode 3495 - Minimum Operations to Make Array Elements Zero](https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/)

## Problem

You are given a 2D array queries, where queries[i] is of the form [l, r]. Each queries[i] defines an array of integers nums consisting of elements ranging from l to r, both inclusive.

In one operation, you can:

- Select two integers a and b from the array.
- Replace them with floor(a / 4) and floor(b / 4).

Your task is to determine the minimum number of operations required to reduce all elements of the array to zero for each query. Return the sum of the results for all queries.

### Example 1

### Example 2

## Constraints

- 1 <= queries.length <= 105
- queries[i].length == 2
- queries[i] == [l, r]
- 1 <= l < r <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3495. Minimum Operations to Make Array Elements Zero

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Find Patterns + Bitwise Operation Statistics | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Find Patterns + Bitwise Operation Statistics

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
long long get(int num) {
    long long cnt = 0;
    int i = 1;
    int base = 1;

    while (base <= num) {
        int end = (base * 2 - 1 < num) ? base * 2 - 1 : num;
        cnt += (long long)((i + 1) / 2) * (end - base + 1);
        i++;
        base *= 2;
    }
    return cnt;
}

long long minOperations(int** queries, int queriesSize, int* queriesColSize) {
    long long res = 0;
    for (int i = 0; i < queriesSize; i++) {
        long long count1 = get(queries[i][1]);
        long long count2 = get(queries[i][0] - 1);
        res += (count1 - count2 + 1) / 2;
    }
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    using ll = long long;

public:
    ll get(int num) {
        int i = 1;
        int base = 1;
        ll cnt = 0;
        while (base <= num) {
            cnt += 1ll * (i + 1) / 2 * (min(base * 2 - 1, num) - base + 1);
            i++;
            base *= 2;
        }
        return cnt;
    }
    long long minOperations(vector<vector<int>>& queries) {
        ll res = 0;
        for (auto& q : queries) {
            res += (get(q[1]) - get(q[0] - 1) + 1) / 2;
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private long Get(int num) {
        long cnt = 0;
        int i = 1;
        int baseVal = 1;

        while (baseVal <= num) {
            int end = Math.Min(baseVal * 2 - 1, num);
            cnt += (long)((i + 1) / 2) * (end - baseVal + 1);
            i++;
            baseVal *= 2;
        }
        return cnt;
    }

    public long MinOperations(int[][] queries) {
        long res = 0;
        foreach (var q in queries) {
            long count1 = Get(q[1]);
            long count2 = Get(q[0] - 1);
            res += (count1 - count2 + 1) / 2;
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func get(num int) int64 {
	var cnt int64
	i := 1
	base := 1

	for base <= num {
		end := base*2 - 1
		if end > num {
			end = num
		}
		cnt += int64((i+1)/2) * int64(end-base+1)
		i++
		base *= 2
	}
	return cnt
}

func minOperations(queries [][]int) int64 {
	var res int64
	for _, q := range queries {
		count1 := get(q[1])
		count2 := get(q[0] - 1)
		res += (count1 - count2 + 1) / 2
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private long get(int num) {
        long cnt = 0;
        int i = 1;
        int base = 1;
        while (base <= num) {
            int end = Math.min(base * 2 - 1, num);
            cnt += (long) ((i + 1) / 2) * (end - base + 1);
            i++;
            base *= 2;
        }
        return cnt;
    }

    public long minOperations(int[][] queries) {
        long res = 0;
        for (int[] q : queries) {
            long count1 = get(q[1]);
            long count2 = get(q[0] - 1);
            res += (count1 - count2 + 1) / 2;
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minOperations = function (queries) {
    let res = 0n;
    for (const q of queries) {
        const count1 = get(q[1]);
        const count2 = get(q[0] - 1);
        res += (count1 - count2 + 1n) / 2n;
    }
    return Number(res);
};

const get = (num) => {
    let cnt = 0n;
    let i = 1;
    let base = 1;

    while (base <= num) {
        const end = Math.min(base * 2 - 1, num);
        cnt += BigInt(Math.floor((i + 1) / 2)) * BigInt(end - base + 1);
        i++;
        base *= 2;
    }
    return cnt;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def get(self, num: int) -> int:
        i = 1
        base = 1
        cnt = 0
        while base <= num:
            cnt += ((i + 1) // 2) * (min(base * 2 - 1, num) - base + 1)
            i += 1
            base *= 2
        return cnt

    def minOperations(self, queries: List[List[int]]) -> int:
        res = 0
        for q in queries:
            res += (self.get(q[1]) - self.get(q[0] - 1) + 1) // 2
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minOperations(queries: number[][]): number {
    let res = 0n;
    for (const q of queries) {
        const count1 = get(q[1]);
        const count2 = get(q[0] - 1);
        res += (count1 - count2 + 1n) / 2n;
    }
    return Number(res);
}

function get(num: number): bigint {
    let cnt = 0n;
    let i = 1;
    let base = 1;

    while (base <= num) {
        const end = Math.min(base * 2 - 1, num);
        cnt += BigInt(Math.floor((i + 1) / 2)) * BigInt(end - base + 1);
        i++;
        base *= 2;
    }
    return cnt;
}
```

</details>
