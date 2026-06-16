# 1135. Connecting Cities With Minimum Cost

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/connecting-cities-with-minimum-cost/)  
`Union-Find` `Graph Theory` `Heap (Priority Queue)` `Minimum Spanning Tree`

**Problem Link:** [LeetCode 1135 - Connecting Cities With Minimum Cost](https://leetcode.com/problems/connecting-cities-with-minimum-cost/)

## Problem

There are n cities labeled from 1 to n. You are given the integer n and an array connections where connections[i] = [xi, yi, costi] indicates that the cost of connecting city xi and city yi (bidirectional connection) is costi.

Return the minimum cost to connect all the n cities such that there is at least one path between each pair of cities. If it is impossible to connect all the n cities, return -1,

The cost is the sum of the connections' costs used.

### Example 1

```text
Input: n = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
Output: 6
Explanation: Choosing any 2 edges will connect all cities so we choose the minimum 2.
```

### Example 2

```text
Input: n = 4, connections = [[1,2,3],[3,4,4]]
Output: -1
Explanation: There is no way to connect all cities even if all edges are used.
```

## Constraints

- 1 <= n <= 104
- 1 <= connections.length <= 104
- connections[i].length == 3
- 1 <= xi, yi <= n
- xi != yi
- 0 <= costi <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Cost to Reach City With Discounts](https://leetcode.com/problems/minimum-cost-to-reach-city-with-discounts/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1135. Connecting Cities With Minimum Cost

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Minimum Spanning Tree (Using Kruskal's algorithm) | C++, Java |

## Approach 1: Minimum Spanning Tree (Using Kruskal's algorithm)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
/** Vanilla Disjoint-set Union Find **/
class DisjointSet {
private:
    vector<int> parents;

public:
    void Union(int a, int b) {
        int rootA = Find(a);
        int rootB = Find(b);
        // If both a and b have same root, i.e. they both belong to the same set, hence we don't need to take union
        if (rootA == rootB) return;
        // Take union by assigning rootA as the parent of rootB
        this->parents[rootB] = rootA;
    }

    int Find(int a) {
        // Traverse all the way to the top (root) going through the parent nodes
        while (a != this->parents[a]) {
            a = this->parents[a];
        }
        return a;
    }

    bool isInSameGroup(int a, int b) {
        // Return true if both a and b belong to the same set, otherwise return false
        return Find(a) == Find(b);
    }

    DisjointSet(int N) {
        this->parents.resize(N + 1);
        // Set the initial parent node to itself
        for (int i = 1; i <= N; ++i) {
            this->parents[i] = i;
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/** Vanilla Disjoint-set Union Find **/
class DisjointSet {
    private int[] parents;

    public void Union(int a, int b) {
        int rootA = Find(a);
        int rootB = Find(b);
        // If both a and b have same root, i.e. they both belong to the same set, hence we don't need to take union
        if (rootA == rootB) return;
        // Take union by assigning rootA as the parent of rootB
        this.parents[rootB] = rootA;
    }

    public int Find(int a) {
        // Traverse all the way to the top (root) going through the parent nodes
        while (a != this.parents[a]) {
            a = this.parents[a];
        }
        return a;
    }

    public boolean isInSameGroup(int a, int b) {
        // Return true if both a and b belong to the same set, otherwise return false
        return Find(a) == Find(b);
    }

    public DisjointSet(int N) {
        this.parents = new int[N + 1];
        // Set the initial parent node to itself
        for (int i = 1; i <= N; ++i) {
            this.parents[i] = i;
        }
    }
}
```

</details>
