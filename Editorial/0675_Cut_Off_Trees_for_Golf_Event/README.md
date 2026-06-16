# 675. Cut Off Trees for Golf Event

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/cut-off-trees-for-golf-event/)  
`Array` `Breadth-First Search` `Heap (Priority Queue)` `Matrix`

**Problem Link:** [LeetCode 675 - Cut Off Trees for Golf Event](https://leetcode.com/problems/cut-off-trees-for-golf-event/)

## Problem

You are asked to cut off all the trees in a forest for a golf event. The forest is represented as an m x n matrix. In this matrix:

- 0 means the cell cannot be walked through.
- 1 represents an empty cell that can be walked through.
- A number greater than 1 represents a tree in a cell that can be walked through, and this number is the tree's height.

In one step, you can walk in any of the four directions: north, east, south, and west. If you are standing in a cell with a tree, you can choose whether to cut it off.

You must cut off the trees in order from shortest to tallest. When you cut off a tree, the value at its cell becomes 1 (an empty cell).

Starting from the point (0, 0), return the minimum steps you need to walk to cut off all the trees. If you cannot cut off all the trees, return -1.

Note: The input is generated such that no two trees have the same height, and there is at least one tree needs to be cut off.

### Example 1

```text
Input: forest = [[1,2,3],[0,0,4],[7,6,5]]
Output: 6
Explanation: Following the path above allows you to cut off the trees from shortest to tallest in 6 steps.
```

### Example 2

```text
Input: forest = [[1,2,3],[0,0,0],[7,6,5]]
Output: -1
Explanation: The trees in the bottom row cannot be accessed as the middle row is blocked.
```

### Example 3

```text
Input: forest = [[2,3,4],[0,0,5],[8,7,6]]
Output: 6
Explanation: You can follow the same path as Example 1 to cut off all the trees.
Note that you can cut off the first tree at (0, 0) before making any steps.
```

## Constraints

- m == forest.length
- n == forest[i].length
- 1 <= m, n <= 50
- 0 <= forest[i][j] <= 109
- Heights of all trees are distinct.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 675. Cut Off Trees for Golf Event

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach Framework | Python3 |
| Approach #1: BFS [Accepted] | Python3 |
| Approach #2: A* Search [Accepted] | Python3 |
| Approach #3: Hadlock's Algorithm [Accepted] | Python3, Bash |

## Approach Framework

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def cutOffTree(self, forest):
        trees = sorted((v, r, c) for r, row in enumerate(forest)
                       for c, v in enumerate(row) if v > 1)
        sr = sc = ans = 0
        for _, tr, tc in trees:
            d = dist(forest, sr, sc, tr, tc)
            if d < 0: return -1
            ans += d
            sr, sc = tr, tc
        return ans
```

</details>

<br>

## Approach #1: BFS [Accepted]

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
def bfs(forest, sr, sc, tr, tc):
    R, C = len(forest), len(forest[0])
    queue = collections.deque([(sr, sc, 0)])
    seen = {(sr, sc)}
    while queue:
        r, c, d = queue.popleft()
        if r == tr and c == tc:
            return d
        for nr, nc in ((r-1, c), (r+1, c), (r, c-1), (r, c+1)):
            if (0 <= nr < R and 0 <= nc < C and
                    (nr, nc) not in seen and forest[nr][nc]):
                seen.add((nr, nc))
                queue.append((nr, nc, d+1))
    return -1
```

</details>

<br>

## Approach #2: A* Search [Accepted]

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
def astar(forest, sr, sc, tr, tc):
    R, C = len(forest), len(forest[0])
    heap = [(0, 0, sr, sc)]
    cost = {(sr, sc): 0}
    while heap:
        f, g, r, c = heapq.heappop(heap)
        if r == tr and c == tc: return g
        for nr, nc in ((r-1,c), (r+1,c), (r,c-1), (r,c+1)):
            if 0 <= nr < R and 0 <= nc < C and forest[nr][nc]:
                ncost = g + 1 + abs(nr - tr) + abs(nc - tc)
                if ncost < cost.get((nr, nc), 9999):
                    cost[nr, nc] = ncost
                    heapq.heappush(heap, (ncost, g+1, nr, nc))
    return -1
```

</details>

<br>

## Approach #3: Hadlock's Algorithm [Accepted]

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
def hadlocks(forest, sr, sc, tr, tc):
    R, C = len(forest), len(forest[0])
    processed = set()
    deque = collections.deque([(0, sr, sc)])
    while deque:
        detours, r, c = deque.popleft()
        if (r, c) not in processed:
            processed.add((r, c))
            if r == tr and c == tc:
                return abs(sr-tr) + abs(sc-tc) + 2*detours
            for nr, nc, closer in ((r-1, c, r > tr), (r+1, c, r < tr),
                                   (r, c-1, c > tc), (r, c+1, c < tc)):
                if 0 <= nr < R and 0 <= nc < C and forest[nr][nc]:
                    if closer:
                        deque.appendleft((detours, nr, nc))
                    else:
                        deque.append((detours+1, nr, nc))
    return -1
```

</details>

<details>
<summary><strong>Bash</strong></summary>

```bash
public int hadlocks(List<List<Integer>> forest, int sr, int sc, int tr, int tc) {
    int R = forest.size(), C = forest.get(0).size();
    Set<Integer> processed = new HashSet();
    Deque<int[]> deque = new ArrayDeque();
    deque.offerFirst(new int[]{0, sr, sc});
    while (!deque.isEmpty()) {
        int[] cur = deque.pollFirst();
        int detours = cur[0], r = cur[1], c = cur[2];
        if (!processed.contains(r*C + c)) {
            processed.add(r*C + c);
            if (r == tr && c == tc) {
                return Math.abs(sr-tr) + Math.abs(sc-tc) + 2 * detours;
            }
            for (int di = 0; di < 4; ++di) {
                int nr = r + dr[di];
                int nc = c + dc[di];
                boolean closer;
                if (di <= 1) closer = di == 0 ? r > tr : r < tr;
                else closer = di == 2 ? c > tc : c < tc;
                if (0 <= nr && nr < R && 0 <= nc && nc < C && forest.get(nr).get(nc) > 0) {
                    if (closer) deque.offerFirst(new int[]{detours, nr, nc});
                    else deque.offerLast(new int[]{detours+1, nr, nc});
                }
            }
        }
    }
    return -1;
}
```

</details>
