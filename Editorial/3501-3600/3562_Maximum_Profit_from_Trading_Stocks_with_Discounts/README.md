# 3562. Maximum Profit from Trading Stocks with Discounts

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/maximum-profit-from-trading-stocks-with-discounts/)  
`Array` `Dynamic Programming` `Tree` `Depth-First Search`

**Problem Link:** [LeetCode 3562 - Maximum Profit from Trading Stocks with Discounts](https://leetcode.com/problems/maximum-profit-from-trading-stocks-with-discounts/)

## Problem

You are given an integer n, representing the number of employees in a company. Each employee is assigned a unique ID from 1 to n, and employee 1 is the CEO, is the direct or indirect boss of every employee. You are given two 1-based integer arrays, present and future, each of length n, where:

- present[i] represents the current price at which the ith employee can buy a stock today.
- future[i] represents the expected price at which the ith employee can sell the stock tomorrow.

The company's hierarchy is represented by a 2D integer array hierarchy, where hierarchy[i] = [ui, vi] means that employee ui is the direct boss of employee vi.

Additionally, you have an integer budget representing the total funds available for investment.

However, the company has a discount policy: if an employee's direct boss purchases their own stock, then the employee can buy their stock at half the original price (floor(present[v] / 2)).

Return the maximum profit that can be achieved without exceeding the given budget.

Note:

- You may buy each stock at most once.
- You cannot use any profit earned from future stock prices to fund additional investments and must buy only from budget.

### Example 1

### Example 2

### Example 3

### Example 4

## Constraints

- 1 <= n <= 160
- present.length, future.length == n
- 1 <= present[i], future[i] <= 50
- hierarchy.length == n - 1
- hierarchy[i] == [ui, vi]
- 1 <= ui, vi <= n
- ui != vi
- 1 <= budget <= 160
- There are no duplicate edges.
- Employee 1 is the direct or indirect boss of every employee.
- The input graph hierarchy is guaranteed to have no cycles.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3562. Maximum Profit from Trading Stocks with Discounts

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Tree Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Tree Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int* dp0;
    int* dp1;
    int size;
} Result;

struct ListNode* creatListNode(int val) {
    struct ListNode* obj = (struct ListNode*)malloc(sizeof(struct ListNode));
    obj->val = val;
    obj->next = NULL;
    return obj;
}

void freeList(struct ListNode* list) {
    while (list) {
        struct ListNode* p = list;
        list = list->next;
        free(p);
    }
}

void dfs(int u, int n, int* present, int* future, struct ListNode** g,
         int budget, Result* result, int* visited) {
    if (visited[u]) {
        return;
    }

    visited[u] = 1;
    int cost = present[u];
    int dCost = present[u] / 2;
    // dp[u][state][budget]
    // state = 0: Do not purchase parent node, state = 1: Must purchase parent
    // node
    int* dp0 = (int*)calloc(budget + 1, sizeof(int));
    int* dp1 = (int*)calloc(budget + 1, sizeof(int));
    // subProfit[state][budget]
    // state = 0: discount not available, state = 1: discount available
    int* subProfit0 = (int*)calloc(budget + 1, sizeof(int));
    int* subProfit1 = (int*)calloc(budget + 1, sizeof(int));
    int uSize = cost;

    for (struct ListNode* p = g[u]; p; p = p->next) {
        int v = p->val;
        Result childResult;
        childResult.dp0 = NULL;
        childResult.dp1 = NULL;
        childResult.size = 0;
        dfs(v, n, present, future, g, budget, &childResult, visited);

        uSize += childResult.size;
        for (int j = budget; j >= 0; j--) {
            for (int sub = 0; sub <= fmin(childResult.size, j); sub++) {
                if (j - sub >= 0) {
                    subProfit0[j] =
                        fmax(subProfit0[j],
                             subProfit0[j - sub] + childResult.dp0[sub]);
                    subProfit1[j] =
                        fmax(subProfit1[j],
                             subProfit1[j - sub] + childResult.dp1[sub]);
                }
            }
        }

        free(childResult.dp0);
        free(childResult.dp1);
    }

    for (int i = 0; i <= budget; i++) {
        dp0[i] = subProfit0[i];
        dp1[i] = subProfit0[i];
        if (i >= dCost) {
            dp1[i] =
                fmax(subProfit0[i], subProfit1[i - dCost] + future[u] - dCost);
        }
        if (i >= cost) {
            dp0[i] =
                fmax(subProfit0[i], subProfit1[i - cost] + future[u] - cost);
        }
    }

    result->dp0 = dp0;
    result->dp1 = dp1;
    result->size = uSize;

    free(subProfit0);
    free(subProfit1);
}

