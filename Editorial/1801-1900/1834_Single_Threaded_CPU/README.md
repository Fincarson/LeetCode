# 1834. Single-Threaded CPU

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/single-threaded-cpu/)  
`Array` `Sorting` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 1834 - Single-Threaded CPU](https://leetcode.com/problems/single-threaded-cpu/)

## Problem

You are given nÃ¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹ tasks labeled from 0 to n - 1 represented by a 2D integer array tasks, where tasks[i] = [enqueueTimei, processingTimei] means that the iÃ¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹thÃ¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹ task will be available to process at enqueueTimei and will take processingTimei to finish processing.

You have a single-threaded CPU that can process at most one task at a time and will act in the following way:

- If the CPU is idle and there are no available tasks to process, the CPU remains idle.
- If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time. If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.
- Once a task is started, the CPU will process the entire task without stopping.
- The CPU can finish a task then start a new one instantly.

Return the order in which the CPU will process the tasks.

### Example 1

```text
Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
Output: [0,2,3,1]
Explanation: The events go as follows:
- At time = 1, task 0 is available to process. Available tasks = {0}.
- Also at time = 1, the idle CPU starts processing task 0. Available tasks = {}.
- At time = 2, task 1 is available to process. Available tasks = {1}.
- At time = 3, task 2 is available to process. Available tasks = {1, 2}.
- Also at time = 3, the CPU finishes task 0 and starts processing task 2 as it is the shortest. Available tasks = {1}.
- At time = 4, task 3 is available to process. Available tasks = {1, 3}.
- At time = 5, the CPU finishes task 2 and starts processing task 3 as it is the shortest. Available tasks = {1}.
- At time = 6, the CPU finishes task 3 and starts processing task 1. Available tasks = {}.
- At time = 10, the CPU finishes task 1 and becomes idle.
```

### Example 2

```text
Input: tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
Output: [4,3,2,0,1]
Explanation: The events go as follows:
- At time = 7, all the tasks become available. Available tasks = {0,1,2,3,4}.
- Also at time = 7, the idle CPU starts processing task 4. Available tasks = {0,1,2,3}.
- At time = 9, the CPU finishes task 4 and starts processing task 3. Available tasks = {0,1,2}.
- At time = 13, the CPU finishes task 3 and starts processing task 2. Available tasks = {0,1}.
- At time = 18, the CPU finishes task 2 and starts processing task 0. Available tasks = {1}.
- At time = 28, the CPU finishes task 0 and starts processing task 1. Available tasks = {}.
- At time = 40, the CPU finishes task 1 and becomes idle.
```

## Constraints

- tasks.length == n
- 1 <= n <= 105
- 1 <= enqueueTimei, processingTimei <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Parallel Courses III](https://leetcode.com/problems/parallel-courses-iii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Minimum Time to Complete All Tasks](https://leetcode.com/problems/minimum-time-to-complete-all-tasks/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1834. Single-Threaded CPU

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting + Min-Heap | C++, Java, Python3 |

## Approach 1: Sorting + Min-Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // Sort based on min task processing time or min task index.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> nextTask;

        // Store task enqueue time, processing time, index.
        vector<array<int, 3>> sortedTasks;
        for (int i = 0; i < tasks.size(); ++i) {
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(sortedTasks.begin(), sortedTasks.end());
        vector<int> tasksProcessingOrder;

        long long currTime = 0;
        int taskIndex = 0;

        // Stop when no tasks are left in array and heap.
        while (taskIndex < tasks.size() || !nextTask.empty()) {
            if (nextTask.empty() && currTime < sortedTasks[taskIndex][0]) {
                // When the heap is empty, try updating currTime to next
                // task's enqueue time.
                currTime = sortedTasks[taskIndex][0];
            }

            // Push all the tasks whose enqueueTime <= currtTime into the heap.
            while (taskIndex < sortedTasks.size() && currTime >= sortedTasks[taskIndex][0]) {
                nextTask.push({sortedTasks[taskIndex][1], sortedTasks[taskIndex][2]});
                ++taskIndex;
            }

            auto [processTime, index] = nextTask.top();
            nextTask.pop();

            // Complete this task and increment currTime.
            currTime += processTime;
            tasksProcessingOrder.push_back(index);
        }

        return tasksProcessingOrder;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] getOrder(int[][] tasks) {
        
        // Sort based on min task processing time or min task index.
        // Store enqueue time, processing time, task index.
        PriorityQueue<int[]> nextTask = new PriorityQueue<int[]>((a, b) -> (a[1] != b[1] ? (a[1] - b[1]) : (a[2] - b[2])));
        
        // Store task enqueue time, processing time, index.
        int sortedTasks[][] = new int[tasks.length][3];
        for (int i = 0; i < tasks.length; ++i) {
            sortedTasks[i][0] = tasks[i][0];
            sortedTasks[i][1] = tasks[i][1];
            sortedTasks[i][2] = i;
        }
        
        Arrays.sort(sortedTasks, (a, b) -> Integer.compare(a[0], b[0]));
        int tasksProcessingOrder[] = new int[tasks.length];
        
        long currTime = 0;
        int taskIndex = 0;
        int ansIndex = 0;
        
        // Stop when no tasks are left in array and heap.
        while (taskIndex < tasks.length || !nextTask.isEmpty()) {
            if (nextTask.isEmpty() && currTime < sortedTasks[taskIndex][0]) {
                // When the heap is empty, try updating currTime to next task's enqueue time. 
                currTime = sortedTasks[taskIndex][0];
            }
            
            // Push all the tasks whose enqueueTime <= currtTime into the heap.
            while (taskIndex < tasks.length && currTime >= sortedTasks[taskIndex][0]) { 
                nextTask.add(sortedTasks[taskIndex]);
                ++taskIndex;
            }
            
            int processTime = nextTask.peek()[1];
            int index = nextTask.peek()[2];
            nextTask.remove();
            
            // Complete this task and increment currTime.
            currTime += processTime; 
            tasksProcessingOrder[ansIndex++] = index;
        }
        
        return tasksProcessingOrder;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        # Sort based on min task processing time or min task index.
        next_task: List[Tuple[int, int]] = []
        tasks_processing_order: List[int] = []
        
        # Store task enqueue time, processing time, index.
        sorted_tasks = [(enqueue, process, idx) for idx, (enqueue, process) in enumerate(tasks)]
        sorted_tasks.sort()
        
        curr_time = 0
        task_index = 0
        
        # Stop when no tasks are left in array and heap.
        while task_index < len(tasks) or next_task:
            if not next_task and curr_time < sorted_tasks[task_index][0]:
                # When the heap is empty, try updating curr_time to next task's enqueue time. 
                curr_time = sorted_tasks[task_index][0]
            
            # Push all the tasks whose enqueueTime <= currtTime into the heap.
            while task_index < len(sorted_tasks) and curr_time >= sorted_tasks[task_index][0]:
                _, process_time, original_index = sorted_tasks[task_index]
                heapq.heappush(next_task, (process_time, original_index))
                task_index += 1
            
            process_time, index = heapq.heappop(next_task)
            
            # Complete this task and increment curr_time.
            curr_time += process_time
            tasks_processing_order.append(index)
        
        return tasks_processing_order
```

</details>
