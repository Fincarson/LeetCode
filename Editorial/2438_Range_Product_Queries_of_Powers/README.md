# 2438. Range Product Queries of Powers

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/range-product-queries-of-powers/)  
`Array` `Bit Manipulation` `Prefix Sum`

**Problem Link:** [LeetCode 2438 - Range Product Queries of Powers](https://leetcode.com/problems/range-product-queries-of-powers/)

## Problem

Given a positive integer n, there exists a 0-indexed array called powers, composed of the minimum number of powers of 2 that sum to n. The array is sorted in non-decreasing order, and there is only one way to form the array.

You are also given a 0-indexed 2D integer array queries, where queries[i] = [lefti, righti]. Each queries[i] represents a query where you have to find the product of all powers[j] with lefti <= j <= righti.

Return an array answers, equal in length to queries, where answers[i] is the answer to the ith query. Since the answer to the ith query may be too large, each answers[i] should be returned modulo 109 + 7.

### Example 1

```text
Input: n = 15, queries = [[0,1],[2,2],[0,3]]
Output: [2,4,64]
Explanation:
For n = 15, powers = [1,2,4,8]. It can be shown that powers cannot be a smaller size.
Answer to 1st query: powers[0] * powers[1] = 1 * 2 = 2.
Answer to 2nd query: powers[2] = 4.
Answer to 3rd query: powers[0] * powers[1] * powers[2] * powers[3] = 1 * 2 * 4 * 8 = 64.
Each answer modulo 109 + 7 yields the same answer, so [2,4,64] is returned.
```

### Example 2

```text
Input: n = 2, queries = [[0,0]]
Output: [2]
Explanation:
For n = 2, powers = [2].
The answer to the only query is powers[0] = 2. The answer modulo 109 + 7 is the same, so [2] is returned.
```

## Constraints

- 1 <= n <= 109
- 1 <= queries.length <= 105
- 0 <= starti <= endi < powers.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2438. Range Product Queries of Powers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Decomposition + Direct Calculation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Binary Decomposition + Prefix Product Preprocessing | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Binary Decomposition + Direct Calculation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* productQueries(int n, int** queries, int queriesSize, int* queriesColSize,
                    int* returnSize) {
    const int mod = 1000000007;
    int* bins = (int*)malloc(32 * sizeof(int));
    int binsSize = 0;
    int rep = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            bins[binsSize++] = rep;
        }
        n /= 2;
        rep *= 2;
    }

    int* ans = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;
    for (int i = 0; i < queriesSize; i++) {
        long long cur = 1;
        for (int j = queries[i][0]; j <= queries[i][1]; j++) {
            cur = (cur * bins[j]) % mod;
        }
        ans[i] = (int)cur;
    }
    free(bins);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> bins;
        int rep = 1;
        while (n) {
            if (n % 2 == 1) {
                bins.push_back(rep);
            }
            n /= 2;
            rep *= 2;
        }

        vector<int> ans;
        for (const auto& query : queries) {
            int cur = 1;
            for (int i = query[0]; i <= query[1]; ++i) {
                cur = static_cast<long long>(cur) * bins[i] % mod;
            }
            ans.push_back(cur);
        }
        return ans;
    }

