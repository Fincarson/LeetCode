# 2462. Total Cost to Hire K Workers

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/total-cost-to-hire-k-workers/)  
`Array` `Two Pointers` `Heap (Priority Queue)` `Simulation`

**Problem Link:** [LeetCode 2462 - Total Cost to Hire K Workers](https://leetcode.com/problems/total-cost-to-hire-k-workers/)

## Problem

You are given a 0-indexed integer array costs where costs[i] is the cost of hiring the ith worker.

You are also given two integers k and candidates. We want to hire exactly k workers according to the following rules:

- You will run k sessions and hire exactly one worker in each session.
- In each hiring session, choose the worker with the lowest cost from either the first candidates workers or the last candidates workers. Break the tie by the smallest index.

		For example, if costs = [3,2,7,7,1,2] and candidates = 2, then in the first hiring session, we will choose the 4th worker because they have the lowest cost [3,2,7,7,1,2].
		In the second hiring session, we will choose 1st worker because they have the same lowest cost as 4th worker but they have the smallest index [3,2,7,7,2]. Please note that the indexing may be changed in the process.
- If there are fewer than candidates workers remaining, choose the worker with the lowest cost among them. Break the tie by the smallest index.
- A worker can only be chosen once.

Return the total cost to hire exactly k workers.

### Example 1

```text
Input: costs = [17,12,10,2,7,2,11,20,8], k = 3, candidates = 4
Output: 11
Explanation: We hire 3 workers in total. The total cost is initially 0.
- In the first hiring round we choose the worker from [17,12,10,2,7,2,11,20,8]. The lowest cost is 2, and we break the tie by the smallest index, which is 3. The total cost = 0 + 2 = 2.
- In the second hiring round we choose the worker from [17,12,10,7,2,11,20,8]. The lowest cost is 2 (index 4). The total cost = 2 + 2 = 4.
- In the third hiring round we choose the worker from [17,12,10,7,11,20,8]. The lowest cost is 7 (index 3). The total cost = 4 + 7 = 11. Notice that the worker with index 3 was common in the first and last four workers.
The total hiring cost is 11.
```

### Example 2

```text
Input: costs = [1,2,4,1], k = 3, candidates = 3
Output: 4
Explanation: We hire 3 workers in total. The total cost is initially 0.
- In the first hiring round we choose the worker from [1,2,4,1]. The lowest cost is 1, and we break the tie by the smallest index, which is 0. The total cost = 0 + 1 = 1. Notice that workers with index 1 and 2 are common in the first and last 3 workers.
- In the second hiring round we choose the worker from [2,4,1]. The lowest cost is 1 (index 2). The total cost = 1 + 1 = 2.
- In the third hiring round there are less than three candidates. We choose the worker from the remaining workers [2,4]. The lowest cost is 2 (index 0). The total cost = 2 + 2 = 4.
The total hiring cost is 4.
```

## Constraints

- 1 <= costs.length <= 105
- 1 <= costs[i] <= 105
- 1 <= k, candidates <= costs.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Time to Cross a Bridge](https://leetcode.com/problems/time-to-cross-a-bridge/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2462. Total Cost to Hire K Workers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| 2 Priority Queues | Java, Python3 |
| 1 Priority Queue | Java, Python3 |

## Approach 1: 2 Priority Queues

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long totalCost(int[] costs, int k, int candidates) {
        PriorityQueue<Integer> headWorkers = new PriorityQueue<>();
        PriorityQueue<Integer> tailWorkers = new PriorityQueue<>();
        
        // headWorkers stores the first k workers.
        // tailWorkers stores at most last k workers without any workers from the first k workers.
        for (int i = 0; i < candidates; i++) {
            headWorkers.add(costs[i]);
        }
        for (int i = Math.max(candidates, costs.length - candidates); i < costs.length; i++) {
            tailWorkers.add(costs[i]);
        }

        long answer = 0;
        int nextHead = candidates;
        int nextTail = costs.length - 1 - candidates;

        for (int i = 0; i < k; i++) {
            if (tailWorkers.isEmpty() || !headWorkers.isEmpty() && headWorkers.peek() <= tailWorkers.peek()) {
                answer += headWorkers.poll();
                
                // Only refill the queue if there are workers outside the two queues.
                if (nextHead <= nextTail) {
                    headWorkers.add(costs[nextHead]);
                    nextHead++;
                }
            } 
            
            else {
                answer += tailWorkers.poll();

                // Only refill the queue if there are workers outside the two queues.
                if (nextHead <= nextTail) {
                    tailWorkers.add(costs[nextTail]);
                    nextTail--;
                }
            }
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        # head_workers stores the first k workers.
        # tail_workers stores at most last k workers without any workers from the first k workers. 
        head_workers = costs[:candidates]
        tail_workers = costs[max(candidates, len(costs) - candidates):]
        heapify(head_workers)
        heapify(tail_workers)
        
        answer = 0
        next_head, next_tail = candidates, len(costs) - 1 - candidates 

        for _ in range(k): 
            if not tail_workers or head_workers and head_workers[0] <= tail_workers[0]: 
                answer += heappop(head_workers)

                # Only refill the queue if there are workers outside the two queues.
                if next_head <= next_tail: 
                    heappush(head_workers, costs[next_head])
                    next_head += 1
            else: 
                answer += heappop(tail_workers)

                # Only refill the queue if there are workers outside the two queues.
                if next_head <= next_tail:  
                    heappush(tail_workers, costs[next_tail])
                    next_tail -= 1
                    
        return answer
```

</details>

<br>

## Approach 2: 1 Priority Queue

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long totalCost(int[] costs, int k, int candidates) {
        // The worker with the lowest cost has the highest priority, if two players has the
        // same cost, break the tie by their indices (0 or 1).
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if (a[0] == b[0]) {
                return a[1] - b[1];
            }
            return a[0] - b[0];});
        
        // Add the first k workers with section id of 0 and 
        // the last k workers with section id of 1 (without duplication) to pq.
        for (int i = 0; i < candidates; i++) {
            pq.offer(new int[] {costs[i], 0});
        }
        for (int i = Math.max(candidates, costs.length - candidates); i < costs.length; i++) {
            pq.offer(new int[] {costs[i], 1});
        }

        long answer = 0;
        int nextHead = candidates;
        int nextTail = costs.length - 1 - candidates;

        for (int i = 0; i < k; i++) {
            int[] curWorker = pq.poll();
            int curCost = curWorker[0], curSectionId = curWorker[1];
            answer += curCost;
            
            // Only refill pq if there are workers outside.
            if (nextHead <= nextTail) {
                if (curSectionId == 0) {
                    pq.offer(new int[]{costs[nextHead], 0});
                    nextHead++;
                } else {
                    pq.offer(new int[]{costs[nextTail], 1});
                    nextTail--;
                }
            }
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        # Add the first k workers with section id of 0 and 
        # the last k workers with section id of 1 (without duplication) to pq.
        pq = []
        for i in range(candidates):
            pq.append((costs[i], 0))
        for i in range(max(candidates, len(costs) - candidates), len(costs)):
            pq.append((costs[i], 1))

        heapify(pq)
        
        answer = 0
        next_head, next_tail = candidates, len(costs) - 1 - candidates 

        # Only refill pq if there are workers outside.
        for _ in range(k): 
            cur_cost, cur_section_id = heappop(pq)
            answer += cur_cost
            if next_head <= next_tail: 
                if cur_section_id == 0:
                    heappush(pq, (costs[next_head], 0))
                    next_head += 1
                else:
                    heappush(pq, (costs[next_tail], 1))
                    next_tail -= 1
                    
        return answer
```

</details>
