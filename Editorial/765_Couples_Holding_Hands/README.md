# 765. Couples Holding Hands

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/couples-holding-hands/)  
`Greedy` `Depth-First Search` `Breadth-First Search` `Union-Find` `Graph Theory`

**Problem Link:** [LeetCode 765 - Couples Holding Hands](https://leetcode.com/problems/couples-holding-hands/)

## Problem

There are n couples sitting in 2n seats arranged in a row and want to hold hands.

The people and seats are represented by an integer array row where row[i] is the ID of the person sitting in the ith seat. The couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2n - 2, 2n - 1).

Return the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.

### Example 1

```text
Input: row = [0,2,1,3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
```

### Example 2

```text
Input: row = [3,2,0,1]
Output: 0
Explanation: All couples are already seated side by side.
```

## Constraints

- 2n == row.length
- 2 <= n <= 30​​​​​​​
- 0 <= row[i] < 2n
- All the elements of row are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [First Missing Positive](https://leetcode.com/problems/first-missing-positive/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Missing Number](https://leetcode.com/problems/missing-number/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [K-Similar Strings](https://leetcode.com/problems/k-similar-strings/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 765. Couples Holding Hands

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Backtracking [Time Limit Exceeded] | Java, Python |
| Approach #2: Cycle Finding [Accepted] | Java, Python |
| Approach #3: Greedy [Accepted] | Java, Python |

## Approach #1: Backtracking [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int N;
    int[][] pairs;

    public int minSwapsCouples(int[] row) {
        N = row.length / 2;
        pairs = new int[N][2];
        for (int i = 0; i < N; ++i) {
            pairs[i][0] = row[2*i] / 2;
            pairs[i][1] = row[2*i+1] / 2;
        }

        return solve(0);
    }

    public void swap(int a, int b, int c, int d) {
        int t = pairs[a][b];
        pairs[a][b] = pairs[c][d];
        pairs[c][d] = t;
    }

    public int solve(int i) {
        if (i == N) return 0;
        int x = pairs[i][0], y = pairs[i][1];
        if (x == y) return solve(i+1);

        int jx=0, kx=0, jy=0, ky=0; // Always gets set later
        for (int j = i+1; j < N; ++j) {
            for (int k = 0; k <= 1; ++k) {
                if (pairs[j][k] == x) {jx = j; kx = k;}
                if (pairs[j][k] == y) {jy = j; ky = k;}
            }
        }

        swap(i, 1, jx, kx);
        int ans1 = 1 + solve(i+1);
        swap(i, 1, jx, kx);

        swap(i, 0, jy, ky);
        int ans2 = 1 + solve(i+1);
        swap(i, 0, jy, ky);

        return Math.min(ans1, ans2);
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def minSwapsCouples(self, row):
        N = len(row) / 2
        pairs = [[row[i]/2, row[i+1]/2]
                 for i in xrange(0, 2*N, 2)
                 if row[i]/2 != row[i+1]/2]

        def swap(a, b, c, d):
            pairs[a][b], pairs[c][d] = pairs[c][d], pairs[a][b]

        def solve(i = 0):
            if i == len(pairs): return 0
            x, y = pairs[i]
            if x == y: return solve(i+1)

            for j in xrange(i+1, len(pairs)):
                for k in xrange(2):
                    if pairs[j][k] == x: jx = j, k
                    if pairs[j][k] == y: jy = j, k

            swap(i, 1, *jx)
            ans1 = 1 + solve(i+1)
            swap(i, 1, *jx)

            swap(i, 0, *jy)
            ans2 = 1 + solve(i+1)
            swap(i, 0, *jy)

            return min(ans1, ans2)

        return solve()
```

</details>

<br>

## Approach #2: Cycle Finding [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minSwapsCouples(int[] row) {
        int N = row.length / 2;
        //couples[x] = {i, j} means that
        //couple #x is at couches i and j (1 indexed)
        int[][] couples = new int[N][2];

        for (int i = 0; i < row.length; ++i)
            add(couples[row[i]/2], i/2 + 1);

        //adj[x] = {i, j} means that
        //x-th couch connected to couches i, j (all 1 indexed) by couples
        int[][] adj = new int[N+1][2];
        for (int[] couple: couples) {
            add(adj[couple[0]], couple[1]);
            add(adj[couple[1]], couple[0]);
        }

        // The answer will be N minus the number of cycles in adj.
        int ans = N;
        // For each couch (1 indexed)
        for (int r = 1; r <= N; ++r) {
            // If this couch has no people needing to be paired, continue
            if (adj[r][0] == 0 && adj[r][1] == 0)
                continue;

            // Otherwise, there is a cycle starting at couch r.
            // We will use two pointers x, y with y faster than x by one turn.
            ans--;
            int x = r, y = pop(adj[r]);
            // When y reaches the start 'r', we've reached the end of the cycle.
            while (y != r) {
                // We are at some couch with edges going to 'x' and 'new'.
                // We remove the previous edge, since we came from x.
                rem(adj[y], x);

                // We update x, y appropriately: y becomes new and x becomes y.
                x = y;
                y = pop(adj[y]);
            }
        }
        return ans;
    }

    // Replace the next zero element with x.
    public void add(int[] pair, int x) {
        pair[pair[0] == 0 ? 0 : 1] = x;
    }

    // Remove x from pair, replacing it with zero.
    public void rem(int[] pair, int x) {
        pair[pair[0] == x ? 0 : 1] = 0;
    }

    // Remove the next non-zero element from pair, replacing it with zero.
    public int pop(int[] pair) {
        int x = pair[0];
        if (x != 0) {
            pair[0] = 0;
        } else {
            x = pair[1];
            pair[1] = 0;
        }
        return x;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def minSwapsCouples(self, row):
        N = len(row) / 2

        #couples[x] = [i, j]:
        #x-th couple is at couches i and j
        couples = [[] for _ in xrange(N)]
        for i, x in enumerate(row):
            couples[x/2].append(i/2)
        #adj[x] = [i, j]
        #x-th couch connected to couches i, j by couples
        adj = [[] for _ in xrange(N)]
        for x, y in couples:
            adj[x].append(y)
            adj[y].append(x)
        #Answer is N minus the number of cycles in "adj"
        ans = N
        for start in xrange(N):
            if not adj[start]: continue
            ans -= 1
            x, y = start, adj[start].pop()
            while y != start:
                adj[y].remove(x)
                x, y = y, adj[y].pop()
        return ans
```

</details>

<br>

## Approach #3: Greedy [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minSwapsCouples(int[] row) {
        int ans = 0;
        for (int i = 0; i < row.length; i += 2) {
            int x = row[i];
            if (row[i+1] == (x ^ 1)) continue;
            ans++;
            for (int j = i+1; j < row.length; ++j) {
                if (row[j] == (x^1)) {
                    row[j] = row[i+1];
                    row[i+1] = x^1;
                    break;
                }
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def minSwapsCouples(self, row):
        ans = 0
        for i in xrange(0, len(row), 2):
            x = row[i]
            if row[i+1] == x^1: continue
            ans += 1
            for j in xrange(i+1, len(row)):
                if row[j] == x^1:
                    row[i+1], row[j] = row[j], row[i+1]
                    break
        return ans
```

</details>
