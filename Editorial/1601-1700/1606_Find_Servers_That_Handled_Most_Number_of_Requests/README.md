# 1606. Find Servers That Handled Most Number of Requests

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/)  
`Array` `Heap (Priority Queue)` `Simulation` `Ordered Set`

**Problem Link:** [LeetCode 1606 - Find Servers That Handled Most Number of Requests](https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/)

## Problem

You have k servers numbered from 0 to k-1 that are being used to handle multiple requests simultaneously. Each server has infinite computational capacity but cannot handle more than one request at a time. The requests are assigned to servers according to a specific algorithm:

- The ith (0-indexed) request arrives.
- If all servers are busy, the request is dropped (not handled at all).
- If the (i % k)th server is available, assign the request to that server.
- Otherwise, assign the request to the next available server (wrapping around the list of servers and starting from 0 if necessary). For example, if the ith server is busy, try to assign the request to the (i+1)th server, then the (i+2)th server, and so on.

You are given a strictly increasing array arrival of positive integers, where arrival[i] represents the arrival time of the ith request, and another array load, where load[i] represents the load of the ith request (the time it takes to complete). Your goal is to find the busiest server(s). A server is considered busiest if it handled the most number of requests successfully among all the servers.

Return a list containing the IDs (0-indexed) of the busiest server(s). You may return the IDs in any order.

### Example 1

```text
Input: k = 3, arrival = [1,2,3,4,5], load = [5,2,3,3,3]
Output: [1]
Explanation:
All of the servers start out available.
The first 3 requests are handled by the first 3 servers in order.
Request 3 comes in. Server 0 is busy, so it's assigned to the next available server, which is 1.
Request 4 comes in. It cannot be handled since all servers are busy, so it is dropped.
Servers 0 and 2 handled one request each, while server 1 handled two requests. Hence server 1 is the busiest server.
```

### Example 2

```text
Input: k = 3, arrival = [1,2,3,4], load = [1,2,1,2]
Output: [0]
Explanation:
The first 3 requests are handled by first 3 servers.
Request 3 comes in. It is handled by server 0 since the server is available.
Server 0 handled two requests, while servers 1 and 2 handled one request each. Hence server 0 is the busiest server.
```

### Example 3

```text
Input: k = 3, arrival = [1,2,3], load = [10,12,11]
Output: [0,1,2]
Explanation: Each server handles a single request, so they are all considered the busiest.
```

## Constraints

