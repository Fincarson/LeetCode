# 56. Merge Intervals

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/merge-intervals/)  
`Array` `Sorting`

**Problem Link:** [LeetCode 56 - Merge Intervals](https://leetcode.com/problems/merge-intervals/)

## Problem

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

### Example 1

```text
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
```

### Example 2

```text
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

### Example 3

```text
Input: intervals = [[4,7],[1,4]]
Output: [[1,7]]
Explanation: Intervals [1,4] and [4,7] are considered overlapping.
```

## Constraints

- 1 <= intervals.length <= 104
- intervals[i].length == 2
- 0 <= starti <= endi <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Insert Interval](https://leetcode.com/problems/insert-interval/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Meeting Rooms](https://leetcode.com/problems/meeting-rooms/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Teemo Attacking](https://leetcode.com/problems/teemo-attacking/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Add Bold Tag in String](https://leetcode.com/problems/add-bold-tag-in-string/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Range Module](https://leetcode.com/problems/range-module/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Employee Free Time](https://leetcode.com/problems/employee-free-time/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Partition Labels](https://leetcode.com/problems/partition-labels/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Interval List Intersections](https://leetcode.com/problems/interval-list-intersections/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Amount of New Area Painted Each Day](https://leetcode.com/problems/amount-of-new-area-painted-each-day/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Longest Substring of One Repeating Character](https://leetcode.com/problems/longest-substring-of-one-repeating-character/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Count Integers in Intervals](https://leetcode.com/problems/count-integers-in-intervals/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Divide Intervals Into Minimum Number of Groups](https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Determine if Two Events Have Conflict](https://leetcode.com/problems/determine-if-two-events-have-conflict/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Count Ways to Group Overlapping Ranges](https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Points That Intersect With Cars](https://leetcode.com/problems/points-that-intersect-with-cars/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Count Days Without Meetings](https://leetcode.com/problems/count-days-without-meetings/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimize Connected Groups by Inserting Interval](https://leetcode.com/problems/minimize-connected-groups-by-inserting-interval/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 56. Merge Intervals

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Connected Components | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Sorting | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Connected Components

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MAX_INTERVALS 10000

typedef struct Node {
    int index;  // Index of the interval in the original list
    struct Node* next;
} Node;

typedef struct {
    Node* edges[MAX_INTERVALS];  // Adjacency list
    int visited[MAX_INTERVALS];  // Visited nodes
    int num_intervals;
} Graph;

void addEdge(Graph* g, int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->index = v;
    node->next = g->edges[u];
    g->edges[u] = node;
}

bool overlap(int* a, int* b) { return a[0] <= b[1] && b[0] <= a[1]; }

void buildGraph(Graph* g, int** intervals, int size) {
    g->num_intervals = size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j && overlap(intervals[i], intervals[j])) {
                addEdge(g, i, j);
            }
        }
    }
}

int* mergeNodes(Graph* g, int start, int** intervals, int* returnSize) {
    int* stack = malloc(g->num_intervals * sizeof(int));
    int top = 0;
    stack[top] = start;
    g->visited[start] = 1;

    int min_start = intervals[start][0];
    int max_end = intervals[start][1];

    while (top >= 0) {
        int node_index = stack[top--];
        Node* node = g->edges[node_index];
        while (node) {
            int idx = node->index;
            if (!g->visited[idx]) {
                g->visited[idx] = 1;
                min_start = (min_start < intervals[idx][0]) ? min_start
                                                            : intervals[idx][0];
                max_end =
                    (max_end > intervals[idx][1]) ? max_end : intervals[idx][1];
                stack[++top] = idx;
            }
            node = node->next;
        }
    }

    free(stack);
    *returnSize = 2;
    int* merged = malloc(2 * sizeof(int));
    merged[0] = min_start;
    merged[1] = max_end;
    return merged;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {
    Graph g = {0};
    buildGraph(&g, intervals, intervalsSize);

    int** merged = malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = malloc(intervalsSize * sizeof(int));

    int count = 0;
    for (int i = 0; i < intervalsSize; i++) {
        if (!g.visited[i]) {
            int size;
            merged[count] = mergeNodes(&g, i, intervals, &size);
            (*returnColumnSizes)[count] = size;
            count++;
        }
    }

    *returnSize = count;
    for (int i = 0; i < g.num_intervals; i++) {
        Node* node = g.edges[i];
        while (node != NULL) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }

    return merged;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    map<vector<int>, vector<vector<int>>> graph;
    map<int, vector<vector<int>>> nodes_in_comp;
    set<vector<int>> visited;

    bool overlap(vector<int>& a, vector<int>& b) {
        return a[0] <= b[1] and b[0] <= a[1];
    }

    // build a graph where an undirected edge between intervals u and v exists
    // iff u and v overlap.
    void buildGraph(vector<vector<int>>& intervals) {
        for (auto interval1 : intervals) {
            for (auto interval2 : intervals) {
                if (overlap(interval1, interval2)) {
                    graph[interval1].push_back(interval2);
                    graph[interval2].push_back(interval1);
                }
            }
        }
    }

    // merges all of the nodes in this connected component into one interval.
    vector<int> mergeNodes(vector<vector<int>>& nodes) {
        int min_start = nodes[0][0];
        for (auto node : nodes) {
            min_start = min(min_start, node[0]);
        }

        int max_end = nodes[0][1];
        for (auto node : nodes) {
            max_end = max(max_end, node[1]);
        }

        return {min_start, max_end};
    }

    // use depth-first search to mark all nodes in the same connected component
    // with the same integer.
    void markComponentDFS(vector<int>& start, int comp_number) {
        stack<vector<int>> stk;
        stk.push(start);

        while (!stk.empty()) {
            vector<int> node = stk.top();
            stk.pop();

            // not found
            if (visited.find(node) == visited.end()) {
                visited.insert(node);

                nodes_in_comp[comp_number].push_back(node);

                for (auto child : graph[node]) {
                    stk.push(child);
                }
            }
        }
    }

    // gets the connected components of the interval overlap graph.
    void buildComponents(vector<vector<int>>& intervals) {
        int comp_number = 0;

        for (auto interval : intervals) {
            if (visited.find(interval) == visited.end()) {
                markComponentDFS(interval, comp_number);
                comp_number++;
            }
        }
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        buildGraph(intervals);
        buildComponents(intervals);

        // for each component, merge all intervals into one interval.
        vector<vector<int>> merged;
        for (size_t comp = 0; comp < nodes_in_comp.size(); comp++) {
            merged.push_back(mergeNodes(nodes_in_comp[comp]));
        }

        return merged;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    IDictionary<int[], List<int[]>> graph =
        new Dictionary<int[], List<int[]>>();

    IDictionary<int, List<int[]>> nodesInComp =
        new Dictionary<int, List<int[]>>();

    HashSet<int[]> visited = new HashSet<int[]>();

    private bool Overlap(int[] a, int[] b) {
        return a[0] <= b[1] && b[0] <= a[1];
    }

    private void BuildGraph(int[][] intervals) {
        foreach (var interval in intervals) {
            graph[interval] = new List<int[]>();
        }

        for (int i = 0; i < intervals.Length; i++) {
            for (int j = 0; j < intervals.Length; j++) {
                if (this.Overlap(intervals[i], intervals[j])) {
                    graph.TryGetValue(intervals[i], out var val);
                    if (val != null) {
                        val.Add(intervals[j]);
                    }

                    graph.TryGetValue(intervals[j], out val);
                    if (val != null) {
                        val.Add(intervals[i]);
                    }
                }
            }
        }
    }

    private int[] MergeNodes(List<int[]> nodes) {
        int minStart = nodes[0][0];
        foreach (var node in nodes) {
            minStart = Math.Min(minStart, node[0]);
        }

        int maxEnd = nodes[0][1];
        foreach (var node in nodes) {
            maxEnd = Math.Max(maxEnd, node[1]);
        }

        return new int[] { minStart, maxEnd };
    }

    private void MarkComponentDFS(int[] start, Stack<int[]> stack,
                                  int compNumber) {
        stack.Push(start);
        while (stack.Count != 0) {
            int[] node = stack.Pop();
            if (!visited.Contains(node)) {
                visited.Add(node);
                if (!nodesInComp.ContainsKey(compNumber)) {
                    nodesInComp.Add(compNumber, new List<int[]>());
                }

                nodesInComp.TryGetValue(compNumber, out var val);
                val.Add(node);
                List<int[]> nodes = null;
                graph.TryGetValue(node, out nodes);
                foreach (var child in nodes) {
                    stack.Push(child);
                }
            }
        }
    }

    private void BuildComponents(int[][] intervals) {
        int compNumber = 0;
        Stack<int[]> stack = new Stack<int[]>();
        foreach (var interval in intervals) {
            if (!visited.Contains(interval)) {
                MarkComponentDFS(interval, stack, compNumber);
                compNumber++;
            }
        }
    }

    public int[][] Merge(int[][] intervals) {
        BuildGraph(intervals);
        BuildComponents(intervals);
        List<int[]> merged = new List<int[]>();
        for (int i = 0; i < nodesInComp.Count; i++) {
            merged.Add(MergeNodes(nodesInComp[i]));
        }

        return merged.ToArray();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func overlap(a []int, b []int) bool {
    return a[0] <= b[1] && b[0] <= a[1]
}

func buildGraph(intervals [][]int) map[int][]int {
    graph := make(map[int][]int)
    for i, interval1 := range intervals {
        for j := i + 1; j < len(intervals); j++ {
            interval2 := intervals[j]
            if overlap(interval1, interval2) {
                graph[i] = append(graph[i], j)
                graph[j] = append(graph[j], i)
            }
        }
    }
    return graph
}

func mergeNodes(nodes []int, intervals [][]int) []int {
    minStart := intervals[nodes[0]][0]
    maxEnd := intervals[nodes[0]][1]
    for _, i := range nodes {
        minStart = int(math.Min(float64(minStart), float64(intervals[i][0])))
        maxEnd = int(math.Max(float64(maxEnd), float64(intervals[i][1])))
    }
    return []int{minStart, maxEnd}
}

func markComponentDFS(
    i int,
    compNumber int,
    visited map[int]bool,
    graph map[int][]int,
    nodesInComp map[int][]int,
) {
    stack := []int{i}
    for len(stack) != 0 {
        node := stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        if _, ok := visited[node]; !ok {
            visited[node] = true
            nodesInComp[compNumber] = append(nodesInComp[compNumber], node)
            for _, child := range graph[node] {
                stack = append(stack, child)
            }
        }
    }
}

func merge(intervals [][]int) [][]int {
    graph := buildGraph(intervals)
    nodesInComp := make(map[int][]int)
    visited := make(map[int]bool)
    compNumber := 0
    for i := range intervals {
        if _, ok := visited[i]; !ok {
            markComponentDFS(i, compNumber, visited, graph, nodesInComp)
            compNumber++
        }
    }
    merged := make([][]int, 0)
    for comp := 0; comp < compNumber; comp++ {
        merged = append(merged, mergeNodes(nodesInComp[comp], intervals))
    }
    return merged
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private Map<int[], List<int[]>> graph;
    private Map<Integer, List<int[]>> nodesInComp;
    private Set<int[]> visited;

    // return whether two intervals overlap (inclusive)
    private boolean overlap(int[] a, int[] b) {
        return a[0] <= b[1] && b[0] <= a[1];
    }

    // build a graph where an undirected edge between intervals u and v exists
    // iff u and v overlap.
    private void buildGraph(int[][] intervals) {
        graph = new HashMap<>();
        for (int[] interval : intervals) {
            graph.put(interval, new LinkedList<>());
        }

        for (int[] interval1 : intervals) {
            for (int[] interval2 : intervals) {
                if (overlap(interval1, interval2)) {
                    graph.get(interval1).add(interval2);
                    graph.get(interval2).add(interval1);
                }
            }
        }
    }

    // merges all of the nodes in this connected component into one interval.
    private int[] mergeNodes(List<int[]> nodes) {
        int minStart = nodes.get(0)[0];
        for (int[] node : nodes) {
            minStart = Math.min(minStart, node[0]);
        }

        int maxEnd = nodes.get(0)[1];
        for (int[] node : nodes) {
            maxEnd = Math.max(maxEnd, node[1]);
        }

        return new int[] { minStart, maxEnd };
    }

    // use depth-first search to mark all nodes in the same connected component
    // with the same integer.
    private void markComponentDFS(int[] start, int compNumber) {
        Stack<int[]> stack = new Stack<>();
        stack.add(start);

        while (!stack.isEmpty()) {
            int[] node = stack.pop();
            if (!visited.contains(node)) {
                visited.add(node);

                if (nodesInComp.get(compNumber) == null) {
                    nodesInComp.put(compNumber, new LinkedList<>());
                }
                nodesInComp.get(compNumber).add(node);

                for (int[] child : graph.get(node)) {
                    stack.add(child);
                }
            }
        }
    }

    // gets the connected components of the interval overlap graph.
    private void buildComponents(int[][] intervals) {
        nodesInComp = new HashMap<>();
        visited = new HashSet<>();
        int compNumber = 0;

        for (int[] interval : intervals) {
            if (!visited.contains(interval)) {
                markComponentDFS(interval, compNumber);
                compNumber++;
            }
        }
    }

    public int[][] merge(int[][] intervals) {
        buildGraph(intervals);
        buildComponents(intervals);

        // for each component, merge all intervals into one interval.
        List<int[]> merged = new LinkedList<>();
        for (int comp = 0; comp < nodesInComp.size(); comp++) {
            merged.add(mergeNodes(nodesInComp.get(comp)));
        }

        return merged.toArray(new int[merged.size()][]);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var overlap = function (a, b) {
    return a[0] <= b[1] && b[0] <= a[1];
};
var buildGraph = function (intervals) {
    var graph = new Map();
    for (var i = 0; i < intervals.length; i++) {
        for (var j = i + 1; j < intervals.length; j++) {
            if (overlap(intervals[i], intervals[j])) {
                if (graph.has(intervals[i])) {
                    graph.get(intervals[i]).push(intervals[j]);
                } else {
                    graph.set(intervals[i], [intervals[j]]);
                }
                if (graph.has(intervals[j])) {
                    graph.get(intervals[j]).push(intervals[i]);
                } else {
                    graph.set(intervals[j], [intervals[i]]);
                }
            }
        }
    }
    return graph;
};
var mergeNodes = function (nodes) {
    var minStart = Infinity;
    var maxEnd = -Infinity;
    for (var node of nodes) {
        minStart = Math.min(minStart, node[0]);
        maxEnd = Math.max(maxEnd, node[1]);
    }
    return [minStart, maxEnd];
};
var markComponentDFS = function (
    start,
    graph,
    nodesInComp,
    compNumber,
    visited,
) {
    var stack = [start];
    while (stack.length) {
        var node = stack.pop();
        if (!visited.has(node)) {
            visited.add(node);
            if (nodesInComp[compNumber]) {
                nodesInComp[compNumber].push(node);
            } else {
                nodesInComp[compNumber] = [node];
            }
            if (graph.has(node)) {
                for (var child of graph.get(node)) {
                    stack.push(child);
                }
            }
        }
    }
};
var merge = function (intervals) {
    var graph = buildGraph(intervals);
    var nodesInComp = {};
    var visited = new Set();
    var compNumber = 0;
    for (var interval of intervals) {
        if (!visited.has(interval)) {
            markComponentDFS(interval, graph, nodesInComp, compNumber, visited);
            compNumber++;
        }
    }
    var merged = [];
    for (var comp = 0; comp < compNumber; comp++) {
        merged.push(mergeNodes(nodesInComp[comp]));
    }
    return merged;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def overlap(self, a, b):
        return a[0] <= b[1] and b[0] <= a[1]

    # generate graph where there is an undirected edge between intervals u
    # and v iff u and v overlap.
    def buildGraph(self, intervals):
        graph = collections.defaultdict(list)

        for i, interval_i in enumerate(intervals):
            for j in range(i + 1, len(intervals)):
                if self.overlap(interval_i, intervals[j]):
                    graph[tuple(interval_i)].append(intervals[j])
                    graph[tuple(intervals[j])].append(interval_i)

        return graph

    # merges all of the nodes in this connected component into one interval.
    def mergeNodes(self, nodes):
        min_start = min(node[0] for node in nodes)
        max_end = max(node[1] for node in nodes)
        return [min_start, max_end]

    # gets the connected components of the interval overlap graph.
    def getComponents(self, graph, intervals):
        visited = set()
        comp_number = 0
        nodes_in_comp = collections.defaultdict(list)

        def markComponentDFS(start):
            stack = [start]
            while stack:
                node = tuple(stack.pop())
                if node not in visited:
                    visited.add(node)
                    nodes_in_comp[comp_number].append(node)
                    stack.extend(graph[node])

        # mark all nodes in the same connected component with the same integer.
        for interval in intervals:
            if tuple(interval) not in visited:
                markComponentDFS(interval)
                comp_number += 1

        return nodes_in_comp, comp_number

    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        graph = self.buildGraph(intervals)
        nodes_in_comp, number_of_comps = self.getComponents(graph, intervals)

        # all intervals in each connected component must be merged.
        return [
            self.mergeNodes(nodes_in_comp[comp])
            for comp in range(number_of_comps)
        ]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const overlap = (a: number[], b: number[]): boolean => {
    return a[0] <= b[1] && b[0] <= a[1];
};
const buildGraph = (intervals: number[][]): Map<number[], number[][]> => {
    let graph: Map<number[], number[][]> = new Map();
    for (let i = 0; i < intervals.length; i++) {
        for (let j = i + 1; j < intervals.length; j++) {
            if (overlap(intervals[i], intervals[j])) {
                if (graph.has(intervals[i])) {
                    graph.get(intervals[i])?.push(intervals[j]);
                } else {
                    graph.set(intervals[i], [intervals[j]]);
                }
                if (graph.has(intervals[j])) {
                    graph.get(intervals[j])?.push(intervals[i]);
                } else {
                    graph.set(intervals[j], [intervals[i]]);
                }
            }
        }
    }
    return graph;
};
const mergeNodes = (nodes: number[][]): number[] => {
    let minStart: number = Infinity;
    let maxEnd: number = -Infinity;
    for (let node of nodes) {
        minStart = Math.min(minStart, node[0]);
        maxEnd = Math.max(maxEnd, node[1]);
    }
    return [minStart, maxEnd];
};
const markComponentDFS = (
    start: number[],
    graph: Map<number[], number[][]>,
    nodesInComp: Record<number, number[][]>,
    compNumber: number,
    visited: Set<number[]>,
): void => {
    let stack: number[][] = [start];
    while (stack.length) {
        let node: number[] | undefined = stack.pop();
        if (node && !visited.has(node)) {
            visited.add(node);
            if (nodesInComp[compNumber]) {
                nodesInComp[compNumber].push(node);
            } else {
                nodesInComp[compNumber] = [node];
            }
            if (graph.has(node)) {
                for (let child of graph.get(node) as number[][]) {
                    stack.push(child);
                }
            }
        }
    }
};
const merge = (intervals: number[][]): number[][] => {
    let graph: Map<number[], number[][]> = buildGraph(intervals);
    let nodesInComp: Record<number, number[][]> = {};
    let visited: Set<number[]> = new Set();
    let compNumber: number = 0;
    for (let interval of intervals) {
        if (!visited.has(interval)) {
            markComponentDFS(interval, graph, nodesInComp, compNumber, visited);
            compNumber++;
        }
    }
    let merged: number[][] = [];
    for (let comp = 0; comp < compNumber; comp++) {
        merged.push(mergeNodes(nodesInComp[comp]));
    }
    return merged;
};
```

</details>

<br>

## Approach 2: Sorting

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
int compareC(const void* a, const void* b) {
    int* ia = *(int**)a;
    int* ib = *(int**)b;
    return ia[0] == ib[0] ? ib[1] - ia[1] : ia[0] - ib[0];
}
int** merge(int** intervals, int intervalsSize, const int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {
    int n = intervalsSize;
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    qsort(intervals, n, sizeof(int*), compareC);
    int** merged = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; ++i) merged[i] = malloc(sizeof(int) * 2);
    memcpy(merged[0], intervals[0], 2 * sizeof(int));
    int t = 0;  // pointers to merged
    for (int i = 1; i < n; ++i) {
        int l = intervals[i][0], r = intervals[i][1];
        if (l <= merged[t][1]) {
            merged[t][1] = max(merged[t][1], r);
        } else {
            memcpy(merged[++t], intervals[i], 2 * sizeof(int));
        }
    }
    ++t;
    *returnSize = t;
    *returnColumnSizes = malloc(sizeof(int) * t);
    for (int i = 0; i < t; ++i) {
        (*returnColumnSizes)[i] = 2;
    }
    return merged;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for (auto interval : intervals) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[][] Merge(int[][] intervals) {
        Array.Sort(intervals, (a, b) => a[0] - b[0]);
        LinkedList<int[]> merged = new LinkedList<int[]>();
        foreach (int[] interval in intervals) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, append it
            if (merged.Count == 0 || merged.Last.Value[1] < interval[0]) {
                merged.AddLast(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals
            else {
                merged.Last.Value[1] =
                    Math.Max(merged.Last.Value[1], interval[1]);
            }
        }

        return merged.ToArray();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func merge(intervals [][]int) [][]int {
    sort.Slice(intervals, func(i, j int) bool {
        return intervals[i][0] < intervals[j][0]
    })
    merged := make([][]int, 0)
    for _, interval := range intervals {
        if len(merged) == 0 || merged[len(merged)-1][1] < interval[0] {
            merged = append(merged, interval)
        } else {
            merged[len(merged)-1][1] = max(merged[len(merged)-1][1], interval[1])
        }
    }
    return merged
}

func max(a int, b int) int {
    if a > b {
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
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        LinkedList<int[]> merged = new LinkedList<>();
        for (int[] interval : intervals) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (merged.isEmpty() || merged.getLast()[1] < interval[0]) {
                merged.add(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            else {
                merged.getLast()[1] = Math.max(
                    merged.getLast()[1],
                    interval[1]
                );
            }
        }
        return merged.toArray(new int[merged.size()][]);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var merge = function (intervals) {
    intervals.sort((a, b) => a[0] - b[0]);
    let merged = [];
    for (let interval of intervals) {
        // if the list of merged intervals is empty or if the current
        // interval does not overlap with the previous, simply append it.
        if (merged.length === 0 || merged[merged.length - 1][1] < interval[0]) {
            merged.push(interval);
        }
        // otherwise, there is overlap, so we merge the current and previous
        // intervals.
        else {
            merged[merged.length - 1][1] = Math.max(
                merged[merged.length - 1][1],
                interval[1],
            );
        }
    }
    return merged;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:

        intervals.sort(key=lambda x: x[0])

        merged = []
        for interval in intervals:
            # if the list of merged intervals is empty or if the current
            # interval does not overlap with the previous, simply append it.
            if not merged or merged[-1][1] < interval[0]:
                merged.append(interval)
            else:
                # otherwise, there is overlap, so we merge the current and previous
                # intervals.
                merged[-1][1] = max(merged[-1][1], interval[1])

        return merged
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function merge(intervals: number[][]): number[][] {
    intervals.sort((a, b) => a[0] - b[0]);
    let merged: number[][] = [];
    for (let interval of intervals) {
        // if the list of merged intervals is empty or if the current
        // interval does not overlap with the previous, append it
        if (merged.length === 0 || merged[merged.length - 1][1] < interval[0]) {
            merged.push(interval);
        }
        // otherwise, there is overlap, so we merge the current and previous
        // intervals
        else {
            merged[merged.length - 1][1] = Math.max(
                merged[merged.length - 1][1],
                interval[1],
            );
        }
    }
    return merged;
}
```

</details>
