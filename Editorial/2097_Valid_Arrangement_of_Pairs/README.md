# 2097. Valid Arrangement of Pairs

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/valid-arrangement-of-pairs/)  
`Array` `Depth-First Search` `Graph Theory` `Eulerian Circuit`

**Problem Link:** [LeetCode 2097 - Valid Arrangement of Pairs](https://leetcode.com/problems/valid-arrangement-of-pairs/)

## Problem

You are given a 0-indexed 2D integer array pairs where pairs[i] = [starti, endi]. An arrangement of pairs is valid if for every index i where 1 <= i < pairs.length, we have endi-1 == starti.

Return any valid arrangement of pairs.

Note: The inputs will be generated such that there exists a valid arrangement of pairs.

### Example 1

```text
Input: pairs = [[5,1],[4,5],[11,9],[9,4]]
Output: [[11,9],[9,4],[4,5],[5,1]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 9 == 9 = start1
end1 = 4 == 4 = start2
end2 = 5 == 5 = start3
```

### Example 2

```text
Input: pairs = [[1,3],[3,2],[2,1]]
Output: [[1,3],[3,2],[2,1]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 3 == 3 = start1
end1 = 2 == 2 = start2
The arrangements [[2,1],[1,3],[3,2]] and [[3,2],[2,1],[1,3]] are also valid.
```

### Example 3

```text
Input: pairs = [[1,2],[1,3],[2,1]]
Output: [[1,2],[2,1],[1,3]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 2 == 2 = start1
end1 = 1 == 1 = start2
```

## Constraints

- 1 <= pairs.length <= 105
- pairs[i].length == 2
- 0 <= starti, endi <= 109
- starti != endi
- No two pairs are exactly the same.
- There exists a valid arrangement of pairs.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2097. Valid Arrangement of Pairs

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Eulerian Path (Recursive) | C++, Java, Python3 |
| Hierholzer's Algorithm (Iterative) | C++, Java, Python3 |

## Approach 1: Eulerian Path (Recursive)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, deque<int>> adjacencyMatrix;
        unordered_map<int, int> inDegree, outDegree;

        // Build the adjacency list and track in-degrees and out-degrees
        for (const auto& pair : pairs) {
            int start = pair[0], end = pair[1];
            adjacencyMatrix[start].push_back(end);
            outDegree[start]++;
            inDegree[end]++;
        }

        vector<int> result;

        // Helper lambda function for DFS traversal,
        // you can make a seperate private function also
        function<void(int)> visit = [&](int node) {
            while (!adjacencyMatrix[node].empty()) {
                int nextNode = adjacencyMatrix[node].front();
                adjacencyMatrix[node].pop_front();
                visit(nextNode);
            }
            result.push_back(node);
        };

        // Find the start node (outDegree == 1 + inDegree )
        int startNode = -1;
        for (const auto& entry : outDegree) {
            int node = entry.first;
            if (outDegree[node] == inDegree[node] + 1) {
                startNode = node;
                break;
            }
        }

        // If no such node exists, start from the first pair's first element
        if (startNode == -1) {
            startNode = pairs[0][0];
        }

        // Start DFS traversal
        visit(startNode);

        // Reverse the result since DFS gives us the path in reverse
        reverse(result.begin(), result.end());

        // Construct the result pairs
        vector<vector<int>> pairedResult;
        for (int i = 1; i < result.size(); ++i) {
            pairedResult.push_back({result[i - 1], result[i]});
        }

        return pairedResult;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[][] validArrangement(int[][] pairs) {
        Map<Integer, Deque<Integer>> adjacencyMatrix = new HashMap<>();
        Map<Integer, Integer> inDegree = new HashMap<>();
        Map<Integer, Integer> outDegree = new HashMap<>();

        // Build the adjacency list and track in-degrees and out-degrees
        for (int[] pair : pairs) {
            int start = pair[0], end = pair[1];
            adjacencyMatrix
                .computeIfAbsent(start, k -> new ArrayDeque<>())
                .add(end);
            outDegree.put(start, outDegree.getOrDefault(start, 0) + 1);
            inDegree.put(end, inDegree.getOrDefault(end, 0) + 1);
        }

        List<Integer> result = new ArrayList<>();

        // Find the start node (outDegree == inDegree + 1)
        int startNode = -1;
        for (int node : outDegree.keySet()) {
            if (outDegree.get(node) == inDegree.getOrDefault(node, 0) + 1) {
                startNode = node;
                break;
            }
        }

        // If no such node exists, start from the first pair's first element
        if (startNode == -1) {
            startNode = pairs[0][0];
        }

        // Start DFS traversal
        visit(startNode, adjacencyMatrix, result);

        // Reverse the result since DFS gives us the path in reverse
        Collections.reverse(result);

        // Construct the result pairs
        int[][] pairedResult = new int[result.size() - 1][2];
        for (int i = 1; i < result.size(); i++) {
            pairedResult[i - 1] = new int[] {
                result.get(i - 1),
                result.get(i),
            };
        }

        return pairedResult;
    }

    private void visit(
        int node,
        Map<Integer, Deque<Integer>> adjMatrix,
        List<Integer> res
    ) {
        Deque<Integer> neighbors = adjMatrix.get(node);
        while (neighbors != null && !neighbors.isEmpty()) {
            int nextNode = neighbors.pollFirst();
            visit(nextNode, adjMatrix, res);
        }
        res.add(node);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def validArrangement(self, pairs):
        from collections import defaultdict, deque

        adjacencyMatrix = defaultdict(deque)
        inDegree, outDegree = defaultdict(int), defaultdict(int)

        # Build the adjacency list and track in-degrees and out-degrees
        for pair in pairs:
            start, end = pair
            adjacencyMatrix[start].append(end)
            outDegree[start] += 1
            inDegree[end] += 1

        result = []

        def visit(node):
            while adjacencyMatrix[node]:
                nextNode = adjacencyMatrix[node].popleft()
                visit(nextNode)
            result.append(node)

        # Find the start node (outDegree == 1 + inDegree )
        startNode = -1
        for node in outDegree:
            if outDegree[node] == inDegree[node] + 1:
                startNode = node
                break

        # If no such node exists, start from the first pair's first element
        if startNode == -1:
            startNode = pairs[0][0]

        # Start DFS traversal
        visit(startNode)

        # Reverse the result since DFS gives us the path in reverse
        result.reverse()

        # Construct the result pairs
        pairedResult = [
            [result[i - 1], result[i]] for i in range(1, len(result))
        ]

        return pairedResult
```

</details>

<br>

## Approach 2: Hierholzer's Algorithm (Iterative)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, deque<int>> adjacencyMatrix;
        unordered_map<int, int> inDegree, outDegree;

        // Build the adjacency list and track in-degrees and out-degrees
        for (const auto& pair : pairs) {
            int start = pair[0], end = pair[1];
            adjacencyMatrix[start].push_back(end);
            outDegree[start]++;
            inDegree[end]++;
        }

        vector<int> result;

        // Find the start node (outDegree == inDegree + 1)
        int startNode = -1;
        for (const auto& entry : outDegree) {
            int node = entry.first;
            if (outDegree[node] == inDegree[node] + 1) {
                startNode = node;
                break;
            }
        }

        // If no such node exists, start from the first pair's first element
        if (startNode == -1) {
            startNode = pairs[0][0];
        }

        stack<int> nodeStack;
        nodeStack.push(startNode);

        // Iterative DFS using stack
        while (!nodeStack.empty()) {
            int node = nodeStack.top();
            if (!adjacencyMatrix[node].empty()) {
                // Visit the next node
                int nextNode = adjacencyMatrix[node].front();
                adjacencyMatrix[node].pop_front();
                nodeStack.push(nextNode);
            } else {
                // No more neighbors to visit, add node to result
                result.push_back(node);
                nodeStack.pop();
            }
        }

        // Reverse the result since we collected nodes in reverse order
        reverse(result.begin(), result.end());

        // Construct the result pairs
        vector<vector<int>> pairedResult;
        for (int i = 1; i < result.size(); ++i) {
            pairedResult.push_back({result[i - 1], result[i]});
        }

        return pairedResult;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[][] validArrangement(int[][] pairs) {
        HashMap<Integer, LinkedList<Integer>> adjacencyMatrix = new HashMap<>();
        HashMap<Integer, Integer> inDegree = new HashMap<>(), outDegree =
            new HashMap<>();

        // Build the adjacency list and track in-degrees and out-degrees
        for (int[] pair : pairs) {
            int start = pair[0], end = pair[1];
            adjacencyMatrix.putIfAbsent(start, new LinkedList<>());
            adjacencyMatrix.get(start).add(end);
            outDegree.put(start, outDegree.getOrDefault(start, 0) + 1);
            inDegree.put(end, inDegree.getOrDefault(end, 0) + 1);
        }

        ArrayList<Integer> result = new ArrayList<>();

        // Find the start node (outDegree == inDegree + 1)
        int startNode = -1;
        for (int node : outDegree.keySet()) {
            if (outDegree.get(node) == inDegree.getOrDefault(node, 0) + 1) {
                startNode = node;
                break;
            }
        }

        // If no such node exists, start from the first pair's first element
        if (startNode == -1) {
            startNode = pairs[0][0];
        }

        Stack<Integer> nodeStack = new Stack<>();
        nodeStack.push(startNode);

        // Iterative DFS using stack
        while (!nodeStack.empty()) {
            int node = nodeStack.peek();
            if (
                adjacencyMatrix.getOrDefault(node, new LinkedList<>()).size() >
                0
            ) {
                // Visit the next node
                int nextNode = adjacencyMatrix.get(node).removeFirst();
                nodeStack.push(nextNode);
            } else {
                // No more neighbors to visit, add node to result
                result.add(node);
                nodeStack.pop();
            }
        }

        // Reverse the result since we collected nodes in reverse order
        Collections.reverse(result);

        // Construct the result pairs
        int[][] pairedResult = new int[result.size() - 1][2];
        for (int i = 1; i < result.size(); ++i) {
            pairedResult[i - 1][0] = result.get(i - 1);
            pairedResult[i - 1][1] = result.get(i);
        }

        return pairedResult;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def validArrangement(self, pairs):
        adjacencyMatrix = collections.defaultdict(list)
        inDegree, outDegree = collections.defaultdict(
            int
        ), collections.defaultdict(int)

        # Build the adjacency list and track in-degrees and out-degrees
        for pair in pairs:
            start, end = pair[0], pair[1]
            adjacencyMatrix[start].append(end)
            outDegree[start] += 1
            inDegree[end] += 1

        result = []

        # Find the start node (outDegree == inDegree + 1)
        startNode = -1
        for node in outDegree:
            if outDegree[node] == inDegree[node] + 1:
                startNode = node
                break

        # If no such node exists, start from the first pair's first element
        if startNode == -1:
            startNode = pairs[0][0]

        nodeStack = [startNode]

        # Iterative DFS using stack
        while nodeStack:
            node = nodeStack[-1]
            if adjacencyMatrix[node]:
                # Visit the next node
                nextNode = adjacencyMatrix[node].pop(0)
                nodeStack.append(nextNode)
            else:
                # No more neighbors to visit, add node to result
                result.append(node)
                nodeStack.pop()

        # Reverse the result since we collected nodes in reverse order
        result.reverse()

        # Construct the result pairs
        pairedResult = []
        for i in range(1, len(result)):
            pairedResult.append([result[i - 1], result[i]])

        return pairedResult
```

</details>
