# 743. Network Delay Time

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/network-delay-time/)  
`Depth-First Search` `Breadth-First Search` `Graph Theory` `Heap (Priority Queue)` `Shortest Path`

**Problem Link:** [LeetCode 743 - Network Delay Time](https://leetcode.com/problems/network-delay-time/)

## Problem

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

### Example 1

```text
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
```

### Example 2

```text
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
```

### Example 3

```text
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
```

## Constraints

- 1 <= k <= n <= 100
- 1 <= times.length <= 6000
- times[i].length == 3
- 1 <= ui, vi <= n
- ui != vi
- 0 <= wi <= 100
- All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [The Time When the Network Becomes Idle](https://leetcode.com/problems/the-time-when-the-network-becomes-idle/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Second Minimum Time to Reach Destination](https://leetcode.com/problems/second-minimum-time-to-reach-destination/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 743. Network Delay Time

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search (DFS) | C++, Java |
| Breadth-First Search (BFS) | C++, Java |
| Dijkstra's Algorithm | C++, Java |

## Approach 1: Depth-First Search (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Adjacency list, defined it as per the maximum number of nodes
    // But can be defined with the input size as well
    vector<pair<int, int>> adj[101];
    
    void DFS(vector<int>& signalReceivedAt, int currNode, int currTime) {
        // If the current time is greater than or equal to the fastest signal received
        // Then no need to iterate over adjacent nodes
        if (currTime >= signalReceivedAt[currNode]) {
            return;
        }

        // Fastest signal time for currNode so far
        signalReceivedAt[currNode] = currTime;
        
        // Broadcast the signal to adjacent nodes
        for (pair<int, int> edge : adj[currNode]) {
            int travelTime = edge.first;
            int neighborNode = edge.second;
            
            // currTime + time : time when signal reaches neighborNode
            DFS(signalReceivedAt, neighborNode, currTime + travelTime);
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build the adjacency list
        for (vector<int> time : times) {
            int source = time[0];
            int dest = time[1];
            int travelTime = time[2];
            
            adj[source].push_back({travelTime, dest});
        }
        
        // Sort the edges connecting to every node
        for (int i = 1; i <= n; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
        
        vector<int> signalReceivedAt(n + 1, INT_MAX);
        DFS(signalReceivedAt, k, 0);
        
        int answer = INT_MIN;
        for (int node = 1; node <= n; node++) {
            answer = max(answer, signalReceivedAt[node]);
        }
        
        // INT_MAX signifies atleat one node is unreachable
        return answer == INT_MAX ? -1 : answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Adjacency list
    Map<Integer, List<Pair<Integer, Integer>>> adj = new HashMap<>();

    private void DFS(int[] signalReceivedAt, int currNode, int currTime) {
        // If the current time is greater than or equal to the fastest signal received
        // Then no need to iterate over adjacent nodes
        if (currTime >= signalReceivedAt[currNode]) {
            return;
        }

        // Fastest signal time for currNode so far
        signalReceivedAt[currNode] = currTime;
        
        if (!adj.containsKey(currNode)) {
            return;
        }
        
        // Broadcast the signal to adjacent nodes
        for (Pair<Integer, Integer> edge : adj.get(currNode)) {
            int travelTime = edge.getKey();
            int neighborNode = edge.getValue();
            
            // currTime + time : time when signal reaches neighborNode
            DFS(signalReceivedAt, neighborNode, currTime + travelTime);
        }
    }
    
    public int networkDelayTime(int[][] times, int n, int k) {
        // Build the adjacency list
        for (int[] time : times) {
            int source = time[0];
            int dest = time[1];
            int travelTime = time[2];
            
            adj.putIfAbsent(source, new ArrayList<>());
            adj.get(source).add(new Pair(travelTime, dest));
        }
        
        // Sort the edges connecting to every node
        for (int node : adj.keySet()) {
            Collections.sort(adj.get(node), (a, b) -> a.getKey() - b.getKey());
        }
        
        int[] signalReceivedAt = new int[n + 1];
        Arrays.fill(signalReceivedAt, Integer.MAX_VALUE);
        
        DFS(signalReceivedAt, k, 0);
        
        int answer = Integer.MIN_VALUE;
        for (int node = 1; node <= n; node++) {
            answer = Math.max(answer, signalReceivedAt[node]);
        }
        
        // Integer.MAX_VALUE signifies atleat one node is unreachable
        return answer == Integer.MAX_VALUE ? -1 : answer;
    }
}
```

</details>

<br>

## Approach 2: Breadth-First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Adjacency list, defined it as per the maximum number of nodes
    // But can be defined with the input size as well
    vector<pair<int, int>> adj[101];
    
    void BFS(vector<int>& signalReceivedAt, int k) {
        queue<int> q;
        q.push(k);
        
        // Time for starting node is 0
        signalReceivedAt[k] = 0;
        
        while (!q.empty()) {
            int currNode = q.front(); 
            q.pop();
            
            // Broadcast the signal to adjacent nodes
            for (pair<int, int> edge : adj[currNode]) {
                int time = edge.first;
                int neighborNode = edge.second;
                
                int arrivalTime = signalReceivedAt[currNode] + time;
                if (signalReceivedAt[neighborNode] > arrivalTime) {
                    // Fastest signal time for neighborNode so far
                    // signalReceivedAt[currNode] + time : 
                    // time when signal reaches neighborNode
                    signalReceivedAt[neighborNode] = arrivalTime;
                    q.push(neighborNode);
                }
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build the adjacency list
        for (vector<int> time : times) {
            int source = time[0];
            int dest = time[1];
            int travelTime = time[2];
            
            adj[source].push_back({travelTime, dest});
        }

        vector<int> signalReceivedAt(n + 1, INT_MAX);
        BFS(signalReceivedAt, k);
        
        int answer = INT_MIN;
        for (int i = 1; i <= n; i++) {
            answer = max(answer, signalReceivedAt[i]);
        }
        
        // INT_MAX signifies atleat one node is unreachable
        return answer == INT_MAX ? -1 : answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Adjacency list
    Map<Integer, List<Pair<Integer, Integer>>> adj = new HashMap<>();

    private void BFS(int[] signalReceivedAt, int sourceNode) {
        Queue<Integer> q = new LinkedList<>();
        q.add(sourceNode);
        
        // Time for starting node is 0
        signalReceivedAt[sourceNode] = 0;
        
        while (!q.isEmpty()) {
            int currNode = q.remove();
            
            if (!adj.containsKey(currNode)) {
                continue;
            }
            
            // Broadcast the signal to adjacent nodes
            for (Pair<Integer, Integer> edge : adj.get(currNode)) {
                int time = edge.getKey();
                int neighborNode = edge.getValue();
                
                // Fastest signal time for neighborNode so far
                // signalReceivedAt[currNode] + time : 
                // time when signal reaches neighborNode
                int arrivalTime = signalReceivedAt[currNode] + time;
                if (signalReceivedAt[neighborNode] > arrivalTime) {
                    signalReceivedAt[neighborNode] = arrivalTime;
                    q.add(neighborNode);
                }
            }
        }
    }
    
    public int networkDelayTime(int[][] times, int n, int k) {
        // Build the adjacency list
        for (int[] time : times) {
            int source = time[0];
            int dest = time[1];
            int travelTime = time[2];
            
            adj.putIfAbsent(source, new ArrayList<>());
            adj.get(source).add(new Pair(travelTime, dest));
        }
        
        int[] signalReceivedAt = new int[n + 1];
        Arrays.fill(signalReceivedAt, Integer.MAX_VALUE);
        
        BFS(signalReceivedAt, k);
        
        int answer = Integer.MIN_VALUE;
        for (int i = 1; i <= n; i++) {
            answer = Math.max(answer, signalReceivedAt[i]);
        }
        
        // INT_MAX signifies atleat one node is unreachable
        return answer == Integer.MAX_VALUE ? -1 : answer;
    }
}
```

</details>

<br>

## Approach 3: Dijkstra's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Adjacency list, defined it as per the maximum number of nodes
    // But can be defined with the input size as well
    vector<pair<int, int>> adj[101];
    
    void dijkstra(vector<int>& signalReceivedAt, int source, int n) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>> pq;
        pq.push({0, source});
        
        // Time for starting node is 0
        signalReceivedAt[source] = 0;
        
        while (!pq.empty()) {
            int currNodeTime = pq.top().first;
            int currNode = pq.top().second; 
            pq.pop();
            
            if (currNodeTime > signalReceivedAt[currNode]) {
                continue;
            }
            
            // Broadcast the signal to adjacent nodes
            for (pair<int, int> edge : adj[currNode]) {
                int time = edge.first;
                int neighborNode = edge.second;
                
                // Fastest signal time for neighborNode so far
                // signalReceivedAt[currNode] + time : 
                // time when signal reaches neighborNode
                if (signalReceivedAt[neighborNode] > currNodeTime + time) {
                    signalReceivedAt[neighborNode] = currNodeTime + time;
                    pq.push({signalReceivedAt[neighborNode], neighborNode});
                }
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build the adjacency list
        for (vector<int> time : times) {
            int source = time[0];
            int dest = time[1];
            int travelTime = time[2];
            
            adj[source].push_back({travelTime, dest});
        }
        
        vector<int> signalReceivedAt(n + 1, INT_MAX);
        dijkstra(signalReceivedAt, k, n);
        
        int answer = INT_MIN;
        for (int i = 1; i <= n; i++) {
            answer = max(answer, signalReceivedAt[i]);
        }
        
        // INT_MAX signifies atleat one node is unreachable
        return answer == INT_MAX ? -1 : answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Adjacency list
    Map<Integer, List<Pair<Integer, Integer>>> adj = new HashMap<>();
    
    private void dijkstra(int[] signalReceivedAt, int source, int n) {
        Queue<Pair<Integer, Integer>> pq = new PriorityQueue<Pair<Integer,Integer>>
            (Comparator.comparing(Pair::getKey));
        pq.add(new Pair(0, source));
        
        // Time for starting node is 0
        signalReceivedAt[source] = 0;
        
        while (!pq.isEmpty()) {
            Pair<Integer, Integer> topPair = pq.remove();
            
            int currNode = topPair.getValue();
            int currNodeTime = topPair.getKey();
            
            if (currNodeTime > signalReceivedAt[currNode]) {
                continue;
            }
            
            if (!adj.containsKey(currNode)) {
                continue;
            }
            
            // Broadcast the signal to adjacent nodes
            for (Pair<Integer, Integer> edge : adj.get(currNode)) {
                int time = edge.getKey();
                int neighborNode = edge.getValue();
                
                // Fastest signal time for neighborNode so far
                // signalReceivedAt[currNode] + time : 
                // time when signal reaches neighborNode
                if (signalReceivedAt[neighborNode] > currNodeTime + time) {
                    signalReceivedAt[neighborNode] = currNodeTime + time;
                    pq.add(new Pair(signalReceivedAt[neighborNode], neighborNode));
                }
            }
        }
    }
    
    public int networkDelayTime(int[][] times, int n, int k) {
        // Build the adjacency list
        for (int[] time : times) {
            int source = time[0];
            int dest = time[1];
            int travelTime = time[2];
            
            adj.putIfAbsent(source, new ArrayList<>());
            adj.get(source).add(new Pair(travelTime, dest));
        }
        
        int[] signalReceivedAt = new int[n + 1];
        Arrays.fill(signalReceivedAt, Integer.MAX_VALUE);
        
        dijkstra(signalReceivedAt, k, n);
        
        int answer = Integer.MIN_VALUE;
        for (int i = 1; i <= n; i++) {
            answer = Math.max(answer, signalReceivedAt[i]);
        }
        
        // INT_MAX signifies atleat one node is unreachable
        return answer == Integer.MAX_VALUE ? -1 : answer;
    }
}
```

</details>
