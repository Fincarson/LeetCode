# 1697. Checking Existence of Edge Length Limited Paths

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/)  
`Array` `Two Pointers` `Union-Find` `Graph Theory` `Sorting`

**Problem Link:** [LeetCode 1697 - Checking Existence of Edge Length Limited Paths](https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/)

## Problem

An undirected graph of n nodes is defined by edgeList, where edgeList[i] = [ui, vi, disi] denotes an edge between nodes ui and vi with distance disi. Note that there may be multiple edges between two nodes.

Given an array queries, where queries[j] = [pj, qj, limitj], your task is to determine for each queries[j] whether there is a path between pj and qj such that each edge on the path has a distance strictly less than limitj .

Return a boolean array answer, where answer.length == queries.length and the jth value of answer is true if there is a path for queries[j] is true, and false otherwise.

### Example 1

```text
Input: n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
Output: [false,true]
Explanation: The above figure shows the given graph. Note that there are two overlapping edges between 0 and 1 with distances 2 and 16.
For the first query, between 0 and 1 there is no path where each distance is less than 2, thus we return false for this query.
For the second query, there is a path (0 -> 1 -> 2) of two edges with distances less than 5, thus we return true for this query.
```

### Example 2

```text
Input: n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
Output: [true,false]
Explanation: The above figure shows the given graph.
```

## Constraints

