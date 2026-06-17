# 2977. Minimum Cost to Convert String II

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/minimum-cost-to-convert-string-ii/)  
`Array` `String` `Dynamic Programming` `Graph Theory` `Trie` `Shortest Path`

**Problem Link:** [LeetCode 2977 - Minimum Cost to Convert String II](https://leetcode.com/problems/minimum-cost-to-convert-string-ii/)

## Problem

You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English characters. You are also given two 0-indexed string arrays original and changed, and an integer array cost, where cost[i] represents the cost of converting the string original[i] to the string changed[i].

You start with the string source. In one operation, you can pick a substring x from the string, and change it to y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y. You are allowed to do any number of operations, but any pair of operations must satisfy either of these two conditions:

- The substrings picked in the operations are source[a..b] and source[c..d] with either b < c or d < a. In other words, the indices picked in both operations are disjoint.
- The substrings picked in the operations are source[a..b] and source[c..d] with a == c and b == d. In other words, the indices picked in both operations are identical.

Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

### Example 1

```text
Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
Output: 28
Explanation: To convert "abcd" to "acbe", do the following operations:
- Change substring source[1..1] from "b" to "c" at a cost of 5.
- Change substring source[2..2] from "c" to "e" at a cost of 1.
- Change substring source[2..2] from "e" to "b" at a cost of 2.
- Change substring source[3..3] from "d" to "e" at a cost of 20.
The total cost incurred is 5 + 1 + 2 + 20 = 28.
It can be shown that this is the minimum possible cost.
```

### Example 2

```text
Input: source = "abcdefgh", target = "acdeeghh", original = ["bcd","fgh","thh"], changed = ["cde","thh","ghh"], cost = [1,3,5]
Output: 9
Explanation: To convert "abcdefgh" to "acdeeghh", do the following operations:
- Change substring source[1..3] from "bcd" to "cde" at a cost of 1.
- Change substring source[5..7] from "fgh" to "thh" at a cost of 3. We can do this operation because indices [5,7] are disjoint with indices picked in the first operation.
- Change substring source[5..7] from "thh" to "ghh" at a cost of 5. We can do this operation because indices [5,7] are disjoint with indices picked in the first operation, and identical with indices picked in the second operation.
The total cost incurred is 1 + 3 + 5 = 9.
It can be shown that this is the minimum possible cost.
```

### Example 3

```text
Input: source = "abcdefgh", target = "addddddd", original = ["bcd","defgh"], changed = ["ddd","ddddd"], cost = [100,1578]
Output: -1
Explanation: It is impossible to convert "abcdefgh" to "addddddd".
If you select substring source[1..3] as the first operation to change "abcdefgh" to "adddefgh", you cannot select substring source[3..7] as the second operation because it has a common index, 3, with the first operation.
If you select substring source[3..7] as the first operation to change "abcdefgh" to "abcddddd", you cannot select substring source[1..3] as the second operation because it has a common index, 3, with the first operation.
```

## Constraints

- 1 <= source.length == target.length <= 1000
- source, target consist only of lowercase English characters.
- 1 <= cost.length == original.length == changed.length <= 100
- 1 <= original[i].length == changed[i].length <= source.length
- original[i], changed[i] consist only of lowercase English characters.
- original[i] != changed[i]
- 1 <= cost[i] <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Can Convert String in K Moves](https://leetcode.com/problems/can-convert-string-in-k-moves/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Moves to Convert String](https://leetcode.com/problems/minimum-moves-to-convert-string/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Minimum Number of Valid Strings to Form Target II](https://leetcode.com/problems/minimum-number-of-valid-strings-to-form-target-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Minimum Number of Valid Strings to Form Target I](https://leetcode.com/problems/minimum-number-of-valid-strings-to-form-target-i/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2977. Minimum Cost to Convert String II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Trie + Floyd's Algorithm + Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Trie + Floyd's Algorithm + Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define INF (INT_MAX / 2)

typedef struct Trie {
    struct Trie* child[26];
    int id;
} Trie;

Trie* createTrie() {
    Trie* node = (Trie*)malloc(sizeof(Trie));
    for (int i = 0; i < 26; i++) {
        node->child[i] = NULL;
    }
    node->id = -1;
    return node;
}

int add(Trie* node, const char* word, int* index) {
    for (int i = 0; word[i]; i++) {
        int ch = word[i] - 'a';
        if (!node->child[ch]) {
            node->child[ch] = createTrie();
        }
        node = node->child[ch];
    }
    if (node->id == -1) {
        node->id = ++(*index);
    }
    return node->id;
}

void update(long long* x, long long y) {
    if (*x == -1 || y < *x) {
        *x = y;
    }
}

long long minimumCost(char* source, char* target, char** original,
                      int originalSize, char** changed, int changedSize,
                      int* cost, int costSize) {
    int n = strlen(source);
    int m = originalSize;
    Trie* root = createTrie();

    int p = -1;
    int nodeCount = m * 2;
    int** G = (int**)malloc(nodeCount * sizeof(int*));
    for (int i = 0; i < nodeCount; i++) {
        G[i] = (int*)malloc(nodeCount * sizeof(int));
        for (int j = 0; j < nodeCount; j++) {
            G[i][j] = INF;
        }
        G[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int x = add(root, original[i], &p);
        int y = add(root, changed[i], &p);
        G[x][y] = fmin(G[x][y], cost[i]);
    }

    for (int k = 0; k <= p; k++) {
        for (int i = 0; i <= p; i++) {
            for (int j = 0; j <= p; j++) {
                G[i][j] = fmin(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    long long* f = (long long*)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        f[i] = -1;
    }
    for (int j = 0; j < n; j++) {
        if (j > 0 && f[j - 1] == -1) {
            continue;
        }

        long long base = (j == 0 ? 0 : f[j - 1]);
        if (source[j] == target[j]) {
            update(&f[j], base);
        }

        Trie* u = root;
        Trie* v = root;
        for (int i = j; i < n; i++) {
            u = u->child[source[i] - 'a'];
            v = v->child[target[i] - 'a'];
            if (!u || !v) {
                break;
            }
            if (u->id != -1 && v->id != -1 && G[u->id][v->id] != INF) {
                update(&f[i], base + G[u->id][v->id]);
            }
        }
    }

    long long result = f[n - 1];
    for (int i = 0; i < nodeCount; i++) {
        free(G[i]);
    }
    free(G);
    free(f);

    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
struct Trie {
    Trie* child[26];
    int id;

    Trie() {
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }
        id = -1;
    }
};

int add(Trie* node, const string& word, int& index) {
    for (char ch : word) {
        int i = ch - 'a';
        if (!node->child[i]) {
            node->child[i] = new Trie();
        }
        node = node->child[i];
    }
    if (node->id == -1) {
        node->id = ++index;
    }
    return node->id;
}

void update(long long& x, long long y) {
    if (x == -1 || y < x) {
        x = y;
    }
}

class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<string>& original, vector<string>& changed,
                          vector<int>& cost) {
        int n = source.size();
        int m = original.size();
        Trie* root = new Trie();

        int p = -1;
        vector<vector<int>> G(m * 2, vector<int>(m * 2, inf));
        for (int i = 0; i < m * 2; ++i) {
            G[i][i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            int x = add(root, original[i], p);
            int y = add(root, changed[i], p);
            G[x][y] = min(G[x][y], cost[i]);
        }

        for (int k = 0; k <= p; ++k) {
            for (int i = 0; i <= p; ++i) {
                for (int j = 0; j <= p; ++j) {
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }

        vector<long long> f(n, -1);
        for (int j = 0; j < n; ++j) {
            if (j > 0 && f[j - 1] == -1) {
                continue;
            }
            long long base = (j == 0 ? 0 : f[j - 1]);
            if (source[j] == target[j]) {
                update(f[j], base);
            }
            Trie* u = root;
            Trie* v = root;
            for (int i = j; i < n; ++i) {
                u = u->child[source[i] - 'a'];
                v = v->child[target[i] - 'a'];
                if (!u || !v) {
                    break;
                }
                if (u->id != -1 && v->id != -1 && G[u->id][v->id] != inf) {
                    update(f[i], base + G[u->id][v->id]);
                }
            }
        }
        return f[n - 1];
    }

private:
    static constexpr int inf = INT_MAX / 2;
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Trie {
    public Trie[] child = new Trie[26];
    public int id = -1;
}

public class Solution {
    private const int INF = int.MaxValue / 2;

    private int Add(Trie node, string word, ref int index) {
        foreach (char ch in word) {
            int i = ch - 'a';
            if (node.child[i] == null) {
                node.child[i] = new Trie();
            }
            node = node.child[i];
        }
        if (node.id == -1) {
            node.id = ++index;
        }
        return node.id;
    }

    private void Update(ref long x, long y) {
        if (x == -1 || y < x) {
            x = y;
        }
    }

    public long MinimumCost(string source, string target, string[] original,
                            string[] changed, int[] cost) {
        int n = source.Length;
        int m = original.Length;
        Trie root = new Trie();

        int p = -1;
        int[,] G = new int[m * 2, m * 2];

        for (int i = 0; i < m * 2; i++) {
            for (int j = 0; j < m * 2; j++) {
                G[i, j] = INF;
            }
            G[i, i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int x = Add(root, original[i], ref p);
            int y = Add(root, changed[i], ref p);
            G[x, y] = Math.Min(G[x, y], cost[i]);
        }

        int size = p + 1;
        for (int k = 0; k < size; k++) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    G[i, j] = Math.Min(G[i, j], G[i, k] + G[k, j]);
                }
            }
        }

        long[] f = new long[n];
        Array.Fill(f, -1);
        for (int j = 0; j < n; j++) {
            if (j > 0 && f[j - 1] == -1) {
                continue;
            }
            long baseVal = (j == 0 ? 0 : f[j - 1]);
            if (source[j] == target[j]) {
                Update(ref f[j], baseVal);
            }

            Trie u = root;
            Trie v = root;
            for (int i = j; i < n; i++) {
                u = u.child[source[i] - 'a'];
                v = v.child[target[i] - 'a'];
                if (u == null || v == null) {
                    break;
                }
                if (u.id != -1 && v.id != -1 && G[u.id, v.id] != INF) {
                    long newVal = baseVal + G[u.id, v.id];
                    Update(ref f[i], newVal);
                }
            }
        }

        return f[n - 1];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type Trie struct {
    child [26]*Trie
    id    int
}

func newTrie() *Trie {
    return &Trie{id: -1}
}

func add(node *Trie, word string, index *int) int {
    for _, ch := range word {
        i := ch - 'a'
        if node.child[i] == nil {
            node.child[i] = newTrie()
        }
        node = node.child[i]
    }
    if node.id == -1 {
        *index++
        node.id = *index
    }
    return node.id
}

func update(x *int64, y int64) {
    if *x == -1 || y < *x {
        *x = y
    }
}

func minimumCost(source string, target string, original []string, changed []string, cost []int) int64 {
    n := len(source)
    m := len(original)
    root := newTrie()
    
    p := -1
    nodeCount := m * 2
    G := make([][]int, nodeCount)
    for i := range G {
        G[i] = make([]int, nodeCount)
        for j := range G[i] {
            G[i][j] = math.MaxInt32 / 2
        }
        G[i][i] = 0
    }
    
    for i := 0; i < m; i++ {
        x := add(root, original[i], &p)
        y := add(root, changed[i], &p)
        G[x][y] = min(G[x][y], cost[i])
    }
    
    size := p + 1
    for k := 0; k < size; k++ {
        for i := 0; i < size; i++ {
            for j := 0; j < size; j++ {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j])
            }
        }
    }
    
    f := make([]int64, n)
    for i := range f {
        f[i] = -1
    }
    
    for j := 0; j < n; j++ {
        if j > 0 && f[j - 1] == -1 {
            continue
        }
        
        var base int64
        if j == 0 {
            base = 0
        } else {
            base = f[j-1]
        }
        
        if source[j] == target[j] {
            update(&f[j], base)
        }
        
        u, v := root, root
        for i := j; i < n; i++ {
            u = u.child[source[i] - 'a']
            v = v.child[target[i] - 'a']
            if u == nil || v == nil {
                break
            }
            if u.id != -1 && v.id != -1 && G[u.id][v.id] != math.MaxInt32/2 {
                newVal := base + int64(G[u.id][v.id])
                update(&f[i], newVal)
            }
        }
    }
    
    return f[n - 1]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Trie {

    Trie[] child = new Trie[26];
    int id = -1;
}

class Solution {

    private static final int INF = Integer.MAX_VALUE / 2;

    private int add(Trie node, String word, int[] index) {
        for (char ch : word.toCharArray()) {
            int i = ch - 'a';
            if (node.child[i] == null) {
                node.child[i] = new Trie();
            }
            node = node.child[i];
        }
        if (node.id == -1) {
            node.id = ++index[0];
        }
        return node.id;
    }

    private void update(long[] x, long y) {
        if (x[0] == -1 || y < x[0]) {
            x[0] = y;
        }
    }

    public long minimumCost(
        String source,
        String target,
        String[] original,
        String[] changed,
        int[] cost
    ) {
        int n = source.length();
        int m = original.length;
        Trie root = new Trie();

        int[] p = { -1 };
        int[][] G = new int[m * 2][m * 2];

        for (int i = 0; i < m * 2; i++) {
            Arrays.fill(G[i], INF);
            G[i][i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int x = add(root, original[i], p);
            int y = add(root, changed[i], p);
            G[x][y] = Math.min(G[x][y], cost[i]);
        }

        int size = p[0] + 1;
        for (int k = 0; k < size; k++) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    G[i][j] = Math.min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }

        long[] f = new long[n];
        Arrays.fill(f, -1);
        for (int j = 0; j < n; j++) {
            if (j > 0 && f[j - 1] == -1) {
                continue;
            }
            long base = (j == 0 ? 0 : f[j - 1]);
            if (source.charAt(j) == target.charAt(j)) {
                f[j] = f[j] == -1 ? base : Math.min(f[j], base);
            }

            Trie u = root;
            Trie v = root;
            for (int i = j; i < n; i++) {
                u = u.child[source.charAt(i) - 'a'];
                v = v.child[target.charAt(i) - 'a'];
                if (u == null || v == null) {
                    break;
                }
                if (u.id != -1 && v.id != -1 && G[u.id][v.id] != INF) {
                    long newVal = base + G[u.id][v.id];
                    if (f[i] == -1 || newVal < f[i]) {
                        f[i] = newVal;
                    }
                }
            }
        }

        return f[n - 1];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class Trie {
    constructor() {
        this.child = new Array(26).fill(null);
        this.id = -1;
    }
}

function minimumCost(source, target, original, changed, cost) {
    const INF = Number.MAX_SAFE_INTEGER / 2;

    function add(node, word, index) {
        for (const ch of word) {
            const i = ch.charCodeAt(0) - "a".charCodeAt(0);
            if (!node.child[i]) {
                node.child[i] = new Trie();
            }
            node = node.child[i];
        }
        if (node.id === -1) {
            node.id = ++index.value;
        }
        return node.id;
    }

    const n = source.length;
    const m = original.length;
    const root = new Trie();

    const p = { value: -1 };
    const nodeCount = m * 2;
    const G = Array.from({ length: nodeCount }, () =>
        Array(nodeCount).fill(INF),
    );
    for (let i = 0; i < nodeCount; i++) {
        G[i][i] = 0;
    }
    for (let i = 0; i < m; i++) {
        const x = add(root, original[i], p);
        const y = add(root, changed[i], p);
        G[x][y] = Math.min(G[x][y], cost[i]);
    }

    const size = p.value + 1;
    for (let k = 0; k < size; k++) {
        for (let i = 0; i < size; i++) {
            for (let j = 0; j < size; j++) {
                G[i][j] = Math.min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    const f = new Array(n).fill(-1);
    for (let j = 0; j < n; j++) {
        if (j > 0 && f[j - 1] === -1) {
            continue;
        }
        const base = j === 0 ? 0 : f[j - 1];
        if (source[j] === target[j]) {
            if (f[j] === -1 || base < f[j]) {
                f[j] = base;
            }
        }

        let u = root;
        let v = root;
        for (let i = j; i < n; i++) {
            u = u.child[source.charCodeAt(i) - "a".charCodeAt(0)];
            v = v.child[target.charCodeAt(i) - "a".charCodeAt(0)];
            if (!u || !v) {
                break;
            }
            if (u.id !== -1 && v.id !== -1 && G[u.id][v.id] !== INF) {
                const newVal = base + G[u.id][v.id];
                if (f[i] === -1 || newVal < f[i]) {
                    f[i] = newVal;
                }
            }
        }
    }

    return f[n - 1];
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
INF = 10**18
INF_INT = 10**9


class Solution:
    def minimumCost(
        self,
        source: str,
        target: str,
        original: List[str],
        changed: List[str],
        cost: List[int],
    ) -> int:
        n = len(source)
        m = len(original)

        child = [[-1] * 26]
        tid = [-1]

        def new_node() -> int:
            child.append([-1] * 26)
            tid.append(-1)
            return len(child) - 1

        idx = -1

        def add(word: str) -> int:
            nonlocal idx
            node = 0
            for ch in word:
                c = ord(ch) - 97
                nxt = child[node][c]
                if nxt == -1:
                    nxt = new_node()
                    child[node][c] = nxt
                node = nxt
            if tid[node] == -1:
                idx += 1
                tid[node] = idx
            return tid[node]

        edges = []
        for i in range(m):
            x = add(original[i])
            y = add(changed[i])
            edges.append((x, y, cost[i]))

        P = idx + 1
        if P == 0:
            return 0 if source == target else -1

        dist = [[INF_INT] * P for _ in range(P)]
        for i in range(P):
            dist[i][i] = 0
        for x, y, w in edges:
            if w < dist[x][y]:
                dist[x][y] = w

        for k in range(P):
            dk = dist[k]
            for i in range(P):
                di = dist[i]
                dik = di[k]
                if dik == INF_INT:
                    continue
                base = dik
                for j in range(P):
                    nd = base + dk[j]
                    if nd < di[j]:
                        di[j] = nd

        dp = [INF] * (n + 1)
        dp[0] = 0

        s_arr = [ord(c) - 97 for c in source]
        t_arr = [ord(c) - 97 for c in target]

        for j in range(n):
            if dp[j] >= INF:
                continue

            base = dp[j]

            if source[j] == target[j] and base < dp[j + 1]:
                dp[j + 1] = base

            u = 0
            v = 0
            for i in range(j, n):
                u = child[u][s_arr[i]]
                v = child[v][t_arr[i]]
                if u == -1 or v == -1:
                    break
                uid = tid[u]
                vid = tid[v]
                if uid != -1 and vid != -1:
                    w = dist[uid][vid]
                    if w != INF_INT:
                        ni = i + 1
                        cand = base + w
                        if cand < dp[ni]:
                            dp[ni] = cand

        ans = dp[n]
        return -1 if ans >= INF else ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class Trie {
    child: (Trie | null)[];
    id: number;

    constructor() {
        this.child = new Array(26).fill(null);
        this.id = -1;
    }
}

function minimumCost(
    source: string,
    target: string,
    original: string[],
    changed: string[],
    cost: number[],
): number {
    const INF: number = Number.MAX_SAFE_INTEGER / 2;

    function add(node: Trie, word: string, index: { value: number }): number {
        for (const ch of word) {
            const i = ch.charCodeAt(0) - "a".charCodeAt(0);
            if (!node.child[i]) {
                node.child[i] = new Trie();
            }
            node = node.child[i]!;
        }
        if (node.id === -1) {
            node.id = ++index.value;
        }
        return node.id;
    }

    const n: number = source.length;
    const m: number = original.length;
    const root: Trie = new Trie();

    const p = { value: -1 };
    const nodeCount: number = m * 2;
    const G: number[][] = Array.from({ length: nodeCount }, () =>
        Array(nodeCount).fill(INF),
    );
    for (let i = 0; i < nodeCount; i++) {
        G[i][i] = 0;
    }

    for (let i = 0; i < m; i++) {
        const x: number = add(root, original[i], p);
        const y: number = add(root, changed[i], p);
        G[x][y] = Math.min(G[x][y], cost[i]);
    }

    const size: number = p.value + 1;
    for (let k = 0; k < size; k++) {
        for (let i = 0; i < size; i++) {
            for (let j = 0; j < size; j++) {
                G[i][j] = Math.min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    const f: number[] = new Array(n).fill(-1);
    for (let j = 0; j < n; j++) {
        if (j > 0 && f[j - 1] === -1) {
            continue;
        }
        const base: number = j === 0 ? 0 : f[j - 1];
        if (source[j] === target[j]) {
            if (f[j] === -1 || base < f[j]) {
                f[j] = base;
            }
        }

        let u: Trie | null = root;
        let v: Trie | null = root;
        for (let i = j; i < n; i++) {
            u = u?.child[source.charCodeAt(i) - "a".charCodeAt(0)] ?? null;
            v = v?.child[target.charCodeAt(i) - "a".charCodeAt(0)] ?? null;
            if (!u || !v) {
                break;
            }
            if (u.id !== -1 && v.id !== -1 && G[u.id][v.id] !== INF) {
                const newVal: number = base + G[u.id][v.id];
                if (f[i] === -1 || newVal < f[i]) {
                    f[i] = newVal;
                }
            }
        }
    }

    return f[n - 1];
}
```

</details>
