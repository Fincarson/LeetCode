# 2467. Most Profitable Path in a Tree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/most-profitable-path-in-a-tree/)  
`Array` `Tree` `Depth-First Search` `Breadth-First Search` `Graph Theory`

**Problem Link:** [LeetCode 2467 - Most Profitable Path in a Tree](https://leetcode.com/problems/most-profitable-path-in-a-tree/)

## Problem

There is an undirected tree with n nodes labeled from 0 to n - 1, rooted at node 0. You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

At every node i, there is a gate. You are also given an array of even integers amount, where amount[i] represents:

- the price needed to open the gate at node i, if amount[i] is negative, or,
- the cash reward obtained on opening the gate at node i, otherwise.

The game goes on as follows:

- Initially, Alice is at node 0 and Bob is at node bob.
- At every second, Alice and Bob each move to an adjacent node. Alice moves towards some leaf node, while Bob moves towards node 0.
- For every node along their path, Alice and Bob either spend money to open the gate at that node, or accept the reward. Note that:

		If the gate is already open, no price will be required, nor will there be any cash reward.
		If Alice and Bob reach the node simultaneously, they share the price/reward for opening the gate there. In other words, if the price to open the gate is c, then both Alice and Bob pay c / 2 each. Similarly, if the reward at the gate is c, both of them receive c / 2 each.
- If Alice reaches a leaf node, she stops moving. Similarly, if Bob reaches node 0, he stops moving. Note that these events are independent of each other.

Return the maximum net income Alice can have if she travels towards the optimal leaf node.

### Example 1

```text
Input: edges = [[0,1],[1,2],[1,3],[3,4]], bob = 3, amount = [-2,4,2,-4,6]
Output: 6
Explanation:
The above diagram represents the given tree. The game goes as follows:
- Alice is initially on node 0, Bob on node 3. They open the gates of their respective nodes.
  Alice's net income is now -2.
- Both Alice and Bob move to node 1.
  Since they reach here simultaneously, they open the gate together and share the reward.
  Alice's net income becomes -2 + (4 / 2) = 0.
- Alice moves on to node 3. Since Bob already opened its gate, Alice's income remains unchanged.
  Bob moves on to node 0, and stops moving.
- Alice moves on to node 4 and opens the gate there. Her net income becomes 0 + 6 = 6.
Now, neither Alice nor Bob can make any further moves, and the game ends.
It is not possible for Alice to get a higher net income.
```

### Example 2

```text
Input: edges = [[0,1]], bob = 1, amount = [-7280,2350]
Output: -7280
Explanation:
Alice follows the path 0->1 whereas Bob follows the path 1->0.
Thus, Alice opens the gate at node 0 only. Hence, her net income is -7280.
```

## Constraints

- 2 <= n <= 105
- edges.length == n - 1
- edges[i].length == 2
- 0 <= ai, bi < n
- ai != bi
- edges represents a valid tree.
- 1 <= bob < n
- amount.length == n
- amount[i] is an even integer in the range [-104, 104].

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Snakes and Ladders](https://leetcode.com/problems/snakes-and-ladders/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Time Taken to Mark All Nodes](https://leetcode.com/problems/time-taken-to-mark-all-nodes/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2467. Most Profitable Path in a Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search and Breadth-First Search | C++, Java, Python3 |
| Two Depth-First Searches | C++, Java, Python3 |
| Depth-First Search | C++, Java, Python3 |

## Approach 1: Depth-First Search and Breadth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        int n = amount.size(), maxIncome = INT_MIN;
        tree.resize(n);
        visited.assign(n, false);
        queue<vector<int>> nodeQueue;
        nodeQueue.push({0, 0, 0});

        // Form tree with edges
        for (vector<int> edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        // Find the path taken by bob to reach node 0 and the times it takes to
        // get there
        findBobPath(bob, 0);

        // Breadth First Search
        visited.assign(n, false);
        while (!nodeQueue.empty()) {
            int sourceNode = nodeQueue.front()[0], time = nodeQueue.front()[1],
                income = nodeQueue.front()[2];

            // Alice reaches the node first
            if (bobPath.find(sourceNode) == bobPath.end() ||
                time < bobPath[sourceNode]) {
                income += amount[sourceNode];
            }

            // Alice and Bob reach the node at the same time
            else if (time == bobPath[sourceNode]) {
                income += (amount[sourceNode] / 2);
            }

            // Update max value if current node is a new leaf
            if (tree[sourceNode].size() == 1 && sourceNode != 0) {
                maxIncome = max(maxIncome, income);
            }
            // Explore adjacent unvisited vertices
            for (int adjacentNode : tree[sourceNode]) {
                if (!visited[adjacentNode]) {
                    nodeQueue.push({adjacentNode, time + 1, income});
                }
            }

            // Mark and remove current node
            visited[sourceNode] = true;
            nodeQueue.pop();
        }
        return maxIncome;
    }

private:
    unordered_map<int, int> bobPath;
    vector<bool> visited;
    vector<vector<int>> tree;

    // Depth First Search
    bool findBobPath(int sourceNode, int time) {
        // Mark and set time node is reached
        bobPath[sourceNode] = time;
        visited[sourceNode] = true;

        // Destination for Bob is found
        if (sourceNode == 0) {
            return true;
        }

        // Traverse through unvisited nodes
        for (auto adjacentNode : tree[sourceNode]) {
            if (!visited[adjacentNode]) {
                if (findBobPath(adjacentNode, time + 1)) {
                    return true;
                }
            }
        }
        // If node 0 isn't reached, remove current node from path
        bobPath.erase(sourceNode);
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int mostProfitablePath(int[][] edges, int bob, int[] amount) {
        int n = amount.length, maxIncome = Integer.MIN_VALUE;
        tree = new ArrayList<>();
        bobPath = new HashMap<>();
        visited = new boolean[n];
        Queue<int[]> nodeQueue = new LinkedList<>();
        nodeQueue.add(new int[] { 0, 0, 0 });
        for (int i = 0; i < n; i++) {
            tree.add(new ArrayList<>());
        }

        // Form tree with edges
        for (int[] edge : edges) {
            tree.get(edge[0]).add(edge[1]);
            tree.get(edge[1]).add(edge[0]);
        }

        // Find the path taken by Bob to reach node 0 and the times it takes to get there
        findBobPath(bob, 0);

        // Breadth First Search
        Arrays.fill(visited, false);
        while (!nodeQueue.isEmpty()) {
            int[] node = nodeQueue.poll();
            int sourceNode = node[0], time = node[1], income = node[2];

            // Alice reaches the node first
            if (
                !bobPath.containsKey(sourceNode) ||
                time < bobPath.get(sourceNode)
            ) {
                income += amount[sourceNode];
            }
            // Alice and Bob reach the node at the same time
            else if (time == bobPath.get(sourceNode)) {
                income += amount[sourceNode] / 2;
            }

            // Update max value if current node is a new leaf
            if (tree.get(sourceNode).size() == 1 && sourceNode != 0) {
                maxIncome = Math.max(maxIncome, income);
            }
            // Explore adjacent unvisited vertices
            for (int adjacentNode : tree.get(sourceNode)) {
                if (!visited[adjacentNode]) {
                    nodeQueue.add(new int[] { adjacentNode, time + 1, income });
                }
            }

            // Mark and remove current node
            visited[sourceNode] = true;
        }
        return maxIncome;
    }

    private Map<Integer, Integer> bobPath;
    private boolean[] visited;
    private List<List<Integer>> tree;

    // Depth First Search
    private boolean findBobPath(int sourceNode, int time) {
        // Mark and set time node is reached
        bobPath.put(sourceNode, time);
        visited[sourceNode] = true;

        // Destination for Bob is found
        if (sourceNode == 0) {
            return true;
        }

        // Traverse through unvisited nodes
        for (int adjacentNode : tree.get(sourceNode)) {
            if (!visited[adjacentNode]) {
                if (findBobPath(adjacentNode, time + 1)) {
                    return true;
                }
            }
        }
        // If node 0 isn't reached, remove current node from path
        bobPath.remove(sourceNode);
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def mostProfitablePath(self, edges, bob, amount):
        n = len(amount)
        max_income = float("-inf")
        tree = [[] for _ in range(n)]
        bob_path = {}
        visited = [False] * n

        # Form tree with edges
        for edge in edges:
            tree[edge[0]].append(edge[1])
            tree[edge[1]].append(edge[0])

        # Inline DFS to find Bob's path
        def find_bob_path(node, time):
            bob_path[node] = time
            visited[node] = True

            if node == 0:
                return True
            for neighbor in tree[node]:
                if not visited[neighbor]:
                    if find_bob_path(neighbor, time + 1):
                        return True
            bob_path.pop(node, None)
            return False

        # Find the path taken by Bob
        find_bob_path(bob, 0)

        # Breadth-First Search (BFS)
        visited = [False] * n
        queue = deque([(0, 0, 0)])

        while queue:
            node, time, income = queue.popleft()

            # Alice reaches the node first
            if node not in bob_path or time < bob_path[node]:
                income += amount[node]
            elif time == bob_path[node]:  # Alice and Bob arrive together
                income += amount[node] // 2

            # Update max value if current node is a leaf
            if len(tree[node]) == 1 and node != 0:
                max_income = max(max_income, income)

            # Explore adjacent unvisited nodes
            for neighbor in tree[node]:
                if not visited[neighbor]:
                    queue.append((neighbor, time + 1, income))
            visited[node] = True

        return max_income
```

</details>

<br>

## Approach 2: Two Depth-First Searches

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        int n = amount.size();
        tree.resize(n);
        visited.assign(n, false);

        // Form tree with edges
        for (vector<int> edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        // Find the path taken by Bob to reach node 0 and the times it takes to
        // get there
        findBobPath(bob, 0);

        // Find Alice's optimal path
        visited.assign(n, false);
        findAlicePath(0, 0, 0, amount);

        return maxIncome;
    }

private:
    unordered_map<int, int> bobPath;
    vector<bool> visited;
    vector<vector<int>> tree;
    int maxIncome = INT_MIN;

    // Depth First Search to find Bob's path
    bool findBobPath(int sourceNode, int time) {
        // Mark and set time node is reached
        bobPath[sourceNode] = time;
        visited[sourceNode] = true;

        // Destination for Bob is found
        if (sourceNode == 0) {
            return true;
        }

        // Traverse through unvisited nodes
        for (int adjacentNode : tree[sourceNode]) {
            if (!visited[adjacentNode] && findBobPath(adjacentNode, time + 1)) {
                return true;
            }
        }

        // If node 0 isn't reached, remove current node from path
        bobPath.erase(sourceNode);
        return false;
    }

    // Depth First Search to find Alice's optimal path
    void findAlicePath(int sourceNode, int time, int income,
                       vector<int>& amount) {
        // Mark node as explored
        visited[sourceNode] = true;

        // Alice reaches the node first
        if (bobPath.find(sourceNode) == bobPath.end() ||
            time < bobPath[sourceNode]) {
            income += amount[sourceNode];
        }

        // Alice and Bob reach the node at the same time
        else if (time == bobPath[sourceNode]) {
            income += (amount[sourceNode] / 2);
        }

        // Update max value if current node is a new leaf
        if (tree[sourceNode].size() == 1 && sourceNode != 0) {
            maxIncome = max(maxIncome, income);
        }

        // Traverse through unvisited nodes
        for (int adjacentNode : tree[sourceNode]) {
            if (!visited[adjacentNode]) {
                findAlicePath(adjacentNode, time + 1, income, amount);
            }
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int mostProfitablePath(int[][] edges, int bob, int[] amount) {
        int n = amount.length;
        tree = new ArrayList<>();
        bobPath = new HashMap<>();
        visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            tree.add(new ArrayList<>());
        }

        // Form tree with edges
        for (int[] edge : edges) {
            tree.get(edge[0]).add(edge[1]);
            tree.get(edge[1]).add(edge[0]);
        }

        // Find the path taken by Bob to reach node 0 and the times it takes to get there
        findBobPath(bob, 0);

        // Find Alice's optimal path
        Arrays.fill(visited, false);
        findAlicePath(0, 0, 0, amount);

        return maxIncome;
    }

    private Map<Integer, Integer> bobPath;
    private boolean[] visited;
    private List<List<Integer>> tree;
    private int maxIncome = Integer.MIN_VALUE;

    // Depth First Search to find Bob's path
    private boolean findBobPath(int sourceNode, int time) {
        // Mark and set time node is reached
        bobPath.put(sourceNode, time);
        visited[sourceNode] = true;

        // Destination for Bob is found
        if (sourceNode == 0) {
            return true;
        }

        // Traverse through unvisited nodes
        for (int adjacentNode : tree.get(sourceNode)) {
            if (!visited[adjacentNode] && findBobPath(adjacentNode, time + 1)) {
                return true;
            }
        }

        // If node 0 isn't reached, remove current node from path
        bobPath.remove(sourceNode);
        return false;
    }

    // Depth First Search to find Alice's optimal path
    private void findAlicePath(
        int sourceNode,
        int time,
        int income,
        int[] amount
    ) {
        // Mark node as explored
        visited[sourceNode] = true;

        // Alice reaches the node first
        if (
            !bobPath.containsKey(sourceNode) || time < bobPath.get(sourceNode)
        ) {
            income += amount[sourceNode];
        }
        // Alice and Bob reach the node at the same time
        else if (time == bobPath.get(sourceNode)) {
            income += amount[sourceNode] / 2;
        }

        // Update max value if current node is a new leaf
        if (tree.get(sourceNode).size() == 1 && sourceNode != 0) {
            maxIncome = Math.max(maxIncome, income);
        }

        // Traverse through unvisited nodes
        for (int adjacentNode : tree.get(sourceNode)) {
            if (!visited[adjacentNode]) {
                findAlicePath(adjacentNode, time + 1, income, amount);
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def mostProfitablePath(self, edges, bob, amount):
        n = len(amount)
        tree = [[] for _ in range(n)]
        bob_path = {}
        visited = [False] * n
        max_income = float("-inf")

        # Form tree with edges
        for edge in edges:
            tree[edge[0]].append(edge[1])
            tree[edge[1]].append(edge[0])

        # Depth First Search to find Bob's path
        def find_bob_path(node, time):
            bob_path[node] = time
            visited[node] = True

            if node == 0:
                return True
            for neighbor in tree[node]:
                if not visited[neighbor] and find_bob_path(neighbor, time + 1):
                    return True
            bob_path.pop(node, None)
            return False

        # Find Bob's path
        find_bob_path(bob, 0)

        # Reset visited array for Alice's path
        visited = [False] * n

        # Depth First Search to find Alice's optimal path
        def find_alice_path(node, time, income):
            nonlocal max_income
            visited[node] = True

            # Alice reaches the node first
            if node not in bob_path or time < bob_path[node]:
                income += amount[node]
            elif time == bob_path[node]:  # Alice and Bob arrive together
                income += amount[node] // 2

            # Update max value if current node is a leaf
            if len(tree[node]) == 1 and node != 0:
                max_income = max(max_income, income)
            for neighbor in tree[node]:
                if not visited[neighbor]:
                    find_alice_path(neighbor, time + 1, income)

        # Find Alice's path
        find_alice_path(0, 0, 0)

        return max_income
```

</details>

<br>

## Approach 3: Depth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        n = amount.size();
        tree.resize(n, vector<int>());

        // Form tree with edges
        for (vector<int> edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        distanceFromBob.resize(n);
        return findPaths(0, 0, 0, bob, amount);
    }

private:
    vector<vector<int>> tree;
    vector<int> distanceFromBob;
    int n;

    // Depth-first Search
    int findPaths(int sourceNode, int parentNode, int time, int bob,
                  vector<int>& amount) {
        int maxIncome = 0, maxChild = INT_MIN;

        // Find the node distances from Bob
        if (sourceNode == bob)
            distanceFromBob[sourceNode] = 0;
        else
            distanceFromBob[sourceNode] = n;
        for (int adjacentNode : tree[sourceNode]) {
            if (adjacentNode != parentNode) {
                maxChild = max(maxChild, findPaths(adjacentNode, sourceNode,
                                                   time + 1, bob, amount));
                distanceFromBob[sourceNode] =
                    min(distanceFromBob[sourceNode],
                        distanceFromBob[adjacentNode] + 1);
            }
        }
        // Alice reaches the node first
        if (distanceFromBob[sourceNode] > time) maxIncome += amount[sourceNode];

        // Alice and Bob reach the node at the same time
        else if (distanceFromBob[sourceNode] == time)
            maxIncome += amount[sourceNode] / 2;

        // Return max income of leaf node
        if (maxChild == INT_MIN)
            return maxIncome;
        else
            return maxIncome + maxChild;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int mostProfitablePath(int[][] edges, int bob, int[] amount) {
        n = amount.length;
        tree = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            tree.add(new ArrayList<>());
        }
        distanceFromBob = new int[n];

        // Form tree with edges
        for (int[] edge : edges) {
            tree.get(edge[0]).add(edge[1]);
            tree.get(edge[1]).add(edge[0]);
        }

        return findPaths(0, 0, 0, bob, amount);
    }

    private List<List<Integer>> tree;
    private int[] distanceFromBob;
    private int n;

    // Depth-first Search
    private int findPaths(
        int sourceNode,
        int parentNode,
        int time,
        int bob,
        int[] amount
    ) {
        int maxIncome = 0, maxChild = Integer.MIN_VALUE;

        // Find the node distances from Bob
        if (sourceNode == bob) {
            distanceFromBob[sourceNode] = 0;
        } else {
            distanceFromBob[sourceNode] = n;
        }

        for (int adjacentNode : tree.get(sourceNode)) {
            if (adjacentNode != parentNode) {
                maxChild = Math.max(
                    maxChild,
                    findPaths(adjacentNode, sourceNode, time + 1, bob, amount)
                );
                distanceFromBob[sourceNode] = Math.min(
                    distanceFromBob[sourceNode],
                    distanceFromBob[adjacentNode] + 1
                );
            }
        }

        // Alice reaches the node first
        if (distanceFromBob[sourceNode] > time) {
            maxIncome += amount[sourceNode];
        }
        // Alice and Bob reach the node at the same time
        else if (distanceFromBob[sourceNode] == time) {
            maxIncome += amount[sourceNode] / 2;
        }

        // Return max income of leaf node
        return (maxChild == Integer.MIN_VALUE)
            ? maxIncome
            : maxIncome + maxChild;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def mostProfitablePath(self, edges, bob, amount):
        n = len(amount)
        tree = [[] for _ in range(n)]
        distance_from_bob = [0] * n

        # Form tree with edges
        for edge in edges:
            tree[edge[0]].append(edge[1])
            tree[edge[1]].append(edge[0])

        # Depth-first search to find paths and compute max income
        def find_paths(node, parent, time):
            max_income = 0
            max_child = float("-inf")

            # Find node distances from Bob
            if node == bob:
                distance_from_bob[node] = 0
            else:
                distance_from_bob[node] = n
            for neighbor in tree[node]:
                if neighbor != parent:
                    max_child = max(
                        max_child, find_paths(neighbor, node, time + 1)
                    )
                    distance_from_bob[node] = min(
                        distance_from_bob[node], distance_from_bob[neighbor] + 1
                    )

            # Alice reaches first
            if distance_from_bob[node] > time:
                max_income += amount[node]

            # Alice and Bob reach at the same time
            elif distance_from_bob[node] == time:
                max_income += amount[node] // 2
            return (
                max_income
                if max_child == float("-inf")
                else max_income + max_child
            )

        return find_paths(0, -1, 0)
```

</details>