int maxProfit(int n, int* present, int presentSize, int* future, int futureSize,
              int** hierarchy, int hierarchySize, int* hierarchyColSize,
              int budget) {
    struct ListNode** g =
        (struct ListNode**)malloc(n * sizeof(struct ListNode*));
    for (int i = 0; i < n; i++) {
        g[i] = NULL;
    }
    for (int i = 0; i < hierarchySize; i++) {
        int u = hierarchy[i][0] - 1;
        int v = hierarchy[i][1] - 1;
        struct ListNode* p = creatListNode(v);
        p->next = g[u];
        g[u] = p;
    }

    int* visited = (int*)calloc(n, sizeof(int));
    Result result;
    result.dp0 = NULL;
    result.dp1 = NULL;
    result.size = 0;
    dfs(0, n, present, future, g, budget, &result, visited);

    int ret = result.dp0[budget];
    free(result.dp0);
    free(result.dp1);
    free(visited);
    for (int i = 0; i < n; i++) {
        freeList(g[i]);
    }
    free(g);

    return ret;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future,
                  vector<vector<int>>& hierarchy, int budget) {
        vector<vector<int>> g(n);

        for (auto& e : hierarchy) {
            g[e[0] - 1].push_back(e[1] - 1);
        }

        auto dfs = [&](auto&& self,
                       int u) -> tuple<vector<int>, vector<int>, int> {
            int cost = present[u];
            int dCost = present[u] / 2;  // discounted cost

            // dp[u][state][budget]
            // state = 0: Do not purchase parent node, state = 1: Must purchase
            // parent node
            auto dp0 = vector(budget + 1, 0);
            auto dp1 = vector(budget + 1, 0);

            // subProfit[state][budget]
            // state = 0: discount not available, state = 1: discount available
            auto subProfit0 = vector(budget + 1, 0);
            auto subProfit1 = vector(budget + 1, 0);

            int uSize = cost;

            for (auto v : g[u]) {
                auto [subDp0, subDp1, vSize] = self(self, v);
                uSize += vSize;
                for (int i = budget; i >= 0; i--) {
                    for (int sub = 0; sub <= min(vSize, i); sub++) {
                        subProfit0[i] = max(subProfit0[i],
                                            subProfit0[i - sub] + subDp0[sub]);
                        subProfit1[i] = max(subProfit1[i],
                                            subProfit1[i - sub] + subDp1[sub]);
                    }
                }
            }

            for (int i = 0; i <= budget; i++) {
                dp0[i] = dp1[i] = subProfit0[i];

                if (i >= dCost) {
                    dp1[i] = max(subProfit0[i],
                                 subProfit1[i - dCost] + future[u] - dCost);
                }

                if (i >= cost) {
                    dp0[i] = max(subProfit0[i],
                                 subProfit1[i - cost] + future[u] - cost);
                }
            }

            return {dp0, dp1, uSize};
        };

        return std::get<0>(dfs(dfs, 0))[budget];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxProfit(int n, int[] present, int[] future, int[][] hierarchy,
                         int budget) {
        List<int>[] g = new List<int>[n];
        for (int i = 0; i < n; i++) {
            g[i] = new List<int>();
        }
        foreach (var e in hierarchy) {
            g[e[0] - 1].Add(e[1] - 1);
        }

        (int[] dp0, int[] dp1, int size) Dfs(int u) {
            int cost = present[u];
            int dCost = present[u] / 2;  // discounted cost

            // dp[u][state][budget]
            // state = 0: Do not purchase parent node, state = 1: Must purchase
            // parent node
            int[] dp0 = new int[budget + 1];
            int[] dp1 = new int[budget + 1];
            // subProfit[state][budget]
            // state = 0: discount not available, state = 1: discount available
            int[] subProfit0 = new int[budget + 1];
            int[] subProfit1 = new int[budget + 1];
            int uSize = cost;

            foreach (int v in g[u]) {
                var (childDp0, childDp1, vSize) = Dfs(v);
                uSize += vSize;
                for (int i = budget; i >= 0; i--) {
                    for (int sub = 0; sub <= Math.Min(vSize, i); sub++) {
                        if (i - sub >= 0) {
                            subProfit0[i] =
                                Math.Max(subProfit0[i],
                                         subProfit0[i - sub] + childDp0[sub]);
                            subProfit1[i] =
                                Math.Max(subProfit1[i],
                                         subProfit1[i - sub] + childDp1[sub]);
                        }
                    }
                }
            }

            for (int i = 0; i <= budget; i++) {
                dp0[i] = subProfit0[i];
                dp1[i] = subProfit0[i];
                if (i >= dCost) {
                    dp1[i] = Math.Max(subProfit0[i], subProfit1[i - dCost] +
                                                         future[u] - dCost);
                }
                if (i >= cost) {
                    dp0[i] = Math.Max(subProfit0[i],
                                      subProfit1[i - cost] + future[u] - cost);
                }
            }

            return (dp0, dp1, uSize);
        }

        return Dfs(0).dp0[budget];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxProfit(n int, present []int, future []int, hierarchy [][]int, budget int) int {
    // Ã¦Å¾â€žÃ¥Â»ÂºÃ©â€šÂ»Ã¦Å½Â¥Ã¨Â¡Â¨
    g := make([][]int, n)
    for i := range g {
        g[i] = make([]int, 0)
    }
    for _, e := range hierarchy {
        g[e[0] - 1] = append(g[e[0] - 1], e[1] - 1)
    }
    
    var dfs func(int) result
    dfs = func(u int) result {
        cost := present[u]
        dCost := present[u] / 2
        // dp[u][state][budget]
        // state = 0: Do not purchase parent node, state = 1: Must purchase parent node
        dp0 := make([]int, budget + 1)
        dp1 := make([]int, budget + 1)
        // subProfit[state][budget]
        // state = 0: discount not available, state = 1: discount available
        subProfit0 := make([]int, budget + 1)
        subProfit1 := make([]int, budget + 1)
        
        uSize := cost
        for _, v := range g[u] {
            childResult := dfs(v)
            uSize += childResult.size
            for i := budget; i >= 0; i-- {
                for sub := 0; sub <= min(childResult.size, i); sub++ {
                    if i-sub >= 0 {
                        subProfit0[i] = max(subProfit0[i], subProfit0[i-sub] + childResult.dp0[sub])
                        subProfit1[i] = max(subProfit1[i], subProfit1[i-sub] + childResult.dp1[sub])
                    }
                }
            }
        }
        
        for i := 0; i <= budget; i++ {
            dp0[i] = subProfit0[i]
            dp1[i] = subProfit0[i]
            if i >= dCost {
                dp1[i] = max(subProfit0[i], subProfit1[i-dCost] + future[u] - dCost)
            }
            if i >= cost {
                dp0[i] = max(subProfit0[i], subProfit1[i-cost] + future[u] - cost)
            }
        }
        
        return result{dp0, dp1, uSize}
    }
    
    return dfs(0).dp0[budget]
}

type result struct {
    dp0  []int
    dp1  []int
    size int
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Result {

    int[] dp0;
    int[] dp1;
    int size;

    Result(int[] dp0, int[] dp1, int size) {
        this.dp0 = dp0;
        this.dp1 = dp1;
        this.size = size;
    }
}

class Solution {

    public int maxProfit(
        int n,
        int[] present,
        int[] future,
        int[][] hierarchy,
        int budget
    ) {
        List<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int[] e : hierarchy) {
            g[e[0] - 1].add(e[1] - 1);
        }

        return dfs(0, present, future, g, budget).dp0[budget];
    }

    private Result dfs(
        int u,
        int[] present,
        int[] future,
        List<Integer>[] g,
        int budget
    ) {
        int cost = present[u];
        int dCost = present[u] / 2;
        // dp[u][state][budget]
        // state = 0: Do not purchase parent node, state = 1: Must purchase parent node
        int[] dp0 = new int[budget + 1];
        int[] dp1 = new int[budget + 1];

        // subProfit[state][budget]
        // state = 0: discount not available, state = 1: discount available
        int[] subProfit0 = new int[budget + 1];
        int[] subProfit1 = new int[budget + 1];
        int uSize = cost;

        for (int v : g[u]) {
            Result childResult = dfs(v, present, future, g, budget);
            uSize += childResult.size;

            for (int i = budget; i >= 0; i--) {
                for (int sub = 0; sub <= Math.min(childResult.size, i); sub++) {
                    if (i - sub >= 0) {
                        subProfit0[i] = Math.max(
                            subProfit0[i],
                            subProfit0[i - sub] + childResult.dp0[sub]
                        );
                        subProfit1[i] = Math.max(
                            subProfit1[i],
                            subProfit1[i - sub] + childResult.dp1[sub]
                        );
                    }
                }
            }
        }

        for (int i = 0; i <= budget; i++) {
            dp0[i] = subProfit0[i];
            dp1[i] = subProfit0[i];
            if (i >= dCost) {
                dp1[i] = Math.max(
                    subProfit0[i],
                    subProfit1[i - dCost] + future[u] - dCost
                );
            }
            if (i >= cost) {
                dp0[i] = Math.max(
                    subProfit0[i],
                    subProfit1[i - cost] + future[u] - cost
                );
            }
        }

        return new Result(dp0, dp1, uSize);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxProfit = function (n, present, future, hierarchy, budget) {
    const g = Array.from({ length: n }, () => []);

    for (const e of hierarchy) {
        g[e[0] - 1].push(e[1] - 1);
    }

    const dfs = (u) => {
        const cost = present[u];
        const dCost = Math.floor(present[u] / 2); // discounted cost

        // dp[u][state][budget]
        // state: 0 = not purchasing parent node, 1 = purchasing parent node
        const dp0 = new Array(budget + 1).fill(0);
        const dp1 = new Array(budget + 1).fill(0);

        // subProfit[state][budget]
        // state = 0: discount not available, state = 1: discount available
        const subProfit0 = Array(budget + 1).fill(0);
        const subProfit1 = Array(budget + 1).fill(0);

        let uSize = cost;

        for (const v of g[u]) {
            const [subDp0, subDp1, vSize] = dfs(v);
            uSize += vSize;

            for (let i = budget; i >= 0; i--) {
                for (let sub = 0; sub <= Math.min(vSize, i); sub++) {
                    subProfit0[i] = Math.max(
                        subProfit0[i],
                        subProfit0[i - sub] + subDp0[sub],
                    );
                    subProfit1[i] = Math.max(
                        subProfit1[i],
                        subProfit1[i - sub] + subDp1[sub],
                    );
                }
            }
        }

        for (let i = 0; i <= budget; i++) {
            dp0[i] = dp1[i] = subProfit0[i];

            if (i >= dCost) {
                dp1[i] = Math.max(
                    subProfit0[i],
                    subProfit1[i - dCost] + future[u] - dCost,
                );
            }

            if (i >= cost) {
                dp0[i] = Math.max(
                    subProfit0[i],
                    subProfit1[i - cost] + future[u] - cost,
                );
            }
        }

        return [dp0, dp1, uSize];
    };

    return dfs(0)[0][budget];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProfit(
        self,
        n: int,
        present: List[int],
        future: List[int],
        hierarchy: List[List[int]],
        budget: int,
    ) -> int:
        g = [[] for _ in range(n)]
        for e in hierarchy:
            g[e[0] - 1].append(e[1] - 1)

        def dfs(u: int):
            cost = present[u]
            dCost = present[u] // 2

            # dp[u][state][budget]
            # state = 0: Do not purchase parent node, state = 1: Must purchase parent node
            dp0 = [0] * (budget + 1)
            dp1 = [0] * (budget + 1)

            # subProfit[state][budget]
            # state = 0: discount not available, state = 1: discount available
            subProfit0 = [0] * (budget + 1)
            subProfit1 = [0] * (budget + 1)
            uSize = cost

            for v in g[u]:
                child_dp0, child_dp1, vSize = dfs(v)
                uSize += vSize
                for i in range(budget, -1, -1):
                    for sub in range(min(vSize, i) + 1):
                        if i - sub >= 0:
                            subProfit0[i] = max(
                                subProfit0[i],
                                subProfit0[i - sub] + child_dp0[sub],
                            )
                            subProfit1[i] = max(
                                subProfit1[i],
                                subProfit1[i - sub] + child_dp1[sub],
                            )

            for i in range(budget + 1):
                dp0[i] = subProfit0[i]
                dp1[i] = subProfit0[i]
                if i >= dCost:
                    dp1[i] = max(
                        subProfit0[i], subProfit1[i - dCost] + future[u] - dCost
                    )
                if i >= cost:
                    dp0[i] = max(
                        subProfit0[i], subProfit1[i - cost] + future[u] - cost
                    )

            return dp0, dp1, uSize

        return dfs(0)[0][budget]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxProfit(
    n: number,
    present: number[],
    future: number[],
    hierarchy: number[][],
    budget: number,
): number {
    const g = Array.from({ length: n }, () => [] as number[]);

    for (const e of hierarchy) {
        g[e[0] - 1].push(e[1] - 1);
    }

    const dfs = (u: number) => {
        const cost = present[u];
        const dCost = Math.floor(present[u] / 2); // discounted cost

        // dp[u][state][budget]
        // state: 0 = not purchasing parent node, 1 = purchasing parent node
        const dp0: number[] = new Array(budget + 1).fill(0);
        const dp1: number[] = new Array(budget + 1).fill(0);

        // subProfit[state][budget]
        // state = 0: discount not available, state = 1: discount available
        const subProfit0: number[] = Array(budget + 1).fill(0);
        const subProfit1: number[] = Array(budget + 1).fill(0);

        let uSize = cost;

        for (const v of g[u]) {
            const [subDp0, subDp1, vSize] = dfs(v);
            uSize += vSize;

            for (let i = budget; i >= 0; i--) {
                for (let sub = 0; sub <= Math.min(vSize, i); sub++) {
                    subProfit0[i] = Math.max(
                        subProfit0[i],
                        subProfit0[i - sub] + subDp0[sub],
                    );
                    subProfit1[i] = Math.max(
                        subProfit1[i],
                        subProfit1[i - sub] + subDp1[sub],
                    );
                }
            }
        }

        for (let i = 0; i <= budget; i++) {
            dp0[i] = dp1[i] = subProfit0[i];

            if (i >= dCost) {
                dp1[i] = Math.max(
                    subProfit0[i],
                    subProfit1[i - dCost] + future[u] - dCost,
                );
            }

            if (i >= cost) {
                dp0[i] = Math.max(
                    subProfit0[i],
                    subProfit1[i - cost] + future[u] - cost,
                );
            }
        }

        return [dp0, dp1, uSize] as const;
    };

    return dfs(0)[0][budget];
}
```

</details>
