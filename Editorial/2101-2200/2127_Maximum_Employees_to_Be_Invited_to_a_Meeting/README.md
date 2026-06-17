# 2127. Maximum Employees to Be Invited to a Meeting

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/)  
`Array` `Dynamic Programming` `Depth-First Search` `Graph Theory` `Topological Sort`

**Problem Link:** [LeetCode 2127 - Maximum Employees to Be Invited to a Meeting](https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/)

## Problem

A company is organizing a meeting and has a list of n employees, waiting to be invited. They have arranged for a large circular table, capable of seating any number of employees.

The employees are numbered from 0 to n - 1. Each employee has a favorite person and they will attend the meeting only if they can sit next to their favorite person at the table. The favorite person of an employee is not themself.

Given a 0-indexed integer array favorite, where favorite[i] denotes the favorite person of the ith employee, return the maximum number of employees that can be invited to the meeting.

### Example 1

```text
Input: favorite = [2,2,1,2]
Output: 3
Explanation:
The above figure shows how the company can invite employees 0, 1, and 2, and seat them at the round table.
All employees cannot be invited because employee 2 cannot sit beside employees 0, 1, and 3, simultaneously.
Note that the company can also invite employees 1, 2, and 3, and give them their desired seats.
The maximum number of employees that can be invited to the meeting is 3.
```

### Example 2

```text
Input: favorite = [1,2,0]
Output: 3
Explanation:
Each employee is the favorite person of at least one other employee, and the only way the company can invite them is if they invite every employee.
The seating arrangement will be the same as that in the figure given in example 1:
- Employee 0 will sit between employees 2 and 1.
- Employee 1 will sit between employees 0 and 2.
- Employee 2 will sit between employees 1 and 0.
The maximum number of employees that can be invited to the meeting is 3.
```

### Example 3

```text
Input: favorite = [3,0,1,4,1]
Output: 4
Explanation:
The above figure shows how the company will invite employees 0, 1, 3, and 4, and seat them at the round table.
Employee 2 cannot be invited because the two spots next to their favorite employee 1 are taken.
So the company leaves them out of the meeting.
The maximum number of employees that can be invited to the meeting is 4.
```

## Constraints

