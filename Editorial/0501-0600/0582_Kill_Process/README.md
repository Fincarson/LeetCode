# 582. Kill Process

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/kill-process/)  
`Array` `Hash Table` `Tree` `Depth-First Search` `Breadth-First Search`

**Problem Link:** [LeetCode 582 - Kill Process](https://leetcode.com/problems/kill-process/)

## Problem

You have n processes forming a rooted tree structure. You are given two integer arrays pid and ppid, where pid[i] is the ID of the ith process and ppid[i] is the ID of the ith process's parent process.

Each process has only one parent process but may have multiple children processes. Only one process has ppid[i] = 0, which means this process has no parent process (the root of the tree).

When a process is killed, all of its children processes will also be killed.

Given an integer kill representing the ID of a process you want to kill, return a list of the IDs of the processes that will be killed. You may return the answer in any order.

### Example 1

```text
Input: pid = [1,3,10,5], ppid = [3,0,5,3], kill = 5
Output: [5,10]
Explanation: The processes colored in red are the processes that should be killed.
```

### Example 2

```text
Input: pid = [1], ppid = [0], kill = 1
Output: [1]
```

## Constraints

- n == pid.length
- n == ppid.length
- 1 <= n <= 5 * 104
- 1 <= pid[i] <= 5 * 104
- 0 <= ppid[i] <= 5 * 104
- Only one process has no parent.
- All the values of pid are unique.
- kill is guaranteed to be in pid.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 582. Kill Process

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Depth First Search [Time Limit Exceeded] | Java |
| Approach #2 Tree Simulation [Accepted] | Java |
| Approach #3 HashMap + Depth First Search  [Accepted] | Java |
| Approach #4 HashMap + Breadth First Search [Accepted]: | Java |

## Approach #1 Depth First Search [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

public class Solution {

    public List < Integer > killProcess(List < Integer > pid, List < Integer > ppid, int kill) {
        List < Integer > l = new ArrayList < > ();
        if (kill == 0)
            return l;
        l.add(kill);
        for (int i = 0; i < ppid.size(); i++)
            if (ppid.get(i) == kill)
                l.addAll(killProcess(pid, ppid, pid.get(i)));
        return l;
    }
}
```

</details>

<br>

## Approach #2 Tree Simulation [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    class Node {
        int val;
        List < Node > children = new ArrayList < > ();
    }
    public List < Integer > killProcess(List < Integer > pid, List < Integer > ppid, int kill) {
        HashMap < Integer, Node > map = new HashMap < > ();
        for (int id: pid) {
            Node node = new Node();
            node.val = id;
            map.put(id, node);
        }
        for (int i = 0; i < ppid.size(); i++) {
            if (ppid.get(i) > 0) {
                Node par = map.get(ppid.get(i));
                par.children.add(map.get(pid.get(i)));
            }
        }
        List < Integer > l = new ArrayList < > ();
        l.add(kill);
        getAllChildren(map.get(kill), l);
        return l;
    }
    public void getAllChildren(Node pn, List < Integer > l) {
        for (Node n: pn.children) {
            l.add(n.val);
            getAllChildren(n, l);
        }
    }
}
```

</details>

<br>

## Approach #3 HashMap + Depth First Search  [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public List < Integer > killProcess(List < Integer > pid, List < Integer > ppid, int kill) {
        HashMap < Integer, List < Integer >> map = new HashMap < > ();
        for (int i = 0; i < ppid.size(); i++) {
            if (ppid.get(i) > 0) {
                List < Integer > l = map.getOrDefault(ppid.get(i), new ArrayList < Integer > ());
                l.add(pid.get(i));
                map.put(ppid.get(i), l);
            }
        }
        List < Integer > l = new ArrayList < > ();
        l.add(kill);
        getAllChildren(map, l, kill);
        return l;
    }
    public void getAllChildren(HashMap < Integer, List < Integer >> map, List < Integer > l, int kill) {
        if (map.containsKey(kill))
            for (int id: map.get(kill)) {
                l.add(id);
                getAllChildren(map, l, id);
            }
    }
}
```

</details>

<br>

## Approach #4 HashMap + Breadth First Search [Accepted]:

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public List < Integer > killProcess(List < Integer > pid, List < Integer > ppid, int kill) {
        HashMap < Integer, List < Integer >> map = new HashMap < > ();
        for (int i = 0; i < ppid.size(); i++) {
            if (ppid.get(i) > 0) {
                List < Integer > l = map.getOrDefault(ppid.get(i), new ArrayList < Integer > ());
                l.add(pid.get(i));
                map.put(ppid.get(i), l);
            }
        }
        Queue < Integer > queue = new LinkedList < > ();
        List < Integer > l = new ArrayList < > ();
        queue.add(kill);
        while (!queue.isEmpty()) {
            int r = queue.remove();
            l.add(r);
            if (map.containsKey(r))
                for (int id: map.get(r))
                    queue.add(id);
        }
        return l;
    }
}
```

</details>
