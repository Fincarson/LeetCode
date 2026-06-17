# 621. Task Scheduler

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/task-scheduler/)  
`Array` `Hash Table` `Greedy` `Sorting` `Heap (Priority Queue)` `Counting`

**Problem Link:** [LeetCode 621 - Task Scheduler](https://leetcode.com/problems/task-scheduler/)

## Problem

You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= tasks.length <= 104
- tasks[i] is an uppercase English letter.
- 0 <= n <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Rearrange String k Distance Apart](https://leetcode.com/problems/rearrange-string-k-distance-apart/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Reorganize String](https://leetcode.com/problems/reorganize-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Number of Weeks for Which You Can Work](https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find Minimum Time to Finish All Jobs II](https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Task Scheduler II](https://leetcode.com/problems/task-scheduler-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Generate Schedule](https://leetcode.com/problems/generate-schedule/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 621. Task Scheduler

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Priority Queue / Max Heap | C++, Java, Python3 |
| Filling the Slots and Sorting | C++, Java, Python3 |
| Greedy Approach | C++, Java, Python3 |
| Using Math Formula | C++, Java, Python3 |

## Approach 1: Using Priority Queue / Max Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Building frequency map
        int freq[26] = {0};
        for (char &ch : tasks) {
            freq[ch - 'A']++;
        }

        // Max heap to store frequencies
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }

        int time = 0;
        // Process tasks until the heap is empty
        while (!pq.empty()) {
            int cycle = n + 1;
            vector<int> store;
            int taskCount = 0;
            // Execute tasks in each cycle
            while (cycle-- && !pq.empty()) {
                if (pq.top() > 1) {
                    store.push_back(pq.top() - 1);
                }
                pq.pop();
                taskCount++;
            }
            // Restore updated frequencies to the heap
            for (int &x : store) {
                pq.push(x);
            }
            // Add time for the completed cycle
            time += (pq.empty() ? taskCount : n + 1);
        }
        return time;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int leastInterval(char[] tasks, int n) {
        // Build frequency map
        int[] freq = new int[26];
        for (char ch : tasks) {
            freq[ch - 'A']++;
        }
        
        // Max heap to store frequencies
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.offer(freq[i]);
            }
        }

        int time = 0;
        // Process tasks until the heap is empty
        while (!pq.isEmpty()) {
            int cycle = n + 1;
            List<Integer> store = new ArrayList<>();
            int taskCount = 0;
            // Execute tasks in each cycle
            while (cycle-- > 0 && !pq.isEmpty()) {
                int currentFreq = pq.poll();
                if (currentFreq > 1) {
                    store.add(currentFreq - 1);
                }
                taskCount++;
            }
            // Restore updated frequencies to the heap
            store.forEach(pq::offer);
            // Add time for the completed cycle
            time += (pq.isEmpty() ? taskCount : n + 1);
        }
        return time;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # Build frequency map
        freq = [0] * 26
        for ch in tasks:
            freq[ord(ch) - ord('A')] += 1
        
        # Max heap to store frequencies
        pq = [-f for f in freq if f > 0]
        heapq.heapify(pq)

        time = 0
        # Process tasks until the heap is empty
        while pq:
            cycle = n + 1
            store = []
            task_count = 0
            # Execute tasks in each cycle
            while cycle > 0 and pq:
                current_freq = -heapq.heappop(pq)
                if current_freq > 1:
                    store.append(-(current_freq - 1))
                task_count += 1
                cycle -= 1
            # Restore updated frequencies to the heap
            for x in store:
                heapq.heappush(pq, x)
            # Add time for the completed cycle
            time += task_count if not pq else n + 1
        return time
```

</details>

<br>

## Approach 2: Filling the Slots and Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Create a frequency array to keep track of the count of each task
        vector<int> freq(26);
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Sort the frequency array in non-decreasing order
        sort(freq.begin(), freq.end());
        // Calculate the maximum frequency of any task
        int maxFreq = freq[25] - 1;
        // Calculate the number of idle slots that will be required
        int idleSlots = maxFreq * n;

        // Iterate over the frequency array from the second highest frequency to the lowest frequency
        for (int i = 24; i >= 0 && freq[i] > 0; i--) {
            // Subtract the minimum of the maximum frequency and the current frequency from the idle slots
            idleSlots -= min(maxFreq, freq[i]);
        }

        // If there are any idle slots left, add them to the total number of tasks
        return idleSlots > 0 ? idleSlots + tasks.size() : tasks.size();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int leastInterval(char[] tasks, int n) {
        // Create a frequency array to keep track of the count of each task
        int[] freq = new int[26];
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Sort the frequency array in non-decreasing order
        Arrays.sort(freq);
        // Calculate the maximum frequency of any task
        int maxFreq = freq[25] - 1;
        // Calculate the number of idle slots that will be required
        int idleSlots = maxFreq * n;

        // Iterate over the frequency array from the second highest frequency to the lowest frequency
        for (int i = 24; i >= 0 && freq[i] > 0; i--) {
            // Subtract the minimum of the maximum frequency and the current frequency from the idle slots
            idleSlots -= Math.min(maxFreq, freq[i]);
        }

        // If there are any idle slots left, add them to the total number of tasks
        return idleSlots > 0 ? idleSlots + tasks.length : tasks.length;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # Create a frequency array to keep track of the count of each task
        freq = [0] * 26
        for task in tasks:
            freq[ord(task) - ord('A')] += 1

        # Sort the frequency array in non-decreasing order
        freq.sort()
        # Calculate the maximum frequency of any task
        max_freq = freq[25] - 1
        # Calculate the number of idle slots that will be required
        idle_slots = max_freq * n
        # Iterate over the frequency array from the second highest frequency to the lowest frequency

        for i in range(24, -1, -1):
            # Subtract the minimum of the maximum frequency and the current frequency from the idle slots
            idle_slots -= min(max_freq, freq[i])

        # If there are any idle slots left, add them to the total number of tasks
        return idle_slots + len(tasks) if idle_slots > 0 else len(tasks)
```

