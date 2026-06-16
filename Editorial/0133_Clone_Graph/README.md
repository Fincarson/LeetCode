# 133. Clone Graph

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/clone-graph/)  
`Hash Table` `Depth-First Search` `Breadth-First Search` `Graph Theory`

**Problem Link:** [LeetCode 133 - Clone Graph](https://leetcode.com/problems/clone-graph/)

## Problem

Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

```text
class Node {
    public int val;
    public List<Node> neighbors;
}
```

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

### Example 1

```text
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
```

### Example 2

```text
Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
```

### Example 3

```text
Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.
```

## Constraints

- The number of nodes in the graph is in the range [0, 100].
- 1 <= Node.val <= 100
- Node.val is unique for each node.
- There are no repeated edges and no self-loops in the graph.
- The Graph is connected and all nodes can be visited starting from the given node.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Clone Binary Tree With Random Pointer](https://leetcode.com/problems/clone-binary-tree-with-random-pointer/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Clone N-ary Tree](https://leetcode.com/problems/clone-n-ary-tree/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 133. Clone Graph

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Breadth First Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Depth First Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
/*
// Definition for a Node.
struct Node {
    int val;
    struct Node** neighbors;
    int numNeighbors;
};
*/
#define MAX_SIZE 101
struct Node* newNode(int val) {
    struct Node* node = malloc(sizeof(struct Node));
    node->val = val;
    node->neighbors = malloc(MAX_SIZE * sizeof(struct Node*));
    node->numNeighbors = 0;
    return node;
}
struct HashTable {
    struct Node* key;
    struct Node* val;
    UT_hash_handle hh;
};
struct HashTable* visited = NULL;
void add(struct Node* keyNode, struct Node* valNode) {
    struct HashTable* s;
    HASH_FIND_PTR(visited, &keyNode, s);
    if (s == NULL) {
        s = (struct HashTable*)malloc(sizeof *s);
        s->key = keyNode;
        s->val = valNode;
        HASH_ADD_PTR(visited, key, s);
    }
}
struct Node* find(struct Node* keyNode) {
    struct HashTable* s;
    HASH_FIND_PTR(visited, &keyNode, s);
    return s ? s->val : NULL;
}
struct Node* cloneGraph(struct Node* node) {
    if (node == NULL) {
        return node;
    }
    struct Node* cloneNode = find(node);
    if (cloneNode) {
        return cloneNode;
    }
    cloneNode = newNode(node->val);
    add(node, cloneNode);
    for (int i = 0; i < node->numNeighbors; i++) {
        cloneNode->neighbors[cloneNode->numNeighbors++] =
            cloneGraph(node->neighbors[i]);
    }
    return cloneNode;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
private:
    unordered_map<Node*, Node*> visited;

public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return node;
        }
        // If the node was already visited before.
        // Return the clone from the visited dictionary.
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }
        // Create a clone for the given node.
        // Note that we don't have cloned neighbors as of now, hence [].
        Node* cloneNode = new Node(node->val, {});
        // The key is original node and value being the clone node.
        visited[node] = cloneNode;
        // Iterate through the neighbors to generate their clones
        // and prepare a list of cloned neighbors to be added to the cloned
        // node.
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }
        return cloneNode;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
/*
// Definition for a Node.
public class Node {
    public int val;
    public IList<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new List<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new List<Node>();
    }
    public Node(int _val, List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

public class Solution {
    private Dictionary<Node, Node> visited = new Dictionary<Node, Node>();

    public Node CloneGraph(Node node) {
        if (node == null) {
            return node;
        }

        // If the node was already visited before.
        // Return the clone from the visited dictionary.
        if (visited.ContainsKey(node)) {
            return visited[node];
        }

        // Create a clone for the given node.
        // Note that we don't have cloned neighbors as of now, hence [].
        Node cloneNode = new Node(node.val, new List<Node>());
        // The key is original node and value being the clone node.
        visited[node] = cloneNode;
        // Iterate through the neighbors to generate their clones
        // and prepare a list of cloned neighbors to be added to the cloned
        // node.
        foreach (Node neighbor in node.neighbors) {
            cloneNode.neighbors.Add(CloneGraph(neighbor));
        }

        return cloneNode;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
/*
// Definition for a Node.

    type Node struct {
        Val int
        Neighbors []*Node
    }
*/
func cloneGraph(node *Node) *Node {
    if node == nil {
        return node
    }
    visited := make(map[*Node]*Node)
    return dfs(node, visited)
}

