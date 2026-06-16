# 2071. Maximum Number of Tasks You Can Assign

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/)  
`Array` `Two Pointers` `Binary Search` `Greedy` `Queue` `Sorting` `Monotonic Queue`

**Problem Link:** [LeetCode 2071 - Maximum Number of Tasks You Can Assign](https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/)

## Problem

You have n tasks and m workers. Each task has a strength requirement stored in a 0-indexed integer array tasks, with the ith task requiring tasks[i] strength to complete. The strength of each worker is stored in a 0-indexed integer array workers, with the jth worker having workers[j] strength. Each worker can only be assigned to a single task and must have a strength greater than or equal to the task's strength requirement (i.e., workers[j] >= tasks[i]).

Additionally, you have pills magical pills that will increase a worker's strength by strength. You can decide which workers receive the magical pills, however, you may only give each worker at most one magical pill.

Given the 0-indexed integer arrays tasks and workers and the integers pills and strength, return the maximum number of tasks that can be completed.

### Example 1

```text
Input: tasks = [3,2,1], workers = [0,3,3], pills = 1, strength = 1
Output: 3
Explanation:
We can assign the magical pill and tasks as follows:
- Give the magical pill to worker 0.
- Assign worker 0 to task 2 (0 + 1 >= 1)
- Assign worker 1 to task 1 (3 >= 2)
- Assign worker 2 to task 0 (3 >= 3)
```

### Example 2

```text
Input: tasks = [5,4], workers = [0,0,0], pills = 1, strength = 5
Output: 1
Explanation:
We can assign the magical pill and tasks as follows:
- Give the magical pill to worker 0.
- Assign worker 0 to task 0 (0 + 5 >= 5)
```

### Example 3

```text
Input: tasks = [10,15,30], workers = [0,10,10,10,10], pills = 3, strength = 10
Output: 2
Explanation:
We can assign the magical pills and tasks as follows:
- Give the magical pill to worker 0 and worker 1.
- Assign worker 0 to task 0 (0 + 10 >= 10)
- Assign worker 1 to task 1 (10 + 10 >= 15)
The last pill is not given because it will not make any worker strong enough for the last task.
```

## Constraints

- n == tasks.length
- m == workers.length
- 1 <= n, m <= 5 * 104
- 0 <= pills <= m
- 0 <= tasks[i], workers[j], strength <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Most Profit Assigning Work](https://leetcode.com/problems/most-profit-assigning-work/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Running Time of N Computers](https://leetcode.com/problems/maximum-running-time-of-n-computers/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Maximum Number of Robots Within Budget](https://leetcode.com/problems/maximum-number-of-robots-within-budget/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Maximum Matching of Players With Trainers](https://leetcode.com/problems/maximum-matching-of-players-with-trainers/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximize the Minimum Powered City](https://leetcode.com/problems/maximize-the-minimum-powered-city/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2071. Maximum Number of Tasks You Can Assign

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Binary Search + Greedy Worker Selection | C++, Java, Python3 |

## Approach: Binary Search + Greedy Worker Selection

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills,
                      int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        auto check = [&](int mid) -> bool {
            int p = pills;
            // Ordered set of workers
            multiset<int> ws;
            for (int i = m - mid; i < m; ++i) {
                ws.insert(workers[i]);
            }
            // Enumerate each task from largest to smallest
            for (int i = mid - 1; i >= 0; --i) {
                // If the largest element in the ordered set is greater than or
                // equal to tasks[i]
                if (auto it = prev(ws.end()); *it >= tasks[i]) {
                    ws.erase(it);
                } else {
                    if (!p) {
                        return false;
                    }
                    auto rep = ws.lower_bound(tasks[i] - strength);
                    if (rep == ws.end()) {
                        return false;
                    }
                    --p;
                    ws.erase(rep);
                }
            }
            return true;
        };

        int left = 1, right = min(m, n), ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
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

    public int maxTaskAssign(
        int[] tasks,
        int[] workers,
        int pills,
        int strength
    ) {
        Arrays.sort(tasks);
        Arrays.sort(workers);
        int n = tasks.length, m = workers.length;
        int left = 1, right = Math.min(m, n), ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(tasks, workers, pills, strength, mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

    private boolean check(
        int[] tasks,
        int[] workers,
        int pills,
        int strength,
        int mid
    ) {
        int p = pills;
        TreeMap<Integer, Integer> ws = new TreeMap<>();
        for (int i = workers.length - mid; i < workers.length; ++i) {
            ws.put(workers[i], ws.getOrDefault(workers[i], 0) + 1);
        }
        for (int i = mid - 1; i >= 0; --i) {
            Integer key = ws.lastKey();
            if (key >= tasks[i]) {
                ws.put(key, ws.get(key) - 1);
                if (ws.get(key) == 0) {
                    ws.remove(key);
                }
            } else {
                if (p == 0) {
                    return false;
                }
                key = ws.ceilingKey(tasks[i] - strength);
                if (key == null) {
                    return false;
                }
                ws.put(key, ws.get(key) - 1);
                if (ws.get(key) == 0) {
                    ws.remove(key);
                }
                --p;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from sortedcontainers import SortedList


class Solution:
    def maxTaskAssign(
        self, tasks: List[int], workers: List[int], pills: int, strength: int
    ) -> int:
        n, m = len(tasks), len(workers)
        tasks.sort()
        workers.sort()

        def check(mid: int) -> bool:
            p = pills
            # Ordered set of workers
            ws = SortedList(workers[m - mid :])
            # Enumerate each task from largest to smallest
            for i in range(mid - 1, -1, -1):
                # If the largest element in the ordered set is greater than or equal to tasks[i]
                if ws[-1] >= tasks[i]:
                    ws.pop()
                else:
                    if p == 0:
                        return False
                    rep = ws.bisect_left(tasks[i] - strength)
                    if rep == len(ws):
                        return False
                    p -= 1
                    ws.pop(rep)
            return True

        left, right, ans = 1, min(m, n), 0
        while left <= right:
            mid = (left + right) // 2
            if check(mid):
                ans = mid
                left = mid + 1
            else:
                right = mid - 1

        return ans
```

</details>
