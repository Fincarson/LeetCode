# 2092. Find All People With Secret

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/find-all-people-with-secret/)  
`Depth-First Search` `Breadth-First Search` `Union-Find` `Graph Theory` `Sorting`

**Problem Link:** [LeetCode 2092 - Find All People With Secret](https://leetcode.com/problems/find-all-people-with-secret/)

## Problem

You are given an integer n indicating there are n people numbered from 0 to n - 1. You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a meeting at timei. A person may attend multiple meetings at the same time. Finally, you are given an integer firstPerson.

Person 0 has a secret and initially shares the secret with a person firstPerson at time 0. This secret is then shared every time a meeting takes place with a person that has the secret. More formally, for every meeting, if a person xi has the secret at timei, then they will share the secret with person yi, and vice versa.

The secrets are shared instantaneously. That is, a person may receive the secret and share it with people in other meetings within the same time frame.

Return a list of all the people that have the secret after all the meetings have taken place. You may return the answer in any order.

### Example 1

```text
Input: n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
Output: [0,1,2,3,5]
Explanation:
At time 0, person 0 shares the secret with person 1.
At time 5, person 1 shares the secret with person 2.
At time 8, person 2 shares the secret with person 3.
At time 10, person 1 shares the secret with person 5.Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹
Thus, people 0, 1, 2, 3, and 5 know the secret after all the meetings.
```

### Example 2

```text
Input: n = 4, meetings = [[3,1,3],[1,2,2],[0,3,3]], firstPerson = 3
Output: [0,1,3]
Explanation:
At time 0, person 0 shares the secret with person 3.
At time 2, neither person 1 nor person 2 know the secret.
At time 3, person 3 shares the secret with person 0 and person 1.
Thus, people 0, 1, and 3 know the secret after all the meetings.
```

### Example 3

```text
Input: n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], firstPerson = 1
Output: [0,1,2,3,4]
Explanation:
At time 0, person 0 shares the secret with person 1.
At time 1, person 1 shares the secret with person 2, and person 2 shares the secret with person 3.
Note that person 2 can share the secret at the same time as receiving it.
At time 2, person 3 shares the secret with person 4.
Thus, people 0, 1, 2, 3, and 4 know the secret after all the meetings.
```

## Constraints

- 2 <= n <= 105
- 1 <= meetings.length <= 105
- meetings[i].length == 3
- 0 <= xi, yi <= n - 1
- xi != yi
- 1 <= timei <= 105
- 1 <= firstPerson <= n - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reachable Nodes In Subdivided Graph](https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2092. Find All People With Secret

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth First Search | C++, Java, Python3 |
| Depth First Search | C++, Java, Python3 |
| Earliest Informed First Traversal | C++, Java, Python3 |
| Breadth First Search on Time Scale | C++, Java, Python3 |
| Union-Find with Reset | C++, Java, Python3 |

## Approach 1: Breadth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        // For every person, we store the meeting time and label of the person
        // met.
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto& meeting : meetings) {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            graph[x].emplace_back(t, y);
            graph[y].emplace_back(t, x);
        }

        // Earliest time at which a person learned the secret
        // as per current state of knowledge. If due to some new information,
        // the earliest time of knowing the secret changes, we will update it
        // and again process all the people whom he/she meets after the time
        // at which he/she learned the secret.
        vector<int> earliest(n, INT_MAX);
        earliest[0] = 0;
        earliest[firstPerson] = 0;

        // Queue for BFS. It will store (person, time of knowing the secret)
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        q.emplace(firstPerson, 0);

        // Do BFS
        while (!q.empty()) {
            auto [person, time] = q.front();
            q.pop();
            for (auto [t, nextPerson] : graph[person]) {
                if (t >= time && earliest[nextPerson] > t) {
                    earliest[nextPerson] = t;
                    q.emplace(nextPerson, t);
                }
            }
        }

        // Since we visited only those people who know the secret,
        // we need to return indices of all visited people.
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (earliest[i] != INT_MAX) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> findAllPeople(
        int n,
        int[][] meetings,
        int firstPerson
    ) {
        // For every person, we store the meeting time and label of the person met.
        Map<Integer, List<int[]>> graph = new HashMap<>();
        for (int[] meeting : meetings) {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            graph
                .computeIfAbsent(x, k -> new ArrayList<>())
                .add(new int[] { t, y });
            graph
                .computeIfAbsent(y, k -> new ArrayList<>())
                .add(new int[] { t, x });
        }

        // Earliest time at which a person learned the secret
        // as per current state of knowledge. If due to some new information,
        // the earliest time of knowing the secret changes, we will update it
        // and again process all the people whom he/she meets after the time
        // at which he/she learned the secret.
        int[] earliest = new int[n];
        Arrays.fill(earliest, Integer.MAX_VALUE);
        earliest[0] = 0;
        earliest[firstPerson] = 0;

        // Queue for BFS. It will store (person, time of knowing the secret)
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[] { 0, 0 });
        q.offer(new int[] { firstPerson, 0 });

        // Do BFS
        while (!q.isEmpty()) {
            int[] personTime = q.poll();
            int person = personTime[0], time = personTime[1];
            for (int[] nextPersonTime : graph.getOrDefault(
                person,
                new ArrayList<>()
            )) {
                int t = nextPersonTime[0], nextPerson = nextPersonTime[1];
                if (t >= time && earliest[nextPerson] > t) {
                    earliest[nextPerson] = t;
                    q.offer(new int[] { nextPerson, t });
                }
            }
        }

        // Since we visited only those people who know the secret,
        // we need to return indices of all visited people.
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (earliest[i] != Integer.MAX_VALUE) {
                ans.add(i);
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findAllPeople(
        self, n: int, meetings: List[List[int]], firstPerson: int
    ) -> List[int]:
        # For every person, store the time and label of the person met.
        graph = defaultdict(list)
        for x, y, t in meetings:
            graph[x].append((t, y))
            graph[y].append((t, x))

        # Earliest time at which a person learned the secret
        # as per current state of knowledge. If due to some new information,
        # the earliest time of knowing the secret changes, we will update it
        # and again process all the people whom he/she meets after the time
        # at which he/she learned the secret.
        earliest = [inf] * n
        earliest[0] = 0
        earliest[firstPerson] = 0

        # Queue for BFS. It will store (person, time of knowing the secret)
        q = deque()
        q.append((0, 0))
        q.append((firstPerson, 0))

        # Do BFS
        while q:
            person, time = q.popleft()
            for t, next_person in graph[person]:
                if t >= time and earliest[next_person] > t:
                    earliest[next_person] = t
                    q.append((next_person, t))

        # Since we visited only those people who know the secret,
        # we need to return indices of all visited people.
        return [i for i in range(n) if earliest[i] != inf]
```

</details>

<br>

## Approach 2: Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        // For every person, we store the meeting time and label of the person
        // met.
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto& meeting : meetings) {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            graph[x].emplace_back(t, y);
            graph[y].emplace_back(t, x);
        }

        // Earliest time at which a person learned the secret
        // as per current state of knowledge. If due to some new information,
        // the earliest time of knowing the secret changes, we will update it
        // and again process all the people whom he/she meets after the time
        // at which he/she learned the secret.
        vector<int> earliest(n, INT_MAX);
        earliest[0] = 0;
        earliest[firstPerson] = 0;

        // Stack for DFS. It will store (person, time of knowing the secret)
        stack<pair<int, int>> stack;
        stack.emplace(0, 0);
        stack.emplace(firstPerson, 0);

        // Do DFS
        while (!stack.empty()) {
            auto [person, time] = stack.top();
            stack.pop();
            for (auto [t, nextPerson] : graph[person]) {
                if (t >= time && earliest[nextPerson] > t) {
                    earliest[nextPerson] = t;
                    stack.emplace(nextPerson, t);
                }
            }
        }

        // Since we visited only those people who know the secret
        // we need to return indices of all visited people.
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (earliest[i] != INT_MAX) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> findAllPeople(
        int n,
        int[][] meetings,
        int firstPerson
    ) {
        // For every person, we store the meeting time and label of the person met.
        Map<Integer, List<int[]>> graph = new HashMap<>();
        for (int[] meeting : meetings) {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            graph
                .computeIfAbsent(x, k -> new ArrayList<>())
                .add(new int[] { t, y });
            graph
                .computeIfAbsent(y, k -> new ArrayList<>())
                .add(new int[] { t, x });
        }

        // Earliest time at which a person learned the secret
        // as per current state of knowledge. If due to some new information,
        // the earliest time of knowing the secret changes, we will update it
        // and again process all the people whom he/she meets after the time
        // at which he/she learned the secret.
        int[] earliest = new int[n];
        Arrays.fill(earliest, Integer.MAX_VALUE);
        earliest[0] = 0;
        earliest[firstPerson] = 0;

        // Stack for DFS. It will store (person, time of knowing the secret)
        Stack<int[]> stack = new Stack<>();
        stack.push(new int[] { 0, 0 });
        stack.push(new int[] { firstPerson, 0 });

        // Do DFS
        while (!stack.isEmpty()) {
            int[] personTime = stack.pop();
            int person = personTime[0], time = personTime[1];
            for (int[] nextPersonTime : graph.getOrDefault(
                person,
                new ArrayList<>()
            )) {
                int t = nextPersonTime[0], nextPerson = nextPersonTime[1];
                if (t >= time && earliest[nextPerson] > t) {
                    earliest[nextPerson] = t;
                    stack.push(new int[] { nextPerson, t });
                }
            }
        }

        // Since we visited only those people who know the secret
        // we need to return indices of all visited people.
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (earliest[i] != Integer.MAX_VALUE) {
                ans.add(i);
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findAllPeople(
        self, n: int, meetings: List[List[int]], firstPerson: int
    ) -> List[int]:
        # For every person, store the time and label of the person met.
        graph = defaultdict(list)
        for x, y, t in meetings:
            graph[x].append((t, y))
            graph[y].append((t, x))

        # Earliest time at which a person learned the secret
        # as per current state of knowledge. If due to some new information,
        # the earliest time of knowing the secret changes, we will update it
        # and again process all the people whom he/she meets after the time
        # at which he/she learned the secret.
        earliest = [inf] * n
        earliest[0] = 0
        earliest[firstPerson] = 0

        # Stack for DFS. It will store (person, time of knowing the secret)
        stack = [(0, 0), (firstPerson, 0)]

        # Do DFS
        while stack:
            person, time = stack.pop()
            for t, next_person in graph[person]:
                if t >= time and earliest[next_person] > t:
                    earliest[next_person] = t
                    stack.append((next_person, t))

        # Since we visited only those people who know the secret
        # we need to return indices of all visited people.
        return [i for i in range(n) if earliest[i] != inf]
```

</details>

<br>

## Approach 3: Earliest Informed First Traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        // For every person, we store the meeting time and label of the person
        // met.
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto& meeting : meetings) {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            graph[x].emplace_back(t, y);
            graph[y].emplace_back(t, x);
        }

        // Priority Queue for BFS. It will store (time of knowing the secret,
        // person) We will pop the person with the minimum time of knowing the
        // secret.
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.emplace(0, 0);
        pq.emplace(0, firstPerson);

        // Visited array to mark if a person is visited or not.
        // We will mark a person as visited after it is dequeued
        // from the queue.
        vector<bool> visited(n, false);

        // Do BFS, but pop minimum.
        while (!pq.empty()) {
            auto [time, person] = pq.top();
            pq.pop();
            if (visited[person]) {
                continue;
            }
            visited[person] = true;
            for (auto [t, nextPerson] : graph[person]) {
                if (!visited[nextPerson] && t >= time) {
                    pq.emplace(t, nextPerson);
                }
            }
        }

        // Since we visited only those people who know the secret
        // we need to return indices of all visited people.
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> findAllPeople(
        int n,
        int[][] meetings,
        int firstPerson
    ) {
        // For every person, we store the meeting time and label of the person met.
        Map<Integer, List<int[]>> graph = new HashMap<>();
        for (int[] meeting : meetings) {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            graph
                .computeIfAbsent(x, k -> new ArrayList<>())
                .add(new int[] { t, y });
            graph
                .computeIfAbsent(y, k -> new ArrayList<>())
                .add(new int[] { t, x });
        }

        // Priority Queue for BFS. It will store (time of knowing the secret, person)
        // We will pop the person with the minimum time of knowing the secret.
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[] { 0, 0 });
        pq.offer(new int[] { 0, firstPerson });

        // Visited array to mark if a person is visited or not.
        // We will mark a person as visited after it is dequeued
        // from the queue.
        boolean[] visited = new boolean[n];

        // Do BFS, but pop minimum.
        while (!pq.isEmpty()) {
            int[] timePerson = pq.poll();
            int time = timePerson[0], person = timePerson[1];
            if (visited[person]) {
                continue;
            }
            visited[person] = true;
            for (int[] nextPersonTime : graph.getOrDefault(
                person,
                new ArrayList<>()
            )) {
                int t = nextPersonTime[0], nextPerson = nextPersonTime[1];
                if (!visited[nextPerson] && t >= time) {
                    pq.offer(new int[] { t, nextPerson });
                }
            }
        }

        // Since we visited only those people who know the secret
        // we need to return indices of all visited people.
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                ans.add(i);
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findAllPeople(
        self, n: int, meetings: List[List[int]], firstPerson: int
    ) -> List[int]:
        # For every person, store the time and label of the person met.
        graph = defaultdict(list)
        for x, y, t in meetings:
            graph[x].append((t, y))
            graph[y].append((t, x))

        # Priority Queue for BFS. It stores (time secret learned, person)
        # It pops the person with the minimum time of knowing the secret.
        pq = []
        heappush(pq, (0, 0))
        heappush(pq, (0, firstPerson))

        # Visited array to mark if a person is visited or not.
        # We will mark a person as visited after it is dequeued
        # from the queue.
        visited = [False] * n

        # Do BFS, but pop minimum.
        while pq:
            time, person = heappop(pq)
            if visited[person]:
                continue
            visited[person] = True
            for t, next_person in graph[person]:
                if not visited[next_person] and t >= time:
                    heappush(pq, (t, next_person))

        # Since we visited only those people who know the secret
        # we need to return indices of all visited people.
        return [i for i in range(n) if visited[i]]
