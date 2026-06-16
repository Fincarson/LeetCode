# 851. Loud and Rich

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/loud-and-rich/)  
`Array` `Depth-First Search` `Graph Theory` `Topological Sort`

**Problem Link:** [LeetCode 851 - Loud and Rich](https://leetcode.com/problems/loud-and-rich/)

## Problem

There is a group of n people labeled from 0 to n - 1 where each person has a different amount of money and a different level of quietness.

You are given an array richer where richer[i] = [ai, bi] indicates that ai has more money than bi and an integer array quiet where quiet[i] is the quietness of the ith person. All the given data in richer are logically correct (i.e., the data will not lead you to a situation where x is richer than y and y is richer than x at the same time).

Return an integer array answer where answer[x] = y if y is the least quiet person (that is, the person y with the smallest value of quiet[y]) among all people who definitely have equal to or more money than the person x.

### Example 1

```text
Input: richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
Output: [5,5,2,5,4,5,6,7]
Explanation:
answer[0] = 5.
Person 5 has more money than 3, which has more money than 1, which has more money than 0.
The only person who is quieter (has lower quiet[x]) is person 7, but it is not clear if they have more money than person 0.
answer[7] = 7.
Among all people that definitely have equal to or more money than person 7 (which could be persons 3, 4, 5, 6, or 7), the person who is the quietest (has lower quiet[x]) is person 7.
The other answers can be filled out with similar reasoning.
```

### Example 2

```text
Input: richer = [], quiet = [0]
Output: [0]
```

## Constraints

- n == quiet.length
- 1 <= n <= 500
- 0 <= quiet[i] < n
- All the values of quiet are unique.
- 0 <= richer.length <= n * (n - 1) / 2
- 0 <= ai, bi < n
- ai != bi
- All the pairs of richer are unique.
- The observations in richer are all logically consistent.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Build a Matrix With Conditions](https://leetcode.com/problems/build-a-matrix-with-conditions/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 851. Loud and Rich

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Cached Depth-First Search [Accepted] | Java, Python |

## Approach #1: Cached Depth-First Search [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    ArrayList<Integer>[] graph;
    int[] answer;
    int[] quiet;

    public int[] loudAndRich(int[][] richer, int[] quiet) {
        int N = quiet.length;
        graph = new ArrayList[N];
        answer = new int[N];
        this.quiet = quiet;

        for (int node = 0; node < N; ++node)
            graph[node] = new ArrayList<Integer>();

        for (int[] edge: richer)
            graph[edge[1]].add(edge[0]);

        Arrays.fill(answer, -1);

        for (int node = 0; node < N; ++node)
            dfs(node);
        return answer;
    }

    public int dfs(int node) {
        if (answer[node] == -1) {
            answer[node] = node;
            for (int child: graph[node]) {
                int cand = dfs(child);
                if (quiet[cand] < quiet[answer[node]])
                    answer[node] = cand;
            }
        }
        return answer[node];
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def loudAndRich(self, richer, quiet):
        N = len(quiet)
        graph = [[] for _ in xrange(N)]
        for u, v in richer:
            graph[v].append(u)

        answer = [None] * N
        def dfs(node):
            #Want least quiet person in this subtree
            if answer[node] is None:
                answer[node] = node
                for child in graph[node]:
                    cand = dfs(child)
                    if quiet[cand] < quiet[answer[node]]:
                        answer[node] = cand
            return answer[node]

        return map(dfs, range(N))
```

</details>
