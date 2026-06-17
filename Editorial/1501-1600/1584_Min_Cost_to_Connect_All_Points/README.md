# 1584. Min Cost to Connect All Points

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/min-cost-to-connect-all-points/)  
`Array` `Union-Find` `Graph Theory` `Minimum Spanning Tree`

**Problem Link:** [LeetCode 1584 - Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/)

## Problem

You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

### Example 1

```text
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
```

### Example 2

```text
Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
```

## Constraints

- 1 <= points.length <= 1000
- -106 <= xi, yi <= 106
- All pairs (xi, yi) are distinct.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Number of Lines to Cover Points](https://leetcode.com/problems/minimum-number-of-lines-to-cover-points/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1584. Min Cost to Connect All Points

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Kruskal's Algorithm | C++, Java, JavaScript, Python3 |
| Prim's Algorithm | C++, Java, JavaScript, Python3 |
| Prim's Algorithm (Optimized) | C++, Java, JavaScript, Python3 |

## Approach 1: Kruskal's Algorithm

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

    bool join(int node1, int node2) {
        int group1 = find(node1);
        int group2 = find(node2);
        
        // node1 and node2 already belong to same group.
        if (group1 == group2) {
            return false;
        }

        if (rank[group1] > rank[group2]) {
            group[group2] = group1;
        } else if (rank[group1] < rank[group2]) {
            group[group1] = group2;
        } else {
            group[group1] = group2;
            rank[group2] += 1;
        }

        return true;
    }
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> allEdges;
        
        // Storing all edges of our complete graph.
        for (int currNode = 0; currNode < n; ++currNode) {
            for (int nextNode = currNode + 1; nextNode < n; ++nextNode) {
                int weight = abs(points[currNode][0] - points[nextNode][0]) + 
                             abs(points[currNode][1] - points[nextNode][1]);
                
                allEdges.push_back({ weight, { currNode, nextNode }});
            }
        }
        
        // Sort all edges in increasing order.
        sort(allEdges.begin(), allEdges.end());
        
        UnionFind uf(n);
        int mstCost = 0;
        int edgesUsed = 0;
        
        for (int i = 0; i < allEdges.size() && edgesUsed < n - 1; ++i) {
            int node1 = allEdges[i].second.first;
            int node2 = allEdges[i].second.second;
            int weight = allEdges[i].first;
            
            if (uf.join(node1, node2)) {
                mstCost += weight;
                edgesUsed++;
            }
        }
        
        return mstCost;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class UnionFind {
    public int[] group;
    public int[] rank;

    public UnionFind(int size) {
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

    public boolean union(int node1, int node2) {
        int group1 = find(node1);
        int group2 = find(node2);
        
        // node1 and node2 already belong to same group.
        if (group1 == group2) {
            return false;
        }

        if (rank[group1] > rank[group2]) {
            group[group2] = group1;
        } else if (rank[group1] < rank[group2]) {
            group[group1] = group2;
        } else {
            group[group1] = group2;
            rank[group2] += 1;
        }

        return true;
    }
}

class Solution {
    public int minCostConnectPoints(int[][] points) {
        int n = points.length;
        ArrayList<int[]> allEdges = new ArrayList<>();
        
        // Storing all edges of our complete graph.
        for (int currNext = 0; currNext < n; ++currNext) {
            for (int nextNext = currNext + 1; nextNext < n; ++nextNext) {
                int weight = Math.abs(points[currNext][0] - points[nextNext][0]) + 
                             Math.abs(points[currNext][1] - points[nextNext][1]);
                
                int[] currEdge = {weight, currNext, nextNext};
                allEdges.add(currEdge);
            }
        }
        
        // Sort all edges in increasing order.
        Collections.sort(allEdges, (a, b) -> Integer.compare(a[0], b[0]));   
        
        UnionFind uf = new UnionFind(n);
        int mstCost = 0;
        int edgesUsed = 0;
        
        for (int i = 0; i < allEdges.size() && edgesUsed < n - 1; ++i) {
            int node1 = allEdges.get(i)[1];
            int node2 = allEdges.get(i)[2];
            int weight = allEdges.get(i)[0];
            
            if (uf.union(node1, node2)) {
                mstCost += weight;
                edgesUsed++;
            }
        }
        
        return mstCost;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class UnionFind {
    constructor(size) {
        this.group = new Array(size).fill(0);
        this.rank = new Array(size).fill(0);
        for (let i = 0; i < size; ++i) {
            this.group[i] = i;
        }
    }

    find(node) {
        if (this.group[node] != node) {
            this.group[node] = this.find(this.group[node]);
        }
        return this.group[node];
    }

    union(node1, node2) {
        let group1 = this.find(node1);
        let group2 = this.find(node2);
        
        // node1 and node2 already belong to same group.
        if (group1 == group2) {
            return false;
        }

        if (this.rank[group1] > this.rank[group2]) {
            this.group[group2] = group1;
        } else if (this.rank[group1] < this.rank[group2]) {
            this.group[group1] = group2;
        } else {
            this.group[group1] = group2;
            this.rank[group2] += 1;
        }

        return true;
    }
};


let minCostConnectPoints = function(points) {
    let n = points.length;
    let allEdges = [];

    // Storing all edges of our complete graph.
    for (let currNode = 0; currNode < n; ++currNode) {
        for (let nextNode = currNode + 1; nextNode < n; ++nextNode) {
            let weight = Math.abs(points[currNode][0] - points[nextNode][0]) + 
                         Math.abs(points[currNode][1] - points[nextNode][1]);

            allEdges.push([weight, currNode, nextNode]);
        }
    }

    // Sort all edges in increasing order.
    allEdges.sort((a, b) => a[0] - b[0]);

    let uf = new UnionFind(n);
    let mstCost = 0;
    let edgesUsed = 0;

    for (let i = 0; i < allEdges.length && edgesUsed < n - 1; ++i) {
        let [weight, node1, node2] = allEdges[i];

        if (uf.union(node1, node2)) {
            mstCost += weight;
            edgesUsed++;
        }
    }

    return mstCost;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class UnionFind:
    def __init__(self, size: int) -> None:
        self.group = [0] * size
        self.rank = [0] * size
        
        for i in range(size):
            self.group[i] = i
      
    def find(self, node: int) -> int:
        if self.group[node] != node:
            self.group[node] = self.find(self.group[node])
        return self.group[node]

    def join(self, node1: int, node2: int) -> bool:
        group1 = self.find(node1)
        group2 = self.find(node2)
        
        # node1 and node2 already belong to same group.
        if group1 == group2:
            return False

        if self.rank[group1] > self.rank[group2]:
            self.group[group2] = group1
        elif self.rank[group1] < self.rank[group2]:
            self.group[group1] = group2
        else:
            self.group[group1] = group2
            self.rank[group2] += 1

        return True
    
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        all_edges = []
        
        # Storing all edges of our complete graph.
        for curr_node in range(n): 
            for next_node in range(curr_node + 1, n): 
                weight = abs(points[curr_node][0] - points[next_node][0]) +\
                         abs(points[curr_node][1] - points[next_node][1])
                all_edges.append((weight, curr_node, next_node))
      
        
        # Sort all edges in increasing order.
        all_edges.sort()
        
        uf = UnionFind(n)
        mst_cost = 0
        edges_used = 0
        
        for weight, node1, node2 in all_edges:
            if uf.join(node1, node2):
                mst_cost += weight
                edges_used += 1
                if edges_used == n - 1:
                    break
        return mst_cost
```

</details>

<br>

## Approach 2: Prim's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        // Min-heap to store minimum weight edge at top.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        
        // Track nodes which are included in MST.
        vector<bool> inMST(n);
        
        heap.push({ 0, 0 });
        int mstCost = 0;
        int edgesUsed = 0;
        
        while (edgesUsed < n) {
            pair<int, int> topElement = heap.top();
            heap.pop();
            
            int weight = topElement.first;
            int currNode = topElement.second;
            
            // If node was already included in MST we will discard this edge.
            if (inMST[currNode]) {
                continue;
            }
            
            inMST[currNode] = true;
            mstCost += weight;
            edgesUsed++;
            
            for (int nextNode = 0; nextNode < n; ++nextNode) {
                // If next node is not in MST, then edge from curr node
                // to next node can be pushed in the priority queue.
                if (!inMST[nextNode]) {
                    int nextWeight = abs(points[currNode][0] - points[nextNode][0]) + 
                                     abs(points[currNode][1] - points[nextNode][1]);
                    
                    heap.push({ nextWeight, nextNode });
                }
            }
        }
        
        return mstCost;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minCostConnectPoints(int[][] points) {
        int n = points.length;
        
        // Min-heap to store minimum weight edge at top.
        PriorityQueue<Pair<Integer, Integer>> heap = new PriorityQueue<>((a, b) -> (a.getKey() - b.getKey()));;
        
        // Track nodes which are included in MST.
        boolean[] inMST = new boolean[n];
        
        heap.add(new Pair(0, 0));
        int mstCost = 0;
        int edgesUsed = 0;
        
        while (edgesUsed < n) {
            Pair<Integer, Integer> topElement = heap.poll();
            
            int weight = topElement.getKey();
            int currNode = topElement.getValue();
            
            // If node was already included in MST we will discard this edge.
            if (inMST[currNode]) {
                continue;
            }
            
            inMST[currNode] = true;
            mstCost += weight;
            edgesUsed++;
            
            for (int nextNode = 0; nextNode < n; ++nextNode) {
                // If next node is not in MST, then edge from curr node
                // to next node can be pushed in the priority queue.
                if (!inMST[nextNode]) {
                    int nextWeight = Math.abs(points[currNode][0] - points[nextNode][0]) + 
                                     Math.abs(points[currNode][1] - points[nextNode][1]);
        
                    heap.add(new Pair(nextWeight, nextNode));
                }
            }
        }
        
        return mstCost;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let minCostConnectPoints = function(points) {
    let n = points.length;
        
    // Min-heap to store minimum weight edge at top.
    let heap = new MinHeap();

    // Track nodes which are included in MST.
    let inMST = Array(n).fill(false);

    heap.insert(0, 0);
    let mstCost = 0;
    let edgesUsed = 0;

    while (edgesUsed < n) {
        let [weight, currNode] = heap.getMin();
        heap.remove();

        // If node was already included in MST we will discard this edge.
        if (inMST[currNode]) {
            continue;
        }

        inMST[currNode] = true;
        mstCost += weight;
        edgesUsed++;

        for (let nextNode = 0; nextNode < n; ++nextNode) {
            // If next node is not in MST, then edge from curr node
            // to next node can be pushed in the priority queue.
            if (!inMST[nextNode]) {
                let nextWeight = Math.abs(points[currNode][0] - points[nextNode][0]) + 
                                 Math.abs(points[currNode][1] - points[nextNode][1]);

                heap.insert(nextWeight, nextNode);
            }
        }
    }

    return mstCost;
};

// Implementing min heap data-structure.
class MinHeap {
    constructor() {
        // Initialing the array heap and adding a dummy element at index 0.
        this.heap = [null];
    }

    getMin() {
        // Accessing the min element at index 1 in the heap array.
        return this.heap[1];
    }
    
    insert(weight, node) {
        // Inserting the new node at the end of the heap array.
        this.heap.push([weight, node]);

        // Finding the correct position for the new node.
        if (this.heap.length > 1) {
            let current = this.heap.length - 1;

            // Traversing up the parent node until the current node (current) is 
            // greater than the parent (current/2).
            while (current > 1 && this.heap[Math.floor(current/2)][0] > this.heap[current][0]) {
                // Swapping the two nodes by using the ES6 destructuring syntax.
                [this.heap[Math.floor(current/2)], this.heap[current]] = [this.heap[current], this.heap[Math.floor(current/2)]];
                current = Math.floor(current/2);
            }
        }
    }
    
    remove() {
        // Smallest element is at the index 1 in the heap array.
        let smallest = this.heap[1];

        // When there are more than two elements in the array, 
        // we put the right most element at the first position and start 
        // comparing nodes with the child nodes/
        if (this.heap.length > 2) {
            this.heap[1] = this.heap[this.heap.length - 1];
            this.heap.splice(this.heap.length - 1);

            if (this.heap.length === 3) {
                if (this.heap[1][0] > this.heap[2][0]) {
                    [this.heap[1], this.heap[2]] = [this.heap[2], this.heap[1]];
                }
                return smallest
            }

            let current = 1;
            let leftChildIndex = current * 2;
            let rightChildIndex = current * 2 + 1;

            while (this.heap[leftChildIndex] && this.heap[rightChildIndex] && 
                   (this.heap[current][0] > this.heap[leftChildIndex][0] || 
                    this.heap[current][0] > this.heap[rightChildIndex][0])) {
                
                if (this.heap[leftChildIndex][0] < this.heap[rightChildIndex][0]) {
                    [this.heap[current], this.heap[leftChildIndex]] = [this.heap[leftChildIndex], this.heap[current]];
                    current = leftChildIndex;
                } else {
                    [this.heap[current], this.heap[rightChildIndex]] = [this.heap[rightChildIndex], this.heap[current]];
                    current = rightChildIndex;
                }

                leftChildIndex = current * 2;
                rightChildIndex = current * 2 + 1;
            }
        }

        // If there are only two elements in the array, 
        // we directly splice out the first element.
        else if (this.heap.length === 2) {
            this.heap.splice(1, 1);
        } else {
            return null;
        }

        return smallest;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        
        # Min-heap to store minimum weight edge at top.
        heap = [(0, 0)]
        
        # Track nodes which are included in MST.
        in_mst = [False] * n
        
        mst_cost = 0
        edges_used = 0
        
        while edges_used < n:
            weight, curr_node = heapq.heappop(heap)
            
            # If node was already included in MST we will discard this edge.
            if in_mst[curr_node]:
                continue
            
            in_mst[curr_node] = True
            mst_cost += weight
            edges_used += 1
            
            for next_node in range(n):
                # If next node is not in MST, then edge from curr node
                # to next node can be pushed in the priority queue.
                if not in_mst[next_node]:
                    next_weight = abs(points[curr_node][0] - points[next_node][0]) +\
                                  abs(points[curr_node][1] - points[next_node][1])
                    
                    heapq.heappush(heap, (next_weight, next_node))
                    
        return mst_cost
```

</details>

<br>

## Approach 3: Prim's Algorithm (Optimized)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int mstCost = 0;
        int edgesUsed = 0;
        
        // Track nodes which are visited.
        vector<bool> inMST(n);
        
        vector<int> minDist(n, INT_MAX);
        minDist[0] = 0;
        
        while (edgesUsed < n) {
            int currMinEdge = INT_MAX;
            int currNode = -1;
            
            // Pick least weight node which is not in MST.
            for (int node = 0; node < n; ++node) {
                if (!inMST[node] && currMinEdge > minDist[node]) {
                    currMinEdge = minDist[node];
                    currNode = node;
                }
            }
            
            mstCost += currMinEdge;
            edgesUsed++;
            inMST[currNode] = true;
            
            // Update adjacent nodes of current node.
            for (int nextNode = 0; nextNode < n; ++nextNode) {
                int weight = abs(points[currNode][0] - points[nextNode][0]) + 
                             abs(points[currNode][1] - points[nextNode][1]);
                
                if (!inMST[nextNode] && minDist[nextNode] > weight) {
                    minDist[nextNode] = weight;
                }
            }
        }
        
        return mstCost;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minCostConnectPoints(int[][] points) {
        int n = points.length;
        int mstCost = 0;
        int edgesUsed = 0;
        
        // Track nodes which are visited.
        boolean[] inMST = new boolean[n];
        
        int[] minDist = new int[n];
        minDist[0] = 0;
        
        for (int i = 1; i < n; ++i) {
            minDist[i] = Integer.MAX_VALUE;
        }
        
        while (edgesUsed < n) {
            int currMinEdge = Integer.MAX_VALUE;
            int currNode = -1;
            
            // Pick least weight node which is not in MST.
            for (int node = 0; node < n; ++node) {
                if (!inMST[node] && currMinEdge > minDist[node]) {
                    currMinEdge = minDist[node];
                    currNode = node;
                }
            }
            
            mstCost += currMinEdge;
            edgesUsed++;
            inMST[currNode] = true;
            
            // Update adjacent nodes of current node.
            for (int nextNode = 0; nextNode < n; ++nextNode) {
                int weight = Math.abs(points[currNode][0] - points[nextNode][0]) + 
                             Math.abs(points[currNode][1] - points[nextNode][1]);
                
                if (!inMST[nextNode] && minDist[nextNode] > weight) {
                    minDist[nextNode] = weight;
                }
            }
        }
        
        return mstCost;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let minCostConnectPoints = function(points) {
    let n = points.length;
    let mstCost = 0;
    let edgesUsed = 0;

    // Track nodes which are visited.
    let inMST = Array(n).fill(false);

    let minDist = Array(n).fill(Number.MAX_SAFE_INTEGER);
    minDist[0] = 0;

    while (edgesUsed < n) {
        let currMinEdge = Number.MAX_SAFE_INTEGER;
        let currNode = -1;

        // Pick least weight node which is not in MST.
        for (let node = 0; node < n; ++node) {
            if (!inMST[node] && currMinEdge > minDist[node]) {
                currMinEdge = minDist[node];
                currNode = node;
            }
        }

        mstCost += currMinEdge;
        edgesUsed++;
        inMST[currNode] = true;

        // Update adjacent nodes of current node.
        for (let nextNode = 0; nextNode < n; ++nextNode) {
            let weight = Math.abs(points[currNode][0] - points[nextNode][0]) + 
                         Math.abs(points[currNode][1] - points[nextNode][1]);

            if (!inMST[nextNode] && minDist[nextNode] > weight) {
                minDist[nextNode] = weight;
            }
        }
    }

    return mstCost;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        mst_cost = 0
        edges_used = 0
        
        # Track nodes which are visited.
        in_mst = [False] * n
        
        min_dist = [math.inf] * n
        min_dist[0] = 0
        
        while edges_used < n:
            curr_min_edge = math.inf
            curr_node = -1
            
            # Pick least weight node which is not in MST.
            for node in range(n):
                if not in_mst[node] and curr_min_edge > min_dist[node]:
                    curr_min_edge = min_dist[node]
                    curr_node = node
            
            mst_cost += curr_min_edge
            edges_used += 1
            in_mst[curr_node] = True
            
            # Update adjacent nodes of current node.
            for next_node in range(n):
                weight = abs(points[curr_node][0] - points[next_node][0]) +\
                         abs(points[curr_node][1] - points[next_node][1])
                
                if not in_mst[next_node] and min_dist[next_node] > weight:
                    min_dist[next_node] = weight
        
        return mst_cost
```

</details>