```

</details>

<br>

## Approach 4: Breadth First Search on Time Scale

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        // Sort meetings in increasing order of time
        sort(meetings.begin(), meetings.end(),
             [](auto& a, auto& b) { return a[2] < b[2]; });

        // Group Meetings in increasing order of time
        map<int, vector<pair<int, int>>> sameTimeMeetings;
        for (auto& meeting : meetings) {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            sameTimeMeetings[t].emplace_back(x, y);
        }

        // Boolean Array to mark if a person knows the secret or not
        vector<bool> knowsSecret(n, false);
        knowsSecret[0] = true;
        knowsSecret[firstPerson] = true;

        // Process in increasing order of time
        for (auto& [t, meetings] : sameTimeMeetings) {
            // For each person, save all the people whom he/she meets at time t
            unordered_map<int, vector<int>> meet;
            for (auto& [x, y] : meetings) {
                meet[x].push_back(y);
                meet[y].push_back(x);
            }

            // Start traversal from those who already know the secret at time t
            // Set to avoid redundancy
            unordered_set<int> start;
            for (auto& [x, y] : meetings) {
                if (knowsSecret[x]) {
                    start.insert(x);
                }
                if (knowsSecret[y]) {
                    start.insert(y);
                }
            }

            // Do BFS
            queue<int> q;
            for (auto& person : start) {
                q.push(person);
            }
            while (!q.empty()) {
                int person = q.front();
                q.pop();
                for (auto& nextPerson : meet[person]) {
                    if (!knowsSecret[nextPerson]) {
                        knowsSecret[nextPerson] = true;
                        q.push(nextPerson);
                    }
                }
            }
        }

        // List of people who know the secret
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (knowsSecret[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> findAllPeople(
        int n,
        int[][] meetings,
        int firstPerson
    ) {
        // Sort meetings in increasing order of time
        Arrays.sort(meetings, (a, b) -> a[2] - b[2]);

        // Group Meetings in increasing order of time
        Map<Integer, List<int[]>> sameTimeMeetings = new TreeMap<>();
        for (int[] meeting : meetings) {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            sameTimeMeetings
                .computeIfAbsent(t, k -> new ArrayList<>())
                .add(new int[] { x, y });
        }

        // Boolean Array to mark if a person knows the secret or not
        boolean[] knowsSecret = new boolean[n];
        knowsSecret[0] = true;
        knowsSecret[firstPerson] = true;

        // Process in increasing order of time
        for (int t : sameTimeMeetings.keySet()) {
            // For each person, save all the people whom he/she meets at time t
            Map<Integer, List<Integer>> meet = new HashMap<>();
            for (int[] meeting : sameTimeMeetings.get(t)) {
                int x = meeting[0], y = meeting[1];
                meet.computeIfAbsent(x, k -> new ArrayList<>()).add(y);
                meet.computeIfAbsent(y, k -> new ArrayList<>()).add(x);
            }

            // Start traversal from those who already know the secret at time t
            // Set to avoid redundancy
            Set<Integer> start = new HashSet<>();
            for (int[] meeting : sameTimeMeetings.get(t)) {
                int x = meeting[0], y = meeting[1];
                if (knowsSecret[x]) {
                    start.add(x);
                }
                if (knowsSecret[y]) {
                    start.add(y);
                }
            }

            // Do BFS
            Queue<Integer> q = new LinkedList<>(start);
            while (!q.isEmpty()) {
                int person = q.poll();
                for (int nextPerson : meet.getOrDefault(
                    person,
                    new ArrayList<>()
                )) {
                    if (!knowsSecret[nextPerson]) {
                        knowsSecret[nextPerson] = true;
                        q.offer(nextPerson);
                    }
                }
            }
        }

        // List of people who know the secret
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (knowsSecret[i]) {
                ans.add(i);
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findAllPeople(
        self, n: int, meetings: List[List[int]], firstPerson: int
    ) -> List[int]:
        # Sort meetings in increasing order of time
        meetings.sort(key=lambda x: x[2])

        # Group Meetings in increasing order of time
        same_time_meetings = defaultdict(list)
        for x, y, t in meetings:
            same_time_meetings[t].append((x, y))

        # Boolean Array to mark if a person knows the secret or not
        knows_secret = [False] * n
        knows_secret[0] = True
        knows_secret[firstPerson] = True

        # Process in increasing order of time
        for t in same_time_meetings:
            # For each person, save all the people whom he/she meets at time t
            meet = defaultdict(list)
            for x, y in same_time_meetings[t]:
                meet[x].append(y)
                meet[y].append(x)

            # Start traversal from those who already know the secret at time t
            # Set to avoid redundancy
            q = set()
            for x, y in same_time_meetings[t]:
                if knows_secret[x]:
                    q.add(x)
                if knows_secret[y]:
                    q.add(y)

            # Do BFS
            q = deque(q)
            while q:
                person = q.popleft()
                for next_person in meet[person]:
                    if not knows_secret[next_person]:
                        knows_secret[next_person] = True
                        q.append(next_person)

        # List of people who know the secret
        return [i for i in range(n) if knows_secret[i]]
```