- n == favorite.length
- 2 <= n <= 105
- 0 <= favorite[i] <= n - 1
- favorite[i] != i

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Redundant Connection](https://leetcode.com/problems/redundant-connection/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Parallel Courses III](https://leetcode.com/problems/parallel-courses-iii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Process Restricted Friend Requests](https://leetcode.com/problems/process-restricted-friend-requests/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2127. Maximum Employees to Be Invited to a Meeting

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Cycle Detection with Extended Paths | C++, Java, Python3 |
| Topological Sort to Reduce Non-Cyclic Nodes | C++, Java, Python3 |

## Approach 1: Cycle Detection with Extended Paths

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<vector<int>> reversedGraph(n);
        for (int person = 0; person < n; ++person) {
            reversedGraph[favorite[person]].push_back(person);
        }

        // Helper function for BFS
        auto bfs = [&](int startNode, unordered_set<int>& visitedNodes) -> int {
            queue<pair<int, int>> q;
            q.push({startNode, 0});
            int maxDistance = 0;
            while (!q.empty()) {
                auto [currentNode, currentDistance] = q.front();
                q.pop();
                for (int neighbor : reversedGraph[currentNode]) {
                    if (visitedNodes.count(neighbor)) continue;
                    visitedNodes.insert(neighbor);
                    q.push({neighbor, currentDistance + 1});
                    maxDistance = max(maxDistance, currentDistance + 1);
                }
            }
            return maxDistance;
        };

        int longestCycle = 0, twoCycleInvitations = 0;
        vector<bool> visited(n, false);

        // Find all cycles
        for (int person = 0; person < n; ++person) {
            if (!visited[person]) {
                unordered_map<int, int> visitedPersons;
                int current = person;
                int distance = 0;
                while (true) {
                    if (visited[current]) break;
                    visited[current] = true;
                    visitedPersons[current] = distance++;
                    int nextPerson = favorite[current];
                    if (visitedPersons.count(nextPerson)) {  // Cycle detected
                        int cycleLength = distance - visitedPersons[nextPerson];
                        longestCycle = max(longestCycle, cycleLength);
                        if (cycleLength == 2) {
                            unordered_set<int> visitedNodes = {current,
                                                               nextPerson};
                            twoCycleInvitations +=
                                2 + bfs(nextPerson, visitedNodes) +
                                bfs(current, visitedNodes);
                        }
                        break;
                    }
                    current = nextPerson;
                }
            }
        }

        return max(longestCycle, twoCycleInvitations);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Calculate the maximum distance from a given start node
    private int bfs(
        int startNode,
        Set<Integer> visitedNodes,
        List<List<Integer>> reversedGraph
    ) {
        // Queue to store nodes and their distances
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[] { startNode, 0 });
        int maxDistance = 0;
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int currentNode = current[0];
            int currentDistance = current[1];
            for (int neighbor : reversedGraph.get(currentNode)) {
                if (visitedNodes.contains(neighbor)) continue; // Skip already visited nodes
                visitedNodes.add(neighbor);
                queue.offer(new int[] { neighbor, currentDistance + 1 });
                maxDistance = Math.max(maxDistance, currentDistance + 1);
            }
        }
        return maxDistance;
    }

    public int maximumInvitations(int[] favorite) {
        int numPeople = favorite.length;
        List<List<Integer>> reversedGraph = new ArrayList<>(numPeople);
        // Build the reversed graph where each node points to its admirers
        for (int i = 0; i < numPeople; i++) {
            reversedGraph.add(new ArrayList<>());
        }
        for (int person = 0; person < numPeople; person++) {
            reversedGraph.get(favorite[person]).add(person);
        }

        int longestCycle = 0;
        int twoCycleInvitations = 0;
        boolean[] visited = new boolean[numPeople];

        // Find all cycles in the graph
        for (int person = 0; person < numPeople; person++) {
            if (!visited[person]) {
                // Track visited persons and their distances
                Map<Integer, Integer> visitedPersons = new HashMap<>();
                int currentPerson = person;
                int distance = 0;
                while (true) {
                    if (visited[currentPerson]) break;
                    visited[currentPerson] = true;
                    visitedPersons.put(currentPerson, distance++);
                    int nextPerson = favorite[currentPerson];

                    // Cycle detected
                    if (visitedPersons.containsKey(nextPerson)) {
                        int cycleLength =
                            distance - visitedPersons.get(nextPerson);
                        longestCycle = Math.max(longestCycle, cycleLength);

                        // Handle cycles of length 2
                        if (cycleLength == 2) {
                            Set<Integer> visitedNodes = new HashSet<>();
                            visitedNodes.add(currentPerson);
                            visitedNodes.add(nextPerson);
                            twoCycleInvitations +=
                                2 +
                                bfs(nextPerson, visitedNodes, reversedGraph) +
                                bfs(currentPerson, visitedNodes, reversedGraph);
                        }
                        break;
                    }
                    currentPerson = nextPerson;
                }
            }
        }
        return Math.max(longestCycle, twoCycleInvitations);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumInvitations(self, favorite: List[int]) -> int:
        # Calculate the maximum distance from a given start node
        def _bfs(
            start_node: int, visited_nodes: set, reversed_graph: List[List[int]]
        ) -> int:
            # Queue to store nodes and their distances
            queue = deque([(start_node, 0)])
            max_distance = 0
            while queue:
                current_node, current_distance = queue.popleft()
                for neighbor in reversed_graph[current_node]:
                    if neighbor in visited_nodes:
                        continue  # Skip already visited nodes
                    visited_nodes.add(neighbor)
                    queue.append((neighbor, current_distance + 1))
                    max_distance = max(max_distance, current_distance + 1)
            return max_distance

        num_people = len(favorite)
        reversed_graph = [[] for _ in range(num_people)]

        # Build the reversed graph where each node points to its admirers
        for person in range(num_people):
            reversed_graph[favorite[person]].append(person)

        longest_cycle = 0
        two_cycle_invitations = 0
        visited = [False] * num_people

        # Find all cycles in the graph
        for person in range(num_people):
            if not visited[person]:

                # Track visited persons and their distances
                visited_persons = {}
                current_person = person
                distance = 0
                while True:
                    if visited[current_person]:
                        break
                    visited[current_person] = True
                    visited_persons[current_person] = distance
                    distance += 1
                    next_person = favorite[current_person]

                    # Cycle detected
                    if next_person in visited_persons:
                        cycle_length = distance - visited_persons[next_person]
                        longest_cycle = max(longest_cycle, cycle_length)

                        # Handle cycles of length 2
                        if cycle_length == 2:
                            visited_nodes = {current_person, next_person}
                            two_cycle_invitations += (
                                2
                                + _bfs(
                                    next_person, visited_nodes, reversed_graph
                                )
                                + _bfs(
                                    current_person,
                                    visited_nodes,
                                    reversed_graph,
                                )
                            )
                        break
                    current_person = next_person

        return max(longest_cycle, two_cycle_invitations)
```

</details>

<br>

## Approach 2: Topological Sort to Reduce Non-Cyclic Nodes

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> inDegree(n, 0);

        // Calculate in-degree for each node
        for (int person = 0; person < n; ++person) {
            inDegree[favorite[person]]++;
        }

        // Topological sorting to remove non-cycle nodes
        queue<int> q;
        for (int person = 0; person < n; ++person) {
            if (inDegree[person] == 0) {
                q.push(person);
            }
        }

        vector<int> depth(n, 1);  // Depth of each node
        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();
            int nextNode = favorite[currentNode];
            depth[nextNode] = max(depth[nextNode], depth[currentNode] + 1);
            if (--inDegree[nextNode] == 0) {
                q.push(nextNode);
            }
        }

        int longestCycle = 0;
        int twoCycleInvitations = 0;

        // Detect cycles
        for (int person = 0; person < n; ++person) {
            if (inDegree[person] == 0) continue;  // Already processed

            int cycleLength = 0;
            int current = person;
            while (inDegree[current] != 0) {
                inDegree[current] = 0;  // Mark as visited
                cycleLength++;
                current = favorite[current];
            }

            if (cycleLength == 2) {
                // For 2-cycles, add the depth of both nodes
                twoCycleInvitations += depth[person] + depth[favorite[person]];
            } else {
                longestCycle = max(longestCycle, cycleLength);
            }
        }

        return max(longestCycle, twoCycleInvitations);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maximumInvitations(int[] favorite) {
        int n = favorite.length;
        int[] inDegree = new int[n];

        // Calculate in-degree for each node
        for (int person = 0; person < n; ++person) {
            inDegree[favorite[person]]++;
        }

        // Topological sorting to remove non-cycle nodes
        Queue<Integer> q = new LinkedList<>();
        for (int person = 0; person < n; ++person) {
            if (inDegree[person] == 0) {
                q.offer(person);
            }
        }

        int[] depth = new int[n]; // Depth of each node
        Arrays.fill(depth, 1);

        while (!q.isEmpty()) {
            int currentNode = q.poll();
            int nextNode = favorite[currentNode];
            depth[nextNode] = Math.max(depth[nextNode], depth[currentNode] + 1);
            if (--inDegree[nextNode] == 0) {
                q.offer(nextNode);
            }
        }

        int longestCycle = 0;
        int twoCycleInvitations = 0;

        // Detect cycles
        for (int person = 0; person < n; ++person) {
            if (inDegree[person] == 0) continue; // Already processed

            int cycleLength = 0;
            int current = person;
            while (inDegree[current] != 0) {
                inDegree[current] = 0; // Mark as visited
                cycleLength++;
                current = favorite[current];
            }

            if (cycleLength == 2) {
                // For 2-cycles, add the depth of both nodes
                twoCycleInvitations += depth[person] + depth[favorite[person]];
            } else {
                longestCycle = Math.max(longestCycle, cycleLength);
            }
        }

        return Math.max(longestCycle, twoCycleInvitations);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumInvitations(self, favorite: List[int]) -> int:
        n = len(favorite)
        in_degree = [0] * n

        # Calculate in-degree for each node
        for person in range(n):
            in_degree[favorite[person]] += 1

        # Topological sorting to remove non-cycle nodes
        q = deque()
        for person in range(n):
            if in_degree[person] == 0:
                q.append(person)
        depth = [1] * n  # Depth of each node

        while q:
            current_node = q.popleft()
            next_node = favorite[current_node]
            depth[next_node] = max(depth[next_node], depth[current_node] + 1)
            in_degree[next_node] -= 1
            if in_degree[next_node] == 0:
                q.append(next_node)

        longest_cycle = 0
        two_cycle_invitations = 0

        # Detect cycles
        for person in range(n):
            if in_degree[person] == 0:  # Already processed
                continue

            cycle_length = 0
            current = person
            while in_degree[current] != 0:
                in_degree[current] = 0  # Mark as visited
                cycle_length += 1
                current = favorite[current]

            if cycle_length == 2:
                # For 2-cycles, add the depth of both nodes
                two_cycle_invitations += depth[person] + depth[favorite[person]]
            else:
                longest_cycle = max(longest_cycle, cycle_length)

        return max(longest_cycle, two_cycle_invitations)
```

</details>