- 1 <= k <= 105
- 1 <= arrival.length, load.length <= 105
- arrival.length == load.length
- 1 <= arrival[i], load[i] <= 109
- arrival is strictly increasing.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Meeting Rooms III](https://leetcode.com/problems/meeting-rooms-iii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1606. Find Servers That Handled Most Number of Requests

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorted Containers. | C++, Java, Python |
| Two Priority Queues | C++, Java, Python |

## Approach 1: Sorted Containers.

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> count(k, 0);
        set<int> free;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;

        // All servers are free at the beginning.

        for (int i = 0; i < k; ++i) {
            free.insert(i);
        }
        
        for (int i = 0; i < arrival.size(); ++i) {
            int start = arrival[i];
            // Move free servers from 'busy' to 'free'.
            while (!busy.empty() && busy.top().first <= start) {
                auto [_, serverId] = busy.top();
                busy.pop();
                free.insert(serverId);
            }

            // If we have free servers, use binary search to find the 
            // target server.
            if (!free.empty()) {
                auto ptr = free.lower_bound(i % k);
                if (ptr == free.end()) {
                    ptr = free.begin();
                }
                int busyId = *ptr;
                free.erase(busyId);
                busy.push(make_pair(start + load[i], busyId));
                count[busyId]++;
            }
        }

        // Find the servers that have the maximum workload.
        vector<int> answer;
        auto maxJob = *max_element(count.begin(), count.end());
        for (int i = 0; i < k; ++i) {
            if (count[i] == maxJob) {
                answer.push_back(i);
            }
        }
        
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> busiestServers(int k, int[] arrival, int[] load) {
        int[] count = new int[k];
        TreeSet<Integer> free = new TreeSet<Integer>();
        PriorityQueue<Pair<Integer, Integer>> busy = new PriorityQueue<>((a, b) -> a.getKey() - b.getKey());
        
        // All servers are free at the beginning.

        for (int i = 0; i < k; ++i) {
            free.add(i);
        }
        
        for (int i = 0; i < arrival.length; ++i) {
            int start = arrival[i];

            // Move free servers from 'busy' to 'free'.
            while (!busy.isEmpty() && busy.peek().getKey() <= start) {
                Pair<Integer, Integer> curr = busy.remove();
                int serverId = curr.getValue();
                free.add(serverId);
            }

            // If we have free servers, use binary search to find the 
            // target server.
            if (!free.isEmpty()) {
                Integer busyId = free.ceiling(i % k);
                if (busyId == null) {
                    busyId = free.first();
                }
 
                free.remove(busyId);
                busy.add(new Pair<>(start + load[i], busyId));
                count[busyId]++;
            }
        }
        
        // Find the servers that have the maximum workload.
        int maxJob = Collections.max(Arrays.stream(count).boxed().collect(Collectors.toList()));
        List<Integer> answer = new ArrayList<>();
        for (int i = 0; i < k; ++i) {
            if (count[i] == maxJob) {
                answer.add(i);
            }
        }
        
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
from sortedcontainers import SortedList
class Solution:
    def busiestServers(self, k: int, arrival: List[int], load: List[int]) -> List[int]:
        count = [0] * k

        # All servers are free at the beginning.

        busy, free = [], SortedList(list(range(k)))

        for i, start in enumerate(arrival):

            # Move free servers from 'busy' to 'free'.
            while busy and busy[0][0] <= start:
                _, server_id = heapq.heappop(busy)
                free.add(server_id)

            # If we have free servers, use binary search to find the 
            # target server.
            if free:
                index = free.bisect_left(i % k)
                busy_id = free[index] if index < len(free) else free[0]
                free.remove(busy_id)
                heapq.heappush(busy, (start + load[i], busy_id))
                count[busy_id] += 1

        # Find the servers that have the maximum workload.
        max_job = max(count)
        return [i for i, n in enumerate(count) if n == max_job]
```

</details>

<br>

## Approach 2: Two Priority Queues

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> count(k, 0);
        priority_queue<int, vector<int>, greater<int>> free;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;

        // All servers are free at the beginning.

        for (int i = 0; i < k; ++i) {
            free.push(i);
        }
        
        for (int i = 0; i < arrival.size(); ++i) {
            int start = arrival[i];

            // Remove free servers from 'busy', modify their IDs and
            // add them to 'free'
            while (!busy.empty() && busy.top().first <= start) {
                auto [_, serverId] = busy.top();
                busy.pop();
                int modifiedId = ((serverId - i) % k + k) % k + i;
                free.push(modifiedId);
            }

            // Get the original server ID by taking the remainder of
            // the modified ID to k.
            if (!free.empty()) {
                int busyId = free.top() % k;
                free.pop();
                busy.push(make_pair(start + load[i], busyId));
                count[busyId]++;
            }
        }

        // Find the servers that have the maximum workload.
        vector<int> answer;
        auto maxJob = *max_element(count.begin(), count.end());
        for (int i = 0; i < k; ++i) {
            if (count[i] == maxJob) {
                answer.push_back(i);
            }
        }
        
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> busiestServers(int k, int[] arrival, int[] load) {
        int[] count = new int[k];
        PriorityQueue<Integer> free = new PriorityQueue<>((a, b) -> a - b);
        PriorityQueue<Pair<Integer, Integer>> busy = new PriorityQueue<>((a, b) -> a.getKey() - b.getKey());
        
        // All servers are free at the beginning.

        for (int i = 0; i < k; ++i) {
            free.add(i);
        }
        
        for (int i = 0; i < arrival.length; ++i) {
            int start = arrival[i];

            // Remove free servers from 'busy', modify their IDs and
            // add them to 'free'
            while (!busy.isEmpty() && busy.peek().getKey() <= start) {
                Pair<Integer, Integer> curr = busy.remove();
                int serverId = curr.getValue();
                int modifiedId = ((serverId - i) % k + k) % k + i;
                free.add(modifiedId);
            }

            // Get the original server ID by taking the remainder of
            // the modified ID to k.
            if (!free.isEmpty()) {
                int busyId = free.peek() % k;
                free.remove();
                busy.add(new Pair<>(start + load[i], busyId));
                count[busyId]++;
            }
        }
        
        // Find the servers that have the maximum workload.
        int maxJob = Collections.max(Arrays.stream(count).boxed().collect(Collectors.toList()));
        List<Integer> answer = new ArrayList<>();
        for (int i = 0; i < k; ++i) {
            if (count[i] == maxJob) {
                answer.add(i);
            }
        }
        
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def busiestServers(self, k: int, arrival: List[int], load: List[int]) -> List[int]:
        count = [0] * k
        
        # All servers are free at the beginning.

        busy, free = [], list(range(k))

        for i, start in enumerate(arrival):
            # Remove free servers from 'busy', modify their IDs and
            # add them to 'free'
            while busy and busy[0][0] <= start:
                _, server_id = heapq.heappop(busy)
                heapq.heappush(free, i + (server_id - i) % k)

            # Get the original server ID by taking the remainder of
            # the modified ID to k.
            if free:
                busy_id = heapq.heappop(free) % k
                heapq.heappush(busy, (start + load[i], busy_id))
                count[busy_id] += 1
        
        # Find the servers that have the maximum workload.
        max_job = max(count)
        return [i for i, n in enumerate(count) if n == max_job]
```

</details>