</details>

<br>

## Approach 5: Union-Find with Reset

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        // Initialize parent and rank arrays
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        // Find parent of node x. Use Path Compression
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        // Unite two nodes x and y, if they are not already united
        int px = find(x);
        int py = find(y);
        if (px != py) {
            // Union by Rank Heuristic
            if (rank[px] > rank[py]) {
                parent[py] = px;
            } else if (rank[px] < rank[py]) {
                parent[px] = py;
            } else {
                parent[py] = px;
                rank[px] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        // Check if two nodes x and y are connected or not
        return find(x) == find(y);
    }

    void reset(int x) {
        // Reset the initial properties of node x
        parent[x] = x;
        rank[x] = 0;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        // Sort meetings in increasing order of time
        sort(meetings.begin(), meetings.end(),
             [](auto& a, auto& b) { return a[2] < b[2]; });

        // Group Meetings in increasing order of time
        map<int, vector<pair<int, int>>> sameTimeMeetings;
        for (auto& meeting : meetings) {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            sameTimeMeetings[t].emplace_back(x, y);
        }

        // Create graph
        UnionFind graph(n);
        graph.unite(firstPerson, 0);

        // Process in increasing order of time
        for (auto& [t, meetings] : sameTimeMeetings) {
            // Unite two persons taking part in a meeting
            for (auto& [x, y] : meetings) {
                graph.unite(x, y);
            }

            // If any one knows the secret, both will be connected to 0.
            // If no one knows the secret, then reset.
            for (auto& [x, y] : meetings) {
                if (!graph.connected(x, 0)) {
                    // No need to check for y since x and y were united
                    graph.reset(x);
                    graph.reset(y);
                }
            }
        }

        // Al those who are connected to 0 will know the secret
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (graph.connected(i, 0)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> findAllPeople(
        int n,
        int[][] meetings,
        int firstPerson
    ) {
        // Sort meetings in increasing order of time
        Arrays.sort(meetings, (a, b) -> a[2] - b[2]);

        // Group Meetings in increasing order of time
        Map<Integer, List<int[]>> sameTimeMeetings = new TreeMap<>();
        for (int[] meeting : meetings) {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            sameTimeMeetings
                .computeIfAbsent(t, k -> new ArrayList<>())
                .add(new int[] { x, y });
        }

        // Create graph
        UnionFind graph = new UnionFind(n);
        graph.unite(firstPerson, 0);

        // Process in increasing order of time
        for (int t : sameTimeMeetings.keySet()) {
            // Unite two persons taking part in a meeting
            for (int[] meeting : sameTimeMeetings.get(t)) {
                int x = meeting[0], y = meeting[1];
                graph.unite(x, y);
            }

            // If any one knows the secret, both will be connected to 0.
            // If no one knows the secret, then reset.
            for (int[] meeting : sameTimeMeetings.get(t)) {
                int x = meeting[0], y = meeting[1];
                if (!graph.connected(x, 0)) {
                    // No need to check for y since x and y were united
                    graph.reset(x);
                    graph.reset(y);
                }
            }
        }

        // Al those who are connected to 0 will know the secret
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (graph.connected(i, 0)) {
                ans.add(i);
            }
        }
        return ans;
    }
}

class UnionFind {

    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        // Initialize parent and rank arrays
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    public int find(int x) {
        // Find parent of node x. Use Path Compression
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    public void unite(int x, int y) {
        // Unite two nodes x and y, if they are not already united
        int px = find(x);
        int py = find(y);
        if (px != py) {
            // Union by Rank Heuristic
            if (rank[px] > rank[py]) {
                parent[py] = px;
            } else if (rank[px] < rank[py]) {
                parent[px] = py;
            } else {
                parent[py] = px;
                rank[px] += 1;
            }
        }
    }

    public boolean connected(int x, int y) {
        // Check if two nodes x and y are connected or not
        return find(x) == find(y);
    }

    public void reset(int x) {
        // Reset the initial properties of node x
        parent[x] = x;
        rank[x] = 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findAllPeople(
        self, n: int, meetings: List[List[int]], firstPerson: int
    ) -> List[int]:
        # Sort meetings in increasing order of time
        meetings.sort(key=lambda x: x[2])

        # Group Meetings in increasing order of time
        same_time_meetings = defaultdict(list)
        for x, y, t in meetings:
            same_time_meetings[t].append((x, y))

        # Create graph
        graph = UnionFind(n)
        graph.unite(firstPerson, 0)

        # Process in increasing order of time
        for t in same_time_meetings:
            # Unite two persons taking part in a meeting
            for x, y in same_time_meetings[t]:
                graph.unite(x, y)

            # If any one knows the secret, both will be connected to 0.
            # If no one knows the secret, then reset.
            for x, y in same_time_meetings[t]:
                if not graph.connected(x, 0):
                    # No need to check for y since x and y were united
                    graph.reset(x)
                    graph.reset(y)

        # Al those who are connected to 0 will know the secret
        return [i for i in range(n) if graph.connected(i, 0)]


class UnionFind:
    def __init__(self, nodes: int):
        # Initialize parent and rank arrays
        self.parent = [i for i in range(nodes)]
        self.rank = [0] * nodes

    def find(self, x: int) -> int:
        # Find the parent of node x. Use Path Compression
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def unite(self, x: int, y: int) -> None:
        # Unite two nodes x and y, if they are not already united
        px = self.find(x)
        py = self.find(y)
        if px != py:
            # Union by Rank Heuristic
            if self.rank[px] > self.rank[py]:
                self.parent[py] = px
            elif self.rank[px] < self.rank[py]:
                self.parent[px] = py
            else:
                self.parent[py] = px
                self.rank[px] += 1

    def connected(self, x: int, y: int) -> bool:
        # Check if two nodes x and y are connected or not
        return self.find(x) == self.find(y)

    def reset(self, x: int) -> None:
        # Reset the initial properties of node x
        self.parent[x] = x
        self.rank[x] = 0
```

</details>
