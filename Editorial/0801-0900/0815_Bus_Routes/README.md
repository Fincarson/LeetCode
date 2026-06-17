# 815. Bus Routes

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/bus-routes/)  
`Array` `Hash Table` `Breadth-First Search`

**Problem Link:** [LeetCode 815 - Bus Routes](https://leetcode.com/problems/bus-routes/)

## Problem

You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

- For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.

You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

### Example 1

```text
Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
```

### Example 2

```text
Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1
```

## Constraints

- 1 <= routes.length <= 500.
- 1 <= routes[i].length <= 105
- All the values of routes[i] are unique.
- sum(routes[i].length) <= 105
- 0 <= routes[i][j] < 106
- 0 <= source, target < 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Costs Using the Train Line](https://leetcode.com/problems/minimum-costs-using-the-train-line/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 815. Bus Routes

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth-First Search (BFS) with Bus Stops as Nodes | C++, Java |
| Breadth-First Search (BFS) with Routes as Nodes | C++, Java |

## Approach 1: Breadth-First Search (BFS) with Bus Stops as Nodes

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        if (source == target) {
            return 0;
        }

        unordered_map<int, vector<int>> adjList;
        // Create a map from the bus stop to all the routes that include this
        // stop.
        for (int route = 0; route < routes.size(); route++) {
            for (auto stop : routes[route]) {
                // Add all the routes that have this stop.
                adjList[stop].push_back(route);
            }
        }

        queue<int> q;
        unordered_set<int> vis;
        // Insert all the routes in the queue that have the source stop.
        for (auto route : adjList[source]) {
            q.push(route);
            vis.insert(route);
        }

        int busCount = 1;
        while (q.size()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int route = q.front();
                q.pop();

                // Iterate over the stops in the current route.
                for (auto stop : routes[route]) {
                    // Return the current count if the target is found.
                    if (stop == target) {
                        return busCount;
                    }

                    // Iterate over the next possible routes from the current
                    // stop.
                    for (auto nextRoute : adjList[stop]) {
                        if (!vis.count(nextRoute)) {
                            vis.insert(nextRoute);
                            q.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numBusesToDestination(int[][] routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        HashMap<Integer, ArrayList<Integer>> adjList = new HashMap<>();
        // Create a map from the bus stop to all the routes that include this stop.
        for (int r = 0; r < routes.length; r++) {
            for (int stop : routes[r]) {
                // Add all the routes that have this stop.
                ArrayList<Integer> route = adjList.getOrDefault(
                        stop,
                        new ArrayList<>());
                route.add(r);
                adjList.put(stop, route);
            }
        }

        if (adjList.get(source) == null || adjList.get(target) == null)
            return -1;
        Queue<Integer> q = new LinkedList<>();
        Set<Integer> vis = new HashSet<Integer>(routes.length);
        // Insert all the routes in the queue that have the source stop.
        for (int route : adjList.get(source)) {
            q.add(route);
            vis.add(route);
        }

        int busCount = 1;
        while (!q.isEmpty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int route = q.remove();

                // Iterate over the stops in the current route.
                for (int stop : routes[route]) {
                    // Return the current count if the target is found.
                    if (stop == target) {
                        return busCount;
                    }

                    // Iterate over the next possible routes from the current stop.
                    for (int nextRoute : adjList.get(stop)) {
                        if (!vis.contains(nextRoute)) {
                            vis.add(nextRoute);
                            q.add(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;
    }
}
```

</details>

<br>

## Approach 2: Breadth-First Search (BFS) with Routes as Nodes

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> adjList[501];

    // Iterate over each pair of routes and add an edge between them if there's
    // a common stop.
    void createGraph(vector<vector<int>>& routes) {
        for (int i = 0; i < routes.size(); i++) {
            for (int j = i + 1; j < routes.size(); j++) {
                if (haveCommonNode(routes[i], routes[j])) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
    }

    // Returns true if the provided routes have a common stop, false otherwise.
    bool haveCommonNode(vector<int>& route1, vector<int>& route2) {
        int i = 0, j = 0;
        while (i < route1.size() && j < route2.size()) {
            if (route1[i] == route2[j]) {
                return true;
            }

            route1[i] < route2[j] ? i++ : j++;
        }
        return false;
    }

    // Add all the routes in the queue that have the source as one of the stops.
    void addStartingNodes(queue<int>& q, vector<vector<int>>& routes,
                          int source) {
        for (int i = 0; i < routes.size(); i++) {
            if (isStopExist(routes[i], source)) {
                q.push(i);
            }
        }
    }

    // Returns true if the given stop is present in the route, false otherwise.
    bool isStopExist(vector<int>& route, int stop) {
        for (int j = 0; j < route.size(); j++) {
            if (route[j] == stop) {
                return true;
            }
        }
        return false;
    }

    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        if (source == target) {
            return 0;
        }

        for (int i = 0; i < routes.size(); ++i) {
            sort(routes[i].begin(), routes[i].end());
        }

        createGraph(routes);

        queue<int> q;
        addStartingNodes(q, routes, source);

        vector<int> vis(routes.size(), 0);
        int busCount = 1;
        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int node = q.front();
                q.pop();

                // Return busCount, if the stop target is present in the current
                // route.
                if (isStopExist(routes[node], target)) {
                    return busCount;
                }

                // Add the adjacent routes.
                for (int adj : adjList[node]) {
                    if (!vis[adj]) {
                        vis[adj] = 1;
                        q.push(adj);
                    }
                }
            }

            busCount++;
        }

        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    List<List<Integer>> adjList = new ArrayList();

    // Iterate over each pair of routes and add an edge between them if there's a common stop.
    void createGraph(int[][] routes) {
        for (int i = 0; i < routes.length; i++) {
            for (int j = i + 1; j < routes.length; j++) {
                if (haveCommonNode(routes[i], routes[j])) {
                    adjList.get(i).add(j);
                    adjList.get(j).add(i);
                }
            }
        }
    }

    // Returns true if the provided routes have a common stop, false otherwise.
    boolean haveCommonNode(int[] route1, int[] route2) {
        int i = 0, j = 0;
        while (i < route1.length && j < route2.length) {
            if (route1[i] == route2[j]) {
                return true;
            }

            if (route1[i] < route2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return false;
    }

    // Add all the routes in the queue that have the source as one of the stops.
    void addStartingNodes(Queue<Integer> q, int[][] routes, int source) {
        for (int i = 0; i < routes.length; i++) {
            if (isStopExist(routes[i], source)) {
                q.add(i);
            }
        }
    }

    // Returns true if the given stop is present in the route, false otherwise.
    boolean isStopExist(int[] route, int stop) {
        for (int j = 0; j < route.length; j++) {
            if (route[j] == stop) {
                return true;
            }
        }
        return false;
    }

    public int numBusesToDestination(int[][] routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        for (int i = 0; i < routes.length; ++i) {
            Arrays.sort(routes[i]);
            adjList.add(new ArrayList());
        }

        createGraph(routes);

        Queue<Integer> q = new LinkedList<>();
        addStartingNodes(q, routes, source);

        Set<Integer> vis = new HashSet<Integer>(routes.length);
        int busCount = 1;
        while (!q.isEmpty()) {
            int sz = q.size();

            while (sz-- > 0) {
                int node = q.remove();

                // Return busCount, if the stop target is present in the current route.
                if (isStopExist(routes[node], target)) {
                    return busCount;
                }

                // Add the adjacent routes.
                for (int adj : adjList.get(node)) {
                    if (!vis.contains(adj)) {
                        vis.add(adj);
                        q.add(adj);
                    }
                }
            }

            busCount++;
        }

        return -1;
    }
}
```

</details>
