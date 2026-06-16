# 1039. Minimum Score Triangulation of Polygon

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 1039 - Minimum Score Triangulation of Polygon](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/)

## Problem

You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex in clockwise order.

Polygon triangulation is a process where you divide a polygon into a set of triangles and the vertices of each triangle must also be vertices of the original polygon. Note that no other shapes other than triangles are allowed in the division. This process will result in n - 2 triangles.

You will triangulate the polygon. For each triangle, the weight of that triangle is the product of the values at its vertices. The total score of the triangulation is the sum of these weights over all n - 2 triangles.

Return the minimum possible score that you can achieve with some triangulation of the polygon.

### Example 1

### Example 2

### Example 3

​​​​​​​

## Constraints

- n == values.length
- 3 <= n <= 50
- 1 <= values[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1039. Minimum Score Triangulation of Polygon

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3 |

## Approach: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, int key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

int hashGetItem(HashItem **obj, int key, int defaultVal) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

bool hashSetItem(HashItem **obj, int key, int val) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        hashAddItem(obj, key, val);
    } else {
        pEntry->val = val;
    }
    return true;
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

inline int min(int a, int b) { return a < b ? a : b; }

int dp(int i, int j, int *values, int valuesSize, HashItem **memo) {
    if (i + 2 > j) {
        return 0;
    }
    if (i + 2 == j) {
        return values[i] * values[i + 1] * values[j];
    }
    int key = i * valuesSize + j;
    if (!hashFindItem(memo, key)) {
        int minScore = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            minScore = min(minScore, values[i] * values[k] * values[j] +
                                         dp(i, k, values, valuesSize, memo) +
                                         dp(k, j, values, valuesSize, memo));
        }
        hashAddItem(memo, key, minScore);
    }
    return hashGetItem(memo, key, 0);
}

int minScoreTriangulation(int *values, int valuesSize) {
    HashItem *memo = NULL;
    int ret = dp(0, valuesSize - 1, values, valuesSize, &memo);
    hashFree(&memo);
    return ret;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        unordered_map<int, int> memo;
        int n = values.size();
        function<int(int, int)> dp = [&](int i, int j) -> int {
            if (i + 2 > j) {
                return 0;
            }
            if (i + 2 == j) {
                return values[i] * values[i + 1] * values[j];
            }
            int key = i * n + j;
            if (!memo.count(key)) {
                int minScore = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    minScore = min(minScore, values[i] * values[k] * values[j] +
                                                 dp(i, k) + dp(k, j));
                }
                memo[key] = minScore;
            }
            return memo[key];
        };
        return dp(0, n - 1);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    int n;
    int[] values;
    IDictionary<int, int> memo = new Dictionary<int, int>();

    public int MinScoreTriangulation(int[] values) {
        this.n = values.Length;
        this.values = values;
        return DP(0, n - 1);
    }

    public int DP(int i, int j) {
        if (i + 2 > j) {
            return 0;
        }
        if (i + 2 == j) {
            return values[i] * values[i + 1] * values[j];
        }
        int key = i * n + j;
        if (!memo.ContainsKey(key)) {
            int minScore = int.MaxValue;
            for (int k = i + 1; k < j; k++) {
                minScore =
                    Math.Min(minScore, values[i] * values[k] * values[j] +
                                           DP(i, k) + DP(k, j));
            }
            memo.Add(key, minScore);
        }
        return memo[key];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minScoreTriangulation(values []int) int {
    memo := make(map[int]int)
    n := len(values)
    var dp func(int, int) int
    dp = func(i int, j int) int {
        if i + 2 > j {
            return 0
        }
        if i + 2 == j {
            return values[i] * values[i + 1] * values[j]
        }
        key := i * n + j
        if _, ok := memo[key]; !ok {
            minScore := math.MaxInt32
            for k := i + 1; k < j; k++ {
                minScore = min(minScore, values[i] * values[k] * values[j] + dp(i, k) + dp(k, j))
            }
            memo[key] = minScore
        }
        return memo[key]
    }
    return dp(0, n - 1)
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    int n;
    int[] values;
    Map<Integer, Integer> memo = new HashMap<Integer, Integer>();

    public int minScoreTriangulation(int[] values) {
        this.n = values.length;
        this.values = values;
        return dp(0, n - 1);
    }

    public int dp(int i, int j) {
        if (i + 2 > j) {
            return 0;
        }
        if (i + 2 == j) {
            return values[i] * values[i + 1] * values[j];
        }
        int key = i * n + j;
        if (!memo.containsKey(key)) {
            int minScore = Integer.MAX_VALUE;
            for (int k = i + 1; k < j; k++) {
                minScore = Math.min(
                    minScore,
                    values[i] * values[k] * values[j] + dp(i, k) + dp(k, j)
                );
            }
            memo.put(key, minScore);
        }
        return memo.get(key);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minScoreTriangulation = function (values) {
    const n = values.length;
    const memo = new Map();
    const dp = (i, j) => {
        if (i + 2 > j) {
            return 0;
        }
        if (i + 2 === j) {
            return values[i] * values[i + 1] * values[j];
        }
        const key = i * n + j;
        if (!memo.has(key)) {
            let minScore = Number.MAX_VALUE;
            for (let k = i + 1; k < j; k++) {
                minScore = Math.min(
                    minScore,
                    values[i] * values[k] * values[j] + dp(i, k) + dp(k, j),
                );
            }
            memo.set(key, minScore);
        }
        return memo.get(key);
    };
    return dp(0, n - 1);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        @lru_cache(None)
        def dp(i, j):
            if i + 2 > j:
                return 0
            if i + 2 == j:
                return values[i] * values[i + 1] * values[j]
            return min(
                (values[i] * values[k] * values[j] + dp(i, k) + dp(k, j))
                for k in range(i + 1, j)
            )

        return dp(0, len(values) - 1)
```

</details>