- 2 <= n <= 105
- 1 <= edgeList.length, queries.length <= 105
- edgeList[i].length == 3
- queries[j].length == 3
- 0 <= ui, vi, pj, qj <= n - 1
- ui != vi
- pj != qj
- 1 <= disi, limitj <= 109
- There may be multiple edges between two nodes.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Checking Existence of Edge Length Limited Paths II](https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Number of Good Paths](https://leetcode.com/problems/number-of-good-paths/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Score of a Path Between Two Cities](https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1697. Checking Existence of Edge Length Limited Paths

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Disjoint-Set Union | C++, Java, JavaScript, Python3 |

## Approach 1: Disjoint-Set Union

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class UnionFind {
public:
    vector<int> group;
    vector<int> rank;

    UnionFind(int size) {
        group = vector<int>(size);
        rank = vector<int>(size);
        for (int i = 0; i < size; ++i) {
            group[i] = i;
        }
    }

    int find(int node) {
        if (group[node] != node) {
            group[node] = find(group[node]);
        }
        return group[node];
    }

    void join(int node1, int node2) {
        int group1 = find(node1);
        int group2 = find(node2);

        // node1 and node2 already belong to same group.
        if (group1 == group2) {
            return;
        }

        if (rank[group1] > rank[group2]) {
            group[group2] = group1;
        } else if (rank[group1] < rank[group2]) {
            group[group1] = group2;
        } else {
            group[group1] = group2;
            rank[group2] += 1;
        }
    }

    bool areConnected(int node1, int node2) {
        int group1 = find(node1);
        int group2 = find(node2);
        return group1 == group2;
    }
};


class Solution {
public:
    // Sort in increasing order based on the 3rd element of the array.
    bool static compare(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        UnionFind uf(n);
        int queriesCount = queries.size();
        vector<bool> answer(queriesCount);

        // Store original indices with all queries.
        vector<vector<int>> queriesWithIndex(queriesCount);
        for (int i = 0; i < queriesCount; ++i) {
            queriesWithIndex[i] = queries[i];
            queriesWithIndex[i].push_back(i);
        }

        int edgesIndex = 0;

        // Sort all edges in increasing order of their edge weights.
        sort(edgeList.begin(), edgeList.end(), compare);
        // Sort all queries in increasing order of the limit of edge allowed.
        sort(queriesWithIndex.begin(), queriesWithIndex.end(), compare);

        // Iterate on each query one by one.
        for (auto& query : queriesWithIndex) {
            int p = query[0];
            int q = query[1];
            int limit = query[2];
            int queryOriginalIndex = query[3];

            // We can attach all edges which satisfy the limit given by the query.
            while (edgesIndex < edgeList.size() && edgeList[edgesIndex][2] < limit) {
                int node1 = edgeList[edgesIndex][0];
                int node2 = edgeList[edgesIndex][1];
                uf.join(node1, node2);
                edgesIndex += 1;
            }

            // If both nodes belong to the same component, it means we can reach them. 
            answer[queryOriginalIndex] = uf.areConnected(p, q);
        }

        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class UnionFind {
    private int[] group;
    private int[] rank;

    UnionFind(int size) {
        group = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; ++i) {
            group[i] = i;
        }
    }

    public int find(int node) {
        if (group[node] != node) {
            group[node] = find(group[node]);
        }
        return group[node];
    }

    public void join(int node1, int node2) {
        int group1 = find(node1);
        int group2 = find(node2);
        
        // node1 and node2 already belong to same group.
        if (group1 == group2) {
            return;
        }

        if (rank[group1] > rank[group2]) {
            group[group2] = group1;
        } else if (rank[group1] < rank[group2]) {
            group[group1] = group2;
        } else {
            group[group1] = group2;
            rank[group2] += 1;
        }
    }
    
    public boolean areConnected(int node1, int node2) {
        int group1 = find(node1);
        int group2 = find(node2);
        return group1 == group2;
    }
};

class Solution {
    // Sort in increasing order based on the 3rd element of the array.
    private void sort(int[][] array) {
        Arrays.sort(array, new Comparator<int[]>() {
          @Override
          public int compare(int[] a, int[] b) {
            return a[2] - b[2];
          }
        });
    }
    
    public boolean[] distanceLimitedPathsExist(int n, int[][] edgeList, int[][] queries) {
        UnionFind uf = new UnionFind(n);
        int queriesCount = queries.length;
        boolean[] answer = new boolean[queriesCount];
        
        // Store original indices with all queries.
        int[][] queriesWithIndex = new int[queriesCount][4];
        for (int i = 0; i < queriesCount; ++i) {
            queriesWithIndex[i][0] = queries[i][0];
            queriesWithIndex[i][1] = queries[i][1];
            queriesWithIndex[i][2] = queries[i][2];
            queriesWithIndex[i][3] = i;
        }
        
        // Sort all edges in increasing order of their edge weights.
        sort(edgeList);
        // Sort all queries in increasing order of the limit of edge allowed.
        sort(queriesWithIndex);
         
        int edgesIndex = 0;
        
        // Iterate on each query one by one.
        for (int queryIndex = 0; queryIndex < queriesCount; queryIndex += 1) {
            int p = queriesWithIndex[queryIndex][0];
            int q = queriesWithIndex[queryIndex][1];
            int limit = queriesWithIndex[queryIndex][2];
            int queryOriginalIndex = queriesWithIndex[queryIndex][3];
            
            // We can attach all edges which satisfy the limit given by the query.
            while (edgesIndex < edgeList.length && edgeList[edgesIndex][2] < limit) {
                int node1 = edgeList[edgesIndex][0];
                int node2 = edgeList[edgesIndex][1];
                uf.join(node1, node2);
                edgesIndex += 1;
            }
            
            // If both nodes belong to the same component, it means we can reach them. 
            answer[queryOriginalIndex] = uf.areConnected(p, q);
        }
        
        return answer;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class UnionFind {
    constructor(size) {
        this.group = [];
        this.rank = [];
        for (let i = 0; i < size; ++i) {
            this.group[i] = i;
        }
    }
  
    find(node) {
        if (this.group[node] !== node) {
            this.group[node] = this.find(this.group[node]);
        }
        return this.group[node];
    }

    join(node1, node2) {
        let group1 = this.find(node1);
        let group2 = this.find(node2);
        
        // node1 and node2 already belong to same group.
        if (group1 === group2) {
            return;
        }

        if (this.rank[group1] > this.rank[group2]) {
            this.group[group2] = group1;
        } else if (this.rank[group1] < this.rank[group2]) {
            this.group[group1] = group2;
        } else {
            this.group[group1] = group2;
            this.rank[group2] += 1;
        }
    }
    
    areConnected(node1, node2) {
        let group1 = this.find(node1);
        let group2 = this.find(node2);
        return group1 === group2;
    }
}

var distanceLimitedPathsExist = function(n, edgeList, queries) {
    let uf = new UnionFind(n);
    let queriesCount = queries.length;
    let answer = new Array(queriesCount);

    // Store original indices with all queries.
    let queriesWithIndex = [];
    for (let i = 0; i < queriesCount; ++i) {
        queriesWithIndex[i] = queries[i];
        queriesWithIndex[i].push(i);
    }

    // Sort all edges in increasing order of their edge weights.
    edgeList.sort((a, b) => a[2] - b[2]);
    // Sort all queries in increasing order of the limit of edge allowed.
    queriesWithIndex.sort((a, b) => a[2] - b[2]);

    let edgesIndex = 0;

    // Iterate on each query one by one.
    queriesWithIndex.forEach(([p, q, limit, queryOriginalIndex]) => {
        // We can attach all edges which satisfy the limit given by the query.
        while (edgesIndex < edgeList.length && edgeList[edgesIndex][2] < limit) {
            let node1 = edgeList[edgesIndex][0];
            let node2 = edgeList[edgesIndex][1];
            uf.join(node1, node2);
            edgesIndex += 1;
        }

        // If both nodes belong to the same component, it means we can reach them. 
        answer[queryOriginalIndex] = uf.areConnected(p, q);
    });

    return answer;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class UnionFind:
    def __init__(self, size: int):
        self.group = [0] * size
        self.rank = [0] * size
        for i in range(size):
            self.group[i] = i

    def find(self, node: int) -> int:
        if self.group[node] != node:
            self.group[node] = self.find(self.group[node])
        return self.group[node]

    def join(self, node1: int, node2: int):
        group1 = self.find(node1)
        group2 = self.find(node2)
        
        # node1 and node2 already belong to same group.
        if group1 == group2:
            return

        if self.rank[group1] > self.rank[group2]:
            self.group[group2] = group1
        elif self.rank[group1] < self.rank[group2]:
            self.group[group1] = group2
        else:
            self.group[group1] = group2
            self.rank[group2] += 1
    
    def are_connected(self, node1: int, node2: int) -> bool:
        return self.find(node1) == self.find(node2)

class Solution:
    def distanceLimitedPathsExist(self, n: int, edge_list: List[List[int]], queries: List[List[int]]) -> List[bool]:
        uf = UnionFind(n)
        queries_count = len(queries)
        answer = [False] * queries_count;
        
        # Store original indices with all queries.
        queries_with_index = [[] for _ in range(queries_count)]
        for i in range(queries_count):
            queries_with_index[i] = queries[i]
            queries_with_index[i].append(i)
        
        # Sort all edges in increasing order of their edge weights.
        edge_list.sort(key=lambda x: x[2])
        # Sort all queries in increasing order of the limit of edge allowed.
        queries_with_index.sort(key=lambda x: x[2])
        
        edges_index = 0
        
        # Iterate on each query one by one.
        for [p, q, limit, query_original_index] in queries_with_index:
            # We can attach all edges which satisfy the limit given by the query.
            while edges_index < len(edge_list) and edge_list[edges_index][2] < limit:
                node1 = edge_list[edges_index][0]
                node2 = edge_list[edges_index][1]
                uf.join(node1, node2)
                edges_index += 1
            
            # If both nodes belong to the same component, it means we can reach them. 
            answer[query_original_index] = uf.are_connected(p, q)

        return answer
```

</details>