</details>

<br>

## Approach 3: Greedy Approach

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Counter array to store the frequency of each task
        int counter[26] = {0};
        int maximum = 0;
        int maxCount = 0;
        // Traverse through tasks to calculate task frequencies
        for (char task : tasks) {
            counter[task - 'A']++;
            if (maximum == counter[task - 'A']) {
                maxCount++;
            }
            else if (maximum < counter[task - 'A']) {
                maximum = counter[task - 'A'];
                maxCount = 1;
            }
        }
        
        // Calculate empty slots, available tasks, and idles needed
        int partCount = maximum - 1;
        int partLength = n - (maxCount - 1);
        int emptySlots = partCount * partLength;
        int availableTasks = tasks.size() - maximum * maxCount;
        int idles = max(0, emptySlots - availableTasks);
        
        // Return the total time required
        return tasks.size() + idles;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int leastInterval(char[] tasks, int n) {
        // Counter array to store the frequency of each task
        int[] counter = new int[26];
        int maximum = 0;
        int maxCount = 0;

        // Traverse through tasks to calculate task frequencies
        for (char task : tasks) {
            counter[task - 'A']++;
            if (maximum == counter[task - 'A']) {
                maxCount++;
            }
            else if (maximum < counter[task - 'A']) {
                maximum = counter[task - 'A'];
                maxCount = 1;
            }
        }
        
        // Calculate empty slots, available tasks, and idles needed
        int partCount = maximum - 1;
        int partLength = n - (maxCount - 1);
        int emptySlots = partCount * partLength;
        int availableTasks = tasks.length - maximum * maxCount;
        int idles = Math.max(0, emptySlots - availableTasks);
        
        return tasks.length + idles;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # Counter array to store the frequency of each task
        counter = [0] * 26
        max_val = 0
        max_count = 0

        # Traverse through tasks to calculate task frequencies
        for task in tasks:
            counter[ord(task) - ord('A')] += 1
            if max_val == counter[ord(task) - ord('A')]:
                max_count += 1
            elif max_val < counter[ord(task) - ord('A')]:
                max_val = counter[ord(task) - ord('A')]
                max_count = 1
        
        # Calculate empty slots, available tasks, and idles needed
        part_count = max_val - 1
        part_length = n - (max_count - 1)
        empty_slots = part_count * part_length
        available_tasks = len(tasks) - max_val * max_count
        idles = max(0, empty_slots - available_tasks)
        
        # Return the total time required
        return len(tasks) + idles
```

</details>

<br>

## Approach 4: Using Math Formula

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // freq array to store the frequency of each task
        int freq[26] = {0};
        int maxCount = 0;

        // Count the frequency of each task and find the maximum frequency
        for (char task : tasks) {
            freq[task - 'A']++;
            maxCount = max(maxCount, freq[task - 'A']);
        }

        // Calculate the total time needed for execution
        int time = (maxCount - 1) * (n + 1);
        for (int f : freq) {
            if (f == maxCount) {
                time++;
            }
        }

        // Return the maximum of total time needed and the length of the task list
        return max((int)tasks.size(), time);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int leastInterval(char[] tasks, int n) {
        // freq array to store the frequency of each task
        int[] freq = new int[26];  
        int maxCount = 0;

        // Count the frequency of each task and find the maximum frequency
        for (char task : tasks) {
            freq[task - 'A']++;
            maxCount = Math.max(maxCount, freq[task - 'A']);
        }

        // Calculate the total time needed for execution
        int time = (maxCount - 1) * (n + 1);
        for (int f : freq) {
            if (f == maxCount) {
                time++;
            }
        }

        // Return the maximum of total time needed and the length of the task list
        return Math.max(tasks.length, time);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # freq array to store the frequency of each task
        freq = [0] * 26  
        max_count = 0

        # Count the frequency of each task and find the maximum frequency
        for task in tasks:
            freq[ord(task) - ord('A')] += 1
            max_count = max(max_count, freq[ord(task) - ord('A')])

        # Calculate the total time needed for execution
        time = (max_count - 1) * (n + 1)
        for f in freq:
            if f == max_count:
                time += 1

        # Return the maximum of total time needed and the length of the task list
        return max(len(tasks), time)
```

</details>
