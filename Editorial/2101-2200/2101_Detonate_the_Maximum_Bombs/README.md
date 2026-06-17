# 2101. Detonate the Maximum Bombs

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/detonate-the-maximum-bombs/)  
`Array` `Math` `Depth-First Search` `Breadth-First Search` `Graph Theory` `Geometry`

**Problem Link:** [LeetCode 2101 - Detonate the Maximum Bombs](https://leetcode.com/problems/detonate-the-maximum-bombs/)

## Problem

You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. This area is in the shape of a circle with the center as the location of the bomb.

The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. xi and yi denote the X-coordinate and Y-coordinate of the location of the ith bomb, whereas ri denotes the radius of its range.

You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range. These bombs will further detonate the bombs that lie in their ranges.

Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed to detonate only one bomb.

### Example 1

```text
Input: bombs = [[2,1,3],[6,1,4]]
Output: 2
Explanation:
The above figure shows the positions and ranges of the 2 bombs.
If we detonate the left bomb, the right bomb will not be affected.
But if we detonate the right bomb, both bombs will be detonated.
So the maximum bombs that can be detonated is max(1, 2) = 2.
```

### Example 2

```text
Input: bombs = [[1,1,5],[10,10,5]]
Output: 1
Explanation:
Detonating either bomb will not detonate the other bomb, so the maximum number of bombs that can be detonated is 1.
```

### Example 3

```text
Input: bombs = [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]
Output: 5
Explanation:
The best bomb to detonate is bomb 0 because:
- Bomb 0 detonates bombs 1 and 2. The red circle denotes the range of bomb 0.
- Bomb 2 detonates bomb 3. The blue circle denotes the range of bomb 2.
- Bomb 3 detonates bomb 4. The green circle denotes the range of bomb 3.
Thus all 5 bombs are detonated.
```

## Constraints

- 1 <= bombs.length <= 100
- bombs[i].length == 3
- 1 <= xi, yi, ri <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minesweeper](https://leetcode.com/problems/minesweeper/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Number of Provinces](https://leetcode.com/problems/number-of-provinces/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Max Area of Island](https://leetcode.com/problems/max-area-of-island/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Rotting Oranges](https://leetcode.com/problems/rotting-oranges/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2101. Detonate the Maximum Bombs

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search, Recursive | Java, Python3 |
| Depth-First Search, Iterative | Java, Python3 |
| Breadth-First Search | Java, Python3 |

## Approach 1: Depth-First Search, Recursive

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maximumDetonation(int[][] bombs) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        int n = bombs.length;

        // Build the graph
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                int xi = bombs[i][0], yi = bombs[i][1], ri = bombs[i][2];
                int xj = bombs[j][0], yj = bombs[j][1];

                // Create a path from node i to node j, if bomb i detonates bomb j.
                if ((long)ri * ri >= (long)(xi - xj) * (xi - xj) + (long)(yi - yj) * (yi - yj)) {
                    graph.computeIfAbsent(i, k -> new ArrayList<>()).add(j);
                }
            }
        }

        int answer = 0;
        for (int i = 0; i < n; i++) {
            int count = dfs(i, new HashSet<>(), graph);
            answer = Math.max(answer, count);
        }

        return answer;
    }

    // DFS to get the number of nodes reachable from a given node cur
    private int dfs(int cur, Set<Integer> visited, Map<Integer, List<Integer>> graph) {
        visited.add(cur);
        int count = 1;
        for (int neib : graph.getOrDefault(cur, new ArrayList<>())) {
            if (!visited.contains(neib)) {
                count += dfs(neib, visited, graph);
            }
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        graph = collections.defaultdict(list)
        n = len(bombs)
        
        # Build the graph
        for i in range(n):
            for j in range(n):
                if i == j:
                    continue         
                xi, yi, ri = bombs[i]
                xj, yj, _ = bombs[j]

                # Create a path from node i to node j, if bomb i detonates bomb j.
                if ri ** 2 >= (xi - xj) ** 2 + (yi - yj) ** 2:
                    graph[i].append(j)

        # DFS to get the number of nodes reachable from a given node cur
        def dfs(cur, visited):
            visited.add(cur)
            for neib in graph[cur]:
                if neib not in visited:
                    dfs(neib, visited)
            return len(visited)
        
        answer = 0
        for i in range(n):
            visited = set()
            answer = max(answer, dfs(i, visited))
        
        return answer
```

</details>

<br>

## Approach 2: Depth-First Search, Iterative

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maximumDetonation(int[][] bombs) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        int n = bombs.length;
        
        // Build the graph
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                int xi = bombs[i][0], yi = bombs[i][1], ri = bombs[i][2];
                int xj = bombs[j][0], yj = bombs[j][1];

                // Create a path from node i to node j, if bomb i detonates bomb j.
                if ((long)ri * ri >= (long)(xi - xj) * (xi - xj) + (long)(yi - yj) * (yi - yj)) {
                    graph.computeIfAbsent(i, k -> new ArrayList<>()).add(j);
                }
            }
        }
        
        int answer = 0;
        for (int i = 0; i < n; i++) {
            answer = Math.max(answer, dfs(i, graph));
        }
        
        return answer;
    }
    
    private int dfs(int i, Map<Integer, List<Integer>> graph) {
        Stack<Integer> stack = new Stack<>();
        Set<Integer> visited = new HashSet<>();
        stack.push(i);
        visited.add(i);
        while (!stack.isEmpty()) {
            int cur = stack.pop();
            for (int neib : graph.getOrDefault(cur, new ArrayList<>())) {
                if (!visited.contains(neib)) {
                    visited.add(neib);
                    stack.push(neib);
                }
            }
        }
        return visited.size();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        graph = collections.defaultdict(list)
        n = len(bombs)
        
        # Build the graph
        for i in range(n):
            for j in range(n):
                xi, yi, ri = bombs[i]
                xj, yj, _ = bombs[j]
                
                # Create a path from i to j, if bomb i detonates bomb j.
                if ri ** 2 >= (xi - xj) ** 2 + (yi - yj) ** 2:
                    graph[i].append(j)
        
        def dfs(i):
            stack = [i]
            visited = set([i])
            while stack:
                cur = stack.pop()
                for neib in graph[cur]:
                    if neib not in visited:
                        visited.add(neib)
                        stack.append(neib)
            return len(visited)
        
        answer = 0
        for i in range(n):
            answer = max(answer, dfs(i))
        
        return answer
```

</details>

<br>

## Approach 3: Breadth-First Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maximumDetonation(int[][] bombs) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        int n = bombs.length;
        
        // Build the graph
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int xi = bombs[i][0], yi = bombs[i][1], ri = bombs[i][2];
                int xj = bombs[j][0], yj = bombs[j][1];
                
                // Create a path from node i to node j, if bomb i detonates bomb j.
                if ((long)ri * ri >= (long)(xi - xj) * (xi - xj) + (long)(yi - yj) * (yi - yj)) {
                    graph.computeIfAbsent(i, k -> new ArrayList<>()).add(j);
                }
            }
        }
        
        int answer = 0;
        for (int i = 0; i < n; i++) {
            answer = Math.max(answer, bfs(i, graph));
        }
        
        return answer;
    }
    
    private int bfs(int i, Map<Integer, List<Integer>> graph) {
        Deque<Integer> queue = new ArrayDeque<>();
        Set<Integer> visited = new HashSet<>();
        queue.offer(i);
        visited.add(i);
        while (!queue.isEmpty()) {
            int cur = queue.poll();
            for (int neib : graph.getOrDefault(cur, new ArrayList<>())) {
                if (!visited.contains(neib)) {
                    visited.add(neib);
                    queue.offer(neib);
                }
            }
        }
        return visited.size();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        graph = collections.defaultdict(list)
        n = len(bombs)
        
        # Build the graph
        for i in range(n):
            for j in range(n):
                if i == j:
                    continue
                xi, yi, ri = bombs[i]
                xj, yj, _ = bombs[j]
                
                # Create a path from node i to node j, if bomb i detonates bomb j.
                if ri ** 2 >= (xi - xj) ** 2 + (yi - yj) ** 2:
                    graph[i].append(j)
        
        def bfs(i):
            queue = collections.deque([i])
            visited = set([i])
            while queue:
                cur = queue.popleft()
                for neib in graph[cur]:
                    if neib not in visited:
                        visited.add(neib)
                        queue.append(neib)
            return len(visited)
        
        answer = 0
        for i in range(n):
            answer = max(answer, bfs(i))
        
        return answer
```

</details>
