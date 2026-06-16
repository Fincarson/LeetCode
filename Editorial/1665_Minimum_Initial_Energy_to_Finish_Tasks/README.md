# 1665. Minimum Initial Energy to Finish Tasks

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/)  
`Array` `Greedy` `Sorting`

**Problem Link:** [LeetCode 1665 - Minimum Initial Energy to Finish Tasks](https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/)

## Problem

You are given an array tasks where tasks[i] = [actuali, minimumi]:

- actuali is the actual amount of energy you spend to finish the ith task.
- minimumi is the minimum amount of energy you require to begin the ith task.

For example, if the task is [10, 12] and your current energy is 11, you cannot start this task. However, if your current energy is 13, you can complete this task, and your energy will be 3 after finishing it.

You can finish the tasks in any order you like.

Return the minimum initial amount of energy you will need to finish all the tasks.

### Example 1

```text
Input: tasks = [[1,2],[2,4],[4,8]]
Output: 8
Explanation:
Starting with 8 energy, we finish the tasks in the following order:
    - 3rd task. Now energy = 8 - 4 = 4.
    - 2nd task. Now energy = 4 - 2 = 2.
    - 1st task. Now energy = 2 - 1 = 1.
Notice that even though we have leftover energy, starting with 7 energy does not work because we cannot do the 3rd task.
```

### Example 2

```text
Input: tasks = [[1,3],[2,4],[10,11],[10,12],[8,9]]
Output: 32
Explanation:
Starting with 32 energy, we finish the tasks in the following order:
    - 1st task. Now energy = 32 - 1 = 31.
    - 2nd task. Now energy = 31 - 2 = 29.
    - 3rd task. Now energy = 29 - 10 = 19.
    - 4th task. Now energy = 19 - 10 = 9.
    - 5th task. Now energy = 9 - 8 = 1.
```

### Example 3

```text
Input: tasks = [[1,7],[2,8],[3,9],[4,10],[5,11],[6,12]]
Output: 27
Explanation:
Starting with 27 energy, we finish the tasks in the following order:
    - 5th task. Now energy = 27 - 5 = 22.
    - 2nd task. Now energy = 22 - 2 = 20.
    - 3rd task. Now energy = 20 - 3 = 17.
    - 1st task. Now energy = 17 - 1 = 16.
    - 4th task. Now energy = 16 - 4 = 12.
    - 6th task. Now energy = 12 - 6 = 6.
```

## Constraints

- 1 <= tasks.length <= 105
- 1 <= actual​i <= minimumi <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1665. Minimum Initial Energy to Finish Tasks

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy (Difference Increasing) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Greedy (Difference Decreases) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Greedy (Difference Increasing)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int compare(const void* a, const void* b) {
    int* taskA = *(int**)a;
    int* taskB = *(int**)b;
    return (taskA[1] - taskA[0]) - (taskB[1] - taskB[0]);
}

