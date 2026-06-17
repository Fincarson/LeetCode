# 1376. Time Needed to Inform All Employees

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/time-needed-to-inform-all-employees/)  
`Tree` `Depth-First Search` `Breadth-First Search`

**Problem Link:** [LeetCode 1376 - Time Needed to Inform All Employees](https://leetcode.com/problems/time-needed-to-inform-all-employees/)

## Problem

A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company is the one with headID.

Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i-th employee, manager[headID] = -1. Also, it is guaranteed that the subordination relationships have a tree structure.

The head of the company wants to inform all the company employees of an urgent piece of news. He will inform his direct subordinates, and they will inform their subordinates, and so on until all employees know about the urgent news.

The i-th employee needs informTime[i] minutes to inform all of his direct subordinates (i.e., After informTime[i] minutes, all his direct subordinates can start spreading the news).

Return the number of minutes needed to inform all the employees about the urgent news.

### Example 1

```text
Input: n = 1, headID = 0, manager = [-1], informTime = [0]
Output: 0
Explanation: The head of the company is the only employee in the company.
```

### Example 2

```text
Input: n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
Output: 1
Explanation: The head of the company with id = 2 is the direct manager of all the employees in the company and needs 1 minute to inform them all.
The tree structure of the employees in the company is shown.
```

## Constraints

- 1 <= n <= 105
- 0 <= headID < n
- manager.length == n
- 0 <= manager[i] < n
- manager[headID] == -1
- informTime.length == n
- 0 <= informTime[i] <= 1000
- informTime[i] == 0 if employee i has no subordinates.
- It is guaranteed that all the employees can be informed.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1376. Time Needed to Inform All Employees

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search (DFS) | C++, Java |
| Breadth-First Search (BFS) | C++, Java |

## Approach 1: Depth-First Search (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxTime = INT_MIN;
    
    void DFS(vector<int> adjList[], vector<int>& informTime, int curr, int time) {
        // Maximum time for an employee to get the news.
        maxTime = max(maxTime, time);
        
        for (int adjacent : adjList[curr]) { 
            // Visit the subordinate employee who gets the news after informTime[curr] unit time.
            DFS(adjList, informTime, adjacent, time + informTime[curr]);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adjList[n];
        
        // Making an adjacent list, each index stores the Ids of subordinate employees.
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adjList[manager[i]].push_back(i);
            }
        }
        
        DFS(adjList, informTime, headID, 0);
        return maxTime;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int maxTime = Integer.MIN_VALUE;

    void DFS(ArrayList<ArrayList<Integer>> adjList, int[] informTime, int curr, int time) {
        // Maximum time for an employee to get the news.
        maxTime = Math.max(maxTime, time);

        for (int adjacent : adjList.get(curr)) {
            // Visit the subordinate employee who gets the news after informTime[curr] unit time.
            DFS(adjList, informTime, adjacent, time + informTime[curr]);
        }
    }

    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        ArrayList<ArrayList<Integer>> adjList = new ArrayList<ArrayList<Integer>>(n);

        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<Integer>());
        }

        // Making an adjacent list, each index stores the Ids of subordinate employees.
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adjList.get(manager[i]).add(i);
            }
        }

        DFS(adjList, informTime, headID, 0);
        return maxTime;
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
    int maxTime = INT_MIN;
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adjList[n];
        
        // Making an adjacent list, each index stores the Ids of subordinate employees.
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adjList[manager[i]].push_back(i);
            }
        }
        
        queue<pair<int, int>>q;
        q.push({headID, 0});
        
        while (!q.empty()) {
            pair<int, int> manager = q.front();
            q.pop();
            
            int parent = manager.first;
            int time = manager.second;
            // Maximum time for an employee to get the news.
            maxTime = max(maxTime, time);
            
            for (int adjacent : adjList[parent]) {
                q.push({adjacent, time + informTime[parent]});
            }
        }
        
        return maxTime;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int maxTime = Integer.MIN_VALUE;

    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        ArrayList<ArrayList<Integer>> adjList = new ArrayList<ArrayList<Integer>>(n);

        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<Integer>());
        }

        // Making an adjacent list, each index stores the Ids of subordinate employees.
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adjList.get(manager[i]).add(i);
            }
        }

        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        q.add(new Pair<>(headID, 0));

        while (!q.isEmpty()) {
            Pair<Integer, Integer> employeePair = q.remove();

            int parent = employeePair.getKey();
            int time = employeePair.getValue();
            // Maximum time for an employee to get the news.
            maxTime = Math.max(maxTime, time);
            
            for (int adjacent : adjList.get(parent)) {
                q.add(new Pair<>(adjacent, time + informTime[parent]));

            }
        }

        return maxTime;
    }
}
```

</details>