private:
    static constexpr int mod = 1000000007;
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private const int MOD = 1000000007;

    public int[] ProductQueries(int n, int[][] queries) {
        var bins = new List<int>();
        int rep = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                bins.Add(rep);
            }
            n /= 2;
            rep *= 2;
        }

        int[] ans = new int[queries.Length];
        for (int i = 0; i < queries.Length; i++) {
            long cur = 1;
            int start = queries[i][0];
            int end = queries[i][1];
            for (int j = start; j <= end; ++j) {
                cur = (cur * bins[j]) % MOD;
            }
            ans[i] = (int)cur;
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func productQueries(n int, queries [][]int) []int {
	const mod = 1000000007
	var bins []int
	rep := 1
	for n > 0 {
		if n%2 == 1 {
			bins = append(bins, rep)
		}
		n /= 2
		rep *= 2
	}

	ans := make([]int, 0, len(queries))
	for _, query := range queries {
		cur := 1
		for i := query[0]; i <= query[1]; i++ {
			cur = (cur * bins[i]) % mod
		}
		ans = append(ans, cur)
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final int MOD = 1000000007;

    public int[] productQueries(int n, int[][] queries) {
        List<Integer> bins = new ArrayList<>();
        int rep = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                bins.add(rep);
            }
            n /= 2;
            rep *= 2;
        }

        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            long cur = 1;
            int start = queries[i][0];
            int end = queries[i][1];
            for (int j = start; j <= end; j++) {
                cur = (cur * bins.get(j)) % MOD;
            }
            ans[i] = (int) cur;
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var productQueries = function (n, queries) {
    const mod = 1000000007;
    const bins = [];
    let rep = 1;
    while (n > 0) {
        if (n % 2 === 1) {
            bins.push(rep);
        }
        n = Math.floor(n / 2);
        rep *= 2;
    }

    const ans = [];
    for (const [start, end] of queries) {
        let cur = 1;
        for (let i = start; i <= end; i++) {
            cur = (cur * bins[i]) % mod;
        }
        ans.push(cur);
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        mod = 10**9 + 7

        bins, rep = [], 1
        while n > 0:
            if n % 2 == 1:
                bins.append(rep)
            n //= 2
            rep *= 2

        ans = []
        for left, right in queries:
            cur = 1
            for i in range(left, right + 1):
                cur = cur * bins[i] % mod
            ans.append(cur)
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function productQueries(n: number, queries: number[][]): number[] {
    const mod: number = 1000000007;
    const bins: number[] = [];
    let rep = 1;
    while (n > 0) {
        if (n % 2 === 1) {
            bins.push(rep);
        }
        n = Math.floor(n / 2);
        rep *= 2;
    }

    const ans: number[] = [];
    for (const [start, end] of queries) {
        let cur = 1;
        for (let i = start; i <= end; i++) {
            cur = (cur * bins[i]) % mod;
        }
        ans.push(cur);
    }
    return ans;
}
```

</details>

<br>

## Approach 2: Binary Decomposition + Prefix Product Preprocessing

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* productQueries(int n, int** queries, int queriesSize, int* queriesColSize,
                    int* returnSize) {
    const int mod = 1000000007;
    int bins[32];
    int binsSize = 0;
    int rep = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            bins[binsSize++] = rep;
        }
        n /= 2;
        rep *= 2;
    }

    int** results = (int**)malloc(binsSize * sizeof(int*));
    for (int i = 0; i < binsSize; i++) {
        results[i] = (int*)malloc(binsSize * sizeof(int));
        long long cur = 1;
        for (int j = i; j < binsSize; j++) {
            cur = (cur * bins[j]) % mod;
            results[i][j] = (int)cur;
        }
    }

    int* ans = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;
    for (int i = 0; i < queriesSize; i++) {
        ans[i] = results[queries[i][0]][queries[i][1]];
    }

    for (int i = 0; i < binsSize; i++) {
        free(results[i]);
    }
    free(results);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> bins;
        int rep = 1;
        while (n) {
            if (n % 2 == 1) {
                bins.push_back(rep);
            }
            n /= 2;
            rep *= 2;
        }

        int m = bins.size();
        vector<vector<int>> results(m, vector<int>(m));
        for (int i = 0; i < m; ++i) {
            int cur = 1;
            for (int j = i; j < m; ++j) {
                cur = static_cast<long long>(cur) * bins[j] % mod;
                results[i][j] = cur;
            }
        }

        vector<int> ans;
        for (const auto& query : queries) {
            ans.push_back(results[query[0]][query[1]]);
        }
        return ans;
    }

private:
    static constexpr int mod = 1000000007;
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private const int MOD = 1000000007;

    public int[] ProductQueries(int n, int[][] queries) {
        var bins = new List<int>();
        int rep = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                bins.Add(rep);
            }
            n /= 2;
            rep *= 2;
        }

        int m = bins.Count;
        int[,] results = new int[m, m];
        for (int i = 0; i < m; i++) {
            long cur = 1;
            for (int j = i; j < m; j++) {
                cur = (cur * bins[j]) % MOD;
                results[i, j] = (int)cur;
            }
        }

        int[] ans = new int[queries.Length];
        for (int i = 0; i < queries.Length; i++) {
            ans[i] = results[queries[i][0], queries[i][1]];
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func productQueries(n int, queries [][]int) []int {
	const mod = 1000000007
	var bins []int
	rep := 1
	for n > 0 {
		if n%2 == 1 {
			bins = append(bins, rep)
		}
		n /= 2
		rep *= 2
	}

	m := len(bins)
	results := make([][]int, m)
	for i := range results {
		results[i] = make([]int, m)
		cur := 1
		for j := i; j < m; j++ {
			cur = (cur * bins[j]) % mod
			results[i][j] = cur
		}
	}

	ans := make([]int, len(queries))
	for i, query := range queries {
		ans[i] = results[query[0]][query[1]]
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final int MOD = 1000000007;

    public int[] productQueries(int n, int[][] queries) {
        List<Integer> bins = new ArrayList<>();
        int rep = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                bins.add(rep);
            }
            n /= 2;
            rep *= 2;
        }

        int m = bins.size();
        int[][] results = new int[m][m];
        for (int i = 0; i < m; i++) {
            long cur = 1;
            for (int j = i; j < m; j++) {
                cur = (cur * bins.get(j)) % MOD;
                results[i][j] = (int) cur;
            }
        }

        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            ans[i] = results[queries[i][0]][queries[i][1]];
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var productQueries = function (n, queries) {
    const mod = 1000000007;
    const bins = [];
    let rep = 1;
    while (n > 0) {
        if (n % 2 === 1) {
            bins.push(rep);
        }
        n = Math.floor(n / 2);
        rep *= 2;
    }

    const m = bins.length;
    const results = Array.from({ length: m }, () => new Array(m));
    for (let i = 0; i < m; i++) {
        let cur = 1;
        for (let j = i; j < m; j++) {
            cur = (cur * bins[j]) % mod;
            results[i][j] = cur;
        }
    }

    const ans = [];
    for (const [start, end] of queries) {
        ans.push(results[start][end]);
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        mod = 10**9 + 7

        bins, rep = [], 1
        while n > 0:
            if n % 2 == 1:
                bins.append(rep)
            n //= 2
            rep *= 2

        m = len(bins)
        results = [[0] * m for _ in range(m)]
        for i in range(m):
            cur = 1
            for j in range(i, m):
                cur = cur * bins[j] % mod
                results[i][j] = cur

        ans = []
        for left, right in queries:
            ans.append(results[left][right])
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function productQueries(n: number, queries: number[][]): number[] {
    const mod: number = 1000000007;
    const bins: number[] = [];
    let rep = 1;
    while (n > 0) {
        if (n % 2 === 1) {
            bins.push(rep);
        }
        n = Math.floor(n / 2);
        rep *= 2;
    }

    const m = bins.length;
    const results: number[][] = Array.from({ length: m }, () => new Array(m));
    for (let i = 0; i < m; i++) {
        let cur = 1;
        for (let j = i; j < m; j++) {
            cur = (cur * bins[j]) % mod;
            results[i][j] = cur;
        }
    }

    const ans: number[] = [];
    for (const [start, end] of queries) {
        ans.push(results[start][end]);
    }
    return ans;
}
```

</details>