int minimumEffort(int** tasks, int tasksSize, int* tasksColSize) {
    qsort(tasks, tasksSize, sizeof(int*), compare);
    int ans = 0;
    for (int i = 0; i < tasksSize; i++) {
        int task0 = tasks[i][0];
        int task1 = tasks[i][1];
        if (ans + task0 > task1) {
            ans = ans + task0;
        } else {
            ans = task1;
        }
    }
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](vector<int>& a, vector<int>& b) {
            return a[1] - a[0] < b[1] - b[0];
        });
        int ans = 0;
        for (auto task : tasks) {
            ans = max(ans + task[0], task[1]);
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinimumEffort(int[][] tasks) {
        Array.Sort(tasks, (a, b) => (a[1] - a[0]).CompareTo(b[1] - b[0]));
        int ans = 0;
        foreach (int[] task in tasks) {
            ans = Math.Max(ans + task[0], task[1]);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumEffort(tasks [][]int) int {
	sort.Slice(tasks, func(i, j int) bool {
		return tasks[i][1]-tasks[i][0] < tasks[j][1]-tasks[j][0]
	})
	ans := 0
	for _, task := range tasks {
		if ans+task[0] > task[1] {
			ans = ans + task[0]
		} else {
			ans = task[1]
		}
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumEffort(int[][] tasks) {
        Arrays.sort(tasks, (a, b) -> a[1] - a[0] - (b[1] - b[0]));
        int ans = 0;
        for (int[] task : tasks) {
            ans = Math.max(ans + task[0], task[1]);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function minimumEffort(tasks) {
    tasks.sort((a, b) => a[1] - a[0] - (b[1] - b[0]));
    let ans = 0;
    for (const task of tasks) {
        ans = Math.max(ans + task[0], task[1]);
    }
    return ans;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        tasks.sort(key=lambda x: x[1] - x[0])
        ans = 0
        for task in tasks:
            ans = max(ans + task[0], task[1])
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumEffort(tasks: number[][]): number {
    tasks.sort((a, b) => a[1] - a[0] - (b[1] - b[0]));
    let ans = 0;
    for (const task of tasks) {
        ans = Math.max(ans + task[0], task[1]);
    }
    return ans;
}
```

</details>

<br>

## Approach 2: Greedy (Difference Decreases)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int compareDesc(const void* a, const void* b) {
    int* taskA = *(int**)a;
    int* taskB = *(int**)b;
    return (taskB[1] - taskB[0]) - (taskA[1] - taskA[0]);
}

int maxInt(int a, int b) { return a > b ? a : b; }

int minimumEffort(int** tasks, int tasksSize, int* tasksColSize) {
    qsort(tasks, tasksSize, sizeof(int*), compareDesc);
    int ans = 0;
    int remain = 0;
    for (int i = 0; i < tasksSize; i++) {
        int task0 = tasks[i][0];
        int task1 = tasks[i][1];
        if (remain <= task1) {
            ans += task1 - remain;
        }
        remain = maxInt(task1 - task0, remain - task0);
    }
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](vector<int>& a, vector<int>& b) {
            return a[1] - a[0] > b[1] - b[0];
        });
        int ans = 0;
        int remain = 0;
        for (auto task : tasks) {
            ans += remain > task[1] ? 0 : task[1] - remain;
            remain = max(task[1] - task[0], remain - task[0]);
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinimumEffort(int[][] tasks) {
        Array.Sort(tasks, (a, b) => (b[1] - b[0]).CompareTo(a[1] - a[0]));
        int ans = 0;
        int remain = 0;
        foreach (int[] task in tasks) {
            if (remain <= task[1]) {
                ans += task[1] - remain;
            }
            remain = Math.Max(task[1] - task[0], remain - task[0]);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumEffort(tasks [][]int) int {
	sort.Slice(tasks, func(i, j int) bool {
		return tasks[i][1]-tasks[i][0] > tasks[j][1]-tasks[j][0]
	})
	ans := 0
	remain := 0
	for _, task := range tasks {
		if remain > task[1] {
			// 不需要增加能量
		} else {
			ans += task[1] - remain
		}
		if task[1]-task[0] > remain-task[0] {
			remain = task[1] - task[0]
		} else {
			remain = remain - task[0]
		}
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumEffort(int[][] tasks) {
        Arrays.sort(tasks, (a, b) -> (b[1] - b[0]) - (a[1] - a[0]));
        int ans = 0;
        int remain = 0;
        for (int[] task : tasks) {
            if (remain <= task[1]) {
                ans += task[1] - remain;
            }
            remain = Math.max(task[1] - task[0], remain - task[0]);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function minimumEffort(tasks) {
    tasks.sort((a, b) => b[1] - b[0] - (a[1] - a[0]));
    let ans = 0;
    let remain = 0;
    for (const task of tasks) {
        if (remain <= task[1]) {
            ans += task[1] - remain;
        }
        remain = Math.max(task[1] - task[0], remain - task[0]);
    }
    return ans;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        tasks.sort(key=lambda x: x[1] - x[0], reverse=True)
        ans = 0
        remain = 0
        for task in tasks:
            if remain <= task[1]:
                ans += task[1] - remain
            remain = max(task[1] - task[0], remain - task[0])
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumEffort(tasks: number[][]): number {
    tasks.sort((a, b) => b[1] - b[0] - (a[1] - a[0]));
    let ans = 0;
    let remain = 0;
    for (const task of tasks) {
        if (remain <= task[1]) {
            ans += task[1] - remain;
        }
        remain = Math.max(task[1] - task[0], remain - task[0]);
    }
    return ans;
}
```

</details>