func dfs(node *Node, visited map[*Node]*Node) *Node {
    if node == nil {
        return node
    }
    if value, ok := visited[node]; ok {
        return value
    }
    cloneNode := &Node{
        Val:       node.Val,
        Neighbors: make([]*Node, len(node.Neighbors)),
    }
    visited[node] = cloneNode
    for i, neighbor := range node.Neighbors {
        cloneNode.Neighbors[i] = dfs(neighbor, visited)
    }
    return cloneNode
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;

    public Node() {}

    public Node(int _val,List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    private HashMap<Node, Node> visited = new HashMap<>();

    public Node cloneGraph(Node node) {
        if (node == null) {
            return node;
        }

        // If the node was already visited before.
        // Return the clone from the visited dictionary.
        if (visited.containsKey(node)) {
            return visited.get(node);
        }

        // Create a clone for the given node.
        // Note that we don't have cloned neighbors as of now, hence [].
        Node cloneNode = new Node(node.val, new ArrayList());
        // The key is original node and value being the clone node.
        visited.put(node, cloneNode);

        // Iterate through the neighbors to generate their clones
        // and prepare a list of cloned neighbors to be added to the cloned node.
        for (Node neighbor : node.neighbors) {
            cloneNode.neighbors.add(cloneGraph(neighbor));
        }
        return cloneNode;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/*
// Definition for a Node.
function Node(val = 0, neighbors = []) {
   this.val = val;
   this.neighbors = neighbors;
};
*/
var cloneGraph = function (node) {
    var visited = new Map();
    function dfs(node) {
        if (node == null) {
            return node;
        }
        // If the node was already visited before.
        // Return the clone from the visited dictionary.
        if (visited.has(node)) {
            return visited.get(node);
        }
        // Create a clone for the given node.
        // Note that we don't have cloned neighbors as of now, hence [].
        var cloneNode = new Node(node.val, []);
        // The key is original node and value being the clone node.
        visited.set(node, cloneNode);
        // Iterate through the neighbors to generate their clones
        // and prepare a list of cloned neighbors to be added to the cloned node.
        node.neighbors.forEach(function (neighbor) {
            cloneNode.neighbors.push(dfs(neighbor));
        });
        return cloneNode;
    }
    return dfs(node);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""


class Solution:

    def __init__(self):
        # Dictionary to save the visited node and it's respective clone
        # as key and value respectively. This helps to avoid cycles.
        self.visited = {}

    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        if not node:
            return node

        # If the node was already visited before.
        # Return the clone from the visited dictionary.
        if node in self.visited:
            return self.visited[node]

        # Create a clone for the given node.
        # Note that we don't have cloned neighbors as of now, hence [].
        clone_node = Node(node.val, [])

        # The key is original node and value being the clone node.
        self.visited[node] = clone_node

        # Iterate through the neighbors to generate their clones
        # and prepare a list of cloned neighbors to be added to the cloned node.
        if node.neighbors:
            clone_node.neighbors = [self.cloneGraph(n) for n in node.neighbors]

        return clone_node
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
/*
// Definition for a Node.
class Node {
    val: number;
    neighbors: Node[];
    constructor(val?: number, neighbors?: Node[]) {
        this.val = (val===undefined ? 0 : val);
        this.neighbors = (neighbors===undefined ? [] : neighbors);
    }
}
*/
function cloneGraph(node: Node | null): Node | null {
    let visited = new Map();
    let dfs = (node: Node | null): Node | null => {
        if (node === null) {
            return null;
        }
        // If the node was already visited before.
        // Return the clone from the visited dictionary.
        if (visited.has(node)) {
            return visited.get(node);
        }
        // Create a clone for the given node.
        // Note that we don't have cloned neighbors as of now, hence [].
        let cloneNode = new Node(node.val, []);
        // The key is original node and value being the clone node.
        visited.set(node, cloneNode);
        if (node.neighbors !== undefined) {
            node.neighbors.forEach((neighbor) =>
                cloneNode.neighbors.push(dfs(neighbor)),
            );
        }
        return cloneNode;
    };
    return dfs(node);
}
```

</details>

<br>

## Approach 2: Breadth First Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct Node *cloneGraph(struct Node *node) {
    if (!node) {
        return NULL;
    }
    // Hash map to save the visited node and it's respective clone
    // as key and value respectively. This helps to avoid cycles.
    struct Node *visited[101] = {NULL};
    // Put the first node in the queue
    struct Node **queue = calloc(101, sizeof(struct Node *));
    queue[0] = node;
    int front = 0;
    int rear = 1;
    // create a new Node
    struct Node *cloneNode = calloc(1, sizeof(struct Node));
    cloneNode->val = node->val;
    cloneNode->numNeighbors = node->numNeighbors;
    // use this created node
    visited[node->val] = cloneNode;
    while (front != rear) {
        struct Node *oldNode = queue[front++];
        struct Node *newNode = visited[oldNode->val];
        // copy the neighbors
        newNode->neighbors =
            calloc(newNode->numNeighbors, sizeof(struct Node *));
        for (int i = 0; i < newNode->numNeighbors; i++) {
            struct Node *oldNeighbor = oldNode->neighbors[i];
            if (visited[oldNeighbor->val]) {
                newNode->neighbors[i] = visited[oldNeighbor->val];
            } else {
                queue[rear++] = oldNeighbor;
                struct Node *newNeighbor = calloc(1, sizeof(struct Node));
                newNeighbor->val = oldNeighbor->val;
                newNeighbor->numNeighbors = oldNeighbor->numNeighbors;
                newNode->neighbors[i] = visited[oldNeighbor->val] = newNeighbor;
            }
        }
    }
    free(queue);
    return visited[node->val];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     vector<Node*> neighbors;
 *     Node() {
 *         val = 0;
 *         neighbors = vector<Node*>();
 *     }
 *     Node(int _val) {
 *         val = _val;
 *         neighbors = vector<Node*>();
 *     }
 *     Node(int _val, vector<Node*> _neighbors) {
 *         val = _val;
 *         neighbors = _neighbors;
 *     }
 * };
 */
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }
        // Hash map to save the visited node and it's respective clone
        // as key and value respectively. This helps to avoid cycles.
        unordered_map<Node*, Node*> visited;
        // Put the first node in the queue
        deque<Node*> queue{node};
        // Clone the node and put it in the visited dictionary.
        visited[node] = new Node(node->val, {});
        // Start BFS traversal
        while (!queue.empty()) {
            // Pop a node say "n" from the from the front of the queue.
            Node* n = queue.front();
            queue.pop_front();
            // Iterate through all the neighbors of the node "n"
            for (Node* neighbor : n->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    // Clone the neighbor and put in the visited, if not present
                    // already
                    visited[neighbor] = new Node(neighbor->val, {});
                    // Add the newly encountered node to the queue.
                    queue.push_back(neighbor);
                }
                // Add the clone of the neighbor to the neighbors of the clone
                // node "n".
                visited[n]->neighbors.push_back(visited[neighbor]);
            }
        }
        // Return the clone of the node from visited.
        return visited[node];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
/**
 * Definition for a Node
 * public class Node {
 *     public int val;
 *     public IList<Node> neighbors;
 *
 *     public Node() {
 *         val = 0;
 *         neighbors = new List<Node>();
 *     }
 *
 *     public Node(int _val) {
 *         val = _val;
 *         neighbors = new List<Node>();
 *     }
 *
 *     public Node(int _val, List<Node> _neighbors) {
 *         val = _val;
 *         neighbors = _neighbors;
 *     }
 * }
 */
public class Solution {
    public Node CloneGraph(Node node) {
        if (node == null) {
            return node;
        }

        // Hash map to save the visited node and it's respective clone
        // as key and value respectively. This helps to avoid cycles.
        Dictionary<Node, Node> visited = new Dictionary<Node, Node>();
        // Put the first node in the queue
        Queue<Node> queue = new Queue<Node>();
        queue.Enqueue(node);
        // Clone the node and put it in the visited dictionary.
        visited[node] = new Node(node.val, new List<Node>());
        // Start BFS traversal
        while (queue.Count > 0) {
            // Pop a node say "n" from the from the front of the queue.
            Node n = queue.Dequeue();
            // Iterate through all the neighbors of the node "n"
            foreach (Node neighbor in n.neighbors) {
                if (!visited.ContainsKey(neighbor)) {
                    // Clone the neighbor and put in the visited, if not present
                    // already
                    visited[neighbor] =
                        new Node(neighbor.val, new List<Node>());
                    // Add the newly encountered node to the queue.
                    queue.Enqueue(neighbor);
                }

                // Add the clone of the neighbor to the neighbors of the clone
                // node "n".
                visited[n].neighbors.Add(visited[neighbor]);
            }
        }

        // Return the clone of the node from visited.
        return visited[node];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
/**
 * Definition for a Node
 * type Node struct {
 *     Val int
 *     Neighbors []*Node
 * }
 */
func cloneGraph(node *Node) *Node {
    if node == nil {
        return node
    }
    // Hash map to save the visited node and it's respective clone
    // as key and value respectively. This helps to avoid cycles.
    visited := make(map[*Node]*Node)
    // Put the first node in the queue
    queue := []*Node{node}
    // Clone the node and put it in the visited map.
    visited[node] = &Node{node.Val, []*Node{}}
    // Start BFS traversal
    for len(queue) > 0 {
        n := queue[0]
        queue = queue[1:]
        // Iterate through all the neighbors of the node
        for _, neighbor := range n.Neighbors {
            if _, ok := visited[neighbor]; !ok {
                // Clone the neighbor and put in the visited, if not present already
                visited[neighbor] = &Node{neighbor.Val, []*Node{}}
                // Add the newly encountered node to the queue.
                queue = append(queue, neighbor)
            }
            // Add the clone of the neighbor to the neighbors of the clone node "n".
            visited[n].Neighbors = append(
                visited[n].Neighbors,
                visited[neighbor],
            )
        }
    }
    // Return the clone of the node from visited.
    return visited[node]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;

    public Node() {}

    public Node(int _val,List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    public Node cloneGraph(Node node) {
        if (node == null) {
            return node;
        }

        // Hash map to save the visited node and it's respective clone
        // as key and value respectively. This helps to avoid cycles.
        HashMap<Node, Node> visited = new HashMap();

        // Put the first node in the queue
        LinkedList<Node> queue = new LinkedList<Node>();
        queue.add(node);
        // Clone the node and put it in the visited dictionary.
        visited.put(node, new Node(node.val, new ArrayList()));

        // Start BFS traversal
        while (!queue.isEmpty()) {
            // Pop a node say "n" from the from the front of the queue.
            Node n = queue.remove();
            // Iterate through all the neighbors of the node "n"
            for (Node neighbor : n.neighbors) {
                if (!visited.containsKey(neighbor)) {
                    // Clone the neighbor and put in the visited, if not present already
                    visited.put(
                        neighbor,
                        new Node(neighbor.val, new ArrayList())
                    );
                    // Add the newly encountered node to the queue.
                    queue.add(neighbor);
                }
                // Add the clone of the neighbor to the neighbors of the clone node "n".
                visited.get(n).neighbors.add(visited.get(neighbor));
            }
        }

        // Return the clone of the node from visited.
        return visited.get(node);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var cloneGraph = function (node) {
    if (node === null) return node;
    // Hash map to save the visited node and it's respective clone
    // as key and value respectively. This helps to avoid cycles.
    const visited = new Map();
    // Put the first node in the queue
    const queue = [node];
    // Clone the node and put it in the visited dictionary.
    visited.set(node, { val: node.val, neighbors: [] });
    // Start BFS traversal
    while (queue.length > 0) {
        const n = queue.shift();
        n.neighbors.forEach((neighbor) => {
            if (!visited.has(neighbor)) {
                // Clone the neighbor and put in the visited, if not present already
                visited.set(neighbor, { val: neighbor.val, neighbors: [] });
                // Add the newly encountered node to the queue.
                queue.push(neighbor);
            }
            // Add the clone of the neighbor to the neighbors of the clone node "n".
            visited.get(n).neighbors.push(visited.get(neighbor));
        });
    }
    // Return the clone of the node from visited.
    return visited.get(node);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from collections import deque


class Solution:

    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:

        if not node:
            return node

        # Dictionary to save the visited node and it's respective clone
        # as key and value respectively. This helps to avoid cycles.
        visited = {}

        # Put the first node in the queue
        queue = deque([node])
        # Clone the node and put it in the visited dictionary.
        visited[node] = Node(node.val, [])

        # Start BFS traversal
        while queue:
            # Pop a node say "n" from the from the front of the queue.
            n = queue.popleft()
            # Iterate through all the neighbors of the node
            for neighbor in n.neighbors:
                if neighbor not in visited:
                    # Clone the neighbor and put in the visited, if not present already
                    visited[neighbor] = Node(neighbor.val, [])
                    # Add the newly encountered node to the queue.
                    queue.append(neighbor)
                # Add the clone of the neighbor to the neighbors of the clone node "n".
                visited[n].neighbors.append(visited[neighbor])

        # Return the clone of the node from visited.
        return visited[node]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
/*
// Definition of Node for TypeScript:
class Node {
    val: number
    neighbors: Node[]
    constructor(val?: number, neighbors?: Node[]) {
        this.val = (val === undefined ? 0 : val)
        this.neighbors = (neighbors === undefined ? [] : neighbors)
    }
}
*/
function cloneGraph(node: Node | null): Node | null {
    if (!node) return node;
    // Dictionary to save the visited node and it's respective clone
    // as key and value respectively. This helps to avoid cycles.
    let visited: Map<Node, Node> = new Map();
    // Put the first node in the queue
    let queue: Node[] = [];
    queue.push(node);
    // Clone the node and put it in the visited dictionary.
    visited.set(node, new Node(node.val, []));
    // Start BFS traversal
    while (queue.length > 0) {
        // Pop a node say "n" from the from the front of the queue.
        let n: Node = queue.shift() as Node;
        // Iterate through all the neighbors of the node
        for (let neighbor of n.neighbors) {
            if (!visited.has(neighbor)) {
                // Clone the neighbor and put in the visited, if not present already
                visited.set(neighbor, new Node(neighbor.val, []));
                // Add the newly encountered node to the queue.
                queue.push(neighbor);
            }
            // Add the clone of the neighbor to the neighbors of the clone node "n".
            visited.get(n)?.neighbors.push(visited.get(neighbor) as Node);
        }
    }
    // Return the clone of the node from visited.
    return visited.get(node) as Node;
}
```

</details>
